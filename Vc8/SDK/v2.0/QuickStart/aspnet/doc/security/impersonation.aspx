<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>User Account Impersonation</h2>

As mentioned in the <a href="default.aspx">Security 
Overview</a>, impersonation is the ability of a thread to execute in a security 
context different from that of the process owning the thread.  What this means 
for a Web application is that if a server is impersonating, it is doing work 
using the identity of the client making the request.

<p>
By default, ASP.NET does not do per-request impersonation.  This is 
different from ASP, which does impersonate on every request.  If desired, 
you can configure an application to impersonate on every request 
with the following <b>Configuration</b> directive:

<p>
<pre class="code">
&lt;identity impersonate="true" /&gt;
</pre>
<p>
Since ASP.NET does dynamic compilation, enabling impersonation 
requires that all accounts have read/write access to the 
application's Codegen directory (where dynamically compiled objects 
are stored by the ASP.NET runtime) as well as the global assembly 
cache (%Windir%\assembly).  Some applications require impersonation 
to be enabled for ASP compatibility or to use Windows authentication 
services.

</asp:Content>


