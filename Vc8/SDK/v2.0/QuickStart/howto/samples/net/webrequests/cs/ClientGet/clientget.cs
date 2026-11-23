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
namespace Microsoft.Samples.QuickStart.HowTo.Net.WebRequests
{
    static class ClientGET 
    {
        private static bool bShow;

        public static void Main(string[] args) 
        {

            if (args.Length < 1) 
            {
                ShowUsage();
            } 
            else 
            {
                if (args.Length == 2)
                    bShow = false;
                else
                    bShow = true;

                GetPage(args[0]);
            }

            Console.WriteLine();
            Console.WriteLine("Press Enter to continue...");
            Console.ReadLine();

            return;
        }

        private static void ShowUsage() 
        {
            Console.WriteLine("Attempts to GET a URL");
            Console.WriteLine("\r\nUsage:");
            Console.WriteLine("ClientGET URL");
            Console.WriteLine("Examples:");
            Console.WriteLine("ClientGET http://www.microsoft.com/net/");
        }


        private static void GetPage(String url) 
        {
            WebResponse response = null;
            StreamReader reader = null;
            try
            {
                WebRequest request = WebRequest.Create(url);
                response = request.GetResponse();
                Stream responseStream = response.GetResponseStream();
                reader = new StreamReader(responseStream);
                Console.WriteLine("\r\nResponse stream received");
                if (bShow)
                {
                    Char[] buffer = new Char[256];
                    int count = reader.Read(buffer, 0, buffer.Length);

                    Console.WriteLine("HTML...\r\n");
                    while (count > 0)
                    {
                        Console.Write(new String(buffer, 0, count));
                        count = reader.Read(buffer, 0, buffer.Length);
                    }
                    Console.WriteLine("");
                }
            }
            catch (UriFormatException)
            {
                Console.WriteLine("\r\nThe request URI was malformed.");
            }
            catch (WebException)
            {
                Console.WriteLine("\r\nThe request URI could not be found.");
            }
            catch (IOException)
            {
                Console.WriteLine("\r\nThe request URI could not be retrieved.");
            }
            finally 
            {
                if (response != null) 
                    response.Close();
                if (reader != null)
                    reader.Close();
            }
        }
    }
}