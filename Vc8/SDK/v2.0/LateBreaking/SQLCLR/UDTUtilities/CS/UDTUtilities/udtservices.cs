/*=====================================================================

  File:      udtservices.cs
  Summary:   This file defines streaming tvfs that are used to return the fields, methods, and properties
			 defined in a UDT.
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
using System.Reflection;
using System.Data;
using System.Data.Sql;
using System.Data.SqlTypes;
using System.Text;
using System.Globalization;
using Microsoft.SqlServer.Server;
using System.Data.SqlClient;

namespace Microsoft.Samples.SqlServer
{

    /// <summary>
    /// Utility Udt functions
    /// </summary>
    public sealed class UdtServices
    {

        #region udt fields
        /// <summary>
        /// Get the fields in the UDT callable from tsql, as a table
        /// </summary>
        /// <param name="udtName"></param>
        /// <returns></returns>
        [SqlFunctionAttribute(FillRowMethodName = "FillFieldRow")]
        public static IEnumerable GetUdtFields(string udtName)
        {
            return GetSqlFields(GetUdt(udtName));
        }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1021:AvoidOutParameters"), System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1021:AvoidOutParameters")]
        public static void FillFieldRow(object fieldMetadata, out string name, out string type)
        {
            FieldInfo fieldInformation = (FieldInfo)fieldMetadata;
            name = fieldInformation.Name;
            type = fieldInformation.FieldType.Name;
        }

        #endregion

        #region udt properties
        /// <summary>
        /// Get the properties defined in a particular UDT
        /// </summary>
        /// <param name="udtName"></param>
        /// <returns></returns>
        [SqlFunctionAttribute(FillRowMethodName = "FillPropertyRow")]
        public static IEnumerable GetUdtProperties(string udtName)
        {
            return GetSqlProperties(GetUdt(udtName));
        }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1021:AvoidOutParameters"), System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1021:AvoidOutParameters"), System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1021:AvoidOutParameters")]
        public static void FillPropertyRow(object propertyMetadata, out string name, out string type, out string routineProperties)
        {
            PropertyInfo propertyInformation = (PropertyInfo)propertyMetadata;
            name = propertyInformation.Name;
            type = propertyInformation.PropertyType.Name;
            MethodInfo methodInformation = propertyInformation.GetGetMethod();
            object[] attrs = methodInformation.GetCustomAttributes(
                typeof(Microsoft.SqlServer.Server.SqlMethodAttribute), true);

            if (attrs != null && attrs.Length == 1)
            {
                Microsoft.SqlServer.Server.SqlMethodAttribute attr
                    = (Microsoft.SqlServer.Server.SqlMethodAttribute)attrs[0];

                routineProperties = GetRoutineProperties(attr);
            }
            else
                routineProperties = "";
        }

        #endregion

        #region udt methods
        /// <summary>
        /// Get the methods on the UDT callable from tsql, as a table
        /// </summary>
        /// <param name="udtName"></param>
        /// <returns></returns>
        [SqlFunctionAttribute(FillRowMethodName = "FillMethodRow")]
        public static IEnumerable GetUdtMethods(string udtName)
        {
            return GetSqlMethods(GetUdt(udtName));
        }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1021:AvoidOutParameters"), System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1021:AvoidOutParameters"), System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1021:AvoidOutParameters"), System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1021:AvoidOutParameters")]
        public static void FillMethodRow(object methodMetadata, out string name,
            out string parameters, out string returnType, out string routineProperties)
        {
            MethodInfo methodInformation = (MethodInfo)methodMetadata;
            name = methodInformation.Name;
            StringBuilder sb = new StringBuilder("(");
            bool first = true;

            foreach (ParameterInfo pi in methodInformation.GetParameters())
            {
                if (first)
                    first = false;
                else
                    sb.Append(", ");

                sb.Append(pi.Name).Append(" ").Append(pi.ParameterType.Name);
            }

            sb.Append(")");

            parameters = sb.ToString();
            returnType = methodInformation.ReturnType.Name;

            object[] attrs = methodInformation.GetCustomAttributes(
                typeof(Microsoft.SqlServer.Server.SqlMethodAttribute), true);

            if (attrs != null && attrs.Length == 1)
            {
                Microsoft.SqlServer.Server.SqlMethodAttribute attr
                    = (Microsoft.SqlServer.Server.SqlMethodAttribute)attrs[0];

                routineProperties = GetRoutineProperties(attr);
            }
            else
                routineProperties = "";


        }

        #endregion

        #region internal utility functions

        private UdtServices()
        {
        }

        /// <summary>
        /// Utility function to get the string representation of
        /// routine properties on a type
        /// </summary>
        /// <param name="attr"></param>
        /// <returns></returns>
        private static string GetRoutineProperties(Microsoft.SqlServer.Server.SqlMethodAttribute attr)
        {
            StringBuilder sb = new StringBuilder();
            if (attr.OnNullCall)
                sb.Append("on_null_call ");

            if (attr.IsMutator)
                sb.Append("mutator ");

            if (attr.IsDeterministic)
                sb.Append("deterministic ");

            if (attr.IsPrecise)
                sb.Append("precise ");

            if (attr.DataAccess != Microsoft.SqlServer.Server.DataAccessKind.None)
                sb.Append("data_access " + Enum.GetName(
                    typeof(Microsoft.SqlServer.Server.DataAccessKind), attr.DataAccess));

            return sb.ToString();
        }

        /// <summary>
        /// Is this a valid parameter type that can be accessible from tsql
        /// </summary>
        /// <param name="t"></param>
        /// <returns></returns>
        private static bool IsSqlParameterType(Type t)
        {
            if (validParameterTypes.ContainsKey(t))
                return true;

            if (t.FullName.StartsWith("System.Data.SqlTypes"))
                return true;

            if (t.GetCustomAttributes(
                typeof(Microsoft.SqlServer.Server.SqlUserDefinedTypeAttribute),
                true).Length == 1)
                return true;

            return false;
        }

        /// <summary>
        /// Is the field type valid?
        /// </summary>
        /// <param name="f"></param>
        /// <param name="declaringType"></param>
        /// <returns></returns>
        private static bool IsSqlField(FieldInfo f, Type declaringType)
        {
            if (f.DeclaringType != declaringType)
                return false;

            return IsSqlParameterType(f.FieldType);
        }

        /// <summary>
        /// Is the property valid to be called from tsql?
        /// </summary>
        /// <param name="f"></param>
        /// <param name="declaringType"></param>
        /// <returns></returns>
        private static bool IsSqlProperty(PropertyInfo f, Type declaringType)
        {
            if (f.DeclaringType != declaringType)
                return false;

            return IsSqlParameterType(f.PropertyType);
        }

        /// <summary>
        /// Is the method valid to be called from tsql?
        /// </summary>
        /// <param name="m"></param>
        /// <param name="declaringType"></param>
        /// <returns></returns>
        private static bool IsSqlMethod(MethodInfo m, Type declaringType)
        {
            if (m.DeclaringType != declaringType)
                return false;

            foreach (ParameterInfo info in m.GetParameters())
            {
                if (!IsSqlParameterType(info.ParameterType))
                    return false;
            }

            return IsSqlParameterType(m.ReturnType);
        }

        /// <summary>
        /// Get the udt specified by the clr type name.
        /// </summary>
        /// <param name="udtName"></param>
        /// <returns></returns>
        private static Type GetUdt(string udtName)
        {
            return Type.GetType(udtName, true);
        }

        /// <summary>
        /// Get the methods on a type
        /// </summary>
        /// <param name="t"></param>
        /// <returns></returns>
        private static ICollection GetSqlMethods(Type t)
        {
            MethodInfo[] methods = t.GetMethods(BindingFlags.Instance | BindingFlags.Public | BindingFlags.DeclaredOnly);
            ArrayList temp = new ArrayList();

            foreach (MethodInfo info in methods)
            {
                if (IsSqlMethod(info, t))
                    temp.Add(info);
            }

            return temp;
        }

        /// <summary>
        /// get the properties on a type
        /// </summary>
        /// <param name="t"></param>
        /// <returns></returns>
        private static ICollection GetSqlProperties(Type t)
        {
            PropertyInfo[] props = t.GetProperties(BindingFlags.Instance | BindingFlags.Public | BindingFlags.DeclaredOnly);
            ArrayList temp = new ArrayList();

            foreach (PropertyInfo info in props)
            {
                if (IsSqlProperty(info, t))
                    temp.Add(info);
            }

            return temp;
        }

        /// <summary>
        /// get the fields on a type
        /// </summary>
        /// <param name="t"></param>
        /// <returns></returns>
        private static ICollection GetSqlFields(Type t)
        {
            FieldInfo[] fields = t.GetFields(BindingFlags.Instance | BindingFlags.Public | BindingFlags.DeclaredOnly);
            ArrayList temp = new ArrayList();

            foreach (FieldInfo info in fields)
            {
                if (IsSqlField(info, t))
                    temp.Add(info);
            }

            return temp;
        }

        /// <summary>
        /// readonly static used to cache frequently used information
        /// </summary>
        private static readonly Hashtable validParameterTypes = GetValidParameterTypes();

        /// <summary>
        /// initialize the cached mapping of valid parameter types
        /// </summary>
        private static Hashtable GetValidParameterTypes()
        {
            Hashtable validTypes = new Hashtable();
            validTypes[typeof(bool)] = true;
            validTypes[typeof(byte)] = true;
            validTypes[typeof(short)] = true;
            validTypes[typeof(char)] = true;
            validTypes[typeof(int)] = true;
            validTypes[typeof(float)] = true;
            validTypes[typeof(long)] = true;
            validTypes[typeof(double)] = true;
            validTypes[typeof(string)] = true;
            validTypes[typeof(Guid)] = true;

            return validTypes;
        }
        #endregion

        #region public utility functions
        [Microsoft.SqlServer.Server.SqlFunction(DataAccess = Microsoft.SqlServer.Server.DataAccessKind.Read)]
        public static string GetFullAssemblyName(string sqlName)
        {
            using (SqlConnection conn = new SqlConnection("context connection=true"))
            {
                SqlCommand cmd = conn.CreateCommand();
                cmd.CommandText = @"SELECT @sqlName, "
                + @"assemblyproperty(@sqlName, 'VersionMajor'), "
                + @"assemblyproperty(@sqlName, 'VersionMinor'), "
                + @"assemblyproperty(@sqlName, 'VersionBuild'), "
                + @"assemblyproperty(@sqlName, 'VersionRevision'), "
                + @"assemblyproperty(@sqlName, 'CultureInfo'), "
                + @"assemblyproperty(@sqlName, 'PublicKey'), "
                + @"assemblyproperty(@sqlName, 'Architecture');";

                cmd.Parameters.AddWithValue("@sqlName", sqlName);

                conn.Open();

                SqlDataReader rdr = cmd.ExecuteReader();

                try
                {
                    if (!rdr.Read())
                        throw new ArgumentException(string.Format(
                            CultureInfo.InvariantCulture,
                            "Assembly {0} not found.", sqlName));

                    return GetAssemblyName(rdr.GetString(0), rdr.GetInt32(1),
                        rdr.GetInt32(2), rdr.GetInt32(3),
                        rdr.GetInt32(4), (rdr.IsDBNull(5)
                        ? SqlString.Null : rdr.GetSqlString(5)),
                        (rdr.IsDBNull(6) ? SqlBinary.Null : rdr.GetSqlBinary(6)),
                        rdr.IsDBNull(7) ? SqlString.Null : rdr.GetSqlString(7));
                }
                finally
                {
                    rdr.Close();
                }
            }
        }

        /// <summary>
        /// helper function to return the assembly name from 
        /// its components stored in sql metadata
        /// </summary>
        /// <param name="friendlyName"></param>
        /// <param name="major_version"></param>
        /// <param name="minor_version"></param>
        /// <param name="build"></param>
        /// <param name="revision"></param>
        /// <param name="culture"></param>
        /// <param name="publicKeyToken"></param>
        /// <returns></returns>
        private static string GetAssemblyName(string friendlyName, int majorVersion, int minorVersion,
            int build, int revision, SqlString culture, SqlBinary publicKeyToken, SqlString processorArchitecture)
        {
            StringBuilder sb = new StringBuilder();
            sb.Append(friendlyName).Append(", ");
            sb.Append("version=");
            sb.Append(majorVersion).Append('.');
            sb.Append(minorVersion).Append('.');
            sb.Append(build).Append('.');
            sb.Append(revision).Append(", ");
            sb.Append("culture=").Append(culture.IsNull ? "neutral" : culture.Value).Append(", ");
            sb.Append("publickeytoken=");
            if (publicKeyToken.IsNull)
            {
                sb.Append("null");
            }
            else
            {
                foreach (byte b in publicKeyToken.Value)
                {
                    sb.Append(b.ToString("X2", CultureInfo.InvariantCulture));
                }
            }

            sb.Append(", ");
            sb.Append("processorarchitecture=");
            sb.Append(processorArchitecture.IsNull ? "msil" : processorArchitecture.Value);

            return sb.ToString();
        }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Performance", "CA1811:AvoidUncalledPrivateCode")]
        private static string ToHexString(byte[] value)
        {
            if (value == null)
                return null;

            StringBuilder sb = new StringBuilder();
            foreach (byte b in value)
            {
                sb.Append(b.ToString("X2", CultureInfo.InvariantCulture));
            }

            return sb.ToString();
        }

        #endregion
    }
}