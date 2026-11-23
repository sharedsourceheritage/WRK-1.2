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
using System.IO;
using System.Text;
using System.Web;

namespace Microsoft.Samples.QuickStart.HowTo.Net.WebRequests
{

    static class ClientPOST 
    {
        public static void Main(string[] args) 
        {

            if (args.Length < 1)
            {
                ShowUsage();
            }
            else
            {
                if (args.Length < 2)
                {
                    GetPage(args[0], "s1=food&s2=bart");
                }
                else
                {
                    GetPage(args[0], args[1]);
                }
                Console.WriteLine();
                Console.WriteLine("Press any key to continue...");
                Console.ReadLine();
            }         
            return;
        }

        private static void ShowUsage() 
        {
            Console.WriteLine("Attempts to POST into to a URL");
            Console.WriteLine();
            Console.WriteLine("Usage:");
            Console.WriteLine("ClientPOST URL [postdata]");
            Console.WriteLine();
            Console.WriteLine("Examples:");
            Console.WriteLine("ClientPOST http://www.microsoft.com s1=food&s2=bart");
        }

        private static void GetPage(String url, String payload) 
        {
            Stream requestStream = null;
			WebResponse response = null;
            StreamReader reader = null;
			try 
            {				
				WebRequest request = WebRequest.Create(url);
                request.Method = WebRequestMethods.Http.Post;
                request.ContentType = "application/x-www-form-urlencoded";
                StringBuilder urlEncoded = new StringBuilder();
                Char[] reserved = {'?', '=', '&'};
                byte[] byteBuffer = null;

                if (payload != null) 
                {
                    int i = 0, j;
                    while(i < payload.Length)
                    {
                        j = payload.IndexOfAny(reserved, i);
                        if (j == -1)
                        {
                            urlEncoded.Append(HttpUtility.UrlEncode(payload.Substring(i, payload.Length - i)));
                            break;
                        }
                        urlEncoded.Append(HttpUtility.UrlEncode(payload.Substring(i, j - i)));
                        urlEncoded.Append(payload.Substring(j, 1));
                        i = j + 1;
                    }
                    byteBuffer = Encoding.UTF8.GetBytes(urlEncoded.ToString());
                    request.ContentLength = byteBuffer.Length;
                    requestStream = request.GetRequestStream();
                    requestStream.Write(byteBuffer, 0, byteBuffer.Length);
                    requestStream.Close();
                } 
                else 
                {
                    request.ContentLength = 0;
                }


                response = request.GetResponse();
                Stream responseStream = response.GetResponseStream();
                reader = new StreamReader(responseStream);
                Console.WriteLine("\r\nResponse stream received");
                Char[] charBuffer = new Char[256];
                int count = reader.Read(charBuffer, 0, charBuffer.Length);
                Console.WriteLine("HTML...\r\n");
                while (count > 0) 
                {
                    Console.Write(new String(charBuffer, 0, count));
                    count = reader.Read(charBuffer, 0, charBuffer.Length);
                }
                Console.WriteLine("");
            } 
            catch(UriFormatException) 
            {
                Console.WriteLine("\r\nThe request URI was malformed.");
            }
            catch (WebException)
            {
                Console.WriteLine("\r\nThe request URI could not be found.");
            }
            catch (IOException)
            {
                Console.WriteLine("\r\nThe request URI could not be found or was malformed");
            }
            finally 
            {
                if (requestStream != null)
                    requestStream.Close(); 
                if (response != null) 
                    response.Close();
                if (reader != null)
                    reader.Close();
            }
        }
    }
}