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
#using <System.dll>
#using <System.Data.dll>
#using <System.Xml.dll>
//#using "TypedData.dll" (in project references)

using namespace System;
using namespace System::Data;
using namespace System::Xml;
using namespace System::Data::SqlClient;
using namespace customerDataSet;

 ref class typeddata
{
public:
  void Run()
  {
    custDS^ myCustDS = gcnew custDS();
    SqlDataAdapter^ mySqlDataAdapter = gcnew SqlDataAdapter("Select * from customers", "server=(local)\\SQLExpress;Trusted_Connection=yes;database=northwind");
    mySqlDataAdapter->Fill(myCustDS, "Customers");

	Console::WriteLine("CustomerID\n");

	for(int i =0; i< myCustDS->Tables[0]->Rows->Count; i++)
		Console::WriteLine(myCustDS->Tables[0]->Rows[i][0]->ToString());
  }
};

void main()
{
	typeddata^ mytypeddata = gcnew typeddata();	 
	 mytypeddata->Run();
}
