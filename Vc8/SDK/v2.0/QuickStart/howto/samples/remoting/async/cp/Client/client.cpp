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

// client.cpp


using namespace System;
using namespace System::Threading;


using namespace System::Runtime::Remoting;
using namespace System::Runtime::Remoting::Messaging;
using namespace System::Runtime::Remoting::Channels;
using namespace System::Runtime::Remoting::Channels::Tcp;


using namespace Microsoft::Samples::RemotingSamples;

public ref class Client 
{
public:
	static ManualResetEvent^ e;
    delegate String^ MyDelegate(String^ name);

public:
	Client()
	{
		e = gcnew ManualResetEvent(false);

		TcpChannel^ chan = gcnew TcpChannel();
		ChannelServices::RegisterChannel(chan, true);
		HelloServer^ obj = safe_cast<HelloServer ^>(Activator::GetObject(Microsoft::Samples::RemotingSamples::HelloServer::typeid, "tcp://localhost:8085/SayHello"));
		if (obj)
		{
			AsyncCallback^ cb = gcnew AsyncCallback(&(Client::MyCallBack));
			MyDelegate^ d = gcnew MyDelegate(obj, &(HelloServer::HelloMethod));
			IAsyncResult^ ar = d->BeginInvoke("Caveman", cb, nullptr);
		}
		else 
			Console::WriteLine("Could not locate server");

		e->WaitOne();
	}

	static void MyCallBack(IAsyncResult^ ar)
	{
		MyDelegate^ d = safe_cast<MyDelegate ^>(safe_cast<AsyncResult ^>(ar)->AsyncDelegate);
		Console::WriteLine(d->EndInvoke(ar));
		e->Set();
	}
};

void main()
{
	Client^ cl = gcnew Client();
}
