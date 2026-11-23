'-----------------------------------------------------------------------
'  This file is part of the Microsoft .NET Framework SDK Code Samples.
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
Imports System.DirectoryServices
Namespace Microsoft.Samples

    Public NotInheritable Class ADRead

        Private Sub New()

        End Sub

        Public Shared Sub Main()
            If (Environment.GetCommandLineArgs().Length <> 2) Then
                Console.WriteLine("Usage: " & Environment.GetCommandLineArgs()(0) & " <ad_path>")
                Console.WriteLine()
                Console.WriteLine("Press Enter to continue...")
                Console.ReadLine()
                Exit Sub
            End If

            Dim objDirEnt As DirectoryEntry = New DirectoryEntry(Environment.GetCommandLineArgs(1))
            Console.WriteLine("Name            = " & objDirEnt.Name)
            Console.WriteLine("Path            = " & objDirEnt.Path)
            Console.WriteLine("SchemaClassName = " & objDirEnt.SchemaClassName)
            Console.WriteLine("")
            Console.WriteLine("Properties:")

            Dim tab As String = "    "
            Dim Key As String
            Dim objValue As Object

            For Each Key In objDirEnt.Properties.PropertyNames
                Console.Write(tab & Key & " = ")
                Console.WriteLine("")
                For Each objValue In objDirEnt.Properties(Key)
                    Console.WriteLine(tab & tab & objValue.ToString())
                Next objValue
            Next
        End Sub

    End Class

End Namespace
