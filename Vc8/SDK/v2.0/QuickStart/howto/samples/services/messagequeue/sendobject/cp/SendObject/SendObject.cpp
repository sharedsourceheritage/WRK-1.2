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
#using <system.messaging.dll>
#using <system.dll>

using namespace System;
using namespace System::Messaging;

#include "Customer.cpp"

int main(void) {
	String^ mqPath =  ".\\MQSendSample";

	if(!MessageQueue::Exists(mqPath)) {
		MessageQueue::Create(mqPath);
	}
	        
	MessageQueue^ mq = gcnew MessageQueue(mqPath);
		
	Customer^ customer = gcnew Customer;
	customer->LastName = "Copernicus";
	customer->FirstName = "Nicolaus";        

	mq->Send(customer);    

	return 0;
}
