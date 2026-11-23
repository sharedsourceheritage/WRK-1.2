<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.RequiredFieldValidator" runat="server">
  RequiredFieldValidator
</Acme:TypeRef>
</h2>

The <b>RequiredFieldValidator</b> control ensures that the user does not skip an entry.
The control fails validation if the value it contains does not change from its initial value when validation is performed. 
If all the fields in the page are valid, the page is valid.

<br /><br />

The following sample illustrates using the <b>RequiredFieldValidator</b> control.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/validation/RequiredFieldValidator/ReqFieldValidator1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/validation/RequiredFieldValidator/ReqFieldValidator1.src"
        Caption="C# ReqFieldValidator1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/validation/RequiredFieldValidator/ReqFieldValidator1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/validation/RequiredFieldValidator/ReqFieldValidator1.src"
        Caption="VB ReqFieldValidator1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

For a detailed discussion of Web Forms validation, please see the <asp:HyperLink NavigateUrl="~/aspnet/doc/validation/default.aspx" runat="server">Validating Form Input Controls</asp:HyperLink> section of this QuickStart tutorial.

</asp:Content>

