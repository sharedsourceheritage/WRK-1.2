<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>

<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>


<h2>HTTP Handlers and Factories</h2>

ASP.NET provides a low-level request/response API that enables developers to use
.NET Framework classes to service incoming HTTP requests. Developers accomplish
this by authoring classes that support the <b>System.Web.IHTTPHandler</b> interface
and implement the <b>ProcessRequest()</b> method.  Handlers are often useful when
the services provided by the high-level page framework abstraction are not required
for processing the HTTP request.  Common uses of handlers include filters and
CGI-like applications, especially those that return binary data.

<br /><br />

Each incoming HTTP request received by ASP.NET is ultimately processed by a specific
instance of a class that implements <b>IHTTPHandler</b>. <b>IHttpHandlerFactory</b> provides the infrastructure
that handles the actual resolution of URL requests to <b>IHttpHandler</b> instances.
In addition to the default <b>IHttpHandlerFactory</b> classes provided by ASP.NET, developers can optionally create and register
factories to support rich request resolution and activation scenarios.

<!--BEGIN SECTION-->
<a name="configure"></a>
<h3>Configuring HTTP Handlers and Factories</h3>

HTTP handlers and factories are declared in the ASP.NET configuration as part
of a web.config file. ASP.NET defines an <b>&lt;httphandlers&gt;</b> configuration section
where handlers and factories can be added and removed. Settings for
<b>HttpHandlerFactory</b> and <b>HttpHandler</b> are inherited by subdirectories.

<br /><br />

For example, ASP.NET maps all requests for .aspx files to the <b>PageHandlerFactory</b> class in
the global machine.config file:

<pre class="code">
&lt;httphandlers&gt;
  ...
  &lt;add verb="*" path="*.aspx" type="System.Web.UI.PageHandlerFactory,System.Web" /&gt;
  ...
&lt;/httphandlers&gt;
</pre>

<!--BEGIN SECTION-->

<a name="customhandler"></a>
<h3>Creating a Custom HTTP Handler</h3>

The following sample creates a custom <b>HttpHandler</b>  that handles
all requests to "SimpleHandler.axd".

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/applications/handler_cs/simplehandler.axd"
        ViewSource="~/aspnet/samples/applications/handler.src"
        Caption="C# Simple HttpHandler"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/applications/handler_vb/simplehandler.axd"
        ViewSource="~/aspnet/samples/applications/handler.src"
        Caption="VB Simple HttpHandler"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

A custom HTTP handler can be created by implementing the <b>IHttpHandler</b>
interface, which contains only two methods. By calling <b>IsReusable</b>, an
HTTP factory can query a handler to determine whether the same instance can be used to service multiple requests. The
<b>ProcessRequest</b> method takes an <b>HttpContext</b> instance as a parameter, which
gives it access to the <b>Request</b> and <b>Response</b> intrinsics.
In the following sample, request data is ignored and a constant
string is sent as a response to the client.

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
public class SimpleHandler : IHttpHandler {
  public void ProcessRequest(HttpContext context) {
    context.Response.Write("Hello World!");
  }

  public bool IsReusable {
    get {
      return true;
    }
  } 

}
</Tab>

<Tab Name="VB">
Public Class SimpleHandler : Inherits IHttpHandler
  Public Sub ProcessRequest(context As HttpContext)
    context.Response.Write("Hello World!")
  End Sub

  Public Function IsReusable() As Boolean
    Return(True)
  End Function
End Class
</Tab>

</Acme:TabControl>

<br />

After placing the handler class definition in the application's \App_Code directory,
the handler class can be specified as a target for requests. In this case, all
requests for "SimpleHandler.axd" will be routed to an instance of the
<b>SimpleHandler</b> class, which lives in the namespace <code>Acme</code>.

<pre class="code">
&lt;httphandlers&gt;
  &lt;add verb="*" path="SimpleHandler.axd" type="Acme.SimpleHandler" /&gt;
&lt;/httphandlers&gt;
</pre>

</asp:Content>

