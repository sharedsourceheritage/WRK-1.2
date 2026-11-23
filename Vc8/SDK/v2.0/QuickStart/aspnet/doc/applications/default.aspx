<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>

<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>


<h2>Understanding Applications and State</h2>

<div class="new">

<h3>What's New in 2.0</h3>

<ul>
  <li><b>Session State Extensibility - </b> Session State is now built upon a fully extensible, provider-based storage model. 
ASP.NET 2.0 ships with providers for in-process, out-of-process and Sql Server storage.  However developers can implement 
custom providers that work against other data stores by deriving from <code>SessionStateStoreProviderBase</code>.  The Session
State feature also allows developers to create custom session ID generators as well as custom HttpModules to use instead of 
the default <code>SessionStateModule</code>.  For scalability, the Sql Server and out-of-process Session State providers 
allow a developer to dynamically determine on a per-request basis the session state server that should load and store session 
data.  This allows session state data to be spread across multiple backend session state servers.
  </li>
  <br /><br />
  <li><b>Control State - </b> In addition to ViewState, controls can now use a ControlState dictionary for round-tripping
state information using the client.  The ControlState dictionary is intended to store limited size information that is 
critical to the functionality of the control, that should not be disabled when EnableViewState is false.</li>
  <br /><br />
  <li><b>Encrypted ViewState - </b> ASP.NET 2.0 enables encryption of ViewState through the Page directive's ViewStateEncryptionMode 
attribute.  This can be used to protect sensitive data that needs to be roundtripped in viewstate that should not be exposed
to the client user.  A common use for this feature might be to encrypt the DataKeyNames values from a GridView control.</li>
</ul>
This section discusses these and other application and state management features in ASP.NET 2.0.
</div>

<br /><br />

<!--BEGIN SECTION-->
<a name="what"></a>
<h3>What is an ASP.NET Application?</h3>

ASP.NET defines an application as the sum of all files, pages, handlers, modules, 
and executable code that can be invoked or run in the scope of a given virtual 
directory (and its subdirectories) on a Web application server.  For example, 
an "order" application might be published in the "/order" virtual directory on a 
Web server computer. For IIS the virtual directory can be set up in the Internet
Services Manager; it contains all subdirectories, unless the subdirectories are
virtual directories themselves.

<br /><br />

Each ASP.NET Framework application on a Web server is executed within 
a unique .NET Framework
application domain, which guarantees class isolation (no versioning or naming conflicts),
security sandboxing (preventing access to certain machine or network resources), 
and static variable isolation.

<br /><br />

ASP.NET maintains a pool of <b>HttpApplication</b> instances over the course of a Web 
application's lifetime. ASP.NET automatically assigns one of these instances to
process each incoming HTTP request that is received by the application.  
The particular <b>HttpApplication</b> instance assigned is responsible for managing
the entire lifetime of the request and is reused only after the request has
been completed. This means that user code within the <b>HttpApplication</b> does not
need to be reentrant.

<br /><br />

<!--BEGIN SECTION-->
<a name="creating"></a>
<h3>Creating an Application</h3>

To create an ASP.NET Framework application you can use an existing virtual directory or 
create a new one. For example, if you installed Windows 2000 Server including 
IIS, you probably have a directory C:\InetPub\WWWRoot. You can configure IIS
using the Internet Services Manager, available under 
Start <nobr>-></nobr> Programs <nobr>-></nobr> Administrative Tools. 
Right-click on an existing directory and choose either New (to create a new
virtual directory) or Properties (to promote an existing regular directory).

<br /><br />

By placing a simple .aspx page like the following in the virtual 
directory and accessing it with the browser, you trigger
the creation of the ASP.NET application.

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
&lt;%@Page Language="C#"%&gt;
&lt;html&gt;
&lt;body&gt;
&lt;h1&gt;hello world, &lt;% Response.Write(DateTime.Now.ToString()); %&gt;&lt;/h1&gt;
&lt;/body&gt;
&lt;/html&gt;
</Tab>

<Tab Name="VB">
&lt;%@Page Language="VB"%&gt;
&lt;html&gt;
&lt;body&gt;
&lt;h1&gt;hello world, &lt;% Response.Write(DateTime.Now.ToString()) %&gt;&lt;/h1&gt;
&lt;/body&gt;
&lt;/html&gt;
</Tab>

</Acme:TabControl>

<br />

Now you can add appropriate code to use
the <a href="state.aspx">Application</a> object--to store
objects with application scope, for example. By creating a 
<a href="globalasax.aspx">global.asax</a> file you also can 
define various event handlers--
for the <b>Application_Start</b> event, for example.

<!--BEGIN SECTION-->
<a name="lifetime"></a>
<h3>Lifetime of an Application</h3>

An ASP.NET Framework application is created the first time a 
request is made to the server; before
that, no ASP.NET code executes. When the first request is made, 
a pool of <b>HttpApplication</b>
instances is created and the <b>Application_Start</b> event 
is raised. The <b>HttpApplication</b> 
instances process this and subsequent requests, until the 
last instance exits and the 
<b>Application_End</b> event is raised.

<br /><br />

Note that the <b>Init</b> and <b>Dispose</b> methods of 
<b>HttpApplication</b> are called per instance and
thus can be called several times between <b>Application_Start</b> 
and <b>Application_End</b>. Only
these events are shared among all instances of <b>HttpApplication</b> 
in one ASP.NET application.

<!--BEGIN SECTION-->
<a name="multiplethreads"></a>
<h3>A Note on Multiple Threads</h3>

If you use objects with application scope, you should be aware that
ASP.NET processes requests concurrently and that the <b>Application</b> object can be 
accessed by multiple threads. Therefore the following code is dangerous and might
not produce the expected result, if the page is repeatedly requested by
different clients at the same time.

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
&lt;%
Application["counter"] = (Int32)Application["counter"] + 1;
%&gt;
</Tab>

<Tab Name="VB">
&lt;%
Application("counter") = CType(Application("counter"), Int32) + 1
%&gt;
</Tab>

</Acme:TabControl>

<br />

To make this code thread safe, serialize the access to the 
<b>Application</b> object using
the <b>Lock</b> and <b>UnLock</b> methods. However, doing so 
also means accepting a considerable 
performance hit.  Another solution is to make the object stored with an application scope
thread safe. 

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
&lt;%
Application.Lock();
Application["counter"] = (Int32)Application["counter"] + 1;
Application.UnLock();
%&gt;
</Tab>

<Tab Name="VB">
&lt;%
Application.Lock()
Application("counter") = CType(Application("counter"), Int32) + 1
Application.UnLock()
%&gt;
</Tab>

</Acme:TabControl>

<br />
The HttpApplicationState collection used above is primarily 
meant for backward-compatibility with classic ASP and will be familiar to ASP developers.
However, the use of static fields in ASP.NET is generally preferred over the use of HttpApplicationState.
<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
&lt;script language="C#" runat="server"&gt;
  public static int counter;
&lt;/script&gt;

&lt;%
System.Threading.Interlocked.Increment( ref counter );
%&gt;
</Tab>

<Tab Name="VB">
&lt;script language="VB" runat="server"&gt;
  Public Shared counter As Integer
&lt;/script&gt;

&lt;%
System.Threading.Interlocked.Increment( counter )
%&gt;
</Tab>

</Acme:TabControl>

</asp:Content>

