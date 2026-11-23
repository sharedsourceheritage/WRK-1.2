<%@ Page Language="C#" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<script runat="server">

  void EnumerateDictionary(System.Collections.Specialized.IOrderedDictionary dictionary) {
    
    foreach (DictionaryEntry entry in dictionary) {
      Response.Write(" <b>" + Server.HtmlEncode(entry.Key.ToString()) + "</b>=" + Server.HtmlEncode(entry.Value.ToString()) + " (" + Server.HtmlEncode(entry.Value.GetType().Name) + ")<br />");
    }
  }
  
  void EnumerateCommandParameters(System.Data.Common.DbCommand command) {
    
    Response.Write("<br/>Parameter order in data source...<br />");
     
    foreach (System.Data.Common.DbParameter param in command.Parameters) {
      Response.Write(" <b>" + Server.HtmlEncode(param.ParameterName) + "</b>=" + Server.HtmlEncode(param.Value.ToString()) + " (" + Server.HtmlEncode(param.Value.GetType().Name) + ")<br />");
    }
  }
  
  void DetailsView1_ItemUpdating(Object sender, System.Web.UI.WebControls.DetailsViewUpdateEventArgs e) {

    Response.Write("<br/>New Values passed from DetailsView...<br />");
    EnumerateDictionary(e.NewValues);

    Response.Write("<br/>Keys passed from DetailsView...<br />");
    EnumerateDictionary(e.Keys);

    Response.Write("<br/>Old Values passed from DetailsView...<br />");
    EnumerateDictionary(e.OldValues);
  }

  void DetailsView1_ItemDeleting(Object sender, System.Web.UI.WebControls.DetailsViewDeleteEventArgs e) {

    Response.Write("<br/>Keys passed from DetailsView...<br />");
    EnumerateDictionary(e.Keys);

    Response.Write("<br/>Values passed from DetailsView...<br />");
    EnumerateDictionary(e.Values);
  }
  
  void DetailsView1_ItemInserting(Object sender, System.Web.UI.WebControls.DetailsViewInsertEventArgs e) {
    Response.Write("<br/>Values passed from DetailsView...<br />");
    EnumerateDictionary(e.Values);
  }
    
  void SqlDataSource1_Updating(Object sender, System.Web.UI.WebControls.SqlDataSourceCommandEventArgs e) {
    EnumerateCommandParameters(e.Command);
    e.Cancel = true;
    // For demonstration purposes only, cancel the update
    Response.Write("<br/>Update canceled");
  }
  
  void SqlDataSource1_Deleting(Object sender, System.Web.UI.WebControls.SqlDataSourceCommandEventArgs e) {
    EnumerateCommandParameters(e.Command);
    // For demonstration purposes only, cancel the delete
    e.Cancel = true;
    Response.Write("<br/>Delete canceled");
  }
  
  void SqlDataSource1_Inserting(Object sender, System.Web.UI.WebControls.SqlDataSourceCommandEventArgs e) {
    EnumerateCommandParameters(e.Command);
    // For demonstration purposes only, cancel the insert
    e.Cancel = true;
    Response.Write("<br/>Insert canceled");
  }
</script>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
  <title>Enumerating Parameters</title>
</head>
<body>
  <form id="form1" runat="server">
    <div>
      &nbsp;<asp:DetailsView AutoGenerateRows="False" DataKeyNames="OrderID" DataSourceID="SqlDataSource1"
        HeaderText=" Order Details" ID="DetailsView1" OnItemUpdating="DetailsView1_ItemUpdating"
        runat="server" Width="314px" OnItemDeleting="DetailsView1_ItemDeleting" OnItemInserting="DetailsView1_ItemInserting">
        <Fields>
          <asp:BoundField DataField="OrderID" HeaderText="OrderID" InsertVisible="False" ReadOnly="True"
            SortExpression="OrderID" />
          <asp:BoundField DataField="OrderDate" HeaderText="OrderDate" SortExpression="OrderDate" />
          <asp:BoundField DataField="ShipCountry" HeaderText="ShipCountry" SortExpression="ShipCountry" />
          <asp:CommandField ShowDeleteButton="True" ShowEditButton="True" ShowInsertButton="True" />
        </Fields>
      </asp:DetailsView>
      <asp:SqlDataSource ConnectionString="<%$ ConnectionStrings:Northwind %>" ID="SqlDataSource1"
        runat="server" SelectCommand="SELECT [OrderID], [OrderDate], [ShipCountry] FROM [Orders]"
        DeleteCommand="DELETE FROM [Orders] WHERE [OrderID] = @OrderID" InsertCommand="INSERT INTO [Orders] ([OrderDate], [ShipCountry]) VALUES (@OrderDate, @ShipCountry)"
        UpdateCommand="UPDATE [Orders] SET [OrderDate] = @OrderDate, [ShipCountry] = @ShipCountry WHERE [OrderID] = @OrderID"
        OnUpdating="SqlDataSource1_Updating" OnDeleting="SqlDataSource1_Deleting" OnInserting="SqlDataSource1_Inserting">
        <DeleteParameters>
          <asp:Parameter Name="OrderID" Type="Int32" />
        </DeleteParameters>
        <UpdateParameters>
          <asp:Parameter Name="OrderDate" Type="DateTime" />
          <asp:Parameter Name="ShipCountry" Type="String" />
          <asp:Parameter Name="OrderID" Type="Int32" />
        </UpdateParameters>
        <InsertParameters>
          <asp:Parameter Name="OrderDate" Type="DateTime" />
          <asp:Parameter Name="ShipCountry" Type="String" />
        </InsertParameters>
      </asp:SqlDataSource>
    </div>
  </form>
</body>
</html>
