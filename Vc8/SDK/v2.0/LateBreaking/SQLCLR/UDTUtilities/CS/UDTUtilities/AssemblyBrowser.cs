/*=====================================================================

  File:      assemblybrowser.cs
  Summary:   provides a relational view over an assembly.
  Date:	     July 21, 2003

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

using System;
using System.Collections;
using System.Data;
using System.Data.Sql;
using System.Data.SqlTypes;
using System.Reflection;
using Microsoft.SqlServer.Server;

namespace Microsoft.Samples.SqlServer
{

    /// <summary>
    /// AssemblyBrowser is a simple utility for composing sql queries over 
    /// assembly metadata. It uses a table-valued-function to return
    /// a table to SqlServer.
    /// </summary>
    public sealed class AssemblyBrowser
    {
        /// <summary>
        /// Get the types in the assembly, as a table
        /// </summary>
        /// <param name="name"></param>
        /// <returns></returns>
        [SqlFunction(FillRowMethodName = "FillTypeRow")]
        public static IEnumerable GetTypes(String name)
        {
            IEnumerable e;

            try
            {
                Assembly a = Assembly.Load(name);
                if (a == null)
                    e = new Type[0];
                else
                    e = a.GetTypes();
            }

            catch (ReflectionTypeLoadException te)
            {
                //could not load some of the types, just return the types that you could load
                e = te.Types;
            }

            if (e == null) e = new Type[0];
            return e;

        }

        /// <summary>
        /// Get the schema of the table
        /// </summary>
        /// <returns></returns>


        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1021:AvoidOutParameters"), System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1021:AvoidOutParameters"), System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1021:AvoidOutParameters"), System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1021:AvoidOutParameters"), System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1021:AvoidOutParameters"), System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1021:AvoidOutParameters"), System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1021:AvoidOutParameters"), System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1021:AvoidOutParameters"), System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1021:AvoidOutParameters"), System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1021:AvoidOutParameters"), System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1021:AvoidOutParameters")]
        public static void FillTypeRow(object metaData, out string fullName, out string baseTypeName,
            out bool isValueType, out int numFields, out bool isSerializable,
            out bool isISerializable, out bool isLayoutSequential, out string namespaceValue,
            out bool isPublic, out bool isSealed, out string assemblyName)
        {
            Type type = (Type)metaData;
            fullName = type.FullName;
            baseTypeName = (type.BaseType == null) ? "" : type.BaseType.FullName;
            isValueType = type.IsValueType;
            FieldInfo[] fields = type.GetFields(BindingFlags.Instance | BindingFlags.Public);
            numFields = (fields == null) ? 0 : fields.Length;
            isSerializable = type.IsSerializable;
            isISerializable = typeof(System.Runtime.Serialization.ISerializable).IsAssignableFrom(type);
            isLayoutSequential = type.IsLayoutSequential;
            namespaceValue = type.Namespace;
            isPublic = type.IsPublic;
            isSealed = type.IsSealed;
            Assembly a = type.Assembly;
            assemblyName = (a == null) ? "null" : a.GetName().Name;
        }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Performance", "CA1811:AvoidUncalledPrivateCode")]
        internal static Assembly GetAssembly(string name)
        {
            try
            {
                return Assembly.Load(name);
            }
            catch (System.IO.FileNotFoundException)
            {
                return null;
            }
        }

        private AssemblyBrowser() { }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1024:UsePropertiesWhereAppropriate"), SqlFunction(FillRowMethodName = "FillAssemblyRow")]
        public static IEnumerable GetLoadedAssemblies()
        {
            IEnumerable e = AppDomain.CurrentDomain.GetAssemblies();
            //Microsoft.SqlServer.Server.SqlMetaData[] schemas
            //    = new Microsoft.SqlServer.Server.SqlMetaData[] {
            //    new Microsoft.SqlServer.Server.SqlMetaData("FullName", SqlDbType.NVarChar, 256)
            //};

            return e;
        }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Performance", "CA1811:AvoidUncalledPrivateCode")]
        private static void FillAssemblyRow(object source, out string fullName)
        {
            fullName = ((Assembly)source).FullName;
        }
    }
}
