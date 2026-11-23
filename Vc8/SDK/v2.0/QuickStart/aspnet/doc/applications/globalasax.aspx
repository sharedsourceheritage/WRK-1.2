<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>

<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>


<h2>Using the Global.asax File</h2>

In addition to writing UI code, developers can also add application level
logic and event handling code into their Web applications. This code does not
handle generating UI and is typically not invoked in response to individual
page requests.  Instead, it is responsible for handling higher-level application
events  such as <b>Application_Start</b>, <b>Application_End</b>, <b>Session_Start</b>,
<b>Session_End</b>,  and so on. Developers author this logic using a <b>Global.asax</b> file located
at the root of a particular Web application's virtual directory tree.
ASP.NET automatically parses and compiles this file into a dynamic .NET Framework class--which extends the <b>HttpApplication</b> base class--the first time any resource or URL
within the application namespace is activated or requested.

<br /><br />

The Global.asax file is parsed and dynamically compiled by ASP.NET into a .NET Framework class
the first time any resource or URL within its application namespace is activated
or requested. The Global.asax file is configured to automatically reject any direct URL
request so that external users cannot download or view the code within.

<br /><br />

<!--BEGIN SECTION-->
<a name="events"></a>
<h3>Application or Session-Scoped Events</h3>

Developers can define handlers for events of the <b>HttpApplication</b> base class by
authoring methods in the Global.asax file that conform to the naming pattern
"Application_EventName(AppropriateEventArgumentSignature)". For example:

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
&lt;script language="C#" runat="server">

void Application_Start(object sender, EventArgs e) {
  // Application startup code goes here
}
&lt;/script>
</Tab>

<Tab Name="VB">
&lt;script language="VB" runat="server">

Sub Application_Start(Sender As Object, E As EventArgs)
  ' Application startup code goes here
End Sub
&lt;/script>
</Tab>

</Acme:TabControl>

<br />

If the event handling code needs to import additional namespaces, the <b>@ import</b>
directive can be used on an .aspx page, as follows:

<pre class="code">
&lt;%@ Import Namespace="System.Text" %>
</pre>

The following sample illustrates the lifetime of <b>Application</b>,
<b>Session</b>, and <b>Request</b>.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/applications/globalasax_cs/globalasax.aspx"
        ViewSource="~/aspnet/samples/applications/globalasax.src"
        Caption="C# Global.asax"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/applications/globalasax_vb/globalasax.aspx"
        ViewSource="~/aspnet/samples/applications/globalasax.src"
        Caption="VB Global.asax"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

The first time the page is opened, the <b>Start</b> event is raised for the application and the session:

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
void Application_Start(object sender, EventArgs e) {
  // Application startup code goes here
}

void Session_Start(object sender, EventArgs e) {
  Response.Write("Session is Starting...&lt;br&gt;");
  Session.Timeout = 1;
}
</Tab>

<Tab Name="VB">
Sub Application_Start(Sender As Object, E As EventArgs)
  ' Application startup code goes here
End Sub

Sub Session_Start(Sender As Object, E As EventArgs)
  Response.Write("Session is Starting...&lt;br&gt;")
  Session.Timeout = 1
End Sub
</Tab>

</Acme:TabControl>

<br />

The <b>BeginRequest</b> and <b>EndRequest</b> events are raised on each request.
When the page is refreshed, only messages from <b>BeginRequest</b>, <b>EndRequest</b>, and
the <b>Page_Load</b> method will appear. Note that by abandoning the current
session (click the "End this session" button) a new session is created
and the <b>Session_Start</b> event is raised again.

<!--BEGIN SECTION-->
<a name="staticobjects"></a>
<h3>Application or Session-Scoped Objects</h3>

Static objects, .NET Framework classes, and COM components all can be defined in
the Global.asax file using the object tag. The scope can be <b>appinstance</b>, <b>session</b>, or
<b>application</b>. The <b>appinstance</b> scope denotes that the object is specific to one
instance of <b>HttpApplication</b> and is not shared.

<pre class="code">
&lt;object id="id" runat="server" class=".NET Framework class Name" scope="appinstance"/&gt;
&lt;object id="id" runat="server" progid="COM ProgID" scope="session"/&gt;
&lt;object id="id" runat="server" classid="COM ClassID" scope="application"/&gt;
</pre>

</asp:Content>

