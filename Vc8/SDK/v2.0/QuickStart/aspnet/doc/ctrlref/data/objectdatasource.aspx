<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.ObjectDataSource" runat="server">
  ObjectDataSource
</Acme:TypeRef>
</h2>

ObjectDataSource belongs to the family of data source controls in ASP.NET, which enables a declarative databinding model against a variety of underlying data stores, such as SQL databases or XML.  Most data source controls encourage a two-tiered application architecture, where the presentation layer (the page) interacts directly with the backend data provider.  However, it is also common for page developers to encapsulate data retrieval (and optionally business logic) into a component object, introducing an additional layer between the presentation page and data provider.  The ObjectDataSource control allows developers to structure their applications using this traditional three-tiered architecture and still take advantage of the ease-of-use benefits of the declarative databinding model in ASP.NET.
<br /><br />

The ObjectDataSource control object model is similar to the SqlDataSource control.  Instead of
a ConnectionString property, ObjectDataSource exposes a <b>TypeName</b> property that specifies
an object type (class name) to instantiate for performing data operations.  Similar to the
command properties of SqlDataSource, the ObjectDataSource control supports properties
such as <b>SelectMethod</b>, <b>UpdateMethod</b>, <b>InsertMethod</b>, and <b>DeleteMethod</b> for specifying methods
of the associated type to call to perform these data operations.  This section
describes techniques for building data access layer and business logic layer components and
exposing them through an ObjectDataSource control.
<br /><br />

<a name="dal"></a>
<h3>Binding to a Data Access Layer</h3>

A data access layer component encapsulates the ADO.NET code to query and modify a database through SQL
commands.  It typically abstracts the details of creating ADO.NET connection and commands and instead exposes
these through methods that can be called with appropriate parameters.  A typical data access layer component
might be exposed as follows:

<pre class="code">
public class MyDataLayer {

  public DataView GetRecords();
  public DataView GetRecordsByCategory(String categoryName);
  public DataView GetRecordByID(int recordID);

  public int UpdateRecord(int recordID, String recordData);
  public int DeleteRecord(int recordID);
  public int InsertRecord(int recordID, String recordData);
}
</pre>

The ObjectDataSource can be associated to this type in the following manner:

<pre class="code">
  &lt;asp:ObjectDataSource TypeName="MyDataLayer" SelectMethod="GetRecords" UpdateMethod="UpdateRecord" 
    DeleteMethod="DeleteRecord" InsertMethod="InsertRecord" runat="server"/&gt;
</pre>

The ObjectDataSource requires a very specific design pattern for the objects it can work with.  These 
restrictions are mostly imposed by the stateless environment under which Web application requests are executed.
Because objects are typically created and destroyed to serve each request, the objects bound through object data
source are expected to be stateless as well.
By default, ObjectDataSource assumes a default constructor (no arguments) for the type specified by the TypeName property, although it is 
possible to instantiate this type on behalf of the ObjectDataSource by handling the <b>ObjectCreating</b> event to create
a custom object instance and assign it to the <b>ObjectInstance</b> property of the event arguments.
The object method associated with the SelectMethod property can return any Object or IEnumerable list, collection, or array.  In the above
data access layer example, the DataView object implements IEnumerable.  As we'll discuss in the following section, these methods might also
return a strongly type collection or object.
<br /><br />

<pre class="code">
GetProducts() -> ProductCollection
GetProductsDataSet() -> DataSet
GetProduct (int productId) -> Product
</pre>

The Update, Insert, and Delete methods should take individual data item fields as parameters, or they can optionally
take an aggregate class object with public properties for data item fields.

<pre class="code">
UpdateProduct (int id, String name, double price, bool inStock)
UpdateProduct (Product p)  // p.ID, p.Name, p.Price, p.InStock …
DeleteProduct (int id)
</pre>

The parameter names or properties of the data item passed to the Update, Insert, and Delete methods must match the names of the data item fields returned by the SelectMethod in order for GridView/DetailsView automatic updates/deletes/inserts to work.
Parameters to ObjectDataSource methods can be associated to data parameter objects assigned to the
<b>SelectParameters</b>, <b>FilterParameters</b>, <b>UpdateParameters</b>, <b>DeleteParameters</b>, or <b>InsertParameters</b> collections.
<br /><br />

The following example demonstrates an ObjectDataSource control that exposes data from a data access layer component named <code>AuthorsDB</code>.  The class file for
this type is placed in the application's App_Code directory, which is dynamically compiled by ASP.NET at runtime.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/GridViewObject_cs/GridViewDAL_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewDAL.src"
        Caption="C# Binding to a Data Access Layer"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/GridViewObject_vb/GridViewDAL_vb.aspx"
        ViewSource="~/aspnet/samples/data/GridViewDAL.src"
        Caption="VB Binding to a Data Access Layer"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

<a name="bll"></a>
<h3>Binding to a Business Logic Layer</h3>

An important thing to note about a data access layer is that because the SelectMethod returns the result of executing the query as a DataView,
it still exposes the schema of the underlying database to the presentation pages.  Another thing to note is that there are no business rules 
in the data access layer; it simply executes queries and returns results.  To insulate the presentation from database schema and introduce
business rules or validation, the data access layer is typically wrapped in a business logic layer.
<br /><br />

A business logic layer is similar to a DAL in that it exposes stateless methods to ObjectDataSource for
binding controls in Web pages.  However, instead of returning ADO.NET results directly, it typically
returns strongly-typed objects that represent the business entities used by the application.  This 
decouples the presentation layer from the schema of the underlying data store, making it easier to 
maintain the data access portion of your site separately from the pages that consume the data.  With
a properly architected middle-tier, you could change the underlying data store to a completely 
different schema without having to update the individual pages in your application.
<br /><br />

An example business logic layer is given below.  

<pre class="code">
public class MyBusinessLayer {

  public RecordCollection GetRecords();
  public RecordCollection GetRecordsByCategory(String categoryName);
  public RecordCollection GetRecordByID(int recordID);
  public String GetRecordName(int recordID);
  public Object GetRecordData(int recordID);

  public int UpdateRecord(Record r);
  public int DeleteRecord(Record r);
  public int InsertRecord(Record r);

  public int UpdateRecordData(int ID, String Data);
  public int UpdateRecordName(int ID, String Name);
}

public class Record {
  public int ID { get; set; }
  public String Name { get; set; }
  public Object Data { get; set; }
}
</pre>

The main difference between the business logic layer and data access layer is that it returns a 
strongly-typed RecordCollection of Record objects, rather than a DataView.  It also allows for
Update, Insert, and Delete operations that take this Record object as a parameter.  The ObjectDataSource
<b>DataObjectTypeName</b> property allows you to configure the ObjectDataSource to pass this type
to methods instead of individual field values.  In the business logic layer method implementations,
you can include custom logic for validating business rules.  For example, you could ensure that only Records in the 
"In Review" category can be updated or only Administrators can insert new records.  You can also
include validation logic to ensure the data types and values supplied as arguments are correct
before inserting or modifying data in the database.  Note that validation logic in business layer 
is not a substitute for input validation at the presentation layer, which helps guide the 
end user to enter the correct values before submitting the update.
<br /><br />

The example below shows a simple business logic layer called <code>AuthorsComponent</code>.  Internally, this BLL calls through to the
DAL to actually perform database operations.  For simplicity, this BLL does not include any
business rules or validation, although it would in a real-world application.  Also note that
instead of writing our own custom collection class to return strongly-typed records, this
example takes advantage of a new language feature in the .NET Framework 2.0 called "Generics" 
to create a collection of <code>Author</code> objects.  Using strongly-typed collections allows ObjectDataSource to infer the schema  of
your business objects at design-time (in Visual Studio and other tools).
<br /><br />

The illustration below shows the interaction between the GridView, ObjectDataSource, and business logic
layer.  The ObjectDataSource is configured to call a <code>GetContacts</code> method on the <code>ContactsList</code> type, which
return a collection of <code>Contact</code> objects.  The GridView enumerates these Contacts objects and binds 
directly to the properties (ID, Name) of this type to produce it's columns.  Note that the SelectMethod can return
either an IEnumerable of Contact objects, or it could return a singleton Contact object.  The ObjectDataSource will
always wrap the result of the SelectMethod in an IEnumerable if it doesn't implement IEnumerable itself.
<br /><br />

<asp:Image ImageUrl="~/aspnet/images/figure1.gif" runat="server"/>
<br />

Like SqlDataSource, the ObjectDataSource control supports sorting when the 
SelectMethod returns a DataSet, DataView, or DataTable object.  Internally, the 
ObjectDataSource relies on the DataView.Sort property to perform sorting in this
case.  ObjectDataSource also supports custom sorting in the SelectMethod implementation, 
which is useful if the method doesn't return a DataSet, DataView, or DataTable.  Custom 
sorting is configured by setting <b>SortParameterName</b> property to the name of
a method parameter that accepts the SortExpression from the data source.  When the 
SelectMethod is called, ObjectDataSource will pass this expression to your method
and you can implement your own sorting logic using this expression.  The preceding 
example demonstrates custom a custom sorting implementation in the AuthorsComponent 
class.
<br /><br />

ObjectDataSource also supports custom paging in the SelectMethod implementation.
This is configured using the <b>StartRowIndexParameterName</b>, 
<b>MaximumRowsParameterName</b>, and <b>SelectCountMethod</b> properties and is
discussed in more detail in the 
<asp:HyperLink NavigateUrl="~/aspnet/doc/data/advanced.aspx#pagesort" runat="server">Advanced Paging and Sorting</asp:HyperLink> section of this tutorial.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/GridViewObject_cs/GridViewDAL_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewObject.src"
        Caption="C# Binding to a Business Logic Layer"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/GridViewObject_vb/GridViewDAL_vb.aspx"
        ViewSource="~/aspnet/samples/data/GridViewObject.src"
        Caption="VB Binding to a Business Logic Layer"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

<a name="dataset"></a>
<h3>Binding to a Visual Studio DataSet</h3>

Building a data access layer can be tedious, because often the ADO.NET code to execute SQL statements or 
stored procedures is the same or similar for different methods of the DAL.  Although you can write your
own DAL using custom ADO.NET code using the techniques described above, Visual Studio also provide a 
convenient way to generate a data access layer for you, based on inputs to a simple wizard.  The data access
layer in this case is a strongly-typed DataSet object.  The DataSet contains TableAdapter types that 
expose methods for returning strongly-typed DataTable objects.  These methods are suitable for binding
to an ObjectDataSource directly, or for calling from your business logic layer components.
<br /><br />

To add a DataSet to your Visual Studio project, right-click the Solution Explorer and choose "Add New
Item...", then select the "DataSet" project item type.  Visual Studio may prompt to add this to the 
App_Code directory; answer "Yes" to this prompt to proceed.  Visual Studio adds a DataSet.xsd file to
the App_Code directory and opens the DataSet designer, launching the TableAdapter wizard by default.
Stepping through the TableAdapter wizard, you can specify SQL statements or stored procedures from 
your database, and then name the methods associated to these queries/commmands on the final page
of the wizard.  
<br /><br />

<asp:Image ImageUrl="~/aspnet/images/figure3.gif" runat="server"/>
<br /><br />

The TableAdapter can expose two types of methods: Fill methods that are suitable for
filling an existing DataSet, and Get methods that return an already filled DataTable object.  The former
is more suitable for a Windows client (where the DataSet is kept in memory for the lifetime of the 
application), whereas the latter Get methods are more suitable for ObjectDataSource.  The TableAdapter 
wizard can also automatically generate Update, Insert, and Delete methods for your provided SQL select 
statements (requires the primary key to be selected).  After completing the wizard, Visual Studio adds 
a new DataTable and TableAdapter type to the DataSet designer.
<br /><br />

A TableAdapter represents the schema from a single result set and the Select, Update, Insert, or Delete operations 
over that schema.  You can add multiple TableAdapters in a DataSet by right-clicking in the DataSet designer.
You can also add additional queries, provided they return the same schema (fields), to a TableAdapter by 
right-clicking the TableAdapter box in the designer.  For example, you could have a single TableAdapter with
methods <code>GetAuthors()</code> and <code>GetAuthorsById(int id)</code>, but you would need a new TableAdapter to add a
<code>GetTitles()</code> method.  The figure below shows the DataSet designer with several TableAdapters added:
<br /><br />

<asp:Image ImageUrl="~/aspnet/images/figure2.gif" runat="server"/>
<br />

Once you've finished designing the DataSet, save the DataSet.xsd file (this causes the types to be 
background compiled by the designer to make them available to your pages).  You can 
now see that these types are exposed to page code:

<pre class="code">
protected void Page_Load(object sender, EventArgs e)
{
    DataSetTableAdapters.PhotosTableAdapter adapter = new DataSetTableAdapters.PhotosTableAdapter();
    adapter.GetPhotosForAlbum(0);
}
</pre>

However, you do not need to call these methods directly from your own code.  You can bind the ObjectDataSource
to these methods instead:

<pre class="code">
&lt;asp:ObjectDataSource ID="ObjectDataSource1" runat="server"
  TypeName="DataSetTableAdapters.PhotosTableAdapter"
  SelectMethod="GetPhotosForAlbum"&gt;
  &lt;SelectParameters&gt;
    &lt;asp:QueryStringParameter Name="albumID" QueryStringField="id" Type="Int32"/&gt;
  &lt;/SelectParameters&gt;
&lt;/asp:ObjectDataSource&gt;
</pre>

The following example shows an ObjectDataSource bound to DataSet.TableAdapter methods.  We will use this 
DataSet in several other examples later in the tutorial to demonstrate how you can use ASP.NET data controls
to implement a simple Photo Album application.  Note that the DetailsView in this example is using a new
field type called <b>ImageField</b> to display the photo images.  Also note the use of <b>ConvertNullToDBNull</b>
on the ObjectDataSource to cause null parameter values to convert to DbNull before passing to TableAdapter
methods (required).
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/PhotoAlbum_vb/AlbumsDataSet.aspx"
        ViewSource="~/aspnet/samples/data/PhotosDataSet.src"
        Caption="C# Binding to a Visual Studio DataSet"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/PhotoAlbum_vb/AlbumsDataSet.aspx"
        ViewSource="~/aspnet/samples/data/PhotosDataSet.src"
        Caption="VB Binding to a Visual Studio DataSet"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

For more information and examples that demonstrate the use of the ObjectDataSource control, refer to the 
<asp:HyperLink NavigateUrl="~/aspnet/doc/data/default.aspx" runat="server">Performing Data Access</asp:HyperLink> section.

</asp:Content>
