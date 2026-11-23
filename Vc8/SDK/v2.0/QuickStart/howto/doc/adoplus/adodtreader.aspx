<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4>ADO.NET: Retrieve Data using OLE DB</h4>

<p>This sample illustrates how to read data from an OLE DB provider using the <B>OleDbDataReader</B> class.
This class provides a way of reading a forward-only stream of data records from a data 
source. If you want to work with SQLServer 7.0 or higher, you should refer to the topic
<a href="sqldtreader.aspx">Retrieve Data from SQLServer</a>.</p>

<p>The <B>OleDbDataReader</B> is created by calling the ExecuteReader method
of the OleDbCommand, not
through direct use of the constructor.
While the <B>OleDbDataReader</B> is in use, the associated <B>OleDbConnection</B> is
busy serving the <B>OleDbDataReader</B>. While in this state, no other
operations can be performed on the <B>OleDbConnection</B> other than closing it.
This is the case until the Close method
of the <B>OleDbDataReader</B> is called.<p>

<Acme:LangSwitch runat="server">
  <CsTemplate>
    <Acme:SourceRef
	RunSample="../../samples/adoplus/adodtreader/CS/AdoDtReader/adodtreader.aspx"
	ViewSource="~/howto/samples/adoplus/adodtreader/adodtreader.src"
	Icon="../../../images/genicon.gif"
	Caption="C# adodtreader.aspx"
	SamplePath="howto\samples\adoplus\adodtreader\"
	runat="server" />
  </CsTemplate>
  <VbTemplate>
     <Acme:SourceRef
	ViewSource="~/howto/samples/adoplus/adodtreader/adodtreader.src"
	RunSample="../../samples/adoplus/adodtreader/VB/AdoDtReader/adodtreader.aspx"
	Icon="../../../images/genicon.gif"
	Caption="VB adodtreader.aspx"
	SamplePath="howto\samples\adoplus\adodtreader\"
	runat="server" />
  </VbTemplate>
  <CpTemplate>
     <Acme:SourceRef
	ViewSource="~/howto/samples/adoplus/adodtreader/adodtreader.src"
	RunSample=""
	Icon="../../../images/genicon.gif"
	Caption="C++ adodtreader.exe"
	SamplePath="howto\samples\adoplus\adodtreader\"
	runat="server" />
  </CpTemplate>
 <VjsTemplate>
       <Acme:SourceRef
        RunSample=""
        ViewSource=""
        Icon = ""
        Caption=""
        runat="server" />
  </VjsTemplate>
</Acme:LangSwitch>

<p>
<B>OleDbDataReader</B> provides a means of reading a forward-only stream of data records from an OleDb data source.
For more interactive operations, such as scrolling, filtering, navigating, remoting, etc., use the DataSet.
<p>
The example creates an OleDbConnection to the Northwind database using the OLE DB .NET Data Provider. The
OleDbCommand selecting items from the employee table is then executed using the OleDbCommand ExecuteReader method.
The results of this command are passed to the <B>OleDbDataReader</B>.
<Acme:TabControl runat="server" >
<Tab Name="C#">

OleDbDataReader myDataReader = null;
OleDbConnection myOleDbConnection = new OleDbConnection("server=(local)\SQLExpress;Integrated Security=SSPI;
    database=northwind;provider=SQLNCLI");
OleDbCommand myOleDbCommand = new OleDbCommand("SELECT EmployeeID, LastName,
    FirstName, Title, ReportsTo FROM Employees", myOleDbConnection);
...
myOleDbConnection.Open();
myDataReader = myOleDbCommand.ExecuteReader();
</Tab>
<Tab Name="VB">

Dim myDataReader as OleDbDataReader
Dim myOleDbConnection as OleDbConnection
Dim myOleDbCommand as OleDbCommand

myOleDbConnection = new OleDbConnection("server=(local)\SQLExpress;Integrated Security=SSPI;
    database=northwind;provider=SQLNCLI")
myOleDbCommand = new OleDbCommand("SELECT EmployeeID, LastName,
    FirstName, Title, ReportsTo FROM Employees", myOleDbConnection)
...
myOleDbConnection.Open()
myDataReader = myOleDbCommand.ExecuteReader()
</Tab>
<Tab Name="C++">

OleDbDataReader * myDataReader;
OleDbConnection * myOleDbConnection = new OleDbConnection(S"server=(local)\\SQLExpress;Trusted_Connection=yes;database=northwind;provider=SQLNCLI");
    OleDbCommand * myOleDbCommand = new OleDbCommand("SELECT EmployeeID, LastName, FirstName, Title, ReportsTo FROM Employees", myOleDbConnection);
...
myOleDbConnection->Open();
myDataReader = myOleDbCommand->ExecuteReader();
</Tab>
</Acme:TabControl>

The example reads through the data using the <B>OleDbDataReader</B> Read method and
writing the data elements out to the console.
<Acme:TabControl runat="server" >
<Tab Name="C#">
while (myDataReader.Read())
{
    ...
    if (myDataReader.IsDBNull(4))
      Console.Write("N/A\n");
    else
      Console.Write(myDataReader.GetInt32(4) + "\n");
}
</Tab>
<Tab Name="VB">
do while (myDataReader.Read())
    ...
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
	...
	if (myDataReader->IsDBNull(4))
	  Console::Write("N/A\n");
	else
	  Console::Write(String::Concat(myDataReader->GetInt32(4).ToString(),"\n"));
}
</Tab>
</Acme:TabControl>

<p>
Finally, the example closes the <B>OleDbDataReader</B>, then
the <B>OleDbConnection</B>.
</p>
<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
// Always call Close when done reading.
myDataReader.Close();

// Close the connection when done with it.
myOleDbConnection.Close();
</Tab>
<Tab Name="VB">
' Always call Close when done reading.
myDataReader.Close()

' Close the connection when done with it.
myOleDbConnection.Close()
</Tab>
<Tab Name="C++">
// Always call Close when done reading.
myDataReader->Close();

// Close the connection when done with it.
myOleDbConnection->Close();
</Tab>
</Acme:TabControl>
<p>


<p>

<H4>Summary</H4>
<OL>
<LI>An <B>OleDbDataReader</B> is for reading a forward-only stream of data records from a data
source fast.
<LI>Remember to close the <B>OleDbDataReader</B> and then the <B>OleDbConnection</B>.
<LI>Remember if the <B>OleDbDataReader</B> is in use, the associated <B>OleDbConnection</B> is
busy serving the <B>OleDbDataReader</B> and while in this state, no other
operations can be performed on the <B>OleDbConnection</B> other than closing it.

</LI>
</OL>
<p>

</asp:Content>
