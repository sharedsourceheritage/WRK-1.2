<%@ Page Language="VB" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<script runat="server">

  Protected Sub GridView1_RowUpdating(ByVal sender As Object, ByVal e As System.Web.UI.WebControls.GridViewUpdateEventArgs)
    Response.Write("Values passed from GridView...<br />")
    Dim entry As DictionaryEntry
    For Each entry In e.NewValues
      Response.Write(" <b>" & Server.HtmlEncode(entry.Key) & "</b>=" & Server.HtmlEncode(entry.Value) & " (" & Server.HtmlEncode(entry.Value.GetType().Name) & ")<br />")
    Next
    For Each entry In e.Keys
      Response.Write(" <b>" & Server.HtmlEncode(entry.Key) & "</b>=" & Server.HtmlEncode(entry.Value) & " (" & Server.HtmlEncode(entry.Value.GetType().Name) & ")<br />")
    Next
  End Sub

  Protected Sub SqlDataSource1_Updating(ByVal sender As Object, ByVal e As System.Web.UI.WebControls.SqlDataSourceCommandEventArgs)
    Response.Write("<br/>Parameter order in data source...<br />")
    Dim param As System.Data.OleDb.OleDbParameter
    For Each param In e.Command.Parameters
      Response.Write(" <b>" & Server.HtmlEncode(param.ParameterName) & "</b>=" & Server.HtmlEncode(param.Value) & " (" & Server.HtmlEncode(param.Value.GetType().Name) & ")<br />")
    Next
    ' For demonstration purposes only, cancel the update
    e.Cancel = True
    Response.Write("<br />Update canceled")
  End Sub
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
        UpdateCommand="UPDATE [Orders] SET [OrderDate] = ?, [ShipCountry] = ? WHERE [OrderID] = ?" OnUpdating="SqlDataSource1_Updating">
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
