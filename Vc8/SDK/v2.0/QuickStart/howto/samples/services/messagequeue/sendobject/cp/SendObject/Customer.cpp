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

public ref class Customer {
protected:
	String^ lastName;
	String^ firstName;

public:
	property String^ LastName {
		String^ get() {
			return lastName;
		}

		void set( String^ value ) {
			lastName = value;
		}
	}
	
	property String^ FirstName {
		String^ get() {
			return firstName;
		}
	
		void set( String^ value ) {
			firstName = value;
		}
	}
	
	property String^ FullName {
		String^ get() {
			return String::Concat( firstName, lastName );
		}
	}
};
