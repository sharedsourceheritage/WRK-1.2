<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>

<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>


<h2>Managing State</h2>

State management is an important aspect of any Web application.  Because state information is lost between
subsequent requests, ASP.NET provides a variety of way to preserve state both server-side and client-side, 
when your application or controls need to round-trip information across requests.  This section demonstrates
some of the available state management features.

<!--BEGIN SECTION-->
<a name="applicationstate"></a>
<h3>Using Application State</h3>

This sample illustrates the use of application state to read a dataset in
<b>Application_Start</b>.  The HttpApplicationState collection used above is primarily meant 
for backward-compatibility with classic ASP and will be familiar to ASP developers. However, 
the use of static fields in ASP.NET is generally preferred over the use of HttpApplicationState. 

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/applications/application_cs/application.aspx"
        ViewSource="~/aspnet/samples/applications/application.src"
        Caption="C# Application State"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/applications/application_vb/application.aspx"
        ViewSource="~/aspnet/samples/applications/application.src"
        Caption="VB Application State"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

Because an application and all the objects it stores can be concurrently accessed
by different threads, it is better to store only infrequently modified data with
application scope. Ideally an object is initialized in the <b>Application_Start</b> event
and further access is read-only.

<br /><br />

In the following sample a file is read in <b>Application_Start</b> (defined in the Global.asax file)
and the content is stored in a <b>DataView</b> object in the application state.

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
void Application_Start() {
    DataSet ds = new DataSet();

    FileStream fs = new FileStream(Server.MapPath("schemadata.xml"),
        FileMode.Open,FileAccess.Read);
    StreamReader reader = new StreamReader(fs);
    ds.ReadXml(reader);
    fs.Close();

    DataView view = new DataView(ds.Tables[0]);
    Application["Source"] = view;
}
</Tab>

<Tab Name="VB">
Sub Application_Start()
    Dim ds As New DataSet()

    Dim fs As New FileStream(Server.MapPath("schemadata.xml"),
        FileMode.Open,FileAccess.Read)
    Dim reader As New StreamReader(fs)
    ds.ReadXml(reader)
    fs.Close()

    Dim view As New DataView (ds.Tables(0))
    Application("Source") = view
End Sub
</Tab>

</Acme:TabControl>

<br />

In the <b>Page_Load</b> method, the <b>DataView</b> is then retrieved and used to populate a <b>GridView</b> object:

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
void Page_Load(Object sender, EventArgs e) {
    DataView Source = (DataView)(Application["Source"]);
    ...
    MyGridView.DataSource = Source;
    ...
}
</Tab>

<Tab Name="VB">
Sub Page_Load(sender As Object, e As EventArgs)
    Dim Source As New DataView  = CType(Application("Source"), DataView)
    ...
    MyGridView.DataSource = Source
    ...
End Sub
</Tab>

</Acme:TabControl>

<br />

The advantage of this solution is that only the first request pays the price of retrieving
the data. All subsequent requests use the already existing <b>DataView</b> object. As the
data is never modified after initialization, you do not have to make any provisions for serializing access.

<!--BEGIN SECTION-->
<a name="sessionstate"></a>
<h3>Using Session State</h3>

The following sample illustrates the use of session state to store volatile user preferences.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/applications/session_cs/session.aspx"
        ViewSource="~/aspnet/samples/applications/session.src"
        Caption="C# Session State"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/applications/session_vb/session.aspx"
        ViewSource="~/aspnet/samples/applications/session.src"
        Caption="VB Session State"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

To provide individual data for a user during a session, data can be stored
with session scope. In the following sample, values for user preferences are initialized
in the <b>Session_Start</b> event in the Global.asax file. 

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
void Session_Start() {
    Session["BackColor"] = "beige";
    ...
}
</Tab>

<Tab Name="VB">
Sub Session_Start()
    Session("BackColor") = "beige"
    ...
End Sub
</Tab>

</Acme:TabControl>

<br />

In the following
customization page, values for user preferences are modified in the <b>Submit_Click</b> event handler according to user input.

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
protected void Submit_Click(Object sender, EventArgs e) {
    Session["BackColor"] = BackColor.Value;
    ...

    Response.Redirect(State["Referer"].ToString());
}
</Tab>

<Tab Name="VB">
Protected Sub Submit_Click(sender As Object, e As EventArgs)
    Session("BackColor") = BackColor.Value
    ...

    Response.Redirect(State("Referer").ToString())
End Sub
</Tab>

</Acme:TabControl>

<br />

The individual values are retrieved using the <b>GetStyle</b> method:

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
protected String GetStyle(String key) {
    return Session[key].ToString();
}
</Tab>

<Tab Name="VB">
Protected GetStyle(key As String) As String
    Return(Session(key).ToString())
End Sub
</Tab>

</Acme:TabControl>

<br />

The <b>GetStyle method</b> is used to construct session-specific styles:

<pre class="code">
&lt;style&gt;
    body
    {
      font: &lt;%=GetStyle("FontSize")%&gt; &lt;%=GetStyle("FontName")%&gt;;
      background-color: &lt;%=GetStyle("BackColor")%&gt;;
    }
    a
    {
        color: &lt;%=GetStyle("LinkColor")%&gt;
    }
&lt;/style&gt;
</pre>

To verify that the values are really stored with session scope,
open the sample page twice, then change one value in the first
browser window and refresh the second one. The second window
picks up the changes because both browser instances share a
common <b>Session</b> object.

<br /><br />

<b>Configuring session state:</b>
Session state features can be configured via the <b>&lt;sessionState&gt;</b>
section in a web.config file. To double the default timeout of
20 minutes, you can add the following to the web.config file of an
application:

<pre class="code">
&lt;sessionState
  timeout="40"
/&gt;
</pre>

If cookies are not available, a session can be tracked
by adding a session identifier to the URL. This can be enabled by setting
the following:

<pre class="code">
&lt;sessionState
  cookieless="true"
/&gt;
</pre>

By default, ASP.NET will store the session state in the same process that processes the request, just as ASP does. Additionally, ASP.NET can
store session data in an external process, which can even reside
on another machine. To enable this feature:

<ul>
<li>Start the ASP.NET state service, either using the Services snap-in or by
executing "net start aspnet_state" on the command line. The state service
will by default listen on port 42424.  To change the port, modify the
registry key for the service:
HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Services\aspnet_state\Parameters\Port
<li>Set the <b>mode</b> attribute of the <b>&lt;sessionState&gt;</b> section to "StateServer".
<li>Configure the <b>stateConnectionString</b> attribute with the values of the
machine on which you started aspnet_state.
</ul>

The following sample assumes that the state service is running
on the same machine as the Web server ("localhost") and uses the default
port (42424):

<pre class="code">
&lt;sessionState
  mode="StateServer"
  stateConnectionString="tcpip=localhost:42424"
/&gt;
</pre>

Note that if you try the sample above with this setting, you can reset
the Web server (enter <code>iisreset</code> on the command line) and the session state
value will persist.

<!--BEGIN SECTION-->
<a name="cookies"></a>
<h3>Using Client-Side Cookies</h3>

The following sample illustrates the use of client-side cookies to store volatile user preferences.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/applications/cookies1_cs/cookies1.aspx"
        ViewSource="~/aspnet/samples/applications/cookies1.src"
        Caption="C# Cookies"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/applications/cookies1_vb/cookies1.aspx"
        ViewSource="~/aspnet/samples/applications/cookies1.src"
        Caption="VB Cookies"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

Storing cookies on the client is one of the methods that ASP.NET's session
state uses to associate requests with sessions. Cookies can also be used
directly to persist data between requests, but the data is then stored
on the client and sent to the server with every request. Browsers place
limits on the size of a cookie; therefore, only a maximum of 4096 bytes is guaranteed
to be acceptable.

<br /><br />

When the data is stored on the client, the <b>Page_Load</b> method in the file
cookies1.aspx checks whether the client has sent a cookie. If not, a new
cookie is created and initialized and stored on the client:

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
protected void Page_Load(Object sender, EventArgs e) {
    if (Request.Cookies["preferences1"] == null) {
        HttpCookie cookie = new HttpCookie("preferences1");
        cookie.Values.Add("ForeColor", "black");
        ...
        Response.Cookies.Add(cookie);
    }
}
</Tab>

<Tab Name="VB">
Protected Sub Page_Load(sender As Object, e As EventArgs)
    If Request.Cookies("preferences1") = Null Then
        Dim cookie As New HttpCookie("preferences1")
        cookie.Values.Add("ForeColor", "black")
        ...
        Response.Cookies.Add(cookie)
    End If
End Sub
</Tab>

</Acme:TabControl>

<br />

On the same page, a <b>GetStyle</b> method is used again to provide
the individual values stored in the cookie:

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
protected String GetStyle(String key) {
  HttpCookie cookie = Request.Cookies["preferences1"];
  if (cookie != null) {
    switch (key)
    {
      case "ForeColor" : return cookie.Values["ForeColor"]; break;
      ...
    }
  }
  return "";
}
</Tab>

<Tab Name="VB">
Protected Function GetStyle(key As String) As String
  Dim cookie As HttpCookie = Request.Cookies("preferences1")
  If cookie <> Null Then
    Select Case key
      Case "ForeColor"
        Return(cookie.Values("ForeColor"))
      Case ...
    End Select
  End If
  Return("")
End Function
</Tab>

</Acme:TabControl>

<br /><br />

Verify that the sample works by opening the cookies1.aspx page and modifying
the preferences. Open the page in another window, it should pick up the new
preferences. Close all browser windows and open the cookies1.aspx page again.
This should delete the temporary cookie and restore the default preference values.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/applications/cookies2_cs/cookies2.aspx"
        ViewSource="~/aspnet/samples/applications/cookies2.src"
        Caption="C# Cookies (Persistent)"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/applications/cookies2_vb/cookies2.aspx"
        ViewSource="~/aspnet/samples/applications/cookies2.src"
        Caption="VB Cookies (Persistent)"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

To make a cookie persistent between sessions, the <b>Expires</b> property on
the <b>HttpCookie</b> class has to be set to a date in the future. The following
code on the customization.aspx page is identical to the previous sample,
with the exception of the assignment to <b>Cookie.Expires</b>:

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
protected void Submit_Click(Object sender, EventArgs e) {
    HttpCookie cookie = new HttpCookie("preferences2");
    cookie.Values.Add("ForeColor",ForeColor.Value);
    ...
    cookie.Expires = DateTime.MaxValue; // Never Expires

    Response.Cookies.Add(cookie);

    Response.Redirect(State["Referer"].ToString());
}
</Tab>

<Tab Name="VB">
Protected Sub Submit_Click(sender As Object, e As EventArgs)
    Dim cookie As New HttpCookie("preferences2")
    cookie.Values.Add("ForeColor",ForeColor.Value)
    ...
    cookie.Expires = DateTime.MaxValue ' Never Expires

    Response.Cookies.Add(cookie)

    Response.Redirect(State("Referer").ToString())
End Sub
</Tab>

</Acme:TabControl>

<br />

Verify that the sample is working by modifying a value, closing all browser
windows, and opening cookies2.aspx again. The window should still show the
customized value.

<!--BEGIN SECTION-->
<a name="viewstate"></a>
<h3>Using View State</h3>

This sample illustrates the use of the <b>ViewState</b> property to store request-specific values.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/applications/viewstate_cs/viewstate.aspx"
        ViewSource="~/aspnet/samples/applications/viewstate.src"
        Caption="C# View State"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/applications/viewstate_vb/viewstate.aspx"
        ViewSource="~/aspnet/samples/applications/viewstate.src"
        Caption="VB View State"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

ASP.NET provides the server-side notion of a view state for each control. A control can save its
internal state between requests using the <b>ViewState</b> property on an instance of the class <b>StateBag</b>. The
<b>StateBag</b> class provides a dictionary-like interface to store objects associated with a string key.

<br /><br />

The file pagestate1.aspx displays one visible panel and stores the index of it in the view
state of the page with the key <b>PanelIndex</b>:

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
protected void Next_Click(Object sender, EventArgs e ) {
    String PrevPanelId = "Panel" + ViewState["PanelIndex"].ToString();
    ViewState["PanelIndex"] = (int)ViewState["PanelIndex"] + 1;
    String PanelId = "Panel" + ViewState["PanelIndex"].ToString();
    ...
}
</Tab>

<Tab Name="VB">
Protected Sub Next_Click(sender As Object, e As EventArgs)
    Dim PrevPanelId As String = "Panel" + ViewState("PanelIndex").ToString()
    ViewState("PanelIndex") = CType(ViewState("PanelIndex") + 1, Integer)
    Dim PanelId As String = "Panel" + ViewState("PanelIndex").ToString()
    ...
End Sub
</Tab>

</Acme:TabControl>

<br />

Note that if you open the page in several browser windows, each browser window will
initially show the name panel. Each window can independently navigate between the panels.

</asp:Content>

