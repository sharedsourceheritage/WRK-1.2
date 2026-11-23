<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.HiddenField" runat="server">
  HiddenField
</Acme:TypeRef>
</h2>

This control enables a developer to store a non-displayed value.
<br /><br />

The <b>HiddenField</b> control is used to store a value that needs to be persisted across posts to the server. It is rendered as an &lt;input type= "hidden"/&gt; element.
Normally view state, session state, and cookies are used to maintain the state of a Web Forms page. However, if these methods are disabled or are not available, you can use the <b>HiddenField</b> control to store state values.  Note that because the value of a HiddenField is rendered to the client browser,
it is not suitable for storing security-sensitive values.
To specify the value for <b>HiddenField</b> a control, use the <b>Value</b> property. You can provide a routine that gets called everytime the value of the <b>HiddenField</b> control changes between posts to the server by creating an event-handler for the <b>ValueChanged</b> event.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/HiddenField/HiddenField1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/HiddenField/HiddenField1.src"
        Caption="C# HiddenField1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/HiddenField/HiddenField1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/HiddenField/HiddenField1.src"
        Caption="VB HiddenField1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
