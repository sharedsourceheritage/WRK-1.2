<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4>How do I create an XML Schema Definition (XSD) File From a Class?</h4>

<p>This topic describes how to build an XSD file for classes that you save and load from XML using the XML Serialization classes.  The XML Serialization classes allow you to <a href="RWObjFromXML.aspx">serialize an object as XML </a>. Often you will start with an XML Schema Definition (XSD) file, and <a href="XsdToCls.aspx">use the XSD.exe tool to build the classes you save and load from </a>.  However, if you started by building your classes first, and then decided to save them as XML, you might want to generate an XML Schema Definition (XSD) file that describes the format that the serializer will use for your objects. This file provides the information that consumers of your persisted classes need to know to properly read them. <p>

<ol>
<li>Locate the assembly and class you want to export.  You only need to know the name of the class that corresponds to the root element of the XML document.  This example will use the following <b>PurchaseOrder</b> type:<p>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        ViewSource="~/howto/Samples/XmlSerialization/PurchaseOrder.src"
        Icon="../../../images/genicon.gif"
        Caption="C# PurchaseOrder.exe"
	Samplepath="howto\samples\Xmlserialization\"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        ViewSource="~/howto/Samples/XmlSerialization/PurchaseOrder.src"
        Icon="../../../images/genicon.gif"
        Caption="VB PurchaseOrder.exe"
	Samplepath="howto\samples\Xmlserialization\"
        runat="server" />
  </VbTemplate>
  <CpTemplate>
       <Acme:SourceRef
        ViewSource="~/howto/Samples/XmlSerialization/PurchaseOrder.src"
        Icon="../../../images/genicon.gif"
        Caption="C++ PurchaseOrder.exe"
	Samplepath="howto\samples\Xmlserialization\"
        runat="server" />
  </CpTemplate>
</Acme:LangSwitch>

<p>
In the code, you will notice additional "Custom Metadata Attributes" above the field declarations. These are used to guide the Xml Serializer classes to properly read and write the XML.  They are basically hints to the parser.  For example, the <b>Items</b> field has a custom attribute applied to it to tell the serializer to that the <b>Items</b> field should contain an array of item objects which get created when the XML is loaded. Since they affect what XML is used to save the object, they also affect the schema that is generated:

<p>
<table cellpadding=0 cellspacing=0 width="95%">
<tr>
<td>

<Acme:TabControl runat="server">
<Tab Name="C#">
[System.Xml.Serialization.XmlArrayItemAttribute("item", IsNullable=false)]
public ItemsItem[] items;
</Tab>
<Tab Name="VB">
&lt;System.Xml.Serialization.XmlArrayItemAttribute("item", IsNullable:=false)&gt;  _
Public items() As ItemsItem
</Tab>
</Acme:TabControl>

</td>
</tr>
</table>
<p>

For detailed information on these attributes, see the reference documentation in the SDK.  They are located in the System.Xml.Serialization namespace. <p>

<p>

<li> Use the xsd.exe tool in the SDK to generate an XSD schema from the class and all classes used by that class.  The <b>-t</b> switch tells the program only to generate a schema for one particular type in the test.exe file:

<div class="code"><pre>
xsd.exe -t:PurchaseOrder PurchaseOrder.dll
</pre></div>

<p>
<li> The result is an XSD schema that describes what the XML file will look like when you serialize your object using the XML Serialization classes:<p>

        <Acme:SourceRef
        ViewSource="~/howto/samples/Xmlserialization/PurchaseOrderXsd.src"
        Icon="../../../images/genicon.gif"
        Caption="PurchaseOrder.XSD"
        runat="server" />

<p>
Note: The xsd.exe tool generates output schemas named schema0.xsd, schema1.xsd, and so on. For clarity, the output schema has been renamed to PurchaseOrder.XSD in this example.

</ol>

</asp:Content>
