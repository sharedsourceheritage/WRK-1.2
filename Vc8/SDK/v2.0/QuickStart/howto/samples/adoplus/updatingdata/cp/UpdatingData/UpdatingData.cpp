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

ref class UpdatingData
{
public:
  void Run()
  {
  
	// Create a new Connection and SqlDataAdapter
	SqlConnection^ myConnection = gcnew SqlConnection("server=(local)\\SQLExpress;Integrated Security=SSPI;database=northwind");
	SqlDataAdapter^ mySqlDataAdapter = gcnew SqlDataAdapter("Select * from Region", myConnection);
	SqlParameter^ workParam = nullptr;

	// Restore database to it's original condition so sample will work correctly.
	myConnection->Open();
	SqlCommand^ CleanupCommand = gcnew SqlCommand("DELETE FROM Region WHERE RegionID = '901'", myConnection);
	CleanupCommand->ExecuteNonQuery();
	myConnection->Close();

	// Build the insert Command
	mySqlDataAdapter->InsertCommand = gcnew SqlCommand("Insert into Region (RegionID, RegionDescription) VALUES (@RegionID, @RegionDescription)", myConnection);
	workParam = mySqlDataAdapter->InsertCommand->Parameters->Add(gcnew SqlParameter("@RegionID", SqlDbType::Int));
	workParam->SourceColumn = "RegionID";
	workParam->SourceVersion = DataRowVersion::Current;

	workParam = mySqlDataAdapter->InsertCommand->Parameters->Add(gcnew SqlParameter("@RegionDescription", SqlDbType::NChar, 50));
	workParam->SourceVersion = DataRowVersion::Current;
	workParam->SourceColumn = "RegionDescription";

	// Build the update command
	mySqlDataAdapter->UpdateCommand = gcnew SqlCommand("Update Region Set RegionDescription = @RegionDescription WHERE RegionID = @RegionID" , myConnection);

	workParam = mySqlDataAdapter->UpdateCommand->Parameters->Add(gcnew SqlParameter("@RegionID", SqlDbType::Int));
	workParam->SourceColumn = "RegionID";
	workParam->SourceVersion = DataRowVersion::Original;

	workParam = mySqlDataAdapter->UpdateCommand->Parameters->Add(gcnew SqlParameter("@RegionDescription", SqlDbType::NChar, 50));
	workParam->SourceVersion = DataRowVersion::Current;
	workParam->SourceColumn = "RegionDescription";

	DataSet^ myDataSet = gcnew DataSet();

	// Set the MissingSchemaAction property to AddWithKey because Fill will not cause primary key & unique key information to be retrieved unless AddWithKey is specified.
	mySqlDataAdapter->MissingSchemaAction = MissingSchemaAction::AddWithKey;
	mySqlDataAdapter->Fill(myDataSet, "Region");

	DataRow^ myDataRow1 = myDataSet->Tables["Region"]->Rows->Find((2));
	myDataRow1[1] = "Changed this region desc";

	DataRow^ myDataRow2 = myDataSet->Tables["Region"]->NewRow();
	myDataRow2[0] = (901);
	myDataRow2[1] = "A new region";
	myDataSet->Tables["Region"]->Rows->Add(myDataRow2);

	try
	{
		mySqlDataAdapter->Update(myDataSet, "Region");
		Console::Write("DataSet transaction succeeded!");
	}
	catch(Exception^ e)
	{
		Console::Write(e->ToString());
	}
  }
};

void main()
{
    UpdatingData^ myupdatingdata = gcnew UpdatingData();
    myupdatingdata->Run();
}

