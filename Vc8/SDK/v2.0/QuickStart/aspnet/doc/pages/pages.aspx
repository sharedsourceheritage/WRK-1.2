<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master"  %>
<%@ Register TagPrefix="Acme" Namespace="Acme" %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Introduction to ASP.NET Pages</h2>

The ASP.NET Web Forms page framework is a scalable common language runtime programming model
that can be used on the server to dynamically generate Web pages. Intended as a logical evolution of ASP (ASP.NET provides syntax compatibility with
existing pages), the ASP.NET page framework has been specifically designed to
address a number of key deficiencies in the previous model.  In particular, it provides
the ability to create and use reusable UI controls that can encapsulate common
functionality and thus reduce the amount of code that a page developer has to write,
the ability for developers to cleanly structure their page logic in an orderly
fashion (not "spaghetti code"), and the ability for development tools to provide strong WYSIWYG design
support for pages (existing classic ASP code is opaque to tools).
This section of the QuickStart provides a high-level code walkthrough of some basic ASP.NET
page features. Subsequent sections of the QuickStart drill down into more specific details.


<!--BEGIN SECTION-->
<a name="writingpages"></a>
<h3>Writing Your First ASP.NET Page</h3>

ASP.NET pages are text files with an .aspx file name extension.  Pages consist of code and markup and are dynamically compiled and executed on the server to produce a rendering to the requesting client browser (or device). They can be deployed throughout an IIS
virtual root directory tree.  When a browser client requests .aspx resources, the ASP.NET runtime parses and compiles
the target file into a .NET Framework class.  This class can then be used to dynamically process incoming requests. (Note that
the .aspx file is compiled only the first time it is accessed; the compiled type instance is then reused across multiple
requests).

<br /><br />

An ASP.NET page can be created simply by taking an existing HTML file and changing its file name extension to .aspx (no
modification of code is required).  For example, the following sample demonstrates a simple HTML page that collects
a user's name and category preference and then performs a form postback to the originating page when a button
is clicked:

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/intro/intro1_cs.aspx"
        ViewSource="~/aspnet/samples/pages/intro/intro1.src"
        Caption="C# Intro1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/intro/intro1_vb.aspx"
        ViewSource="~/aspnet/samples/pages/intro/intro1.src"
        Caption="VB Intro1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br /><br />

<b>Important:</b> Note that nothing happens yet when you click the Lookup button.  This is because the .aspx file contains
only static HTML (no dynamic content).  Thus, the same HTML is sent back to the client on each trip to the page,
which results in a loss of the contents of the form fields (the text box and drop-down list) between requests.

<!--BEGIN SECTION-->
<a name="usingcode"></a>
<h3>Adding Simple Code to a Page</h3>

ASP.NET provides syntax compatibility with existing ASP pages. This includes support
for &lt;% %&gt; code render blocks that can be intermixed with HTML content within
an .aspx file. These code blocks execute in a top-down manner at page render time.

<br /><br />

The below example demonstrates how &lt;% %&gt; render blocks can be used to loop over an HTML block (increasing
the font size each time):

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/intro/intro2_cs.aspx"
        ViewSource="~/aspnet/samples/pages/intro/intro2.src"
        Caption="C# Intro2.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/intro/intro2_vb.aspx"
        ViewSource="~/aspnet/samples/pages/intro/intro2.src"
        Caption="VB Intro2.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br /><br />

<b>Important:</b> Unlike with ASP, the code used within the above &lt;% %&gt; blocks is actually compiled--not interpreted using a script engine.  This
results in improved runtime execution performance.

<br /><br />

ASP.NET page developers can utilize &lt;% %&gt; code blocks to dynamically modify HTML
output much as they can today with ASP. For example, the following sample demonstrates
how &lt;% %&gt; code blocks can be used to interpret results posted back from a client.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/intro/intro3_cs.aspx"
        ViewSource="~/aspnet/samples/pages/intro/intro3.src"
        Caption="C# Intro3.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/intro/intro3_vb.aspx"
        ViewSource="~/aspnet/samples/pages/intro/intro3.src"
        Caption="VB Intro3.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br /><br />

<b>Important:</b> While &lt;% %&gt; code blocks provide a powerful way to custom
manipulate the text output returned from an ASP.NET page, they do not 
provide a clean HTML programming model.  As the sample above illustrates, developers using
only &lt;% %&gt; code blocks must custom manage page state between round trips and custom
interpret posted values.

<!--BEGIN SECTION-->
<a name="serverctrls"></a>
<h3>Introduction to ASP.NET Server Controls</h3>

In addition to code and markup, ASP.NET pages can contain <b>server controls</b>, which are programmable server-side objects that typically represent a UI element in the page, such as a textbox or image.  Server controls participate in the execution of the page and produce their own markup rendering to the client.  The principle advantage of server controls is that they enable developers to get complex rendering and behaviors from simple building-block components, dramatically reducing the amount of code it takes to produce a dynamic Web page.
Another advantage of server controls is that it is easy to customize their rendering or behavior.  Server controls expose properties that can be set either declaratively (on the tag) or programmatically (in code).  Server controls (and the page itself) also expose events that developers can handle to perform specific actions during the page execution or in response to a client-side action that posts the page back to the server (a "postback").  Server controls also simplify the problem of retaining state across round-trips to the server, automatically retaining their values across successive postbacks.

<br /><br />

Server controls are declared within an .aspx file using custom tags or intrinsic HTML tags that contain
a <b>runat="server"</b> attribute value.  Intrinsic HTML tags are handled by one of the controls
in the <b>System.Web.UI.HtmlControls</b> namespace.  Any tag that doesn't explicitly map to one of
the controls is assigned the type of <b>System.Web.UI.HtmlControls.HtmlGenericControl</b>.

<br /><br />

The following sample uses four server controls: <b>&lt;form runat=server&gt;</b>, <b>&lt;asp:textbox runat=server&gt;</b>,
<b>&lt;asp:dropdownlist runat=server&gt;</b>, and <b>&lt;asp:button runat=server&gt;</b>.  At run time these server controls
automatically generate HTML content.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/intro/intro4_cs.aspx"
        ViewSource="~/aspnet/samples/pages/intro/intro4.src"
        Caption="C# Intro4.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/intro/intro4_vb.aspx"
        ViewSource="~/aspnet/samples/pages/intro/intro4.src"
        Caption="VB Intro4.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br /><br />

<b>Important:</b> Note that these server controls automatically maintain any client-entered values between round trips
to the server.  This control state is not stored on the server (it is instead stored within an
<b>&lt;input type="hidden"&gt;</b> form field that is round-tripped between requests).  Note also that no client-side script is
required.

<br /><br />

In addition to supporting standard HTML input controls, ASP.NET enables developers to utilize richer custom controls on their
pages.  For example, the following sample demonstrates how the <b>&lt;asp:adrotator&gt;</b> control can be used to dynamically
display rotating ads on a page.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/intro/intro5_cs.aspx"
        ViewSource="~/aspnet/samples/pages/intro/intro5.src"
        Caption="C# Intro5.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/intro/intro5_vb.aspx"
        ViewSource="~/aspnet/samples/pages/intro/intro5.src"
        Caption="VB Intro5.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br /><br />

<b>Important:</b> A detailed listing of all built-in server controls can
be found in the <asp:HyperLink NavigateUrl="~/aspnet/doc/ctrlref/standard/default.aspx" runat="server">Control Reference</asp:HyperLink> section of
this QuickStart.

<!--BEGIN SECTION-->
<a name="handlingevts"></a>
<h3>Handling Server Control Events</h3>

Each ASP.NET server control is capable of exposing an object model containing properties, methods, and events.  ASP.NET developers can
use this object model to cleanly modify and interact with the page.

<br /><br />

The following example demonstrates how an ASP.NET page developer can handle the <b>OnClick</b>
event from the <b>&lt;asp:button runat=server&gt;</b> control to manipulate the <b>Text</b> property
of the <b>&lt;asp:label runat=server&gt;</b> control.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/intro/intro6_cs.aspx"
        ViewSource="~/aspnet/samples/pages/intro/intro6.src"
        Caption="C# Intro6.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/intro/intro6_vb.aspx"
        ViewSource="~/aspnet/samples/pages/intro/intro6.src"
        Caption="VB Intro6.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br /><br />

This simple sample is functionally equivalent to the "Intro3" sample demonstrated earlier in this section.  Note, however,
how much cleaner and easier the code is in this new server-control-based version.  As we will see later in the tutorial, the ASP.NET page Framework also exposes
a variety of page-level events that you can handle to write code to execute a specific time during the processing of the page.  Examples of these events are Page_Load and Page_Render.

</asp:Content>

