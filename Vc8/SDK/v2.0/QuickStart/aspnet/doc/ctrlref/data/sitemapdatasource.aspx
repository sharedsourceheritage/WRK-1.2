<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.SiteMapDataSource" runat="server">
  SiteMapDataSource
</Acme:TypeRef>
</h2>

The <b>SiteMapDataSource</b> control enables you to declaratively data bind to site navigation data in
your pages.  The SiteMapDataSource control is associated to a data-bound control through the control's
<b>DataSourceID</b> property.  For general information on site navigation in ASP.NET, refer to the 
<asp:HyperLink NavigateUrl="~/aspnet/doc/navigation/default.aspx" runat="server">Creating a Site Navigation Hierarchy</asp:HyperLink> topic of this tutorial.
<br /><br />

The following example shows a SiteMapDataSource control bound to a <b>TreeView</b> control in a master
page.  Note that the TreeView control automatically binds to the <code>Title</code> and <code>Url</code> of a <b>SiteMapNode</b>, 
so it is not necessary to explicitly define the Databindings property of the TreeView.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/data/SiteMapDataSource/SiteMapDataSource1_cs/Home.aspx"
        ViewSource="~/aspnet/samples/ctrlref/data/SiteMapDataSource/SiteMapDataSource1.src"
        Caption="C# TreeView Bound To SiteMapDataSource"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/data/SiteMapDataSource/SiteMapDataSource1_vb/Home.aspx"
        ViewSource="~/aspnet/samples/ctrlref/data/SiteMapDataSource/SiteMapDataSource1.src"
        Caption="VB TreeView Bound To SiteMapDataSource"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
</br>

You can set the <b>ShowStartingNode</b> property to determine whether the SiteMapDataSource exposes the 
starting node as the root of the site map, or whether it starts from the child nodes of the root node instead.  The example below 
sets ShowStartingNode to false.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/data/SiteMapDataSource/SiteMapDataSource2_cs/Home.aspx"
        ViewSource="~/aspnet/samples/ctrlref/data/SiteMapDataSource/SiteMapDataSource2.src"
        Caption="C# ShowStartingNode Property"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/data/SiteMapDataSource/SiteMapDataSource2_vb/Home.aspx"
        ViewSource="~/aspnet/samples/ctrlref/data/SiteMapDataSource/SiteMapDataSource2.src"
        Caption="VB ShowStartingNode Property"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />


The previous example shows the whole site map, starting from the root node (the default starting node for SiteMapDataSource).
You can also configure a specific starting node for the data source by setting the <b>StartingNodeUrl</b> property to the Url of a node in the 
site map.  You can also set the <b>StartingNodeOffset</b> property of SiteMapDataSource to dictate a number of levels
up or down from the current starting node to set a new starting node for the data source.  If the 
StartingNodeOffset is negative (-N), the SiteMapDataSource starts N levels above the current starting
node, traveling up the parent node hierarchy.  If the StartingNodeOffset is positive (N), the SiteMapDataSource
starts N levels below the current starting node, travelling down the child hierarchy toward the current
node in the site map.  
<br /><br />

The example below shows a sample usage for StartingNodeOffset and StartingNodeUrl.
Note that when you click one of the <code>Chapter</code> or <code>Paragraph</code> 
nodes in the tree, the starting node for the SiteMapDataSource in SiteMap.master
becomes the Chapter node, which 2 levels below the <code>~/Home.aspx</code> node, 
along the path toward the currently selected chapter or paragraph node in the site map.
Because <code>~/Home.aspx</code> is the Url for the root node in the site map, it is not 
strictly necessary to set StartingNodeUrl here (since the root node is the default starting 
node for SiteMapDataSource), but it is set here purely for the sake of example.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/data/SiteMapDataSource/SiteMapDataSource3_cs/Home.aspx"
        ViewSource="~/aspnet/samples/ctrlref/data/SiteMapDataSource/SiteMapDataSource3.src"
        Caption="C# StartingNodeUrl and StartingNodeOffset Properties"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/data/SiteMapDataSource/SiteMapDataSource3_vb/Home.aspx"
        ViewSource="~/aspnet/samples/ctrlref/data/SiteMapDataSource/SiteMapDataSource3.src"
        Caption="VB StartingNodeUrl and StartingNodeOffset Properties"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

The <b>StartFromCurrentNode</b> property sets the starting node for the SiteMapDataSource to the current
node in the site map.  This property is mutually exclusive with the <b>StartingNodeUrl</b> property; one of 
these may be set at the same time for a SiteMapDataSource.  The example below shows a SiteMapDataSource
configured with StartFromCurrentNode set to true and ShowStartingNode set to false.  This exposes the 
immediate children of the current node in the site map.  A <b>GridView</b> control is bound to this 
data source for navigating to the children of the current node.  Because the SiteMapDataSource
supports the IDataSource interface in addition to IHierarchicalDataSource, it is possible to bind
tabular or list controls to SiteMapDataSource.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/data/SiteMapDataSource/SiteMapDataSource4_cs/Home.aspx"
        ViewSource="~/aspnet/samples/ctrlref/data/SiteMapDataSource/SiteMapDataSource4.src"
        Caption="C# StartFromCurrentNode Property"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/data/SiteMapDataSource/SiteMapDataSource4_vb/Home.aspx"
        ViewSource="~/aspnet/samples/ctrlref/data/SiteMapDataSource/SiteMapDataSource4.src"
        Caption="VB StartFromCurrentNode Property"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

You can define a negative offset for the starting node (relative to the current node)
by defining the StartingNodeOffset property.  A positive offset is not supported when the starting node is
the current node.  The example below demonstrates a <b>DropDownList</b> control inside the CurrentNodeTemplate 
of a SiteMapPath control, bound to a SiteMapDataSource with StartingNodeOffset set to -1, StartFromCurrentNode
set to true, and ShowStartingNode set to false.  This has the effect of showing the current node and its 
sibling nodes in the DropDownList.  The DropDownList SelectedValue property is data-bound to the Url of
the CurrentNode in the site map (using the 

<asp:HyperLink NavigateUrl="~/aspnet/doc/navigation/sitenavapi.aspx" runat="server">Site Navigation API</asp:HyperLink>), so that the DropDownList reflects the current 
node as selected by default.  You can change the value in this DropDownList to navigate to one of the 
sibling nodes of the current node.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/data/SiteMapDataSource/SiteMapDataSource5_cs/Home.aspx"
        ViewSource="~/aspnet/samples/ctrlref/data/SiteMapDataSource/SiteMapDataSource5.src"
        Caption="C# StartFromCurrentNode and StartingNodeOffset Properties"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/data/SiteMapDataSource/SiteMapDataSource5_vb/Home.aspx"
        ViewSource="~/aspnet/samples/ctrlref/data/SiteMapDataSource/SiteMapDataSource5.src"
        Caption="VB StartFromCurrentNode and StartingNodeOffset Properties"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

</asp:Content>
