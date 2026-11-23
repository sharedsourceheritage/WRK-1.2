<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.SiteMapPath" runat="server">
  SiteMapPath
</Acme:TypeRef>
</h2>

The SiteMapPath control displays a list of links representing the user's current page and the hierarchal path back to the root of the website. This functionality is sometimes referred to as a breadcrumb for the user. 

<h3>SiteMapPath Control and Data Retrieval</h3>

The SiteMapPath control relies on a SiteMapProvider to retrieve the data that it will display. Unlike the Menu or Treeview control the SiteMapPath control does NOT use a SiteMapDataSource control and can not be bound to other hierarchal datasource controls. 
<br /><br />

The default SiteMap provider will automatically be used by the control or you can set the SiteMapProvider property on the control to point to any provider already configured in the web.config file. The SiteMapPath control will only display on a page whose URL is contained within the specified SiteMapPath provider. NOTE: This is a typical error that developers encounter – so if the SiteMapPath control does not appear when you run your page check to make sure the page is listed correctly (no typos) in the SiteMapPath providers data store,  the web.sitemap file.
<br /><br />

The SiteMapPath control will automatically take advantage of the security trimming, URL remapping and Localized Site Map data features of the <asp:HyperLink NavigateUrl="~/aspnet/doc/navigation/sitenavapi.aspx" runat="server">Site Navigation API</asp:HyperLink>.

<br/><br/>

<h3>Basic SiteMapPath Example</h3>

In the following sample a SiteMapPath control and a <asp:HyperLink NavigateUrl="~/aspnet/doc/ctrlref/navigation/menu.aspx" runat="server">Menu control</asp:HyperLink> are used and both bind to SiteMap data. Use the Menu control to navigate to different pages in the web site and see how the display of the SiteMapPath control changes to show different hierarchies.  The web.sitemap XML file containing the site structure is also included for your reference. The XML file contains the optional Description SiteMapNode element which is displayed as answer tips by the SiteMapPath and Menu control. 
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/navigation/SiteMapPath/SiteMapPathBasic_cs/Home.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/SiteMapPath/SiteMapPathBasic.src"
        Caption="C# SiteMapPathBasic.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/navigation/SiteMapPath/SiteMapPathBasic_vb/Home.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/SiteMapPath/SiteMapPathBasic.src"
        Caption="VB SiteMapPathBasic.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<h3>SiteMapPath Behaviors Example</h3>

The SiteMapPath provides properties to change the most common display options.  In this sample we demonstrate how to:

<ul>
  <li>Set the ShowToolTips=false so that the description text from the SiteMap Provider XML file is not automatically displayed. </li>
  <li>Set the ParentLevelsDisplayed=3 which will display the current page and 3 levels of the hierarchy. By default this property is set to -1 and all parent levels are displayed.</li>
  <li>Set RenderCurrentNodeAsLink=true so that the current page displayed in the hierarchy will appear as a link instead of text. </li>
  <li>Set PathDirection=CurrentToRoot which will change the order in which the links the appear. The default is start from the highest node and go to the current page, with this setting the links will be displayed starting at the current page and ending at the highest node displayed.</li>
  <li>Set the PathSeparator=":" the default is "&gt;"</li>
</ul>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/navigation/SiteMapPath/SiteMapPathBehaviors_cs/Home.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/SiteMapPath/SiteMapPathBehaviors.src"
        Caption="C# SiteMapPathBehaviors.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/navigation/SiteMapPath/SiteMapPathBehaviors_vb/Home.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/SiteMapPath/SiteMapPathBehaviors.src"
        Caption="VB SiteMapPathBehaviors.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<h3>SiteMapPath Appearance</h3>

You can change the appearance of a SiteMapPath by setting style properties on the control; using a skin/theme file or by templating the nodes of the SiteMapPath.

<h3>SiteMapPath StyleExample</h3>

In addition to the standard web control style properties, the SiteMapPath control supports setting separate style properties for:

<ul>
  <li><b>NodeStyle:</b> The NodeStyle is used for all nodes displayed, if there is a style conflict the most specific style to that element is applied. The NodeStyle merges with the standard web control style properties in the event of a conflict the NodeStyle will be displayed. </li><br /><br />
  <li><b>CurrentNodeStyle:</b> The CurrentNodeStyle is applied to the node representing the current page being displayed. The appearance of the current node is also affected by the RenderCurrentNodeAsLink property. The CurrentNodeStyle merges with the standard web control style properties and the NodeStyle properties, in the event of a conflict the CurrentNodeStyle will be applied.  </li><br /><br />
  <li><b>RootNodeStyle:</b> The RootNodeStyle is applied to the absolute root of the SiteMap Provider hierarchy. As a result, the RootNodeStyle may not be displayed on every page of your website depending on how many levels of the hierarchy are displayed. In the event that the RootNode is the current page being displayed then the CurrentNodeStyle will be applied. . The RootNodeStyle merges with the standard web control style properties and the NodeStyle properties, in the event of a conflict the RootNodeStyle will be applied. </li><br /><br />
  <li><b>PathSeparatorStyle:</b>  The PathSeparatorStyle is applied to the PathSeparator property value that is used to separate the nodes. The PathSeparatorStyle merges with the standard web control style properties in the event of a conflict the PathSeparatorStyle will be displayed. </li><br /><br />
</ul>

<br /><br />

You can also use the themes feature <asp:HyperLink NavigateUrl="~/aspnet/doc/themes/default.aspx" runat="server">Themes and Skins feature</asp:Hyperlink> to control the appearance of the SiteMapPath control. 
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/navigation/SiteMapPath/SiteMapPathStyles_cs/Home.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/SiteMapPath/SiteMapPathStyles.src"
        Caption="C# SiteMapPathStyles.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/navigation/SiteMapPath/SiteMapPathStyles_vb/Home.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/SiteMapPath/SiteMapPathStyles.src"
        Caption="VB SiteMapPathStyles.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<h3>SiteMapPath Template Example</h3>

In addition to styles, you can use templates to further control the look and feel of the SiteMapPath control. Templates give you full control over the HTML that is rendered for a specific part of the control. When you choose to template one of the nodes, you are responsible for databinding the pertinent information (e.g. Title, URL and Description) from the SiteMap Provider to the appropriate controls on your page. For example if you want to databind the title to a label in one of the Node Templates you can type the following expression: <code>Text='&lt;%# Eval("title")%&gt;'</code>. 
<br /><br />

The SiteMapPath supports the following templates: 
<br /><br />

<ul>
  <li><b>NodeTemplate:</b> Displayed for nodes in the hierarchy. </li>
  <br /><br />
  <li><b>CurrentNodeTemplate:</b>  Displayed for the corresponding node in the hierarchy to the page that is being displayed.</li>
  <br /><br /> 
  <li><b>RootNodeTemplate:</b> Displayed when the absolute root of the SiteMap hierarchy is returned. In the event that the RootNode is the current page then the CurrentNode or CurrentNodeTemplate will be displayed. </li>
  <br /><br />
  <li><b>PathSeparatorTemplate:</b>  Displayed between the various nodes being displayed and is used in place of PathSeparator text value.</li>
  <br /><br />
</ul>

In the following sample the PathSeparatorTemplate displays an image. The CurrentNodeTemplate displays the phrase “You are at “title”!” by databinding a label to the title value. The RootNodeTemplate displays the static phrase “RootNode” because it is not databound to any SiteMap node values. 
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/navigation/SiteMapPath/SiteMapPathTemplates_cs/Home.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/SiteMapPath/SiteMapPathTemplates.src"
        Caption="C# SiteMapPathTemplates.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/navigation/SiteMapPath/SiteMapPathTemplates_vb/Home.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/SiteMapPath/SiteMapPathTemplates.src"
        Caption="VB SiteMapPathTemplates.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

</asp:Content>
