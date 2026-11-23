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

#include "Order.cpp"

#using <mscorlib.dll>
#using <system.dll>
#using <system.messaging.dll>

using namespace System;
using namespace System::Messaging;

int main( int argc, char* argv[] ) {

	String^ mqPath = ".\\FormattersSample";

	if ( !MessageQueue::Exists(mqPath) ) {
		MessageQueue::Create(mqPath);
	}

	MessageQueue^ mq = gcnew MessageQueue(mqPath);

	Order^ order = gcnew Order();
	order->OrderId = 102;
	order->ItemDescription = "MS Visual Studio 7";

	mq->Formatter = gcnew XmlMessageFormatter;
	mq->Send(order);

	mq->Formatter = gcnew BinaryMessageFormatter;        
	mq->Send(order);

	mq->Formatter = gcnew ActiveXMessageFormatter;     
	mq->Send(10);

	return 0;
}
