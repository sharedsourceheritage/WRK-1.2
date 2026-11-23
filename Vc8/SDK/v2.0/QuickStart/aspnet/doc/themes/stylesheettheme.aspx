<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>

<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>


<h2>Server-side Styles using Themes</h2>

A Theme is meant to be applied to an application after the application has been created, possibly even 
after the site is already hosted on a production server.  The person applying the theme to an application
may not even be the same person who developed the application.  For example, it is common to have 
application developers and web site designers working on different aspects of the site.  When a Theme is
applied to an application, the style properties in the Theme definition override property values on
the target controls in the application's pages.
<br /><br />
On the other hand, it is also common for developers to factor out stylistic information separately
from application behavior.  One example of this is the use of Cascading Style Sheets (CSS) to define
control and markup styles in a separate file.  You can use Themes for this purpose as well, by applying
the Theme as a sort of server-side stylesheet.  When applied in this way, the style properties in the 
Theme definition set the default value for controls in the application, but these properties may also
be set on the control in the page to override the Theme definition.

<a name="styles"></a>
<h3>Declarative Server-side Styles</h3>

When a Theme is applied by setting the <b>Theme</b> attribute of the <code>@Page</code> directive or 
<code>&lt;pages/&gt;</code> section of configuration, the properties of skins in the theme override
same-named properties on the target controls in page.  The example below shows a Label in a page with
its ForeColor property set to blue.  In the applied Theme, the Label skin defined the ForeColor property
to orange.  When you run the page, notice that the Theme definition wins over the local control property,
and all Labels render as orange.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/themes/ThemeOverride_cs.aspx"
        ViewSource="~/aspnet/samples/themes/ThemeOverride.src"
        Caption="C# Themes Override Page Properties"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/themes/ThemeOverride_vb.aspx"
        ViewSource="~/aspnet/samples/themes/ThemeOverride.src"
        Caption="VB Themes Override Page Properties"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

A Theme definition can be applied as a server-side style by setting the <b>StyleSheetTheme</b> attribute
the <code>@Page</code> directive or <code>&lt;pages/&gt;</code> section of configuration to the name of the
Theme.  When applied as a StyleSheetTheme, Theme properties may be overridden by controls in the Page.
The example below shows the Theme from the previous example applied as a StyleSheetTheme.  Notice that the
ForeColor property defined on the page wins over the Theme definition, so that the Label now renders as blue.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/themes/StylesheetThemeOverride_cs.aspx"
        ViewSource="~/aspnet/samples/themes/StylesheetThemeOverride.src"
        Caption="C# Page Properties Override StylesheetThemes"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/themes/StylesheetThemeOverride_vb.aspx"
        ViewSource="~/aspnet/samples/themes/StylesheetThemeOverride.src"
        Caption="VB Page Properties Override StylesheetThemes"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

<a name="precedence"></a>
<h3>Theme and StyleSheetTheme Precedence</h3>

A StyleSheetTheme is meant to be applied during application development, as a means to factor our style
information from pages in order to keep the behavior of the application separately maintainable from the
look-and-feel of the application.  You may still want to apply Themes to an application with a StyleSheetTheme
applied.  If both a Theme and StyleSheetTheme are applied to an application, the properties of controls are applied in
the the following order:

<ul>
  <li>StyleSheetTheme properties are applied first
  <li>Control properties in the page are applied (overrides StyleSheetTheme)
  <li>Theme properties are applied last (overriding both control properties and the StyleSheetTheme)
</ul>

The following example demonstrates the order of precedence described above.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/themes/ThemesAndStylesheetThemes_cs.aspx"
        ViewSource="~/aspnet/samples/themes/ThemesAndStylesheetThemes.src"
        Caption="C# Themes and StylesheetThemes Precedence"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/themes/ThemesAndStylesheetThemes_vb.aspx"
        ViewSource="~/aspnet/samples/themes/ThemesAndStylesheetThemes.src"
        Caption="VB Themes and StylesheetThemes Precedence"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

<a name="vwd"></a>
<h3>Visual Web Developer Support</h3>

Visual Web Developer includes design-time support for StyleSheetThemes.  When a StyleSheetTheme is applied to a page,
the Design View in Visual Studio reflects the application of the StyleSheetTheme in the rendering preview for controls.
You can also choose from the list of available SkinID values for a control by choosing the <b>Auto Format...</b> option
in the control's smart task panel (only supported for certain controls).  The Auto Format dialog shows the list of 
available SkinID values from the StyleSheetTheme along with a preview of the control with the chosen skin applied.  
When you choose to apply one of these values, the designer persists the SkinID property for the control.
<br /><br />
<asp:Image ImageUrl="~/aspnet/images/figure8.gif" runat="server"/>

</asp:Content>

