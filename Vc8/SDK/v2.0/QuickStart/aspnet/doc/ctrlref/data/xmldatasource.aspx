<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.XmlDataSource" runat="server">
  XmlDataSource
</Acme:TypeRef>
</h2>

The <b>XmlDataSource</b> control belongs to the family of data source controls in ASP.NET, which enables a declarative databinding model against a variety of underlying data stores.
The XMLDataSource control supports declarative databinding to XML files.  XmlDataSource is an example of a hierarchical data source, which supports the required interfaces to allow hierarchical
data-bound controls, such as <b>TreeView</b> and <b>Menu</b>, to traverse the hierarchy of nodes to produce their rendering.  XmlDataSource also supports the tabular data source interfaces required to bind list controls
like <b>GridView</b>, <b>DropDownList</b>, and <b>DataList</b>.
<br /><br />

XmlDataSource supports a <code>DataFile</code> property for specifying the path to an XML data file to be used as input.  You may also specify a <code>TranformFile</code> property to apply an XSLT transformation to the data and an <code>XPath</code> property for specifying a subset of nodes to expose from the data source.
<br /><br />
The example below demonstrates a TreeView control bound to an XML file through an XmlDataSource control.  The TreeView associates properties of individual TreeNode objects to attributes of XML nodes in the hierarchy (attributes are promoted to properties of the data item for the sake of data binding).  
By default, the TreeView control simply renders the data item by calling <code>ToString()</code> on the object.  This renders the element name of the XML node so that you can see the hierarchy of the nodes the TreeView is bound against.  This does not necessarily produce the desired rendering, but it gives 
you a starting point for further customizing the way the XML data will be displayed.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/navigation/TreeView/treeview12_xml_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/TreeView/TreeView12.src"
        Caption="C# Binding TreeView to an XML File"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/navigation/TreeView/treeview12_xml_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/TreeView/TreeView12.src"
        Caption="VB Binding TreeView to an XML File"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br/>

To give the TreeView a more meaningful rendering, you can specify individual data bindings for nodes in the tree.  <b>TreeNodeBinding</b> objects may
be added to the TreeView's <b>Databindings</b> collection for the purpose of defining how the fields of hierachical data items are mapped to TreeNode properties.
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

The following example shows a TreeView bound to the same XML data as the preceding example, with DataBindings defined for specific elements in the XML hierarchy.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/navigation/TreeView/treeview13_xml_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/TreeView/TreeView13.src"
        Caption="C# TreeView Data Bindings"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/navigation/TreeView/treeview13_xml_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/TreeView/TreeView13.src"
        Caption="VB TreeView Data Bindings"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br/>

The XmlDataSource supports an <b>XPath</b> property you can use to filter the set of nodes exposed by the data source.  In the example below, 
the XPath property is set to <code>Bookstore/genre[@name='Business']/book</code>, to filter the nodes of the data source to show only those book elements
under the "Business" genre.  Be careful to specify correct syntax for the XPath property; otherwise, the data source may expose no nodes (and the 
asssociated data-bound control will not render).
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/navigation/TreeView/treeview14_xml_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/TreeView/TreeView14.src"
        Caption="C# Binding TreeView to an XPath Result"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/navigation/TreeView/treeview14_xml_vb.aspx"
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
        RunSample="../../../samples/ctrlref/navigation/TreeView/treeview15_xml_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/TreeView/TreeView15.src"
        Caption="C# Binding TreeView to an XSLT Transformation"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/navigation/TreeView/treeview15_xml_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/navigation/TreeView/TreeView15.src"
        Caption="VB TreeView to an XSLT Transformation"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br/>

It is also possible to bind a tabular data-bound control to XmlDataSource, however the control only renders the first level of hierarchy in this case.  In the example below, a templated DataList control is bound to the same bookstore XML file from the preceding example.  Because the top-level nodes exposed from the data source are <code>&lt;book/&gt;</code> nodes, the DataList can bind to properties of those nodes in its ItemTemplate using <code>Eval</code> data binding expressions.
<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/DataListXml_cs.aspx"
        ViewSource="~/aspnet/samples/data/DataListXml.src"
        Caption="C# DataList Bound to XML File"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/DataListXml_vb.aspx"
        ViewSource="~/aspnet/samples/data/DataListXml.src"
        Caption="VB DataList Bound to XML File"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br/>

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
        RunSample="../../../samples/data/DataListXmlNested_cs.aspx"
        ViewSource="~/aspnet/samples/data/DataListXmlNested.src"
        Caption="C# Nested DataList Bound to XML File"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/DataListXmlNested_vb.aspx"
        ViewSource="~/aspnet/samples/data/DataListXmlNested.src"
        Caption="VB Nested DataList Bound to XML File"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br/>

</asp:Content>
