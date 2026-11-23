<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.Xml" runat="server">
  Xml
</Acme:TypeRef>
</h2>

The <b>Xml</b> control can be used to write out an XML document or the results of an XSL
Transform.  The <b>DocumentSource</b> specifies the XML document to use.  This document
will be written directly to the output stream unless <b>TransformSource</b> is also specified.
<b>TransformSource</b> must be a valid XSL Transform document and will be used to transform
the XML document before its contents are written to the output stream.  The following sample
illustrates using a simple <b>Xml</b> control.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/Xml/Xml1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/Xml/Xml1.src"
        Caption="C# Xml1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/Xml/Xml1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/Xml/Xml1.src"
        Caption="VB Xml1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br /><br />

A preloaded <b>XMLDocument</b> can be passed to the <b>Document</b> property of the <b>Xml</b> control.
You can also pass a preloaded <b>XSLTransform</b> to the <b>Transform</b>
property of the <b>Xml</b> control.  The following sample illustrates creating custom <b>XMLDocument</b> and <b>XSLTransform</b>
objects, then passing them into the <b>Xml</b> control to be displayed.

<br /><br />

<!--intermediate-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/Xml/Xml2_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/Xml/Xml2.src"
        Caption="C# Xml2.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/Xml/Xml2_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/Xml/Xml2.src"
        Caption="VB Xml2.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
