<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>

<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>


<h2>Hierarchical Data</h2>

Data source controls can expose either tabular or hierarchical data, or both.  The SqlDataSource and ObjectDataSource controls demonstrated previously are examples of tabular data source controls.  ASP.NET 2.0 also includes two hierarchical data source controls:  <b>XmlDataSource</b> for connecting to XML files, and <b>SiteMapDataSource</b> for connecting to site navigation data.
Some techniques for using these controls are covered by the examples that follow in this section. 
<br /><br />

Refer to the <asp:HyperLink NavigateUrl="~/aspnet/doc/ctrlref/data/xmldatasource.aspx" runat="server">XmlDataSource</asp:HyperLink> and <asp:HyperLink NavigateUrl="~/aspnet/doc/ctrlref/data/sitemapdatasource.aspx" runat="server">SiteMapDataSource</asp:HyperLink> topics in the Control Reference section for more examples of these controls.

<a name="treeviewmenu"></a>
<h3>The TreeView and Menu Controls</h3>

Like data sources, data-bound controls can also be hierarchical.  Whereas tabular data-bound controls render a list or grid of data, hierarchical data-bound controls are able to recurse into a data hierarchy in order to render data as parent-child relationships in the UI.  Two examples of hierarchical data-bound controls are the <b>TreeView</b> and <b>Menu</b> controls in ASP.NET 2.0.  The techniques for databinding these controls to hierarchical data sources are covered by the examples that follow in this section.  

<br /><br />
Refer to the <asp:HyperLink NavigateUrl="~/aspnet/doc/ctrlref/navigation/treeview.aspx" runat="server">TreeView</asp:HyperLink> and <asp:HyperLink NavigateUrl="~/aspnet/doc/ctrlref/navigation/menu.aspx" runat="server">Menu</asp:HyperLink> topics in the Control Reference section for more examples of these controls.

<br/><br/>

<a name="xml"></a>
<h3>Binding to XML</h3>
The XmlDataSource control allows controls to bind to XML data.  XmlDataSource supports a <code>DataFile</code> property for specifying the path to an XML data file to be used as input.  You may also specify a <code>TranformFile</code> property to apply an XSLT transformation to the data and an <code>XPath</code> property for specifying a subset of nodes to expose from the data source.
<br /><br />
The example below demonstrates a TreeView control bound to an XML file through an XmlDataSource control.  The TreeView associates properties of individual TreeNode objects to attributes of XML nodes in the hierarchy (attributes are promoted to properties of the data item for the sake of data binding).  
By default, the TreeView control simply renders the data item by calling <code>ToString()</code> on the object.  This renders the element name of the XML node so that you can see the hierarchy of the nodes the TreeView is bound against.  This does not necessarily produce the desired rendering, but it gives 
you a starting point for further customizing the way the XML data will be displayed.
<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/ctrlref/navigation/TreeView/treeview12_xml_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/TreeView/TreeView12.src"
        Caption="C# Binding TreeView to an XML File"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/ctrlref/navigation/TreeView/treeview12_xml_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/TreeView/TreeView12.src"
        Caption="VB Binding TreeView to an XML File"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br/>

To give the TreeView a more meaningful rendering, you can specify individual data bindings for nodes in the tree.  <b>TreeNodeBinding</b> objects may
be added to the TreeView's <b>Databindings</b> collection for the purpose of defining how the fields of hierarchical data items are mapped to TreeNode properties.
There are two key properties of TreeNodeBinding that determine the set of hierarchical data items to which the binding applies.  The <b>DataMember</b> property
specifies the type of data item, or in the case of XML data, the element name for which a binding applies.  The <b>Depth</b> property specifies the depth in 
the hierarchy at which the data binding should apply.  You can set either DataMember or Depth, or you can set both of these properties.  For example, to
define data bindings for all <code>Book</code> elements in a given XML file, set DataMember to "Book".  To define bindings for all nodes at depth 1, set
the Depth property to 1.  To define bindings for all <code>Book</code> nodes at depth 1, set both DataMember to "Book" and Depth to 1 on the TreeNodeBinding 
object.
<br /><br />

Once you have set DataMember or Depth to match a given set of nodes, you can define additional properties of TreeNodeDataBinding to define how
properties of the data item (or XML node attributes, in the case of XML data) map to the properties of the TreeNodes that the TreeView control renders.
For example, the <b>TextField</b> property defines the name of property/attribute  to use for the Text of the TreeNode.  Similarly, the ValueField property
defines the data item property/attribute to use for the TreeNode Value.  The NavigateUrlField property defines the field/attribute to use for TreeNode's NavigateUrl,
and so on.  You can also specify static values for the TreeNode properties for a given data binding.  For example, to specify that TreeNodes for <code>Book</code> elements
have a "Book.gif" image, set the ImageUrl property on the TreeNodeBinding whose DataMember property is set to "Book".
<br /><br />

The following example shows a TreeView bound to the same XML data as the preceding example, with Databindings defined for specific elements in the XML hierarchy.

<br /><br />
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/ctrlref/navigation/TreeView/treeview13_xml_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/TreeView/TreeView13.src"
        Caption="C# TreeView Data Bindings"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/ctrlref/navigation/TreeView/treeview13_xml_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/TreeView/TreeView13.src"
        Caption="VB TreeView Data Bindings"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br/>

The XmlDataSource supports an <b>XPath</b> property you can use to filter the set of nodes exposed by the data source.  In the example below, 
the XPath property is set to <code>Bookstore/genre[@name='Business']/book</code>, to filter the nodes of the data source to show only those book elements
under the "Business" genre.  Be careful to specify correct syntax for the XPath property; otherwise, the data source may expose no nodes (and the 
associated data-bound control will not render).
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/ctrlref/navigation/TreeView/treeview14_xml_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/TreeView/TreeView14.src"
        Caption="C# Binding TreeView to an XPath Result"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/ctrlref/navigation/TreeView/treeview14_xml_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/TreeView/TreeView14.src"
        Caption="VB TreeView to an XPath Result"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br/>

Note that the TreeView hierarchy exactly matches the hierarchy of the source XML.  Because of this, it is either common to construct XML specifically for binding to the TreeView or to use an XSL transformation to "re-shape" the data into an appropriate hierarchy for binding to the TreeView.

<br /><br />
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/ctrlref/navigation/TreeView/treeview15_xml_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/TreeView/TreeView15.src"
        Caption="C# Binding TreeView to an XSLT Transformation"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/ctrlref/navigation/TreeView/treeview15_xml_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/TreeView/TreeView15.src"
        Caption="VB TreeView to an XSLT Transformation"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br/><br/>
It is also possible to bind a tabular data-bound control to a hierarchical data source, however the control only renders the first level of hierarchy in this case.  In the example below, a templated DataList control is bound to the same bookstore XML file from the preceding example.  Because the top-level nodes exposed from the data source are <code>&lt;book/&gt;</code> nodes, the DataList can bind to properties of those nodes in its ItemTemplate using <code>Eval</code> data binding expressions.
<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/DataListXml_cs.aspx"
        ViewSource="~/aspnet/samples/data/DataListXml.src"
        Caption="C# DataList Bound to XML File"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/DataListXml_vb.aspx"
        ViewSource="~/aspnet/samples/data/DataListXml.src"
        Caption="VB DataList Bound to XML File"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br/>
Although rendering one level of hierarchy is useful, it would be better if we could nest tabular data-bound controls to reflect the underlying hierarchy.  Fortunately, ASP.NET 2.0 allows you to do just that.  In addition to the <code>Eval</code> data binding syntax, ASP.NET 2.0 provides an <b>XPath-based data binding syntax</b> that is supported on any data item that implements the <b>IXPathNavigable</b> interface.  There are two supported expression types:
<ul>
  <li><code>XPath(<i>expression, [formatString]</i>)</code> - Evaluates an XPath expression against the data item, returning a single value.
  <li><code>XPathSelect(<i>expression, [formatString]</i>)</code> - Evaluates an XPath expression against the data item, returning a selected list of nodes.
</ul>
The example below builds upon the preceding example, using the <code>XPath</code> data binding expressions instead of <code>Eval</code> expressions to bind to attributes of the book nodes.  At face value, this appears to do nothing more than introduce an <code>'@'</code> prefix to each expression, which is the XPath syntax to refer to a node attribute.  However, the real flexibility of XPath lies in its ability to refer to arbitrary items within the hierarchy (not just attributes).  
<br/><br/>
The example adds another DataList to the ItemTemplate of the outer DataList, and binds the <b>DataSource</b> property of this inner DataList to an <code>XPathSelect</code> expression representing the list of chapter nodes for the current book node.  In the ItemTemplate of the inner DataList, XPath data binding expressions are evaluated against these 'chapter' context nodes.  Using this technique, ASP.NET 2.0 allows you to easily construct rich, hierarchical rendering of data by composing tabular data-bound controls.
<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/DataListXmlNested_cs.aspx"
        ViewSource="~/aspnet/samples/data/DataListXmlNested.src"
        Caption="C# Nested DataList Bound to XML File"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/DataListXmlNested_vb.aspx"
        ViewSource="~/aspnet/samples/data/DataListXmlNested.src"
        Caption="VB Nested DataList Bound to XML File"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br/>

A hierarchical data source control like XmlDataSource associates a unique path to each node in its
hierarchy, in order to serve requests from data-bound controls for nodes at a specific location.
This enables features like TreeView's PopoulateOnDemand feature, where nodes from a data source
can be sent down to the client as each node is expanded, instead of sending down all nodes at once
(this feature is discussed in more detail in the TreeView control reference samples).  It also
enables you to use this path from page code to configure a data source to show nodes from a 
specific location.  The path syntax is specific to the type of data represented, and cannot 
be constructed from code.  However, you can access the data path for a node bound to TreeView
using the TreeNode <b>DataPath</b> property.  Because the XmlDataSource uses XPath expressions
for it's data path syntax, these paths may be assigned to the XPath property of an XmlDataSource
to filter the list of nodes.  The example below demonstrates this technique to implement a 
master-details scenario using XmlDataSource.  There are two XmlDataSource controls, one bound
to the TreeView (master control), and one bound to a DataList (details control).  When a TreeView
node is clicked, the DataPath property is retrieved and assigned to the XmlDataSource control
bound to the DataList, in order to display additional information for the specific node that 
was clicked.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/ctrlref/navigation/TreeView/treeview19_evtlog4_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/TreeView/TreeView19.src"
        Caption="C# XML-based Event Log using TreeView (Master-Details)"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/ctrlref/navigation/TreeView/treeview19_evtlog4_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/TreeView/TreeView19.src"
        Caption="VB XML-based Event Log using TreeView (Master-Details)"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

The <asp:HyperLink NavigateUrl="~/aspnet/doc/ctrlref/navigation/treeview.aspx" runat="server">TreeView control reference</asp:HyperLink> section walks through a series of steps for how this sample
was written from scratch, so refer to that topic for more information.

<a name="sitenav"></a>
<h3>Binding to Site Navigation</h3>

Site navigation data is another form of hierarchical data in an ASP.NET application.  As described
in the <asp:HyperLink NavigateUrl="../navigation/default.aspx" runat="server">Creating a Site Navigation Hierarchy</asp:HyperLink>
section.  In addition to supporting the Site Navigation API in ASP.NET for programmatic access to site map data, ASP.NET 2.0 also supports
a <b>SiteMapDataSource</b> control for declarative data binding.  When you bind a TreeView (or Menu) control to a SiteMapDataSource, 
the Text and Url properties of the site map can be bound to TreeNodes (or MenuItems).  Although you can 
specify a DataBinding collection to establish these bindings, this is not strictly necessary.  The TreeView 
and Menu controls automatically bind the Text and NavigateUrl properties of TreeNode or MenuItem to the related
site map properties (this is achieved using the <b>INavigateUIData</b> interface on <b>SiteMapNode</b>).
Another feature of TreeView and Menu when bound to a SiteMapDataSource is that is automatically sets the 
SelectedNode or SelectedItem property to the current node in the site map.
<br /><br />
The example below shows a TreeView bound to a SiteMapDataSource control.  Although this example shows the 
Databindings collection for demonstration purposes, this is not necessary when you are only binding to the Text
and Url properties of the node.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/ctrlref/navigation/TreeView/treeview20_sitemap_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/TreeView/TreeView20.src"
        Caption="C# TreeView Bound to SiteMap Data"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/ctrlref/navigation/TreeView/treeview20_sitemap_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/TreeView/TreeView20.src"
        Caption="VB TreeView Bound to SiteMap Data"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="database"></a>
<h3>Binding to Relational Databases</h3>

A relational database can also be interpreted as a hierarchy, when tables are associated through foreign key 
relationships.  For example, a products database where each product is associated with a product category can be 
interpreted as a hierarchical (1-to-many) relationship between categories and products.  Although the current
version of ASP.NET does not include a data source control for exposing relational data as hierarchical, you
can still achieve this by programmatically populating nodes/items of a hierarchical data-bound control like 
TreeView or Menu.  The example below shows a TreeView control populated from a relational database.  This example
takes advantages of the <b>PopulateOnDemand</b> feature of TreeView to populate child nodes on-demand (through a
callback to the server) when a TreeNode is expanded on the client.  For more information about this feature,
refer to the <asp:HyperLink NavigateUrl="~/aspnet/doc/ctrlref/navigation/treeview.aspx" runat="server">TreeView control reference</asp:HyperLink> 
section of this tutorial.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/ctrlref/navigation/TreeView/treeviewdatabase_cs/treeview11_database_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/TreeView/TreeView11.src"
        Caption="C# Populating TreeView from a Database"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/ctrlref/navigation/TreeView/treeviewdatabase_vb/treeview11_database_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/TreeView/TreeView11.src"
        Caption="VB Populating TreeView from a Database"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br/>

</asp:Content>

