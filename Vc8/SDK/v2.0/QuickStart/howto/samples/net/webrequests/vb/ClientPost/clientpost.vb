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
Imports System.Web
Imports Microsoft.VisualBasic

Namespace Microsoft.Samples.QuickStart.HowTo.Net.WebRequests
    NotInheritable Class ClientPost

        Private Sub ClientPost()
        End Sub

        Public Shared Sub Main()
            Dim args As String()

            args = Environment.GetCommandLineArgs()
            If (args.Length < 2) Then
                ShowUsage()
            Else
                If args.Length < 3 Then
                    GetPage(args(1), "sl=foo&s2=bar")
                Else
                    GetPage(args(1), args(2))
                End If
            End If

            Console.WriteLine()
            Console.WriteLine("Press any key to continue...")
            Console.ReadLine()
        End Sub

        Private Shared Sub ShowUsage()
            Console.WriteLine("Attempts to POST to a URL")
            Console.WriteLine()
            Console.WriteLine("Usage:")
            Console.WriteLine("ClientPOST URL [postdata]")
            Console.WriteLine()
            Console.WriteLine("Examples:")
            Console.WriteLine("ClientPOST http://www.nba.com [s1=foo&s2=bar]")
        End Sub

        Private Shared Sub GetPage(ByVal url As String, ByVal payload As String)
            Dim requestStream As Stream = Nothing
            Dim response As WebResponse = Nothing
            Dim reader As StreamReader = Nothing

            Try
                Dim request As WebRequest = WebRequest.Create(url)
                request.Method = WebRequestMethods.Http.Post
                request.ContentType = "application/x-www-form-urlencoded"
                Dim SomeBytes() As Byte
                Dim UrlEncoded As New StringBuilder
                Dim reserved() As Char = {ChrW(63), ChrW(61), ChrW(38)}

                If payload <> Nothing Then
                    Dim i As Integer = 0
                    Dim j As Integer
                    While i < payload.Length
                        j = payload.IndexOfAny(reserved, i)
                        If j = -1 Then
                            UrlEncoded.Append(HttpUtility.UrlEncode(payload.Substring(i, payload.Length - i)))
                            Exit While
                        End If
                        UrlEncoded.Append(HttpUtility.UrlEncode(payload.Substring(i, j - i)))
                        UrlEncoded.Append(payload.Substring(j, 1))
                        i = j + 1
                    End While
                    SomeBytes = System.Text.Encoding.UTF8.GetBytes(UrlEncoded.ToString())
                    request.ContentLength = SomeBytes.Length
                    requestStream = request.GetRequestStream()
                    requestStream.Write(SomeBytes, 0, SomeBytes.Length)
                    requestStream.Close()
                Else
                    request.ContentLength = 0
                End If
                response = request.GetResponse()
                Dim responseStream As Stream = response.GetResponseStream()
                reader = New StreamReader(responseStream)

                Console.WriteLine()
                Console.WriteLine("Response stream received")
                Dim buffer(256) As Char
                Dim count As Integer = reader.Read(buffer, 0, buffer.Length)

                Console.WriteLine("HTML...")
                Console.WriteLine()
                Do While count > 0
                    Console.Write(New String(buffer, 0, count))
                    count = reader.Read(buffer, 0, buffer.Length)
                Loop
                Console.WriteLine("")
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
                If requestStream IsNot Nothing Then
                    requestStream.Close()
                End If
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

