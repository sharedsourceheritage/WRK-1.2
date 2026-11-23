<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.CompareValidator" runat="server">
  CompareValidator
</Acme:TypeRef>
</h2>

The <b>CompareValidator</b> control compares the value of one control to another, or to an explicit value
in the control's <b>ValueToCompare</b> property.  

<br /><br />

<b>Note:</b> For the purpose of validation, a specific
property on the control is designated as its "value".  For more information, see the <a href="~/aspnet/doc/validation.aspx" runat="server">Validating Form Inputs</a> section.

<br /><br />

<b>CompareValidator</b> uses three key properties to perform its validation.  <b>ControlToValidate</b> and <b>ControlToCompare</b>
contain the values to compare.  <b>Operator</b> defines the type of comparison to perform, for example, Equal or Not
Equal.  <b>CompareValidator</b> performs the validation by evaluating these properties as an expression, as shown in the following example.

<br/><br/>

<code>   &lt;ControlToValidate&gt; &lt;Operator&gt; &lt;ControlToCompare&gt; </code>

<br/><br/>

If the expression evaluates <b>true</b>, the validation result is valid.

<br /><br />

The following sample illustrates using the <b>CompareValidator</b> control.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/validation/CompareValidator/CompareValidator1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/validation/CompareValidator/CompareValidator1.src"
        Caption="C# CompareValidator1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/validation/CompareValidator/CompareValidator1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/validation/CompareValidator/CompareValidator1.src"
        Caption="VB CompareValidator1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

For a detailed discussion of Web Forms validation, please see the <asp:HyperLink NavigateUrl="~/aspnet/doc/validation/default.aspx" runat="server">Validating Form Input Controls</asp:HyperLink> section of this QuickStart tutorial.

</asp:Content>
