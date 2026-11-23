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
Imports microsoft.visualbasic

Namespace Microsoft.Samples.QuickStart.HowTo.Net.WebRequests

    NotInheritable Class ClientWebErrorHandler

        Private Sub ClientWebErrorHandler()
        End Sub

        Public Shared Sub Main()
            Dim resolvedUri As Boolean = False
            Dim uriToResolve As String
            Dim responseStream As Stream
            Dim encoding As Encoding
            Dim reader As StreamReader
            Dim buffer(256) As Char

            While (Not resolvedUri)

                Dim response As WebResponse = Nothing
                Try
                    ' Get a uri from the user
                    Console.Write("Please enter the uri to resolve: ")
                    uriToResolve = Console.ReadLine()
                    Console.WriteLine()

                    ' Create the request object
                    Dim request As WebRequest = WebRequest.Create(uriToResolve)
                    request.Credentials = New NetworkCredential("invaliduser", "invalidpassword")

                    ' Create the response object
                    response = request.GetResponse()
                    Console.WriteLine("URI Resolved!")

                    ' Successfully resolved the URI
                    resolvedUri = True

                    responseStream = response.GetResponseStream()
                    encoding = System.Text.Encoding.GetEncoding("utf-8")
                    reader = New StreamReader(responseStream, encoding)

                    Console.WriteLine()
                    Console.WriteLine("Response stream received")
                    Dim count As Integer = reader.Read(buffer, 0, 256)

                    Console.WriteLine("HTML...")
                    Console.WriteLine()
                    Do While count > 0
                        Dim str As String = New String(buffer, 0, count)
                        Console.Write(str)
                        count = reader.Read(buffer, 0, 256)
                    Loop
                    Console.WriteLine("")
                Catch webException As WebException
                    '  If you get to this point, the exception has been caught
                    Console.WriteLine("A WebException has been caught!")

                    '  Write out the Exception message
                    Console.WriteLine(webException.ToString())

                    '  Get the WebException status code
                    If (webException.Status = WebExceptionStatus.ProtocolError) Then
                        '  Write out the WebResponse protocol status
                        Console.WriteLine("Error received from Server")
                    End If
                Catch uriFormatException As UriFormatException
                    '  If you get to this point, the exception has been caught
                    Console.WriteLine("A URIFormatException has been caught!")
                    '  Write out the Exception message
                    Console.WriteLine(uriFormatException.ToString())
                Finally
                    If response IsNot Nothing Then
                        response.Close()
                    End If
                End Try
            End While

            Console.WriteLine()
            Console.WriteLine("Press Enter to continue...")
            Console.ReadLine()
        End Sub
    End Class
End Namespace
