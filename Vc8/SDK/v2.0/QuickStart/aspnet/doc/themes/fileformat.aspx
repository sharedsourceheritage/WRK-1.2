<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>

<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Contents of a Theme and Skin</h2>

As demonstrated in preceding sections, a <b>Skin</b> file contains control definitions with property 
values to apply to controls of the same type in the application.  This section discusses additional
details about what is valid content to add to a skin file or Theme.

<a name="properties"></a>
<h3>Themable Properties</h3>

The control definitions in a skin file can only contain values for properties that are marked as Themeable.  
Each control defines the set of properties that may be themed using the <b>ThemeableAttribute</b> on the 
property.  Adding a property that is not Themeable to a skin file results in an error.  A control itself
may also be excluded from a Theme, for example data source controls are not themeable. By default, the 
<b>ID</b> property is not themeable for any controls.  All properties are themeable by default unless a 
control specifies otherwise.  To check whether a given property is themeable for a control,
refer to the .NET Framework reference documentation.

<a name="css"></a>
<h3>Using CSS in Themes</h3>

A Cascading Style Sheet (CSS) may be added to a Theme by placing it under the named Theme subdirectory.
The CSS stylesheet will be applied to all pages with that theme applied, provided the page has a 
<code>&lt;head runat="server"/&gt;</code> control defined.  You can name the CSS file anything you want
as long at it has the <code>.css</code> extension.  A Theme may contain multiple CSS files as well.
When the page contains references to CSS files (using a <code>&lt;link rel="stylesheet" href="..."/&gt;</code> tag in 
the <code>&lt;head/&gt;</code> element), any CSS files in the Theme are applied after the page's stylesheets.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/themes/Stylesheet_cs.aspx"
        ViewSource="~/aspnet/samples/themes/Stylesheet.src"
        Caption="C# CSS Stylesheets in Themes"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/themes/Stylesheet_vb.aspx"
        ViewSource="~/aspnet/samples/themes/Stylesheet.src"
        Caption="VB CSS Stylesheets In Themes"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

<a name="images"></a>
<h3>Using Images in Themes</h3>

A Theme can also contain images that are referenced by control definition in skin file.  References to
images in skins should used relative paths to the images folder under the Theme directory, so that the
skin file and images can be easy moved together to other applications.  At runtime, the paths to images
are re-based so that the references are relative to the control in the target page instead of the skin 
file.  The following example demonstrates a Theme with an images subdirectory.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/themes/Images_cs.aspx"
        ViewSource="~/aspnet/samples/themes/Images.src"
        Caption="C# Images in Themes"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/themes/Images_vb.aspx"
        ViewSource="~/aspnet/samples/themes/Images.src"
        Caption="VB Images In Themes"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

<a name="collections"></a>
<h3>Theming Control Collections</h3>

Most of the properties you will set in a skin will be simple-valued properties such as <code>Font-Name</code>, 
<code>Width</code>, and <code>BackColor</code>.  However, you can also skin collection properties.  Skinning a 
collection property does not apply the properties to items in the collection of the target control.  Rather, it
replaces the collection in its entirety when using <b>Themes</b> and merges the collection when using <b>StyleSheetThemes.</b>  
The following example demonstrates the <b>Items</b> collection of a DropDownList control defined in a skin file.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/themes/ThemeCollection_cs.aspx"
        ViewSource="~/aspnet/samples/themes/ThemeCollection.src"
        Caption="C# Theming Collection Properties"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/themes/ThemeCollection_vb.aspx"
        ViewSource="~/aspnet/samples/themes/ThemeCollection.src"
        Caption="VB Theming Collection Properties"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

This is also useful for certain collection properties that contain collections
of styles, such as the LevelStyles property of the <b>TreeView</b> control or LevelMenuItemStyles, 
LevelSubMenuItemStyles or LevelSelectedStyles properties of the <b>Menu</b> control.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/themes/ThemeLevelStyles_cs.aspx"
        ViewSource="~/aspnet/samples/themes/ThemeLevelStyles.src"
        Caption="C# TreeView LevelStyles in a Theme"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/themes/ThemeLevelStyles_vb.aspx"
        ViewSource="~/aspnet/samples/themes/ThemeLevelStyles.src"
        Caption="VB TreeView LevelStyles in a Theme"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

<a name="templates"></a>
<h3>Theming Control Templates</h3>

You can also apply template properties in a skin file.  Like collections, defining a template property in a skin
file does not theme individual items in the target control's template, but instead replaces the entire template
contents.  This is useful for dramatically altering the layout of a templated control through the application
of a Theme or StyleSheetTheme.  

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/themes/ThemeTemplate_cs.aspx"
        ViewSource="~/aspnet/samples/themes/ThemeTemplate.src"
        Caption="C# Theming Template Properties"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/themes/ThemeTemplate_vb.aspx"
        ViewSource="~/aspnet/samples/themes/ThemeTemplate.src"
        Caption="VB Theming Template Properties"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

<a name="databinding"></a>
<h3>DataBindings and Expressions</h3>

Note that data bindings using <code>&lt;%# Eval %&gt;</code> or <code>&lt;%# Bind %&gt;</code> are also 
valid in a theme template, however arbitrary code data bindings or expressions are not allowed.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/themes/ThemeDataBind_cs.aspx"
        ViewSource="~/aspnet/samples/themes/ThemeDataBind.src"
        Caption="C# Data Bindings in Themes"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/themes/ThemeDataBind_vb.aspx"
        ViewSource="~/aspnet/samples/themes/ThemeDataBind.src"
        Caption="VB Data Bindings in Themes"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

</asp:Content>

