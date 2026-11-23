<%@ Page Language="C#" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<script runat="server">

  void GridView1_RowUpdating(Object sender, System.Web.UI.WebControls.GridViewUpdateEventArgs e) {
    Response.Write("Values passed from GridView...<br />");
    
    foreach (DictionaryEntry entry in e.NewValues) {
      Response.Write(" <b>" + Server.HtmlEncode(entry.Key.ToString()) + "</b>=" + Server.HtmlEncode(entry.Value.ToString()) + " (" + Server.HtmlEncode(entry.Value.GetType().Name) + ")<br />");
    }
    foreach (DictionaryEntry entry in e.Keys) {
      Response.Write(" <b>" + Server.HtmlEncode(entry.Key.ToString()) + "</b>=" + Server.HtmlEncode(entry.Value.ToString()) + " (" + Server.HtmlEncode(entry.Value.GetType().Name) + ")<br />");
    }
  }

  void SqlDataSource1_Updating(Object sender, System.Web.UI.WebControls.SqlDataSourceCommandEventArgs e) {
    Response.Write("<br/>Parameter order in data source...<br />");
    
    foreach (System.Data.OleDb.OleDbParameter param in e.Command.Parameters) {
      Response.Write(" <b>" + Server.HtmlEncode(param.ParameterName.ToString()) + "</b>=" + Server.HtmlEncode(param.Value.ToString()) + " (" + Server.HtmlEncode(param.Value.GetType().Name) + ")<br />");
    }
    // For demonstration purposes only, cancel the update
    e.Cancel = true;
    Response.Write("<br />Update canceled");
  }
</script>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
  <title>Untitled Page</title>
</head>
<body>
  <form id="form1" runat="server">
    <div>
      <asp:GridView AutoGenerateColumns="False" DataKeyNames="OrderID" DataSourceID="SqlDataSource1"
        ID="GridView1" runat="server" OnRowUpdating="GridView1_RowUpdating">
        <Columns>
          <asp:CommandField ShowEditButton="True" />
          <asp:BoundField DataField="OrderID" HeaderText="OrderID" InsertVisible="False" ReadOnly="True"
            SortExpression="OrderID" />
          <asp:BoundField DataField="ShipCountry" HeaderText="ShipCountry" SortExpression="ShipCountry" />
          <asp:BoundField DataField="OrderDate" HeaderText="OrderDate" SortExpression="OrderDate" />
        </Columns>
      </asp:GridView>
      <asp:SqlDataSource ConnectionString="<%$ ConnectionStrings:NorthwindOLEDB %>" ID="SqlDataSource1"
        ProviderName="<%$ ConnectionStrings:NorthwindOLEDB.ProviderName %>" runat="server"
        SelectCommand="SELECT TOP 10 [OrderID], [OrderDate], [ShipCountry] FROM [Orders]"
        UpdateCommand="UPDATE [Orders] SET [OrderDate] = ?, [ShipCountry] = ? WHERE [OrderID] = ?"
        OnUpdating="SqlDataSource1_Updating">
        <UpdateParameters>
          <asp:Parameter Name="OrderDate" Type="DateTime" />
          <asp:Parameter Name="ShipCountry" Type="String" />
          <asp:Parameter Name="OrderID" Type="Int32" />
        </UpdateParameters>
      </asp:SqlDataSource>
    </div>
  </form>
</body>
</html>
