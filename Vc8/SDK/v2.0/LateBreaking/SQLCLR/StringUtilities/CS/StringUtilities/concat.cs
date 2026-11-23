
/*=====================================================================

  File:      Concatenate.cs for User Defined Aggregate SQLCLR Example
  Summary:   Defines an aggregate for Concatenatenating string values into
			 a comma delimited string.
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
using System.IO;
using System.Data.Sql;
using System.Data.SqlTypes;
using System.Text;
using Microsoft.SqlServer.Server;

[assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1020:AvoidNamespacesWithFewTypes", Scope = "namespace", Target = "Microsoft.Samples.SqlServer")]

namespace Microsoft.Samples.SqlServer
{
    [Serializable]
    [Microsoft.SqlServer.Server.SqlUserDefinedAggregate(
        Microsoft.SqlServer.Server.Format.UserDefined, //use clr serialization to serialize the intermediate result
        IsInvariantToNulls = true,			//optimizer property
        IsInvariantToDuplicates = false,		//optimizer property
        IsInvariantToOrder = false,			//optimizer property
        MaxByteSize = 8000)					//maximum size in bytes of persisted value
        ]
    public class Concatenate : Microsoft.SqlServer.Server.IBinarySerialize
    {
        /// <summary>
        /// The variable that holds the intermediate result of the concatenation
        /// </summary>
        private StringBuilder intermediateResult;

        /// <summary>
        /// Initialize the internal data structures
        /// </summary>
        public void Init()
        {
            intermediateResult = new StringBuilder();
        }

        /// <summary>
        /// Accumulate the next value, nop if the value is null
        /// </summary>
        /// <param name="value"></param>
        public void Accumulate(SqlString value)
        {

            if (value.IsNull)
            {
                return;
            }
            intermediateResult.Append(value.Value).Append(',');

        }

        /// <summary>
        /// Merge the partially computed aggregate with this aggregate.
        /// </summary>
        /// <param name="other"></param>
        public void Merge(Concatenate other)
        {
            intermediateResult.Append(other.intermediateResult);
        }

        /// <summary>
        /// Called at the end of aggregation, to return the results of the aggregation
        /// </summary>
        /// <returns></returns>
        public SqlString Terminate()
        {
            string output = string.Empty;
            //delete the trailing comma, if any
            if (intermediateResult != null && intermediateResult.Length > 0)
                output = intermediateResult.ToString(0, intermediateResult.Length - 1);
            return new SqlString(output);
        }

        public void Read(BinaryReader r)
        {
            intermediateResult = new StringBuilder(r.ReadString());
        }

        public void Write(BinaryWriter w)
        {
            w.Write(intermediateResult.ToString());
        }
    }
}