<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.HtmlControls.HtmlInputText" runat="server">
  HtmlInputText
</Acme:TypeRef>
</h2>

The <b>HtmlInputText</b> control is a single-line input control that lets the user enter text.  <b>HtmlInputText</b>
supports two behaviors.  If <b>Type</b> is <b>Text</b>, <b>HtmlInputText</b> operates as a standard text box.  If <b>Type</b> is
<b>Password</b>, the user's input is masked by the "*" character to keep it private.

<br /><br />

The following sample illustrates using the <b>HtmlInputText</b> control in both <b>Text</b> and <b>Password</b> modes.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlInputText/HtmlInputText1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlInputText/HtmlInputText1.src"
        Caption="C# HtmlInputText1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlInputText/HtmlInputText1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlInputText/HtmlInputText1.src"
        Caption="VB HtmlInputText1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>