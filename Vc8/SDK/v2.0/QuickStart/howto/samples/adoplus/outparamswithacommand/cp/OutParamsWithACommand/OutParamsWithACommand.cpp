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

using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;

ref class outparamswithacommand
{
public:
  void Run()
  {
    String^ MsgString = nullptr;

    // Create a new Connection and SqlDataAdapter
    SqlConnection ^ myConnection = gcnew SqlConnection("server=(local)\\SQLExpress;Integrated Security=SSPI;database=northwind");

    // Create stored procedure with out parameter
    try
    {
      SqlCommand ^ CreateProcCommand = gcnew SqlCommand("CREATE PROCEDURE GetCompanyName  @CustomerId nchar(5), @CompanyName nchar(40) out as select @CompanyName = CompanyName from Customers where CustomerId = @CustomerId",myConnection);
      SqlCommand ^ DropProcCommand = gcnew SqlCommand("IF EXISTS (SELECT name FROM sysobjects WHERE name = 'GetCompanyName' AND type = 'P') DROP PROCEDURE GetCompanyName", myConnection);

      myConnection->Open();
      DropProcCommand->ExecuteNonQuery();   // remove procedure if it exists
      CreateProcCommand->ExecuteNonQuery(); // create procedure

      SqlCommand ^ myCommand = gcnew SqlCommand("GetCompanyName", myConnection);
	  myCommand->CommandType = CommandType::StoredProcedure;

      // Fill the parameters collection based upon stord procedure.
      SqlParameter ^ inParam = gcnew SqlParameter("@CustomerID", SqlDbType::NChar, 5);
	  inParam->Direction = ParameterDirection::Input;
	  inParam->Value = "ALFKI";

	  SqlParameter ^ outParam = gcnew SqlParameter("@CompanyName", SqlDbType::NChar, 40);
	  outParam->Direction = ParameterDirection::Output;

	  myCommand->Parameters->Add(inParam);
	  myCommand->Parameters->Add(outParam);

      myCommand->ExecuteNonQuery();
	  MsgString = String::Concat("CompanyName = ",myCommand->Parameters["@CompanyName"]->Value->ToString());
    }
    catch(Exception ^ e)
    {
      MsgString = e->ToString();
    }
    finally
    {
      myConnection->Close();
    }

    Console::Write(MsgString);
  }
};

void main()
{
	outparamswithacommand ^ myoutparamswithacommand = gcnew outparamswithacommand();
	myoutparamswithacommand->Run();
}

