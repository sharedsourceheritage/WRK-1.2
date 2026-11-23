<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.HtmlControls.HtmlGeneric" runat="server">
  HtmlGeneric
</Acme:TypeRef>
</h2>

The <b>HtmlGenericControl</b> provides an ASP.NET server control implementation for all unknown HTML server control
tags not directly represented by a specific HTML server control (for example, <b>&lt;span&gt;</b>, <b>&lt;div&gt;</b>,
<b>&lt;body&gt;</b>, and so on).

<br /><br />

The following sample illustrates using the <b>HtmlGenericControl</b> control for the <b>&lt;body&gt;</b> tag.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlGenericControl/HtmlGenericControl1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlGenericControl/HtmlGenericControl1.src"
        Caption="C# HtmlGenericControl1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlGenericControl/HtmlGenericControl1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlGenericControl/HtmlGenericControl1.src"
        Caption="VB HtmlGenericControl1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
