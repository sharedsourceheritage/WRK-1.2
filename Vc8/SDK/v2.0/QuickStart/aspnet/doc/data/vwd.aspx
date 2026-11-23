<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>

<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>


<h2>Working with Databases in Visual Web Developer 2005 Express Edition</h2>

Visual Web Developer 2005 Express Edition includes <b>SQL Server 2005 Express Edition</b>, a free edition of SQL Server 2005 targeted at non-professional 
or hobbyist developers who want a simple database solution for building applications.  Because SQL Server Express supports the 
complete SQL Server programming model, such as SQLCLR, T-SQL, stored procedures, views, triggers, and the XML data type, you can
get acquainted with the this technology using SQL Server Express, while ensuring that your application
continues to run against higher-level SKUs such as SQL Server Enterprise Edition.
SQL Server Express is easy to download and set up (it is less than 36MB), and is also included with 
Visual Studio 2005 and Visual Web Developer 2005.
<br /><br />
Visual Studio includes tools for database management such as the Database Explorer and Query Builder, 
which can be used with SQL Server Express databases.  Visual Studio also supports a new file-based approach 
to databases for creating a SQL Server Express database as part of your project. Together, Visual Studio 
2005 and SQL Server 2005 Express enable a complete solution for building and deploying data-driven 
Web applications, including the following features:

<ul>
  <li>Database project item</li>
  <li>Local database connections</li>
  <li>Database Explorer management</li>
  <li>Relative path connection strings</li>
  <li>XCopy deployment support</li>
  <li>Integrated debugging support</li>
<%--  <li>Auto-creates databases for ASP.NET providers, such as Membership, Roles, and Personalization</li>--%>
</ul>

This section describes the file-based approach to databases in Visual Studio 2005 and how to create
and consume these databases from the designer.


<a name="intro"></a>
<h3>Visual Web Developer and Data</h3>

Visual Web Developer provides a variety of tools for working with the databases used by your Web applications.
You can easily connect to databases and create or view database diagrams or schemas using the Database Explorer.   
You can also query databases and populate data using the Query Builder dialog and Query Results grid. 
Creating a new database (using a local file) is also exposed as a project item (described below).
<br /><br />

Once you have a connection to a Database in Visual Web Developer, you can drag and drop database 
tables directly to pages to create a data-bound GridView control.  Visual Web Developer automatically
creates an associated data source control configured for Select, Update, Insert, and Delete operations
against this table.  This shortcut can spare you the effort of having to create a data source manually, 
and you can easily replace the GridView with an appropriate data-bound control for your scenario.
<br /><br />

<a name="databases"></a>
<h3>Local and Server Databases</h3>

You are probably already familiar with server-based databases and connection strings.  In this configuration,
a database server such as SQL Server 2005 associates a database name to a database file that attached and
maintained by the server.  You can connect to a server-based database with a connection string that specifies
the server name, database name, and authentication scheme, for example:

<pre class="code">
"server=(local)\SQLExpress;database=Pubs;Integrated Security=true"
</pre>

However, Visual Studio 2005 also supports the notion of a local database, that is added as a file to the current
Web application's <b>App_Data</b> directory.  The App_Data directory is a secure place to store data files, because
the contents of this directory are never served to client requests.  It is also the recommended location for
XML files and other data stores.  A local SQL Server Express database has a .MDF extension, for example "MyDatabase.MDF",
which is the standard file format supported by SQL Server.  When connected to a server, the database also has an associated 
log file, such as "MyDatabase_log.LDF".  The database file and log file should always be moved together.
<br /><br />

A local file database is attached to SQL Server Express dynamically through the use of a relative path connection
string.  The relative path ensures that the application can be moved to another location without breaking the 
connection to the database.  A relative-path connection string in a Web application is specified as follows:

<pre class="code">
"server=(local)\SQLExpress;AttachDbFileName=|DataDirectory|MyDatabase.mdf;Integrated Security=true;User Instance=true"
</pre>

There are two additional properties of the above connection string.  The <b>AttachDbFileName</b> property specifies
the location of the database file to attach to the server dynamically when the connection is opened.  Although this
property can accept a fully-qualified path to the database, this example uses the <b>|DataDirectory|</b> syntax, 
which will be substituted with the path to the Web application's App_Data directory at runtime.  This is what
allows the application to be moved to a different location without breaking the connection.  Secondly, the <b>User Instance=true</b>
property dictates the way in which SQL Server Express will attach to the database.  In this case, SQL Server Express spawns a 
new process running as the user that opened the connection in order to attach the database to this new instance.  In an
ASP.NET application, this user will be the local ASPNET account or Network Service by default, depending on your operating
system.  A separate user instance of SQL Server is required to securely attach database files from a non-administrative account, 
such as the ASP.NET account.
<br /><br />

<b>Important: </b> Because all ASP.NET applications run under the same process account by default, all applications will attach
local databases to the same instance of SQL Server Express.  This means that all applications will have equal access to all 
attached databases in this instance, regardless of the individual application that attached a database initially.  For 
isolation between applications using SQL Server Express, you must run each application is a separate worker process or application
pool (under IIS 6).  For this reason, local SQL Server databases are considered more of a development-time convenience, and not 
an replacement for server-based databases in shared hosting scenarios.  For more information on how to move the contents of a local 
database to a server database, refer to the deployment topic at the end of this section.
<br /><br />

Another important point is that no two users may be connected to a single local database at the same time.  When designing an application
in Visual Studio, the designer takes care of automatically releasing connections to enable Visual Studio and ASP.NET
to share access to the file (when running the application to debug from within the designer, for example).

<a name="create"></a>
<h3>Creating a Local Database</h3>

You can easily create a local database in a Web application project in Visual Studio.  Provided you installed SQL Server Express with 
Visual Studio, you can follow these steps to create a local database, add tables, and populate data.
<br /><br />

<b>To create a local database:</b>

<ol>
  <li>Right-click the Solution Explorer and choose the "Add New Item..." option.
  <li>Select the "SQL Database" item and give the file a name, for example "Database.mdf".
  <li>Visual Studio prompts to add this file to the "App_Data" directory.  Click "Yes".
  <li>Visual Studio adds the file and automatically connects to the database using Database Explorer.
</ol>

<div class="indent">
  <asp:Image ImageUrl="~/aspnet/images/figure6.gif" runat="server"/>
</div>

<b>To add a table to the local database:</b>

<ol>
  <li>Right-click the Tables node in Database Explorer and choose the "Add New Table" option.
  <li>Enter names and types for the columns in the database, optionally setting other column properties in the property grid.
      To create a sample Contacts database, continue following the steps below.
  <li>Set the first Column Name to "ContactID" and set the Data Type to "int".  Uncheck the "Allow Nulls" checkbox for this column.
  <li>Right-click the grey box with the arrow next to the ContactID column and choose the "Set Primary Key" option.
  <li>In the Column Properties grid below the Columns grid, expand the "Identity Specification" node and set "Is Identity" to "Yes".
  <li>Set the second Column Name to "ContactName" and set the Data Type to "varchar(50)".  Leave the "Allow Nulls" checkbox checked.
  <li>Type Ctrl-S to save the table and give it the name "Contacts".  Click OK to save the table.
  <li>Close the table definition window.
</ol>

<div class="indent">
<asp:Image ImageUrl="~/aspnet/images/figure4.gif" runat="server"/>
</div>

<br />

<b>To populate a table with data:</b>

<ol>
  <li>Right-click the table node (for example, "Contacts") in Database Explorer and choose the "Show Table Data" option.
  <li>Enter data for the rows of your table in the results grid.  If following the "Contacts" example from above, you can enter values for the ContactName column and the database will automatically generate corresponding ContactID values. 
  <li>Close the results grid window.
</ol>

<div class="indent">
<asp:Image ImageUrl="~/aspnet/images/figure5.gif" runat="server"/>
</div>


<a name="bind"></a>
<h3>Binding to a Local Database</h3>

To bind to a local database you can configure an ASP.NET data source control to connect to the file using a relative-path connection.
To easily bind a SQL Server Express database to a SqlDataSource and GridView control, follow the steps below:

<ol>
  <li>Double-click a page in Solution Explorer, for example "Default.aspx".  Visual Studio opens the file.
  <li>Select the Design View tab below the page window to switch to Design View.
  <li>Double-click the database file in Solution Explorer, for example "Database.mdf".  Visual Studio opens the Database Explorer for this connection.
  <li>Expand the Tables nodes to reveal the tables in your database.
  <li>Drag and drop a table from Database Explorer to the open page window in Design View.  Visual Studio create a GridView bound to a SqlDataSource control.
  <li>Expand the Smart Task Panel on the GridView control and enable paging, sorting, and editing for the grid.
  <li>Type Ctrl-F5 to run the page (without debugging).
</ol>

The example below shows a GridView and SqlDataSource control connected to a local database.  In order to run this sample, the ASP.NET process account must be granted
read/write permission to the MDF and LDF files in the ~/App_Data directory.  To grant these permissions, follow these steps:

<ol>
  <li>Select the ~/App_Data/Database.MDF file in Windows Explorer and choose Properties
  <li>Select the Security tab and click Add...
  <li>Click Locations..., select your machine name (at the top of the list), and click OK
  <li>In the object names text area, type the name of the ASP.NET process account.  By default, this is "Network Service" on IIS 6.0 or "ASPNET" on IIS 5.x
  <li>Check the "Read" and "Write" checkboxed in the Allow column and click OK
  <li>Repeat for the LDF file in the App_Data directory, if one exists
</ol>

If you created the application on your local computer using Visual Studio, the above permissions will be granted to the App_Data directory by default.  If you need
to alter permission to the database file after it has been attached, you will need to shut down the application domain first before the new permissions will take effect.
Refer to the information below regarding "app_offline.htm" for instructions to shut down an ASP.NET application.
<br />
<br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/SQLExpress_cs.aspx"
        ViewSource="~/aspnet/samples/data/SQLExpress.src"
        Caption="C# Binding to a Local Database"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/SQLExpress_vb.aspx"
        ViewSource="~/aspnet/samples/data/SQLExpress.src"
        Caption="VB Binding to a Local Database"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="deploy"></a>
<h3>Deploying a Local Database</h3>

One benefit of a local database file is that it can be easily moved as part of the application to another location or machine (as
long as that machine is also running SQL Server Express).  To move the database, the file must be unlocked.  While a designer or
application is connected to the database, the file will remain locked.  To unlock the database, all active connections to the database
must be closed.  You can close the connections to the database using the following techniques:  

<ul>
<li>If ASP.NET has open connections, you can shut down the application
domain by adding a file named "app_offline.htm" to the Web application root directory.  This has the effect 
of shutting down the application domain (not the process) and redirecting all requests to the application to
this file (returning a 404 response code).  To allow the application to restart, remove this file.  Note that
simply closing connections in your page code will not release the file lock, because by default the ADO.NET
connection pool retains the active connections.
</ul>

Visual Studio provides a <b>Copy Web</b> feature to move application files from the working directory to a 
target server, using xcopy, FTP, or FrontPage Server Extensions.  The target machine may be local or remote.
To invoke the Copy Web feature, choose "Website > Copy Web Site..." from the Visual Studio menu bar.
<br /><br />

While you can move a database using Copy Web or a simple xcopy or FTP operation, the target machine must also be running SQL Server Express (under
the same instance name) in order for the application to continue working.  As mentioned above, because all applications running as
ASP.NET connect to the same SQL instance, all applications on the target machine should be trusted to each other.  On machines
where applications should not be able to see each other's database, the server-based approach (using SQL authentication or other
isolation technique) is recommended instead of a local database.  If you use SQL Server Express as a development tool, you will need
to copy your SQL Server Express database contents to the provisioned server database as part of production deployment.

<%-- TODO: Describe Import/Export techniques --%>

</asp:Content>

