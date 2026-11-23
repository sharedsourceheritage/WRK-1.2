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
imports System.Runtime.Remoting
imports System.Runtime.Remoting.Channels
imports System.Runtime.Remoting.Channels.TCP

Namespace Microsoft.Samples

    Public NotInheritable Class Client

	Private Sub New()
	End Sub

        Shared Sub Main()
            Dim chan As TCPChannel
            chan = New TCPChannel
            ChannelServices.RegisterChannel(chan, true)
            Dim obj As IHello
            obj = CType(Activator.GetObject(GetType(IHello), "tcp://localhost:8085/SayHello"), IHello)
            If obj Is Nothing Then
                System.Console.WriteLine("Could not locate server")
            Else
                Console.WriteLine(obj.HelloMethod("Caveman"))
            End If

        End Sub

    End Class

End Namespace
