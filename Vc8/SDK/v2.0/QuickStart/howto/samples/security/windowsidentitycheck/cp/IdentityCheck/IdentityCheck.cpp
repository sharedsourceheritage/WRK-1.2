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
using namespace System::Security;
using namespace System::Security::Permissions;
using namespace System::Security::Principal;
using namespace System::Threading;

[assembly:SecurityPermission(SecurityAction::RequestMinimum, ControlPrincipal=true)];
[PrincipalPermission(SecurityAction::Demand, Role="BUILTIN\\Administrators")]
String^ DeclAdminCheck() 
{
	return "Declarative check for Administrators group passed!";
}

[PrincipalPermission(SecurityAction::Demand, Role="BUILTIN\\Users")]
String^ DeclUserCheck() 
{
	return "Declarative check for Users group passed!";
}

// This is the entry point for this application
void main()
{
	AppDomain::CurrentDomain->SetPrincipalPolicy(PrincipalPolicy::WindowsPrincipal);

	WindowsPrincipal^ user = safe_cast<WindowsPrincipal^>(Thread::CurrentPrincipal);

	Console::WriteLine("User name: {0}",                  user->Identity->Name);
	Console::WriteLine("Authentication type: {0}",        user->Identity->AuthenticationType);
	Console::WriteLine("Is in Administrators group: {0}", user->IsInRole(WindowsBuiltInRole::Administrator).ToString() );
	Console::WriteLine("Is in Users group: {0}",         user->IsInRole(WindowsBuiltInRole::User).ToString());

	try 
	{
		Console::WriteLine("\n{0}", DeclAdminCheck());
	}
	catch (SecurityException^ se) 
	{
		if ( se->PermissionType == PrincipalPermission::typeid ) 
		{
			Console::WriteLine("\nDeclarative check for Admin group failed!");
		}
	}

	try 
	{
		Console::WriteLine("\n{0}", DeclUserCheck());
	}
	catch (SecurityException^ se)
	{
		if ( se->PermissionType == PrincipalPermission::typeid ) 
		{
			Console::WriteLine("\nDeclarative check for Users group failed!");
		}
	}

	
	Console::WriteLine("\nPress Enter to Exit.");
	Console::Read();
}