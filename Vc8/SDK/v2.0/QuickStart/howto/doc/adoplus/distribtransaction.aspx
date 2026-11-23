<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>
    
    <h2>ADO.NET: Use Distributed Transactions</h2>
    
    <br /><br />This sample illustrates how to use distributed transactions, which are available automatically from the Microsoft .NET Framework component services. Microsoft Transaction Server (MTS),
    Microsoft .NET Framework SDK, and the common language runtime
    support the same automatic, distributed transaction model. To use this feature,
    complete
    the following steps to provide for automatic distributed transactions to your
    data source.
    <br /><br /><OL type=1>
    <LI>Use <b>System.EnterpriseServices</b>.
    <LI>Create a <b>ServicedComponent</b> to provide automatic transaction support.
    <LI>Add some features to the <b>ServicedComponent</b>.
    <LI>Write code to execute (distributed) transactions on the <b>ServicedComponent</b>.
    </OL>
    <br /><br />
    One major advantage of the automatic distributed transaction programming
    model (Windows 2000 Component Services) is that data stores (the Resource
    Managers) are automatically enlisted in transactions. When the transaction group is to
    be completed, call <b>SetComplete</b> or if it is not to be completed call <b>SetAbort</b>. These distributed transactions can span
    multiple databases. ADO.NET providers (ADO Interop Provider and SQL Server Provider) automatically enlist in
    Component Services transactions that initiated using <b>ComponentServices</b>.
    
    <br /><br />
    Any instance of a .NET Framework class can participate in an automatic
    transaction, as long as you prepare the class to do so. Each resource accessed
    by a class instance or object enlists in the transaction. For example, if an
    object uses ADO.NET to post money on an account in a database, the resource
    manager for the database determines if it should execute in a transaction and,
    if so, it enlists the database in the transaction automatically.
    
    
    <Acme:LangSwitch runat="server" ID=LangSwitch1>
      <CsTemplate>
    <Acme:SourceRef
    RunSample=""
    ViewSource="~/howto/samples/adoplus/DistribTransaction/DistribTransaction.src"
    Icon="../../../images/genicon.gif"
    Caption="C# DistribTransaction.exe"
    SamplePath="howto\samples\adoplus\DistribTransaction\"
    CanBeHosted="false"
    runat="server" ID=SourceRef1/>
      </CsTemplate>
      <VbTemplate>
    <Acme:SourceRef
    ViewSource="~/howto/samples/adoplus/DistribTransaction/DistribTransaction.src"
    RunSample=""
    Icon="../../../images/genicon.gif"
    Caption="VB DistribTransaction.exe"
    SamplePath="howto\samples\adoplus\DistribTransaction\"
    CanBeHosted="false"
    runat="server" ID=SourceRef2/>
      </VbTemplate>
      <CpTemplate>
    <Acme:SourceRef
    ViewSource="~/howto/samples/adoplus/DistribTransaction/DistribTransaction.src"
    RunSample=""
    Icon="../../../images/genicon.gif"
    Caption="C++ DistribTransaction.exe"
    SamplePath="howto\samples\adoplus\DistribTransaction\"
    CanBeHosted="false"
    runat="server" ID=SourceRef2/>
      </CpTemplate>
 <VjsTemplate>
       <Acme:SourceRef
        RunSample=""
        ViewSource=""
        Icon = ""
        Caption=""
        CanBeHosted="false"
        runat="server" />
  </VjsTemplate>
    </Acme:LangSwitch>
    
    <br /><br />
    First, make sure you are using <b>System.EnterpriseServices</b>.
    <br /><br />
    <Acme:TabControl runat="server" >
    <Tab Name="C#">
    using System.EnterpriseServices;
    </Tab>
    <Tab Name="VB">
    Imports System.EnterpriseServices
    </Tab>
    <Tab Name="C++">
    using namespace System::EnterpriseServices;
    </Tab>
    </Acme:TabControl>
    <br /><br />
    Next, create a derived class of <b>ServicedComponent</b> for ComServices to provide automatic transaction support.
    <br /><br />
    A serviced component is a .NET Framework component that derives from the
    <B>System.ServicedComponent</FONT></B> class and is automatically serviced
    by Microsoft Windows 2000 Component Services. A serviced component is typically
    hosted in a Microsoft .NET Framework library as an in-process server or as an out-of-process server
    that is called by an unmanaged client. 
    <br /><br />
    To prepare a class for using the transaction model, the class must be
    marked to participate in a transaction. Once the class is marked with a
    <b>Transaction</b> attribute it will automatically execute
    within the scope of a transaction. You can control an object's transactional
    behavior by setting a transaction attribute value on the page, webmethod, or
    class. The attribute value, in turn, determines the transactional behavior of
    the object that is created. 
    <br /><br />
    In the case of class <b>myServicedComponent</b> 'TransactionOption.Required' indicates that the object
    requires a transaction. It runs in the scope of an
    existing transaction, if one exists. If not, it will start one.
    
    <Acme:TabControl runat="server">
    <Tab Name="C#">
    [TransactionAttribute(TransactionOption.Required)]
    public class myServicedComponent:ServicedComponent
    {
      ...
    }
    </Tab>
    <Tab Name="VB">
    public class TransactionAttribute<</>(TransactionOption.Required)> myServicedComponent : Inherits ServicedComponent
      ...
    end class
     </Tab>
    <Tab Name="C++">
    [TransactionAttribute(TransactionOption::Required)]
    public __gc class myServicedComponent : public ServicedComponent
    {
      ...
    }
    </Tab>
    </Acme:TabControl>
    <br /><br />
    The next step is to add some features to the derived class of the <b>ServicedComponent</b>.
    <br /><br />
    You can use <B>System.EnterpriseServices.ContextUtil</B>, which exposes the
    <B>SetComplete</B> or <B>SetAbort</B> members, to explicitly commit or abort a
    transaction. <B>SetComplete</B> indicates that your object votes to commit its
    work; <B>SetAbort</B> indicates that your object encountered a problem and votes
    to abort the ongoing transaction. A transaction is neither committed nor aborted
    until it reaches the end of the page. Further, a single abort vote from any
    object participating in the transaction causes the entire transaction to fail.
    
    <Acme:TabControl runat="server" ID=TabControl3>
    <Tab Name="C#">
    ...
    private SqlConnection m_rConnection;
    
    public myServicedComponent()
    {
    }
    
    public SqlConnection SqlConn
    {
      get { return m_rConnection; }
    }
    
    public ConnectionState State
    {
      get { return m_rConnection.State; }
    }
    
    public void myServicedComponentConnect(string ConnectionString)
    {
      m_rConnection = new SqlConnection(ConnectionString);
      m_rConnection.Open();
    }
    
    public void myServicedComponentClose()
    {
      if (m_rConnection != null)
          m_rConnection.Close();
    }
    
    public void myServicedComponentDispose()
    {
        if (m_rConnection != null)
            m_rConnection.Dispose();
    }
    
    public SqlCommand myServicedComponentCreateCommand()
    {
      return new SqlCommand(null, m_rConnection);
    }
    
    public void myServicedComponentSetComplete()  // to commit changes
    {
      Console.WriteLine("Committing connection's transaction.");
      ContextUtil.SetComplete();
      Console.WriteLine("SetComplete");
    }
    
    public void myServicedComponentSetAbort()     // to rollback the distributed transaction
    {
      Console.WriteLine("Aborting connection's transaction.");
      ContextUtil.SetAbort();
      Console.WriteLine("SetAbort");
    }
    ...
    </Tab>
    <Tab Name="VB">
    ...
    private m_rConnection as SqlConnection
    
    public sub myServicedComponent()
    end sub
    
    public function SqlConn as SqlConnection
      return m_rConnection
    end function
    
    public function State as ConnectionState
      return m_rConnection.State
    end function
    
    public sub myServicedComponentConnect(ConnectionString as string)
      m_rConnection = new SqlConnection(ConnectionString)
      m_rConnection.Open()
    end sub
    
    public sub myServicedComponentClose()
      if not (m_rConnection is nothing) then m_rConnection.Close()
    end sub
    
    public sub myServicedComponentDispose()
      m_rConnection.Dispose()
    end sub
    
    public function myServicedComponentCreateCommand() as SqlCommand
      return new SqlCommand(Nothing, m_rConnection)
    end function
    
    public sub myServicedComponentSetComplete()  ' to commit changes
      Console.WriteLine("Committing connection's transaction.")
      ContextUtil.SetComplete()
      Console.WriteLine("SetComplete")
    end sub
    
    public sub myServicedComponentSetAbort()     ' to rollback the distributed transaction
      Console.WriteLine("Aborting connection's transaction.")
      ContextUtil.SetAbort()
      Console.WriteLine("SetAbort")
    end sub
    ...
    </Tab>
    <Tab Name="C++">
    ...
	private:
	SqlConnection * m_rConnection;
	
	public:
	myServicedComponent()
	{
	}
	
	__property SqlConnection * get_SqlConn() { return m_rConnection; }
	
	
	__property ConnectionState * get_State()  { return __box (m_rConnection->State); }
	
	
	void myServicedComponentConnect(String * ConnectionString)
	{
	m_rConnection = new SqlConnection(ConnectionString);
	m_rConnection->Open();
	}
	
	void myServicedComponentClose()
	{
	  if (m_rConnection != 0)
	m_rConnection->Close();
	}
	
	void myServicedComponentDispose()
	{
	if (m_rConnection != 0)
	  m_rConnection->Dispose();
	}
	
	void myServicedComponentChangeDatabase(String * DBName)
	{
	if (m_rConnection != 0)
	  m_rConnection->ChangeDatabase(DBName);
	}
	
	SqlCommand * myServicedComponentCreateCommand()
	{
	return new SqlCommand(0, m_rConnection);
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
    ...
    </Tab>
    </Acme:TabControl>
    <br /><br />

    Finally, you will write code to execute (distributed) transactions on the <b>ServicedComponent</b>. In this code, you create
    an instance of the new derived class of the <b>ServicedComponent</b> and use it to connect to the database provider. Then several
    SQL commands are executed as distributed transactions using the <b>myServicedComponent</b>. The transactions are then
    finalized using the <b>SetComplete</b> method of the Microsoft .NET Framework Component Services.

    
    <Acme:TabControl runat="server" ID=TabControl2>
    <Tab Name="C#">
    SqlCommand mySqlCommand;
    myServicedComponent mySC = new myServicedComponent();
    

    mySC.myServicedComponentConnect("server=(local)\\SQLExpress;Integrated Security=SSPI;database=northwind");
    Console.WriteLine("connection state is: " + mySC.State);
    mySqlCommand = new SqlCommand(null, mySC.SqlConn);
    
    try
    {
      // Clean up the database to restore to its original state.
      mySqlCommand.CommandText = "if exists (select * from sysobjects where name = 'TestTable' and type = 'U') drop table TestTable";
      mySqlCommand.ExecuteNonQuery();
    
      // Create table "TestTable".
      Console.WriteLine("Creating table TestTable.");
      mySqlCommand.CommandText = "create table TestTable (c1 int identity, c2 int)";
      mySqlCommand.ExecuteNonQuery();
    
      // Create unique index ss on TestTable.
      Console.WriteLine("Creating unique index ss on TestTable.");
      mySqlCommand.CommandText = "create unique index ss on TestTable(c1)";
      mySqlCommand.ExecuteNonQuery();
    
      // Insert into TestTable values.
      Console.WriteLine("Inserting into TestTable values.");
      mySqlCommand.CommandText = "insert into TestTable values (11)";
      mySqlCommand.ExecuteNonQuery();
    
      // Commit the transaction.
      mySC.myServicedComponentSetComplete();
    }
    catch (Exception e)
    {
      Console.Write(e.ToString());
    
      // Rollback the transaction.
      mySC.myServicedComponentSetAbort();
    }
    finally
    {
      mySC.myServicedComponentClose();
      Console.WriteLine("connection state is: " + mySC.State);
    }
    </Tab>
    <Tab Name="VB">
    Dim mySqlCommand as SqlCommand
    Dim mySC as myServicedComponent = new myServicedComponent()
    

    mySC.myServicedComponentConnect("server=(local)\\SQLExpress;Integrated Security=SSPI;database=northwind")
    Console.WriteLine("connection state is: " & mySC.State)
    mySqlCommand = new SqlCommand(Nothing, mySC.SqlConn)
    
    try
      ' Clean up the database to restore to its original state.
      mySqlCommand.CommandText = "if exists (select * from sysobjects where name = 'TestTable' and type = 'U') drop table TestTable"
      mySqlCommand.ExecuteNonQuery()
    
      ' Create table "TestTable".
      Console.WriteLine("Creating table TestTable.")
      mySqlCommand.CommandText = "create table TestTable (c1 int identity, c2 int)"
      mySqlCommand.ExecuteNonQuery()
    
      ' Create unique index ss on TestTable.
      Console.WriteLine("Creating unique index ss on TestTable.")
      mySqlCommand.CommandText = "create unique index ss on TestTable(c1)"
      mySqlCommand.ExecuteNonQuery()
    
      ' Insert into TestTable values.
      Console.WriteLine("Inserting into TestTable values.")
      mySqlCommand.CommandText = "insert into TestTable values (11)"
      mySqlCommand.ExecuteNonQuery()
    
      ' Commit the transaction.
      mySC.myServicedComponentSetComplete()
    catch e as Exception
      Console.Write(e.ToString())
    
      ' Rollback the transaction.
      mySC.myServicedComponentSetAbort()
    finally
      mySC.myServicedComponentClose()
      Console.WriteLine("connection state is: " & mySC.State)
    end try
     </Tab>
    <Tab Name="C++">
    SqlCommand * mySqlCommand;
    myServicedComponent * mySC = new myServicedComponent();

    mySC->myServicedComponentConnect(S"server=(local)\\SQLExpress;Trusted_Connection=yes;database=northwind;provider=SQLNCLI");
    Console::Write("connection state is: ");
    Console::WriteLine(mySC->State);

    mySqlCommand = new SqlCommand(0, mySC->SqlConn);

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
    catch (Exception * e)
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
    </Tab>
    </Acme:TabControl>
    
    
    <br /><br />
    A related issue is key creation and strong naming of keys. We can use Strong Name tool "sn.exe" to create a key 
    file. For example, the following command creates a new, random key pair and stores it in keyPair.snk.
    <br /><br />
    <div class="code">sn -k keyPair.snk</div>
    <br /><br />
    Here is how to use the key pair in the registration of the assembly.
    <br /><br />
    
    <Acme:TabControl runat="server">
    <Tab Name="C#">
    [assembly:System.Reflection.AssemblyKeyFile("keyPair.snk")]
    </Tab>
    <Tab Name="VB">
    <</>assembly:System.Reflection.AssemblyKeyFile("keyPair.snk")>
    </Tab>
    <Tab Name="C++">
    [assembly: AssemblyKeyFileAttribute("keyfile.snk")];
    </Tab>
    </Acme:TabControl>
    
    <br /><br />
    
</asp:Content>
