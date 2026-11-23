<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.LoginStatus" runat="server">
  LoginStatus
</Acme:TypeRef>
</h2>

The LoginStatus control automatically detects the user's authentication status and displays the appropriate Login/Logout option. Clicking on the Login button will redirect the user to the login page for the website. The LoginStatus control will retrieve the login page URL from the web.config file forms authentication section. Clicking on the Logout button will clear the user's authentication status and by default refresh the page that they are currently viewing. The LoginStatus control can display the Login/Logout options as link buttons or image buttons.

<br /><br />
<h3> LoginStatus Sample </h3>
This sample shows the basic functionality of the LoginStatus control.
<br /><br />
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/Login_cs/LoginNameStatusBasic.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/LoginNameStatusBasic.src"
        Caption="C# LoginStatus"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/Login_vb/LoginNameStatusBasic.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/LoginNameStatusBasic.src"
        Caption="VB LoginStatus"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
