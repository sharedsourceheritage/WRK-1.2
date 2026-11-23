<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.HtmlControls.HtmlImage" runat="server">
  HtmlImage
</Acme:TypeRef>
</h2>

An <b>HtmlImage</b> control renders the image file specified by its <b>Src</b> property in an HTML <b>&lt;img&gt;</b> tag.

<br />

The following sample illustrates using the <b>HtmlImage</b> control.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlImage/HtmlImage1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlImage/HtmlImage1.src"
        Caption="C# HtmlImage1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlImage/HtmlImage1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlImage/HtmlImage1.src"
        Caption="VB HtmlImage1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>