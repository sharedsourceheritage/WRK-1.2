using System;
using System.Data;
using System.Data.Sql;
using System.Data.SqlTypes;
using Microsoft.SqlServer.Server;

/*=====================================================================

  File:      Hello.cs for HelloWorld CLR integration example
  Summary:   Simple sample which demonstrates assembly and stored procedure
             basics, and also offers a contrasts between unmanaged extended
             stored procedures and CLR integration stored procedures.
  Date:		 December 14, 2004

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
    public sealed partial class Hello
    {
        private Hello()
        {
        }

        [System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1021:AvoidOutParameters"), Microsoft.SqlServer.Server.SqlProcedure]
        public static void HelloWorld(out string greeting)
        {
            Microsoft.SqlServer.Server.SqlMetaData columnInfo
                = new Microsoft.SqlServer.Server.SqlMetaData("Column1", SqlDbType.NVarChar, 12);
            SqlDataRecord greetingRecord
                = new SqlDataRecord(new Microsoft.SqlServer.Server.SqlMetaData[] { columnInfo });
            greetingRecord.SetString(0, "Hello World!");
            SqlContext.Pipe.Send(greetingRecord);
            greeting = "Hello World!";
        }
    }
}
