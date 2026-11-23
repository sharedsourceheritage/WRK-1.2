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
using System.IO;
using System.Collections;
using System.Runtime.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
namespace Microsoft.Samples
{
    public static class SerializeTest
    {
        public static void Main(String[] args)
        {
            Console.WriteLine("Create object graph");
            ArrayList l = new ArrayList();
            for (int x = 0; x < 10; x++)
            {
                Console.WriteLine(x);
                l.Add(x);
            } // end for
            Console.Write("Serializing object graph to disk..");
            Stream s = null;
            try
            {
                s = File.Open("foo.bin", FileMode.Create, FileAccess.ReadWrite);
                BinaryFormatter b = new BinaryFormatter();
                b.Serialize(s, l);
            }
            catch(Exception e)
            {
                Console.WriteLine("An exception occured during serialization: " + e.ToString());
            }           
            finally
            {
                if (s != null) s.Close();
                Console.WriteLine("Complete.");
            }

            Console.Write("Deserializing object graph from disk..");
            Stream r = null;
            try
            {
                r = File.Open("foo.bin", FileMode.Open, FileAccess.Read);
                BinaryFormatter c = new BinaryFormatter();
                ArrayList p = (ArrayList)c.Deserialize(r);
                foreach (int i in p)
                {
                    Console.WriteLine(i);
                }
            }
            catch(Exception e)
            {
                Console.WriteLine("An exception occured during deserialization: " + e.ToString());
            }            
            finally
            {
                if (r != null) r.Close();
                Console.WriteLine("Complete.");
            }

            Console.WriteLine("\r\nPress Return to exit.");
            Console.Read();
        } // end main
    } // end class
}