<%@ Page Language="C#" %>
<%@ Import Namespace="System.Data" %>
<%@ Import Namespace="System.Data.SqlClient" %>

<html>

<script runat="server">
    void Page_Load(Object Src, EventArgs E)
    {
        DataView Source;

        // try to retrieve item from cache
        // if it's not there, add it

        Source = (DataView)Cache["MyDataSet"];

        if (Source == null)
        {
            SqlConnection myConnection = new SqlConnection(ConfigurationManager.ConnectionStrings["Pubs"].ConnectionString);
            SqlDataAdapter myCommand = new SqlDataAdapter("select * from Authors", myConnection);

            DataSet ds = new DataSet();
            myCommand.Fill(ds, "Authors");

            Source = new DataView(ds.Tables["Authors"]);
            Cache["MyDataSet"] = Source;

            CacheMsg.Text = "Dataset created explicitly";
        }
        else
        {
            CacheMsg.Text = "Dataset retrieved from cache";
        }

        MyGrid.DataSource = Source;
        MyGrid.DataBind();
    }
  </script>

<body>
    <form method="GET" runat="server">
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

