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
using System.Diagnostics;
using System.Threading;

namespace Microsoft.Samples
{
	public sealed class LogMonitor
	{
		private LogMonitor()
		{
		}

		public static void Main(String[] args)
		{
			if (args.Length != 1)
			{
				Console.WriteLine("Usage: LogMontitor.exe <appName>");
				Console.WriteLine();
				Console.WriteLine("Press Enter to continue...");
				Console.ReadLine();
				return;
			}

			string log = args[0];
			string machine = ".";

			if (!EventLog.Exists(log, machine))
			{
				Console.WriteLine("The log does not exist!");
				return;
			}

			EventLog aLog = new EventLog();

			aLog.Log = log;
			aLog.MachineName = machine;
			aLog.EntryWritten += new EntryWrittenEventHandler(OnEntryWritten);
			aLog.EnableRaisingEvents = true;
			Console.WriteLine("Press \'q\' to quit the sample");
			while (Console.Read() != 'q')
			{
				Thread.Sleep(500);
			}
		}

		private static void OnEntryWritten(Object source, EntryWrittenEventArgs e)
		{
			Console.WriteLine("Written: " + e.Entry.Message);
		}
	}
}
