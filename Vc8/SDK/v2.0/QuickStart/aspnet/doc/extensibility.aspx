<%@ Page Language="C#" MasterPageFile="~/aspnet/aspnet.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2><b>Extending ASP.NET</b></h2>

<div class="new">


<!-- ----------------------------------------------------------------- -->
<h3>What's New in 2.0</h3>

ASP.NET 2.0 was designed with pluggability and extensibility in mind.  You can replace many
of the built-in modules and behaviors in ASP.NET with your own custom implementations.  Among the 
improvements to extensibility in this release are:

<ul>
<li>The <b><a href="#PFL">Page framework lifecycle</a> - </b>has additional steps and processes;
<li><b><a href="#SCR">Server controls runtime</a> - </b>Custom controls can be written to take advantage of 
new features such as:
<ol>
<li><a href="#SM"><b>State management</b></a> such as view-state and control-state, or requesting encryption 
of the page-state;
<li>You can write <a href="#A"><b>control and page adapters</b></a> where you require your control or page to 
handle behaviors that are dependant on the browser, device or device class or the markup. Adapters plug into   
the runtime lifecycle;
<li>The new <a href="#DS"><b>data-source and data-bound controls</b></a> mean you can add declarative 
data binding support for new data storage providers, by writing custom data-source controls that 
represent those storage providers;
<li><a href="#WR"><b>Web resources</b></a>, to embed a resource like client-side script files;
<li>Use the enhanced <a href="#CSM"><b>client script management</b></a> functionality;
<li>Make use of the <i>theming</i> or <a href="#F"><b>device filtering</b></a> features in ASP.NET, or;
<li><b><a href="#CB">Callbacks</a> - </b>Where a page developer or control developer wishes to perform actions 
that require communication with the server, without an entire postback, they can make use of 'callbacks';</li>
</ol>
<li><b><a href="#PS">Page-state</a> - </b>In addition to the handling of view-state and control-state in the control 
you can also extend the page-state persister used to handle the collective page state;</li>
  <li><b><a href="#SCD">Server controls design-time</a> - </b>Designer classes associated to server controls provide 
the means to edit the control in a visual designer. You can write control designers to provide rich 
editing features like region-editing, task-based editing, painting and template-editing;</li>
  <li><b><a href="#ASP">Application service providers</a> - </b>All of the built-in services in ASP.NET 2.0 are 
completely extensible through a provider-based registration model.  This includes Membership, 
Roles, Personalization, Site Counters, Profile, Session State, Site Navigation, and Web Events.</li>
  <li><b><a href="#EB">Expression builders</a> - </b>You can add custom expression builders to add declarative support 
for substituting values into a page prior to the parsing and compilation phases. Expression builders 
can provide both runtime and design-time support;</li>
  <li><b><a href="#L">Localization</a> - </b>Rather than using ResX files to support localization, you can implement your 
own resource providers to support the runtime and design-time localization model that obtains data 
from another source such as a backend data store;</li>
  <li><b><a href="#C">Compilation and pre-compilation</a> - </b>You can add new file format extensions into the ASP.NET compilation system 
using <a href="#BP"><b>build providers</b></a>. For example, ASP.NET 2.0 uses build providers to process  
WSDL files for compiling Web service proxies and XSD files for 
compiling strongly-typed data sets in the <i>App_Code</i> directory. If you want to 'virtualize' your web content from a source other 
than traditional files, then you can implement a <a href="#VPP"><b>virtual path provider</b></a>.</li>
</ul>
This section describes these and other general extensibility features in ASP.NET 2.0.
</div>
<br />
ASP.NET 2.0 was designed with extensibility in mind.  While ASP.NET 2.0 strives to meet the demands 
of most applications with out-of-the-box features, we understand that it is very important to be 
able to extend those features with your own implementations when your application calls for a 
behavior outside the scope of the built-in features.  Fortunately, nearly every part of the 
ASP.NET 2.0 system is replaceable or extendable.  


<!-- ------------------------------------------------------ -->
<h4><a name="#PFL"></a>Page Framework Lifecycle</h4>
The page framework lifecycle is a process that begins with the page and recursively drills into the 
controls and child controls within that page. At each point in the lifecycle there are specific 
operations that constitute the behavior of the page and the control and understanding this is 
important for control extensibility, page extensibility and specific page development features. 
For example: 
<ul>
<li><code>Page.InitializeCulture</code> where you can explicitly handle the <code>UICulture</code> and 
<code>Culture</code> for localization, e.g. from Profile;
<li><code>Page.OnPreInit, Page_PreInit</code>, where you can dynamically set the <code>Page.Theme</code> or 
<code>Page.MasterPageFile</code>;
<li><code>Control.LoadControlState, Control.SaveControlState</code> 
to explicitly handle new state management functionality;
<li>Other new page events, like <code>OnInitComplete, OnPreLoad, OnLoadComplete, OnPreRenderComplete,
 OnSaveStateComplete</code> etc.</li>
</ul>


<!-- ------------------------------------------------------ -->
<h3><a name="#SCR"></a>Server Controls Runtime</h3>
User Controls, (.ASCX) are 'compositional controls' that are written declaratively 
using the same techniques used to build a declarative page. Visual Studio now provides a 
'preview' of user-controls in the design-view when these controls are displayed in the consuming page. 
Custom controls, (code files, assemblies) are programmatically created and provide 
extensibility in many forms, (composition, inheritance etc.). When writing a custom control, it is 
important to understand a control's lifecycle stages, including the handling of state information 
and any postback handling. 
<p />
When creating custom controls you can compile your controls into assemblies that are added to the 
application's <i>Bin</i> directory or in ASP.NET 2.0, you can add code file(s) to the 
application's <i>App_Code</i> directory. In this case ASP.NET 2.0 will dynamically compile the 
control. You can also in ASP.NET 2.0 reuse <i>tag prefixes</i> when registering controls from multiple namespaces. So 
it is possible to create several controls in several namespaces that all contribute to the same tag prefix. 
<p />
<pre class="code">
&lt;%-- Register the controls defined in an assembly that resides in the Bin directory --%&gt;
&lt;%@ Register TagPrefix="Demos" NameSpace="DemoControls" Assembly="MyDemoControls" %&gt;

&lt;%-- Register the controls defined in code that resides in the App_Code directory --%&gt;
&lt;%@ Register TagPrefix="Demos" NameSpace="DemoControls" %>

&lt;Demos:ControlFromBinAssembly runat="server" ID="CustomControl1" /&gt;
&lt;Demos:ControlFromCodeFile runat="server" ID="CustomControl2" /&gt;
</pre>


<!-- ------------------------------------------------------ -->
<h4>Control Classes</h4>
ASP.NET introduced the <code>Control</code> and <code>WebControl</code> base classes, and ASP.NET 2.0 
adds more features to these classes along with new classes for example the <code>CompositeControl</code>. 
This simple base class overrides the <code>Controls</code> collection and provides a mechanism for 
an associated <code>CompositeControlDesigner</code> to ensure the child controls are always created.
<p />
<Acme:TabControl runat="server">
<Tab Name="C#">
public class MyCompositionControl : CompositeControl {
  protected override void CreateChildControls() {
    Controls.Clear();
    // Create control collection ..
  }
  // Additional implementation
}
</Tab>
<Tab Name="VB">
Public Class MyCompositionControl 
  Inherits CompositeControl
    Protected Overrides Sub CreateChildControls()
      Controls.Clear()
      ' Create control collection ..
    End Sub
    ' Additional implementation
End Class
</Tab>
</Acme:TabControl>
<p />
The <code>CompositeControl</code> is a <code>WebControl</code> and implements <code>INamingContainer</code>. The 
<code>Controls</code> collection calls <code>EnsureChildControls</code>. You would create all 
child controls in <code>CreateChildControls</code>. The base class provides design-time support, 
again ensuring the <code>Controls</code> collection is created.
<p />
You can enable a page developer to style your control by exposing top-level properties 
that delegate to the child control style properties. If you have many properties and controls, 
then consider exposing properties of type <code>Style</code> and applying these during 
render methods so that child controls do not persist these as view-state, but rather the 
parent handles state management of these complex properties.


<!-- ----------------------------------------------------------- -->
<h4>Control Class and Property Meta-data</h4>
There are a number of interesting class-level and property-level attributes used for features in ASP.NET 
2.0 some of which are:
<ul>
<li><code>LocalizableAttribute</code>: Localization is enabled for all controls and objects, 
including static markup in a web application through the use of expressions, (both implicit and 
explicit). These features are 'layered' on a control at parse-time and you do not 
need to add any special handling to your control. During design-time, Visual Studio will 'push' values 
to a neutral resource for properties that are marked with the <code>LocalizableAttribute</code>.</li>
<li><code>ThemeableAttribute</code>: Page developers and developers performing customization can take advantage of 
themes to affect the stylistic appearance and to some extent the content of a page or site. 
All properties are by default theme-able, so if there are properties that you decide should not be 
theme-able, such as sensitive data properties or properties that are not style-based, 
mark them as <code>Themeable(false)</code>.</li> 
<li><code>UrlPropertyAttribute</code>: Where a control could be used in master-page for example, or other such 
types then Url type properties will potentially require re-basing (an image or a style sheet). In order to 
base the Url property value to the consuming page, e.g. a content-page in a master-page, content-page 
relationship the page framework will rebase that Url when marked with this attribute, and that the control developer uses 
the <code>System.Web.UI.Control.ResolveClientUrl()</code> method to render the correct client Url for the browser;</li>
<li><code>WebResourceAttribute</code>: Used to mark the assembly that contains an embedded resource, so 
that resource can be served in a request;</li>
<li><code>FilterableAttribute</code>: Used to mark control properties, or controls that wish to 
support the device filtering, declarative syntax in the page.</li>
</ul>
Note: that when creating custom controls, Visual Studio intellisense and validation will interpret types and 
class and property meta-data attributes to create the schema.

<!-- ------------------------------------------------------ -->
<h4><a name="#SM"></a>State Management</h4>
In ASP.NET 1.x, it was common for controls to store data in the view-state dictionary in order 
to round-trip data across postbacks.  Page developers could disable view-state however, 
and consequently lose some of the core control behavior as that data was also 
round-tripped in view-state. In ASP.NET 2.0 you can take advantage of <i>control-state</i> if you 
have a requirement to keep some state regardless of the setting the page developer 
makes. Items stored in control-state should be limited: 
a current page index or a data key value. Be prudent using this form of state, it is not 
intended to be a repository for large amounts of data. 
Custom controls need to register for control-state (ideally <code>OnInit</code> but  
before <code>OnLoad</code>) and provide explicit save and load handling. You'll need to register on 
every postback.
<p />
<Acme:TabControl runat="server">
<Tab Name="C#">
protected override void OnInit(EventArgs e) {
  base.OnInit(e);
  Page.RegisterRequiresControlState(this);
}
protected override object SaveControlState() {
  object o = base.SaveControlState();

  // Additional implementation

  return new Pair(o, ViewIndex);
}
protected override void LoadControlState(object state) {
  Pair p = state As Pair;
  if (p != null) {
    base.LoadControlState(p.First);
    ViewIndex = (int)p.Second;
  }  
  // Additional implementation
}
</Tab>
<Tab Name="VB">
Protected Overrides Sub OnInit(ByVal e As System.EventArgs)
  MyBase.OnInit(e)
  Page.RegisterRequiresControlState(Me)
End Sub
Protected Overrides Function SaveControlState() As Object
  Dim o As Object = MyBase.SaveControlState()

  ' Additional implementation

  Return New Pair(o, ViewIndex)
End Function
Protected Overrides Sub LoadControlState(ByVal savedState As Object)
  Dim p As Pair = savedState
  If Not (p Is Nothing) Then
    MyBase.LoadControlState(p.First)
    ViewIndex = CInt(p.Second)
  End If
End Sub
</Tab>
</Acme:TabControl>
<p />
In ASP.NET 2.0, the control-state and view-state are combined in the hidden field in the page rendering. You can make a request 
to the page to encrypt the field, (<code>Page.RegisterRequiresViewStateEncryption</code>) if you need to round-trip potentially sensitive data.

<!-- ------------------------------------------------------ -->
<h4><a name="#A"></a>Control and Page Adapters: Handling Behavior for Devices, Browsers or Markups</h4>
The 'behavior' of a control, (e.g. the rendering) is normally handled within the class for the 
control (using the associated text writer and <code>HttpBrowserCapabilitites</code>). 
You can, however, create configurable <i>page and control adapters</i> that handle the behavior on behalf of the
control. Such configuration is made within the browser capabilities files, (<i>.browser</i>). 
<p />
The <code>HttpBrowserCapabilities</code> creation process uses 
declarative browser files that reside in the install directory under <i>Config\Browsers</i> and/or the 
application's 
local <i>App_Browsers</i> directory. The following snippet 
shows a custom browser file that maps a custom adapter for a custom control; and in this example, the
 assembly containing the adapter is created from the <i>App_Code</i> directory of the application, 
as the type definitions are shown without being full qualified.
<pre class="code">
&lt;!-- New browser node links into parent --&gt;
&lt;browser id="My_PIE_PPC" parentID="PIEnoDeviceID"&gt;
  &lt;identification&gt;
    &lt;capability name="browser" match="Pocket IE" /&gt;
    &lt;capability name="majorversion" match="4" /&gt;
  &lt;/identification&gt;

  &lt;!-- Define new text-writer for this browser and define control-adapter mapping --&gt;
  &lt;controlAdapters markupTextWriterType="MyNamespace.MyCustomTextWriter" &gt;
    &lt;adapter controlType="MyNamespace.MyControl" adapterType="MyNamespace.MyControlAdapter" /&gt;
  &lt;/controlAdapters&gt;
&lt;/browser&gt; 
</pre>
<p />
During the <a href="#PFL">page framework lifecycle</a>, ASP.NET 2.0 attempts to look for an 
adapter on the control using the <code>Control.ResolveAdapter</code> method. If an adapter is returned, the page 
framework will call on the adapter methods instead of the control's lifecycle methods. 
As an extensibility developer you can extend the adapter base classes, e.g. <code>ControlAdapter</code>, 
<code>WebControlAdapter</code> and <code>PageAdapter</code> and define overrides for the 
lifecycle stages and other methods such as child control creation and postback handling.
<p />
<ul>
<li>The base adapter classes call back on the control's equivalent method. It is typical therefore, 
to call on the base method in your adapter. This is not necessarily true of the <code>Render</code> 
method(s), as you could end-up with unwarranted markup behavior;
<li>Adapters can implement <code>IPostBackEventHandler</code> and <code>IPostBackDataHandler</code> 
to handle postback data and raise events;
<li>Adapters can implement view-state and control-state methods, <code>LoadAdapterViewState, SaveAdapterViewState</code> 
and <code>LoadAdapterControlState</code>, <code>SaveAdapterControlState</code>. These methods 
contribute to the control's behavior however;
<li>Adapters can implement <code>CreateChildControls</code> and handle data-binding calls;
<li>Alternatively you can prevent 'adaptation' for your custom control by returning null from 
<code>Control.ResolveAdapter</code>.
</ul>
<p />
<Acme:TabControl runat="server">
<Tab Name="C#">
// Control
public class MyControl : Control {
  // Example showing override of Render to control entire rendering
  protected override void Render(HtmlTextWriter writer) {
    Style s = new Style();
    s.ForeColor = System.Drawing.Color.Green;
    writer.EnterStyle(s);			
    writer.Write("Welcome custom control.");
    writer.ExitStyle(s);
  }
  // Additional implementation
}
// Adapter	
public class MyControlAdapter : ControlAdapter {
  // Example showing override of Render to control entire rendering
  protected override void Render(HtmlTextWriter writer) {
    Style s = new Style();
    s.ForeColor = System.Drawing.Color.Red;
    writer.EnterStyle(s);
    writer.Write("Welcome custom control adapter.");            
    writer.ExitStyle(s);
  }
  // Additional implementation
}
</Tab>
<Tab Name="VB">
' Control
Public Class MyControl 
  Inherits Control
  ' Example showing override of Render to control entire rendering
  Protected Overrides Sub Render(ByVal writer As HtmlTextWriter)
    Dim s As New Style()
    s.ForeColor = System.Drawing.Color.Green
    writer.EnterStyle(s)
    writer.Write("Welcome custom control.")
    writer.ExitStyle(s)
  End Sub
  ' Additional implementation
End Class
' Adapter	
Public Class MyControlAdapter 
  Inherits ControlAdapter
  ' Example showing override of Render to control entire rendering      
  Protected Overrides Sub Render(ByVal writer As HtmlTextWriter) 
    Dim s As New Style()
    s.ForeColor = System.Drawing.Color.Red
    writer.EnterStyle(s)
    writer.Write("Welcome custom control adapter.")
    writer.ExitStyle(s)
  End Sub
  ' Additional implementation
End Class
</Tab>
</Acme:TabControl>


<!-- ------------------------------------------------------ -->
<h4><a name="#DS"></a>Data Source and Data Bound Controls</h4>
A data source control represents a backend data storage provider that can expose data to data-bound 
UI controls.  ASP.NET ships with several data source control, for example data sources representing 
SQL databases, middle-tier objects, or XML files.  All data source controls have the following in common:
<ul>
<li>Represent one or more named views of data
<li>Each view provides an enumeration of objects
<ul>
<li>Essentially SELECT in SQL terms
</ul>
<li>A view may also be able to perform editing operations on its collection of objects
<ul>
<li>Essentially UPDATE, INSERT, DELETE in SQL terms.
<li>Capabilities model exposed as boolean properties
</ul>
<li>Ability to trigger change events
<li>Ability to load data on-demand
</ul>
You can easily add support for additional data sources by creating a custom data source control, which is a server control that implements either the <b>IDataSource</b> or <b>IHierarchicalDataSource</b> interface, or both.  ASP.NET 2.0 also includes the <b>DataSourceControl</b> and <b>HierarchicalDataSourceControl</b> abstract base classes that encapsulate the common behavior that most data source controls need.
<pre class="code">
public interface IDataSource {
  event EventHandler DataSourceChanged { add; remove; }
  DataSourceView GetView(string viewName);
  ICollection GetViewNames();
}

public abstract class DataSourceControl : 
  Control, IDataSource, IListSource {
  // Additional implementation
}
</pre>
A <b>DataSourceView</b> represents the various operations that can be performed over a view of the data that the data source control exposes.  The following is a simplification of the actual DataSourceView base class (in actuality, the methods follow an asynchronous design pattern).
<pre class="code">
public abstract class DataSourceView {
  public virtual bool CanDelete { get; }
  // CanInsert, CanPage, CanSort, CanUpdate, ...

  public event EventHandler DataSourceViewChanged;
  public virtual int Delete (IDictionary keys, IDictionary oldValues, ...);
  public virtual bool Insert (IDictionary values, ...);
  public virtual int Update (IDictionary keys, IDictionary values, IDictionary oldValues, ...);
  public abstract IEnumerable Select(DataSourceSelectArguments arguments);
}
</pre>
The .NET Framework reference documentation for these classes includes examples that show how to write a 
custom tabular or hierarchical data source control.
<br/><br/>


<!-- ------------------------------------------------------ -->
<h4><a name="#WR"></a>Web Resources</h4>
In ASP.NET 1.x developers writing custom controls that required custom resources such as images 
or client script would need to install the resources in the <code>aspnet_client</code> virtual folder. 
In ASP.NET 2.0 you can take advantage of <i>web resources</i> to 
simplify the process. Web resources allow resources to be embedded in an assembly and are
retrieved through the web resources handler. The following sample shows use of an embedded JavaScript file 
and use of the <code>Page.ClientScript.RegisterClientScriptResource</code> method. If embedding a stylesheet instead, then
you will need to consider registering the stylesheet and using <code>Page.ClientScript.GetWebResourceUrl</code> 
to point to the embedded resource.
<p />
<Acme:TabControl runat="server">
<Tab Name="C#">
// Mark the assembly with the resource
[assembly: WebResource("CustonmControlScript.js", "text/javascript")]

public class CustomControl : WebControl {
  
  // Additional implementation
	
  protected override void OnPreRender(EventArgs e) {
    this.Page.ClientScript.RegisterClientScriptResource(typeof(CustomControl), "CustomControlScript.js");
    this.Attributes.Add("onmouseover", "MouseOverScript()");
    base.OnPreRender(e);	
  }
}
</Tab>
<Tab Name="VB">
' Mark the assembly with the resource
&lt;assembly: WebResource("CustomControlScript.js", "text/javascript")&gt;

Public Class CustomControl
  Inherits WebControl

  ' Additional implementation

  Protected Overrides Sub OnPreRender(ByVal e As System.EventArgs)
    Me.Page.ClientScript.RegisterClientScriptResource(GetType(CustomControl), "CustomControlScript.js");
    Me.Attributes.Add("onmouseover", "MouseOverScript()"
    MyBase.OnPreRender(e)
  End Sub
End Class
</Tab>
</Acme:TabControl>


<!-- ------------------------------------------------------ -->
<h4><a name="#CSM"></a>Client Script Management</h4>
The <code>Control.Page</code> property exposes a <code>ClientScript</code> property that 
encapsulates features for handling, registering and referencing client-script. 
When combined with web resources, it is possible for you to also embed those scripts within the 
assembly of the control, see the <a href="#WR">sample</a> in web resources. 
<p />
<Acme:TabControl runat="server">
<Tab Name="C#">
public class MyButton : Button {
  protected override void OnPreRender(EventArgs e) {
    String sScript = "function DoAlert(){alert('Hello World');}";
    this.Page.ClientScript.RegisterClientScriptBlock(typeof(MyButton), 
      "ScriptFunction", sScript, true);

    OnClientClick = "javascript:DoAlert();";
    base.OnPreRender(e);
  }

  // Additional implementation

}
</Tab>
<Tab Name="VB">
Public Class MyButton
  Inherits Button
  Protected Overrides Sub OnPreRender(ByVal e As System.EventArgs)
    Dim sScript As String = "function DoAlert(){alert('Hello World');}"
    Me.Page.ClientScript.RegisterClientScriptBlock(GetType(MyButton), _ 
      "ScriptFunction", sScript, True)

    OnClientClick = "javascript:DoAlert();"
    MyBase.OnPreRender(e)
  End Sub

  ' Additional implementation

End Class
</Tab>
</Acme:TabControl>


<!-- ------------------------------------------------------ -->
<h4><a name="#F"></a>Device, (device markup or browser) Filtering</h4>
A page developer can use a new declarative syntax to qualify control properties so that they are 
only set when a device filter definition evaluates to true. For example, a device filter ID may define the 
Internet Explorer class of browsers, as defined in <i>browser</i> files in the application. The device-filter 
can be used to declaratively qualify properties of a control. You do not have to add anything to your custom 
control to support this. However, in cases where you do not wish device filters to apply simply mark your
control or property with the <code>Filterable(false)</code> attribute. Note that localization also takes device filtering 
into account.
<pre class="code">
&lt;!-- Text property is defaulted to a value, reset given IE and also if the custom filter applies. --&gt; 
&lt;!-- The more specific the device-filter wins.. --&gt;
&lt;asp:Label runat="server" Id="WelcomeLabel" Text="Welcome to ASP.NET's Quickstarts" 
	IE:Text="Quickstarts" MyFilter:Text="Welcome" /&gt;
</pre>


<!-- ------------------------------------------------------ -->
<h4><a name="#CB"></a>Callbacks</h4>
Callbacks allow a control or page to perform an out-of-band call back to the server in a manner that does not
 require the page to be posted back entirely. This means that your custom control does not cause the client browser to wait on an entire 
page post back and your custom control can enable rich UI functionality. You can develop a custom control that easily combines for example, 
web resources with client script management to make use of the call back infrastructure. 
To enable a call back you will:
<ul>
<li>Create a server-side call back event with a given signature in your custom control, (<code>ICallbackEventHandler.PrepareCallbackEvent</code>)
 that acts on an argument passed into the method<. You should call on a method that developers can override if they extend your
 custom control;
</li>
<li>Create a server-side method that generates the result for the call back, <code>ICallbackEventHandler.RenderCallbackResult</code>. 
You should call a method that developers can override if they extenf your control. The return result will be passed to 
client-side script defined by your custom control;
<li>Create client-side script that manages the return call or error. This will be generated through your custom control;</li>
<li>Use the callback event reference hooked up to a client-side event in your custom control.</li>
</ul>
<p />
<Acme:TabControl runat="server">
<Tab Name="C#">
public class CustomControl : CompositeControl, ICallbackEventHandler {
  void ICallbackEventHandler.PrepareCallbackEvent(string eventArgument) {
    PrepareCallBackEvent(eventArgument);
  }

  String ICallbackEventHandler.RenderCallbackResult() {
    return RenderCallbackResult();
  }

  private String _callbackEventArg;

  // Do work in a protected virtual methods so that derived controls can override
  protected virtual void PrepareCallBackEvent(string eventArgument) {
    _callbackEventArg = eventArgument;
  }

  protected virtual String RenderCallbackResult() {
    if (_callbackEventArg == "theArg") 
      return = "Some data";
    
    return "Only theArg allowed!";
  }

  // Additional implementation
	
  // Client script functions that handle the callback
  private String sButtonCallBack = 
    "function ButtonCallBack(result, context) { alert(result); }";
  private String sButtonCallBackError = 
    "function ButtonErrorCallBack(result, context) { alert(result); }";

  protected override void OnInit(EventArgs e) {
    base.OnInit(e);

    // Additional implementation

    Page.ClientScript.RegisterClientScriptBlock(typeof(CustomControl), 
      "ButtonCallBack", sButtonCallBack, true);
    Page.ClientScript.RegisterClientScriptBlock(typeof(CustomControl), 
      "ButtonCallBackError", sButtonCallBackError, true);
  }

  // Additional implementation
	
  protected override void OnPreRender(EventArgs e) {
    // Set up the OnClick event to fire an out-of band call to the handler
    Attributes["OnClick"] = Page.ClientScript.GetCallbackEventReference(this, 
      "'theArg'", "ButtonCallback", "null", "ButtonErrorCallback", true);
    base.OnPreRender(e);
  }
}
</Tab>
<Tab Name="VB">
Public Class CustomControl
  Inherits CompositeControl
  Implements ICallbackEventHandler

  Private Sub PrepareCallbackEvent(ByVal eventArgument As String)
    Implements System.Web.UI.ICallbackEventHandler.PrepareCallbackEvent
    PrepareCallbackEvent(eventArgument)
  End Sub

  Private Function RenderCallbackResult() As String _
    Implements System.Web.UI.ICallbackEventHandler.RenderCallbackResult
    Return RenderCallbackResult()
  End Function

  Private _callbackEventArg As String;

  Protected Overridable Sub PrepareCallback(ByVal eventArgument As String)
    _callbackEventArg = eventArgument
  End Sub

  Protected Overridable Function RenderCallbackResult() As String   
    Dim result As String

    If (_callbackEventArg = "theArg") Then
      result = "Some data"
    Else
      result = "Only theArg allowed!" 
    End If

    Return result 
  End Function

  Private sButtonCallBack As String = _
    "function ButtonCallBack(result, context){ alert(result);}"
  Private sButtonCallBackError As String = _
    "function ButtonErrorCallBack(result, context){ alert(result);}"

  Protected Overrides Sub OnInit(ByVal e As System.EventArgs)
    MyBase.OnInit(e)
    Page.ClientScript.RegisterClientScriptBlock(GetType(MyControl), _
      "ButtonCallBack", sButtonCallBack, True);
    Page.ClientScript.RegisterClientScriptBlock(GetType(MyControl), _
      "ButtonCallBackError", sButtonCallBackError, True);
  End Sub

  ' Additional implementation

  Protected Overrides Sub OnPreRender(ByVal e As EventArgs)
    Me.Attributes("OnClick") = _
    Page.ClientScript.GetCallbackEventReference(Me, _
      "'theArg'", "ButtonCallback", "null", "ButtonErrorCallback", True)
    MyBase.OnPreRender(e)
  End Sub
End Class
</Tab>
</Acme:TabControl>


<!-- ------------------------------------------------------ -->
<h3><a name="#PS"></a>Page-state</h3>
Page-state, (the cumulative view-state and control-state for the controls and the page) is 
typically persisted to the page's response, using the <code>HiddenFieldStatePersister</code> (it 
is the VIEWSTATE hidden field). You can 
override the <code>PageStatePersister</code> on the <code>Page</code> for custom persistence however.
Given the adaptive nature of controls to the requesting device, some devices may not handle 
significant amounts of data that are typically 'round-tripped'. Through the 
<code>PageAdapter</code> configured for a device, the state can be persisted to alternative 
sources. ASP.NET 2.0 defines two page state persisters, <code>HiddenFieldPageStatePersister</code> 
and <code>SessionPageStatePersister</code>.
<p />
ASP.NET 2.0 also enables the splitting up the single hidden field into several
using the <code>maxPageStateFieldLength</code> attribute in configuration. 


<!-- ------------------------------------------------------ -->
<h3><a name="#SCD"></a>Server Controls Design-time</h3>
There are many improvements, simplifications and advances in control designers. 
You write a <code>ControlDesigner</code> to provide design-time behavior for your custom 
control in a development environment like Visual Studio. The following features are available in ASP.NET 2.0:
<ul>
<li><i>Region-based editing</i>. In ASP.NET 1.x you would use a <code>ReadWriteControlDesigner</code> to 
provide a single read/write area for your control on the design-surface. In ASP.NET 2.0 you can 
create editable, template-able and read-only regions (<code>DesignerRegion</code> types) for richer editing experiences. 
Regions can also provide tool-tips and highlighting. You can also handle click events on the control 
and interact with the regions;
<li>Painting on the design-surface. You can provide graphics on 
the design-surface for your control by indicating that the control supports painting and overriding 
 <code>OnPaint</code>;
<li>Control-designer types can interact with the control more closely with accessors but also can 
take advantage of control features such as embedded resources like images;
<li><i>Task-based editing</i>. Using <code>DesignerActionList</code>s you can provide a very 
visual, contextual task list for page developers to interact with. This advances the previous 
concept of <code>DesignerVerb</code>s;
<li>Improved and much simplified <i>template-editing</i>. Your control-designer can defer simply to the tool's 
template editing UI or you can create your own UI using regions. Adding template editing is now as simple as 
defining the <code>TemplateGroups</code> collection on the <code>ControlDesigner</code>; 
<li>Several new convenient control-designer base classes, <code>CompositeControlDesigner</code> and 
<code>ContainerControlDesigner</code> for common scenarios.
</ul>
The following snippet shows a very simple <code>WebControl</code> and associates a 
<code>ContainerControlDesigner</code>. In this form, the designer tool creates a single, editable 
region for the control, which allows drag-and-drop. The control defines children as child controls, 
see <code>ParseChildren(false)</code> and <code>PersistChildren(true)</code>. 
The <code>ControlDesigner</code> creates a caption bar and sets styles accordingly. The pseudo code also 
shows steps to implement a simple <code>DesignerActionList</code>.
<p />
<Acme:TabControl runat="server">
<Tab Name="C#">
namespace CustomControls {
  [Designer(typeof(MyDesigner)), ParseChildren(false), PersistChildren(true)]
  public class MyControl : WebControl { }

  public class MyDesigner : ContainerControlDesigner {
    private Style _style = null;
    public override string FrameCaption { get { /* Return a caption */"; } }
    public override Style FrameStyle { get { /* Return a Style for the frame*/ } }

    public override DesignerActionListCollection ActionLists {
      get { 
	// Get the base collection and add my own list
      }
    }
    
    private sealed class MyList : DesignerActionList {
      // Additional members to handle the smart-tag

      public override DesignerActionItemCollection GetSortedActionItems() {
	// Create a collection and add DesignerActionTextItem, 
	// DesignerActionPropertyItem and DesignerActionMethodItem types
      }
    }
  }
}
</Tab>
<Tab Name="VB">
&lt;Designer(GetType(MyDesigner)), ParseChildren(false), PersistChildren(true)&gt;
Namespace CustomControls

  &lt;Designer(GetType(MyDesigner)), ParseChildren(False), PersistChildren(True)&gt; _
  Public Class MyControl
      Inherits WebControl
  End Class

  Public Class MyDesigner
    Inherits ContainerControlDesigner

    Private _style As Style = Nothing
    Public Overrides ReadOnly Property FrameCaption() As String
      Get
        ' Return a caption
      End Get
    End Property

    Public Overrides ReadOnly Property FrameStyle() As Style
      Get
        ' Return a style for the frame
      End Get
    End Property

    Public Overrides ReadOnly Property ActionLists() _
      As System.ComponentModel.Design.DesignerActionListCollection
      Get
        ' Get the base collection and add my own list
      End Get
    End Property

    Private Class MyList
      Inherits System.ComponentModel.Design.DesignerActionList
      ' Members to handle the smart-tag
		    ..
      Public Overrides Function GetSortedActionItems() _
        As System.ComponentModel.Design.DesignerActionItemCollection
	' Create a collection and add DesignerActionTextItem, 
	' DesignerActionPropertyItem and DesignerActionMethodItem types
      End Function
    End Class
  End Class
End Namespace
</Tab>
</Acme:TabControl>
<p />


<!-- ------------------------------------------------------ -->
<h3><a name="#ASP"></a>Application Service Providers</h3>
Many ASP.NET application services have been designed with a provider-based model.  Providers abstract the physical data storage for
a feature from the classes and business logic exposed by a feature.  Features that are built on top of providers allow you to create
your own custom providers and configure them to work with the feature.  Custom providers allow developers to implement specialized
business logic and to operate against alternate data stores.  Pages that use a provider-based feature continue to work normally with
custom providers, and without any changes in page code.  The following application services support the provider model and allow you
to author and configure custom providers:
<ul>
  <li> Membership
  <li> Role Manager
  <li> Session State
  <li> Profile
  <li> Site Navigation
  <li> Site Counters
  <li> Web Parts Personalization
  <li> Web Events
</ul>

<!-- ------------------------------------------------------ -->
<h3><a name="#EB"></a>Expression Builders</h3>
<code>ExpressionBuilder</code>s in ASP.NET 2.0 are a parse-time feature that allows  
the page developer to add declarative syntax to assign to a control's properties. ASP.NET 2.0 ships with expression builders for:
<ul>
<li>Connection strings. Used to access connection-strings in configuration. <code>&lt;%$ connectionstrings: MyConnStr %&gt;</code>;
<li>Application settings. Used to access the application setting in configuration. 
<code>&lt;%$ appsettings: MyAppValue %&gt;</code>, and;
<li>Resources. Used as the foundation for building a <a href="localization/default.aspx">multi-lingual</a> 
site. <code>&lt;%$ resources: mykey %&gt;</code>.
</ul>
Expression builders can offer design-time handling through the <i>Expressions dialog</i> in Visual Studio which is 
accessed through the property grid. You can add your own expression builders and expression prefix and 

not only handle the expression during runtime but you can also support the design-time too.
<p />
Expression builders can also be constructed to support the <i>no compile</i> feature of ASP.NET 2.0. 
Instead of ASP.NET generating code through the expression builder during the generation of the page-class, the 
runtime instead instantiates the expression builder and evaluates the expression.
The following example shows a pseudo <code>ExpressionBuilder</code> and 
<code>ExpressionBuilderEditor</code>. 
.
<p />
<pre class="code">
&lt;!-- In configuration, add your expression builder. Here the type is defined in App_code --&gt;
&lt;expressionBuilders&gt;
	&lt;add expressionPrefix="Expr" type="CustomExpressions.CustomExpressionBuilder" /&gt;
&lt;/expressionBuilders&gt;
</pre>

<acme:TabControl runat="server">
<tab name="C#">
namspace CustomExpressions {
  // Create expression builder and define the prefix, the editor etc.
  [ExpressionPrefix("Expr"), ExpressionEditor("CustomExpressionEditorDesigner"]
  public sealed class CustomExpressionBuilder : ExpressionBuilder {
    public override bool SupportsEvaluate {
      get {
        return true; // Supports the evaluation for no compile scenarios
      }
    }

    public override CodeExpression GetCodeExpression(..) {
      // Return a code expression, given the declarative expression
    }

    public override object EvaluateExpression(..) {
      // Return an evaluation of the expression for no compile scenarios
    }
    
    // Additional implementation
  }

  // The editor is used at design-time.
  public sealed class CustomExpressionEditor : ExpressionEditor {
    public override ExpressionEditorSheet GetExpressionEditorSheet(..) {
      // Create a sheet
      return new CustomExpressionEditorSheet(..);
    }

    public override object EvaluateExpression(..) {
      // Return an evaluation during design-time
    }

    private sealed class CustomExpressionEditorSheet : ExpressionEditorSheet {
      // Expose any properties that represent the expression's value, you can define
      // default values, type converters and descriptions
    }
  }
}
</Tab>
<Tab name="VB">
Namespace CustomExpressionBuilders
  ' Create the expression builder and define the prefix, the editor etc.
  <ExpressionPrefix("Expr"), ExpressionEditor("CustomExpressionEditor")> _
  Public NotInheritable Class CustomExpressionBuilder
    Inherits ExpressionBuilder

    Public Overrides ReadOnly Property SupportsEvaluate() As Boolean
      Get
        Return True
        ' Supports the evaluation for no compile scenarios
      End Get
    End Property

    Public Overrides Function GetCodeExpression(ByVal entry As System.Web.UI.BoundPropertyEntry, _
      ByVal parsedData As Object, ByVal context As System.Web.Compilation.ExpressionBuilderContext) _
      As System.CodeDom.CodeExpression
      ' Return a code expression, given the declarative expression
    End Function

    Public Overrides Function EvaluateExpression(ByVal target As Object, _
      ByVal entry As System.Web.UI.BoundPropertyEntry, ByVal parsedData As Object, _
      ByVal context As System.Web.Compilation.ExpressionBuilderContext) As Object
      ' Return an evaluation of the expression for no compile scenarios
    End Function

    ' Additional implementation

  End Class

  ' The editor is used at design-time
  Public NotInheritable Class CustomExpressionEditor
    Inherits ExpressionEditor

    Public Overrides Function GetExpressionEditorSheet(ByVal expression As String, _
      ByVal serviceProvider As System.IServiceProvider) As System.Web.UI.Design.ExpressionEditorSheet
      ' Create a sheet
    End Function

    Public Overrides Function EvaluateExpression(ByVal expression As String, _
      ByVal parseTimeData As Object, ByVal propertyType As System.Type, _
      ByVal serviceProvider As System.IServiceProvider) As Object
      ' Return an evaluation during design-time
    End Function

    Private NotInheritable Class CustomExpressionEditorSheet
        Inherits ExpressionEditorSheet
      ' Expose any properties that represent the expression's value, you can define
      ' default values, type converters and descriptions
    End Class
  End Class
End Namespace
</Tab>
</Acme:TabControl>


<!-- ------------------------------------------------------ -->
<h3><a name="#L"></a>Localization</h3>
You can review the localization features <asp:hyperlink runat="server" id="loclink" navigateurl="~/aspnet/doc/localization/default.aspx">here</asp:hyperlink>.
<p />
The localization model in ASP.NET 2.0 allows the page developer to set implicit or explicit, 
declarative expressions. You can extend the resource expressions as described above and still use the 
underlying resource providers. More likely however, is extending localization to provide an 
alternative source for resource data rather than use ResX and it's resultant satellite assemblies. 
You can simply swap out the existing <code>ResourceProviderFactory</code> that is defined in configuration 
and supply a new one. The factory creates <code>IResourceProvider</code>s for both global and local 
resources. The following pseudo code demonstrates a simple case (the custom factory 
must be defined in configuration).
<p />
<pre class="code">
&lt;!-- Defines the type in configuration. This sample shows defining the type in the 
App_Code directory --&gt;
&lt;globalization resourceProviderFactoryType="CustomLocalizationProviders.CustomResourceProviderFactory" ../&gt;
</pre>

<Acme:TabControl runat="server">
<Tab Name="C#">
// Note that to support design-time too, add the following attribute and
// define the provider
namsepace CustomLocalizationProviders {
  [DesignTimeResourceProviderFactoryAttribute(typeof(CustomDesignTimeResourceProviderFactory))]
  public sealed class CustomResourceProviderFactory: ResourceProviderFactory {
    public override IResourceProvider CreateGlobalResourceProvider(string classKey) {
      return new CustomGlobalResourceProvider(classKey);
    }
    public override IResourceProvider CreateLocalResourceProvider(string virtualPath) {
      return new CustomLocalResourceProvider(virtualPath);
    }

    private sealed class MyGlobalResourceProvider: IResourceProvider {
      object IResourceProvider.GetObject(string resourceKey, CultureInfo culture) {
	// Get a resource object for the resource key and culture
      }
      IResourceReader ResourceReader {
        get { /* return a reader that enumerates the neutral resource */ }
      }    
    }
 
    // Implement CustomLocalResourceProvider           

  }
}		
</Tab>
<Tab Name="VB">
' Note that to support design-time too, add the following attribute and
' define the provider
Namespace CustomLocalizationProviders
  &lt;DesignTimeResourceProviderFactoryAttribute(GetType(CustomDesignTimeResourceProviderFactory))&gt; _
  Public NotInheritable Class CustomResourceProviderFactory
    Inherits ResourceProviderFactory

    Public Overrides Function CreateGlobalResourceProvider(ByVal classKey As String) _
      As System.Web.Compilation.IResourceProvider
      Return New CustomGlobalResourceProvider(classKey)
    End Function

    Public Overrides Function CreateLocalResourceProvider(ByVal virtualPath As String) _
      As System.Web.Compilation.IResourceProvider
      Return New CustomLocalResourceProvider(virtualPath)
    End Function

    Private NotInheritable Class CustomGlobalResourceProvider
      Implements IResourceProvider

      Public Sub New(ByVal classKey As String)
        ' ..
      End Sub

      Public Function GetObject(ByVal resourceKey As String, _
        ByVal culture As System.Globalization.CultureInfo) _
        As Object Implements System.Web.Compilation.IResourceProvider.GetObject
        ' Get a resource object for the resource key and culture
      End Function

      Public ReadOnly Property ResourceReader() As System.Resources.IResourceReader _
        Implements System.Web.Compilation.IResourceProvider.ResourceReader
        Get
          ' Return a reader that enumerates the neutral resource */
        End Get
      End Property
    End Class

    ' Implement CustomLocalResourceProvider

  End Class
End Namespace
</Tab>
</Acme:TabControl>


<!-- ------------------------------------------------------ -->
<h3><a name="#C"></a>Compilation and Pre-compilation</h3>
ASP.NET 2.0 defines several ways to compile a web application and several extensibility points.
<p />
Dynamic compilation includes for example, code separation files 
associated with web pages and user controls, code in the <i>App_Code</i> directory and abstract files 
such as ASPX, ASCX, RESX, and also, WSDL, XSD.
<p />
There are two forms of pre-compilation of sites for deployment as well as a pre-compilation mode that 
'primes' the site. Pre-compiling for deployment can be performed in two ways 
that either allows specific updates to the compiled site or not. 
In both cases code is removed from the compiled site (target). Where 
no updates are selected, the declarative files like ASPX are removed too. Pre-compiling to prime a site means that ASP.NET 
will perform regular compilation of the entire site to avoid the first-time request penalty.
<p />

To precompile a site, you can use the aspnet_compiler.exe tool.  This tool is located in the .NET Framework
installation directory, for example <code>%WINDIR%\Microsoft.NET\Framework\&lt;version&gt;</code>.  You can 
run the tool with a <code>/?</code> switch to see the list of available options.  For example, to pre-compile 
a site in-place by specifying the virtual path to the application, use the following command line:

<pre class="code">
  &gt; aspnet_compiler.exe -v /MyApp 
</pre>

<p />
You can also extend the compilation processes in a number of ways; by contributing new file 
types or extensions to the compilation using <code>BuildProvider</code>s, or by making 
specific content virtual so that the source is for example not on disk. 
The <code>VirtualPathProvider</code> provides this extensibility point.


<!-- ------------------------------------------------------ -->
<h4><a name="#BP"></a>Build Providers</h4>
Build providers are associated to a file extension through configuration. A
build provider is used to produce code for a virtual path that will be compiled by ASP.NET. With a 
build provider you can add source to the compilation processes of ASP.NET that comes from the parsing and subsequent code 
generation of some 'arbirtary' content. For example, if you have some XML format defining some data, or class, 
e.g. custom report data, then you could easily use a custom build provider to generate code that defines 
a custom object. This could easily be 'consumed' by an <code>&lt;asp:objectdatasource ../&gt;</code> control for example.
<p />
The following snippet shows the mapping of a custom build provider for a new file type (extension: myext). 
When files with this extension are added to the <i>App_Code</i> directory only, The custom build provider is used to parse 
the file and 'hand back' code to ASP.NET. The custom build provider is also defined within the 
<i>App_Code</i> directory, but in a configured sub direcrory. This ensures that the type for the custom 
build provider will be available for use by the build system, when the custom file type is encountered in the main
 <i>App_Code</i> 
directory. 
<p />
<pre class="code">
// In configuration, this build provider is defined in the App_code\CustomBuildProviders directory

&lt;system.web&gt;
  &lt;compilation&gt;
    &lt;codeSubDirectories&gt;
      &lt;add directoryName="CustomBuildProviders"/&gt;
    &lt;/codeSubDirectories&gt;
    &lt;buildProviders&gt;
      &lt;add extension=".myext" type="CustomBuildProviders.CustomBuildProvider"/&gt;
    &lt;/buildProviders&gt;
  &lt;/compilation&gt;
&lt;system.web&gt;	
</pre>

<Acme:TabControl runat="server">
<Tab Name="C#">
namespace CustomBuildProviders {
  [BuildProviderAppliesToAttribute(BuildProviderAppliesTo.Code)]
  public sealed class CustomBuildProvider : BuildProvider {

  // Additional implementation

  public override void GenerateCode(AssemblyBuilder assemblyBuilder) {
    // Return code, e.g. a CodeCompileUnit that is added to the 
    // assembly builder.

    ParseVirtualPath();

    // Generate codeDOM for the type
    CodeCompileUnit ccu = GenerateCodeCompileUnit();
    if (ccu != null)
      assemblyBuilder.AddCodeCompileUnit(this, ccu);
  }
		
  private ParseVirtualPath(String virtualPath) { 
    // Additional implementation
  }

  private CodeCompileUnit GenerateCodeCompileUnit() { 
    // Additional implementation 
  }
}
</Tab>
<Tab Name="VB">
Namespace CustomBuildProviders 
  &lt;BuildProviderAppliesToAttribute(BuildProviderAppliesTo.Code)&gt; _
  Public NotInheritable Class CustomBuildProvider 
    Inherits BuildProvider
    
    ' Additional implementation
		
    Public Overrides Sub GenerateCode(ByVal assemblyBuilder As System.Web.Compilation.AssemblyBuilder)
      ' Return code, e.g. a CodeCompileUnit that is added to the 
      ' assembly builder.

      ParseVirtualPath()

      ' Generate codeDOM for the type
      Dim ccu As CodeCompileUnit
      ccu = GenerateCodeCompileUnit()
      If Not (ccu Is Nothing) Then
        assemblyBuilder.AddCodeCompileUnit(Me, ccu)
      End If
    End Sub
		
    Private Sub ParseVirtualPath()
      ' Additional implementation
    End Sub

    Provate Function GenerateCodeCompileUnit() As CodeCompileUnit
      ' Return a new CodeCompileUnit 				
    End Function
  End Class
End Namespace
</Tab></Acme:tabControl>

<p />
If you need to obtain a type in application code you can use the 
<code>BuildManager.GetType</code> method as assembly names are not predictable. 


<!-- ------------------------------------------------------ -->
<h4><a name="#VPP"></a>Virtual Path Provider</h4>
ASP.NET allows you to provide content for web 'content', such as an ASPX, or it's code behind through a 
mechanism called a <code>VirtualPathProvider</code>. The ASP.NET build
system will call on registered <code>VirtualPathProvider</code>s to supply the content, that will then be further 
parsed and compiled. This means that for specific content you will be able to abstract content away from the file 
system for example. 
<p />
To use a virtual path provider, you need to register your virtual path provider with ASP.NET at an early point in the application's lifecycle, for example 
in a special static method you can define in code in the <i>App_Code</i> directory, called <code>AppInitialize</code>. Only 
specific types of web content can be virtualized in this manner. For example, code in the <i>App_Code</i> directory 
cannot be mapped to a <code>VirtualPathProvider</code>.
<p />
Virtual path providers, therefore, are used to serve requests for content based on a virtual path and when registered there may be a 
number of virtual path providers in use. It is possible that the web content in your application may be served by a number of 
virtual path providers. For example your custom virtual path provider and the in-built ASP.NET one that handles the regular 
file system. In this case you need to construct your virtual path provider in a manner that it hands off to the 
<code>Previous</code> virtual path provider, if it does not handle a specific virtual path.
<p />
The following snippet shows pseudo-code for a custom <code>VirtualPathProvider</code>
<p />
<Acme:TabControl runat="server">
<Tab Name="C#">
// For example, using code in the App_Code directory
namespace CustomVirtualPathProviders {
  public sealed class CustomVirtualPathProvider : VirtualPathProvider {

    public static void AppInitialize() {
      CustomVirtualPathProvider myVpp = new CustomVirtualPathProvider();
      HostingEnvironment.RegisterVirtualPathProvider(myVpp);
    }

    // Implement other methods that define file hashing and dependencies ..
    public override string GetFileHash(string virtualPath, IEnumerable virtualPathDependencies) {
      // Return a hash value based on the virtualPathDependencies
      // For unhandled dependencies, create a list of these, then defer to the Previous to
      // get it's hash and combine with this hash value
    }

    public override CacheDependency GetCacheDependency(string virtualPath, 
      IEnumerable virtualPathDependencies, DateTime utcStart) {
      // If the custom virtual path provider handles the path or dependency and it can
      // create a CahceDependency create on and combine with that from the Previous
      // If the provider cannot create a cacheDependency and it handles one of the
      // dependencies, return null
    }
	
    public override bool FileExists(string virtualPath) {
      // If the custom virtual path provider handles the virtualPath and 
      // it exists return true, otherwise defer to Previous
    }

    public override bool DirectoryExists(string virtualDir) {
      // If the custom virtual path provider handles the virtualDir and 
      // it exists return true, otherwise defer to Previous
    }

    public override VirtualFile GetFile(string virtualPath) {
      // If the custom virtual path provider handles the virtualPath and 
      // it exists then create a VirtualFile and return, otherwise defer to Previous
      // VirtualFile implements an Open method to return a Stream
    }

    public override VirtualDirectory GetDirectory(string virtualDir) {
      // If the custom virtual path provider handles the virtualDir and 
      // it exists then create a VirtualDirectory and return, otherwise defer to Previous
      // VirtualDirectory implements enumerations of sub-dirs and files
    }

    internal class MyVirtualFile : VirtualFile {
      public MyVirtualFile(String virtualPath, .. ) : base(virtualPath) { .. }
      public override Stream Open() { .. }
    }
}
</Tab>
<Tab Name="VB">
' For example, using code in the App_Code directory
Namespace CustomVirtualPathProviders

  Public NotInheritable Class CustomVirtualPathProvider
    Inherits VirtualPathProvider

    Public Sub AppInitialize()
      Dim myVpp As New CustomVirtualPathProvider()
      HostingEnvironment.RegisterVirtualPathProvider(myVpp)
    End Sub

    Public Overrides Function GetFileHash(ByVal virtualPath As String, _ 
      ByVal virtualPathDependencies As System.Collections.IEnumerable) As String
      ' Return a hash value based on the virtualPathDependencies
      ' For unhandled dependencies, create a list of these, then defer to the Previous to
      ' get it's hash and combine with this hash value
    End Function

    Public Overrides Function GetCacheDependency(ByVal virtualPath As String, _
      ByVal virtualPathDependencies As System.Collections.IEnumerable, _ 
      ByVal utcStart As Date) As System.Web.Caching.CacheDependency
      ' If the custom virtual path provider handles the path or dependency and it can
      ' create a CahceDependency create on and combine with that from the Previous
      ' If the provider cannot create a cacheDependency and it handles one of the
      ' dependencies, return null
    End Function

    Public Overrides Function FileExists(ByVal virtualPath As String) As Boolean
      ' If the custom virtual path provider handles the virtualPath and 
      ' it exists return true, otherwise defer to Previous
    End Function

    Public Overrides Function DirectoryExists(ByVal virtualDir As String) As Boolean
      ' If the custom virtual path provider handles the virtualDir and 
      ' it exists return true, otherwise defer to Previous
    End Function

    Public Overrides Function GetDirectory(ByVal virtualDir As String) _ 
      As System.Web.Hosting.VirtualDirectory
      ' If the custom virtual path provider handles the virtualDir and 
      ' it exists return true, otherwise defer to Previous
    End Function

    Public Overrides Function GetFile(ByVal virtualPath As String) _ 
      As System.Web.Hosting.VirtualFile
      ' If the custom virtual path provider handles the virtualPath and 
      ' it exists then create a custom VirtualFile and return, otherwise defer to Previous
      ' VirtualFile implements an Open method to return a Stream
    End Function

    Private NotInheritable Class MyVirtualFile
      Inherits VirtualFile
      Sub New(ByVal virtualPath As String)
          MyBase.New(VirtualPath)
      End Sub
      Public Overrides Function Open() As System.IO.Stream
	' Return a Stream
      End Function
    End Class

  End Class
End Namespace
</Tab>
</Acme:TabControl>
</asp:Content>