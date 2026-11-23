<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.Literal" runat="server">
  Literal
</Acme:TypeRef>
</h2>

A <b>Literal</b> control is used to display text. You cannot apply a style to a literal control. 

This control will pass the content directly to the client browser, unless you use the Mode property to encode the content.


<h3>Simple Literal control</h2>
The following example demonstrates how to use the <b>Literal</b> control to display static text.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/Literal/Literal1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/Literal/Literal1.src"
        Caption="C# Literal1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/Literal/Literal1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/Literal/Literal1.src"
        Caption="VB Literal1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<h3>Encode Literal control</h2>

By setting the <b>Mode</b> property to <code>Encode</code>, the Literal control will encode the content of the Text property.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/Literal/Literal2_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/Literal/Literal2.src"
        Caption="C# Literal2.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/Literal/Literal2_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/Literal/Literal2.src"
        Caption="VB Literal2.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
