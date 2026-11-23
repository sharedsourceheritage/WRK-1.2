<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.PlaceHolder" runat="server">
  PlaceHolder
</Acme:TypeRef>
</h2>

The <b>PlaceHolder</b> control can be used as a container control within a document
to dynamically load other controls.  The <b>PlaceHolder</b> control has no HTML-based output
and is used only to mark a spot for other controls that can be added to the <b>Controls</b>
collection of the <b>PlaceHolder</b> during page execution.  The following example illustrates
adding controls to a <b>PlaceHolder</b>.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/PlaceHolder/PlaceHolder1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/PlaceHolder/PlaceHolder1.src"
        Caption="C# PlaceHolder1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/PlaceHolder/PlaceHolder1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/PlaceHolder/PlaceHolder1.src"
        Caption="VB PlaceHolder1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
