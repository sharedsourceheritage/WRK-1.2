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

    Public NotInheritable Class ADWrite

        Private Sub New()

        End Sub

        Public Shared Sub Main()
            If Environment.GetCommandLineArgs().Length <> 4 Then
                Console.WriteLine("Usage: " + Environment.GetCommandLineArgs()(0) + " <ad_path> <property> <value>")
                Console.WriteLine()
                Console.WriteLine("Press Enter to continue...")
                Console.ReadLine()
                Exit Sub
            End If

            Dim adPath As String = Environment.GetCommandLineArgs()(1)
            Dim propertyName As String = Environment.GetCommandLineArgs()(2)
            Dim newValue As String = Environment.GetCommandLineArgs()(3)
            Dim o As Object

            Dim objDirEnt As DirectoryEntry = New DirectoryEntry(adPath)
            Console.WriteLine("Name            = " + objDirEnt.Name)
            Console.WriteLine("Path            = " + objDirEnt.Path)
            Console.WriteLine("SchemaClassName = " + objDirEnt.SchemaClassName)            
            If objDirEnt.Properties.Contains(propertyName) Then                
                For Each o In objDirEnt.Properties(propertyName)
                    Console.WriteLine("{0} = {1}", propertyName, o.ToString())
                Next                
            Else
                Console.WriteLine("Property " + propertyName + "'s value is not yet set")
            End If 
            
            Console.WriteLine("... changing to ")

            objDirEnt.Properties(propertyName).Value = newValue
            objDirEnt.CommitChanges()
            
            For Each o In objDirEnt.Properties(propertyName)
                Console.WriteLine("{0} = {1}", propertyName, o.ToString())
            Next

        End Sub

    End Class

End Namespace
