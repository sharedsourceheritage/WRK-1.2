<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.HtmlControls.HtmlInputRadioButton" runat="server">
  HtmlInputRadioButton
</Acme:TypeRef>
</h2>

An <b>HtmlInputRadioButton</b> control creates a single radio button input field.   Setting the <b>Name</b>
attribute the same way on each radio button forms a group in which only one radio button can be selected at a time.
The selected state must be tested on the individual radio buttons, however.

<br /><br />

The following sample illustrates using the <b>HtmlInputRadioButton</b> control.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlInputRadioButton/HtmlInputRadioButton1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlInputRadioButton/HtmlInputRadioButton1.src"
        Caption="C# HtmlInputRadioButton1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlInputRadioButton/HtmlInputRadioButton1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlInputRadioButton/HtmlInputRadioButton1.src"
        Caption="VB HtmlInputRadioButton1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
