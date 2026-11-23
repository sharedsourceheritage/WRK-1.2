'=====================================================================
'
'  File:     LargeObjectBinary.vb for Handling LOB using ADO.Net Example
'  Summary:  The purpose of this sample is to show:'
'                1) how to read binary data from a file and store the 
'                   contents into a database
'                2) how to retrieve binary data stored in the database 
'                   and write the contents to a file
'  Date:        April 14, 2003
'
'---------------------------------------------------------------------
'  This file is part of the Microsoft SQL Server Code Samples.
'  Copyright (C) Microsoft Corporation.  All rights reserved.
'
'  This source code is intended only as a supplement to Microsoft
'  Development Tools and/or on-line documentation.  See these other
'  materials for detailed information regarding Microsoft code samples.
'
'  THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
'  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
'  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
'  PARTICULAR PURPOSE.
'======================================================================== 

Option Explicit On

Imports System
Imports System.Data
Imports System.Data.SqlClient
Imports System.IO
Imports System.Security

Public Class LargeObjectBinary
    ' Size of the BLOB buffer.
    ' Use sp_configure (with show advanced option on) to find the optimal value.  It should be based on the network packet size.
    ' In general, 4k is considered a good default for most situations.
    Private Const bufferSize As Integer = 4096

    Private connectionString As String

    ''' <summary>
    ''' Contains methods for reading and writing large binary objects to and from the database.
    ''' </summary>
    ''' <param name="dataSource">Name of the server that has the sample database AdventureWorks installed on it.</param>
    Public Sub New(ByVal dataSource As String)
        connectionString = "data source=" + dataSource + ";initial catalog=AdventureWorks;Integrated Security=SSPI"
    End Sub

    ''' <summary>
    ''' Reads large binary objects from the database into a file.  
    ''' This file is saved to a file on the users machine.
    ''' </summary>
    ''' <param name="DocumentID">Unique identifier for a Document.</param>
    ''' <param name="userDirectory">The current directory path.</param>
    ''' <param name="fileName">The file name to store the contents read from the database.</param>
    Public Sub GetDocumentFromDatabase(ByVal documentId As Int32, ByVal userDirectory As String, ByVal fileName As String)
        Dim sqlReader As SqlDataReader = Nothing

        Dim sqlConn As New SqlConnection(connectionString)
        Try
            sqlConn.Open()
            Dim sprocCommand As New SqlCommand("[Production].[usp_GetDocumentByID]", sqlConn)
            Try
                sprocCommand.CommandType = CommandType.StoredProcedure
                sprocCommand.Parameters.Add(New SqlParameter("@DocumentID", SqlDbType.Int))
                sprocCommand.Parameters(0).Value = documentId

                Try
                    sqlReader = sprocCommand.ExecuteReader(CommandBehavior.SequentialAccess)
                    sqlReader.Read()

                    ' Create a file to hold the output.
                    fileName = userDirectory + fileName
                    Dim fileStream As New FileStream(fileName, FileMode.Create, FileAccess.Write)
                    Try
                        Dim binaryWriter As New BinaryWriter(fileStream)
                        Try
                            ' The BLOB byte[] buffer to be filled by GetBytes.
                            Dim outbyte(bufferSize) As Byte

                            ' The starting position in the BLOB output.
                            Dim startIndex As Long = 0

                            ' Read the bytes into outbyte[] and retain the number of bytes returned.
                            Dim retval As Long = sqlReader.GetBytes(0, startIndex, outbyte, 0, bufferSize)

                            ' Continue reading and writing while there are bytes beyond the size of the buffer.
                            While retval = bufferSize
                                binaryWriter.Write(outbyte, 0, CInt(retval))

                                ' Reposition the start index to the end of the last buffer and fill the buffer.
                                startIndex += bufferSize
                                retval = sqlReader.GetBytes(0, startIndex, outbyte, 0, bufferSize)
                            End While

                            ' Write the remaining buffer.
                            binaryWriter.Write(outbyte, 0, CInt(retval))
                        Finally
                            binaryWriter.Close()
                        End Try
                    Finally
                        fileStream.Close()
                    End Try
                Finally
                    sqlReader.Close()
                End Try
            Finally
                sprocCommand.Dispose()
            End Try
        Finally
            sqlConn.Dispose()
        End Try
    End Sub

    ''' <summary>
    ''' Save the contents of a file in the database.
    ''' </summary>
    ''' <param name="datafilesDirectory"></param>
    ''' <param name="fileName">The file name containing the contents to be read and stored in the database.</param>
    ''' <param name="fileExtension"></param>
    ''' <remarks></remarks>
    Public Sub InsertDocument(ByVal datafilesDirectory As String, ByVal fileName As String, ByVal fileExtension As String)
        ' Note:  Max limit on the input file is 2G.
        Dim fullFileName As String = datafilesDirectory + fileName
        Dim bytes As Byte() = ReadFile(fullFileName)
        Dim sqlConn As New SqlConnection(connectionString)
        Try
            Dim sprocCommand As New SqlCommand("[Production].[usp_InsertDocument]", sqlConn)
            Try
                sqlConn.Open()
                sprocCommand.CommandType = CommandType.StoredProcedure
                sprocCommand.Parameters.Add(New SqlParameter("@Title", SqlDbType.NVarChar, 50))
                ' Add time to the short name because there is an unique constraint on this column.
                sprocCommand.Parameters(0).Value = fileName + DateTime.Now.TimeOfDay.ToString()
                sprocCommand.Parameters.Add(New SqlParameter("@FileName", SqlDbType.NVarChar, 400))
                sprocCommand.Parameters(1).Value = fullFileName
                sprocCommand.Parameters.Add(New SqlParameter("@FileExtension", SqlDbType.NVarChar, 8))
                sprocCommand.Parameters(2).Value = fileExtension
                sprocCommand.Parameters.Add(New SqlParameter("@Status", SqlDbType.TinyInt))
                sprocCommand.Parameters(3).Value = 1
                sprocCommand.Parameters.Add(New SqlParameter("@Document", SqlDbType.Image))
                sprocCommand.Parameters(4).Value = bytes
                sprocCommand.Parameters.Add(New SqlParameter("@DocumentID", SqlDbType.Int))
                sprocCommand.Parameters(5).Direction = ParameterDirection.Output
                sprocCommand.ExecuteNonQuery()
                'Dim DocumentID As Integer = CInt(sprocCommand.Parameters(5).Value)
            Finally
                sprocCommand.Dispose()
            End Try
        Finally
            sqlConn.Dispose()
        End Try
    End Sub

    ''' <summary>
    ''' Read the contents of a file and return the bytes.
    ''' </summary>
    ''' <param name="fileName">The name of the file to be read.</param>
    ''' <returns></returns>
    Private Shared Function ReadFile(ByVal fileName As String) As Byte()
        ' Open the file assuming the file is in ASCII format.
        Dim binaryReader As New BinaryReader(CType(File.OpenRead(fileName), Stream), System.Text.Encoding.ASCII)
        Try
            Dim fileSize As Long = binaryReader.BaseStream.Length
            Dim bytes() As Byte = New Byte(CInt(fileSize)) {}
            binaryReader.Read(bytes, 0, CInt(fileSize))
            Return bytes
        Finally
            binaryReader.Close()
        End Try
    End Function
End Class
