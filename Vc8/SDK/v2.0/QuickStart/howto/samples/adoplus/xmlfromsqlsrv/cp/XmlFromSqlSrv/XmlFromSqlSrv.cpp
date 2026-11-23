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
#using <System.Xml.dll>
#using <System.Data.dll>

using namespace System;
using namespace System::Data;
using namespace System::Xml;
using namespace System::Data::SqlClient;

ref class xmlfromsqlsrv
{
public:

  void Run()
  {
    String^ sConnection = "server=(local)\\SQLExpress;Integrated Security=SSPI;database=northwind";
    SqlConnection^ mySqlConnection = gcnew SqlConnection(sConnection);
    SqlCommand^ mySqlCommand = gcnew SqlCommand("select * from customers FOR XML AUTO, XMLDATA", mySqlConnection);
    mySqlCommand->CommandTimeout = 15;

    try
    {
	mySqlConnection->Open();

	// Now create the DataSet and fill it with xml data.
	DataSet^ myDataSet1 = gcnew DataSet();
	myDataSet1->ReadXml(safe_cast<XmlTextReader^>(mySqlCommand->ExecuteXmlReader()), XmlReadMode::Fragment);

	// Modify to match the other dataset
	myDataSet1->DataSetName = "NewDataSet";


	// Get the same data through the provider.
	SqlDataAdapter^ mySqlDataAdapter = gcnew SqlDataAdapter("select * from customers", sConnection);
	DataSet^ myDataSet2 = gcnew DataSet();
	mySqlDataAdapter->Fill(myDataSet2);

	// Write data to files: data1.xml and data2.xml for comparison.
	myDataSet1->WriteXml("data1.xml");
	myDataSet2->WriteXml("data2.xml");
	Console::WriteLine ("Data has been writen to the output files: data1.xml and data2.xml");
    }
    catch(Exception^ e)
    {
      Console::WriteLine(e->ToString());
    }
    finally
    {
      mySqlConnection->Close();
    }
  }
};

void main()
{
	xmlfromsqlsrv^ myxmlfromsqlsrv = gcnew xmlfromsqlsrv();
	myxmlfromsqlsrv->Run();
}
