
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
// adread.cpp
//
using namespace System;
using namespace System::Collections;

#using <System.dll>
#using <System.DirectoryServices.dll>

using namespace System::DirectoryServices;
void main( int argc, char ** argv )
{
   if ( argc != 2 )
   {
      Console::WriteLine( String::Concat( L"Usage: ", Environment::GetCommandLineArgs()[ 0 ], L" <ad_path>" ) );
      Console::WriteLine();
      Console::WriteLine( L"Press any key to continue..." );
      Console::ReadLine();
      return;
   }

   DirectoryEntry^ objDirEnt = gcnew DirectoryEntry( gcnew String(argv[ 1 ]) );
   Console::WriteLine( String::Concat( L"Name            = ", objDirEnt->Name ) );
   Console::WriteLine( String::Concat( L"Path            = ", objDirEnt->Path ) );
   Console::WriteLine( String::Concat( L"SchemaClassName = ", objDirEnt->SchemaClassName ) );
   Console::WriteLine( L"" );
   Console::WriteLine( L"Properties:" );
   String^ Key;
   Object^ objValue;
   ICollection^ PropCol = objDirEnt->Properties->PropertyNames;
   if ( PropCol->Count > 0 )
   {
      IEnumerator^ Enum1 = PropCol->GetEnumerator();
      while ( Enum1->MoveNext() )
      {
         Key = Enum1->Current->ToString();
         Console::Write( L"\t{0} = ", Key );
         Console::WriteLine( L"" );
         ICollection^ ValCol = objDirEnt->Properties[Key];
         if ( ValCol->Count > 0 )
         {
            IEnumerator^ Enum2 = ValCol->GetEnumerator();
            while ( Enum2->MoveNext() )
            {
               objValue = Enum2->Current;
               Console::WriteLine( L"\t\t{0}", objValue );
            }
         }
      }
   }
}

