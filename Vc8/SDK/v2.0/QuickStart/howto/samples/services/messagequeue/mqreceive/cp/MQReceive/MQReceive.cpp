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

// This is the main project file for VC++ application project 
// generated using an Application Wizard.

#using <mscorlib.dll>
#using <system.dll>
#using <system.messaging.dll>

using namespace System;
using namespace System::Messaging;


int main( int argc, char* argv[] )
{
	// Args in main signature must be unmanaged - do the conversion here.
	array<String^>^ args = Environment::GetCommandLineArgs();

	if ( argc != 2 ) {
		Console::WriteLine( String::Concat( "Usage: ", args[0], " <queue>" ) );
	} else {
		String^ mqPath = String::Concat( ".\\", args[1] );

		if ( !MessageQueue::Exists(mqPath) ) {
			Console::WriteLine( String::Concat( "The queue '", mqPath, "' does not exist!" ) );
			return -1;
		}

		MessageQueue^ mq = gcnew MessageQueue(mqPath);
		
		try {
			array<String^>^ strTypeNames = gcnew array<String^>(1){ "System.String,mscorlib" };
			safe_cast<XmlMessageFormatter^>( mq->Formatter )->TargetTypeNames = strTypeNames;
		}
		catch( InvalidCastException^ ) {
			Console::WriteLine( "Error: XmlMessageFormatter* cast failed." );
			return -1;
		}

		try {
			Message^ m = mq->Receive( TimeSpan(0,0,3) );
			Console::WriteLine( String::Concat( "Message: ", safe_cast<String^>(m->Body) ) );
		}
		catch ( MessageQueueException^ ) {
			Console::WriteLine( "There are no messages in the queue" );
			return -1;
		}
		catch ( InvalidOperationException^ ) {
			Console::WriteLine( "The message removed from the queue is not a string" );
			return -1;
		}
		catch ( InvalidCastException^ ) {
			Console::WriteLine( "Error: String* cast failed." );
			return -1;
		}
	}

	Console::WriteLine();
	Console::WriteLine("Press Enter to continue...");
	Console::ReadLine();

    return 0;
}
