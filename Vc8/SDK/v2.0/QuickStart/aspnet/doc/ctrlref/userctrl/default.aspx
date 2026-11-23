<%@ Page Language="C#" MasterPageFile="~/aspnet/aspnet.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>User Controls</h2>

In addition to the built-in server controls provided by ASP.NET, you can easily define your own controls using the same programming
techniques that you have already learned for writing Web Forms pages. In fact, with just a few modifications, almost any Web Forms page
can be reused in another page as a server control (note that a user control is of type <b>System.Web.UI.UserControl</b>, which inherits directly from
<b>System.Web.UI.TemplateParser</b>).  A Web Forms page used as a server control is named a user control
for short.  As a matter of convention, the .ascx extension is used to indicate such controls.  This ensures that the user control's file cannot
be executed as a standalone Web Forms page (you will see a little that there are a few, albeit important, differences between
a user control and a Web Forms page).  User controls are included in a Web Forms page using a <b>Register</b>  directive:

<pre class="code">
&lt;%@ Register TagPrefix="Acme" TagName="Message" Src="pagelet1.ascx" %&gt;
</pre>

The <b>TagPrefix</b> determines a unique namespace for the user control (so that multiple user controls with the same name can be differentiated from
each other).  The <b>TagName</b> is the unique name for the user control (you can choose any name).  The <b>Src</b> attribute is the virtual path to the
user control - for example "MyPagelet.ascx" or "/MyApp/Include/MyPagelet.ascx".  After registering the user control, you may place the user control
tag in the Web Forms page just as you would an ordinary server control (including the <b>runat="server"</b> attribute):

<br/><br/>

<pre class="code">
&lt;Acme:Message runat="server"/&gt;
</pre>

The following example shows a user control imported into another Web Forms page. Note that the user control in this case is just a simple static file.

<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/userctrl/userctrl1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/userctrl/userctrl1.src"
        Caption="C# UserCtrl1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/userctrl/userctrl1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/userctrl/userctrl1.src"
        Caption="VB UserCtrl1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<!--BEGIN SECTION-->
<a name="properties"></a>
<h3>Exposing User Control Properties</h3>

When a Web Forms page is treated as a control, the public fields and methods of that Web Form are promoted to public properties (that is, tag
attributes) and methods of the control as well.  The following example shows an extension of the previous user control example that adds
two public <b>String</b> fields.  Notice that these fields can be set either declaratively or programmatically in the containing page.

<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/userctrl/userctrl2_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/userctrl/userctrl2.src"
        Caption="C# UserCtrl2.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/userctrl/userctrl2_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/userctrl/userctrl2.src"
        Caption="VB UserCtrl2.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br/>

In addition to promoting public fields to control properties, the property syntax may be used.  Property syntax has the advantage
of being able to execute code when properties are set or retrieved.  The following example demonstrates an <b>Address</b> user control that wraps the text
properties of <b>TextBox</b> controls within it.  The benefit of doing this is that the control inherits the automatic state management of the <b>TextBox</b> control
for free.

<br/><br/>

Notice that there are two <b>Address</b> user controls on the containing Web Forms page that set the 
<b>Caption</b> property to "Billing Address" and "Shipping Address", respectively.  The real power of user controls is in this type of reusability.

<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/userctrl/userctrl3_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/userctrl/userctrl3.src"
        Caption="C# UserCtrl3.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/userctrl/userctrl3_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/userctrl/userctrl3.src"
        Caption="VB UserCtrl3.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br/>

Another useful user control is a <b>Login</b> control for collecting user names and passwords.

<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/userctrl/userctrl4_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/userctrl/userctrl4.src"
        Caption="C# UserCtrl4.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/userctrl/userctrl4_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/userctrl/userctrl4.src"
        Caption="VB UserCtrl4.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br/>

In this example, form validation controls are added to the <b>Login</b> user control.

<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/userctrl/userctrl5_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/userctrl/userctrl5.src"
        Caption="C# UserCtrl5.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/userctrl/userctrl5_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/userctrl/userctrl5.src"
        Caption="VB UserCtrl5.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<!--BEGIN SECTION-->
<a name="events"></a>
<h3>Encapsulating Events in a User Control</h3>

User controls participate in the complete execution lifecycle of the request, much the way ordinary server controls do.  This means that
a user control can handle its own events, encapsulating some of the page logic from the containing Web Forms page.  The following example demonstrates
a product-listing user control that internally handles its own postbacks.  Note that the user control itself
has no wrapping <b>&lt;form runat="server"&gt;</b> control.  Because only one form control may be present on a page (ASP.NET does not
allow nested server forms), it is left to the containing Web Forms page to define this.

<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/userctrl/userctrl6_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/userctrl/userctrl6.src"
        Caption="C# UserCtrl6.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/userctrl/userctrl6_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/userctrl/userctrl6.src"
        Caption="VB UserCtrl6.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<!--BEGIN SECTION-->
<a name="program"></a>
<h3>Creating User Controls Programmatically</h3>

Just as ordinary server controls can be created programmatically, so can be user controls. The page's <b>LoadControl</b> method is used to
load the user control, passing the virtual path to the user control's source file:

<br/><br/>

<Acme:TabControl runat="server">

<Tab Name="C#">
Control c1 = LoadControl("userctrl7.ascx");
((UserCtrl7)c1).Category = "business";
Page.Controls.Add(c1);
</Tab>

<Tab Name="VB">
Dim c1 As Control = LoadControl("userctrl7.ascx")
CType(c1, (UserCtrl7)).Category = "business"
Page.Controls.Add(c1)
</Tab>

</Acme:TabControl>

<br/>

The type of the user control is determined by a <b>ClassName</b> attribute on the <b>Control</b> directive.  For
example, a user control saved with the file name "userctrl7.ascx" is assigned the strong type "UserCtrl7"
as follows:

<pre class="code">
&lt;%@ Control ClassName="UserCtrl7" %&gt;
</pre>

Because the <b>LoadControl</b> method returns a type of <b>System.Web.UI.Control</b>, it must be cast to the
appropriate strong type in order to set individual properties of the control.  Finally, the user
control is added to the base page's <b>ControlCollection</b>.

<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/userctrl/userctrl7_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/userctrl/userctrl7.src"
        Caption="C# UserCtrl7.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/userctrl/userctrl7_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/userctrl/userctrl7.src"
        Caption="VB UserCtrl7.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br/>

<b>Important</b>  The strong type for a user control is available to the containing Web Forms page only if a <b>Register</b> directive is included for
the user control (even if there are no user control tags actually declared).

</asp:Content>

