//-----------------------------------------------------------------------
//  This file is part of the Microsoft .NET Framework SDK Code Samples.
// 
//  Copyright (C) Microsoft Corporation.  All rights reserved.
// 
//This source code is intended only as a supplement to Microsoft
//Development Tools and/or on-line documentation.  See these other
//materials for detailed information regarding Microsoft code samples.
// 
//THIS CODE AND INFORMATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY
//KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//PARTICULAR PURPOSE.
//-----------------------------------------------------------------------

using System;
using System.Net;
using System.Threading;
using System.Text;
using System.IO;

namespace Microsoft.Samples.QuickStart.HowTo.Net.WebRequests
{

    // The RequestState class is used to pass data
    // across async calls
    sealed class RequestState
    {
        private const int BUFFER_SIZE = 1024;
        private StringBuilder requestData;
		private byte[] buffer;
		private HttpWebRequest request;
        private HttpWebResponse response;
		private Stream responseStream;
        // Create Decoder for appropriate encoding type
		private Decoder decoder = Encoding.UTF8.GetDecoder();

		public Decoder DataDecoder
		{
			get
			{
				return decoder;
			}
			set
			{
				decoder = value;
			}
		}

        public HttpWebResponse Response
        {
            get
            {
                return response;
            }
            set
            {
                response = value;
            }
        }

		public Stream ResponseStream
		{
			get
			{
				return responseStream;
			}
			set
			{
				responseStream = value;
			}
		}

		public HttpWebRequest Request
		{
			get
			{
				return request;
			}
			set
			{
				request = value;
			}
		}

		public byte[] ReadBuffer
		{
			get
			{
				return buffer;
			}
		}


		public StringBuilder RequestData
		{
			get
			{
				return requestData;
			}
			set
			{
				requestData = value;
			}
		}

		public RequestState()
        {
            buffer = new byte[BUFFER_SIZE];
            RequestData = new StringBuilder("");
        }
    }

    // ClientGetAsync issues the async request
    static class ClientGetAsync
    {
        private static ManualResetEvent allDone = new ManualResetEvent(false);
        private const int BUFFER_SIZE = 1024;

        public static void Main(string[] args)
        {

            if (args.Length < 1)
            {
                ShowUsage();
                return;
            }

            // Get the URI from the command line
            try
            {
                Uri uri = new Uri(args[0]);


                // Create the state object
                RequestState state = new RequestState();

                // Create the request.
                HttpWebRequest request = 
					(HttpWebRequest)WebRequest.Create(uri);
                
                // Add the request into the state so it can be passed around.
                state.Request = request;

                // Issue the async request
                request.BeginGetResponse(
					new AsyncCallback(RespCallback), state);

                // Set the ManualResetEvent to Wait so that the app
                // doesn't exit until after the callback is called
                allDone.WaitOne();
            }
            catch (UriFormatException)
            {
                Console.WriteLine("\r\nThe request URI was malformed.");
            }
        }

        private static void ShowUsage() 
        {
            Console.WriteLine("Attempts to GET a URL");
            Console.WriteLine("\r\nUsage:");
            Console.WriteLine("ClientGetAsync URL");
            Console.WriteLine("Examples:");
            Console.WriteLine("ClientGetAsync http://www.microsoft.com/net/");
        }

        private static void RespCallback(IAsyncResult result)
        {
            // Get the RequestState object from the async result
            RequestState state = (RequestState)result.AsyncState;

            // Get the HttpWebRequest from RequestState
            HttpWebRequest request = state.Request;

            HttpWebResponse response = null;
            try
            {
                // Calling EndGetResponse produces the HttpWebResponse object
                // which came from the request issued above
                response = (HttpWebResponse)request.EndGetResponse(result);

                // Add the response to the state object.
                state.Response = response;

                // Get the response stream.
                Stream responseStream = response.GetResponseStream();

                // Add the response stream to the state object.
                state.ResponseStream = responseStream;

                // Note that rs.BufferRead is passed in to BeginRead.  This is
                // where the data will be read into.
                responseStream.BeginRead(
                    state.ReadBuffer, 
                    0, 
                    BUFFER_SIZE, 
                    new AsyncCallback(ReadCallBack), 
                    state);
            }
            catch (WebException)
            {
                Console.WriteLine("\r\nThe request URI was not found.");
                if (response != null)
                    response.Close();
                allDone.Set();
            }
            catch (IOException)
            {
                Console.WriteLine(
					"\r\nCould not connect to the requested resource.");
                response.Close();
                allDone.Set();
            }
        }

        private static void ReadCallBack(IAsyncResult result)
        {
            // Get the RequestState object from the asyncresult
            RequestState state = (RequestState)result.AsyncState;

            // Pull out the ResponseStream that was set in RespCallback
            Stream responseStream = state.ResponseStream;
		
            // At this point rs.BufferRead should have some data in it.
            // Read will tell us if there is any data there
            int read = responseStream.EndRead(result);

            if (read > 0)
            {
                // Prepare Char array buffer for converting to Unicode
                Char[] charBuffer = new Char[BUFFER_SIZE];
			
                // Convert byte stream to Char array and then String
                // length shows how many characters are converted to Unicode.
                int length = state.DataDecoder.GetChars(state.ReadBuffer, 0, read, charBuffer, 0); 			

                // Append the recently read data to the RequestData stringbuilder object
                // contained in RequestState
                state.RequestData.Append(new String(charBuffer, 0, length));
			
                // Now fire off another async call to read some more data
                // Note that this will continue to get called until
                // responseStream.EndRead returns 0.
                try
                {
                    responseStream.BeginRead(
                        state.ReadBuffer,
                        0,
                        BUFFER_SIZE,
                        new AsyncCallback(ReadCallBack),
                        state);
                }
                catch (IOException)
                {
                    Console.WriteLine("\r\nCould not retrieve the requested resource.");
                    state.Response.Close();
                    allDone.Set();
                }
            }
            else
            {
                // All of the data has been read, so display it to the console
                Console.WriteLine(state.RequestData.ToString());

                // Close the response to free up resources.
                state.Response.Close();

                // Set the ManualResetEvent so the main thread can exit.
                allDone.Set();
            }
            return;
        }
    }
}