<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>

<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>


<h2>Binding to Databases</h2>

One of the most common types of data to display in a Web application is data that comes from a SQL database such as Microsoft SQL Server, Oracle, or another OLEDB or ODBC data store.  The <b>SqlDataSource</b> control represents a direct connection to a database in a Web application that data-bound controls can use to retrieve data automatically.  SqlDataSource is intended to replace the ADO.NET code you would normally write in a page to create a connection and command to query a database.  Because the data queries are specified directly as properties of the data source control, this is sometimes called a two-tier model, because the data queries are still maintained in page code.  For this reason, the SqlDataSource control is usually aimed at small hobbyist or personal sites that do not require a fully encapsulated data middle-tier object.  A later section of this tutorial discusses the ObjectDataSource control, which is targeted at larger enterprises with a need for middle-tier encapsulation of database queries.

<a name="gridview"></a>
<h3>The GridView Control</h3>

For the purposes of demonstrating how to bind to data from a database, the examples in this section take advantage of a new data-bound control called <b>GridView</b>.  
The GridView control is a new data-bound control in ASP.NET 2.0 for rendering data in a tabular grid format.  Each row in the grid corresponds to a record of data and the columns represent the fields of the record.  If you are familiar with the DataGrid control from ASP.NET v1.x, the GridView control is its replacement and supports a very similar object model.  
<br /><br />
The GridView control supports the following features:

<ul>
  <li>Binding to data source controls.</li>
  <li>Built-in sorting capabilities.</li>
  <li>Built-in updating and deleting capabilities.</li>
  <li>Build-in paging capabilities.</li>
  <li>Built-in row selection capabilities.</li>
  <li>Programmatic access to the GridView object model to dynamically set properties and handle events.</li>
  <li>New column types such as CheckBoxField and ImageField.</li>
  <li>Multiple data fields for the hyperlink columns.</li>
  <li>Multiple data key fields for selection, updates, and deletes.</li>
  <li>Customizable appearance through themes and styles.</li>
</ul>

<a name="report"></a>
<h3>Creating a Data Report</h3>

The simplest type of data-driven page is a read-only report, which displays data but does not allow the user to manipulate the presentation or modify the data.  To create a read-only report against a SQL database, first configure a SqlDataSource on the page and then connect a data-bound control such as GridView to the data source by specifying its <code>DataSourceID</code> property.  
The example below shows a GridView control associated to a SqlDataSource control.
<br/><br/>

<pre class="code">
&lt;form runat="server"&gt;
  &lt;asp:GridView ID="GridView1" DataSourceID="SqlDataSource1" runat="server"/&gt;
  &lt;asp:SqlDataSource ID="SqlDataSource1" runat="server" 
    SelectCommand="SELECT [au_id], [au_lname], [au_fname] FROM [authors]"
    ConnectionString="&lt;%$ ConnectionStrings:Pubs %&gt;" /&gt;
&lt;/form&gt;
</pre>
  
The SqlDataSource <b>ConnectionString</b> property specifies the connection string to the database and the <b>SelectCommand</b> property specifies the query to execute to retrieve data.  The connection string can be specified literally in the page, but in this case the property is assigned using a new expression syntax that retrieves the value from Web.config.
In the example below, a GridView control is bound to a SqlDataSource control connected to a Microsoft&trade; SQL Server database.  
<br /><br />


<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewSimple_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewSimple.src"
        Caption="C# GridView-SqlDataSource"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewSimple_vb.aspx"
        ViewSource="~/aspnet/samples/data/GridViewSimple.src"
        Caption="VB GridView-SqlDataSource"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br/>

The SqlDataSource control is not limited to only connecting to Microsoft&trade; SQL Server database.  It can actually connect to any managed ADO.NET provider configured as a <b>System.Data.Common.DbProviderFactory</b>.  By default, there are four providers included in the .NET Framework machine.config:

<pre class="code">
&lt;configuration&gt;
  &lt;system.data&gt;
    &lt;DbProviderFactories&gt;
      &lt;add name="Odbc Data Provider" invariant="System.Data.Odbc" type="System.Data.Odbc.OdbcFactory, ..." /&gt;
      &lt;add name="OleDb Data Provider" invariant="System.Data.OleDb" type="System.Data.OleDb.OleDbFactory, ..." /&gt;
      &lt;add name="OracleClient Data Provider" invariant="System.Data.OracleClient" type="System.Data.OracleClient.OracleClientFactory, ..." /&gt;
      &lt;add name="SqlClient Data Provider" invariant="System.Data.SqlClient" type="System.Data.SqlClient.SqlClientFactory, ..." /&gt;
    &lt;/DbProviderFactories&gt;
  &lt;/system.data&gt;
&lt;/configuration&gt;
</pre>

The SqlDataSource <b>ProviderName</b> property can be set to the invariant name of any valid provider factory (it defaults to System.Data.SqlClient).  Note that if you change the provider name, you will need to ensure the ConnectionString and SelectCommand properties use the correct syntax for the chosen provider.
<br /><br />

In the preceding example, the GridView control reflected against the fields of the data records returned by SqlDataSource in order to dynamically generate the columns of the grid.  You can also specify explicit column fields to display by adding <b>DataControlField</b> objects to the GridView's <b>Columns</b> collection.  This allows you to specify exactly which columns to display and their relative order.
The following example demonstrates a collection of <b>BoundField</b> and <b>CheckBoxField</b> objects in the GridView Columns collection.  Other field types that can be assigned to this collection are ImageField, HyperLinkField, CommandField, ButtonField, and TemplateField.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewBoundFields_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewBoundFields.src"
        Caption="C# GridView-SqlDataSource (BoundFields)"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewBoundFields_vb.aspx"
        ViewSource="~/aspnet/samples/data/GridViewBoundFields.src"
        Caption="VB GridView-SqlDataSource (BoundFields)"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br/>

The SelectCommand property of SqlDataSource can also be set to a stored procedure name instead of SQL command text.  To enable this, set the <b>SelectCommandType</b> property to "StoredProcedure".
The following example demonstrates the SqlDataSource control configured to select data from a stored procedure in the Northwind sample database.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewStoredProc_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewStoredProc.src"
        Caption="C# GridView-SqlDataSource (Stored Procedure)"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewStoredProc_vb.aspx"
        ViewSource="~/aspnet/samples/data/GridViewStoredProc.src"
        Caption="VB GridView-SqlDataSource (Stored Procedure)"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br/>

By default, the SqlDataSource control returns a DataView from a DataSet object that contains the query results.  You can configure the SqlDataSource control to return data as a DataReader instead by setting the <b>SqlDataSourceMode</b> property to "DataReader".
Using a DataReader is generally more performant than a DataSet when you just need forward-only, read-only access to the data.  However, note that the sorting capability of SqlDataSource will be disabled in this mode.
The following example demonstrates the DataReader mode of SqlDataSource.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewDataReader_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewDataReader.src"
        Caption="C# GridView-SqlDataSource (DataReader)"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewDataReader_vb.aspx"
        ViewSource="~/aspnet/samples/data/GridViewDataReader.src"
        Caption="VB GridView-SqlDataSource (DataReader)"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="connstrings"></a>
<h3>Connection String Settings</h3>

In the preceding examples, SqlDataSource references the database connection string by name using a new declarative expression syntax in ASP.NET 2.0 that resolves to the connection string value at runtime.  The connection string itself is stored in the Web.config file under a <code>&lt;connectionStrings&gt;</code> configuration section, so that it is easily maintained in a single location for all pages in the application.  

<pre class="code">
&lt;configuration&gt;
  &lt;connectionStrings&gt;
    &lt;add name="Pubs" connectionString="Server=(local);Integrated Security=True;Database=pubs;"
      providerName="System.Data.SqlClient" /&gt;
  &lt;/connectionStrings&gt;
&lt;/configuration&gt;
</pre>

The following example shows the Web.config file used by the preceding SqlDataSource samples.
<br /><br />

<Acme:SourceRef
  ViewSource="~/aspnet/samples/data/ConnStr.src"
  Caption="Connection Strings Configuration"
  runat="server" />
<br/>

Storing connection strings in Web.config is a recommended practice for any ASP.NET application, not only for centralized management, but also for the purpose of securing your connection strings.
A command-line tool is available in ASP.NET 2.0 to encrypt this section for further security in a production environment.
Refer to the <asp:HyperLink NavigateUrl="~/aspnet/doc/management/mgmtapi.aspx#encrypt" runat="server">Encrypting Configuration Sections</asp:HyperLink> topic of the management section of this tutorial for more detail on encrypting connection strings.
This next example shows the Web.config file with an encrypted &lt;connectionStrings/&gt; section.
<br /><br />

<Acme:SourceRef
  ViewSource="~/aspnet/samples/data/ConnStrEncrypt.src"
  Caption="Connection Strings Configuration (Encrypted)"
  runat="server" />

The SqlDataSource control's ConnectionString property is then set to the expression <code>&lt;%$ ConnectionStrings:Pubs %&gt;</code>, which is resolved by the ASP.NET parser to the connection string value at runtime.  You can also specify an expression for the ProviderName property of SqlDataSource, for example <code>&lt;%$ ConnectionStrings:Pubs.ProviderName %&gt;</code>.

<a name="sortpage"></a>
<h3>Sorting and Paging Data</h3>

One of the key advantages of the GridView control over other data-bound controls is its ability to automatically take advantage of data source capabilities.  Instead of relying on page code to manually sort or page data, the GridView control can perform these operations automatically as long as the data source is configured to support these operations.
<br /><br />
The SqlDataSource control supports sorting when its DataSourceMode property is set to "DataSet".  
To enable the sorting UI in the GridView, set the <b>AllowSorting</b> property to true.  
This causes the GridView to render link buttons for its column headers that can be clicked to sort a column.  
The GridView control passes the <b>SortExpression</b> associated with the column field to the data source control, which returns the sorted data to the GridView.  
<br /><br />
The SortExpression syntax expected by SqlDataSource is the same syntax as the Sort property of System.Data.DataView, although other data sources might support a different syntax. 
Because the sorting behavior of SqlDataSource relies on the underlying DataView Sort property, sorting is only supported by SqlDataSource when in DataSet mode; if set to DataReader mode, sorting will be disabled.
Typically you will set the SortExpression to a single field name associated with a column of the GridView.
The GridView automatically alternates between appending "ASC" or "DESC" to the SortExpression on each click, to toggle between ascending and descending sort order.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewSorting_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewSorting.src"
        Caption="C# GridView Sorting"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewSorting_vb.aspx"
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
        RunSample="../../samples/data/GridViewPaging_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewPaging.src"
        Caption="C# GridView Paging"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewPaging_vb.aspx"
        ViewSource="~/aspnet/samples/data/GridViewPaging.src"
        Caption="VB GridView Paging"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br/>

You can also customize the style and settings for the pager by configuring the <b>PagerStyle</b> and <b>PagerSettings</b> properties, respectively.  PagerStyle determines the look and feel of the pager, whereas PagerSettings determines the type of paging to use (Numeric or Next/Previous buttons), the pager position, and related options.
The following example demonstrates a few of these styles and settings applied to the GridView pager.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewPagingSettings_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewPagingSettings.src"
        Caption="C# GridView Pager Settings"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewPagingSettings_vb.aspx"
        ViewSource="~/aspnet/samples/data/GridViewPagingSettings.src"
        Caption="VB GridView Pager Settings"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

Note that the paging operation in the preceding example is being performed entirely by the GridView control over the DataView returned by SqlDataSource, which supports the ICollection interface.  In this case, the GridView retrieves all of the data records from the data source, renders a subset of the rows, and then discards the remaining rows.  This is sometimes called "UI paging" because the logic for paging is happening in the rendering layer of the GridView control.
While convenient for paging over arbitrary collections, this is not necessarily the most efficient way to page over data. 
It is also possible to configure paging at the data source interface level, so that GridView requests only as many rows as it needs from the data source in order to render the current page.
The SqlDataSource control does not support interface-level paging at this time.  The ObjectDataSource control does support this feature, and it is discussed in the <asp:HyperLink NavigateUrl="~/aspnet/doc/data/advanced.aspx#pagesort" runat="server">Advanced Sorting and Paging</asp:HyperLink> topic of this tutorial.


<a name="updatedelete"></a>
<h3>Updating and Deleting Data</h3>

Just like sorting and paging, the GridView control can also automatically render UI for modifying data through Update and Delete operations, provided the associated data source is configured to support these capabilities.  The SqlDataSource control supports Update operations when its <b>UpdateCommand</b> property is set and Delete operations when its <b>DeleteCommand</b> property is set to a valid update or delete command or stored procedure.
The UpdateCommand or DeleteCommand should contain parameter placeholders for each value that will be passed by the GridView control (more on this below).
You can also specify an <b>UpdateParameters</b> or <b>DeleteParameters</b> collection to set properties for each parameter, such as the parameter data type, input/output direction, or default value.  These collections are discussed 
in more detail in subsequent topics.
<br /><br />

<pre class="code">
&lt;asp:SqlDataSource ID="SqlDataSource1" runat="server"
  ConnectionString="&lt;%$ ConnectionStrings:Pubs %&gt;"
  SelectCommand="SELECT [au_id], [au_lname], [au_fname], [state] FROM [authors]"
  UpdateCommand="UPDATE [authors] SET [au_lname] = @au_lname, [au_fname] = @au_fname, [state] = @state WHERE [au_id] = @au_id"
  DeleteCommand="DELETE FROM [authors] WHERE [au_id] = @au_id"/&gt;
</pre>


To enable the UI in the GridView for Updates or Deletes, you can either set the <b>AutoGenerateEditButton</b> and <b>AutoGenerateDeleteButton</b> properties to true, or you can add a <b>CommandField</b> to the GridView control and enable its <b>ShowEditButton</b> and <b>ShowDeleteButton</b> properties.  
The GridView supports editing or deleting one row at a time.  For editing, the user places the row in edit mode by clicking the Edit button, and then confirms the Update by clicking the Update button while the row is in edit mode.  The user can also click the Cancel button to abort the edit operation and return to read-only mode.
The following example shows the a GridView and SqlDataSource configured for updating data rows.  
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewUpdating_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewUpdating.src"
        Caption="C# GridView Updating"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewUpdating_vb.aspx"
        ViewSource="~/aspnet/samples/data/GridViewUpdating.src"
        Caption="VB GridView Updating"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

An important property that plays a special role in Update and Delete operations is the <b>DataKeyNames</b> property.  This property is typically set to the names of fields from the data source that 
are part of a primary key used to match a given row in the data source.  Multiple keys are comma-separated when specifying this property declaratively, although it is common to only have one primary 
key field.  The values of fields specified by the DataKeyNames property are round-tripped in viewstate for the sake of retaining original values to pass to an Update or Delete operation, even if that
field is not rendered as one of the columns in the GridView control.  When the GridView invokes the data source Update or Delete operation, it passes the values of these fields to the data source
in a special Keys dictionary, separate from the Values dictionary that contains new values entered by the user while the row is in edit mode (for update operations).
The contents of the Values dictionary are obtained from the input controls rendered for the row in edit mode.  To exclude a value from this dictionary, set the <b>ReadOnly</b> property
to true on the corresponding <b>BoundField</b> in the Columns collection.  If you are using the GridView designer in Visual Studio, the ReadOnly property is set to true for primary key fields by default.
<br /><br />

Notice the naming convention for parameters in the Update statement assigned to UpdateCommand.  The automatic capability of GridView and other data-bound controls to invoke the Update operation 
relies on this naming convention in order to work.  Parameters are expected to be named the same as the associated field values returned by the SelectCommand.  Using this naming convention makes it possible to align the values passed 
by the data-bound control to the data source with the parameters in the SQL update statement.
<br /><br />

The use of this default naming convention assumes that the contents of the Keys and Values dictionaries are mutually exclusive - that is, field values that may be updated 
by the user while the data-bound control is in edit mode should be named differently from the field values used to match the row to update (in the WHERE clause, for SqlDataSource).  
Another way to think about this is that any field set on DataKeyNames should be made read-only or not visible in the data-bound control (for example, in the GridView Columns collection).  
<br /><br />

Although it is common for key fields to be read-only, there are valid scenarios where you will want to be able to update fields that are also used to match the data row to update.  For example, if you set ReadOnly=false
on a field in the GridView's Columns collection that is also set in DataKeyNames, GridView will pass the old value for the field in the Keys dictionary, whereas it will pass the new value
for the field in the Values dictionary.  In order to differentiate between these two values, you will need to name the parameters differently in the SQL statement, for example:

<pre class="code">
&lt;asp:SqlDataSource ID="SqlDataSource1" runat="server"
  ConnectionString="&lt;%$ ConnectionStrings:Pubs %&gt;"
  SelectCommand="SELECT [au_id], [au_lname], [au_fname], [state] FROM [authors]"
  UpdateCommand="UPDATE [authors] SET [au_id] = @au_id, [au_lname] = @au_lname, [au_fname] = @au_fname, [state] = @state WHERE [au_id] = @original_au_id"
  DeleteCommand="DELETE FROM [authors] WHERE [au_id] = @original_au_id"/&gt;
  OldValuesParameterFormatString="original_{0}"
</pre>

In this example, the parameter name @original_au_id is used to refer to the original value for the key field, and @au_id is used to refer to the new value.  The <b>OldValuesParameterFormatString</b>
property of SqlDataSource is also set to a valid .NET Framwork format string to indicate how parameters in the Keys dictionary should be renamed.  This format string is also applied to 
old values of non-key fields passed by the data-bound control, when the SqlDataSource's <b>ConflictDetection</b> property is set to <code>CompareAllValues</code>. For Delete operations, the SqlDataSource only applies the Keys dictionary by default (there are no new values for a delete operation), using the value of the
OldValuesParameterFormatString property to format the key parameter names.
<br /><br />

<a name="filter"></a>
<h3>Filtering Data</h3>

A common scenario in data-driven pages is the ability to filter data in a report.  For example, suppose the user
could select from a set of field values in a DropDownList to filter the report grid to only display rows with a 
matching field value.  In ASP.NET v1.x, you would have needed to perform the following steps in code:

<ol>
  <li>Cancel databinding in Page_Load if the request is a postback
  <li>Handle SelectedIndexChanged event
  <li>Add DropDownList SelectedValue to command's Parameters collection
  <li>Execute the command and call DataBind
</ol>

In ASP.NET 2.0, this code is eliminated through the use of declarative <b>Data Parameter</b> objects.  A data parameter
allows external values to be declaratively associated with data source operations. These parameters are usually associated with a variable in a command expression or property, for example 
a parameter in a SQL statement or stored procedure for SqlDataSource.  Data source controls expose parameter collection properties that can contain parameter objects for each supported data operation.  For example:

<pre class="code">
&lt;asp:DropDownList ID="DropDownList1" ... runat="server"/&gt;
...
&lt;asp:SqlDataSource ID="SqlDataSource1" runat="server" 
  ConnectionString="&lt;%$ ConnectionStrings:Pubs %&gt;"
  SelectCommand="SELECT [au_id], [au_lname], [au_fname], [state] FROM [authors] WHERE [state] = @state"&gt;
  &lt;SelectParameters&gt;
    &lt;asp:ControlParameter Name="state" ControlID="DropDownList1" PropertyName="SelectedValue" /&gt;
  &lt;/SelectParameters&gt;
&lt;/asp:SqlDataSource&gt;
</pre>

The following example demonstrates a QueryStringParameter used to obtain a parameter value from the querystring of the request URL:
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewQueryString_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewQueryString.src"
        Caption="C# Filter By QueryString"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewQueryString_vb.aspx"
        ViewSource="~/aspnet/samples/data/GridViewQueryString.src"
        Caption="VB Filter By QueryString"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br/>

The next example demonstrates a ControlParameter used to obtain a parameter value from a DropDownList control on the page:
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewDropDownList_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewDropDownList.src"
        Caption="C# Filter By DropDownList"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewDropDownList_vb.aspx"
        ViewSource="~/aspnet/samples/data/GridViewDropDownList.src"
        Caption="VB Filter By DropDownList"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

You can configure data parameters to retrieve values from any of the following sources:

<br /><br />
<table class="table">
<tr>
  <th width="20%">Name</th>
  <th>Description</th>
</tr>
<tr>
  <td><Acme:TypeRef TypeName="System.Web.UI.WebControls.Parameter" runat="server"/>
      &nbsp;&nbsp;<span class="blue">Parameter</span></td>
  <td>The Parameter class is the common base from which all other Parameter types are derived.  The Parameter class also serves as the implementation for static parameters, where the value is specified statically using the <code>DefaultValue</code> property.  
      <br /><br />
       Parameters share a common <code>Name</code> property, which is the name of the parameter for the particular data source operation (for example, this would match a parameter name in the SelectCommand for the SqlDataSource).  All Parameters also share a <code>Type</code> property which specifies the type of the parameter value.  
      <br /><br />
      Parameters also share a <code>Direction</code> property, which is used to specify whether the Parameter is used for Input, Output (or ReturnValue), or both Input and Output.  Data sources generally expose output parameters and return values from an event args passed to the data source operation's status event.  Refer to the <asp:HyperLink NavigateUrl="~/aspnet/doc/data/advanced.aspx#parameters" runat="server">Working With Parameters</asp:HyperLink> topic of this tutorial for an example.
  </td>
</tr>
<tr>
  <td><Acme:TypeRef TypeName="System.Web.UI.WebControls.QueryStringParameter" runat="server"/>
      &nbsp;&nbsp;<span class="blue">QueryStringParameter</span></td>
  <td>
      The QueryStringParameter class binds the value of a querystring field to the value of the Parameter object.  The <code>QueryStringField</code> property matches the name of the querystring field from which the value is retrieved.  The <code>DefaultValue</code> property will be returned whenever the querystring value is unavailable.
  </td>
</tr>
<tr>
  <td><Acme:TypeRef TypeName="System.Web.UI.WebControls.ControlParameter" runat="server"/>
      &nbsp;&nbsp;<span class="blue">ControlParameter</span></td>
  <td>
      The ControlParameter class binds the value of a Control property to the value of the Parameter object.  The <code>ControlID</code> property matches the ID of the Control whose property is bound to the parameter.  The <code>PropertyName</code> specifies the property of the control from which the actual value is retrieved.  The Control whose ID is specified by <code>ControlID</code> may optionally define a <code>ControlValuePropertyAttribute</code>, which determines the default property name from which to retrieve the control's value.  This property will be used whenever PropertyName is not set explicitly.  ControlValuePropertyAttribute is applied to the following control properties:

<ul>
<li>Label.Text	   
<li>TextBox.Text 
<li>ListControl.SelectedValue (for example, DropDownList)   
<li>CheckBox.Checked	   
<li>Calendar.SelectedDate	   
<li>DetailsView.SelectedValue
<li>GridView.SelectedValue
<li>TreeView.SelectedValue
<li>FileUpload.FileBytes
</ul>

  </td>
</tr>
<tr>
  <td><Acme:TypeRef TypeName="System.Web.UI.WebControls.SessionParameter" runat="server"/>
      &nbsp;&nbsp;<span class="blue">SessionParameter</span></td>
  <td>
      The SessionParameter class binds the value of a Session object to the value of the Parameter object.  The <code>SessionField</code> property matches the name of the Session key from which the value is retrieved.  The <code>DefaultValue</code> property will be returned whenever the Session value is unavailable.
  </td>
</tr>
<tr>
  <td><Acme:TypeRef TypeName="System.Web.UI.WebControls.FormParameter" runat="server"/>
      &nbsp;&nbsp;<span class="blue">FormParameter</span></td>
  <td>
      The FormParameter class binds the value of an HTML form field to the value of the Parameter object.  The <code>FormField</code> property matches the name of the form field from which the value is retrieved.  The <code>DefaultValue</code> property will be returned whenever the Form value is unavailable.
  </td>
</tr>
<tr>
  <td><Acme:TypeRef TypeName="System.Web.UI.WebControls.CookieParameter" runat="server"/>
      &nbsp;&nbsp;<span class="blue">CookieParameter</span></td>
  <td>
      The CookieParameter class binds the value of an HttpCookie to the value of the Parameter object.  The <code>CookieName</code> property matches the name of the cookie from which the value is retrieved (only simple-valued cookies are supported).  The <code>DefaultValue</code> property will be returned whenever the cookie value is unavailable.
  </td>
</tr>
<tr>
  <td><Acme:TypeRef TypeName="System.Web.UI.WebControls.ProfileParameter" runat="server"/>
      &nbsp;&nbsp;<span class="blue">ProfileParameter</span></td>
  <td>
      The ProfileParameter class binds the value of a User Profile object to the value of the Parameter object.  The <code>ParameterName</code> property matches the name of the profile property name from which the value is retrieved.  The <code>DefaultValue</code> property will be returned whenever the property value is unavailable.
      Form more information, refer to the <asp:HyperLink NavigateUrl="~/aspnet/doc/profile/default.aspx" runat="server">User Profiles</asp:HyperLink> section of this tutorial.
  </td>
</tr>
</table>
<br />


Note the difference between data parameters that evaluate against an external source (Control, QueryString, etc) and the parameters that 
are passed for Update, Insert and Delete operations from preceding examples.  In the latter scenario, the parameter values are supplied 
dynamically by the data-bound control that invokes the Update operation, in this case the GridView control.  For Update, Insert, and Delete
operations you typically will not require data parameters associated to external values.  However, you can include an <code>&lt;asp:Parameter&gt;</code>
object (the base class for all data parameters) in the UpdateParameters, InsertParameters, or DeleteParameters collection of the data source 
in order to specify properties such as the <code>Type</code>, <code>Direction</code>, or <code>DefaultValue</code> (the value to use
if the value passed by GridView is null), to be applied to the parameter values passed from the GridView control.


<a name="cache"></a>
<h3>Caching Data</h3>

Another capability of data source controls is the ability to cache data automatically.  Although you can still use the cache APIs to programmatically cache data, setting a few declarative properties on a data source control can accomplish the same result.
To enable caching for the SqlDataSource control (and also ObjectDataSource, discussed later), set the <b>EnableCaching</b> property to true.  You can specify the length of time (in seconds) to store an entry in the cache using the <b>CacheDuration</b> property.  
You can also set the <b>CacheExpirationPolicy</b> property to either <code>Sliding</code> or <code>Absolute</code> just as you can do from the cache API.
Caching is only supported on the SqlDataSource control when the DataSourceMode property is set to "DataSet".
<br /><br />
For example, if you set CacheDuration to 5 and SlidingExpiration to Absolute, the SqlDataSource will retrieve data from the database on the first request to the page and store this data in the cache.  For subsequent requests, the SqlDataSource will attempt to retrieve the cache entry to serve
the request without going back to the original database.  After 5 seconds (or perhaps earlier, if cache memory pressure is high), the cache entry will be purged and a subsequent request to the page causes SqlDataSource to go back to the database again (repeating
the caching process with the new data).  
<br /><br />
If you instead set CacheDuration to 5 and SlidingExpiration to Sliding, the cached data 
will have its time-to-live periodically refreshed as long as the data source requests the
cached data once every 5 seconds.  If a page requests the cached data at least once
every 5 seconds, and there is no cache memory pressure, the cached data effectively
remains in the cache forever.  On the other hand, if no requests are made for the cached
data within a 5 second time period, then the cached item is purged and the next time a 
request occurs the SqlDataSource control will go back to the original database again.
<br /><br />
The example below demonstrates caching with the SqlDataSource control.  The TimeStamp column updates each time the query is executed, so you can see how often the data is retrieved from the database versus retrieved from the cache.  Note that approximately every
five seconds, the TimeStamp updates.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewCaching_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewCaching.src"
        Caption="C# SqlDataSource Caching"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewCaching_vb.aspx"
        ViewSource="~/aspnet/samples/data/GridViewCaching.src"
        Caption="VB SqlDataSource Caching"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br/>

A keen observer may have noticed that the TimeStamp also updates every time a new value is selected for the
DropDownlist filter on the page.  The reason for this is that each unique set of parameters supplied to the SelectCommand
results in a different query to the database, and consequently a separate entry in the cache (notice that if you select the
same value in the DropDownList twice within a 5 second timeframe, the TimeStamp is the same for that parameter value).
<br /><br />
An alternative approach that works well for smaller data queries is to select all the data from the database initially
for placing in the cache, and then filter over the single cache entry for different parameter values.  To support 
this scenario, the SqlDataSource control supports a <b>FilterExpression</b> property and corresponding <b>FilterParameters</b> 
collection.  Instead of applying parameter values to the command itself (as is the case with SelectParameters), the 
filter expression is applied to the RowFilter property of the DataView object returned from executing the command.
The expression syntax must match the expected syntax for the DataView 
<a href="http://msdn.microsoft.com/library/default.asp?url=/library/en-us/cpref/html/frlrfsystemdatadataviewclassrowfiltertopic.asp">Row Filter</a>
property.  
<br /><br />
You can insert placeholders for parameter values into a FilterExpression using the standard .NET Framework format string syntax, for example
"{0}", "{1}", and so on.  At runtime, the SqlDataSource control applies the values of parameters specified in the FilterParameters collection 
to the FilterExpression by formatting the string with the values.  Note that the parameter values are not escaped, so you'll need to wrap the 
parameter placeholders in single-quotes for String types.  

<pre class="code">
&lt;asp:DropDownList ID="DropDownList1" ... runat="server"/&gt;
...
&lt;asp:SqlDataSource ID="SqlDataSource1" runat="server" 
  ConnectionString="&lt;%$ ConnectionStrings:Pubs %&gt;"
  SelectCommand="SELECT [au_id], [au_lname], [au_fname], [state] FROM [authors]"&gt;
  FilterExpression="state = '{0}'"
  &lt;FilterParameters&gt;
    &lt;asp:ControlParameter Name="state" ControlID="DropDownList1" PropertyName="SelectedValue" /&gt;
  &lt;/FilterParameters&gt;
&lt;/asp:SqlDataSource&gt;
</pre>

The following example demonstrates this filtering technique in action.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewCachingFilter_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewCachingFilter.src"
        Caption="C# Filtering Cache Entries"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewCachingFilter_vb.aspx"
        ViewSource="~/aspnet/samples/data/GridViewCachingFilter.src"
        Caption="VB Filtering Cache Entries"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br/>

Caching data is always a tradeoff between performance (not going back to the database on each request) and stale data (because the cache entry contains
a snapshot of the data captured at a specific time).  It is common for pages to use relatively low CacheDuration values in order to ensure that cache data 
is somewhat current.  A more ideal situation would be to only invalidate cache entries when the underlying data in the database changes.  As long as the 
data has not changed, there is no reason to purge the cache entry.
<br /><br />

A new feature in ASP.NET 2.0 called <b>SQL Cache Invalidation</b> enables you to configure a data source to cache data indefinitely (or for a specified duration)
until the data in the database changes, at which time the cache entry is purged.  This technique allows you to use much higher values for CacheDuration 
and still guarantee that the data displayed always matches the values in the database.  
SQL Cache Invalidation is only supported on Microsoft&trade; SQL Server databases.  There are two implementations of SQL Cache Invalidation: a notification-based
implementation supported on SQL Server 2005 and a polling-based implementation supported on earlier versions of SQL Server.  The 
<asp:HyperLink NavigateUrl="~/aspnet/doc/caching/SQLInvalidation.aspx" runat="server">SQL Cache Invalidation</asp:HyperLink> section of this tutorial describes 
the steps required to configure either of these implementations.
<br /><br />
Once SQL Cache Invalidation is configured, you can use it from a data source control by specifying the <b>SqlCacheDependency</b> property of the data source.
If using the polling-based implementation, this value accepts a format of the form <code>connectionName:tableName</code>.  If using the notification-based 
implementation, set this property to "CommandNotification".
<br /><br />

In this next example, the CacheDuration is set to "Infinite" and SqlCacheDependency is specified.  Notice that the TimeStamp column does not update until
the data is modified using the Edit button on the GridView.
<br /><br />
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewCachingSql_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewCachingSql.src"
        Caption="C# Data Source SqlCacheInvalidation"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewCachingSql_vb.aspx"
        ViewSource="~/aspnet/samples/data/GridViewCachingSql.src"
        Caption="VB Data Source SqlCacheInvalidation"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>


<a name="masterdetails"></a>
<h3>Master-Details and the DetailsView Control</h3>

You have seen in the Filtering Data section how data source controls can accept parameter values from external sources,
such as other controls on the form, querystring values, and so on.  A similar technique can be employed to build a 
master-details scenario.  Master-details typically refers to an arrangement of controls where a selected record in
one control (the "master" control) displays additional details for the selected record in another control (the "details" control).  The additional details may
be properties of the same data item, or may be related records associated to the master data item through a foreign key relationship in the database.
<br /><br />

The GridView control supports a <b>SelectedValue</b> property, which indicates the currently selected row in the GridView.  The SelectedValue property evaluates to the 
value of the first field specified in the DataKeyNames property.  You can enable the UI for selection on the GridView by setting the <b>AutoGenerateSelectButton</b> to
true, or by adding a CommandField with <b>ShowSelectButton</b> set to true to the GridView Columns collection.
The SelectedValue property of GridView can then be associated to a ControlParameter in a data source for querying the details records, in much the same way that filtering
was configured for a DropDownList in preceding examples.
<br /><br />

To display details for the currently selected row, you could use another GridView control, but ASP.NET also includes a new <b>DetailsView</b> control that is uniquely suited
for this purpose.  The DetailsView control renders a single record at a time instead of a collection of records.  Like the GridView, DetailsView renders in a tabular 
format, except the rows correspond to each data field (like GridView columns).  The fields are specified in the DetailsView <b>Fields</b> collection.  
The DetailsView can also optionally page over a collection of records in the same
manner as GridView paging (in DetailsView, the PageSize is always 1).
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewMasterDetails_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewMasterDetails.src"
        Caption="C# Master-Details w/ GridView and DetailsView"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewMasterDetails_vb.aspx"
        ViewSource="~/aspnet/samples/data/GridViewMasterDetails.src"
        Caption="VB Master-Details w/ GridView and DetailsView"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br/>

DetailsView supports editing just like GridView, and you can enable the UI the same way 
using the AutoGenerateEditButton or CommandField.ShowEditButton properties.  Of course,
the data source associated to the DetailsView must also be configured to support the 
Update operation (in this case, by specifying an UpdateCommand on SqlDataSource).
The following example demonstrates a DetailsView configured to support editing records
in a master-details scenario.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewMasterDetailsEdit_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewMasterDetailsEdit.src"
        Caption="C# DetailsView Editing"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewMasterDetailsEdit_vb.aspx"
        ViewSource="~/aspnet/samples/data/GridViewMasterDetailsEdit.src"
        Caption="VB DetailsView Editing"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br/>

Normally data-bound controls automatically re-bind to their data source
whenever the data source changes (for example after an update).  However,
in the preceding example, the DetailsView is bound to a different data source than
the GridView, so when the Update operation is invoked, only the DetailsView
receives a change event from its data source.  To force the GridView to also
re-bind when the DetailsView performs an update, you can call <code>DataBind()</code>
explicitly on GridView in the DetailsView <code>ItemUpdated</code> event. This example
also handles events to disable editing when a GridView sorting or paging 
operation occurs or when a new filter value is selected in the 
DropDownList control.
<br /><br />

It is also common to split master-details display across several pages in a Web 
application.  To do this, you can add a hyperlink to each row of the GridView to 
navigate to a separate details page, passing arguments along the querystring.
In the details page, the data source bound to DetailsView would accept these 
arguments using a <b>QueryStringParameter</b> object.  
<br /><br />

A hyperlink may be added to the GridView by adding a <b>HyperLinkField</b> object to the
GridView Columns collection.  The HyperLinkField <b>Text</b> property sets the 
text to display for the hyperlink (for example "View Details..."), while the
<b>NavigateUrl</b> property specifies the URL to navigate when the link is clicked. 
Rather than specify a static URL for all rows, it is more common to specify 
<b>NavigateUrlFields</b> to be used in the construction of a dynamic URL.  
NavigateUrlFields can be set declaratively to a comma-separated list of 
fields from the data source. The <b>NavigateUrlFormatString</b> property specifies 
a standard .NET Framework format  string for the URL, using placeholders like 
{0} and {1} to substitute the field values at runtime.
<br /><br />

This next example demonstrates a master-details scenario using GridView and DetailsView
in separate pages.  Unlike the previous examples that showed the GridView and DetailsView
bound to the same type of record (an author), this example shows different types of
records for the master and details controls (authors and books), associated by a 
foreign key relationship in the underlying database.  Because an author record may 
have more than one associated book, the DetailsView has been configured to support 
paging over the book records in the details page.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewMasterDetailsPage_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewMasterDetailsPage.src"
        Caption="C# Master-Details (Separate Pages)"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewMasterDetailsPage_vb.aspx"
        ViewSource="~/aspnet/samples/data/GridViewMasterDetailsPage.src"
        Caption="VB Master-Details (Separate Pages)"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>


<a name="insert"></a>
<h3>Inserting Data</h3>

Like the GridView control, the DetailsView control supports Updating and Deleting data through 
its data source.  However, DetailsView also supports Inserting data, whereas GridView does not.
You can easily pair a DetailsView with GridView to enable inserting records to be displayed 
in the GridView control.
<br /><br />

To enable the SqlDataSource to support Inserts, set the <b>InsertCommand</b> property to a valid 
insert command, with parameter placeholders for each field value that is rendered by the 
DetailsView in Insert mode.  You can also optionally specify an <b>InsertParameters</b> collection 
to contain data parameter objects for this operation.

<br /><br />

To enable the UI for inserting, set the <b>AutoGenerateInsertButton</b> property to true or add a 
CommandField with <b>ShowInsertButton</b> set to true to the DetailsView Fields collection.
To place the DetailsView in insert mode, click the "New" button.  DetailsView renders input controls 
for each field when in insert mode.  Note that fields marked as ReadOnly are rendered as input
controls in Insert mode (although they would not for Update mode).  To exclude a field from 
Insert mode, set the <b>InsertVisible</b> property of the field to false. To commit an insert 
operation, click the "Insert" button while in insert mode.  To abort the insert operation, 
click the "Cancel" button.
<br /><br />
When an Insert operation is committed, the DetailsView collects the values from its input controls
and populates a Values dictionary to pass to the data source.  The SqlDataSource applies these 
values to the InsertCommand's parameters collection before executing the command.  
As with Updates, the automatic insert capability relies on parameters in the InsertCommand that are
named exactly the same as the fields returned from the select operation.  Note that the Keys dictionary 
is not required for insert.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewMasterDetailsInsert_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewMasterDetailsInsert.src"
        Caption="C# Master-Details Insert"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewMasterDetailsInsert_vb.aspx"
        ViewSource="~/aspnet/samples/data/GridViewMasterDetailsInsert.src"
        Caption="VB Master-Details Insert"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br/>

You can place the DetailsView on a separate page to perform an Insert or Update operation.  The 
following example shows a DetailsView configured on a separate page for Insert and Updates.  Notice
that the <b>DefaultMode</b> property is set in this example to <code>Insert</code> or <code>Edit</code>
so that the DetailsView renders in this mode initially instead of read-only mode.  After an Insert or
Update operation is performed, DetailsView always reverts to the DefaultMode (which is <code>ReadOnly</code>, by default).
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewMasterDetailsInsertPage_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewMasterDetailsInsertPage.src"
        Caption="C# Master-Details Insert (Separate Pages)"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewMasterDetailsInsertPage_vb.aspx"
        ViewSource="~/aspnet/samples/data/GridViewMasterDetailsInsertPage.src"
        Caption="VB Master-Details Insert (Separate Pages)"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>


</asp:Content>

