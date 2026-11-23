<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4>How Do I...Debug an XSL Transformation Application?</h4>

<p>
This sample illustrates how to debug an XSLT application.
<p>
<Acme:LangSwitch runat="server">
  <CsTemplate>

<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/TransformXML_Debug/TransformXML.src"
Icon = "/quickstart/images/genicon.gif"
Caption="C# TransformXML.exe"
SamplePath="howto\samples\Xml\TransformXML_Debug\"
CanBeHosted="false"
runat="server" />

  </CsTemplate>
  <VbTemplate>

<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/TransformXML_Debug/TransformXML.src"
Icon = "/quickstart/images/genicon.gif"
Caption="VB TransformXML.exe"
SamplePath="howto\samples\Xml\TransformXML_Debug\"
CanBeHosted="false"
runat="server" />

  </VbTemplate>
  <CpTemplate>

<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/TransformXML_Debug/TransformXML.src"
Icon = "/quickstart/images/genicon.gif"
Caption="C++ TransformXML.exe"
SamplePath="howto\samples\Xml\TransformXML_Debug\"
CanBeHosted="false"
runat="server" />

  </CpTemplate>
</Acme:LangSwitch>

<p>
The Visual Studio debugger can be used to debug an XSLT application. When instantiating the XslCompiledTransform 
object, set the <i>enableDebug</i> parameter to true in your code. This tells the XSLT 
processor to create debug information when the code is compiled. You can start debugging
as you would with any other application. When you get to the Transform method call, you can 
press F11 to step into the code. This loads the XSLT style sheet in a new document window 
and the starts the XSLT debugger. You can now set breakpoints in the style sheet, step through the code in the style sheet, and so on.

<p>
<b>Note</b> 
<br>
The XSLT debugger is available in the Professional and Enterprise editions of Visual Studio.

<p>
The following code enables debugging on the XslCompiledTransform object. 
<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
XslCompiledTransform processor = new XslCompiledTransform(true);
</Tab>
<Tab Name="VB">
Dim processor As New XslCompiledTransform(true)
</Tab>
<Tab Name="C++">
XslCompiledTransform^ processor = gcnew XslCompiledTransform(true);
</Tab>
</Acme:TabControl>
<p>
<H4>Summary</H4>
<OL>
<LI>The Visual Studio debugger can be used to debug XSLT style sheets or XSLT applications.
<LI>To debug an XSLT application, set the <i>enableDebug</i> parameter to true when instantiating the XslCompiledTransform object. This tells the XSLT processor to create debug information when the code is compiled.
<LI>Set a breakpoint on the Transform method call.
<LI>Start the Visual Studio debugger and press F11 to step into the XSLT code. The XSLT style sheet is loaded in a new document window and the XSLT debugger is started.
</OL>

<p>

</asp:Content>



















