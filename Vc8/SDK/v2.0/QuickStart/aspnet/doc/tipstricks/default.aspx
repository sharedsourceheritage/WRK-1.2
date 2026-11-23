<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Tips and Tricks</h2>

<div class="new">

<h3>What's New in 2.0</h3>

<ul>
  <li><b>Cross Page Posting - </b> ASP.NET 2.0 allows you to post back from one page to another and you can obtain the source page values from the target page.</li>
  <li><b>Wizard Control - </b> The wizard control allows you to easily add multi-step form entry scenarios to your pages.</li>
  <li><b>Validation Groups - </b> Validation groups allow multiple forms on a page to be separately validated.</li>
  <li><b>Focus API - </b> The Focus API enables you to set focus to any control on the page, specify default buttons to submit for input controls, and more.</li>
  <li><b>Compilation Build Providers - </b> ASP.NET 2.0 includes support for compiling declarative file formats when they are placed in the App_Code directory.</li>
  <li><b>No Compile Pages - </b> Pages in ASP.NET 2.0 can be excluded from the compilation process, to be interpreted at runtime instead.</li>
  <li><b>Securing Non-ASP.NET content - </b> Under IIS 6, you can easily secure non-ASP.NET files such as static images or classic ASP pages from within an ASP.NET application.</li>
  <li><b>Client-Script Features - </b> ASP.NET 2.0 includes several new features that take advantage of client-side script.</li>
</ul>

This section describes tips and tricks for using several new features in ASP.NET 2.0.
</div>

<br />

<a name="crosspagepostback"></a>
<h3>Cross Page PostBack</h3>

By default, button controls in ASP.NET pages post back to the same page that contains the button,
where you can write an event handler for the post.  In most cases this is the desired behavior, but
occassionaly you will also want to be able to post to another page in your application. The 
<b>Server.Transfer</b> method can be used to move between pages, however the URL doesn't change. 
Instead, the cross page posting feature in ASP.NET 2.0 allows you to fire a normal postback to a different page in 
the application.  In the target page, you can then access the values of server controls in the source page that initiated the post back.
<br /><br />

To use cross page posting, you can set the <b>PostBackUrl</b> property of a <b>Button, LinkButton or ImageButton </b> control, which specifies the target 
page.  In the target page, you can then access the <b>PreviousPage</b> property to retrieve values from the source page.
By default, the PreviousPage property is of type <b>Page</b>, so you must access controls using
the <b>FindControl</b> method.  You can also enable strongly-typed access to the source page by setting the 
<b>@PreviousPageType</b> directive in the target page to the virtual path or Type name of the source page.
Note that if you intend for multiple pages to post to a single target page, you cannot use the
strongly-typed accessor (leave the PreviousPage directive unset).
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../aspnet/samples/tipstricks/CrossPagePostBack_cs.aspx"
        ViewSource="~/aspnet/samples/tipstricks/CrossPagePostBack.src"
        Caption="C# Cross Page PostBack"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../aspnet/samples/tipstricks/CrossPagePostBack_vb.aspx"
        ViewSource="~/aspnet/samples/tipstricks/CrossPagePostBack.src"
        Caption="VB Cross Page PostBack"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

Cross page posting works by the following technique:

<ul>
    <li>Cross page posting sets action of the form in Page 1</li>
    <li>When the Button is clicked, the post goes from Page 1 to Page 2</li>
    <li>Page 2 retains viewstate from Page 1</li>
    <li>When PreviousPage accessed, viewstate is re-populated to an instance of Page 1</li>
    <li>Page 1 then executes up to its LoadComplete phase (excludes rendering)</li>
    <li>At this point, Page 2 may access the values of controls in Page 1</li>
</ul>

Because Page 1 will execute (up to LoadComplete) in response to a cross-page post, 
it is sometimes necessary to special-case code in the page to only execute when the request
is not a cross-page post, but a normal request to Page 1 instead.  You may use the <b>IsCrossPagePostBack</b>
property in Page 1 to handle this situation.
<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
if (!Page.IsCrossPagePostBack) {
    // handle a normal request
}
</Tab>
<Tab Name="VB">
If Not Page.IsCrossPagePostBack Then
    ' handle a normal request
End If
</Tab>
</Acme:TabControl>
<br />

You can also post back to another application, however the <b>PreviousPage</b> property is null in this case.
You can also transfer in code, while still preserving viewstate through the PreviousPage property using <code>Server.Transfer(IHttpHandler, preserveViewState)</code>.
<br /><br />

<a name="wizardcontrol"></a>
<h3>Wizard Control</h3>

The <b>Wizard</b> control is used to create a multi-step form entry process in a web page. 
To specify the individual steps , place a <b>WizardStep</b> object for each entry between the opening and closing tags of the <b>WizardSteps</b> element of the Wizard control.
There are many benefits to the Wizard control:
<p />

<ul>
<li>Easily enable multi-step forms and data collection</li>
<li>Handles all aspects of navigation, linear or non-linear</li>
<li>Enables commit-at-finish or commit-as-you-go (AllowReturn=false)</li>
<li>Controls automatically retain viewstate across posts to different steps</li>
<li>Can use built-in UI, or customize through properties or templates</li>
</ul>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../aspnet/samples/tipstricks/Wizard_cs.aspx"
        ViewSource="~/aspnet/samples/tipstricks/Wizard.src"
        Caption="C# Wizard Control"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../aspnet/samples/tipstricks/Wizard_vb.aspx"
        ViewSource="~/aspnet/samples/tipstricks/Wizard.src"
        Caption="VB Wizard Control"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="validationgroups"></a>
<h3>Validation Groups</h3>

You can use the <b>ValidationGroup</b> property when you want to perform separate validation scenarios on the same page.
Set the group name on validator controls and on the button or other postback control that causes validation.  This is useful with <b>Wizard</b> control, <b>MultiView</b> or data controls (for editing scenarios).
To enable validation groups, set this property to the same value for all validators that should belong to a common group.  On a <b>Button</b> control in the form with <b>CausesValidation</b>
set to true, you also set the ValidationGroup property to the name of the group that should be validated when the Button is clicked.

By default all validators are in the "" group (default group), for backward compatibility. The
<b>Page</b> object also exposes a <b>GetValidators("group")</b> method and <b>Validate("group")</b> method for
retrieving a collection of validators in a specific group.
<b>Page.IsValid</b> reflects validity of all controls (cumulative) that have had <b>Validate</b> called.
<br /><br />

The example below demonstrates the ValidationGroup property.  To view the behavior, click the first (Search) button in the 
page, then click the second button on the page.  Notice that a different set of validators fires for each click.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../aspnet/samples/tipstricks/ValidationGroup_cs.aspx"
        ViewSource="~/aspnet/samples/tipstricks/ValidationGroup.src"
        Caption="C# Validation Groups"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../aspnet/samples/tipstricks/ValidationGroup_vb.aspx"
        ViewSource="~/aspnet/samples/tipstricks/ValidationGroup.src"
        Caption="VB Validation Groups"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="focusapi"></a>
<h3>Focus API and DefaultButton</h3>


The Focus API allows you to declaratively or programmatically set focus to specific controls on the form.  You can use the <b>Page.SetFocus</b> method to pass the ID of a control
that should receive focus or you can call the <b>Focus</b> method on the control directly.  
You can also set the <b>DefaultFocus</b> property of the Form element to the ID of a control that should receive focus when the page is first loaded.
Similar to DefaultFocus, you can set the <b>DefaultButton</b> property of the Form element to the ID of a <b>Button</b> control that should submit when the Enter
key is pressed inside of any input control on the form.  If your page should have different default buttons depending on the input control that has current focus, 
you can wrap specific input controls in a <b>Panel</b> control and set the DefaultButton property of the Panel instead.  Any input control in the Panel will use
the Panel's DefaultButton property to submit the form when the Enter key is pressed from within the input control.
A validation feature that depends on the Focus API is <b>SetFocusOnError</b> which is set on validator controls to cause the first invalid control to receive focus.
The following example shows the Focus API, DefaultButton, DefaultFocus, and SetFocusOnError features in use on a single form.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../aspnet/samples/tipstricks/FocusAPI_cs.aspx"
        ViewSource="~/aspnet/samples/tipstricks/FocusAPI.src"
        Caption="C# Focus API, DefaultButton, DefaultFocus, and SetFocusOnError"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../aspnet/samples/tipstricks/FocusAPI_vb.aspx"
        ViewSource="~/aspnet/samples/tipstricks/FocusAPI.src"
        Caption="VB Focus API, DefaultButton, DefaultFocus, and SetFocusOnError"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

For composite controls, the Focus method sets focus to the first
focusable control in the composite control rendering by default, but individual controls can override this behavior to set focus to another element.  
This example shows the focus given to the first input control in a DetailsView when the Focus method is
called when the DetailsView is in edit mode.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../aspnet/samples/tipstricks/DetailsViewFocus_cs.aspx"
        ViewSource="~/aspnet/samples/tipstricks/DetailsViewFocus.src"
        Caption="C# DetailsView Focus"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../aspnet/samples/tipstricks/DetailsViewFocus_vb.aspx"
        ViewSource="~/aspnet/samples/tipstricks/DetailsViewFocus.src"
        Caption="VB DetailsView Focus"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

<a name="buildproviders"></a>
<h3>Compilation Build Providers</h3>

A compilation build provider in ASP.NET 2.0 is a type that is registered to "compile" or "build" a declarative
file format into something that can be used from your pages.  A build provider is registered in configuration and is associated to a specific
file extension.  When files having this extension are placed into the App_Code directory, ASP.NET invokes the 
registered build provider to compile the file.  ASP.NET 2.0 includes support for several compilation
build providers out-of-the-box or you can also create and register your own types (refer to the 
<asp:HyperLink NavigateUrl="~/aspnet/doc/extensibility.aspx" runat="server">Extending ASP.NET</asp:HyperLink>
section for more information.  In addition to standard class files in various languages, the following declarative
types can be automatically compiled in ASP.NET:

<ul>
  <li>.wsdl - builds a Web Service proxy object
  <li>.resx - builds a resources file that can be used for localization
  <li>.xsd - builds a strongly-typed DataSet object
</ul>

<a name="nocompilepages"></a>
<h3>No Compile Pages</h3>

No Compile Pages enables improved scaling for large sites with 1000s of pages, 
as windows has limit on number of DLLs loaded into an app and perf degrades as you hit this limit. 
Set <code>&lt;%@ Page CompilationMode="Auto" %&gt;</code> directive to compile conditionally to obtain the
scaling benefits without limitations on code.  You can also set CompilationMode to "Never" to prevent the page from
ever being compiled.  You can set this property on the <code>&lt;pages/&gt;</code> section in Web.config
to apply to all pages in an application.
A no-compile page will throw an error when it contains user code.  However, you may still use
declarative ASP.NET syntax such as data bindings (<code>&lt;%# Eval %&gt;</code> and <code>&lt;%#Bind %&gt;</code> only) and 
expressions, such as <code>&lt;%$ ConnectionStrings:Pubs %&gt;</code>.  
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../aspnet/samples/tipstricks/NoCompile_cs.aspx"
        ViewSource="~/aspnet/samples/tipstricks/NoCompile.src"
        Caption="C# NoCompile page"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../aspnet/samples/tipstricks/NoCompile_vb.aspx"
        ViewSource="~/aspnet/samples/tipstricks/NoCompile.src"
        Caption="VB NoCompile page"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

The <b>CompilationMode</b> property only applies to pages,
but you can still use types from within the Code directory (for example base classes for pages).  If 
you prefer for no-compile pages to be excluded access to compiled types from the Code directory, 
lock this directory down in configuration.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../aspnet/samples/tipstricks/NoCompileBase_cs.aspx"
        ViewSource="~/aspnet/samples/tipstricks/NoCompileBase.src"
        Caption="C# NoCompile page with a base class"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../aspnet/samples/tipstricks/NoCompileBase_vb.aspx"
        ViewSource="~/aspnet/samples/tipstricks/NoCompileBase.src"
        Caption="VB NoCompile page with a base class"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

A complementary feature is the pre-compile tool, aspnet_compiler.exe, which allows you to pre-compile an
entire site using a command-line tool, to protect your intellectual property (code) in pages and enable
deployment without an initial compilation hit.

<%--

<a name="fileprovider"></a>
<h3>File Provider</h3>
<br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../aspnet/samples/tipstricks/FileProvider/Default.aspx"
        ViewSource="~/aspnet/samples/tipstricks/FileProvider.src"
        Caption="C# File Provider"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../aspnet/samples/tipstricks/FileProvider/Default.aspx"
        ViewSource="~/aspnet/samples/tipstricks/FileProvider.src"
        Caption="VB File Provider"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

--%>

<a name="securingnonaspnetcontent"></a>
<h3>Securing Non-ASP.NET Files</h3>

ASP.NET handles requests for file extensions that are normally associated with ASP.NET, while IIS handles requests for all other file extensions.  By default this
means common file extensions such as .aspx and .asmx are processed by ASP.NET.  This processing includes authentication and authorization to ASP.NET files.  Sometimes 
though, a developer wants non-ASP.NET resources to be processed by ASP.NET.  One reason for processing non-ASP.NET files through ASP.NET is to allow ASP.NET 
authentication and authorization to control access to these types of files.
<br /><br />
The combination of IIS6 on Windows Server 2003 and ASP.NET 2.0 provides the most flexibility for running the ASP.NET pipeline as part of processing a request for a 
non-ASP.NET resource.  IIS6 includes support that allows ASP.NET 2.0 to perform authentication and authorization steps, and to then hand off the remainder of the 
processing of a non-ASP.NET resource back to IIS6.  For example, it is possible to authenticate access to an ASP page using ASP.NET forms authentication, authorize access
with ASP.NET's Url authorization and still allow the ASP ISAPI extension (asp.dll) to execute the ASP page.  This support is possible because IIS6 introduced a new server
 support function for ISAPI extensions: <code>HSE_REQ_EXEC_URL</code>.
<br /><br />
Assume that a directory structure contains a mix of both ASP and ASP.NET files.  The ASP.NET pages are used to log a user in with forms authentication, while the 
ASP pages represent the rest of the application.  Using the IIS6 MMC, right-click on directory and create an application (this is the same step that is necessary 
when setting up a standard ASP.NET application).  After an application has been created, click on the <b>Configuration</b> button that is located on the <b>Directory
</b> property page.  This will cause the <b>Application Configuration</b> dialog to be displayed.  New to IIS6 is a feature called wildcard application mapping.  The 
bottom of the <b>Application Configuration</b> dialog allows you to configure this feature.
<br /><br />
First determine the path for the ASP.NET ISAPI extension that processes ASP.NET files such as .aspx files.  You can find this path by looking at the 
extensions that are listed in the <b>Application Extensions</b> list shown in the top half of the <b>Application Configuration</b> dialog.  Click on the row in the list
that maps the .aspx extension, and select the <b>Edit</b> button.  In the dialog that pops up, highlight the text in the <b>Executable</b> textbox and copy it to the clipboard.  Then cancel out 
of the dialog.
<br /><br />
Next, click the <b>Insert</b> button that is in the bottom half of the <b>Application Configuration</b> dialog.  A dialog box titled <b>Add/Edit Application Extension
 Mapping</b> will be displayed.  In the <b>Executable</b> text box, enter the path to the ASP.NET ISAPI extension that you copied to the clipboard earlier.  The end result 
should look something like the screenshot below.
<br /><br />
<asp:Image ImageUrl="~/aspnet/images/isapimap.gif" runat="server"/>
<br /><br />
Click <b>OK</b> to close out all of the dialogs.  Now whenever a request is made for any file, the request will first be processed by ASP.NET.  If the web.config for your 
ASP.NET application has enabled forms authentication, an unauthenticated request for a .asp file will first trigger a redirect to the login page configured for forms 
authentication.  After a user has successfully logged in, they will be redirected back to the original .asp page.  When the now-authenticated user requests the .asp page,
ASP.NET will first run through the <code>FormsAuthenticationModule</code> to verify that the forms authentication cookie exists and is still valid.  If this check passes,
ASP.NET will hand processing of the .asp page back to IIS6, at which point IIS6 will pass the request on to the ISAPI extension that normally process .asp pages.  In this 
case the extension is asp.dll and the ASP page will then run to completion.  The reason ASP.NET will pass the request back to IIS6 is that non-ASP.NET resources will 
fall through the list of configured <code>&lt;httpHandlers&gt;</code> to the following entry:

<pre class="code">
&lt;add path="*" verb="GET,HEAD,POST" type="System.Web.DefaultHttpHandler" validate="True" /&gt;
</pre>

The <code>DefaultHttpHandler</code> is responsible for handing requests back to IIS6 for further processing.
<br /><br />
A similar technique with some constraints is available on IIS5 and IIS5.1.  These versions of IIS require that for each file extension that a developer wants processed by 
ASP.NET, an explicit mapping to the ASP.NET ISAPI extension must be added to the <b>Application Extensions</b> list described earlier.  The second constraint is that 
IIS 5.x does not allow a request to be passed back from ASP.NET to IIS 5.x.  As a result, only static files requested using the GET verb can effectively be protected by 
ASP.NET.  After the first half of the ASP.NET pipeline executes (which includes authentication and authorization), ASP.NET will process the resource using an 
optimized <code>StaticFileHandler</code> rather than attempting to pass the request back to IIS 5.x.  Attempts to process the POST verb, or to request .asp files will 
result in a 405 (invalid method) or 403 error (forbidden:  access denied) respectively.
<br /><br />

<a name="clientscriptgoodies"></a>
<h3>Client-Script Features</h3>

ASP.NET 2.0 includes a number of features that rely on client-side script in the browser. 

For example, the <b>OnClientClick</b> property of <b>Button</b> control allows you to programmatically run client-side script when
the Button is clicked.  The Button renders the client-side <code>onclick</code> attribute along with the button's own javascript.  
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../aspnet/samples/tipstricks/ClientClick_cs.aspx"
        ViewSource="~/aspnet/samples/tipstricks/ClientClick.src"
        Caption="C# ClientClick Event"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../aspnet/samples/tipstricks/ClientClick_vb.aspx"
        ViewSource="~/aspnet/samples/tipstricks/ClientClick.src"
        Caption="VB ClientClick Event"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

There are cases where an application requires the position of the page in the browser to remain 
after post-back to the server. For example, if data entry causes post-back in a large page, the 
end-user would be required to scroll the page to the position that they were editing at in order 
to continue. Page developers can simply mark their form to maintain scroll position by setting
the <b>MaintainScrollPositionOnPostBack</b> property to true in the <code>@Page</code> directive
or by setting this in Web.config to apply to all pages in an application.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../aspnet/samples/tipstricks/MaintainScrollPosition_cs.aspx"
        ViewSource="~/aspnet/samples/tipstricks/MaintainScrollPosition.src"
        Caption="C# Maintain Scroll Position"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../aspnet/samples/tipstricks/MaintainScrollPosition_vb.aspx"
        ViewSource="~/aspnet/samples/tipstricks/MaintainScrollPosition.src"
        Caption="VB Maintain Scroll Position"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

An exciting new feature for controls are <b>Client-side CallBacks</b>, which allow a control to execute an
out-of-band request back to the server to obtain additional data, without posting the entire page.  This feature
relies on browser support for callback handling (usually through XMLHTTP), as specified by the <code>SupportsClientCallbacks</code>
property in browser capabilities.
<br /><br />
The <b>TreeView</b> control takes advantage of this feature to enable populating tree nodes on-demand
when a parent node is expanded on the client.  <b>GridView</b> and <b>DetailsView</b> also take advantage of this feature
to implement paging and sorting when <b>EnableSortingAndPagingCallbacks</b> is set to true.  A control registers itself
as being able to receive callback events by implementing the <code>ICallbackEventHandler</code> interface.
This interface allows the page to invoke registered delegates for returning callback data to the client.
There are two methods of the ICallBackHandler interface, <code>RaiseCallbackEvent</code> and <code>GetCallbackResult</code>.
RaiseCallbackEvent accepts an argument for context (args passed from the client), which can be used to process the event.
GetCallbackResult returns a String that represents the data to return to the client.  The reason this interface is separated
into two methods is to allow for asynchronous processing, for example to retrieve data from a data source control.
The control then registers a client-side callback function that knows how to create the arguments to pass to the server-side delegate, and an error handling function to 
be invoked when an error in callback processing occurs.  Finally, the control 
emits references to callback events using <code>Page.ClientScript.GetCallBackEventReference</code>.  
An example below demonstrates the use of client-side callbacks to implement a cascading DropDownList scenario.
In this case, the Page itself implements the ICallbackEventHandler interface, for demonstration purposes.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../aspnet/samples/tipstricks/CallBackEventHandler_cs.aspx"
        ViewSource="~/aspnet/samples/tipstricks/CallBackEventHandler.src"
        Caption="C# CallBack Event Handlers"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../aspnet/samples/tipstricks/CallBackEventHandler_vb.aspx"
        ViewSource="~/aspnet/samples/tipstricks/CallBackEventHandler.src"
        Caption="VB CallBack Event Handlers"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />


</asp:Content>

