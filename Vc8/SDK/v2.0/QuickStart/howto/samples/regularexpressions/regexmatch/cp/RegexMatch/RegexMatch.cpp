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

#using <System.dll>
using namespace System::Text::RegularExpressions;

int main(array<String^>^ argv)
{
   Regex ^ emailregex = gcnew Regex("(?<user>[^@]+)@(?<host>.+)");
   String ^ s = "johndoe@tempuri.org";

   if ( argv->Length > 1 )
   {
      s = argv[1];
   }; 

   Match ^ m = emailregex -> Match(s);

  if ( m->Success ) {
	  Console::WriteLine(String::Concat("User: ", m->Groups->default::get("user")->Value));
	  Console::WriteLine(String::Concat("Host: ", m->Groups->default::get("host")->Value));
   } else {
	   Console::WriteLine(String::Concat(s, " is not a valid email address"));

   };


   Console::WriteLine();
   Console::WriteLine("Press Enter to Continue...");
   Console::ReadLine();
   
}
