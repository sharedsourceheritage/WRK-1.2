<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Using the Login Controls</h2>

The following examples demonstrate how to use the login controls in an application.

<h3>Creating and Logging In a User</h3>

In this example we see a home page of a website which includes a <b>LoginStatus</b> control that prompts the user to login to the website. The LoginStatus control on this page determines that the user is not currently authenticated and displays a Login link to the user. Clicking on this link takes the user to the default login.aspx page which is configured in the forms authentication section of web.config.  The <b>Login</b> control is displayed on the Login.aspx page. (Note: The login control's VisibleWhenLoggedIn property is ignored on the default login page.) In this example, the login control sets additional properties to display the Create User link, clicking this link takes the user to another page where the <b>CreateUserWizard</b> control is used. By default the CreateUserWizard control is a two step process, on the first step a user enters the required information and when they click the create user button the control passes the information to the membership API. If the user can not be created by the membership API an appropriate error message is shown within the control or if the user is created they the control loads the second step in the wizard. In this example the ContinueDestinationPageUrl property has been set to return the user to the home page once they have been created.  By default the CreateUserWizard control authenticates or “logs-in” users when they are successfully created.  When a user is returned to the homepage they will notice that the LoginStatus control has detected that they are now authenticated and displays a logout link.  Clicking on the logout link causes the user's authentication ticket to be cleared and toggles the display to the login link.  At this point the user can click the login link, and since they have already created a user account, they can enter their username and password on the login.aspx to login to the website.  You will notice that the Login control displays a remember me checkbox.  Checking this box and successfully logging in will cause a persistent cookie to be written to the user's machine, with a default expiry of 50 years.  You can disable this option in the Login control by setting the DisplayRememberMe and the RememberMeSet properties are set to false. By reviewing the source for this example you will see that no code was written and that very few properties were set to enable this entire scenario.  Style properties for these controls were set via a stylesheet applied to the site. 

<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/security/logincontrols_cs/Home.aspx"
        ViewSource="~/aspnet/samples/security/LoginCtrl.src"
        Caption="C# LoginStatus, Login and CreateUserWizard"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/security/logincontrols_vb/Home.aspx"
        ViewSource="~/aspnet/samples/security/LoginCtrl.src"
        Caption="VB LoginStatus, Login and CreateUserWizard"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<h3>Displaying Different Content for Authenticated Users</h3>

This sample illustrates how to use a <b>LoginView</b> control to display different content for authenticated and anonymous users.  Although, not shown in this example the LoginView control also supports displaying different content based on a user's role. The <b>AnonymousTemplate</b> in the LoginView control contains a login control and the <b>LoggedInTemplate</b> contains the LoginName control.  The LoginName controls takes advantage of the formatstring property to display Welcome, followed by the user's name. To see both templates login to the site using a previously created user account or create a new account, to return to the anonymous content click the Logout link at the top of the page. 

<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/security/logincontrols_cs/HomeLoginView.aspx"
        ViewSource="~/aspnet/samples/security/LoginView.src"
        Caption="C# LoginView and LoginName"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/security/logincontrols_vb/HomeLoginView.aspx"
        ViewSource="~/aspnet/samples/security/LoginView.src"
        Caption="VB LoginView and LoginName"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<h3>Changing a Password</h3>

The ChangePassword control by default requires the user to be authenticated on the site prior to changing their password.  However, in this example we have set the DisplayUserName property to true, as a result a user can be authenticated by the ChangePassword control prior to changing their password or a user who is already authenticated on the site can enter a different user account and authenticate as that user prior to changing their password.  The sample also links to a CreateUser page that will let you create a valid user to test this scenario. 
<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/security/logincontrols_cs/HomeChangePassword.aspx"
        ViewSource="~/aspnet/samples/security/ChangePassword.src"
        Caption="C# ChangePassword"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/security/logincontrols_vb/HomeChangePassword.aspx"
        ViewSource="~/aspnet/samples/security/ChangePassword.src"
        Caption="VB ChangePassword"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>


