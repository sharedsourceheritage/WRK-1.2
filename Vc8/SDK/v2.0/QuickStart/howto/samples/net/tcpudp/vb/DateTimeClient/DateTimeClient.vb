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
Imports System.IO
Imports System.Net
Imports System.Net.Sockets
Imports System.Text
Namespace Microsoft.Samples.QuickStart.HowTo.Net.TcpUdp

Public Class Client

        Private Sub Client()

        End Sub
        Public Shared Sub Main()
            Dim tcpc As New TcpClient
            Dim read(35) As Byte
            Dim args As String() = Environment.GetCommandLineArgs()

            If (args.Length < 2) Then
                Console.WriteLine("Please specify a server name in the command line")
                Exit Sub
            End If

            Dim server As String = args(1)

            ' Verify that the server exists
            Try
                Dns.GetHostEntry(server)
            Catch
                Console.WriteLine("Cannot find server: {0}", server)
                Exit Sub
            End Try

            ' Get the stream
            Dim s As Stream = Nothing
            Dim bytes As Integer
            Dim Time As String

            ' Try to connect to the server
            Try
                tcpc.Connect(server, 13)

                s = tcpc.GetStream()

                ' Read the stream and convert it to ASII
                bytes = s.Read(read, 0, read.Length)
                Time = Encoding.ASCII.GetString(read)

            Catch exc As Exception
                Console.WriteLine("Cannot connect to {0}: {1}", server, exc.Message)
                If Not s Is Nothing Then
                    s.Close()
                End If
                Exit Sub
            Finally
                If Not tcpc Is Nothing Then
                    tcpc.Close()
                End If
                If Not s Is Nothing Then
                    s.Close()
                End If
            End Try

            ' Display the data
            Console.WriteLine("Received {0} bytes", bytes)
            Console.WriteLine("Current date and time is: {0}", Time)

            ' Wait for user response to exit
            Console.WriteLine("Press Return to exit")
            Console.Read()
        End Sub

    End Class
End Namespace
