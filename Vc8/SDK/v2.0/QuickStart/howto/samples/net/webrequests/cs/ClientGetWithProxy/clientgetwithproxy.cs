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

    static class ClientGETwithProxy 
    {
        private static bool bShow;

        public static void Main(string[] args) 
        {

            if (args.Length < 2) 
            {
                ShowUsage();
            } 
            else 
            {
                if (args.Length > 2)
                    bShow = false;
                else
                    bShow = true;

                getPage(args[0], args[1]);
            }

            Console.WriteLine();
            Console.WriteLine("Press Enter to continue...");
            Console.ReadLine();

            return;
        }

        private static void ShowUsage() 
        {
            Console.WriteLine("Attempts to GET a URL with a proxy");
            Console.WriteLine();
            Console.WriteLine("Usage:");
            Console.WriteLine("ClientGETwithProxy URL proxyname");
            Console.WriteLine();
            Console.WriteLine("Examples:");
            Console.WriteLine("ClientGETwithProxy http://www.microsoft.com/net/ myproxy");
        }

        private static void getPage(string url, string proxy) 
        {
            WebResponse response = null;
            StreamReader reader = null;
            try
            {
                WebProxy webProxy = new WebProxy(proxy, 80);

                // Disable Proxy use when the host is local i.e. without periods.
                webProxy.BypassProxyOnLocal = true;

                // Now actually take over the global with our new settings, all new requests
                // use this proxy info
                HttpWebRequest.DefaultWebProxy = webProxy;

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