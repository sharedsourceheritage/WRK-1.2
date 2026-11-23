<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>
    
    <h2>ADO.NET: Retrieve Data from SQL Server</h2>
    
    <br /><br />This sample illustrates how to read data from SQL Server using the <B>SqlDataReader</B> class.
    This class provides a way of reading a forward-only stream of data records from a data 
    source. If you want to work with databases that have OLE DB interfaces or
    versions of SQL Server prior to SQL Server 7.0, see
    <a href="adodtreader.aspx">Retrieve Data Using OLE DB</a>.
    
    <br /><br />The <B>SqlDataReader</B> is created by calling the <b>ExecuteReader</b> method
    of the <b>SqlCommand</b>, not
    through direct use of the constructor.
    While the <B>SqlDataReader</B> is in use, the associated <B>SqlConnection</B> is
    busy serving the <B>SqlDataReader</B>. While in this state, no other
    operations can be performed on the <B>SqlConnection</B> other than closing it.
    This is the case until the <b>Close</b> method
    of the <B>SqlDataReader</B> is called.<br /><br />
    
    <Acme:LangSwitch runat="server" ID=LangSwitch1>
      <CsTemplate>
    <Acme:SourceRef
    RunSample="../../samples/adoplus/sqldtreader/CS/sqldtreader/sqldtreader.aspx"
    ViewSource="~/howto/samples/adoplus/sqldtreader/sqldtreader.src"
    Icon="../../../images/genicon.gif"
    Caption="C# sqldtreader.aspx"
    Samplepath="howto\samples\adoplus\sqldtreader\"
    CanBeHosted="false"
    runat="server" ID=SourceRef1/>
      </CsTemplate>
      <VbTemplate>
    <Acme:SourceRef
    ViewSource="~/howto/samples/adoplus/sqldtreader/sqldtreader.src"
    RunSample="../../samples/adoplus/sqldtreader/VB/sqldtreader/sqldtreader.aspx"
    Icon="../../../images/genicon.gif"
    Caption="VB sqldtreader.aspx"
    Samplepath="howto\samples\adoplus\sqldtreader\"
    CanBeHosted="false"
    runat="server" ID=SourceRef2/>
      </VbTemplate>
      <CpTemplate>
    <Acme:SourceRef
    ViewSource="~/howto/samples/adoplus/sqldtreader/sqldtreader.src"
    RunSample=""
    Icon="../../../images/genicon.gif"
    Caption="C++ sqldtreader.exe"
    Samplepath="howto\samples\adoplus\sqldtreader\"
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
    <B>SqlDataReader</B> provides a means of reading a forward-only stream of data records from a SQL Server data source.
    For more interactive operations such as scrolling, filtering, navigating, and remoting, use the DataSet.
    <br /><br />
    The example creates a SqlConnection to the Northwind database. The 
    <b>SqlCommand</b> selecting items from the employee table is then executed using the <b>SqlCommand ExecuteReader</b> method.
    The results of this command are passed to the <B>SqlDataReader</B>.
    <Acme:TabControl runat="server" >
    <Tab Name="C#">
    SqlDataReader myDataReader = null;

    SqlConnection mySqlConnection = new SqlConnection("server=(local)\SQLExpress;Integrated Security=SSPI;database=northwind");
    SqlCommand mySqlCommand = new SqlCommand("SELECT EmployeeID, LastName, FirstName, Title, ReportsTo FROM Employees", mySqlConnection);
    ...
    mySqlConnection.Open();
    myDataReader = mySqlCommand.ExecuteReader(CommandBehavior.CloseConnection);
    </Tab>
    <Tab Name="VB">
    Dim myDataReader as SqlDataReader
    Dim mySqlConnection as SqlConnection
    Dim mySqlCommand as SqlCommand
    

    mySqlConnection = new SqlConnection("server=(local)\SQLExpress;Integrated Security=SSPI;database=northwind")
    mySqlCommand = new SqlCommand("SELECT EmployeeID, LastName, FirstName, Title, ReportsTo FROM Employees", mySqlConnection)
    ...
    mySqlConnection.Open()
    myDataReader = mySqlCommand.ExecuteReader(CommandBehavior.CloseConnection)
    </Tab>
    <Tab Name="C++">
    SqlDataReader * myDataReader = 0;

    SqlConnection * mySqlConnection = new SqlConnection(S"server=(local)\\SQLExpress;Trusted_Connection=yes;database=northwind;provider=SQLNCLI");
    SqlCommand * mySqlCommand = new SqlCommand("SELECT EmployeeID, LastName, FirstName, Title, ReportsTo FROM Employees", mySqlConnection);
    ...
    mySqlConnection->Open();
    myDataReader = mySqlCommand->ExecuteReader();
    </Tab>
    </Acme:TabControl>
    
    The example reads through the data using the <B>SqlDataReader Read</b> method and
    writing the data elements out to the console.
    <Acme:TabControl runat="server" >
    <Tab Name="C#">
    while (myDataReader.Read())
    {
      Console.Write(myDataReader.GetInt32(0) + "\t");
      Console.Write(myDataReader.GetString(2) + " " + myDataReader.GetString(1) + "\t");
      Console.Write(myDataReader.GetString(3) + "\t");
      if (myDataReader.IsDBNull(4))
        Console.Write("N/A\n");
      else
        Console.Write(myDataReader.GetInt32(4) + "\n");
    }
    </Tab>
    <Tab Name="VB">
    do while (myDataReader.Read())
      Console.Write(myDataReader.GetInt32(0).ToString() + Chr(9))
      Console.Write(myDataReader.GetString(2) + " " + myDataReader.GetString(1) + Chr(9))
      Console.Write(myDataReader.GetString(3) + Chr(9))
      if (myDataReader.IsDBNull(4)) then
        Console.Write("N/A" + Chr(10))
      else
        Console.Write(myDataReader.GetInt32(4).ToString() + Chr(10))
      end if
    loop
     </Tab>
    <Tab Name="C++">
      while (myDataReader->Read())
      {
        Console::Write(myDataReader->GetInt32(0));
		Console::Write("\t\t");
        Console::Write(myDataReader->GetString(2));
		Console::Write(" ");
		Console::Write(myDataReader->GetString(1));
		Console::Write("\t");
        Console::Write(myDataReader->GetString(3));
		Console::Write("\t");
        if (myDataReader->IsDBNull(4))
          Console::Write("N/A\n");
        else
          Console::WriteLine(myDataReader->GetInt32(4));
      }
    </Tab>
    </Acme:TabControl>
    
    <br /><br />
    Finally, the example closes the <B>SqlDataReader</B>, then
    the <B>SqlConnection</B>.
    
    <br /><br />
    <Acme:TabControl runat="server" >
    <Tab Name="C#">
    // Always call Close when done reading.
    myDataReader.Close();
    
    // Close the connection when done with it.
    mySqlConnection.Close();
    </Tab>
    <Tab Name="VB">
    ' Always call Close when done reading.
    myDataReader.Close()
    
    ' Close the connection when done with it.
    mySqlConnection.Close()
    </Tab>
    <Tab Name="C++">
    // Always call Close when done reading.
    myDataReader->Close();
    
    // Close the connection when done with it.
    mySqlConnection->Close();
    </Tab>
    </Acme:TabControl>
    <br /><br />
    
    
    <br /><br />
    
    <h2>Summary</h2>
    <OL>
    <LI>A <B>SqlDataReader</B> is for reading a forward-only stream of data records from SQL Server.
    <LI>Remember to close the <B>SqlDataReader</B> and then the <B>SqlConnection</B>.
    <LI>There can be only one <B>SqlDataReader</B> open at a time on the <B>SqlConnection</B>.  If the <B>SqlDataReader</B> is in use, the associated <B>SqlConnection</B> is
    busy serving the <B>SqlDataReader</B> and while in this state, no other
    operations can be performed on the <B>SqlConnection</B> other than closing it.
    
    </LI>
    </OL>
    <br /><br />
</asp:Content>