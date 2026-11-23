<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.HtmlControls.HtmlButton" runat="server">
  HtmlButton
</Acme:TypeRef>
</h2>

The <b>HtmlButton</b> control renders as an HTML 4.0 <b>&lt;button&gt;</b>.  This differs from 
<asp:HyperLink NavigateUrl="~/aspnet/doc/ctrlref/html/HtmlInputButton.aspx" runat="server">
&lt;input type="button"&gt;</asp:HyperLink> in that it enables Web developers to create rich user interface form buttons
that can be composed from embedded HTML elements (and even other ASP.NET server controls).

<br /><br />

The following sample illustrates using the <b>HtmlButton</b> control.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlButton/HtmlButton1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlButton/HtmlButton1.src"
        Caption="C# HtmlButton1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlButton/HtmlButton1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlButton/HtmlButton1.src"
        Caption="VB HtmlButton1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
