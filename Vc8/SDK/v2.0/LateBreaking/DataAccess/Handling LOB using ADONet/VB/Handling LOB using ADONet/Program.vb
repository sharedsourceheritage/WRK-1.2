'=====================================================================
'
'  File:     Program.vb for Handling LOB using ADO.Net Example
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
Option Strict On

Imports System
Imports System.IO

'/ <summary>
'/ Entry point for the sample.
'/ </summary>
Module Program
    '/ <summary>
    '/ Command line sample showing how to read/write large binary objects stored in the database.
    '/ <param name="args[]">Input parameters.</param>        
    '/        /in:    Name of the file to read and store contents in the database. 
    '/        /out:    Name of the file to store the contents read from the database.
    '/        /dsrc:    Name of the database server.
    '/ </summary>        
    Sub Main(ByVal args() As String)

        ' Set default values for input parameters.
        Dim DocumentID As Int32 = 1

        ' Get the path location of the test file to be saved in the database.
        Dim datafilesDirectory As String = Directory.GetCurrentDirectory() + "\"
        Dim stringLength As Int32 = datafilesDirectory.IndexOf("VB\Handling LOB using ADONet\bin") - 1
        datafilesDirectory = datafilesDirectory.Substring(0, stringLength) + "\DataFiles\"

        ' Use the user's application data folder to save the contents of varbinary(max) column.
        Dim userDirectory As String = System.Environment.GetEnvironmentVariable("APPDATA") + "\"

        Dim inFileName As String = "testdoc.doc"
        Dim outFileName As String = "docout.doc"

        Dim dataSource As String = "."

        ' Split the parameters passed into individual arrays so that they can processed correctly.
        Dim i As Integer
        For i = 0 To args.Length - 1
            Dim arg As String = args(i)

            ' Name of the file to read and store contents in the database. 
            If arg.StartsWith("/in:") Then
                inFileName = arg.Substring(4)
                ' Name of the file to store the contents read from the database.
            ElseIf arg.StartsWith("/out:") Then
                outFileName = arg.Substring(5)
                ' Name of the database server.
            ElseIf arg.StartsWith("/dsrc:") Then
                dataSource = arg.Substring(6)
            End If
        Next i
        Try
            ' Make sure the folders / files exist.
            Dim directoryInfo As New DirectoryInfo(datafilesDirectory)
            If Not directoryInfo.Exists Then
                Throw New DirectoryNotFoundException("Folder not found:  " + datafilesDirectory)
            End If
            directoryInfo = New DirectoryInfo(userDirectory)
            If Not directoryInfo.Exists Then
                Throw New DirectoryNotFoundException("Folder not found:  " + userDirectory)
            End If

            Dim fileInfo As New FileInfo(datafilesDirectory + inFileName)
            If Not fileInfo.Exists Then
                Throw New FileNotFoundException("File not found.", inFileName)
            End If
            Dim largeObjectBinary As New LargeObjectBinary(dataSource)
            ' Reads large binary objects from the database into a file.
            largeObjectBinary.GetDocumentFromDatabase(DocumentID, userDirectory, outFileName)
            ' Save the contents of a file in the database.
            largeObjectBinary.InsertDocument(datafilesDirectory, inFileName, fileInfo.Extension)
        Catch e As SystemException
            Console.WriteLine("Something went wrong, {0}", e.ToString())
            Environment.Exit(1)
        End Try
        Environment.Exit(0)
    End Sub
End Module
