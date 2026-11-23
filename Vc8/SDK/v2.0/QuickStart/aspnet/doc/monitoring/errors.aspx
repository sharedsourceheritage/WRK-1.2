<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>

<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Handling Errors</h2>

When an error occurs on a page, ASP.NET sends information about the
error to the client.  Errors are divided into four categories:

<ul>
<li>Configuration errors: Occur when the syntax or structure of a
Web.config file in the configuration hierarchy is incorrect.</li>
<li>Parser errors: Occur when the ASP.NET syntax on a page is malformed.</li>
<li>Compilation errors: Occur when statements in a page's target 
language are incorrrect.</li>
<li>Run-time errors: Occur during a page's execution, even though the 
errors could not be detected at compile time.</li>
</ul>

By default, the information shown for a run-time error is the call
stack (the chains of procedure calls leading up to the exception).
If debug mode is enabled, ASP.NET displays the line number in source
code where the run-time error originated.  Debug mode is a valuable
tool for debugging your application.  You can enable debug mode
at the page level, using the following directive:

<pre class="code">
&lt;%@ Page Debug="true" %&gt;
</pre>

You can also enable debug mode at the application level, using the 
Web.config file in the application's root directory, as
shown in the following example.
<br /><br />

<b>Note:</b> Running debug mode incurs a heavy performance penalty.
Be sure to disable it before deploying your finished application.

<br /><br />
The following example demonstrates the use of debug mode to show 
source line numbers for a run-time exception.
By default, if you view this example from a remote computer, you
will not see debug information. To customize this example to allow
viewing from a remote computer, see the section below.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/monitoring/errors/errors_cs/error1.aspx"
        ViewSource="~/aspnet/samples/monitoring/errors/error1.src"
        Caption="C# Debug Mode"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/monitoring/errors/errors_vb/error1.aspx"
        ViewSource="~/aspnet/samples/monitoring/errors/error1.src"
        Caption="VB Debug Mode"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

<!--BEGIN SUB SECTION-->
<a name="custom"></a>
<h3>Customizing Error Pages</h3>

Depending on the circumstances, you might want to handle application
errors in different ways.  For example, at development time you
probably want to see the detailed error pages that ASP.NET provides
to help you identify and fix problems.  However, once an
application is being served in a production environment, you probably
do not want to display detailed errors to your customer clients.
You can use ASP.NET to specify whether errors are shown
to local clients, to remote clients, or to both. By default,
errors are shown only to local clients (those clients on the same
computer as the server).  You can also specify a custom error page
to redirect clients to if an error occurs.

<br /><br />

Custom errors are enabled in the Web.config file for an application. For example:

<pre class="code">
&lt;configuration&gt;
     &lt;system.web&gt;
         &lt;customErrors defaultRedirect="genericerror.htm" 
             mode="RemoteOnly" /&gt;
     &lt;/system.web&gt;
&lt;/configuration&gt;
</pre>

This configuration enables local clients to see the default ASP.NET
detailed error pages but redirects remote clients to a custom page, genericerror.htm.
This page could be an .aspx page as well. ASP.NET passes the path of the page
on which the error occurred to the error page as a
<b>QueryString</b> argument.  Note that if the execution of the
error page generates an error, a blank page is sent back to the
remote client.

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
&lt;%@ Page Language="C#" Description="Error page"%&gt;

&lt;html&gt;
&lt;head&gt;
&lt;title&gt;Error page&lt;/title&gt;
&lt;/head&gt;

&lt;body&gt;
&lt;h1&gt;Error page&lt;/h1&gt;
Error originated on: &lt;%=Request.QueryString["ErrorPage"] %&gt;
&lt;/body&gt;
&lt;/html&gt;
</Tab>
<Tab Name="VB">
&lt;%@ Page Language="VB" Description="Error page"%&gt;

&lt;html&gt;
&lt;head&gt;
&lt;title&gt;Error page&lt;/title&gt;
&lt;/head&gt;

&lt;body&gt;
&lt;h1&gt;Error page&lt;/h1&gt;
Error originated on: &lt;%=Request.QueryString("ErrorPage") %&gt;
&lt;/body&gt;
&lt;/html&gt;
</Tab>
</Acme:TabControl>

<br />

<b>Note:</b> Only files mapped to the aspnet_isapi.dll extension in IIS
generate these errors. Files not served through the aspnet_isapi.dll are
not processed by ASP.NET and generate IIS errors. See the IIS
documentation for information about configuring IIS custom errors.

<br /><br />

The following table describes the configuration attributes and
values for the <b>&lt;customErrors&gt;</b> tag.

<br /><br />

<table class="table">
<tr>
<th width="20%">Attribute</th><th width="100%">Description</th>
</tr>
<tr>
  <td>
    <b>mode</b>
  </td>
  <td>Indicates whether custom errors are enabled, disabled, or only
shown to remote computers. Values: <b>On</b>, <b>Off</b>, <b>RemoteOnly</b> (default).
</td>
</tr>
<tr>
  <td>
    <b>defaultRedirect</b>
  </td>
  <td>Indicates the default URL to which a browser should be redirected
if an error occurs.  This attribute is optional.
  </td>
</tr>
</table>

<br />

The <b>Mode</b> attribute determines whether errors are shown to
local clients, remote clients, or both.  The effects of each setting are
described in the following table.

<br /><br />

<table class="table">
<tr>
<th width="20%">Mode</th><th width="40%">Local host request</th>
<th width="40%">Remote host request</th>
</tr>
<tr>
  <td>
    <b>On</b>
  </td>
  <td>
     Custom error page.
  </td>
  <td>
     Custom error page.
  </td>
</tr>
<tr>
  <td>
    <b>Off</b>
  </td>
  <td>
     ASP.NET error page.
  </td>
  <td>
     ASP.NET error page.
  </td>
</tr>
<tr>
  <td>
    <b>RemoteOnly</b>
  </td>
  <td>
     ASP.NET error page.
  </td>
  <td>
     Custom error page.
  </td>
</tr>
</table>

<br />

The following sample demonstrates how the <b>&lt;customErrors&gt;</b>
configuration section is used.

<br /><br />


<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/monitoring/errors/custom1_cs/custom1.aspx"
        ViewSource="~/aspnet/samples/monitoring/errors/custom1.src"
        Caption="C# Custom Errors"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/monitoring/errors/custom1_vb/custom1.aspx"
        ViewSource="~/aspnet/samples/monitoring/errors/custom1.src"
        Caption="VB Custom Errors"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

In addition to redirecting to a common page for all errors, you can also
assign specific error pages to specific error status codes.
The <b>&lt;customErrors&gt;</b> configuration section supports an inner
<b>&lt;error&gt;</b> tag that associates HTTP status codes with
custom error pages. For example:

<pre class="code">
&lt;configuration&gt;
  &lt;system.web&gt;
    &lt;customErrors mode="RemoteOnly" defaultRedirect="/genericerror.htm"&gt;
      &lt;error statusCode="500" redirect="/error/callsupport.htm"/&gt;
      &lt;error statusCode="404" redirect="/error/notfound.aspx"/&gt;
      &lt;error statusCode="403" redirect="/error/noaccess.aspx"/&gt;
    &lt;/customErrors&gt;
  &lt;/system.web&gt;
&lt;/configuration&gt;
</pre>

The following table describes the attributes and values for the
<b>&lt;error&gt;</b> tag.

<br /><br />

<table class="table">
<tr>
<th width="20%">Attribute</th><th width="100%">Description</th>
</tr>
<tr>
  <td>
    <b>StatusCode</b>
  </td>
  <td>
HTTP status code of errors for which the custom error
page should be used.  Examples: 403 Forbidden, 404 Not Found, or
500 Internal Server Error.
</td>
</tr>
<tr>
  <td>
    <b>Redirect</b>
  </td>
  <td>
URL to which the client browser should be redirected if an error
occurs.
  </td>
</tr>
</table>

<br />

The following example demonstrates how to use the <b>&lt;error&gt;</b> tag.
Note that the example specifies an .aspx page for "File Not Found"
errors so that the missing page URL passed via the <b>QueryString</b> can be printed.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/monitoring/errors/custom2_cs/custom2.aspx"
        ViewSource="~/aspnet/samples/monitoring/errors/custom2.src"
        Caption="C# Error Tag"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/monitoring/errors/custom2_vb/custom2.aspx"
        ViewSource="~/aspnet/samples/monitoring/errors/custom2.src"
        Caption="VB Error Tag"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

<!--BEGIN SUB SECTION-->
<a name="handling"></a>
<h3>Handling Errors Programmatically</h3>

You can also handle errors in code, at either the page level or the
application level.  The <b>Page</b> base class exposes a
<b>Page_Error</b> method, which you can override in your pages.
The method is called whenever an uncaught exception is thrown at
run time.

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
&ltscript language="C#" runat="server"&gt;

void Page_Error(Object source, EventArgs e) {
    String message = "&lt;font face=verdana color=red&gt;"
        + "&lt;h4&gt;" + Request.Url.ToString() + "&lt;/h4&gt;"
        + "&lt;pre&gt;&lt;font color='red'&gt;" 
        + Server.GetLastError().ToString() + "&lt;/pre&gt;"
        + "&lt;/font&gt;";

    Response.Write(message);
}

&lt/script&gt;
</Tab>
<Tab Name="VB">
&ltscript language="C#" runat="server"&gt;

Sub Page_Error(Source As Object, E As EventArgs)
    Dim message As String = "&lt;font face=verdana color=red&gt;" _
        & "&lt;h4&gt;" & Request.Url.ToString() & "&lt;/h4&gt;" _
        & "&lt;pre&gt;&lt;font color='red'&gt;" _
        & Server.GetLastError().ToString() & "&lt;/pre&gt;" _
        & "&lt;/font&gt;"

    Response.Write(message)
End Sub

&lt/script&gt;
</Tab>
</Acme:TabControl>

<br />

The following sample demonstrates the <b>Page_Error</b> method.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/monitoring/errors/errors_cs/error2.aspx"
        ViewSource="~/aspnet/samples/monitoring/errors/error2.src"
        Caption="C# Page_Error Method"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/monitoring/errors/errors_vb/error2.aspx"
        ViewSource="~/aspnet/samples/monitoring/errors/error2.src"
        Caption="VB Page_Error Method"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

In addition to handling errors at the page level, you might want to
handle errors at the application level. To do this, use the
<b>Application_Error</b> event in <asp:HyperLink NavigateUrl="~/aspnet/doc/applications/globalasax.aspx" runat="server">Global.asax</asp:HyperLink>.
This event occurs for any unhandled exception thrown within the
application.

<br /><br />

<Acme:TabControl HtmlEncode runat="server">
<Tab Name="C#">
void Application_Error(Object sender, EventArgs e) {
    //...Do something here
}
</Tab>
<Tab Name="VB">
Sub Application_Error(sender As Object, e As EventArgs)
    '...Do something here
End Sub
</Tab>
</Acme:TabControl>

</asp:Content>

