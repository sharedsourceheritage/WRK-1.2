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
Imports System.IO
Imports System.Text

Namespace Microsoft.Samples.QuickStart.HowTo.Net.WebRequests

    NotInheritable Class ClientGetProxy

        Private Sub ClientGetProxy()
        End Sub

        Private Shared bShow As Boolean

        Public Shared Sub Main()
            Dim args As String()
            args = Environment.GetCommandLineArgs()

            If (args.Length < 3) Then
                ShowUsage()
            Else
                If (args.Length > 3) Then
                    bShow = False
                Else
                    bShow = True
                End If
                GetPage(args(1), args(2))
            End If

            Console.WriteLine()
            Console.WriteLine("Press Enter to continue...")
            Console.ReadLine()
        End Sub

        Private Shared Sub ShowUsage()
            Console.WriteLine("Attempts to GET a URL")
            Console.WriteLine()
            Console.WriteLine("Usage:")
            Console.WriteLine("ClientGETwithProxy URL proxyname")
            Console.WriteLine()
            Console.WriteLine("Examples:")
            Console.WriteLine("ClientGETwithProxy http://www.microsoft.com/net/ myproxy")
        End Sub

        Private Shared Sub GetPage(ByVal url As String, ByVal proxy As String)
            Dim response As WebResponse = Nothing
            Dim reader As StreamReader = Nothing
            Try
                Dim webProxy As WebProxy = New WebProxy(proxy, 80)

                ' Disable Proxy use when the host is local i.e. without periods.
                webProxy.BypassProxyOnLocal = True

                ' Now actually take over the global with our new settings, all new requests
                ' use this proxy info
                HttpWebRequest.DefaultWebProxy = webProxy

                Dim request As WebRequest = WebRequest.Create(url)
                response = request.GetResponse()
                Dim responseStream As Stream = response.GetResponseStream()
                reader = New StreamReader(responseStream)

                Console.WriteLine()
                Console.WriteLine("Response stream received")
                If bShow Then
                    Dim buffer(256) As Char
                    Dim count As Integer = reader.Read(buffer, 0, buffer.Length)

                    Console.WriteLine("HTML...")
                    Console.WriteLine()
                    Do While count > 0
                        Console.Write(New String(buffer, 0, count))
                        count = reader.Read(buffer, 0, buffer.Length)
                    Loop
                    Console.WriteLine("")
                End If
            Catch Exc As UriFormatException
                Console.WriteLine()
                Console.WriteLine("The request URI was malformed.")
            Catch Exc As WebException
                Console.WriteLine()
                Console.WriteLine("The request URI could not be found.")
            Catch Exc As IOException
                Console.WriteLine()
                Console.WriteLine("The request URI could not be retrieved.")
            Finally
                If response IsNot Nothing Then
                    response.Close()
                End If
                If reader IsNot Nothing Then
                    reader.Close()
                End If
            End Try
        End Sub
    End Class
End Namespace

