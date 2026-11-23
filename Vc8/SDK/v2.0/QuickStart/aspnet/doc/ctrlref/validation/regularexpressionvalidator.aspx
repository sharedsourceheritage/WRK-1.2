<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>


<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.RegularExpressionValidator" runat="server">
  RegularExpressionValidator
</Acme:TypeRef>
</h2>

The <b>RegularExpressionValidator</b> control confirms that the entry matches a pattern defined by a
regular expression. This type of validation allows you to check for predictable sequences of characters,
such as those in social security numbers, e-mail addresses, telephone numbers, postal codes, and so on.

<br /><br />

<b>RegularExpressionValidator</b> uses two key properties to perform its validation:  <b>ControlToValidate</b> contains
the value to validate, and  <b>ValidationExpression</b> contains the regular expression to match.

<br /><br />

The following sample illustrates using the <b>RegularExpressionValidator</b> control.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/validation/RegularExpressionValidator/RegExValidator1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/validation/RegularExpressionValidator/RegExValidator1.src"
        Caption="C# RegExValidator1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/validation/RegularExpressionValidator/RegExValidator1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/validation/RegularExpressionValidator/RegExValidator1.src"
        Caption="VB RegExValidator1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

For a detailed discussion of Web Forms validation, please see the <asp:HyperLink NavigateUrl="~/aspnet/doc/validation/default.aspx" runat="server">Validating Form Input Controls</asp:HyperLink> section of this QuickStart tutorial.

</asp:Content>
