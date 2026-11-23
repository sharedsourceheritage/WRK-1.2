<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.HtmlControls.HtmlInputImage" runat="server">
  HtmlInputImage
</Acme:TypeRef>
</h2>

An <b>HtmlInputImage</b> control is used to create a graphical button.  Unlike <b>HtmlButton</b> controls,
all standard browser clients support image buttons.

<br />

The following sample illustrates using the <b>HtmlInputImage</b> control.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlInputImage/HtmlInputImage1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlInputImage/HtmlInputImage1.src"
        Caption="C# HtmlInputImage1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlInputImage/HtmlInputImage1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlInputImage/HtmlInputImage1.src"
        Caption="VB HtmlInputImage1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
