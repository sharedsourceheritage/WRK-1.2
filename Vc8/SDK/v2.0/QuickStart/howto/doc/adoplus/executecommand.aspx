<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2>ADO.NET: Execute a Command</h2>

<br /><br />Commands are issued against databases to take actions against data stores.
For example, you could execute a command that inserts or deletes data. For more information on moving data into and out
of databases, see <a href="updatedatafromdb.aspx">"Update a Database
from a DataSet"</a>. Commands include any command that can be issued
against a database, and in the case of the <b>OleDbCommand</b>, can be data store
specific. For example, you could issue a stored procedure call for a command,
or perhaps a command to "set quoted_identifier on". Whatever the command
may be, the <b>OleDbCommand</b> or <b>SqlCommand</b> can be used to get the command to your
back-end data store.

<br /><br />
With ADO classic, you could issue commands through the
<b>Command</b> object, <b>Connection</b> object, or <b>Recordset</b> object. In ADO.NET, only the
<b>Command</b> object executes commands.

<br /><br />
To issue a command against a database, the <b>Command</b> object must have
two basic things: a <b>Connection</b> and <b>CommandText</b>, both of which can be set in
the constructor. To execute the command, the <b>Connection</b>
has to be open and not in fetching state:

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
String InsertCmdString;
InsertCmdString = "Insert into Region (RegionID, RegionDescription) VALUES (100, 'Description')";
SqlCommand mySqlCommand = new SqlCommand(InsertCmdString, myConnection);
</Tab>
<Tab Name="VB">
Dim InsertCmdString As String
InsertCmdString = "Insert into Region (RegionID, RegionDescription) VALUES (100, 'Description')"
Dim mySqlCommand As SqlCommand = New SqlCommand(InsertCmdString, myConnection)
</Tab>
<Tab Name="C++">
SqlCommand * myCommand;
myCommand->CommandText = "Insert into Region (RegionID, RegionDescription) VALUES (100, 'Description')";
</Tab>
</Acme:TabControl>


<br /><br />
This topic covers executing non-result generating commands. 
To execute the command that does not return results, call the <b>ExecuteNonQuery</b> method.

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
mySqlCommand.ExecuteNonQuery();
</Tab>
<Tab Name="VB">
mySqlCommand.ExecuteNonQuery()
</Tab>
<Tab Name="C++">
mySqlCommand->ExecuteNonQuery();
</Tab>
</Acme:TabControl>


<br /><br />
The <b>OleDbCommand</b> and <b>SqlCommand</b> objects have parameter collections that behave
like the parameter collections from ADO classic. You can pass your
parameters inline:

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
mySqlCommand.CommandText = "myStoredProc 'CustId'";
</Tab>
<Tab Name="VB">
mySqlCommand.CommandText = "myStoredProc 'CustId'"
</Tab>
<Tab Name="C++">
mySqlCommand->CommandText = "myStoredProc 'CustId'";
</Tab>
</Acme:TabControl>


<br /><br />
Or by using the <b>Parameters</b> collection:


<br /><br />
<Acme:TabControl runat="server">
<Tab Name="C#">
workParam = mySqlCommand.Parameters.Add("@CustomerID", SQLDataType.NChar, 5);
workParam.Value = "NewID";
</Tab>
<Tab Name="VB">
workParam = mySqlCommand.Parameters.Add("@CustomerID", SQLDataType.NChar, 5)
workParam.Value = "NewID"
</Tab>
<Tab Name="C++">
workParam = mySqlCommand->Parameters->Add("@CustomerID", SQLDataType.NChar, 5);
workParam.Value = "NewID";
</Tab>
</Acme:TabControl>


<br /><br />
For more information about using parameters, see
<a href="outparams.aspx">Getting Out Parameters from a Stored Procedure</a>.

<br /><br />
The following sample shows how to execute an insert command against a SQL
database using the <b>SqlCommand</b>.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
<Acme:SourceRef
  RunSample="../../samples/adoplus/executingacommand/cs/executingacommand/executingacommand.aspx"
  ViewSource="~/howto/samples/adoplus/executingacommand/executingacommand.src"
  Icon="../../../images/genicon.gif"
  Caption="C# executingacommand.aspx"
  SamplePath="howto\samples\adoplus\executingacommand\"
  CanBeHosted="false"
  runat="server" />
  </CsTemplate>
  <VbTemplate>
<Acme:SourceRef
  RunSample="../../samples/adoplus/executingacommand/vb/executingacommand/executingacommand.aspx"
  ViewSource="~/howto/samples/adoplus/executingacommand/executingacommand.src"
  Icon="../../../images/genicon.gif"
  Caption="VB executingacommand.aspx"
  SamplePath="howto\samples\adoplus\executingacommand\"
  CanBeHosted="false"
  runat="server" />
  </VbTemplate>
  <CpTemplate>
<Acme:SourceRef
  RunSample=""
  ViewSource="~/howto/samples/adoplus/executingacommand/executingacommand.src"
  Icon="../../../images/genicon.gif"
  SamplePath="howto\samples\adoplus\executingacommand\"
  CanBeHosted="false"
  Caption="C++ executingacommand.exe"
  runat="server" />
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


</asp:Content>