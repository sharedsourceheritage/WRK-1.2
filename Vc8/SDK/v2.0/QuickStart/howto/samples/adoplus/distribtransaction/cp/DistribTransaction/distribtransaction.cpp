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
#using <System.EnterpriseServices.dll>


using namespace System;
using namespace System::Data;
using namespace System::Reflection;
using namespace System::Data::SqlClient;
using namespace System::EnterpriseServices;

[assembly: AssemblyKeyFileAttribute("keyfile.snk")];
[TransactionAttribute(TransactionOption::Required)]
public ref class myServicedComponent : public ServicedComponent
{
private:
	SqlConnection ^ m_rConnection;

public:
	myServicedComponent()
	{
	}

   property SqlConnection^ SqlConn { SqlConnection^ get() {return m_rConnection; } }
  

   property ConnectionState^ State  { ConnectionState^ get() {return  m_rConnection->State; } }


  void myServicedComponentConnect(String ^ ConnectionString)
  {
    m_rConnection = gcnew SqlConnection(ConnectionString);
    m_rConnection->Open();
  }

  void myServicedComponentClose()
  {
	  if (m_rConnection != nullptr)
        m_rConnection->Close();
  }

  void myServicedComponentDispose()
  {
      if (m_rConnection != nullptr)
          m_rConnection->Close();
  }

  void myServicedComponentChangeDatabase(String^ DBName)
  {
      if (m_rConnection != nullptr)
          m_rConnection->ChangeDatabase(DBName);
  }

  SqlCommand^ myServicedComponentCreateCommand()
  {
    return gcnew SqlCommand(nullptr, m_rConnection);
  }

  void myServicedComponentSetComplete()  // to commit changes
  {
	Console::WriteLine("Committing connection\'s transaction.");
	ContextUtil::SetComplete();
    Console::WriteLine("SetComplete");
  }

  void myServicedComponentSetAbort()     // to rollback the distributed transaction
  {
    Console::WriteLine("Aborting connection\'s transaction.");
	ContextUtil::SetAbort();
    Console::WriteLine("SetAbort");
  }
};

ref class distribtransaction
{
public:

  void Run()
  {
    SqlCommand ^ mySqlCommand;
    myServicedComponent ^ mySC = gcnew myServicedComponent();

    mySC->myServicedComponentConnect("server=(local)\\SQLExpress;Integrated Security=SSPI;database=northwind");
    Console::Write("connection state is: ");
    Console::WriteLine(mySC->State);

    mySqlCommand = gcnew SqlCommand(nullptr, mySC->SqlConn);

    try
    {
      // Clean up the database to restore to its original state.
      mySqlCommand->CommandText = "if exists (select * from sysobjects where name = 'TestTable' and type = 'U') drop table TestTable";
      mySqlCommand->ExecuteNonQuery();

      // Create table "TestTable".
      Console::WriteLine("Creating table TestTable.");
      mySqlCommand->CommandText = "create table TestTable (c1 int identity, c2 int)";
      mySqlCommand->ExecuteNonQuery();

      // Create unique index ss on TestTable.
      Console::WriteLine("Creating unique index ss on TestTable.");
      mySqlCommand->CommandText = "create unique index ss on TestTable(c1)";
      mySqlCommand->ExecuteNonQuery();

      // Insert into TestTable values.
      Console::WriteLine("Inserting into TestTable values.");
      mySqlCommand->CommandText = "insert into TestTable values (11)";
      mySqlCommand->ExecuteNonQuery();

      // Commit the transaction.
      mySC->myServicedComponentSetComplete();
    }
    catch (Exception ^ e)
    {
      Console::Write(e->ToString());

      // Rollback the transaction.
      mySC->myServicedComponentSetAbort();
    }
    __finally
    {
      //mySC->myServicedComponentClose();
      //Console::WriteLine("connection state is: " + mySC->State);
    }
  }
};

void main()
{
  distribtransaction ^ mydistribtransaction = gcnew distribtransaction();
  mydistribtransaction->Run();
}


