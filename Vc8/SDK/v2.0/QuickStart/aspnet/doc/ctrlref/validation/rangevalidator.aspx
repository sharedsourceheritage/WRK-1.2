<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.RangeValidator" runat="server">
  RangeValidator
</Acme:TypeRef>
</h2>

The <b>RangeValidator</b> control tests whether an input value falls within a given range.
<b>RangeValidator</b> uses three key properties to perform its validation:  <b>ControlToValidate</b> contains the value
to validate,  <b>MinimumValue</b> defines the minimum value of the valid range, and <b>MaximumValue</b> defines the maximum value of the valid
range.  These constants are stored as string values, but are converted to the data type defined by <b>Type</b> when
the comparison is performed.

<br /><br />

The following sample illustrates the <b>RangeValidator</b> control.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/validation/RangeValidator/RangeValidator1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/validation/RangeValidator/RangeValidator1.src"
        Caption="C# RangeValidator1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/validation/RangeValidator/RangeValidator1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/validation/RangeValidator/RangeValidator1.src"
        Caption="VB RangeValidator1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

For a detailed discussion of Web Forms validation, please see the <asp:HyperLink NavigateUrl="~/aspnet/doc/validation/default.aspx" runat="server">Validating Form Input Controls</asp:HyperLink> section of this QuickStart tutorial.

</asp:Content>
