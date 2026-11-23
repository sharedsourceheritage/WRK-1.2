<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>

<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Web Forms Syntax Reference</h2>

An ASP.NET Web Forms page is a declarative text file with an .aspx file name extension.
In addition to static content, you can use eight distinct syntax markup elements.
This section of the QuickStart reviews each of these syntax elements and provides
examples demonstrating their use.

<!--BEGIN SECTION-->
<a name="render"></a>
<h3>Rendering Code Syntax: &lt;% %&gt;  and &lt;%= %&gt;</h3>

Code rendering blocks are denoted with &lt;% ... %&gt; elements, allow you to custom-control
content emission, and execute during the render phase of Web Forms page execution.
The following example demonstrates how you can use them to loop over HTML content.

<br /><br />

<Acme:TabControl runat="server">

<Tab Name="C#">
&lt;% for (int i=0; i<8; i++) { %&gt;
     &lt;font size="&lt;%=i%&gt;"&gt; Hello World! &lt;/font&gt; &lt;br&gt;
&lt;% } %&gt;
</Tab>

<Tab Name="VB">
&lt;% For I=0 To 7 %&gt;
     &lt;font size="&lt;%=i%&gt;"&gt; Hello World! &lt;/font&gt; &lt;br&gt;
&lt;% Next %&gt;
</Tab>

</Acme:TabControl>

<br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/reference/reference1_cs.aspx"
        ViewSource="~/aspnet/samples/pages/reference/reference1.src"
        Caption="C# Reference1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/reference/reference1_vb.aspx"
        ViewSource="~/aspnet/samples/pages/reference/reference1.src"
        Caption="VB Reference1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

Code enclosed by &lt;% ... %&gt; is just executed, while expressions that include an
equal sign, &lt;%= ... %&gt;, are evaluated and the result is emitted as content.
Therefore <code><nobr>&lt;%="Hello World" %&gt;</nobr></code> renders the same thing as the C#
code <code><nobr>&lt;% Response.Write("Hello World"); %&gt;</nobr></code>.

<br /><br />

<b>Note:</b> For languages that use marks to end or separate statements
(for example, the semicolon (;) in C#), it is important to place those marks correctly depending on how your code should be rendered.

<br /><br />

<table class="table" cellpadding=3>
<tr><th colspan="2"><b>C# code</b></th></tr>
<tr>
  <td><code>&lt;% Response.Write("Hello World"); %&gt;</code></td>
  <td>A semicolon is necessary to end the statement.</td></tr>
<tr>
  <td><code>&lt;%="Hello World"; %&gt;</code></td>
  <td>Wrong: Would result in "<code>Response.Write("Hello World";);</code>".</td></tr>
<tr>
  <td><code>&lt;%="Hello World" %&gt;</code></td><td>A semicolon is not necessary.</td></tr>
</table>


<!--BEGIN SECTION-->
<a name="code"></a>
<h3>Declaration Code Syntax: &lt;script runat="server"&gt; </h3>

Code declaration blocks define member variables and methods that will be compiled into the
generated <b>Page</b> class.  These blocks can be used to author page and navigation logic.
The following example demonstrates how a <b>Subtract</b> method can be declared within a
<b>&lt;script runat="server"&gt;</b> block, and then invoked from the page.

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
&lt;script language="C#" runat=server&gt;
int subtract(int num1, int num2) {
  return num1 - num2;
}
&lt;/script&gt;

&lt;%
  ...
  number = subtract(number, 1);
  ...
%&gt;
</Tab>

<Tab Name="VB">
&lt;script language="VB" runat=server&gt;
Function Subtract(num1 As Integer, num2 As Integer) As Integer
  Return(num1 - num2)
End Function
&lt;/script&gt;

&lt;%
  ...
  number = subtract(number, 1)
  ...
%&gt;
</Tab>

</Acme:TabControl>

<br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/reference/reference2_cs.aspx"
        ViewSource="~/aspnet/samples/pages/reference/reference2.src"
        Caption="C# Reference2.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/reference/reference2_vb.aspx"
        ViewSource="~/aspnet/samples/pages/reference/reference2.src"
        Caption="VB Reference2.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

<b>Important:</b> Unlike ASP -- where functions could be declared within &lt;% %&gt; blocks --
all functions and global page variables must be declared in a <b>&lt;script runat=server&gt;</b>
tag.  Functions declared within &lt;% %&gt; blocks will now generate a syntax compile error.


<!--BEGIN SECTION-->
<a name="ctrl"></a>
<h3>Server Control Syntax</h3>

Custom ASP.NET server controls enable page developers to dynamically generate HTML user interface (UI) and respond to
client requests. They are represented within a file using a declarative, tag-based syntax.
These tags are distinguished from other tags because they contain a <b>"runat=server"</b> attribute.
The following example demonstrates how an <b>&lt;asp:label runat="server"&gt;</b> server control can be
used within an ASP.NET page. This control corresponds to the <b>Label</b> class in the
<b><nobr>System.Web.UI.WebControls</nobr></b> namespace, which is included by default.

<br /><br />

By adding a tag with the ID "Message", an instance of <b>Label</b> is created at run time:

<br /><br />

<pre class="code">&lt;asp:label id="Message" font-size=24 runat="server"/&gt;</pre>

The control can then be accessed using the same name. The following line sets the <b>Text</b> property
of the control.

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
Message.Text = "Welcome to ASP.NET";
</Tab>

<Tab Name="VB">
Message.Text = "Welcome to ASP.NET"
</Tab>

</Acme:TabControl>

<br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/reference/reference3_cs.aspx"
        ViewSource="~/aspnet/samples/pages/reference/reference3.src"
        Caption="C# Reference3.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/reference/reference3_vb.aspx"
        ViewSource="~/aspnet/samples/pages/reference/reference3.src"
        Caption="VB Reference3.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<!--BEGIN SECTION-->
<a name="htmlctrl"></a>
<h3>HTML Server Control Syntax </h3>

HTML server controls enable page developers to programmatically manipulate HTML elements
within a page.  An HTML server control tag is distinguished from client HTML elements
by means of a <b>"runat=server"</b> attribute.  The following example demonstrates how an HTML
<b>&lt;span runat=server&gt;</b> server control can be used within an ASP.NET page.

<br /><br />

As with other server controls, the methods and properties are accessible programmatically, as shown in the following example.

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
&lt;script language="C#" runat="server"&gt;
  void Page_Load(Object sender, EventArgs e) {
    Message.InnerHtml = "Welcome to ASP.NET";
  }
&lt;/script&gt;
...
&lt;span id="Message" style="font-size:24" runat="server"/&gt;
</Tab>

<Tab Name="VB">
&lt;script language="VB" runat="server"&gt;
  Sub Page_Load(sender As Object, e As EventArgs)
    Message.InnerHtml = "Welcome to ASP.NET"
  End Sub
&lt;/script&gt;
...
&lt;span id="Message" style="font-size:24" runat="server"/&gt;
</Tab>

</Acme:TabControl>

<br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/reference/reference4_cs.aspx"
        ViewSource="~/aspnet/samples/pages/reference/reference4.src"
        Caption="C# Reference4.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/reference/reference4_vb.aspx"
        ViewSource="~/aspnet/samples/pages/reference/reference4.src"
        Caption="VB Reference4.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<!--BEGIN SECTION-->
<a name="databind"></a>
<h3>Data Binding Syntax: &lt;%# %&gt; </h3>

The data binding support built into ASP.NET enables page developers to hierarchically bind
control properties to data container values.  Code located within a &lt;%# %&gt;
code block is only executed when the <b>DataBind</b> method of its parent control
container is invoked.  The following example demonstrates how to use the data binding
syntax within an <b>&lt;asp:datalist runat=server&gt;</b> control.

<br /><br />

Within the datalist, the template for one item is specified. The content of the item template
is specified using a data binding expression and the <code>Container.DataItem</code> refers to the data
source used by the datalist <code>MyList</code>.

<pre class="code">
&lt;asp:datalist id="MyList" runat=server&gt;
  &lt;ItemTemplate&gt;
    Here is a value: &lt;%# Container.DataItem %&gt;
  &lt;/ItemTemplate&gt;
&lt;/asp:datalist&gt;
</pre>

In this case the data source of the <code>MyList</code> control is set programmatically, and
then <code>DataBind()</code> is called.

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
void Page_Load(Object sender, EventArgs e) {
  ArrayList items = new ArrayList();

  items.Add("One");
  items.Add("Two");
  items.Add("Three");

  MyList.DataSource = items;
  MyList.DataBind();
}
</Tab>

<Tab Name="VB">
Sub Page_Load(sender As Object, e As EventArgs)
  Dim items As New ArrayList()

  items.Add("One")
  items.Add("Two")
  items.Add("Three")

  MyList.DataSource = items
  MyList.DataBind()
End Sub
</Tab>

</Acme:TabControl>

<br />

Calling the <b>DataBind</b> method of a control causes a recursive tree walk from that
control on down in the tree; the <b>DataBinding</b> event is raised on each
server control in that hierarchy, and data binding expressions on the control are
evaluated accordingly. So, if the <b>DataBind</b> method of the page is called, then every
data binding expression within the page will be called.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/reference/reference5_cs.aspx"
        ViewSource="~/aspnet/samples/pages/reference/reference5.src"
        Caption="C# Reference5.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/reference/reference5_vb.aspx"
        ViewSource="~/aspnet/samples/pages/reference/reference5.src"
        Caption="VB Reference5.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

ASP.NET 2.0 also includes a new simplified databinding syntax, that
allows controls to automatically data-bind to data source controls, 
without requiring you to call DataBind() in page code.  This syntax
is discussed in the section on <asp:HyperLink NavigateUrl="~/aspnet/doc/data/default.aspx" runat="server">Performing Data Access</asp:HyperLink>.

<!--BEGIN SECTION-->
<a name="object"></a>
<h3>Object Tag Syntax: &lt;object runat="server" /&gt;</h3>

Object tags enable page developers to declare and create instances of variables using a declarative, tag-based syntax. The
following example demonstrates how the object tag can be used to create an instance of an <b>ArrayList</b> class.

<pre class="code">
&lt;object id="items" class="System.Collections.ArrayList" runat="server"/&gt;
</pre>

The object will be created automatically at run time and can then be accessed through the ID "items".

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
void Page_Load(Object sender, EventArgs e) {
  items.Add("One");
  items.Add("Two");
  items.Add("Three");
  ...
}
</Tab>

<Tab Name="VB">
Sub Page_Load(sender As Object, e As EventArgs)
  items.Add("One")
  items.Add("Two")
  items.Add("Three")
  ...
End Sub
</Tab>

</Acme:TabControl>

<br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/reference/reference6_cs.aspx"
        ViewSource="~/aspnet/samples/pages/reference/reference6.src"
        Caption="C# Reference6.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/reference/reference6_vb.aspx"
        ViewSource="~/aspnet/samples/pages/reference/reference6.src"
        Caption="VB Reference6.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>


<!--BEGIN SECTION-->
<a name="comment"></a>
<h3>Server-Side Comment Syntax: &lt;%-- Comment --%&gt;</h3>

Server-side comments enable page developers to prevent server code (including server controls) and
static content from executing or rendering.  The following sample demonstrates how to block content from
executing and being sent down to a client. Note that everything between &lt;%-- and --%&gt; is
filtered out and only visible in the original server file, even though it contains other ASP.NET
directives.

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
&lt;%--
  &lt;asp:calendar id="MyCal" runat=server/&gt;
    &lt;% for (int i=0; i<45; i++) { %&gt;
             Hello World &lt;br&gt;
    &lt;% } %&gt;
--%&gt;
</Tab>

<Tab Name="VB">
&lt;%--
  &lt;asp:calendar id="MyCal" runat=server/&gt;
    &lt;% For I=0 To 44 %&gt;
             Hello World &lt;br&gt;
    &lt;% Next %&gt;
--%&gt;
</Tab>

</Acme:TabControl>

<br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/reference/reference7_cs.aspx"
        ViewSource="~/aspnet/samples/pages/reference/reference7.src"
        Caption="C# Reference7.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/reference/reference7_vb.aspx"
        ViewSource="~/aspnet/samples/pages/reference/reference7.src"
        Caption="VB Reference7.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>


<!--BEGIN SECTION-->
<a name="include"></a>
<h3>Server-Side Include Syntax: &lt;-- #Include File="Locaton.inc" --&gt;</h3>

Server-side #Includes enable developers to insert the raw contents of a specified file anywhere
within an ASP.NET page.  The following sample demonstrates how to insert a custom header and footer within a page.

<pre class="code">
&lt;!-- #Include File="Header.inc" --&gt;
...
&lt;!-- #Include File="Footer.inc" --&gt;
</pre>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/reference/reference8_cs.aspx"
        ViewSource="~/aspnet/samples/pages/reference/reference8.src"
        Caption="C# Reference8.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/pages/reference/reference8_vb.aspx"
        ViewSource="~/aspnet/samples/pages/reference/reference8.src"
        Caption="VB Reference8.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<!--BEGIN SECTION-->
<a name="expressions"></a>
<h3>Expression Syntax: &lt;%$ ... %&gt; <span class="newinline">New in 2.0</span></h3>

ASP.NET 2.0 adds a new declarative expression syntax for substituting values into a page before the
page is parsed.  This is useful for substituting connection string values or application settings
defined in a Web.config file for server control property values.  It can also be used to substitute values from a resource file for locaization.  More on connection string and resources expressions
and expression handlers can be found in the <asp:HyperLink NavigateUrl="~/aspnet/doc/data/default.aspx" runat="server">Performing Data Access</asp:HyperLink>, <asp:HyperLink NavigateUrl="~/aspnet/doc/localization/default.aspx" runat="server">Internationalizing Your Application</asp:HyperLink> and <asp:HyperLink NavigateUrl="~/aspnet/doc/extensibility.aspx" runat="server">Extending ASP.NET</asp:HyperLink> sections.

<pre class="code">
&lt;asp:SqlDataSource ID="SqlDataSource1" ConnectionString='&lt;%$ connectionStrings:Pubs %&gt;' runat="server" SelectCommand="sp_GetAuthors" /&gt;
&lt;asp:Label ID="Label1" Text='&lt;%$ Resources: ExchRate, ConvertLabel %&gt;' runat="server"/&gt;
</pre>

</asp:Content>

