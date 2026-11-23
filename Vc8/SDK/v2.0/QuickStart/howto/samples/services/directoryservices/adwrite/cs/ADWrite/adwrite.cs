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
using System.DirectoryServices;
using System.Security.Permissions;
using System.Runtime.InteropServices;

namespace Microsoft.Samples
{    
    public sealed class ADWrite 
    {
        public ADWrite() {}

        public static void Main(String[] args) 
        {
            if ( args.Length!=3 ) 
            {
                Console.WriteLine("Usage: " + Environment.GetCommandLineArgs()[0] + " <ad_path> <property> <value>");
                Console.WriteLine ();
                Console.WriteLine ("Press Enter to continue...");
                Console.ReadLine();
                return;
            }

            DirectoryEntry objDirEnt = new DirectoryEntry(args[0]);
            Console.WriteLine("Name            = " + objDirEnt.Name);
            Console.WriteLine("Path            = " + objDirEnt.Path);
            Console.WriteLine("SchemaClassName = " + objDirEnt.SchemaClassName);
            if(objDirEnt.Properties.Contains(args[1]))
            {                
                foreach(object o in objDirEnt.Properties[args[1]])
                    Console.WriteLine("{0} = {1}", args[1], o.ToString());                            

            }
            else
            {
                Console.WriteLine("Property {0}'s value is not yet set", args[1]);
            }
            Console.WriteLine("... changing to ");
            (objDirEnt.Properties[args[1]]).Value = args[2];
            objDirEnt.CommitChanges();
            
            foreach(object o in objDirEnt.Properties[args[1]])
                Console.WriteLine("{0} = {1}", args[1], o.ToString());  
        }
    }
}