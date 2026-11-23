<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Securing Your Application</h2>

<div class="new">

<h3>What's New in 2.0</h3>

<ul>
  <li><b>Membership and Role Manager Providers - </b> ASP.NET 2.0 now includes built-in support for membership (user name/password credential storage) and role management services out of the box. Because all of these services are provider-driven, they can be easily swapped out and replaced with your own custom implementation.</li>
  <br /><br />
  <li><b>Login Controls - </b> The new login controls provide the building blocks to add authentication and authorization-based UI to your site, such as login forms, create user forms, password retrieval, and custom UI for logged in users or roles. These controls use the built-in membership and role services in ASP.NET 2.0 to interact with the user and role information defined for your site. </li>
</ul>
This section discusses these and other security-related features in ASP.NET 2.0.
</div>

<br /><br />

An important part of many Web applications is the ability to identify 
users and control access to resources.  The act of determining the 
identity of the requesting entity is known as authentication.  
Generally, the user must present credentials, such as a name/password pair in order to be 
authenticated. 
Once an authenticated identity is available, it must be determined 
whether that identity can access a given resource. This process is 
known as authorization.  ASP.NET works in conjunction with IIS to provide authentication and authorization services to applications.

<p>
An important feature of COM objects is the ability to control the 
identity under which COM object code is executed.  When a COM object 
executes code with the identity of the requesting entity, this is 
known as impersonation.  ASP.NET Framework applications can optionally choose to impersonate requests.
<p>
Some applications also want to be able to dynamically tailor content, 
based on the requesting identity or based on a set of roles that a 
requesting identity belongs to.  ASP.NET Framework applications can dynamically 
check whether the current requesting identity participates 
in a particular role. For example, an application might want to check 
to see whether the current user belongs to the manager's role, in 
order to conditionally generate content for managers.
<p>
The ASP.NET 2.0 Membership feature facilitates the creation and management of users.  The Membership
feature works in conjunction with another new feature called Role Manager.  Role Manager provides the infrastructure for creating
roles and assigning users to roles.  When the Membership and Role Manager features are used in conjunction with Forms Authentication,
ASP.NET 2.0 provides end-to-end support for creating, authenticating and authorizing users.
<br /><br />
Both Membership and Role Manager have been designed with a provider-based model.  Providers
abstract the physical data storage for a feature from the classes and business logic exposed by a feature.  Both Membership and
Role Manager ship with providers for Microsoft&trade; SQL Server.  Membership also ships with a provider that works against Active Directory and 
Active Directory Application Mode (ADAM).  Role Manager ships with an additional provider that works with the Authorization Manager feature available in
Windows Server 2003.  You can create your own custom providers and 
configure them to work either the Membership or Role Manager features.  Pages that use the Membership and Role Manager features
will continue to work unchanged with your custom providers.
<br /><br />
The Login Controls are a set of custom server controls that provide common user interfaces for authentication and authorization
tasks.  The Login Controls use the functionality in the Membership, Role Manager, and Forms Authentication features.


</asp:Content>


