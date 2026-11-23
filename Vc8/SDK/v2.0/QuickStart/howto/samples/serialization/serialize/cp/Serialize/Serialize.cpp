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

using namespace System;
using namespace System::IO;
using namespace System::Collections;
using namespace System::Runtime::Serialization;
using namespace System::Runtime::Serialization::Formatters::Binary;

int main( void ) {

	Console::WriteLine( "Create object graph" );

	ArrayList^ l = gcnew ArrayList;
	for( int x = 0; x < 10; x++ ) {
		Console::WriteLine( x );
		l->Add(x);
	} // end for

	Console::Write( "Serializing object graph to disk.." );

	Stream^ s = File::Open( "foo.bin", FileMode::Create, FileAccess::Write );
	BinaryFormatter^ b = gcnew BinaryFormatter;
	b->Serialize( s, l );
	s->Close();

	Console::WriteLine( "Complete." );
	Console::Write ("Deserializing object graph from disk..");

	Stream^ r = File::Open( "foo.bin", FileMode::Open, FileAccess::Read );
	BinaryFormatter^ c = gcnew BinaryFormatter;
	ArrayList^ p;
	try {
		p = safe_cast<ArrayList^>( c->Deserialize( r ) );
	}
	catch( InvalidCastException^ ) {
		Console::WriteLine( "Error: Cast failed." );
		return -1;
	}

	Console::WriteLine( "Complete." );
	for( int x = 0; x < p->Count; x++ ) {
		Console::WriteLine( p->default[x] );
	} // end for

	r->Close();

	Console::WriteLine( "\r\nPress Return to exit." );
	Console::Read();

    return 0;
} // end main
