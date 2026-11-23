'=====================================================================
'
'  File:    inprocda.vb
'  Summary: Simple examples to demonstrate in-proc data access features
'  Date:    June 14, 2004
'
'---------------------------------------------------------------------
'  This file is part of the Microsoft SQL Server Code Samples.
'  Copyright (C) Microsoft Corporation.  All rights reserved.
'
'  This source code is intended only as a supplement to Microsoft
'  Development Tools and/or on-line documentation.  See these other
'  materials for detailed information regarding Microsoft code samples.

'  THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
'  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
'  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
'  PARTICULAR PURPOSE.
''======================================================= 

<Assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1020:AvoidNamespacesWithFewTypes", Scope:="namespace", Target:="Microsoft.Samples.SqlServer")> 

Partial Public NotInheritable Class DataAccessDemo
    Private Sub New()
    End Sub

    ''' <summary>
    ''' Simple example of performing data access within a function
    ''' </summary>
    ''' <returns></returns>
    <SqlFunction(DataAccess:=DataAccessKind.Read)> _
    Public Shared Function ReportSqlVersion() As SqlString
        Using conn As New SqlConnection("context connection=true")
            'create a command from the current context
            Dim cmd As SqlCommand = conn.CreateCommand()

            'execute something
            cmd.CommandText = "SELECT @@VERSION"

            conn.Open()

            'return results as scalar
            Return CType(cmd.ExecuteScalar(), String)
        End Using
    End Function

    ''' <summary>
    ''' Simple example to send a message to the client.
    ''' </summary>
    Public Shared Sub SendMessage(ByVal msg As String)
        SqlContext.Pipe.Send(("Message from server: " & msg))
    End Sub

    ''' <summary>
    ''' Create a result set on the fly and send it to the client.
    ''' </summary>
    Public Shared Sub SendTransientResultSet()
        'create the metadata for the columns
        Dim columnSchema() As Microsoft.SqlServer.Server.SqlMetaData _
            = {New SqlMetaData("stringcol", SqlDbType.NVarChar, 128)}


        'create a record based on that metadata
        Dim newRecord As New SqlDataRecord(columnSchema)

        'populate it
        newRecord.SetString(0, "Hello World!")

        'send it
        SqlContext.Pipe.Send(newRecord)
    End Sub

    ''' <summary>
    ''' Execute a command and send the results to the client directly.
    ''' </summary>
    Public Shared Sub ExecuteToClient()
        Using conn As New SqlConnection("context connection=true")
            Dim cmd As SqlCommand = conn.CreateCommand()

            cmd.CommandText = "SELECT @@VERSION"
            conn.Open()
            SqlContext.Pipe.ExecuteAndSend(cmd)
        End Using
    End Sub

    ''' <summary>
    ''' Execute a command and send the resultig reader to the client
    ''' </summary>
    Public Shared Sub SendReaderToClient()
        Using conn As New SqlConnection("context connection=true")
            Dim cmd As SqlCommand = conn.CreateCommand()
            cmd.CommandText = "SELECT @@VERSION"
            conn.Open()
            Dim rdr As SqlDataReader = cmd.ExecuteReader()
            Try
                SqlContext.Pipe.Send(rdr)
            Finally
                rdr.Close()
            End Try
        End Using
    End Sub


End Class
