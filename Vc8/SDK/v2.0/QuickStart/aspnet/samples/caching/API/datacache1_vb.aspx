<%@ Page Language="vb" %>
<%@ Import Namespace="System.Data" %>
<%@ Import Namespace="System.Data.SqlClient" %>

<html>

<script runat="server">
    Sub Page_Load(ByVal Src As Object, ByVal E As EventArgs)
        Dim Source As DataView

        ' try to retrieve item from cache
        ' if it's not there, add it
        Source = Cache("MyDataSet")

        If Source Is Nothing Then
            Dim MyConnection As SqlConnection
            Dim MyCommand As SqlDataAdapter

            MyConnection = New SqlConnection(ConfigurationManager.ConnectionStrings("Pubs").ConnectionString)
            MyCommand = New SqlDataAdapter("select * from Authors", MyConnection)

            Dim ds As New DataSet
            MyCommand.Fill(ds, "Authors")

            Source = New DataView(ds.Tables("Authors"))
            Cache("MyDataSet") = Source

            CacheMsg.Text = "Dataset created explicitly"
        Else
            CacheMsg.Text = "Dataset retrieved from cache"
        End If

        MyGrid.DataSource = Source
        MyGrid.DataBind()
    End Sub
  </script>

<body>
    <form id="Form1" runat="server">
        <h3>
            <font face="Verdana">Caching Data</font></h3>
        <asp:GridView ID="MyGrid" runat="server">
        </asp:GridView>
        <p>
            <i>
                <asp:Label ID="CacheMsg" runat="server" /></i>
        </p>
    </form>
</body>
</html>

