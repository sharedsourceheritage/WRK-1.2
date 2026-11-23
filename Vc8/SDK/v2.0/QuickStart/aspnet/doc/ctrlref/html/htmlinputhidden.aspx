<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.HtmlControls.HtmlInputHidden" runat="server">
  HtmlInputHidden
</Acme:TypeRef>
</h2>

You can use hidden controls within HTML forms to embed non-visible information that will be sent back to the
server the next time a user performs a postback.  This technique is commonly used to persist session-dependent
information without using cookies or session state.   The Web Forms framework uses this feature of
HTML to automatically store and restore the view state of ASP.NET server controls across round trips to the server.

<br /><br />

The following sample illustrates using the <b>HtmlInputHidden</b> control.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlInputHidden/HtmlInputHidden1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlInputHidden/HtmlInputHidden1.src"
        Caption="C# HtmlInputHidden1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlInputHidden/HtmlInputHidden1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlInputHidden/HtmlInputHidden1.src"
        Caption="VB HtmlInputHidden1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
