<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.HtmlControls.HtmlInputButton" runat="server">
  HtmlInputButton
</Acme:TypeRef>
</h2>

The <b>HtmlInputButton</b> control (<b>&lt;Input type=button&gt;</b>) is similar in function to the 
<asp:HyperLink NavigateUrl="~/aspnet/doc/ctrlref/html/HtmlButton.aspx" runat="server">&lt;button&gt;</asp:HyperLink> tag, except that it can target any browser.

<br /><br />

The following sample illustrates using the <b>HtmlInputButton</b> control.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlInputButton/HtmlInputButton2_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlInputButton/HtmlInputButton2.src"
        Caption="C# HtmlInputButton2.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlInputButton/HtmlInputButton2_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlInputButton/HtmlInputButton2.src"
        Caption="VB HtmlInputButton2.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<!--BEGIN SECTION-->
<a name="submit"></a>
<h3>Submit and Reset HtmlInputButtons</h3>

The <b>HtmlInputButton</b> control also supports the <b>Reset</b> and <b>Submit</b> button types, which are used only with forms.
<b>Submit</b> submits the form, whereas <b>Reset</b> restores all of the entry fields in a form to their initial values.

<br /><br />

The following sample illustrates using <b>Submit</b> and <b>Reset</b> <b>HtmlInputButton</b> controls.

<br /><br />

<!--submit/reset-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlInputButton/HtmlInputButton1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlInputButton/HtmlInputButton1.src"
        Caption="C# HtmlInputButton1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlInputButton/HtmlInputButton1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlInputButton/HtmlInputButton1.src"
        Caption="VB HtmlInputButton1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
