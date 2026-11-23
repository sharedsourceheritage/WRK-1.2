<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4>How Do I...Use an Extension Object in an XSLT Style Sheet?</h4>
<p>
The XsltArgumentList class contains XSLT parameters and XSLT extension objects. When passed into the Execute method, these parameters and extension objects can be invoked from style sheets.
</p>
<Acme:LangSwitch runat="server">
  <CsTemplate>
<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/ExtensionObject/ExtensionObject.src"
Icon="../../../images/genicon.gif"
SamplePath="howto\samples\Xml\ExtensionObject\"
CanBeHosted="false"
Caption="C# ExtensionObject.exe"
runat="server" 
/>
  </CsTemplate>
  <VbTemplate>
<Acme:SourceRef
ViewSource="~/howto/samples/Xml/ExtensionObject/ExtensionObject.src"
RunSample=""
Icon="../../../images/genicon.gif"
SamplePath="howto\samples\Xml\ExtensionObject\"
CanBeHosted="false"
Caption="VB ExtensionObject.exe"
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
<p>
XSLT extension objects are added to the XsltArgumentList using the AddExtensionObject method. A qualified name and namespace URI are associated with the extension object at that time.
<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
//Create an XsltArgumentList
XsltArgumentList xslArg = new XsltArgumentList();

//Add an object to calculate the circumference of the circle.
Calculate obj = new Calculate();
xslArg.AddExtensionObject("urn:myObj", obj);
</Tab>
<Tab Name="VB">
'Create an XsltArgumentList
Dim xslArg As New XsltArgumentList()

'Add an object to calculate the circumference of the circle.
Dim obj As New Calculate()
xslArg.AddExtensionObject("urn:myObj", obj)
</Tab>

</Acme:TabControl>
<p>
The following code creates the XSLT processor and executes the transformation. By passing in the XsltArgumentList object to the Execute method, the extension object is now usable by the XSLT processor.
<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
//Create XslCompiledTransform and compile stylesheet.
XslCompiledTransform processor = new XslCompiledTransform();
...
//Create an XmlWriter to output to the console.   
using (XmlWriter writer = XmlWriter.Create(Console.Out))
{
    //Transform the file.
    processor.Transform(filename, xslArg, writer);
}
</Tab>
<Tab Name="VB">
Dim processor As New XslCompiledTransform()
...
 'Create an XmlWriter to output to the console.   
Using writer As XmlWriter = XmlWriter.Create(Console.Out)
    'Transform the file.
    processor.Transform(filename, xslArg, writer)
End Using
</Tab>

</Acme:TabControl>
<p>
<h4>Summary</h4>
<ol>
<li>The XsltArgumentList class extends XSLT functionality by allowing you to add extension objects and parameters.
<li>Use the AddExtensionObject method to add the extension object.
<li>Invoke the extension object in the style sheet.
<li>Pass the XsltArgumentList object to the Transform method.
</ol>

</asp:Content>
