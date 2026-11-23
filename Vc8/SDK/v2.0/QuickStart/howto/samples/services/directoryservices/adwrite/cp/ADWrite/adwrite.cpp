
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
// adwrite.cpp
//
using namespace System;

#using <System.dll>
#using <System.DirectoryServices.dll>

using namespace System::DirectoryServices;
void main( int argc, char ** argv )
{
   if ( argc != 4 )
   {
      Console::WriteLine( String::Concat( L"Usage: ", Environment::GetCommandLineArgs()[ 0 ], L" <ad_path> <property> <value>" ) );
      Console::WriteLine();
      Console::WriteLine( L"Press any key to continue..." );
      Console::ReadLine();
      return;
   }

   DirectoryEntry^ objDirEnt = gcnew DirectoryEntry( gcnew String(argv[ 1 ]) );
   Console::WriteLine( String::Concat( L"Name            = ", objDirEnt->Name ) );
   Console::WriteLine( String::Concat( L"Path            = ", objDirEnt->Path ) );
   Console::WriteLine( String::Concat( L"SchemaClassName = ", objDirEnt->SchemaClassName ) );
   PropertyCollection^ properties = objDirEnt->Properties;
   PropertyValueCollection^ values;
   String^ propertyName = gcnew String(argv[ 2 ]);
   int count = 0;
   if(properties->Contains(propertyName))
   {           
	   values = properties[propertyName];
	   count = values->Count;
	   for(int i = 0; i < count; i++)
		   Console::WriteLine(L"{0} = {1}", propertyName, values[i]);
	   
   }
   else
   {
	   Console::WriteLine(String::Concat(L"Property ", propertyName, L"'s value is not yet set"));
   }
   Console::WriteLine( L"... changing to " );
   objDirEnt->Properties[propertyName]->Value = Environment::GetCommandLineArgs()[ 3 ];
   objDirEnt->CommitChanges();
   properties = objDirEnt->Properties;
   values = properties[propertyName];
   count = values->Count;
   
   for(int i = 0; i < count; i++)
	   Console::WriteLine(L"{0} = {1}", propertyName, values[i]);
}

