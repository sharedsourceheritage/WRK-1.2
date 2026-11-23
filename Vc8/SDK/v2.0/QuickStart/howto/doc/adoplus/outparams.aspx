 <%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>
    
    <h2>ADO.NET: Get Out Parameters from a Stored Procedure</h2>
    
    <br /><br />Some stored procedures return values through parameters. When a parameter in a SQL statement or stored procedure is declared as "out", the value of the parameter is returned back to the caller; the value is stored in a parameter in the Parameters collection on the <b>OleDbCommand</b> or <b>SqlCommand</b> objects.
    <br /><br />
    Unlike the sample below, if the connection and command name are not set, you can still establish the parameters, but you have to create the collection of parameters and expected types.
    <br /><br />
    
    <Acme:TabControl runat="server">
    <Tab Name="C#">
    workParam = myCommand.Parameters.Add("@CustomerID", SQLDataType.NChar, 5);
    workParam.Value = "CUSTID";
    </Tab>
    <Tab Name="VB">
    workParam = myCommand.Parameters.Add("@CustomerID", SQLDataType.NChar, 5)
    workParam.Value = "CUSTID"
    </Tab>
    <Tab Name="C++">
    workParam = myCommand->Parameters->Add("@CustomerID", SQLDataType.NChar, 5);
    workParam->Value = "CUSTID";
    </Tab>
    </Acme:TabControl>
    <br /><br />
    
    The following sample shows how to use a stored procedure that returns output parameters. The command is executed to create a stored procedure in the Northwind database.
    <br /><br />
    
    <Acme:LangSwitch runat="server">
      <CsTemplate>
    <Acme:SourceRef
      RunSample="../../samples/adoplus/outparamswithacommand/cs/outparamswithacommand/outparamswithacommand.aspx"
      ViewSource="~/howto/samples/adoplus/outparamswithacommand/outparamswithacommand.src"
      Icon="../../../images/genicon.gif"
      Caption="C# OutParamsWithACommand.aspx"
      SamplePath="howto\samples\adoplus\outparamswithacommand\"
      CanBeHosted="false"
      runat="server" />
      </CsTemplate>
      <VbTemplate>
    <Acme:SourceRef
      RunSample="../../samples/adoplus/outparamswithacommand/vb/outparamswithacommand/outparamswithacommand.aspx"
      ViewSource="~/howto/samples/adoplus/outparamswithacommand/outparamswithacommand.src"
      Icon="../../../images/genicon.gif"
      Caption="VB OutParamsWithACommand.aspx"
      SamplePath="howto\samples\adoplus\outparamswithacommand\"
      CanBeHosted="false"
      runat="server" />
      </VbTemplate>
      <CpTemplate>
    <Acme:SourceRef
      RunSample=""
      ViewSource="~/howto/samples/adoplus/outparamswithacommand/outparamswithacommand.src"
      Icon="../../../images/genicon.gif"
      Caption="C++ OutParamsWithACommand.exe"
      SamplePath="howto\samples\adoplus\outparamswithacommand\"
      CanBeHosted="false"
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
    <br /><br />
    
    </asp:Content>
    

