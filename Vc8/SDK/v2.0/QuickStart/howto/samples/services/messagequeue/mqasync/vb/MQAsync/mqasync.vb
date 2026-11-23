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
Imports System.Threading
Namespace Microsoft.Samples

    Class MQReceive
        Public Shared Sub Main()
            Dim appName As String = Environment.GetCommandLineArgs()(0)

            If (Environment.GetCommandLineArgs().Length <> 2) Then
                Console.WriteLine("Usage: {0} <queue>", appName)
                Exit Sub
            End If

            Dim mqPath As String = ".\" + Environment.GetCommandLineArgs()(1)

            If (Not MessageQueue.Exists(mqPath)) Then
                Console.WriteLine("The queue '{0}' does not exist!", mqPath)
            Else
                Dim mq As MessageQueue = New MessageQueue(mqPath)
                Dim formatter As XmlMessageFormatter = CType(mq.Formatter, XmlMessageFormatter)
                formatter.TargetTypeNames = New String() {"System.String,mscorlib"}

                AddHandler mq.ReceiveCompleted, AddressOf OnReceiveCompleted
                mq.BeginReceive()
            End If

            Console.WriteLine("Press Enter to quit the sample")
            Console.ReadLine()
        End Sub

        Public Shared Sub OnReceiveCompleted(ByVal source As Object, ByVal asyncResult As ReceiveCompletedEventArgs)
            Dim mq As MessageQueue = CType(source, MessageQueue)
            Dim m As Message = mq.EndReceive(asyncResult.AsyncResult)
            m.Formatter = New XmlMessageFormatter(New String() {"System.String, mscorlib"})
            Console.WriteLine("Message: {0}", CStr(m.Body))
            mq.BeginReceive()
        End Sub
    End Class
End Namespace
