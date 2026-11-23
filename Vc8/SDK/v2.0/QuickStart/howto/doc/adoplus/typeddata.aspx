<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2>ADO.NET: Work with Typed Data</h2>

<br /><br />ADO classic code provides late-bound access to values within its
recordset through weakly typed variables. ADO.NET code enables you to access the data held in the DataSet through a "strongly typed"
metaphor. This means you can access tables and columns that are part of
the DataSet with user-friendly names and strongly typed variables.
Therefore, rather than writing the ADO classic code shown below:
<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
AdoRecordset.Find("CustomerID = 'ALFKI'");
AdoRecordSet.Fields["FirstName"].Value  = "Bob";
</Tab>
<Tab Name="VB">
AdoRecordset.Find("CustomerID = 'ALFKI'")
AdoRecordSet.Fields("FirstName").Value  = "Bob"
</Tab>
<Tab Name="C++">
AdoRecordset->Find("CustomerID = 'ALFKI'");
AdoRecordSet->Fields->Item["FirstName"]->Value  = "Bob";
</Tab>
</Acme:TabControl>

<br /><br />
with a strongly typed DataSet, you write the following ADO.NET code:
<br /><br />


<Acme:TabControl runat="server">
<Tab Name="C#">
CustomerDataSet.Customers["ALFKI"].CustomerName = "Bob";
</Tab>
<Tab Name="VB">
CustomerDataSet.Customers("ALFKI").CustomerName = "Bob"
</Tab>
<Tab Name="C++">
CustomerDataSet->Customers->Item["ALFKI"]->CustomerName = "Bob";
</Tab>
</Acme:TabControl>


<br /><br />Additionally, the strongly typed DataSet provides access to row values
as the correct, strongly typed value. With ADO, variant types are used
when assigning and retrieving data. If the value that you assigned was of
the wrong type, ADO would give you a run-time error. With ADO.NET, if the
value is of type integer and you attempt to assign a string, you will get
a compile-time error.

<br /><br />Given an XML schema that complies with the XSD standard, you can
generate a strongly typed DataSet using the XSD.exe tool provided with the .NET Framework
SDK. The syntax for generating a DataSet using this tool is:

<div class="code"><pre>
xsd.exe /d /l:CS {XSDSchemaFileName.xsd}
</pre></div>

<br /><br /> The /d directive directs the tool to generate a DataSet; the /l: directive
specifies the language to use -- either "C#" or "VB."

<br /><br />The following example uses a strongly typed DataSet called "myCustDS" to
load a list of customers from the Northwind database. Once the data is loaded
using the <b>Fill</b> method, the code loops through each customer in the
"Customers" table using the typed <b>myDataRow</b> object. Note the direct access to 
the "CustomerID" field, as opposed to accessing it through the <b>Fields</b> collection.

<br /><br />Before running the following sample, you must run "nmake /a" in the "..\typeddata\DllSrc" 
directory from a console window to create the TypedData.dll file.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
    <Acme:SourceRef
  RunSample=""
  ViewSource="~/howto/samples/adoplus/TypedData/TypedData.src"
  Icon="../../../images/genicon.gif"
  Caption="C# TypedData.aspx"
  SamplePath="howto\samples\adoplus\TypedData\"
  CanBeHosted="false"
  runat="server" />
  </CsTemplate>
  <VbTemplate>
    <Acme:SourceRef
  RunSample=""
  ViewSource="~/howto/samples/adoplus/TypedData/TypedData.src"
  Icon="../../../images/genicon.gif"
  SamplePath="howto\samples\adoplus\TypedData\"
  CanBeHosted="false"
  Caption="VB TypedData.aspx"
  runat="server" />
  </VbTemplate>
  <CpTemplate>
    <Acme:SourceRef
  RunSample=""
  ViewSource="~/howto/samples/adoplus/TypedData/TypedData.src"
  Icon="../../../images/genicon.gif"
  SamplePath="howto\samples\adoplus\TypedData\"
  CanBeHosted="false"
  Caption="C++ TypedData.exe"
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