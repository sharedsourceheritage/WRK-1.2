<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>

<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Working with Server Controls</h2>

ASP.NET server controls are identified within a page using declarative tags
that contain a <b>runat="server"</b> attribute.  The following example declares three
<b>&lt;asp:label runat="server"&gt;</b> server controls and customizes the text and
style properties of each one individually.

<p>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/controls/controls1_cs.aspx"
        ViewSource="~/aspnet/samples/pages/controls/controls1.src"
        Caption="C# Controls1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/controls/controls1_vb.aspx"
        ViewSource="~/aspnet/samples/pages/controls/controls1.src"
        Caption="VB Controls1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>


<!--BEGIN SECTION-->
<a name="manipulating"></a>
<h3>Manipulating Server Controls</h3>

You can programmatically identify an individual ASP.NET server control
within a page by providing it with an <b>id</b> attribute.  You
can use this <b>id</b> reference to programmatically manipulate the server control's
object model at run time.  For example, the following sample demonstrates how a page
developer could programmatically set an <b>&lt;asp:label runat="server"&gt;</b> control's
<b>Text</b> property within the <b>Page_Load</b> event.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/controls/controls2_cs.aspx"
        ViewSource="~/aspnet/samples/pages/controls/controls2.src"
        Caption="C# Controls2.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/controls/controls2_vb.aspx"
        ViewSource="~/aspnet/samples/pages/controls/controls2.src"
        Caption="VB Controls2.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<!--BEGIN SECTION-->
<a name="handling"></a>
<h3>Handling Control Events</h3>

ASP.NET server controls can optionally expose and raise server events, which
can be handled by page developers.  A page developer may accomplish this
by declaratively wiring an event to a control (where the attribute
name of an event wireup indicates the event name and the attribute value
indicates the name of a method to call).  For example, the following code
example demonstrates how to wire an <b>OnClick</b> event to a button control.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/controls/controls3_cs.aspx"
        ViewSource="~/aspnet/samples/pages/controls/controls3.src"
        Caption="C# Controls3.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/controls/controls3_vb.aspx"
        ViewSource="~/aspnet/samples/pages/controls/controls3.src"
        Caption="VB Controls3.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<!--BEGIN SECTION-->
<a name="multiple"></a>
<h3>Handling Multiple Control Events</h3>

Event handlers provide a clean way for page developers to structure logic
within an ASP.NET page.  For example, the following sample demonstrates how to
wire and handle four button events on a single page.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/controls/controls4_cs.aspx"
        ViewSource="~/aspnet/samples/pages/controls/controls4.src"
        Caption="C# Controls4.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/controls/controls4_vb.aspx"
        ViewSource="~/aspnet/samples/pages/controls/controls4.src"
        Caption="VB Controls4.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<!--BEGIN SECTION-->
<a name="navigation1"></a>
<h3>Performing Page Navigation (Scenario 1)</h3>

Page navigation among multiple pages is a common scenario in virtually
all Web applications.  The following sample demonstrates how to use the <b>&lt;asp:hyperlink runat=server&gt;</b> control to navigate
to another page (passing custom query string parameters along the way).  The
sample then demonstrates how to easily get access to these
query string parameters from the target page.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/controls/controls5_cs.aspx"
        ViewSource="~/aspnet/samples/pages/controls/controls5.src"
        Caption="C# Controls5.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/controls/controls5_vb.aspx"
        ViewSource="~/aspnet/samples/pages/controls/controls5.src"
        Caption="VB Controls5.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<!--BEGIN SECTION-->
<br>
<a name="navigation2"></a>
<h3>Performing Page Navigation (Scenario 2)</h3>

Not all page navigation scenarios are initiated through hyperlinks on the client.
Client-side page redirects or navigations can also be initiated from the
server by an ASP.NET page developer by calling the <b>Response.Redirect(url)</b> method.
This is typically done when server-side validation is required on some client
input before the navigation actually takes place.

<br /><br />

The following sample demonstrates how to use the <b>Response.Redirect</b> 
method to pass parameters to another target page.  It also demonstrates how to easily get access to these parameters from the target
page.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/controls/controls6_cs.aspx"
        ViewSource="~/aspnet/samples/pages/controls/controls6.src"
        Caption="C# Controls6.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/controls/controls6_vb.aspx"
        ViewSource="~/aspnet/samples/pages/controls/controls6.src"
        Caption="VB Controls6.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>

