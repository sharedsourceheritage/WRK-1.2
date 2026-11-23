#region Using directives

using System;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.Data;
using System.Data.Common;
using System.Data.Sql;
using System.Data.SqlTypes;
using System.Data.SqlClient;
using System.IO;
using System.Globalization;
using Microsoft.SqlServer.Server;

#endregion

/*=====================================================================

  File:      ResultSet.cs for Result Set sample
  Summary:   A class which permits browsing of results while executing other
             commands by using server-side cursors. 
  Date:	     November 17, 2004

---------------------------------------------------------------------

  This file is part of the Microsoft SQL Server Code Samples.
  Copyright (C) Microsoft Corporation.  All rights reserved.

This source code is intended only as a supplement to Microsoft
Development Tools and/or on-line documentation.  See these other
materials for detailed information regarding Microsoft code samples.

THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

======================================================= */
namespace Microsoft.Samples.SqlServer
{
    /// <summary>
    /// This class is used to provide an API similar to a SQL data reader except that it is possible
    /// to navigate through any part of the result set.  It is also possible to execute commands while
    /// this class is still "open" even though the CLR in-proc provider does not support MARS at this time.
    /// This implementation is highly simplified to make the sample easy to understand.  A better implementation
    /// would fetch multiple rows to avoid a database turnaround per row fetched.
    /// Using this class can have a significantly smaller memory footprint than filling a dataset with 
    /// all the results of a query which is very important for server side programming.
    /// </summary>
    public class ResultSet : IDataReader, IDataRecord, IEnumerable, IDisposable
    {
        private SqlConnection connection = null; //Which database to access
        private Microsoft.SqlServer.Server.SqlDataRecord results = null;        //A cache or a single row's worth of data 
        //A cache of whether the columns of the current cached row are set to the default value for the column
        private int visibleFieldCount;

        private string cursorName = string.Format("[{0}]", Guid.NewGuid().ToString());

        // Properties

		internal Microsoft.SqlServer.Server.SqlDataRecord CurrentRecord
        {
            get
            {
                EnsureState(StateValues.read);
                return results;
            }
        }

        /// <summary>
        ///     Which database to access.  The connection passed to the setter must
        ///     be open.
        /// </summary>
        /// <value>The object representing the database being accessed</value>
        [System.CLSCompliant(false)]
        public SqlConnection Connection
        {
            get
            {
                return connection;
            }

            set
            {
                if (state != StateValues.created && state != StateValues.initialized)
                    throw new InvalidStateException("Cannot alter select command after opening the result set.");
                if (value.State != ConnectionState.Open)
                    throw new InvalidStateException("Connection must be opened prior to setting result set connection value.");
                connection = value;
                if (selectCommand != null && connection != null)
                    state = StateValues.initialized;
                else
                    state = StateValues.created;
            }
        }

        private string selectCommand;  //What query to execute against the database
        public string SelectCommand
        {
            get
            {
                return selectCommand;
            }

            set
            {
                if (state != StateValues.created && state != StateValues.initialized)
                    throw new InvalidStateException("Cannot alter select command after opening the result set.");
                selectCommand = value;
                if (selectCommand != null && connection != null)
                    state = StateValues.initialized;
                else
                    state = StateValues.created;
            }
        }

        private bool isScrollable = true;
        public bool IsScrollable
        {
            get
            {
                return isScrollable;
            }

            set
            {
                if (state != StateValues.created && state != StateValues.initialized)
                    throw new InvalidStateException("Cannot alter IsScrollable property after opening the result set.");
                isScrollable = value;
            }
        }




        //The possible phases this object can go through from creation through termination.
        private enum StateValues
        {
            created,    //Result set is instantiated but connection and select command are not set
            initialized, //Result set is instantiated and connection and select command are set
            opened, //The cursor has been created for browsing data
            read, //At least one row of data has been read and cached.
            closed
        }; //The cursor has been closed and deallocated, and the connection is closed. 
        //No further operations are possible.

        //What the current phase is
        private StateValues state = StateValues.created;


        //It is possible to create the result set with this constructor and then set the connection
        //and select command using the public properties.
        public ResultSet()
        {

        }

        //Or you can create the result set all at once using this form of the constructor.
        [System.CLSCompliant(false)]
        public ResultSet(SqlConnection connection, string selectCommand)
        {
            this.Connection = connection;
            this.SelectCommand = selectCommand;
            state = StateValues.initialized;
        }

        //By default the result set is scrollable, but you can create a forward-only
        //result set using this constructor and specifying false for isScrollable.
        [System.CLSCompliant(false)]
        public ResultSet(SqlConnection connection, string selectCommand, bool isScrollable)
        {
            this.Connection = connection;
            this.SelectCommand = selectCommand;
            this.IsScrollable = isScrollable;
            state = StateValues.initialized;
        }


        //TODO: Drop this for Beta 3
        public ResultSet(string selectCommand)
        {
            this.connection = new SqlConnection("context connection=true");
            this.selectCommand = selectCommand;
            state = StateValues.initialized;
        }

        /// <summary>
        /// This method should be called just before the result set is to be used to pull data.  
        /// The open doesn't happen as part of creation as server resources are being consumed
        /// while the result set is open.  Be sure to close an open result set as soon as possible
        /// to release server side resources.
        /// </summary>
        public void Open()
        {
            switch (state)
            {
                case StateValues.created:
                    throw new InvalidStateException("Cannot open result set until it is properly initialized");
                case StateValues.opened:
                case StateValues.read:
                    throw new InvalidStateException("Result set already open.");
                case StateValues.closed:
                    throw new InvalidStateException("Cannot reopen closed result set.");
                default:
                    break;
            }
            if (state == StateValues.initialized)
            {
                //There are many possible cursor options.  We only allow control of scrollability.
                //To keep the implementation simple we only permit read operations.
                string scrollMode = (isScrollable) ? "SCROLL" : "FORWARD_ONLY";
                //Caller must ensure that any user input which is part of selectCommand is free from
                //injection attacks.
                SqlCommand cmd = connection.CreateCommand();
				cmd.CommandText = string.Format("DECLARE {0} CURSOR GLOBAL {1} READ_ONLY  FOR {2}; OPEN {0};",
					cursorName, scrollMode, selectCommand);
                cmd.ExecuteNonQuery();
                state = StateValues.opened;
            }
        }


        #region IDataReader Members

        /// <summary>
        /// Free all server and client side resources being consumed for this result set.  Most operations
        /// are no longer valid after calling this method on the result set.
        /// </summary>
        public void Close()
        {
            switch (state)
            {
                case StateValues.created:
                case StateValues.initialized:
                    throw new InvalidStateException("Cannot close unopened result set.");
                case StateValues.closed:
                    throw new InvalidStateException("Result set already closed.");
                case StateValues.opened:
                case StateValues.read:
                    SqlCommand cmd = connection.CreateCommand();
					cmd.CommandText =
						string.Format("CLOSE {0}; DEALLOCATE {0};", cursorName);
                    try
                    {
                        cmd.ExecuteNonQuery();
                    }
                    finally
                    {
                        results = null;
                        //TODO: For beta 3 close connection
                        state = StateValues.closed;
                    }
                    break;
                default:
                    throw new InvalidStateException(
                        string.Format(CultureInfo.InvariantCulture,
                        "Unknown result set state {0}", state.ToString()));
            }

        }

        /// <summary>
        /// This implementation does not support multi-dimensional data
        /// </summary>
        /// <value>Always zero</value>
        public int Depth
        {
            get
            {
                EnsureState(StateValues.read);
                return 0;
            }
        }

        /// <summary>
        /// Normally this would return a data table with schema information about the data being returned.
        /// Unfortunately this isn't implemented in the in-proc provider, so we always throw an exception.
        /// </summary>
        /// <returns>Always throws an NYI exception.</returns>
        public DataTable GetSchemaTable()
        {
            throw new NotImplementedException("GetSchemaTable is not currently implemented.");
        }

        /// <summary>
        /// Determines if there is any data to read
        /// </summary>
        /// <value>True if there is data to read, otherwise false</value>
        public bool HasRows
        {
            get
            {
                throw new NotImplementedException("HasRows is not currently implemented.");
            }
        }

        /// <summary>
        /// Determines if the result set is available for use
        /// </summary>
        /// <value>Returns false if the result set is available for use, otherwise true</value>
        public bool IsClosed
        {
            get { return state == StateValues.closed; }
        }

        /// <summary>
        /// Multiple result sets are not supported.
        /// </summary>
        /// <returns>Always throws an invalid operation exception</returns>
        public bool NextResult()
        {
            throw new InvalidOperationException("Multiple result sets are not support for result set class");
        }

        /// <summary>
        /// Fetches the next row from the result set on the server and makes that data available to the caller.
        /// </summary>
        /// <returns>True if and only if there is data to read</returns>
        public bool Read()
        {
            return fetch(string.Format("FETCH NEXT FROM {0};", cursorName));
        }

        /// <summary>
        /// Returns the number of records affected by processing this result set.  This may only be called when
        /// the result set is closed.  Since this implementation supports only read-only access, there 
        /// can never be any rows affected.
        /// </summary>
        /// <value>Always -1</value>
        public int RecordsAffected
        {
            get
            {
                EnsureState(StateValues.closed);
                return -1;
            }
        }


        #endregion

        #region Navigation methods

        /// <summary>
        /// Move to a particular record number in the results returned by the query.  Requires
        /// a scrollable result set.
        /// </summary>
        /// <param name="position"></param>
        /// <returns>True if and only if there is data to read</returns>

        public bool ReadAbsolute(int position)
        {
            EnsureScroll();
            return fetch(string.Format("FETCH ABSOLUTE {0} FROM {1};",
                position, cursorName));
        }

        /// <summary>
        /// Move to the first result in the results returned by the query and read it.  Requires
        /// a scrollable result set.
        /// </summary>
        /// <returns>True if and only if there is data to read</returns>
        public bool ReadFirst()
        {
            EnsureScroll();
            return fetch(string.Format("FETCH FIRST FROM {0};", cursorName));
        }

        /// <summary>
        /// Move to the last result in the results returned by the query and read it.  Requires
        /// a scrollable result set.
        /// </summary>
        /// <returns>True if and only if there is data to read</returns>
        public bool ReadLast()
        {
            EnsureScroll();
            return fetch(string.Format("FETCH LAST FROM {0};", cursorName));
        }

        /// <summary>
        /// Move to the immediate prior result in the results returned by the query, and read it.  
        /// Requires a scrollable result set.
        /// </summary>
        /// <returns>True if and only if there is data to read</returns>
        public bool ReadPrevious()
        {
            EnsureScroll();
            return fetch(string.Format("FETCH PREVIOUS FROM {0};", cursorName));
        }

        /// <summary>
        /// Move the specified number of records forward or backward from the current position
        /// in the results returned by the query and read it.  Requires
        /// a scrollable result set.
        /// </summary>
        /// <param name="position">How many records forward or backward</param>
        /// <returns>True if and only if there is data to read</returns>
        public bool ReadRelative(int position)
        {
            EnsureScroll();
            return fetch(string.Format("FETCH RELATIVE {0} FROM {1};", position, cursorName));
        }

        #endregion


        #region IDisposable Members

        /// <summary>
        /// Dispose is idential to closing the result set.
        /// </summary>
        public void Dispose()
        {
            Close();
        }

        #endregion

        #region IDataRecord Members
        /// <summary>
        /// The number of columns available in the results just read
        /// </summary>
        /// <value>The number of columns</value>
        public int FieldCount
        {
            get
            {
                EnsureState(StateValues.read);
                return results.FieldCount;
            }
        }

        public int VisibleFieldCount
        {
            get
            {
                EnsureState(StateValues.read);
                return visibleFieldCount;
            }
        }

        public IDataReader GetData(int ordinal)
        {
			throw new InvalidOperationException("GetData is no longer implemented");
        }


        /// <summary>
        /// What kind of data is acceptable for the specified column
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>What kind of data is acceptable</returns>
        public string GetDataTypeName(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetDataTypeName(i);
        }

        /// <summary>
        /// Returns the object which represents the kind of data which is 
        /// acceptable for the specified column.
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>The object which represents the kind of data is which acceptable</returns>
        public Type GetFieldType(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetFieldType(i);
        }

        /// <summary>
        /// Returns the symbolic id of the specified column
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>The symbolic id (name) of the column</returns>
        public string GetName(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetName(i);
        }

        /// <summary>
        /// Given a column name, returns the integer id the column.
        /// </summary>
        /// <param name="name">Which column</param>
        /// <returns>The integer id of the column</returns>
        public int GetOrdinal(string name)
        {
            EnsureState(StateValues.read);
            //Note: this implementation does not deal with all collation and internationalization issues.
            return results.GetOrdinal(name);
        }

        /// <summary>
        /// Places all the values contained in the current row into the supplied object array.  The elements
        /// of the array are based on the SQL type system.
        /// </summary>
        /// <param name="values">Where to put the row values</param>
        /// <returns>How many columns of values were placed in the array</returns>
        public int GetSqlValues(object[] values)
        {
            EnsureState(StateValues.read);
            return results.GetSqlValues(values);
        }

        /// <summary>
        /// Places all the values contained in the current row into the supplied object array.  The 
        /// elements of the array are based on the CLR type system.
        /// </summary>
        /// <param name="values">Where to put the values</param>
        /// <returns>How many columns of data were put in the array</returns>
        public int GetValues(object[] values)
        {
            EnsureState(StateValues.read);
            return results.GetValues(values);
        }

        /// <summary>
        /// Accesses the data in the specified column by name
        /// </summary>
        /// <param name="name">Which column to access</param>
        /// <returns>What was contained in the specified column for the current row</returns>
        public object this[string name]
        {
            get
            {
                EnsureState(StateValues.read);
                return results[name];
            }
        }

        /// <summary>
        /// Accesses the data in the specified column by numerical id
        /// </summary>
        /// <param name="i">Which column to access</param>
        /// <returns>The data in the specified column</returns>
        public object this[int i]
        {
            get
            {
                EnsureState(StateValues.read);
                return results[i];
            }
        }

        //// Methods in this region provide access to column data for the current row as 
        //// objects using the Sql type system.  The advantage of using this type system is that
        //// you can deal very precisely with the database's concept of null.  Also, some types 
        //// (such as SqlXml) provide more efficient methods of data access than the CLR type system.

        /// <summary>
        /// Access the data in the specified column in the current row as a SqlBinary object
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>The data as SqlBinary</returns>
        public SqlBinary GetSqlBinary(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetSqlBinary(i);
        }

        /// <summary>
        /// Access the data in the specified column in the current row as a SqlBoolean object
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>The data as SqlBoolean</returns>
        public SqlBoolean GetSqlBoolean(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetSqlBoolean(i);
        }

        /// <summary>
        /// Access the data in the specified column in the current row as a SqlByte object
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>The data as SqlByte</returns>
        public SqlByte GetSqlByte(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetSqlByte(i);
        }

        /// <summary>
        /// Access the data in the specified column in the current row as a SqlBytes object
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>The data as SqlBytes</returns>
        public SqlBytes GetSqlBytes(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetSqlBytes(i);
        }

        /// <summary>
        /// Access the data in the specified column in the current row as a SqlChars object
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>The data as SqlChars</returns>
        public SqlChars GetSqlChars(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetSqlChars(i);
        }

        /// <summary>
        /// Access the data in the specified column in the current row as a SqlDateTime object
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>The data as SqlDateTime</returns>
        public SqlDateTime GetSqlDateTime(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetSqlDateTime(i);
        }

        /// <summary>
        /// Access the data in the specified column in the current row as a SqlDecimal object
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>The data as SqlDecimal</returns>
        public SqlDecimal GetSqlDecimal(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetSqlDecimal(i);
        }

        /// <summary>
        /// Access the data in the specified column in the current row as a SqlDouble object
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>The data as SqlDouble</returns>
        public SqlDouble GetSqlDouble(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetSqlDouble(i);
        }

        /// <summary>
        /// Access the data in the specified column in the current row as a SqlGuid object
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>The data as SqlGuid</returns>
        public SqlGuid GetSqlGuid(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetSqlGuid(i);
        }

        /// <summary>
        /// Access the data in the specified column in the current row as a SqlInt16 object
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>The data as SqlInt16</returns>
        public SqlInt16 GetSqlInt16(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetSqlInt16(i);
        }

        /// <summary>
        /// Access the data in the specified column in the current row as a SqlInt32 object
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>The data as SqlInt32</returns>
        public SqlInt32 GetSqlInt32(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetSqlInt32(i);
        }

        /// <summary>
        /// Access the data in the specified column in the current row as a SqlInt64 object
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>The data as SqlInt64</returns>
        public SqlInt64 GetSqlInt64(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetSqlInt64(i);
        }

        /// <summary>
        /// Return schema information for the specified column
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>Schema information for the column represented by a SqlMetaData object</returns>
        public Microsoft.SqlServer.Server.SqlMetaData GetSqlMetaData(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetSqlMetaData(i);
        }

        /// <summary>
        /// Access the data in the specified column in the current row as a SqlMoney object
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>The data as SqlMoney</returns>
        public SqlMoney GetSqlMoney(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetSqlMoney(i);
        }

        /// <summary>
        /// Access the data in the specified column in the current row as a SqlSingle object
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>The data as SqlSingle</returns>
        public SqlSingle GetSqlSingle(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetSqlSingle(i);
        }

        /// <summary>
        /// Access the data in the specified column in the current row as a SqlString object
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>The data as SqlString</returns>
        public SqlString GetSqlString(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetSqlString(i);
        }

        /// <summary>
        /// Access the data in the specified column in the current row as a Sql object
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>The data as a Sql object</returns>
        public object GetSqlValue(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetSqlValue(i);
        }

        /// <summary>
        /// Access the data in the specified column in the current row as a SqlXml object
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>The data as SqlXml</returns>
        public SqlXml GetSqlXml(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetSqlXml(i);
        }

        //// Methods in this region provide access to column data for the current row
        //// using the CLR type system.  The advantage of using these methods is seamless integration
        //// with other CLR components.

        /// <summary>
        /// Access the data in the specified column in the current row as a Boolean
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>The data as Boolean</returns>
        public bool GetBoolean(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetBoolean(i);
        }

        /// <summary>
        /// Access the data in the specified column in the current row as a byte 
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>The data as a byte</returns>
        public byte GetByte(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetByte(i);
        }


        /// <summary>
        /// Copies bytes from the specified column of the current row into a buffer supplied by
        /// the caller.
        /// </summary>
        /// <param name="i">Which column</param>
        /// <param name="fieldOffset">Where to start in the column's data</param>
        /// <param name="buffer">Where to place the bytes</param>
        /// <param name="bufferOffset">Where to start in the buffer</param>
        /// <param name="length">How many bytes to copy</param>
        /// <returns>How many bytes were actually copied</returns>
        public long GetBytes(int i, long fieldOffset, byte[] buffer, int bufferOffset, int length)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetBytes(i, fieldOffset, buffer, bufferOffset, length);
        }

        /// <summary>
        /// Access the data in the specified column in the current row as a  char.
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>The data as a char</returns>
        public char GetChar(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetChar(i);
        }

        /// <summary>
        /// Copies characters from the specified column of the current row into a buffer supplied by
        /// the caller.
        /// </summary>
        /// <param name="i">Which column</param>
        /// <param name="fieldOffset">Where to start in the column's data</param>
        /// <param name="buffer">Where to place the characters</param>
        /// <param name="bufferOffset">Where to start in the buffer</param>
        /// <param name="length">How many characters to copy</param>
        /// <returns>How many characters were actually copied</returns>
        public long GetChars(int i, long fieldOffset, char[] buffer, int bufferOffset, int length)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetChars(i, fieldOffset, buffer, bufferOffset, length);
        }

        /// <summary>
        /// Access the data in the specified column in the current row as a DateTime 
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>The data as a DateTime</returns>
        public DateTime GetDateTime(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetDateTime(i);
        }

        /// <summary>
        /// Access the data in the specified column in the current row as a decimal. 
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>The data as a decimal</returns>
        public decimal GetDecimal(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetDecimal(i);
        }

        /// <summary>
        /// Access the data in the specified column in the current row as a double
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>The data as a double</returns>
        public double GetDouble(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetDouble(i);
        }

        /// <summary>
        /// Access the data in the specified column in the current row as a float
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>The data as a float</returns>
        public float GetFloat(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetFloat(i);
        }

        /// <summary>
        /// Access the data in the specified column in the current row as a Guid 
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>The data as a Guid</returns>
        public Guid GetGuid(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetGuid(i);
        }

        /// <summary>
        /// Access the data in the specified column in the current row as a short 
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>The data as a short</returns>
        public short GetInt16(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetInt16(i);
        }

        /// <summary>
        /// Access the data in the specified column in the current row as an int
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>The data as an int</returns>
        public int GetInt32(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetInt32(i);
        }

        /// <summary>
        /// Access the data in the specified column in the current row as a long 
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>The data as a long</returns>
        public long GetInt64(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetInt64(i);
        }

        /// <summary>
        /// Access the data in the specified column in the current row as a string 
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>The data as a string</returns>
        public string GetString(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetString(i);
        }

        /// <summary>
        /// Access the data in the specified column in the current row as an object  
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>The data as an object</returns>
        public object GetValue(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.GetValue(i);
        }

        /// <summary>
        /// Returns true if and only if the data in the specified column of the current row is null
        /// as defined by the database.  Note this is different than the CLR concept of null.
        /// </summary>
        /// <param name="i">Which column</param>
        /// <returns>A Boolean indicating whether the column value is null</returns>
        public bool IsDBNull(int i)
        {
            EnsureState(StateValues.read);
            EnsureOrdinal(i);
            return results.IsDBNull(i);
        }

        #endregion

        #region Private implementation

        /// <summary>
        /// Utility method which executes a server side cursor motion command and reads the row
        /// at the current location of the cursor after the motion is complete.  Note that reading one row
        /// at a time can be pretty inefficient.  See comments at the start of this class.
        /// </summary>
        /// <param name="commandText">What SQL cursor motion command to execute</param>
        /// <returns>True if and only if there is data to read</returns>
        private bool fetch(string commandText)
        {
            EnsureState(StateValues.read, StateValues.opened,
                 "The result set must be open to perform the read operation.");
            SqlCommand cmd = connection.CreateCommand();
			cmd.CommandText = commandText;

            SqlDataReader reader = null;
            try
            {
                reader = cmd.ExecuteReader();
                //If there is no data, return false;
                if (!reader.Read())
                {
                    state = StateValues.opened;
                    return false;
                }
                else
                {
                    //Otherwise, advance the state to 'read'
                    state = StateValues.read;
                    //If we haven't cached schema information get it now
                    if (results == null) FetchMetadata(reader);
                    //Cache data values
                    object[] values = new object[FieldCount];
                    reader.GetSqlValues(values);
                    results.SetValues(values);
                    //Indicate there is data read by returning true
                    return true;
                }
            }
            finally
            {
                if (reader != null)
                {
                    reader.Close();
                    reader = null;
                }
            }
        }

        /// <summary>
        /// Helper method for the fetch method.  Initializes the data structures which cache 
        /// the schema information for the current query.
        /// </summary>
        /// <param name="reader">The reader from where schema information may be read</param>
        private void FetchMetadata(SqlDataReader reader)
        {
            int columnCount = reader.FieldCount;
			visibleFieldCount = columnCount;
			/* VisibleFieldcount doesn't work correctly in Beta3.  Use FieldCount for now.
            visibleFieldCount = reader.VisibleFieldCount;
			 */
            //Initialize the data cache
            SqlMetaData[] metadata = new SqlMetaData[visibleFieldCount];
            //Fill the schema cache for each column
			DataTable schemaTable = reader.GetSchemaTable();
            SqlString collationString = new SqlString(String.Empty);
			for (int i = 0; i < metadata.Length; i++)
			{
				DataRow columnSchema = schemaTable.Rows[i];
					metadata[i] = new SqlMetaData(
							reader.GetName(i),
							(SqlDbType)columnSchema["ProviderType"],
							(int)columnSchema["ColumnSize"],
							(byte)((short)columnSchema["NumericPrecision"]),
							(byte)((short)columnSchema["NumericScale"]),
							collationString.LCID,
							collationString.SqlCompareOptions,
							(Type)columnSchema["DataType"]
						);
			}

			results = new Microsoft.SqlServer.Server.SqlDataRecord(metadata);
        }


        /// <summary>
        /// Helper method which validates the state of the result set before processing a 
        /// requested operation.  If the result set is in an invalid state an exception is thrown.
        /// </summary>
        /// <param name="desiredState"></param>
        private void EnsureState(StateValues desiredState)
        {
            if (state != desiredState)
            {
                //Compute the default message
                string message = string.Format(CultureInfo.InvariantCulture, "Expected result set state to be {0} but it was {1}",
                    desiredState.ToString(), state.ToString());
                //If we have more specific information, provide a different message.
                if (desiredState == StateValues.read)
                    message = "You must read a valid row of the result set "
                        + "before performing the requested operation.";
                throw new InvalidStateException(message);
            }
        }

        /// <summary>
        /// Similar to the single argument EnsureState method except that the two specified states 
        /// are both legal and a custom error message must be provided.
        /// </summary>
        /// <param name="desiredState1"></param>
        /// <param name="desiredState2"></param>
        /// <param name="message"></param>
        private void EnsureState(StateValues desiredState1, StateValues desiredState2, string message)
        {
            if (state != desiredState1 && state != desiredState2)
                throw new InvalidStateException(message);
        }

        /// <summary>
        /// Makes certain that the requested column is valid, and throws an exception with a 
        /// clear error message if it isn't.  This would be more useful than the error message
        /// given when accessing beyond the valid boundary of an array, for example.
        /// </summary>
        /// <param name="i">The column trying to be accessed</param>
        private void EnsureOrdinal(int i)
        {
            if (i >= results.FieldCount)
                throw new ArgumentException(
                    string.Format(CultureInfo.InvariantCulture, "Attempt to access column {0} when only {1} columns exist",
                    i, results.FieldCount));
        }

        /// <summary>
        /// Makes certain that the result set is in a proper state to read data, and that
        /// scrolling is allowed.  This method is called from methods which require scrolling capabilities.
        /// </summary>
        private void EnsureScroll()
        {
            if (!isScrollable)
                throw new InvalidOperationException("Attempting to execute a scroll operation on a non-scrollable result set.");
        }



        #endregion

        #region IEnumerable Members

        public IEnumerator GetEnumerator()
        {
            return new ResultSetEnumerator(this);
        }



        #endregion
    }

    public class ResultSetEnumerator : IEnumerator
    {
        private bool isRead = false;

        private ResultSet resultSetToEnumerate = null;

        public ResultSetEnumerator(ResultSet resultSetToEnumerate)
        {
            this.resultSetToEnumerate = resultSetToEnumerate;
        }

        #region IEnumerator Members
        /// <summary>
        /// Returns the current element of a result set which is represented by a SqlDataRecord
        /// </summary>
        /// <value>A SqlDataRecord which represents the current record in a result set</value>
        public object Current
        {
            get
            {
                if (!isRead)
                    throw new InvalidOperationException(
                        "The enumerator is positioned before the first element "
                        + "of the collection or after the last element");
                return resultSetToEnumerate.CurrentRecord;

            }
        }

        /// <summary>
        /// Advance to the next valid element of a result set
        /// </summary>
        /// <returns>True if there is a valid element available at this position</returns>
        public bool MoveNext()
        {
            if (!isRead)
            {
                if (resultSetToEnumerate.ReadFirst())
                {
                    isRead = true;
                    return true;
                }
                else
                    return false;
            }
            else
            {
                return resultSetToEnumerate.Read();
            }
        }

        /// <summary>
        /// Reset the current position of the enumerator to just prior to the current element
        /// </summary>
        public void Reset()
        {
            isRead = false;
        }

        #endregion
    }
}
