<%@ Import Namespace="System.Configuration" %>
<%@ Import Namespace="System.Web.Configuration" %>
<%@ Import Namespace="System.Data.Common" %>

<script runat=server language=VB >
  
    Public Sub Page_Load(source As Object, e As EventArgs)

        ' Get the connection string.

        Dim connectionString As ConnectionStringSettings = ConfigurationManager.ConnectionStrings("Northwind")

        ' Construct an ADO.NET provider factory.

        Dim providerFactory As DbProviderFactory = DbProviderFactories.GetFactory(connectionString.ProviderName)

        ' Construct and open a connection.

        Dim connection As DbConnection = providerFactory.CreateConnection()
        connection.ConnectionString = connectionString.ConnectionString
        connection.Open()

        Try

            ' Select all customers

            Dim command As DbCommand = providerFactory.CreateCommand()
            command.Connection = connection
            command.CommandText = "SELECT * FROM Customers"
            Dim dr As DbDataReader = command.ExecuteReader()
            GridView1.DataSource = dr
            GridView1.DataBind()
        
        Finally

            connection.Close()

        End Try

    End Sub

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
