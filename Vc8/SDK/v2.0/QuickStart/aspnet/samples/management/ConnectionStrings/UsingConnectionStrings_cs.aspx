<%@ Import Namespace="System.Configuration" %>
<%@ Import Namespace="System.Web.Configuration" %>
<%@ Import Namespace="System.Data.Common" %>

<script runat=server language=C# >
  
    public void Page_Load(object source, EventArgs e)
    {
        // Get the connection string.

        ConnectionStringSettings connectionString = ConfigurationManager.ConnectionStrings["Northwind"];

        // Construct an ADO.NET provider factory.

        DbProviderFactory providerFactory = DbProviderFactories.GetFactory(connectionString.ProviderName);

        // Construct and open a connection.

        DbConnection connection = providerFactory.CreateConnection();
        connection.ConnectionString = connectionString.ConnectionString;
        connection.Open();

        try
        {
            // Select all customers

            DbCommand command = providerFactory.CreateCommand();
            command.Connection = connection;
            command.CommandText = "SELECT * FROM Customers";
            DbDataReader dr = command.ExecuteReader();                    
            GridView1.DataSource = dr;
            GridView1.DataBind();
        }
        finally
        {
            connection.Close();
        }
    }

</script>

<html>
<head>
    <title>Using Connection Strings</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <asp:GridView ID="GridView1" Runat="server" />
    </div>
    </form>
</body>
</html>
