<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.GridView" runat="server">
  GridView
</Acme:TypeRef>
</h2>

The ASP.NET <b>GridView</b> control is the successor to the v1.x DataGrid, adding the ability to take advantage of specific capabilities of ASP.NET data source controls.  Whereas the v1.x DataGrid required a page developer to write custom code to handle simple operations such as paging, sorting, editing or deleting data, the GridView control can automatically handle these operations provided its bound data source control supports these capabilities.  The GridView also offers some functionality improvements over the DataGrid, such as the ability to define multiple primary key fields, and some UI customization improvements, such as new field types and templating options.  It also exposes a new model for page developers to handle or cancel events.
<br /><br />

The following example demonstrates the GridView control bound to a SqlDataSource control to produce a read-only tabular report.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/GridViewSimple_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewSimple.src"
        Caption="C# GridView-SqlDataSource"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/GridViewSimple_vb.aspx"
        ViewSource="~/aspnet/samples/data/GridViewSimple.src"
        Caption="VB GridView-SqlDataSource"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br/>

In the preceding example, the GridView control reflected against the fields of the data records returned by SqlDataSource in order to dynamically generate the columns of the grid.  You can also specify explicit column fields to display by adding <b>DataControlField</b> objects to the GridView's <b>Columns</b> collection.  This allows you to specify exactly which columns to display and their relative order.
The following example demonstrates a collection of <b>BoundField</b> and <b>CheckBoxField</b> objects in the GridView Columns collection.  Other field types that can be assigned to this collection are ImageField, HyperLinkField, CommandField, ButtonField, and TemplateField.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/GridViewBoundFields_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewBoundFields.src"
        Caption="C# GridView-SqlDataSource (BoundFields)"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/GridViewBoundFields_vb.aspx"
        ViewSource="~/aspnet/samples/data/GridViewBoundFields.src"
        Caption="VB GridView-SqlDataSource (BoundFields)"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br/>

One of the key advantages of the GridView control over other data-bound controls is its ability to automatically take advantage of data source capabilities. Instead of relying on page code to manually sort or page data, the GridView control can perform these operations automatically as long as the data source is configured to support these operations. 
The following example shows a GridView control with sorting enabled.
<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/GridViewSorting_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewSorting.src"
        Caption="C# GridView Sorting"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/GridViewSorting_vb.aspx"
        ViewSource="~/aspnet/samples/data/GridViewSorting.src"
        Caption="VB GridView Sorting"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br/>

You can also enable paging UI in the GridView by setting the <b>AllowPaging</b> property to true.  The GridView can automatically page over any return value from a data source that supports the <b>ICollection</b> interface.  The DataView returned by SqlDataSource when in DataSet mode supports this interface, so GridView can page over the result.  When in DataReader mode, the GridView cannot page over the data returned by SqlDataSource.
The following example demonstrates the GridView paging UI against a SqlDataSource in DataSet mode.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/GridViewPaging_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewPaging.src"
        Caption="C# GridView Paging"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/GridViewPaging_vb.aspx"
        ViewSource="~/aspnet/samples/data/GridViewPaging.src"
        Caption="VB GridView Paging"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br/>

GridView also supports a special mode for paging and sorting that takes advantage of client-side
callbacks to the server to obtain data for the new page or newly sorted data.  To enable this
feature, set the <b>EnableSortingAndPagingCallbacks</b> property to true.  Notice that when
a page or sort operation is performed, the page does not need to postback in order to 
retrieve new values (although a client script callback to the server is made).  This 
feature is not supported when the GridView contains templated fields.  Showing a Select
button in a CommandField is also not supported when this feature is enabled.
<br /><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/PagingSortingCallbacks_cs.aspx"
        ViewSource="~/aspnet/samples/data/PagingSortingCallbacks.src"
        Caption="C# GridView Paging and Sorting Callbacks"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/PagingSortingCallbacks_vb.aspx"
        ViewSource="~/aspnet/samples/data/PagingSortingCallbacks.src"
        Caption="VB GridView Paging and Sorting Callbacks"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

Just like sorting and paging, the GridView control can also automatically render UI for modifying data through Update and Delete operations, provided the associated data source is configured to support these capabilities.  The SqlDataSource control supports Update operations when its <b>UpdateCommand</b> property is set and Delete operations when its <b>DeleteCommand</b> property is set to a valid update or delete command or stored procedure.
The UpdateCommand or DeleteCommand should contain parameter placeholders for each value that will be passed by the GridView control.
<br /><br />

To enable the UI in the GridView for Updates or Deletes, you can either set the <b>AutoGenerateEditButton</b> and <b>AutoGenerateDeleteButton</b> properties to true, or you can add a <b>CommandField</b> to the GridView control and enable its <b>ShowEditButton</b> and <b>ShowDeleteButton</b> properties.  
The GridView supports editing or deleting one row at a time.  For editing, the user places the row in edit mode by clicking the Edit button, and then confirms the Update by clicking the Update button while the row is in edit mode.  The user can also click the Cancel button to abort the edit operation and return to read-only mode.
The following example shows the a GridView and SqlDataSource configured for updating data rows.  
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/GridViewUpdating_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewUpdating.src"
        Caption="C# GridView Updating"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/GridViewUpdating_vb.aspx"
        ViewSource="~/aspnet/samples/data/GridViewUpdating.src"
        Caption="VB GridView Updating"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

An important property that plays a special role in Update and Delete operations is the <b>DataKeyNames</b> property.  This property is typically set to the names of fields from the data source that 
are part of a primary key used to match a given row in the data source.  Multiple keys are comma-separated when specifying this property declaratively, although it is common to only have one primary 
key field.  The values of fields specified by the DataKeyNames property are round-tripped in viewstate for the sake of retaining original values to pass to an Update or Delete operation, even if that
field is not rendered as one of the columns in the GridView control.  When the GridView invokes the data source Update or Delete operation, it passes the values of these fields to the data source
in a special Keys dictionary, separate from the Values dictionary that contains new values entered by the user while the row is in edit mode (for update operations).
The contents of the Values dictionary are obtained from the input controls rendered for the row in edit mode.  To exclude a value from this dictionary, set the <b>ReadOnly</b> property
to true on the corresponding <b>BoundField</b> in the Column collection.  If you are using the GridView designer in Visual Studio, the ReadOnly property is set to true for primary key fields by default.
<br /><br />

For more information and examples that demonstrate the use of the GridView control, refer to the 
<asp:HyperLink NavigateUrl="~/aspnet/doc/data/default.aspx" runat="server">Performing Data Access</asp:HyperLink> section.

</asp:Content>
