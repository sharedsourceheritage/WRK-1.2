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
using namespace Text::RegularExpressions;


int main(array<String^>^ argv){
   Regex ^ digitregex = gcnew Regex("(?<digit>[0-9])");
   String ^ before = "Here is so4848me te88xt with emb4493edded numbers.";
            
   if ( argv->Length > 1 ) {
   array<String^>^ args = Environment::GetCommandLineArgs();
   before = String::Join(" ", args);
   }
            
   String ^ after = digitregex -> Replace(before, "");            

   Console::WriteLine(String::Concat("Before: ", before));
   Console::WriteLine(String::Concat("After : ", after));

   Console::WriteLine();
   Console::WriteLine("Press Enter to Continue...");
   Console::ReadLine();
}

