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

Class MQReceive
        Public Shared Sub Main()
            Dim Args() As String = Environment.GetCommandLineArgs()
            Dim appName As String = Args(0)

            If (Environment.GetCommandLineArgs().Length <> 2) Then
                Console.WriteLine("Usage: {0} <queue>", appName)
            Else
                Dim queuePath As String = Args(1)
                Dim mqPath As String = ".\" + queuePath

                If (Not MessageQueue.Exists(mqPath)) Then
                    Console.WriteLine("The queue '{0}' does not exist!", mqPath)
                    Exit Sub
                End If

                Dim mq As MessageQueue = New MessageQueue(mqPath)
                Dim formatter As XmlMessageFormatter = CType(mq.Formatter, XmlMessageFormatter)
                formatter.TargetTypeNames = New String() {"System.String,mscorlib"}

                Try
                    Dim m As Message = mq.Receive(New TimeSpan(0, 0, 3))
                    Console.WriteLine("Message: {0}", CStr(m.Body))
                Catch e As MessageQueueException
                    Console.WriteLine("There are no messages in the queue")
                    Exit Sub
                Catch e As InvalidOperationException
                    Console.WriteLine("The message removed from the queue is not a string")
                    Exit Sub
                End Try
            End If

            Console.WriteLine()
            Console.WriteLine("Press Enter to continue...")
            Console.ReadLine()
        End Sub
    End Class
End Namespace
