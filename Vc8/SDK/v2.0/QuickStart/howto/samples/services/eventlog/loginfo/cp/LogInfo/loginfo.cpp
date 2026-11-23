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

// loginfo.cpp

#using <mscorlib.dll>
using namespace System;

#using <System.dll>
using namespace System::Diagnostics;

int main(array<System::String^>^ argv)
{
	String^ appName = Environment::GetCommandLineArgs()[0];

	//if(argc != 2 && argc != 3)
	if (argv->Length != 1 && argv->Length != 2)
	{
		Console::WriteLine(argv->Length);
		Console::WriteLine(String::Concat("Usage: ", appName, " <log> [<machine>]"));
		Console::WriteLine ();
		Console::WriteLine ("Press any key to continue...");
		Console::ReadLine();
		return 0;
	}

	String^ log = argv[0];

	String^ machine;
	if(argv->Length == 3)
	{
		machine= argv[1];
	}
	else
	{
		machine = "."; // local machine
	}

	if(!EventLog::Exists(log, machine))
	{
		Console::WriteLine("The log does not exist!");
		return 0;
	}

	EventLog^ aLog = gcnew EventLog();
	aLog->Log = log;
	aLog->MachineName = machine;

	Console::WriteLine(String::Concat("There are ", aLog->Entries->Count.ToString(), " entr[y|ies] in the log:"));

	EventLogEntryCollection^ entries = aLog->Entries;
	if (entries->Count > 0)
	{
		EventLogEntry^ entry;
		for (int i = 0; i < entries->Count; i++)
		{
			entry = entries->default::get(i);
			Console::WriteLine(String::Concat("\tEntry: ", entry->Message));
		}
	}

	return 0;
}
