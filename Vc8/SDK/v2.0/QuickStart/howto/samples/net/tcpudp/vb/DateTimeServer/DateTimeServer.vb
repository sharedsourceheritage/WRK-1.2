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
Imports System.Net
Imports System.Net.Sockets
Imports System.Text
Imports System.Threading
Imports System.Globalization
Namespace Microsoft.Samples.QuickStart.HowTo.Net.TcpUdp

    Public Class DateTimeServer
        Private Sub DateTimeServer()

        End Sub
        Public Shared Sub Main()
            Dim now As Date
            Dim strDateLine As String
            Dim ASCII As Encoding = Encoding.ASCII
            Dim s As Socket

            Try
                Dim tcpl As New TcpListener(IPAddress.Any, 13) 'listen on port 13
                tcpl.Start()


                Console.WriteLine("Waiting for clients to connect")
                Console.WriteLine("Press Ctrl+c to Quit...")

                While (True)
                    ' Accept will block until someone connects
                    s = tcpl.AcceptSocket()

                    ' Get the current date and time then concatenate it
                    ' into a string
                    now = DateTime.Now
                    strDateLine = now.ToShortDateString() + " " + now.ToLongTimeString()

                    ' Convert the string to a Byte Array and send it
                    Dim byteDateLine() As Byte = ASCII.GetBytes(strDateLine.ToCharArray())
                    s.Send(byteDateLine, byteDateLine.Length, SocketFlags.None)
                    Console.WriteLine("Sent {0}", strDateLine)
                End While

            Catch socketError As SocketException
                If (socketError.ErrorCode) = 10048 Then
                    Console.WriteLine("Connection to this port failed.  There is another server is listening on this port.")
                End If
            Finally
                If Not s Is Nothing Then
                    s.Close()
                End If
            End Try

        End Sub
    End Class
End Namespace
