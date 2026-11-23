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
imports System.Runtime.Remoting.Channels.TCP
imports System.Runtime.Remoting.Channels.HTTP

Namespace Microsoft.Samples

    Public NotInheritable Class Sample

	Private Sub New()
	End Sub

        Shared Sub Main()
            Dim chan1 As TCPChannel
            chan1 = New TCPChannel(8085)
            Dim chan2 As HTTPChannel
            chan2 = New HTTPChannel(8086)
            ChannelServices.RegisterChannel(chan1, true)
            ChannelServices.RegisterChannel(chan2, false)
            RemotingConfiguration.RegisterWellKnownServiceType(GetType(HelloServer), "SayHello", WellKnownObjectMode.Singleton)
            System.Console.WriteLine("Hit <enter> to exit...")
            System.Console.ReadLine()
        End Sub

    End Class

End Namespace
