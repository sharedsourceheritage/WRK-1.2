'=====================================================================
'
'  File:    LargeObjectBinary.vb for Large Binary Object SQLCLR Example
'  Summary: Defines SQLCLR based stored procedures for storing and 
'           retrieving large binary objects between the database and
'           filestores accessible from the server.
'  Date:    May 24, 2004
'
'---------------------------------------------------------------------
'
'  This file is part of the Microsoft SQL Server Code Samples.
'  Copyright (C) 2004 Microsoft Corporation.  All rights reserved.
'
'  This source code is intended only as a supplement to Microsoft
'  Development Tools and/or on-line documentation.  See these other
'  materials for detailed information regarding Microsoft code samples.
'
'  THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
'  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
'  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
'  PARTICULAR PURPOSE.
'
'======================================================= 

''' <summary>
''' Date:       May 22, 2004
''' Purpose:    The purpose of this sample is to show:
'''            1) how to read binary data from a file and store the contents into a database
'''            2) how to retrieve binary data stored in the database and write the contents to a file
'''        This version of the sample is designed to run server side.  
'''        Note that in Yukon Beta 1, VARBINARY(MAX) only supports 8000 
'''        bytes of data from CLR stored procedures.
'''        Any additional data will be silently truncated.
'''
''' Connects to a database and contains the methods for reading and writing
''' large binary objects to and from the database.
''' </summary>
Public NotInheritable Class LargeObjectBinary
    'Recommended chunk size for processing large amounts of data
    Private Const bufferSize As Integer = 4000

    ''' <summary>
    '''    This class only contains static members, therefore it needs no public constructor.
    ''' </summary>
    Private Sub New()
    End Sub

    ''' <summary>
    ''' Retrieves a thumbnail photograph from the database into a file assessible to the server.  
    ''' </summary>
    ''' <param name="photoId">Unique identifier for a product picture.</param>
    ''' <param name="currentDirectory">Which folder to put the picture into.</param>
    ''' <param name="fileName">What to call the picture in the specified folder.</param>
    <Microsoft.SqlServer.Server.SqlProcedure()> _
    Public Shared Sub GetPhotoFromDB(ByVal photoId As Integer, _
        ByVal currentDirectory As String, ByVal fileName As String)
        Dim sqlReader As SqlDataReader = Nothing

        Dim conn As SqlConnection = New SqlConnection("context connection = true")
        conn.Open()

        Dim sprocCommand As SqlCommand = conn.CreateCommand()
        'Even though we are supply an int, it is a good habit to use parameters to insert
        'values into command text rather than using String.Format.  In the 
        'case of string parameters, it can help prevent injection attacks.
        sprocCommand.CommandText = "SELECT ThumbNailPhoto FROM Production.ProductPhoto " _
            & "WHERE ProductPhotoID = @ProductPhotoID"
        sprocCommand.Parameters.Add("@ProductPhotoID", SqlDbType.Int)
        sprocCommand.Parameters(0).Value = photoId

        'TODO: Is getting chunks the best way to retrieve LOB from the database?  Is there a limit?
        Try
            sqlReader = sprocCommand.ExecuteReader() 'CommandBehavior.SequentialAccess
            If sqlReader Is Nothing Then
                LogError(currentDirectory, "ExecuteReader failed!")
            Else
                If sqlReader.Read() Then
                    ' Create a file to hold the output.
                    If (Not Directory.Exists(currentDirectory)) Then
                        Directory.CreateDirectory(currentDirectory)
                    End If

                    fileName = currentDirectory + fileName
                    Dim fileStream As New FileStream(fileName, FileMode.OpenOrCreate, FileAccess.Write)
                    Try
                        Dim binaryWriter As New BinaryWriter(fileStream)
                        Try
                            ' The BLOB byte() buffer to be filled by GetBytes.
                            Dim outbyte(bufferSize) As Byte

                            ' The starting position in the BLOB output.
                            Dim startIndex As Long = 0

                            ' Read the bytes into outbyte() and retain the number of bytes returned.
                            Dim retval As Long = sqlReader.GetBytes(0, startIndex, outbyte, 0, bufferSize)

                            ' Continue reading and writing while there are 
                            ' bytes beyond the size of the buffer.
                            While retval = bufferSize
                                binaryWriter.Write(outbyte)

                                ' Reposition the start index to the end of 
                                ' the last buffer and fill the buffer.
                                startIndex += bufferSize
                                retval = sqlReader.GetBytes(0, startIndex, outbyte, 0, bufferSize)
                            End While

                            ' Write the remaining buffer.
                            binaryWriter.Write(outbyte)
                        Finally
                            binaryWriter.Close()
                        End Try
                    Finally
                        fileStream.Close()
                    End Try 'binaryWriter.Flush();
                Else
                    LogError(currentDirectory, "No row returned!")
                End If
            End If
        Catch e As SqlException
            LogError(currentDirectory, String.Format(CultureInfo.InvariantCulture, _
                "Unable to copy binary contents from database.  Error: {0}", e.ToString()))
        Finally
            If Not (sqlReader Is Nothing) Then
                sqlReader.Close()
            End If
        End Try
    End Sub

    ''' <summary>
    ''' Saves a thumbnail picture into the database from a file accessible to the server.
    ''' </summary>
    ''' <param name="photoId">Unique identifier for a product picture.</param>
    ''' <param name="currentDirectory">Which folder to get the picture from.</param>
    ''' <param name="fileName">What the picture in the specified folder is called.</param>
    <Microsoft.SqlServer.Server.SqlProcedure()> _
    Public Shared Sub PutPhotoIntoDB(ByVal photoId As Integer, _
        ByVal currentDirectory As String, ByVal fileName As String)
        'TODO: Is there a limit on how large the LOB can be?
        Dim fullFileName As String = currentDirectory + fileName
        Dim bytes As Byte() = ReadFile(fullFileName)

        Try
            Dim conn As SqlConnection = New SqlConnection("context connection = true")
            conn.Open()

            Dim sprocCommand As SqlCommand = conn.CreateCommand()
            sprocCommand.CommandText = "dbo.usp_UpdateImage"
            sprocCommand.CommandType = CommandType.StoredProcedure

            sprocCommand.Parameters.Add(New SqlParameter("@ProductPhotoID", SqlDbType.Int))
            ' Add time to the short name because there is an unique constraint on this column.
            sprocCommand.Parameters(0).Value = photoId
            sprocCommand.Parameters.Add(New SqlParameter("@ThumbNailPhoto", SqlDbType.VarBinary))
            sprocCommand.Parameters(1).Value = bytes
            sprocCommand.ExecuteNonQuery()
        Catch e As SqlException
            LogError(currentDirectory, String.Format(CultureInfo.InvariantCulture, _
                "Unable to update binary contents into the database.  Error: {0}", e.ToString()))
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
            Dim bytes() As Byte = New Byte(CType(fileSize, Integer)) {}
            binaryReader.Read(bytes, 0, CType(fileSize, Integer))
            Return bytes
        Finally
            binaryReader.Close()
        End Try
    End Function

    ''' <summary>
    '''        Appends a message to a file accessible to the server.  When System.Diagnostics is available from
    '''        CLR Sprocs this should be changed to use the event log.
    ''' </summary>
    ''' <param name="currentDirectory">Which folder the message log file resides in</param>
    ''' <param name="errorMessage">The text to add to the message log file</param>
    Private Shared Sub LogError(ByVal currentDirectory As String, ByVal errorMessage As String)
        Dim errorLogStream As New FileStream(currentDirectory + "error.log", FileMode.Append, FileAccess.Write)
        Try
            Dim errorLogWriter As New StreamWriter(errorLogStream)
            Try
                errorLogWriter.WriteLine(errorMessage)
            Finally
                errorLogWriter.Close()
            End Try
        Finally
            errorLogStream.Close()
        End Try
    End Sub
End Class
