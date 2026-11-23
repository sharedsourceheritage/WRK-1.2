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
Imports System.Threading
Imports System.Runtime.Remoting
Imports System.Runtime.Remoting.Messaging
Imports System.Runtime.Remoting.Channels
Imports System.Runtime.Remoting.Channels.TCP

Namespace Microsoft.Samples

    Public NotInheritable Class Client

        Public Shared resetEvent As ManualResetEvent = New ManualResetEvent(False)
        Public Delegate Function HelloMethodCallback(ByVal name As String) As String

        Shared Sub Main()

            Dim channel As TCPChannel
            channel = New TCPChannel
            ChannelServices.RegisterChannel(channel, true)
            Dim remoteObject As HelloServer
            remoteObject = CType(Activator.GetObject(GetType(HelloServer), "tcp://localhost:8085/SayHello"), HelloServer)
            If remoteObject Is Nothing Then
                System.Console.WriteLine("Could not locate server")
            Else
                Dim callback As AsyncCallback
                callback = New AsyncCallback(AddressOf Client.ClientCallBack)
                Dim remoteDelegate As HelloMethodCallback
                remoteDelegate = New HelloMethodCallback(AddressOf remoteObject.HelloMethod)
                Dim asyncResult As IAsyncResult
                asyncResult = remoteDelegate.BeginInvoke("Caveman", callback, 0)
            End If

            resetEvent.WaitOne()
        End Sub


        Shared Sub ClientCallBack(ByVal asyncResult As IAsyncResult)
            Dim remoteDelegate As HelloMethodCallback = CType(asyncResult, AsyncResult).AsyncDelegate
            Console.WriteLine(remoteDelegate.EndInvoke(asyncResult))
            resetEvent.Set()
        End Sub

    End Class

End Namespace
