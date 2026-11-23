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

using namespace System;
using namespace System::Collections;
using namespace System::Security;
using namespace System::Security::Permissions;

[assembly:EnvironmentPermission(SecurityAction::RequestRefuse,
Read="USERNAME;USERDOMAIN;USERDNSDOMAIN;COMPUTERNAME;LOGONSERVER",
Write="USERNAME;USERDOMAIN;USERDNSDOMAIN;COMPUTERNAME;LOGONSERVER")];

String^ GetEnvironmentValue(String^ Var);

// This is the entry point for this application
void main()
{
	//We are guaranteed to get these (providing they are set, of course)
	Console::WriteLine("Processor: {0}", GetEnvironmentValue("PROCESSOR_IDENTIFIER"));
	Console::WriteLine("Revision: {0}", GetEnvironmentValue("PROCESSOR_REVISION"));
	Console::WriteLine("Count: {0}", GetEnvironmentValue("NUMBER_OF_PROCESSORS"));
	Console::WriteLine("Operating System: {0}", GetEnvironmentValue("OS"));

	//We may or may not get these depending upon security policy
	Console::WriteLine("System Drive: {0}", GetEnvironmentValue("SYSTEMDRIVE"));
	Console::WriteLine("System Path: {0}", GetEnvironmentValue("SYSTEMROOT"));
	Console::WriteLine("Extensions: {0}", GetEnvironmentValue("PATHEXT"));

	//Should always return a security exception
	Console::WriteLine("ComputerName: {0}", GetEnvironmentValue("COMPUTERNAME"));

	Console::Write("\nPress Enter to exit...");
	Console::Read();

    return;
}


String^ GetEnvironmentValue(String^ Var) 
{
	try 
	{
		String^ Val = Environment::GetEnvironmentVariable(Var);

		if (Val == nullptr)
			return "*Not Set*";
		else
			return Val;

	} 
	catch (SecurityException^) 
	{
		return "*Inadequate Permissions*";
	} 
}