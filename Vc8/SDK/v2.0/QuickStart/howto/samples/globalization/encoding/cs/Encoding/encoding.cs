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
using System.Text;

namespace Microsoft.Samples.Globalization.EncodingCS
{
	class CultureAndRegion
	{

		public static void Main(String[] args)
		{
			//Create a text file for this example
			Console.WriteLine ("Creating text.txt");
			FileStream fs = new FileStream("text.txt", FileMode.OpenOrCreate);

			Console.WriteLine ("Writing UTF8");
			StreamWriter t = new StreamWriter (fs, Encoding.UTF8);
			t.WriteLine("This is in UTF8");
			t.Flush();

			Console.WriteLine ("Writing Unicode");
			StreamWriter t2 = new StreamWriter (fs, Encoding.Unicode);
			t2.WriteLine("This is in Unicode");
			t2.Flush();

			Console.WriteLine ("Writing Ascii");
			StreamWriter t3 = new StreamWriter (fs, Encoding.ASCII);
			t3.WriteLine("This is in ASCII");
			t3.Flush();

                        // Note that UTF-8 would be preferred as different systems or user settings
                        // could cause different Encoding.Default behaviors.  Additionally, Encoding.Default
                        // could lose or change data, whereas UTF-8 would be lossless.
            		Console.Write("Writing Your Default Code Page ");
            		Console.WriteLine(Encoding.Default.EncodingName);
            		StreamWriter t4 = new StreamWriter(fs, Encoding.Default);
            		t4.Write("This is in your default code page ");
            		t4.WriteLine(Encoding.Default.EncodingName);
            		t4.Flush();

			fs.Close();

			Console.WriteLine ();
			Console.WriteLine ("Press Enter to continue...");
			Console.ReadLine();
		}
	}

}
