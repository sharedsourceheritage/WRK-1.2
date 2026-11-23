<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>

<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Applying Styles to Controls</h2>

The Web is a flexible environment for user interfaces, with extreme variations in the look and feel of different Web sites.  The
widespread adoption of cascading style sheets (CSS) is largely responsible for the rich designs encountered on the Web.  All of ASP.NET's HTML server controls and Web server controls
have been designed to provide first-class support for CSS styles. This section discusses how to use 
styles in conjunction with server controls and demonstrates the very fine control over the look and feel of your Web Forms that they provide.

<!--BEGIN SECTION-->
<a name="htmlstyles"></a>
<h3>Applying Styles to HTML Controls</h3>

Standard HTML tags support CSS through a style attribute, which can be set to a semicolon-delimited list of attribute/value pairs.
For more information about the CSS attributes supported by the Internet Explorer browser, see
MSDN Web Workshop's <a target="_blank" href="http://msdn.microsoft.com/workshop/author/css/reference/attributes.asp">CSS Attributes Reference</a> page.
All of the ASP.NET HTML server controls can accept styles in exactly the same manner as standard HTML tags.  The following example
illustrates a number of styles applied to various HTML server controls.  If you view the source code on the page returned to the client, you will see that these styles are passed along to the browser in the control's rendering.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/styles/style1_cs.aspx"
        ViewSource="~/aspnet/samples/styles/style1.src"
        Caption="C# Style1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/styles/style1_vb.aspx"
        ViewSource="~/aspnet/samples/styles/style1.src"
        Caption="VB Style1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

CSS also defines a class attribute, which can be set to a CSS style definition contained in a &lt;style&gt;...&lt;/style&gt; section of
the document.  The class attribute makes it easy to define styles once and apply them to several tags without having to redefine the
style itself.  Styles on HTML server controls also can be set in this manner, as demonstrated in the following sample.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/styles/style2_cs.aspx"
        ViewSource="~/aspnet/samples/styles/style2.src"
        Caption="C# Style2.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/styles/style2_vb.aspx"
        ViewSource="~/aspnet/samples/styles/style2.src"
        Caption="VB Style2.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

When an ASP.NET page is parsed, the style information is populated into a <b>Style</b> property (of type <b>CssStyleCollection</b>)
on the <b>System.Web.UI.HtmlControls.HtmlControl</b> class.  This property is essentially a dictionary  that exposes the control's
styles as a string-indexed collection of values for each style-attribute key.  For example, you could use the following code to set and
subsequently retrieve the <b>width</b> style attribute on an <b>HtmlInputText</b> server control.

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
&lt;script language="C#" runat="server" &gt;

    void Page_Load(Object sender, EventArgs E) {
        MyText.Style["width"] = "90px";
        Response.Write(MyText.Style["width"]);
    }

&lt;/script&gt;

&lt;input type="text" id="MyText" runat="server"/&gt;
</Tab>

<Tab Name="VB">
&lt;script language="VB" runat="server" &gt;

    Sub Page_Load(Sender As Object, E As EventArgs)
        MyText.Style("width") = "90px"
        Response.Write(MyText.Style("width"))
    End Sub

&lt;/script&gt;

&lt;input type="text" id="MyText" runat="server"/&gt;
</Tab>

</Acme:TabControl>

<br />

This next sample shows how you can programmatically manipulate the style for an HTML server control using this <b>Style</b> collection property.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/styles/style3_cs.aspx"
        ViewSource="~/aspnet/samples/styles/style3.src"
        Caption="C# Style3.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/styles/style3_vb.aspx"
        ViewSource="~/aspnet/samples/styles/style3.src"
        Caption="VB Style3.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<!--BEGIN SECTION-->
<a name="webstyles"></a>
<h3>Applying Styles to Web Server Controls</h3>

Web server controls provide an additional level of support for styles by adding several strongly typed properties for commonly used
style settings, such as background and foreground color, font name and size, width, height, and so on.  These style properties represent a
subset of the style behaviors available in HTML and are represented as "flat" properties exposed directly on the
<b>System.Web.UI.WebControls.WebControl</b> base class.  The advantage of using these properties is that they provide
compile-time type checking and statement completion in development tools such as Microsoft Visual Studio .NET.

<br /><br />

The following sample shows a <b>WebCalendar</b> control with several styles applied to it (a calendar without styles applied is included for
contrast).  Note that when setting a property that is a class type, such as <b>Font</b>, you need to use the subproperty syntax
 <i>PropertyName-SubPropertyName</i> .

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/styles/style4_cs.aspx"
        ViewSource="~/aspnet/samples/styles/style4.src"
        Caption="C# Style4.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/styles/style4_vb.aspx"
        ViewSource="~/aspnet/samples/styles/style4.src"
        Caption="VB Style4.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

The <b>System.Web.UI.WebControls</b> namespace includes a <b>Style</b> base class that encapsulates common style
attributes (additional style classes, such as <b>TableStyle</b> and <b>TableItemStyle</b>, inherit from
this common base class).  Many Web server controls expose properties of this type for specifying the style of individual rendering
elements of the control.  For example, the <b>WebCalendar</b> exposes many such style properties: <b>DayStyle</b>,
<b>WeekendDayStyle</b>, <b>TodayDayStyle</b>, <b>SelectedDayStyle</b>, <b>OtherMonthDayStyle</b>,
and <b>NextPrevStyle</b>.  You can set individual properties of these styles using the subproperty syntax
<i>PropertyName-SubPropertyName</i>, as the following sample demonstrates.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/styles/style5_cs.aspx"
        ViewSource="~/aspnet/samples/styles/style5.src"
        Caption="C# Style5.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/styles/style5_vb.aspx"
        ViewSource="~/aspnet/samples/styles/style5.src"
        Caption="VB Style5.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

A slightly different syntax allows each <b>Style</b> property to be declared as a child element nested within Web server control tags.

<br /><br />

<pre class="code">
&lt;ASP:Calendar ... runat="server"&gt;
    &lt;TitleStyle BorderColor="darkolivegreen" BorderWidth="3"
            BackColor="olivedrab" Height="50px" /&gt;
&lt;/ASP:Calendar&gt;
</pre>

The following sample shows alternative syntax but is functionally equivalent to the preceding one.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/styles/style6_cs.aspx"
        ViewSource="~/aspnet/samples/styles/style6.src"
        Caption="C# Style6.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/styles/style6_vb.aspx"
        ViewSource="~/aspnet/samples/styles/style6.src"
        Caption="VB Style6.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

As with HTML server controls, you can apply styles to Web server controls using a CSS class definition. The <b>WebControl</b> base class exposes a <b>String</b> property named <b>CssClass</b> for setting the style class:

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/styles/style7_cs.aspx"
        ViewSource="~/aspnet/samples/styles/style7.src"
        Caption="C# Style7.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/styles/style7_vb.aspx"
        ViewSource="~/aspnet/samples/styles/style7.src"
        Caption="VB Style7.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

If an attribute is set on a server control that does not correspond to any strongly typed property on the control, the attribute
and value are populated in the <b>Attributes</b> collection of the control.  By default, server controls will render these attributes
unmodified in the HTML returned to the requesting browser client.  This means that the style and class attributes can be
set on Web server controls directly instead of using the strongly typed properties. While this requires some understanding of the actual
rendering of the control, it can be a flexible way to apply styles as well.  It is especially useful for the standard form input controls,
as illustrated in the following sample.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/styles/style8_cs.aspx"
        ViewSource="~/aspnet/samples/styles/style8.src"
        Caption="C# Style8.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/styles/style8_vb.aspx"
        ViewSource="~/aspnet/samples/styles/style8.src"
        Caption="VB Style8.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

Web server control styles can also be set programmatically, using the <b>ApplyStyle</b> method of the base <b>WebControl</b> class, as in the following code.

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
&lt;script language="C#" runat="server"&gt;
    void Page_Load(Object Src, EventArgs E ) {
        Style style = new Style();
        style.BorderColor = Color.Black;
        style.BorderStyle = BorderStyle.Dashed;
        style.BorderWidth = 1;

        MyLogin.ApplyStyle (style);
        MyPassword.ApplyStyle (style);
        MySubmit.ApplyStyle (style);
    }
&lt;/script&gt;

Login: &lt;ASP:TextBox id="MyLogin" runat="server" /&gt;/&lt;p/&gt;
Password: &lt;ASP:TextBox id="MyPassword" TextMode="Password" runat="server" /&gt;
View:  &lt;ASP:DropDownList id="MySelect" runat="server"&gt;  ...  &lt;/ASP:DropDownList&gt;
</Tab>

<Tab Name="VB">
&lt;script language="VB" runat="server"&gt;
    Sub Page_Load(Src As Object, E As EventArgs)
        Dim MyStyle As New Style
        MyStyle.BorderColor = Color.Black
        MyStyle.BorderStyle = BorderStyle.Dashed
        MyStyle.BorderWidth = New Unit(1)

        MyLogin.ApplyStyle (MyStyle)
        MyPassword.ApplyStyle (MyStyle)
        MySubmit.ApplyStyle (MyStyle)
    End Sub
&lt;/script&gt;

Login: &lt;ASP:TextBox id="MyLogin" runat="server" /&gt;/&lt;p/&gt;
Password: &lt;ASP:TextBox id="MyPassword" TextMode="Password" runat="server" /&gt;
View:  &lt;ASP:DropDownList id="MySelect" runat="server"&gt;  ...  &lt;/ASP:DropDownList&gt;
</Tab>

</Acme:TabControl>

<br />

The following sample demonstrates the code above.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/styles/style9_cs.aspx"
        ViewSource="~/aspnet/samples/styles/style9.src"
        Caption="C# Style9.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/styles/style9_vb.aspx"
        ViewSource="~/aspnet/samples/styles/style9.src"
        Caption="VB Style9.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>

