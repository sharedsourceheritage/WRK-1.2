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

#using <mscorlib.dll>
#using <system.dll>
#using <system.messaging.dll>

using namespace System;
using namespace System::Messaging;

void main( int argc, char* argv[] ) {

	// Args in main signature must be unmanaged - do the conversion here.
	array<String^>^ args = Environment::GetCommandLineArgs();

	if ( argc != 4 ) {
		Console::WriteLine("Usage: ");
		Console::WriteLine(String::Concat( "\t", args[0], " <queue> <command> <value>" ));
		Console::WriteLine("" );
		Console::WriteLine("\t\t<command> =");
		Console::WriteLine("\t\t\tl: change label");
		Console::WriteLine("\t\t\ts: change queue size");
		Console::WriteLine("\t\t\tj: change journal size");
		return;
	}

	String^ mqPath = String::Concat( ".\\", args[1] );
	if ( !MessageQueue::Exists(mqPath) ) {
		Console::WriteLine( String::Concat( "The queue ", mqPath, " does not exist" ) );
		return;
	}

	MessageQueue^ mq = gcnew MessageQueue(mqPath);

	String^ command = args[2];

	if ( command->Equals( "l" ) ) {
		mq->Label = args[3];
	} else if ( command->Equals( "s" ) ) {
		mq->MaximumQueueSize = UInt32::Parse(args[3]);
	} else if ( command->Equals( "j" ) ) {
		mq->MaximumJournalSize = UInt32::Parse(args[3]);
	}
    
	return;
}
