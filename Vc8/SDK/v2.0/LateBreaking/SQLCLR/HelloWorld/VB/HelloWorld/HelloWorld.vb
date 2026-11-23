'/*=====================================================================
'  File:    Hello.vb for HelloWorld CLR integration example
'  Summary: Simple sample which demonstrates assembly and stored procedure
'           basics, and also offers a contrasts between unmanaged extended
'           stored procedures and CLR integration stored procedures.
'  Date:    February 09, 2005
'---------------------------------------------------------------------
'  This file is part of the Microsoft SQL Server Code Samples.
'  Copyright (C) Microsoft Corporation.  All rights reserved.

'  This source code is intended only as a supplement to Microsoft
'  Development Tools and/or on-line documentation.  See these other
'  materials for detailed information regarding Microsoft code samples.
'
'  THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
'  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
'  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
'  PARTICULAR PURPOSE.
'======================================================= */

Imports System
Imports System.Data
Imports System.Data.Sql
Imports System.Data.SqlTypes
Imports Microsoft.SqlServer.Server

Partial Public NotInheritable Class StoredProcedures
    Private Sub New()
    End Sub

    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1045:DoNotPassTypesByReference")> <Microsoft.SqlServer.Server.SqlProcedure()> _
    Public Shared Sub HelloWorld(ByRef greeting As String)
        Dim columnInfo As New Microsoft.SqlServer.Server.SqlMetaData("Column1", _
            SqlDbType.NVarChar, 12)
        Dim greetingRecord As New SqlDataRecord(New _
            Microsoft.SqlServer.Server.SqlMetaData() {columnInfo})
        greetingRecord.SetString(0, "Hello World!")
        SqlContext.Pipe.Send(greetingRecord)
        greeting = "Hello World!"
    End Sub
End Class
