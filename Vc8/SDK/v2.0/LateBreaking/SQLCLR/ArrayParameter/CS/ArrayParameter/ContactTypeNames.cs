#region Using directives

using System;
using System.Data;
using System.Data.Sql;
using System.Data.SqlTypes;
using System.Collections;
using System.Collections.Generic;
using System.Text;
using System.Globalization;
using Microsoft.SqlServer.Server;

#endregion

/*=====================================================================

  File:      ArrayParameter.cs for the ArrayParameter CLR Integration sample
  Summary:   CLR Integration user defined type (UDT) implementation which demonstrates passing 
             an array of strings to the server.  This UDT contains an array of contact type names
             which is passed to the usp_EnsureContactTypeNames stored procedure imnplemented
             in the EnsureNames class in the EnsureContactTypeNames assembly.
  Date:	     December 14, 2004

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
    // This class is used to demonstrate passing an array of a fairly small number of reasonably small strings
    // to a CLR integration based stored procedure on the server.  Because a UDT is limited to 8000 bytes
    // this approach will not work well for large numbers of strings or long strings.  See the contact
    // creation stored procedure in the AdventureWorks CLR integration sample for an alternative approach
    // using XML which does not have these limitations.
    [Serializable]
    [Microsoft.SqlServer.Server.SqlUserDefinedType(Microsoft.SqlServer.Server.Format.UserDefined, IsByteOrdered = true, MaxByteSize = 8000)]
    public class ContactTypeNames : INullable, Microsoft.SqlServer.Server.IBinarySerialize
    {

        #region Constructors
        private const int maxByteSize = 8000;

        public ContactTypeNames()
        {
        }

        public ContactTypeNames(string[] names)
        {
            int numberOfCharacters = 0;
            foreach (string name in names)
            {
                if (name.Length == 0) 
                    throw new ArgumentException("Zero length names are not allowed");
                numberOfCharacters += name.Length;
            }
            int dataByteSize = numberOfCharacters*2 //UTF-16 characters take 2 bytes
                + names.Length*4  //Four byte header for each string
                + 4                 //Four byte header for null string at end
                + 1;                //One byte boolean for null flag
            if (dataByteSize >= maxByteSize)
                throw new ArgumentException(string.Format(CultureInfo.InvariantCulture, "Data provided occupies {0} bytes but only {1} bytes "
                    + "are available", dataByteSize, maxByteSize));

            this._names = names;
        }
        #endregion

        #region Accessors
        public string[] GetTypeNameArray()
        {
            //Don't let caller modify our copy of the array
            return (string[])_names.Clone();
        }

        //This has an odd API because we can only define Transact-SQL functions on static methods.
        [SqlFunctionAttribute(FillRowMethodName = "FillNameRow")]
        public static IEnumerable GetContactTypeNames(ContactTypeNames names)
        {
            return names.GetTypeNameArray();
        }

        public static void FillNameRow(object nameArrayElement, out string contactName)
        {
            contactName = (string)nameArrayElement;
        }

        #endregion

        #region String Conversions

        /// <summary>
        /// The string format for contact type names is a sequence of names separated by commas
        /// </summary>
        /// <param name="s">a string containing contact type names separated by commas</param>
        /// <returns>An instance of contact type name containing the specified names</returns>
        [Microsoft.SqlServer.Server.SqlMethod(DataAccess = Microsoft.SqlServer.Server.DataAccessKind.None, IsDeterministic = false, IsMutator = false, IsPrecise = false,
        SystemDataAccess = Microsoft.SqlServer.Server.SystemDataAccessKind.None)]
        public static ContactTypeNames Parse(SqlString s)
        {
            if (s.IsNull)
                return Null;
            return new ContactTypeNames(s.Value.Split(new char[] {','}));
        }

        /// <summary>
        /// Convert the contact type names to a string
        /// </summary>
        /// <returns>The contact type names separated by commas</returns>
        public override string ToString()
        {
            if (this.IsNull)
                return null;

            StringBuilder sb = new StringBuilder();
            foreach (string name in _names)
            {
                if (sb.Length > 0) sb.Append(", ");
                sb.Append(name);
            }

            return sb.ToString();
        }
        #endregion

        #region INullable Members

        public static ContactTypeNames Null
        {
            get
            {
                return new ContactTypeNames();
            }
        }
        public bool IsNull
        {
            get 
            { 
                return _names == null; 
            }
        }

        #endregion

        #region IBinarySerialize Members

        //Format: 
        //Byte 1: Null flag (boolean) (true = null)
        //Byte 2 - 7994: Strings with 4 byte length headers,
        //               last string is a zero length string.
        //This format is in part dictated by how the BinaryWriter serializes strings.  See
        //the Microsoft .NET Framework documentation on System.IO.BinaryWriter for more details.

        public void Read(System.IO.BinaryReader r)
        {
            if (r.ReadBoolean())
            {
                _names = null;
                return;
            }
            List<String> nameList = new List<String>();
            string name;
            while ((name = r.ReadString()).Length != 0)
            {
                nameList.Add(name);
            }
            _names = new string[nameList.Count];
            nameList.CopyTo(_names);
        }

        public void Write(System.IO.BinaryWriter w)
        {
            w.Write(this.IsNull);
            foreach (string name in _names)
            {
                w.Write(name);
            }
            w.Write(string.Empty);            
        }

        #endregion

        #region Private Implementation

        private string[] _names = null;
        #endregion

    }


}
