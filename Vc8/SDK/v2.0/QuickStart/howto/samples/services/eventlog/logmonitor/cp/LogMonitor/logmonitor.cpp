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

// logmonitor.cpp
using namespace System;
using namespace System::Threading;
using namespace System::Diagnostics;

ref class LogMonitor
{
private:
	EventLog^ aLog;

public:

	// Ctor initializes the log monitor by creating
	// an EventLog object that wraps the system event log
	LogMonitor(String^ log, String^ machine)
	{
		aLog = gcnew EventLog();
		aLog->Log = log;
		aLog->MachineName = machine;
	}

	void Monitor()
	{
		// Wire-up event handler
		aLog->EntryWritten += gcnew EntryWrittenEventHandler(this, &LogMonitor::OnEntryWritten);
		aLog->EnableRaisingEvents = true;

		// Sit and spin, displaying events from the log
		Console::WriteLine("Press \'q\' to quit the sample");
		while(Console::Read() != 'q')
		{
			Thread::Sleep(500);
		}
	}

	// Called whenever an event is raised by the monitor
	void OnEntryWritten(Object^ source, EntryWrittenEventArgs^ e) 
	{
		Console::WriteLine(String::Concat("Written: ", e->Entry->Message));
	}
};

int main( array<String^>^ argv )
{
	if( argv->Length != 1)
	{
		Console::WriteLine("Usage: LogMonitor <logName>");
		Console::WriteLine ();
		Console::WriteLine ("Press any key to continue...");
		Console::ReadLine();
		return 0;
	}

	String^ log = argv[0];
		

	String^ machine;
	machine = ".";

	if(!EventLog::Exists(log, machine))
	{
		Console::WriteLine("The log does not exist!");
		return 0;
	}

	LogMonitor^ monitor = gcnew LogMonitor(log, machine);
	monitor->Monitor();

	return 0;
}
