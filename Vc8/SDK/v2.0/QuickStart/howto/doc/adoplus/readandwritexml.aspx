<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>
    
    <h2>ADO.NET: Read and Write XML</h2>
    
    <br /><br />ADO.NET and DataSet can read and write XML schema and XML. For more information,
    see <A target=content href="../XML/XMLDataSet.aspx">
    How do I...Use XML and the DataSet?</A>
    
    <br /><br />Schemas, or the tables, columns, constraints and so forth, of a DataSet
    can be defined in several ways. One method is to create them using properties
    and methods (<b>Tables.Add</b>, <b>Columns.Add</b>, and so on). This establishes
    a schema within your DataSet that can be used as a container to hold data.
    Another way is to use the SqlDataAdapter or OleDbDataAdapter. When you use
    these commands, if the schema does not exist in a DataSet, it is created for
    you.
    
    <br /><br />XML is an intrinsic element of ADO.NET. Several methods that support XML have
    been implemented. The <b>GetXmlSchema</b> method allows you to get the schema of a DataSet as an XSD schema.
    For example, if you load a DataSet from the database,
    you could get an XSD schema from it:
    
    <Acme:TabControl runat="server">
    <Tab Name="C#">
    Console.WriteLine(myDataSet.GetXmlSchema());
    </Tab>
    <Tab Name="VB">
    Console.WriteLine(myDataSet.GetXmlSchema())
    </Tab>
    <Tab Name="C++">
    Console::WriteLine(myDataSet->GetXmlSchema(););
    </Tab>
    </Acme:TabControl>
    
    <br /><br />This returns an XSD compliant XML schema for the schema in your DataSet.
    
    <br /><br />XML representation is also retrieved through the <b>GetXml</b> method.
    
    <Acme:TabControl runat="server">
    <Tab Name="C#">
    Console.WriteLine(myDataSet.GetXml());
    </Tab>
    <Tab Name="VB">
    Console.WriteLine(myDataSet.GetXml())
    </Tab>
    <Tab Name="C++">
    Console::WriteLine(myDataSet->GetXml());
    </Tab>
    </Acme:TabControl>
    
    <br /><br />The sample below loads data from a database, and then outputs the XSD Schema
    and XML data.
    
    <br /><br />
    
    <Acme:LangSwitch runat="server">
      <CsTemplate>
    <Acme:SourceRef
      RunSample="../../samples/adoplus/ReadAndWriteXML/cs/ReadAndWriteXML/ReadAndWriteXML.aspx"
      ViewSource="~/howto/samples/adoplus/ReadAndWriteXML/ReadAndWriteXML.src"
      Icon="../../../images/genicon.gif"
      Caption="C# ReadAndWriteXML.aspx"
      SamplePath="howto\samples\adoplus\ReadAndWriteXML\"
      CanBeHosted="false"
      runat="server" />
      </CsTemplate>
      <VbTemplate>
    <Acme:SourceRef
      RunSample="../../samples/adoplus/ReadAndWriteXML/vb/ReadAndWriteXML/ReadAndWriteXML.aspx"
      ViewSource="~/howto/samples/adoplus/ReadAndWriteXML/ReadAndWriteXML.src"
      Icon="../../../images/genicon.gif"
      Caption="VB ReadAndWriteXML.aspx"
      SamplePath="howto\samples\adoplus\ReadAndWriteXML\"
      CanBeHosted="false"
      runat="server" />
      </VbTemplate>
      <CpTemplate>
    <Acme:SourceRef
      RunSample=""
      ViewSource="~/howto/samples/adoplus/ReadAndWriteXML/ReadAndWriteXML.src"
      Icon="../../../images/genicon.gif"
      Caption="C++ ReadAndWriteXML.exe"
      SamplePath="howto\samples\adoplus\ReadAndWriteXML\"
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
