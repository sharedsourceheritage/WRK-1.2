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
using namespace System::Data::SqlClient;
using namespace System::Xml;

ref class filterdatatable
{
public:
  void Run()
  {
    // Create a new Connection and SqlDataAdapter
    SqlConnection ^ myConnection = gcnew SqlConnection("server=(local)\\SQLExpress;Integrated Security=SSPI;database=northwind");
    SqlDataAdapter ^ mySqlDataAdapter = gcnew SqlDataAdapter("select * from customers", myConnection);

    // Create the new instance of the DataSet
    DataSet ^ myDataSet = gcnew DataSet();

    // Load the customer table from the database into a table called Customers in the dataset
    mySqlDataAdapter->Fill(myDataSet,"Customers");

    // Create a new dataview instance on the Customers table that was just created
    DataView ^ myDataView = gcnew DataView(myDataSet->Tables["Customers"]);

    // Sort the view based on the CustomerID column
    myDataView->Sort = "CustomerID";

    // Filter the dataview to only show customers with the CustomerID of ALFKI
    myDataView->RowFilter = "CustomerID='ALFKI'";

    for (int i = 0; i < myDataView->Count; i++)
    {
      Console::Write(myDataView[i]["CustomerID"]->ToString());
	  Console::Write(" - ");
	  Console::WriteLine(myDataView[i]["CompanyName"]->ToString());
    }
  }
};

void main()
{
	filterdatatable ^ myfilterdatatable = gcnew filterdatatable();
	myfilterdatatable->Run();
}

