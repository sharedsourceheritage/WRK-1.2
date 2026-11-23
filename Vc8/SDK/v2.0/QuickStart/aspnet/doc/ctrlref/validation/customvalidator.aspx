<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.CustomValidator" runat="server">
  CustomValidator
</Acme:TypeRef>
</h2>

The <b>CustomValidator</b> control calls a user-defined function to perform validations that the standard
validators can't handle. The custom function can execute on the server or in client-side script, such as JScript
or VBScript. For client-side custom validation, the name of the custom function must be identified in the
<b>ClientValidationFunction</b> property. The custom function must have the form  <code>function myvalidator(source, arguments)</code>
Note that <b>source</b> is the client-side <b>CustomValidator</b> object, and <b>arguments</b> is an object with two properties,
<b>Value</b> and <b>IsValid</b>.  The <b>Value</b> property is the value to be validated and the <b>IsValid</b> property is a
Boolean used to set the return result of the validation.  You can view a client-side validation example in the <asp:HyperLink NavigateUrl="~/aspnet/doc/validation/default.aspx" runat="server">Validating Form Input Controls</asp:HyperLink>
section.

<br /><br />

For server-side custom validation, place your custom validation in the validator's <b>OnServerValidate</b> delegate.

<br /><br />

The following sample illustrates using the <b>CustomValidator</b> control.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/validation/CustomValidator/CustomValidator1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/validation/CustomValidator/CustomValidator1.src"
        Caption="C# CustomValidator1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/validation/CustomValidator/CustomValidator1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/validation/CustomValidator/CustomValidator1.src"
        Caption="VB CustomValidator1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

For a detailed discussion of Web Forms validation, please see the <asp:HyperLink NavigateUrl="~/aspnet/doc/validation/default.aspx" runat="server">Validating Form Input Controls</asp:HyperLink> section of this QuickStart tutorial.

</asp:Content>
