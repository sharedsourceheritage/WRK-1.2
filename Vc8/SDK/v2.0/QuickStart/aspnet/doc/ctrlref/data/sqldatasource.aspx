<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.SqlDataSource" runat="server">
  SqlDataSource
</Acme:TypeRef>
</h2>

The <b>SqlDataSource</b> control is a data source control that represents a connection to an ADO.NET SQL database provider, such as SQL, OLEDB, ODBC, or Oracle.  Note that a separate AccessDataSource control is implemented in ASP.NET, although it is possible to connect to Access with SqlDataSource as well (using the Microsoft Jet 4.0 OLEDB provider).  Like all data source controls, the SqlDataSource control can be declaratively bound to any data-bound control that supports the <b>DataSourceID</b> property.  SqlDataSource is also self-describing about its capabilities (select, insert, update, delete, sort) so that data-bound controls can provide automatic behavior when a capability is present.  
<br /><br />

SqlDataSource is intended to replace the ADO.NET code you would normally write in a page to create a connection and command to query a database. Because the data queries are specified directly as properties of the data source control, this is sometimes called a two-tier model, because the data queries are still maintained in page code. For this reason, the SqlDataSource control is usually aimed at small hobbyist or personal sites that do not require a fully encapsulated data middle-tier object. Another section of this tutorial discusses the ObjectDataSource control, which is targeted at larger enterprises with a need for middle-tier encapsulation of database queries. 
<br /><br />

The example below shows a GridView control associated to a SqlDataSource control. The <b>SelectCommand</b> property defines the SQL select statement to execute when the GridView requests the data from SqlDataSource.
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

The SelectCommand property of SqlDataSource can also be set to a stored procedure name instead of SQL command text.  To enable this, set the <b>SelectCommandType</b> property to "StoredProcedure".
The following example demonstrates the SqlDataSource control configured to select data from a stored procedure in the Northwind sample database.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/GridViewStoredProc_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewStoredProc.src"
        Caption="C# GridView-SqlDataSource (Stored Procedure)"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/GridViewStoredProc_vb.aspx"
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
        RunSample="../../../samples/data/GridViewDataReader_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewDataReader.src"
        Caption="C# GridView-SqlDataSource (DataReader)"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/GridViewDataReader_vb.aspx"
        ViewSource="~/aspnet/samples/data/GridViewDataReader.src"
        Caption="VB GridView-SqlDataSource (DataReader)"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

The SqlDataSource control supports Update operations when its <b>UpdateCommand</b> property is set and Delete operations when its <b>DeleteCommand</b> property is set to a valid update or delete command or stored procedure.
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

Notice the naming convention for parameters in the Update statement assigned to UpdateCommand.  The automatic capability of GridView and other data-bound controls to invoke the Update operation 
relies on this naming convention in order to work.  Parameters are expected to be named the same as the associated field values returned by the SelectCommand.  Using this naming convention makes it possible to align the values passed 
by the data-bound control to the data source with the parameters in the SQL update statement.
<br /><br />

The use of this default naming convention assumes that the contents of the Keys and Values dictionaries are mutually exclusive - that is, field values that may be updated 
by the user while the data-bound control is in edit mode should be named differently from the field values used to match the row to update (in the WHERE clause, for SqlDataSource).  
Another way to think about this is that any field set on DataKeyNames should be made read-only or not visible in the data-bound control (for example, in the GridView columns collection).  
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
property of SqlDataSource is also set to a valid .NET Framwork format string to indicate how parameters in the Keys dictionary should be re-named.  This format string is also applied to 
old values of non-key fields passed by the data-bound control, when the SqlDataSource's <b>ConflictDetection</b> property is set to <code>CompareAllValues</code>. 
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

A common scenario in data-driven page is the ability to filter data in a report.  For example, suppose the user
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

The following example demonstrates a ControlParameter used to obtain a parameter value from a DropDownList control on the page:
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/GridViewDropDownList_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewDropDownList.src"
        Caption="C# Filter By DropDownList"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/GridViewDropDownList_vb.aspx"
        ViewSource="~/aspnet/samples/data/GridViewDropDownList.src"
        Caption="VB Filter By DropDownList"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

SqlDataSource also support the Insert operation, when its <b>InsertCommand</b> property is
set.  You can optionally define parameters for insert using the <b>InsertParameters</b> collection.  
The following example demonstrates a SqlDataSource control configured to insert data.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/GridViewMasterDetailsInsert_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewMasterDetailsInsert.src"
        Caption="C# Master-Details Insert"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/GridViewMasterDetailsInsert_vb.aspx"
        ViewSource="~/aspnet/samples/data/GridViewMasterDetailsInsert.src"
        Caption="VB Master-Details Insert"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br/>

For more information and examples that demonstrate the use of the SqlDataSource control, refer to the 
<asp:HyperLink NavigateUrl="~/aspnet/doc/data/default.aspx" runat="server">Performing Data Access</asp:HyperLink> section.

</asp:Content>
