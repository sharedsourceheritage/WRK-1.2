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

ref class adooverview3
{
public:
	
	void Run()
  {
		SqlDataReader ^ myReader;

    SqlConnection ^ mySqlConnection = gcnew SqlConnection("server=(local)\\SQLExpress;Integrated Security=SSPI;database=northwind");
    SqlCommand ^ mySqlCommand = gcnew SqlCommand("select * from customers", mySqlConnection);

    try
    {
      mySqlConnection->Open();
      myReader = mySqlCommand->ExecuteReader();

			Console::Write("Customer ID    ");
			Console::WriteLine("Company Name");

      while (myReader->Read())
      {
				Console::Write(myReader->default["CustomerID"]);
				Console::Write("      ");
				Console::WriteLine(myReader->default["CompanyName"]);
      }
    }
    catch(Exception ^ e)
    {
			Console::Write(e->Message);
    }
    myReader->Close();
    mySqlConnection->Close();
  }
};

#ifdef _UNICODE
int wmain(void)
#else
int main(void)
#endif
{
    adooverview3 ^ myadooverview3 = gcnew adooverview3();
    myadooverview3->Run();
    return 0;
}
