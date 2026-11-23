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
Imports System.Threading
Imports System.Text
Imports System.IO

Namespace Microsoft.Samples.QuickStart.HowTo.Net.WebRequests

    ' The RequestState class is used to pass data
    ' across async calls
    NotInheritable Class RequestState

        Private requestDataValue As New StringBuilder("")
        Private buffer(1024) As Byte
        Private requestValue As HttpWebRequest
        Private responseValue As HttpWebResponse
        Private responseStreamValue As Stream
        ' Create Decoder for appropriate encoding type
        Private decoderValue As Decoder = Encoding.UTF8.GetDecoder()

        Property RequestData() As StringBuilder
            Get
                Return requestDataValue
            End Get
            Set(ByVal inputValue As StringBuilder)
                requestDataValue = inputValue
            End Set
        End Property

        Property ReadBuffer() As Byte()
            Get
                Return buffer
            End Get
            Set(ByVal inputValue As Byte())
                buffer = inputValue
            End Set
        End Property

        Property Request() As HttpWebRequest
            Get
                Return requestValue
            End Get
            Set(ByVal inputValue As HttpWebRequest)
                requestValue = inputValue
            End Set
        End Property

        Property Response() As HttpWebResponse
            Get
                Return responseValue
            End Get
            Set(ByVal value As HttpWebResponse)
                responseValue = value
            End Set
        End Property

        Property ResponseStream() As Stream
            Get
                Return responseStreamValue
            End Get
            Set(ByVal inputValue As Stream)
                responseStreamValue = inputValue
            End Set
        End Property

        Property DataDecoder() As Decoder
            Get
                Return decoderValue
            End Get
            Set(ByVal inputValue As Decoder)
                decoderValue = inputValue
            End Set
        End Property

    End Class

    ' ClientGetAsync issues the async request
    NotInheritable Class ClientGetAsync

        Private Shared allDone As New ManualResetEvent(False)
        Private Const BUFFER_SIZE As Integer = 1024

        Shared Sub Main()
            Dim Args As String() = Environment.GetCommandLineArgs()

            If Args.Length < 2 Then
                ShowUsage()
                Return
            End If

            ' Get the URI from the command line
            Dim uri As Uri = New Uri(Args(1))

            ' Create the request object
            Dim request As HttpWebRequest = CType(WebRequest.Create(uri), HttpWebRequest)

            ' Create the state object
            Dim state As RequestState = New RequestState()

            ' Add the request into the state so it can be passed around
            state.Request = request

            ' Issue the async request
            request.BeginGetResponse(New AsyncCallback(AddressOf RespCallback), state)

            ' Set the ManualResetEvent to Wait so that the app
            ' doesn't exit until after the callback is called
            allDone.WaitOne()
        End Sub

        Private Shared Sub ShowUsage()
            Console.WriteLine("Attempts to GET a URL")
            Console.WriteLine()
            Console.WriteLine("Usage:")
            Console.WriteLine("ClientGetAsync URL")
            Console.WriteLine("Examples:")
            Console.WriteLine("ClientGetAsync http://www.microsoft.com/")
        End Sub

        Private Shared Sub RespCallback(ByVal result As IAsyncResult)
            ' Get the RequestState object from the async result
            Dim state As RequestState = CType(result.AsyncState, RequestState)

            ' Get the HttpWebRequest from RequestState
            Dim request As HttpWebRequest = state.Request

            Dim response As HttpWebResponse = Nothing
            Try
                ' Calling EndGetResponse produces the HttpWebResponse object
                ' which came from the request issued above
                response = CType(request.EndGetResponse(result), HttpWebResponse)

                ' Add the response to the state object.
                state.Response = response

                ' Now that we have the response, it is time to start reading
                ' data from the response stream
                Dim ResponseStream As Stream = response.GetResponseStream()

                ' The read is also done using async so we'll want
                ' to store the stream in RequestState
                state.ResponseStream = ResponseStream

                ' Note that rs.BufferRead is passed in to BeginRead.  This is
                ' where the data will be read into.
                ResponseStream.BeginRead( _
                    state.ReadBuffer, _
                    0, _
                    BUFFER_SIZE, _
                    New AsyncCallback(AddressOf ReadCallBack), _
                    state)
            Catch exc As WebException
                Console.WriteLine()
                Console.WriteLine("The request URI was not found.")
                If response IsNot Nothing Then
                    response.Close()
                End If
                allDone.Set()
            Catch exc As IOException
                Console.WriteLine()
                Console.WriteLine("Could not connect to the requested resource.")
                response.Close()
                allDone.Set()
            End Try
        End Sub

        Private Shared Sub ReadCallBack(ByVal result As IAsyncResult)
            ' Get the RequestState object from the asyncresult
            Dim state As RequestState = CType(result.AsyncState, RequestState)

            ' Pull out the ResponseStream that was set in RespCallback
            Dim responseStream As Stream = state.ResponseStream

            ' At this point rs.BufferRead should have some data in it.
            ' Read will tell us if there is any data there
            Dim read As Integer = responseStream.EndRead(result)
            If read > 0 Then
                ' Prepare Char array buffer for converting to Unicode
                Dim charBuffer(1024) As Char

                ' Convert byte stream to Char array and then String
                ' len shows how many characters are converted to Unicode
                Dim length As Integer = state.DataDecoder.GetChars(state.ReadBuffer, 0, read, charBuffer, 0)

                ' Append the recently read data to the RequestData stringbuilder object
                ' contained in RequestState
                state.RequestData.Append(New String(charBuffer, 0, length))

                ' Now fire off another async call to read some more data
                ' Note that this will continue to get called until
                ' responseStream.EndRead returns 0.
                Try
                    responseStream.BeginRead( _
                        state.ReadBuffer, _
                        0, _
                        BUFFER_SIZE, _
                        New AsyncCallback(AddressOf ReadCallBack), _
                        state)
                Catch exc As IOException
                    Console.WriteLine()
                    Console.WriteLine("Could not retrieve the requested resource.")
                    state.Response.Close()
                    allDone.Set()
                End Try
            Else
                ' All of the data has been read, so display it to the console
                Console.WriteLine(state.RequestData.ToString())

                ' Close down the response stream
                responseStream.Close()

                ' Set the ManualResetEvent so the main thread can exit
                allDone.Set()
            End If

            Return
        End Sub
    End Class
End Namespace

