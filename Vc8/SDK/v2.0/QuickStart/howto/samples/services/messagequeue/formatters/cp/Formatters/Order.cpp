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

[Serializable]
public ref class Order {
protected:

    Int64 orderId;
    String^ itemDescription;

public:
	property Int64 OrderId {
		Int64 get() {
			return orderId;
		}

		void set( Int64 value ) {
			orderId = value;
		}
	}
    
    property String^ ItemDescription {
		String^ get() {
			return itemDescription;
		}

		void set( String^ value ) {
			itemDescription = value;
		}
	}
};


  
