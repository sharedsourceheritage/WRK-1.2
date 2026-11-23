<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Using the Membership and Role Manager APIs</h2>
<p>
<h3>Membership</h3>

The Membership feature is built around two central classes:  <b>Membership</b> and <b>MembershipUser</b>.  The <b>Membership</b>
class provides methods for creating users (represented by the <b>MembershipUser</b> class), as well as common administrative methods
for managing users.  The users that are created with the <b>Membership</b> class represent the authenticated identities for an
ASP.NET application.  
<br /><br />
Common tasks that you perform with the <b>Membership</b> class include:
<ul>
  <li> Creating a new <b>MembershipUser</b>
  <li> Validating a username-password combination when a user attempts to log in.  You can then use Forms Authentication to issue
       a cookie indicating that a user has logged in to a site.
  <li> Retrieving a <b>MembershipUser</b> instance
  <li> Updating a <b>MembershipUser</b> instance 
  <li> Searching for users based on various search criteria
  <li> Getting the count of authenticated users that are currently online
  <li> Deleting users from the system when they are no longer needed
</ul>
Once you have obtained a <b>MembershipUser</b> instance, the common tasks that you perform directly with the <b>MembershipUser</b>
class include:
<ul>
   <li>Accessing the properties on the <b>MembershipUser</b> class in your application
   <li>Retrieving a user's password (only if the Membership feature is configured to allow password retrieval)
   <li>Changing a user's password or resetting a user's password
   <li>Changing a user's password question and password answer (if the Membership feature has been configured to prompt a user
       for a password question and answer prior to retrieving or updating a password).
   <li> Unlocking a user that has been locked out due to bad passwords or bad password answers.
</ul>

<h3>Role Manager</h3>

The central management class for Role Manager is the <b>Roles</b> class.  The <b>Roles</b> class provides methods for creating roles
and assigning users to roles. It also provides common administrative methods for managing role information.
<br /><br />
Common tasks that you perform with the <b>Roles</b> class include:
<ul>
  <li> Creating a new role
  <li> Deleting an existing role
  <li> Assigning users to roles
  <li> Removing users from roles
  <li> Determining if a user is authorized to a specific role
  <li> Searching for users in a specific role, as well as retrieving all users in a role
  <li> Getting the role information for a specific user
</ul>
The Role Manager feature also includes an <code>HttpModule</code>.  This module is responsible for retrieving
role assignments for a user and storing this information inside of a <b>RolePrincipal</b> that is available on the <code>HttpContext</code> for
a page.  The existence of a <b>RolePrincipal</b> on the <code>HttpContext</code> allows you to secure pages and directories using the 
<code>&lt;authorization&gt;</code> element.  Depending on the role information stored in the <b>RolePrincipal</b>, a user
can be authorized for only specific pages and directories within a site.
<br /><br />
<h3>Examples</h3>
The following samples demonstrate how to use the Membership API in an application.
<a name="createuser"></a>
<h3>Creating a New User</h3>
The following sample demonstrates how to create a new <b>MembershipUser</b>.  This sample uses the <code>Membership.CreateUser</code>
overload that returns a status parameter.  Other overloads are available that throw exceptions as opposed to returning a status
code.  Note that by default, the Membership feature requires passwords to be at least seven characters long, and the password 
must contain at least one non-alphanumeric character.
<br><br>
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/security/membershiproles_cs/CreatingUsers.aspx"
        ViewSource="~/aspnet/samples/security/CreatingUsers.src"
        Caption="C# Creating a User Using Membership"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/security/membershiproles_vb/CreatingUsers.aspx"
        ViewSource="~/aspnet/samples/security/CreatingUsers.src"
        Caption="VB Creating a User Using Membership"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="login"></a>
<h3>User Login and Accessing User Properties</h3>

The following sample demonstrates user login with the <code>Membership.ValidateUser</code> method.  It also demonstrates
how to use Forms Authentication with Membership when logging in a user.  With the user account created in the 
previous sample, enter your credentials on the login page.  Once you are logged in you will be redirected to a page
that uses <code>Membership.GetUser</code> to retrieve the <b>MembershipUser</b> instance corresponding to the
logged in user.  Also notice that the page that displays user properties has been placed in a directory that only allows access
to authenticated users.  Click the logout link at the bottom of the page to log yourself out.
<br/><br/>
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/security/membershiproles_cs/secured/DisplayUserProperties.aspx"
        ViewSource="~/aspnet/samples/security/Login.src"
        Caption="C# Login and Viewing User Properties"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/security/membershiproles_vb/secured/DisplayUserProperties.aspx"
        ViewSource="~/aspnet/samples/security/Login.src"
        Caption="VB Login and Viewing User Properties"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="update"></a>
<h3>Updating User Properties</h3>

Login again using the credentials that were created earlier. The page displays the user properties with the <b>DetailsView</b> control that is new in ASP.NET 2.0.
The <b>DetailsView</b> control communicates with a data source control.  In this example, an <b>ObjectDataSource</b> control is used to retrieve the contents of a 
<b>MembershipUser</b> instance.  You can click on the <i>Edit</i> link at the bottom of the page to toggle the <b>DetailsView</b> into edit mode.  Both the email
and comment for the <b>MembershipUser</b> can be changed.  When you want to save the new values to the database, click on the <i>Update</i> link.  Notice in the
code that the page implements the <code>ItemUpdating</code> event that is raised by the <b>ObjectDataSource</b>.  This is necessary because the <b>MembershipUser</b>
class does not have a parameter-less constructor, which is a requirement to use automatic two-way databinding with <b>ObjectDataSource</b>.    Click the logout link at
the bottom of the page to log yourself out.
<br/><br/>
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/security/membershiproles_cs/secured/UpdateUserProperties.aspx"
        ViewSource="~/aspnet/samples/security/Update.src"
        Caption="C# Updating User Properties"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/security/membershiproles_vb/secured/UpdateUserProperties.aspx"
        ViewSource="~/aspnet/samples/security/Update.src"
        Caption="VB Updating User Properties"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="lockout"></a>
<h3>Account Lockouts</h3>
The Membership feature automatically tracks the number of bad password attempts that occur during login.  It also tracks the number of bad password answers that are supplied
when either retrieving a password or attempting to reset a password.  This sample demonstrates the automatic account lockout ability, as well as how to unlock a user
once the account is locked out.  First create a new user account using the <a href="#createuser">Creating a New User</a> sample.  Next, click on the button below to run 
the Account Lockout sample.  The login page displays the number of bad login attempts you will need to make in order to lock yourself out.  On the login
page, use the first account you created, and intentionally enter a bad password.  Continue to use a bad password for the number of times indicated on the login page.
Notice that after making the appropriate number of bad login attempts, if you then use the correct password, you still cannot login - this is 
because the Membership feature automatically locked the account out after the appropriate number of bad login attempts occurred.  In order to unlock the user account,
login with the second user account that you just created.  The page that is displayed is very similar to the previous sample that displayed user properties.  However,
this page allows you to enter an arbitrary username in the textbox at the bottom of the page.  Enter the username for the locked out account into this textbox and hit
the Enter key.  The <b>DetailsView</b> control will refresh and show the information for this user.  Notice that the checkbox <code>IsLockedOut</code> for the lockout status is checked.  The 
<code>LastLockoutDate</code> has also been updated to indicate when the user was locked out.  Click the unlock button at the bottom of the page to unlock the currently 
displayed user.  This will call the <code>UnlockUser</code> method on the <b>MembershipUser</b> instance, thus unlocking the user account.  After unlocking the user, 
the <code>IsLockedOut</code> checkbox has been cleared, and the <code>LastLockoutDate</code> property has been reset.  Click the logout link at the bottom of the page.
Now attempt to login with the first user account.  Notice that you can now login successfully again.
<br/><br/>
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/security/membershiproles_cs/secured/UnlockUser.aspx"
        ViewSource="~/aspnet/samples/security/UnlockUser.src"
        Caption="C# Account Lockout"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/security/membershiproles_vb/secured/UnlockUser.aspx"
        ViewSource="~/aspnet/samples/security/UnlockUser.src"
        Caption="VB Account Lockout"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="delete"></a>
<h3>Deleting a User</h3>

You can delete a user with the <code>Membership.DeleteUser</code> method.  The following sample demonstrates deleting the currently
logged in user and then logging the user out with Forms Authentication.
<br/><br/>
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/security/membershiproles_cs/secured/DeleteUser.aspx"
        ViewSource="~/aspnet/samples/security/DeleteUser.src"
        Caption="C# Deleting A User"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/security/membershiproles_vb/secured/DeleteUser.aspx"
        ViewSource="~/aspnet/samples/security/DeleteUser.src"
        Caption="VB Deleting A User"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="roles"></a>
<h3>Managing Roles</h3>

The following samples demonstrate the Role Manager feature using roles with an authenticated user.  All of the sample pages deny access to anonymous users.
If you have not already done so, create a new user with the <a href="#createuser">Creating a New User</a> sample.  By default the Role Manager feature is 
not enabled in ASP.NET.  However, the web.config used in the following samples explicitly enables the Role Manager feature.
<a name="deleteroles"></a>
<h3>Adding and Deleting Roles</h3>

The following sample demonstrates how to create and delete roles using the <code>Roles.CreateRole</code> and <code>
Roles.DeleteRole</code> methods.  After you create a new role, or delete an existing role, the page uses the <code>Roles.GetAllRoles</code>
 method to display the available roles in the system.  The return value from <code>Roles.GetAllRoles</code> can be easily bound to
any control that supports databinding.  For the last sample, you will want to create at least one role called  "Administrators".
<br /><br />
As you create and delete roles, note that the Role Manager feature does not allow you to
create duplicate roles.  Also note that, by default, Role Manager does not allow you to delete populated roles.
<br><br>
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/security/membershiproles_cs/secured/Add_Delete_Roles.aspx"
        ViewSource="~/aspnet/samples/security/Add_Delete_Roles.src"
        Caption="C# Adding And Deleting Roles"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/security/membershiproles_vb/secured/Add_Delete_Roles.aspx"
        ViewSource="~/aspnet/samples/security/Add_Delete_Roles.src"
        Caption="VB Adding And Deleting Roles"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="addrole"></a>
<a name="deleterole"></a>
<h3>Adding a User to a Role and Deleting a User from a Role</h3>

Using the roles that you previously created, this sample demonstrates how to add a user to a role and how to remove a user from a role.
A user is added to a role with the <code>Roles.AddUserToRole</code> method, while a user is removed from a role with the
<code>Roles.RemoveUserFromRole</code> method.  Prior to adding a user to a role, a check is made to ensure that the user is not
already a member of the role.  This check is performed because Role Manager throws an exception if you attempt to add a user more 
than once to a role.  As with the previous sample, role information and role membership is displayed using data-bound controls.  The
list of roles that a user belongs to is retrieved with the <code>Roles.GetRolesForUser</code> method.  For the next sample to
work, make sure to add yourself to the "Administrators" role.
<br /><br />
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/security/membershiproles_cs/secured/Add_Delete_UserRoles.aspx"
        ViewSource="~/aspnet/samples/security/Add_Delete_UserRoles.src"
        Caption="C# Adding And Deleting Users To/From Roles"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/security/membershiproles_vb/secured/Add_Delete_UserRoles.aspx"
        ViewSource="~/aspnet/samples/security/Add_Delete_UserRoles.src"
        Caption="VB Adding And Deleting Users To/From Roles"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="auth"></a>
<h3>Authorizing Access to a Page with Role Manager</h3>

The web.config file for this sample contains an <code>&lt;authorization&gt;</code> element restricting access to members of the
"Administrators" role.  If you have not already done so, make sure to create a role called "Administrators" and add yourself to that
role.  Once you are a member of the "Administrators" role, you will be able to reach the sample page.  ASP.NET provides a Role
Manager <code>HttpModule</code> that automatically attaches a <b>RolePrincipal</b> to the <code>HttpContext</code> of the current request.  If you are a 
member of the "Administrators" role, when Url authorization performs an <code>IsInRole</code> check against the <b>RolePrincipal</b> 
(Url authorization calls <code>RolePrincipal.IsInRole</code>), the access check returns <code>true</code> and you are allowed
to access the page.  Note that you can reference a <b>RolePrincipal</b> in your page by calling <code>Page.User</code> and casting
the result to a <b>RolePrincipal</b>.
<br /><br />
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/security/membershiproles_cs/administrators_role/Administrators_Page.aspx"
        ViewSource="~/aspnet/samples/security/Administrators_Page.src"
        Caption="C# Authorizing Access To a Page For A Role"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/security/membershiproles_vb/administrators_role/Administrators_Page.aspx"
        ViewSource="~/aspnet/samples/security/Administrators_Page.src"
        Caption="VB Authorizing Access To a Page For A Role"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="progauth"></a>
<h3>Programmatically Checking Authorization</h3>

Because the Role Manager feature attaches a <b>RolePrincipal</b> to the <code>HttpContext</code>, you can also write code to perform access checks against the
<b>RolePrincipal</b>. If you have not already done so, make sure to create two additional roles called "Regular Users" and "Power Users". Add yourself to these
roles as well.  When you run the sample, the page performs <code>IsInRole</code> checks using a variety of techniques.  Some access checks are made using <code>
User.IsInRole</code>.  This demonstrates that the <b>RolePrincipal</b> is available using the normal <code>Page.User</code> syntax.  The page also demonstrates
casting <code>Page.User</code> to a <b>RolePrincipal</b> reference, and then calling <code>IsInRole</code> directly on the <b>RolePrincipal</b>.
<br /><br />
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/security/membershiproles_cs/secured/IsInRole.aspx"
        ViewSource="~/aspnet/samples/security/IsInRole.src"
        Caption="C# Programmtic Authorization"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/security/membershiproles_vb/secured/IsInRole.aspx"
        ViewSource="~/aspnet/samples/security/IsInRole.src"
        Caption="VB Programmtic Authorization"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>


