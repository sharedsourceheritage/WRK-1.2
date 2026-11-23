<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.Label" runat="server">
  Label
</Acme:TypeRef>
</h2>

The <b>Label</b> control displays text in a set location on the page.  Unlike static text, the <b>Text</b>
property of a label can be set programmatically.  The following sample illustrates using the <b>Label</b> control.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/Label/Label1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/Label/Label1.src"
        Caption="C# Label1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/Label/Label1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/Label/Label1.src"
        Caption="VB Label1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

The following sample illustrates how to databind the <b>Label</b> control.
<br /><br />

<!--databound-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/Label/Label2_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/Label/Label2.src"
        Caption="C# Label2.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/Label/Label2_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/Label/Label2.src"
        Caption="VB Label2.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
