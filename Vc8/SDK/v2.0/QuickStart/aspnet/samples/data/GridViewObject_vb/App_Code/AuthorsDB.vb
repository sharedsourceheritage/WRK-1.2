'-----------------------------------------------------------------------
'  This file is part of the Microsoft .NET SDK Code Samples.
' 
'  Copyright (C) Microsoft Corporation.  All rights reserved.
' 
'This source code is intended only as a supplement to Microsoft
'Development Tools and/or on-line documentation.  See these other
'materials for detailed information regarding Microsoft code samples.
' 
'THIS CODE AND INFORMATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY
'KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
'IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
'PARTICULAR PURPOSE.
'-----------------------------------------------------------------------
Imports System

Public Class AuthorsDB
    Public Sub New()
    End Sub

    Shared Function GetAuthorsByState(ByVal state As String) As System.Data.DataSet
        Dim connectionString As String = ConfigurationManager.ConnectionStrings("Pubs").ConnectionString
        Dim dbConnection As System.Data.IDbConnection = New System.Data.SqlClient.SqlConnection(connectionString)

        Dim queryString As String = "SELECT [authors].[au_id], [authors].[au_fname], [authors].[au_lname], [authors].[" & _
            "state] FROM [authors] WHERE ([authors].[state] = @state)"
        Dim dbCommand As System.Data.IDbCommand = New System.Data.SqlClient.SqlCommand
        dbCommand.CommandText = queryString
        dbCommand.Connection = dbConnection

        Dim dbParam_state As System.Data.IDataParameter = New System.Data.SqlClient.SqlParameter
        dbParam_state.ParameterName = "@state"
        dbParam_state.Value = state
        dbParam_state.DbType = System.Data.DbType.StringFixedLength
        dbCommand.Parameters.Add(dbParam_state)

        Dim dataAdapter As System.Data.IDbDataAdapter = New System.Data.SqlClient.SqlDataAdapter
        dataAdapter.SelectCommand = dbCommand
        Dim dataSet As System.Data.DataSet = New System.Data.DataSet
        dataAdapter.Fill(dataSet)

        Return dataSet
    End Function

    Shared Function GetStates() As System.Data.DataSet
        Dim connectionString As String = ConfigurationManager.ConnectionStrings("Pubs").ConnectionString
        Dim dbConnection As System.Data.IDbConnection = New System.Data.SqlClient.SqlConnection(connectionString)

        Dim queryString As String = "SELECT DISTINCT [authors].[state] FROM [authors]"
        Dim dbCommand As System.Data.IDbCommand = New System.Data.SqlClient.SqlCommand
        dbCommand.CommandText = queryString
        dbCommand.Connection = dbConnection

        Dim dataAdapter As System.Data.IDbDataAdapter = New System.Data.SqlClient.SqlDataAdapter
        dataAdapter.SelectCommand = dbCommand
        Dim dataSet As System.Data.DataSet = New System.Data.DataSet
        dataAdapter.Fill(dataSet)

        Return dataSet
    End Function

    Shared Function UpdateAuthor(ByVal au_id As String, ByVal au_lname As String, ByVal au_fname As String, ByVal state As String) As Integer
        Dim connectionString As String = ConfigurationManager.ConnectionStrings("Pubs").ConnectionString
        Dim dbConnection As System.Data.IDbConnection = New System.Data.SqlClient.SqlConnection(connectionString)

        Dim queryString As String = "UPDATE [authors] SET [au_lname]=@au_lname, [au_fname]=@au_fname, [state]=@state W" & _
            "HERE ([authors].[au_id] = @au_id)"
        Dim dbCommand As System.Data.IDbCommand = New System.Data.SqlClient.SqlCommand
        dbCommand.CommandText = queryString
        dbCommand.Connection = dbConnection

        Dim dbParam_au_id As System.Data.IDataParameter = New System.Data.SqlClient.SqlParameter
        dbParam_au_id.ParameterName = "@au_id"
        dbParam_au_id.Value = au_id
        dbParam_au_id.DbType = System.Data.DbType.[String]
        dbCommand.Parameters.Add(dbParam_au_id)
        Dim dbParam_au_lname As System.Data.IDataParameter = New System.Data.SqlClient.SqlParameter
        dbParam_au_lname.ParameterName = "@au_lname"
        dbParam_au_lname.Value = au_lname
        dbParam_au_lname.DbType = System.Data.DbType.[String]
        dbCommand.Parameters.Add(dbParam_au_lname)
        Dim dbParam_au_fname As System.Data.IDataParameter = New System.Data.SqlClient.SqlParameter
        dbParam_au_fname.ParameterName = "@au_fname"
        dbParam_au_fname.Value = au_fname
        dbParam_au_fname.DbType = System.Data.DbType.[String]
        dbCommand.Parameters.Add(dbParam_au_fname)
        Dim dbParam_state As System.Data.IDataParameter = New System.Data.SqlClient.SqlParameter
        dbParam_state.ParameterName = "@state"
        dbParam_state.Value = state
        dbParam_state.DbType = System.Data.DbType.StringFixedLength
        dbCommand.Parameters.Add(dbParam_state)

        Dim rowsAffected As Integer = 0
        dbConnection.Open()
        Try
            rowsAffected = dbCommand.ExecuteNonQuery
        Finally
            dbConnection.Close()
        End Try

        Return rowsAffected
    End Function

End Class

