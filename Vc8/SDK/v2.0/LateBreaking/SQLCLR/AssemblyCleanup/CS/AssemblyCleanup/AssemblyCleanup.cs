/*=====================================================================
 
  File:     AssemblyCleanup.cs for .NET CLR user assemblies cleanup sample
  Summary:  Defines a CLR user defined function CleanupUnusedAssemblies that drops 
            all the invisible assemblies with no references.
  Date:     July 08, 2005
 
---------------------------------------------------------------------
 
  This file is part of the Microsoft SQL Server Code Samples.
  Copyright (C) 2005 Microsoft Corporation.  All rights reserved.

  This source code is intended only as a supplement to Microsoft
  Development Tools and/or on-line documentation.  See these other
  materials for detailed information regarding Microsoft code samples.
 
  THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
  PARTICULAR PURPOSE.
 
======================================================================= */

using System;
using System.Text;
using System.Diagnostics;
using System.Data.SqlClient;
using System.Collections.Generic;
using System.Globalization;
using Microsoft.SqlServer.Server;

[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1020:AvoidNamespacesWithFewTypes", Scope = "namespace", Target = "Microsoft.Samples.SqlServer")]

namespace Microsoft.Samples.SqlServer
{
    /// <summary>
    /// Defines a CLR user defined function CleanupUnusedAssemblies that drops 
    /// all the invisible assemblies with no references.
    /// </summary>
    public sealed class AssemblyCleanup
    {
        private SqlTransaction transaction;

        internal class AssemblySet
        {
            private Dictionary<int, object> m_dictionary;

            /// <summary>
            /// Initialize internal structures
            /// </summary>
            /// <returns></returns>
            public AssemblySet()
            {
                m_dictionary = new Dictionary<int, object>();
            }

            /// <summary>
            /// Adds an assembly id into the current AssemblySet if it is not 
            /// already part of it.
            /// </summary>
            /// <returns></returns>
            public void Add(int assemblyId)
            {
                if (!m_dictionary.ContainsKey(assemblyId))
                {
                    m_dictionary.Add(assemblyId, null);
                }
            }

            /// <summary>
            /// Number of assembly ids stored in this instance
            /// </summary>
            /// <returns></returns>
            public int Count
            {
                get
                {
                    return m_dictionary.Count;
                }
            }

            /// <summary>
            /// Returns the comma-separated list of assembly ids contained in this instance
            /// </summary>
            /// <returns>string value that represents a comma-seperated list 
            /// of assembly ids</returns>
            public string ToCommaSeperatedList()
            {
                StringBuilder sb = new StringBuilder();

                if (m_dictionary.Count > 0)
                {
                    foreach (KeyValuePair<int, object> kv in m_dictionary)
                    {
                        sb.Append(kv.Key);
                        sb.Append(",");
                    }

                    sb.Length--; // remove the trailing comma
                }

                return sb.ToString();
            }
        }

        /// <summary>
        /// Initializes an instance of AssemblyCleanup with a SqlTransaction
        /// </summary>
        /// <returns></returns>
        private AssemblyCleanup(SqlTransaction transaction)
        {
            this.transaction = transaction;
        }

        /// <summary>
        /// Helper function that creates a SqlCommand object as part of the current 
        /// transaction
        /// </summary>
        /// <returns></returns>
        private SqlCommand CreateCommandInTransaction()
        {
            SqlCommand cmd = this.transaction.Connection.CreateCommand();

            cmd.Transaction = this.transaction;

            return cmd;
        }

        /// <summary>
        /// Helper function that constructs an AssemblySet instance using the 
        /// first column of the resultset resulting from the query that was passed in.
        /// </summary>
        /// <param name="query"></param>
        /// <returns></returns>
        private AssemblySet GetAssemblySetFromQuery(string query)
        {
            SqlCommand cmd = CreateCommandInTransaction();

            AssemblySet set = new AssemblySet();

            cmd.CommandText = query;
            using (SqlDataReader rd = cmd.ExecuteReader())
            {
                while (rd.Read())
                {
                    set.Add(rd.GetInt32(0));
                }
            }

            return set;
        }

        /// <summary>
        /// Constructs a DROP ASSEMBLY T-SQL statement using the AssemblySet 
        /// passed in as a parameter.
        /// </summary>
        /// <param name="set"></param>
        /// <returns></returns>
        private void DropAssemblies(AssemblySet unusedAssemblySet)
        {
            if (unusedAssemblySet.Count > 0)
            {
                StringBuilder assemblyNamesToDrop = new StringBuilder();

                // Gather the list of assembly names we will drop later
                SqlCommand cmd = CreateCommandInTransaction();

                cmd.CommandText = String.Format(CultureInfo.InvariantCulture,
                    "SELECT name FROM sys.assemblies WHERE assembly_id IN ({0});",
                    unusedAssemblySet.ToCommaSeperatedList());
                using (SqlDataReader rd = cmd.ExecuteReader())
                {
                    while (rd.Read())
                    {
                        assemblyNamesToDrop.Append("[");
                        assemblyNamesToDrop.Append(rd.GetString(0));
                        assemblyNamesToDrop.Append("],");
                    }
                }

                // Remove trailing comma
                assemblyNamesToDrop.Length--;

                // Drop all assemblies at the same time
                cmd.CommandText = String.Format(CultureInfo.InvariantCulture,
                    "DROP ASSEMBLY {0}", assemblyNamesToDrop.ToString());
                cmd.ExecuteNonQuery();
            }
        }

        /// <summary>
        /// Serves as the stored procedure entry point and drives the process 
        /// of expanding the "assemblies in use" set, negating it, and 
        /// dropping the results
        /// </summary>
        /// <param name="visibleAssemblies">If set to true, will also drop 
        /// unused visible assemblies. Otherwise, will only drop unused invisible 
        /// assemblies.</param>
        /// <returns></returns>
        [Microsoft.SqlServer.Server.SqlProcedure()]
        public static void CleanupUnusedAssemblies(bool visibleAssemblies)
        {
            bool succeeded = false;
            SqlConnection conn;
            SqlTransaction transaction;
            string sqlStatement;
            AssemblySet assembliesToDrop;
            AssemblyCleanup assemblyCleanup;

            conn = new SqlConnection("context connection=true");
            conn.Open();
            transaction = conn.BeginTransaction();

            try
            {
                // Create a set of assemblies in use by looking at 
                // the metadata of the current database
                sqlStatement =
                    "DECLARE @UsedAssembly TABLE (AssemblyID int NOT NULL); " +
                    "DECLARE @RowCount int; " +
                    "INSERT INTO @UsedAssembly " +
                    "SELECT DISTINCT([assembly_id]) " +
                    "FROM sys.assembly_modules " +
                    "UNION " +
                    "SELECT [assembly_id] " +
                    "FROM sys.assembly_types; " +
                    "SET @RowCount = @@ROWCOUNT; " +
                    "WHILE @RowCount > 0 " +
                    "BEGIN " +
                    "INSERT INTO @UsedAssembly " +
                    "SELECT [referenced_assembly_id] " +
                    "FROM sys.assembly_references ar " +
                    "INNER JOIN @UsedAssembly ua " +
                    "ON ar.[assembly_id] = ua.AssemblyID " +
                    "WHERE NOT EXISTS (SELECT * FROM @UsedAssembly WHERE AssemblyID = [referenced_assembly_id]) " +
                    "SET @RowCount = @@ROWCOUNT; " +
                    "END;";

                if (visibleAssemblies)
                {
                    sqlStatement +=
                        "SELECT assembly_id " +
                        "FROM sys.assemblies " +
                        "WHERE assembly_id NOT IN (SELECT AssemblyID FROM @UsedAssembly);";
                }
                else
                {
                    sqlStatement +=
                        "SELECT assembly_id " +
                        "FROM sys.assemblies " +
                        "WHERE assembly_id NOT IN (SELECT AssemblyID FROM @UsedAssembly) " +
                        "    AND is_visible = 0;";
                }

                // This marks the beginning of the transaction
                assemblyCleanup = new AssemblyCleanup(transaction);

                // Assemblies that are currently in use
                assembliesToDrop
                    = assemblyCleanup.GetAssemblySetFromQuery(sqlStatement);

                assemblyCleanup.DropAssemblies(assembliesToDrop);

                // Mark as succeeded
                succeeded = true;
            }
            finally
            {
                // We must guarantee that we explicitly call either Commit() 
                // or Rollback() before we return.
                if (succeeded)
                {
                    transaction.Commit();
                }
                else
                {
                    transaction.Rollback();
                }
            }
        }
    }
}
