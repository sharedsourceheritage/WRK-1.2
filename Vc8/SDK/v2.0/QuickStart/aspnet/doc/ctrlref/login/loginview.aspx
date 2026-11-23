<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.LoginView" runat="server">
  LoginView
</Acme:TypeRef>
</h2>

The LoginView control automatically detects a user's authentication status and role and matches that information to appropriate template of information to display to that user.  The LoginView control consists of a collection of templates that can be associated with an authentication status or one or more role groups. For more information about the membership and roles system <asp:hyperlink navigateurl ="~/aspnet/doc/security/default.aspx"    runat="server"> click here </asp:hyperlink>.  Since the LoginView derives from control (and not webcontrol) it has no style properties. It's intent is to serve as a non-visual container that automatically switches the template to be displayed based on the user's designation.


<b>Note:</b> The samples for this control use Master Pages to provide the information that is used to login a user. Learn more about <asp:hyperlink navigateurl ="~/aspnet/doc/masterpages/default.aspx"    runat="server"> Master Pages </asp:hyperlink> here. 

<br/><br/>

<h3>Simple LoginView Sample </h3>
This sample demonstrates the Anonymous and LoggedIn templates for the LoginView control. Both of these templates are properties on the control and do not require using roles or adding a role group collection to the control.  

<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/Login_cs/LoginViewBasic.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/LoginViewBasic.src"
        Caption="C# LoginView"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/Login_vb/LoginViewBasic.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/LoginViewBasic.src"
        Caption="VB LoginView"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

<h3>LoginView RoleGroup Behaviors </h3>
In addition to the Anonymous and LoggedIn templates the LoginView control supports a collection of templates associated with different user roles. Since a user can be associated with multiple roles and a template can be associated with multiple roles it is important to understand how a template is matched to the user's role. The RoleGroup collection of templates is sequential (Anonymous and LoggedIn templates are handled outside of the sequence). All of the roles associated with the user are retrieved and the LoginView control looks for a template that matches any role associated with the user. The LoginView control evaluates each template from top to bottom in the collection and the first template associated with a role that the user belongs to is displayed to that user.  There is <b>no attempt</b> by the control to merge all of the templates that the user is eligible to see based on all of their role group associations or to select the most privileged role group template. For example if a user is in both the customer and admin role groups and the customer template is sequentially before the admin template, that user will only ever see the customer template.  

<h3>LoginView RoleGroup Behavior Sample</h3>
This sample contains two LoginView controls with the same role group templates. The order of the templates is different in the two controls. As a result users who belong to more then one role will see different content in the two controls. 
<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/Login_cs/LoginViewBehaviors.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/LoginViewBehaviors.src"
        Caption="C# LoginView Behaviors"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/Login_vb/LoginViewBehaviors.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/LoginViewBehaviors.src"
        Caption="VB LoginView Behaviors"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

<h3>LoginView Templates </h3>
Since the LoginView control is heavily dependent on templates it is important to know how to programmatically access the controls inside the different templates. FindControl is the mechanism used to access the controls within the templates.


<h3>LoginView FindControl Template Sample</h3>
In this sample FindControl is used to access the selection of a DropDownList within the Admin template and display the value of the selection in a label. 
<br/> <br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/Login_cs/LoginViewTemplates.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/LoginViewTemplates.src"
        Caption="C# LoginView Templates"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/Login_vb/LoginViewTemplates.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/LoginViewTemplates.src"
        Caption="VB LoginView Templates"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />


</asp:Content>
