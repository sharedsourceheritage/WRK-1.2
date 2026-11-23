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

// logwrite.cpp


using namespace System;


using namespace System::Diagnostics;

int main(array<String^>^ argv)
{
	if ( argv->Length != 3 ) 
	{
		Console::WriteLine(String::Concat("Usage: ", " <log> <message> <source>"));
		Console::WriteLine();
		Console::WriteLine("Press any key to continue...");
		Console::ReadLine();
		return 0;
	}

	String^ log = argv[0];
	String^ message = argv[1];
	String^ source = argv[2];

	if ( !EventLog::SourceExists(source) )
	{
		try
		{
			EventLog::CreateEventSource(source, log);
		}
		catch (System::Security::SecurityException^) 
		{
			Console::WriteLine("You need to have permissions to write to the System Log to use this sample.");
		}
	}

	try
	{
		EventLog^ aLog = gcnew EventLog();
		aLog->Source = source;
		aLog->WriteEntry(message, EventLogEntryType::Information);

		Console::WriteLine("Entry written successfuly!");
	}
	catch (System::Security::SecurityException^)
	{
		Console::WriteLine("You need to have permissions to write to the System Log to use this sample.");
	}

	return 0;
}
