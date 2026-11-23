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

// server.cpp


using namespace System;
using namespace System::Collections;


using namespace System::Runtime::Remoting;
using namespace System::Runtime::Remoting::Channels;
using namespace System::Runtime::Remoting::Channels::Tcp;
using namespace System::Runtime::Serialization::Formatters::Binary;
using namespace System::Runtime::Serialization::Formatters;



void main()
{
	// creating a custom formatter for your TcpChannel sink chain.
	BinaryServerFormatterSinkProvider^ provider = gcnew BinaryServerFormatterSinkProvider();
	provider->TypeFilterLevel = TypeFilterLevel::Full;

	// creating the dictionary to set the port on the channel instance.
	Hashtable^ props = gcnew Hashtable();
	props->Add("port", (8085));

	// pass the props for the port setting and the server provider in the server chain argument. (Client remains null here.)
	TcpChannel^ chan = gcnew TcpChannel(props, nullptr, provider);
	ChannelServices::RegisterChannel(chan, true);
	RemotingConfiguration::RegisterWellKnownServiceType(Type::GetType("Microsoft.Samples.RemotingSamples.HelloServer,Share"), "SayHello", WellKnownObjectMode::SingleCall);

	Console::WriteLine("Hit <enter> to exit...");
	Console::ReadLine();
}
