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

imports System
imports System.Threading
imports System.Runtime.Remoting
imports System.Runtime.Remoting.Channels
imports System.Runtime.Remoting.Channels.HTTP
imports System.Runtime.Remoting.Channels.TCP

Namespace Microsoft.Samples

    Public NotInheritable Class Client

        Dim init As Boolean = False
        Public Shared thread1 As Thread
        Public Shared thread2 As Thread

        Shared Sub Main()
            Dim c As Client
            c = New Client
            thread1 = New Thread(New ThreadStart(AddressOf c.RunMe))
            thread2 = New Thread(New ThreadStart(AddressOf c.RunMe))
            thread1.Start()
            thread2.Start()
        End Sub


        Public Sub RunMe()
            If Thread.CurrentThread Is thread1 Then
                Dim chan As HTTPChannel
                chan = New HTTPChannel
                ChannelServices.RegisterChannel(chan, false)
                Console.WriteLine("I am thread one")
                Dim obj As HelloServer
                obj = CType(Activator.GetObject(GetType(HelloServer), "http://localhost:8086/SayHello"), HelloServer)
                Dim i As Integer
                For i = 0 To 1000
                    Console.WriteLine(obj.CountMe() & " - from thread 1 ")
                    Thread.Sleep(0)
                Next i
            ElseIf Thread.CurrentThread Is thread2 Then
                Dim chan As TCPChannel
                chan = New TCPChannel
                ChannelServices.RegisterChannel(chan, true)
                Console.WriteLine("I am thread two")
                Dim obj As HelloServer
                obj = CType(Activator.GetObject(GetType(HelloServer), "tcp://localhost:8085/SayHello"), HelloServer)
                Dim i As Integer
                For i = 0 To 1000
                    Console.WriteLine(obj.CountMe() & " - from thread 2 ")
                    Thread.Sleep(0)
                Next i
            End If
        End Sub

    End Class

End Namespace
