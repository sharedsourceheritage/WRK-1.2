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
Imports System.Messaging

Namespace Microsoft.Samples

Public Class MQCtrl
        Public Shared Sub Main()
            Dim appName As String = Environment.GetCommandLineArgs()(0)

            If (Environment.GetCommandLineArgs().Length <> 4) Then
                Console.WriteLine("Usage: ")
                Console.WriteLine("    {0} <queue> <command> <value>", appName)
                Console.WriteLine("")
                Console.WriteLine("        <Command> =")
                Console.WriteLine("            l: change label")
                Console.WriteLine("            s: change queue size")
                Console.WriteLine("            j: change journal size")
                Exit Sub
            End If

            Dim mqPath As String = ".\" + Environment.GetCommandLineArgs()(1)
            If (Not MessageQueue.Exists(mqPath)) Then
                Console.WriteLine("The queue {0} does not exist", mqPath)
                Exit Sub
            End If

            Dim mq As MessageQueue = New MessageQueue(mqPath)

            Dim command As String = Environment.GetCommandLineArgs()(2)
            Dim value As String = Environment.GetCommandLineArgs()(3)
            If (command = "l") Then
                mq.Label = value
            ElseIf (command = "s") Then
                mq.MaximumQueueSize = Int32.Parse(value)
            ElseIf (command = "j") Then
                mq.MaximumJournalSize = Int32.Parse(value)
            End If
        End Sub
    End Class
End Namespace
