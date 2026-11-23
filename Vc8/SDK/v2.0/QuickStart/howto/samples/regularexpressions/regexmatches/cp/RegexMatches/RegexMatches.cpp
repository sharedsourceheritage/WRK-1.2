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

            Regex ^ digitregex = gcnew Regex("(?<number>\\d+)");
            String ^ s = "abc 123 def 456 ghi 789";

            if ( argv->Length > 1 ) {
		    array<String^> ^ args = Environment::GetCommandLineArgs();
                s = String::Join(" ", args);
            }

            MatchCollection ^ mc = digitregex->Matches(s);

            if ( mc->Count > 0 ) {
                Console::WriteLine("Digits:");
                for(Int32 i = 0; i < mc-> Count; i++)
					Console::WriteLine(String::Concat("  ",mc->default::get(i)->Value));
            } else {
                Console::WriteLine(String::Concat("[", s, "] contains no numbers."));
            };

            Console::WriteLine();
            Console::WriteLine("Press Enter to Continue...");
            Console::ReadLine();
}


  
