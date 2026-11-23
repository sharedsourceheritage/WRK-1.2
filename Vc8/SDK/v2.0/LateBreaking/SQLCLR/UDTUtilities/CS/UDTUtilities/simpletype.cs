/*=====================================================================

  File:      simpletype.cs
  Summary:   Simple udt, used to drive the type browser sample
  Date:	     Sep 23, 2003

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
using System.Data.Sql;
using System.Data.SqlTypes;
using System.Globalization;
using Microsoft.SqlServer.Server;

namespace Microsoft.Samples.SqlServer
{
    [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Performance", "CA1815:OverrideEqualsAndOperatorEqualsOnValueTypes"), Microsoft.SqlServer.Server.SqlUserDefinedTypeAttribute(Microsoft.SqlServer.Server.Format.Native)]
    [Serializable]
    public struct SimpleUdt : INullable
    {
        #region udt contract
        public override string ToString()
        {
            return base.ToString();
        }


        public bool IsNull
        {
            get
            {
                return this._value.IsNull;
            }
        }


        public static SimpleUdt Null
        {
            get
            {
                SimpleUdt h = new SimpleUdt();

                return h;
            }
        }


        public static SimpleUdt Parse(SqlString sqlString)
        {
            if (sqlString.IsNull)
                return Null;

            SimpleUdt u = new SimpleUdt();

            u.Value = new SqlInt32(int.Parse(sqlString.Value,
                CultureInfo.InvariantCulture));

            return u;
        }
        #endregion

        #region implementation
        private SqlInt32 _value;

        private SqlInt32 _examplePublicField;

        public SqlInt32 ExamplePublicField
        {
            get
            {
                return this._examplePublicField;
            }
            set
            {
                this._examplePublicField = value;
            }
        }


        public SqlInt32 Value
        {
            get
            {
                return this._value;
            }
            set
            {
                this._value = value;
            }
        }

        [Microsoft.SqlServer.Server.SqlMethod(IsDeterministic = true)]
        public SqlInt32 ReturnValue()
        {
            return this._value;
        }

        #endregion
    }
}