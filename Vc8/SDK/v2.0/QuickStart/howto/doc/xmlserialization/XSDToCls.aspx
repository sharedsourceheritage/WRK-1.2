<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4>How do I create classes from an XSD schema?</h4>

<p>This topic describes how to create classes that can be used to read and write XML that is defined by an XML Schema Description (XSD) file. Once you understand how to generate the classes for your XSD schema, you should read the <a href="RWObjFromXML.aspx">"How Do I Read and Write Objects From XML?"</a> topic to find out how to actually load XML into them, and save XML from them.

<ol>
<li> Locate an XSD file.  In this example, we will use a purchase order schema, as follows: <p>

        <Acme:SourceRef
        ViewSource="~/howto/samples/Xmlserialization/PurchaseOrderXsd.src"
        Icon="../../../images/genicon.gif"
        Caption="PurchaseOrder.XSD"
        runat="server" />

<p>
<li> Use the xsd.exe tool in the SDK to generate source code for the classes you want. Do this by specifying the name of the XSD file as an argument to the executable. The example below creates classes in C# using the purchaseorder.xsd schema and puts them in the <b>XmlSerializationHowTo</b> namespace:

<div class="code"><pre>
xsd.exe -c -l:c# -n:XmlSerializationHowTo purchaseorder.xsd
</pre></div>

<li> The tool uses the XSD file to create a set of classes that can read XML files that use the schema that you specified. Here is the code that gets created for the above schema:<p>


<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        ViewSource="~/howto/samples/Xmlserialization/PurchaseOrder.src"
        Icon="../../../images/genicon.gif"
        Caption="C# PurchaseOrder.exe"
	Samplepath="howto\samples\Xmlserialization\"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        ViewSource="~/howto/samples/Xmlserialization/PurchaseOrder.src"
        Icon="../../../images/genicon.gif"
        Caption="VB PurchaseOrder.exe"
	Samplepath="howto\samples\Xmlserialization\"
        runat="server" />
  </VbTemplate>
 <VjsTemplate>
       <Acme:SourceRef
        RunSample=""
        ViewSource=""
        Icon = ""
        Caption=""
        runat="server" />
  </VjsTemplate>
  <CpTemplate>
       <Acme:SourceRef
        RunSample=""
        ViewSource=""
        Icon = ""
        Caption=""
        runat="server" />
  </CpTemplate>
</Acme:LangSwitch>


</ol>

In the code, you will notice additional "Custom Metadata Attributes" above the field declarations. These are used to guide the Xml Serializer classes in properly reading and writing the XML.  They are basically hints to the parser.  For example, the <b>Items</b> field has a custom attribute applied to it to tell the serializer to that the <b>Items</b> field should contain an array of item objects which get created when the XML is loaded.<p>



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


<p>
For detailed information on these attributes, see the reference documentation in the SDK.  They are located in the System.Xml.Serialization namespace. <p>
Now that you understand how to generate the classes for your XSD schema, you should read the <a href="RWObjFromXML.aspx">"How Do I Read and Write Objects From XML?"</a> topic to find out how to actually load XML into them, and save XML from them.

</p>
</asp:Content>

