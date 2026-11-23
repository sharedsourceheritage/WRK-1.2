<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.Menu" runat="server">
  Menu
</Acme:TypeRef>
</h2>

The Menu control is comprised of one or more MenuItems typically organized into different levels of a hierarchy. Each MenuItem consists of properties that determine the look and feel of the MenuItem (e.g. text, navigateURL, etc). 
The Menu control conceptually contains two types of Menus: a StaticMenu that is always displayed on the page, and a DynamicMenu that pops out when the user opens a parent MenuItem. 
<br /><br />

<b>Note: </b>To accomplish the pop-out behavior the Menu control relies on javascript, on downlevel browsers the Menu renders using secondary navigation to enable accessing child menu items.

<br/><br/>
<b>Note:</b> Some samples for this control use Master Pages. For more information on <asp:hyperlink navigateurl ="~/aspnet/doc/masterpages/default.aspx"    runat="server"> Master Pages</asp:hyperlink>. 
<br /><br /> 

<h3>Menu Data Options </h3>

The Menu supports displaying data from a hierarchal datasource control or from items that are declaratively or programmatically added to the control's Items collection. The Menu control will automatically databind the values of the <asp:hyperlink navigateurl ="~/aspnet/doc/ctrlref/data/sitemapdatasource.aspx" runat="server"> SiteMapDataSource control</asp:hyperlink>. 

<h3>StaticMenuItemCollection Sample</h3> 

This sample demonstrates the basic Menu functionality when you specify the collection of MenuItems within the control instead of databinding the Menu control. 
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/navigation/Menu/StaticMenuItemCollection_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/Menu/StaticMenuItemCollection.src"
        Caption="C# Menu With Static Items"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/navigation/Menu/StaticMenuItemCollection_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/Menu/StaticMenuItemCollection.src"
        Caption="VB Menu With Static Items"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<h3>Menu Using a SiteMapDataSource control</h3>

There are two samples in this page that each use a Menu control associated with a SiteMapDataSource control on the page by setting the Menu DataSourceID property.  The SiteMapDataSource control is using the default SiteMap Provider and web.sitemap XML file to retrieve the data.  Since the SiteMapDataSource control returns a well known data format the Menu control automatically databinds the title, url, description, etc to the corresponding MenuItem properties for use in rendering.  By default the SiteMapDataSource control returns all SiteMapNode items for display and the Menu defaults to display a single static level of data, this default combination results in a single item on the page which pop-outs to expose the rest of the hierarchy dynamically.  A more typically Menu rendering involves several Menu Items being displayed statically on the page where one or many of these items pop-outs to expose additional Menu Item options.  The SiteMapDataSource controls what data is retrieved from the Site Navigation API by specifying the StartingNodeUrl and the ShowStartingNode Boolean property that provides an easy way to hide the root SiteMapNode. The Menu control  supports setting the number of levels in Menu hierarchy to be displayed statically on the page by setting the StaticDisplayLevels property and the number of levels to be displayed dynamically by setting the MaximumDisplayLevels. 
<br /><br />	

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/navigation/Menu/MenuUsingSiteMapDataSource_cs/ContentPages/LibraryHome.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/Menu/MenuUsingSiteMapDataSource.src"
        Caption="C# Menu Bound to SiteMapDataSource"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/navigation/Menu/MenuUsingSiteMapDataSource_vb/ContentPages/LibraryHome.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/Menu/MenuUsingSiteMapDataSource.src"
        Caption="VB Menu Bound to SiteMapDataSource"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<h3>Menu Using a XMLDataSource control</h3>
In this sample, the Menu control is databound to an XMLDataSource control that retrieves its data from the sitemap.xml file to demonstrate how to databind the XML data to the corresponding MenuItem properties. Unlike with the SiteMapDataSource control which automatically databinds, you are responsible for the databinding when you use an XMLDataSource control since it is not guaranteed to return a well known API to the Menu control. You can use the XPath property of the XMLDataSource control to select what nodes should be included for display in the Menu control. 

<b>Note: </b>This sample demonstrates a navigation scenario but remember that the Menu control can be used in a lot of different scenarios like walking a product hierarchy or geographic listings.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/navigation/Menu/MenuUsingXmlDataSource_cs/ContentPages/LibraryHome.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/Menu/MenuUsingXmlDataSource.src"
        Caption="C# Menu Bound to XmlDataSource"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/navigation/Menu/MenuUsingXmlDataSource_vb/ContentPages/LibraryHome.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/Menu/MenuUsingXmlDataSource.src"
        Caption="VB Menu Bound to XmlDataSource"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<h3>Menu Appearance </h3>

The Menu supports a large number of properties that enable you to declaratively change how the Menu is displayed.  In addition to the properties that can be set on the control or in a theme or skin, the Menu control also supports templating MenuItems. 

<h3>Menu Display Behaviors </h3>

This sample takes advantage of the following behavior properties to change the look of the Menu without taking full advantage of the style properties available. 
<br /><br />

<b>Orientation:</b> By setting the Orientation property from the default vertical setting to horizontal the Menu quickly adapts to a menu suitable to display at the top or bottom of a page. Several StaticMenuItem style properties are also set in this example (e.g. HorizontalPadding) to improve the visual display in horizontal mode.
<br /><br />

<b>StaticFormatString:</b> This property enables you to easily have the text displayed around the data bound to the title property. In your format string use the {0} to represent where the data should be inserted in your string. In this example it asks you to Read all of the books in the static level of the Menu. The DynamicFormatString enables you to set this information for the menu items that are displayed dynamically. 
<br /><br />

<b>StaticPopOutImageUrl:</b> A replacement image is also supplied for the StaticPopOutImage that indicates when a MenuItem can be hovered over to display it's child items. The default image will continue to be used for MenuItems that appear dynamically and have additional child items to be displayed. This functionality is controlled by the DynamicPopOutImageUrl. 
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/navigation/Menu/MenuBehaviors_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/Menu/MenuBehaviors.src"
        Caption="C# Menu Behaviors"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/navigation/Menu/MenuBehaviors_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/Menu/MenuBehaviors.src"
        Caption="VB Menu Behaviors"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<h3> Menu Styles </h3>
The Menu control supports an almost daunting number of styles that can easily seem overwhelming.  However, by learning a few key concepts and associated terminology for the Menu you will find the styles versatile and easy to use.  A Menu is composed of one or many MenuLevels and each MenuLevel can contain one or more MenuItem.  The Menu control supports setting styles on individual MenuItems or individual MenuLevels and MenuSubLevels, however most web sites that use pop-out Menus typically have one look and feel for the portion of the Menu that is statically displayed on the web page and another look and feel for the portion of the Menu that is dynamically displayed on the webpage. To simplify setting the styles for all MenuLevels and MenuItems that appear statically and all MenuLevels and MenuItems that appear dynamically the Menu control supports the following style properties: 
<ul>
<li><b>Static/DynamicMenuStyle</b> The MenuStyle sets the properties that control the corresponding Menu – think of it as the style for the box that contains all of the MenuItems.  In addition to the traditional style properties it also includes HorizontalPadding and VerticalPadding.  </li>
<li><b>DynamicMenuItemStyle</b> The MenuItemStyle sets the properties that control the display of the individual MenuItems contained in the corresponding component of the menu – think of it as the style for the links that appear within the box.  In addition to the traditional style properties it also includes ItemSpacing, HorizontalPadding and VerticalPadding.     </li>
<li><b>DynamicSelectedStyle</b> The SelectedStyle sets the properties that control the display of the individual MenuItem that is currently selected and contained on the corresponding component of the menu – think of it as a MenuItemStyle specific to the selected item.  In addition to the traditional style properties it also includes ItemSpacing, HorizontalPadding and VerticalPadding.        </li>
<li><b>DynamicHoverStyle</b> The HoverStyle sets the properties that control the display of the individual MenuItem that is currently selected and contained on the corresponding component of the menu – think of it as a MenuItemStyle specific to the selected item.  In addition to the traditional style properties it also includes ItemSpacing, HorizontalPadding and VerticalPadding.          </li>
</ul>
Note: A Head tag with runat=server must be set on any page that uses any of the Menu HoverStyles and the Menu control
will generate all styles in a more efficient manner on pages with a <code> &lthead runat=server/&gt </code>. 
<br /><br />

In the following sample a number of style properties are used to illustrate their effect on different parts of the Menu. In addition the HorizontalOffset properties are used to change the positioning of the pop-out portion of the Menu relative to the static portion of the Menu. 
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/navigation/Menu/MenuStyles_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/Menu/MenuStyles.src"
        Caption="C# Menu Styles"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/navigation/Menu/MenuStyles_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/Menu/MenuStyles.src"
        Caption="VB Menu Styles"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<h3> Menu Templates </h3>
The Menu also supports the StaticMenuItemTemplate and DynamicMenuItemTemplate  these templates are used to control the HTML that is rendered inside the anchor tag of each MenuItem.  This provides you with greater flexibility than provided by the style properties since you have direct control over the rendering.  However, when you template the MenuItems you MUST databind the text that you want to appear. One way to do this is by using the following databinding expression inside your template:  <code> Text='&lt%# Eval( "Text" ) %&gt'</code>
<br /><br />

Two Templated Menus are included in this sample to illustrate some of the possibilities that you can achieve by templating a Menu control. 
<br /><br />

The Horizontal menu example illustrates inserting various amounts of non-breaking spaces to improve the visual representation of the control in addition to the style properties that are set on the control. 
<br /><br />

In addition to exploring some of the different display options, the vertical example also illustrates setting a display property based on a value in the data structure. The databinding expression for the text field sets the bold property to true for items that are defined as selectable=false in the datastructure.  

<br /><br />
<code> Font-Bold='&lt;%# !bool.Parse( Eval( "Selectable" ).ToString( ) ) %&gt;' Text='&lt;%# Eval( "Text" ) %&gt;' </code> 
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/navigation/Menu/MenuTemplates_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/Menu/MenuTemplates.src"
        Caption="C# Menu Templates"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/navigation/Menu/MenuTemplates_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/Menu/MenuTemplates.src"
        Caption="VB Menu Templates"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>




</asp:Content>
