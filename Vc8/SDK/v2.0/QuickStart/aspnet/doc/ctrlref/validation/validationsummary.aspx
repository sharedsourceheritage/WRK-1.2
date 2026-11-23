<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.ValidationSummary" runat="server">
  ValidationSummary
</Acme:TypeRef>
</h2>

When the user's input is processed (for example, when the form is submitted), the Web Forms framework passes
the user's entry to the associated validation control or controls. The validation controls test the user's input
and set a property to indicate whether the entry passed the validation test. After all validation controls have
been processed, the <b>IsValid</b> property on the page is set; if any of the controls shows
that a validation check failed, the entire page is set to invalid.

<br /><br />

A <b>ValidationSummary</b> control is displayed when the <b>IsValid</b> property of the page is false.  It "polls" each of the
validation controls on the page and aggregates the text messages exposed by each.  The following  sample illustrates
displaying errors with a <b>ValidationSummary</b>.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/validation/ValidationSummary/ValidationSummary1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/validation/ValidationSummary/ValidationSummary1.src"
        Caption="C# ValidationSummary1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/validation/ValidationSummary/ValidationSummary1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/validation/ValidationSummary/ValidationSummary1.src"
        Caption="VB ValidationSummary1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

For a detailed discussion of Web Forms validation, please see the <asp:HyperLink NavigateUrl="~/aspnet/doc/validation/default.aspx" runat="server">Validating Form Input Controls</asp:HyperLink> section of this QuickStart tutorial.

</asp:Content>
