<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>

<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>


<h2>Using Themes to Customize a Site</h2>

The previous section demonstrated a variety of ways to specify styles for controls by setting style properties
on controls themselves.  For example, consider the following page, which has a number of style settings applied 
to individual controls on the page.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/themes/NoTheme_cs.aspx"
        ViewSource="~/aspnet/samples/themes/NoTheme.src"
        Caption="C# Page with No Theme Applied"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/themes/NoTheme_vb.aspx"
        ViewSource="~/aspnet/samples/themes/NoTheme.src"
        Caption="VB Page with No Theme Applied"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

In addition to specifying styles on individual controls, ASP.NET 2.0 introduces <b>Themes</b>, which provide an easy way 
to define the style settings for controls and pages in your site separately from the pages of your application.  The benefit 
of Themes is that you can design a site without regard for the style and apply the style at a later time without having to 
update the pages or application code.  You can also obtain custom Themes from external sources to apply stylistic settings
to your application.  The benefit of a Theme is that the style settings are stored in a single location that can be maintained
separately from the application to which the Theme is applied.
<br /><br />

The following example demonstrates the same page with a Theme applied in order to specify the style 
settings for the control.  Notice that the page itself does not need to contain any style information.  The Theme automatically
applies style properties at runtime to controls on the page.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/themes/Theme_cs.aspx"
        ViewSource="~/aspnet/samples/themes/Theme.src"
        Caption="C# Page with Example Theme Applied"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/themes/Theme_vb.aspx"
        ViewSource="~/aspnet/samples/themes/Theme.src"
        Caption="VB Page with Example Theme Applied"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

<a name="folder"></a>
<h3>The App_Themes Folder</h3>

Themes reside in the App_Themes folder directly under the application root directory.  A Theme consists of a named subdirectory 
under this folder that contains a collection of one or more <b>Skin</b> files, named with the <code>.skin</code> extension. A Theme
can also contain a CSS file and/or subdirectories for static files like images.  The figure below shows an App_Themes directory with
two Themes defined, named "Default" and "White", each of which has a single skin file and CSS file.
<br /><br />

<asp:Image ImageUrl="~/aspnet/images/figure7.gif" runat="server"/>
<br /><br />

Observe in the previous example that the contents of a skin file are simply control definitions as they might appear in a page.  A skin file can
contain multiple control definitions, for example one definition for each control type.  The properties of controls defined in the theme 
automatically override the local property value for a control of the same type in the target page with the Theme applied.
For example, a &lt;asp:Calendar Font-Name="Verdana" runat="server"/&gt; control definition in a skin file will cause all
Calendar controls in pages with the Theme applied to use the Verdana font.  A local value for this property on the 
control will be overridden by the Theme.  Note that it is an error to specify an <b>ID</b> property value for
a control definition in a skin file.  

<a name="global"></a>
<h3>Global and Application Themes</h3>

A Theme can reside at the application-level or machine-level (globally available to all applications).  Application-level Themes are
placed in the App_Themes directory under the application root directory, as described above.  Global Themes are placed in a "Themes" directory
under an ASP.NETClientFiles folder under the ASP.NET installation directory, for example <code>%WINDIR%\Microsoft.NET\Framework\&lt;version&gt;\ASP.NETClientFiles\Themes</code>.
The location of global themes is <code>Inetpub\wwwroot\aspnet_client\system_web\&lt;version&gt;\Themes</code> for IIS web sites.

<a name="directive"></a>
<h3>Assigning a Theme to a Page</h3>

An individual page can be assigned a Theme by setting the <code>&lt;%@ Page Theme="..." %&gt;</code> directive to the name of a global or application-level Theme (the name of a folder under the Themes or App_Themes directory).
A page can only have one Theme applied, but there may be multiple skin files in the theme that apply style settings to controls in the page. 

<a name="config"></a>
<h3>Assigning a Theme in Config</h3>

You can also define the applied theme for all pages in an application by specifying the 
<code>&lt;pages theme="..."/&gt;</code> section in Web.config.  To unset this theme for a particular page, 
you can set the Theme attribute of the Page directive to empty string (<code>""</code>).  Note that a 
master page cannot have a Theme applied; you should set the Theme on content pages or in configuration
(described below) instead.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        ViewSource="~/aspnet/samples/themes/Web.config.example.src"
        Caption="C# Assigning a Theme in Web.config"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        ViewSource="~/aspnet/samples/themes/Web.config.example.src"
        Caption="VB Assigning a Theme in Web.config"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

<a name="disable"></a>
<h3>Disabling Themes for a Control</h3>

A specific control can be excluded from having the Theme override its properties by setting the 
<b>EnableTheming</b> property to <code>false</code>.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/themes/ThemeDisabled_cs.aspx"
        ViewSource="~/aspnet/samples/themes/ThemeDisabled.src"
        Caption="C# Disabling Themes for a Control"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/themes/ThemeDisabled_vb.aspx"
        ViewSource="~/aspnet/samples/themes/ThemeDisabled.src"
        Caption="VB Disabling Themes for a Control"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

</asp:Content>

