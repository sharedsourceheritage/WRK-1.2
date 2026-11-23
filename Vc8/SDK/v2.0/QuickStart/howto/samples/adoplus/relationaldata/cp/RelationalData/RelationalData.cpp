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

using namespace System;
using namespace System::Data;
using namespace System::Xml;
using namespace System::Data::SqlClient;

ref class RelationalData
{
public:
  void Run()
  {
    DataSet^ myDataSet = gcnew DataSet();

    SqlConnection^ myConnection = gcnew SqlConnection("server=(local)\\SQLExpress;Integrated Security=SSPI;database=northwind");
    SqlDataAdapter^ mySqlDataAdapter1 = gcnew SqlDataAdapter("select * from customers", myConnection);
    SqlDataAdapter^ mySqlDataAdapter2 = gcnew SqlDataAdapter("select * from orders", myConnection);

    mySqlDataAdapter1->Fill(myDataSet,"Customers");
    mySqlDataAdapter2->Fill(myDataSet,"Orders");

    // ADD RELATION
    myDataSet->Relations->Add("CustOrders",myDataSet->Tables["Customers"]->Columns["CustomerId"],myDataSet->Tables["Orders"]->Columns["CustomerId"]);

    // Iterate over data of Customers and their orders
    for(int i = 0; i< myDataSet->Tables["Customers"]->Rows->Count; i++)
    {
	  DataRow ^ myDataRow1 = myDataSet->Tables["Customers"]->Rows[i];
    	  Console::Write("Customer: ");
	  Console::WriteLine(myDataRow1["ContactName"]->ToString());

      // Iterate over orders data.
      array<DataRow^> ^rows = myDataRow1->GetChildRows(myDataSet->Relations["CustOrders"]);
      for(int j = 0; j< rows->Length; j++)
      {
        Console::Write("Order #");
		Console::WriteLine(rows[j]["OrderId"]->ToString());
      }

      Console::WriteLine();
    }
    myConnection->Close();
  }
};
void main()
{
	RelationalData^ myrelationaldata = gcnew RelationalData();
	myrelationaldata->Run();
}
