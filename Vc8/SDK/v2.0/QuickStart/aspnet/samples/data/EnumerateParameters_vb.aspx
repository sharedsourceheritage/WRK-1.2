<%@ Page Language="VB" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<script runat="server">

  Protected Sub EnumerateDictionary(ByVal dictionary As System.Collections.Specialized.IOrderedDictionary)
    
    Dim entry As DictionaryEntry
    For Each entry In dictionary
      Response.Write(" <b>" & Server.HtmlEncode(entry.Key) & "</b>=" & Server.HtmlEncode(entry.Value) & " (" & Server.HtmlEncode(entry.Value.GetType().Name) & ")<br />")
    Next
  End Sub
  
  Protected Sub EnumerateCommandParameters(ByVal command As System.Data.Common.DbCommand)
    
    Response.Write("<br/>Parameter order in data source...<br />")
    Dim param As System.Data.Common.DbParameter
    For Each param In command.Parameters
      Response.Write(" <b>" & Server.HtmlEncode(param.ParameterName) & "</b>=" & Server.HtmlEncode(param.Value) & " (" & Server.HtmlEncode(param.Value.GetType().Name) & ")<br />")
    Next
  End Sub
  
  Protected Sub DetailsView1_ItemUpdating(ByVal sender As Object, ByVal e As System.Web.UI.WebControls.DetailsViewUpdateEventArgs)

    Response.Write("<br/>New Values passed from DetailsView...<br />")
    EnumerateDictionary(e.NewValues)

    Response.Write("<br/>Keys passed from DetailsView...<br />")
    EnumerateDictionary(e.Keys)

    Response.Write("<br/>Old Values passed from DetailsView...<br />")
    EnumerateDictionary(e.OldValues)
  End Sub

  Protected Sub DetailsView1_ItemDeleting(ByVal sender As Object, ByVal e As System.Web.UI.WebControls.DetailsViewDeleteEventArgs)    

    Response.Write("<br/>Keys passed from DetailsView...<br />")
    EnumerateDictionary(e.Keys)

    Response.Write("<br/>Values passed from DetailsView...<br />")
    EnumerateDictionary(e.Values)
  End Sub
  
  Protected Sub DetailsView1_ItemInserting(ByVal sender As Object, ByVal e As System.Web.UI.WebControls.DetailsViewInsertEventArgs)
    Response.Write("<br/>Values passed from DetailsView...<br />")
    EnumerateDictionary(e.Values)
  End Sub
    
  Protected Sub SqlDataSource1_Updating(ByVal sender As Object, ByVal e As System.Web.UI.WebControls.SqlDataSourceCommandEventArgs)
    EnumerateCommandParameters(e.Command)
    ' For demonstration purposes only, cancel the update
    e.Cancel = True
    Response.Write("<br/>Update canceled")
  End Sub
  
  Protected Sub SqlDataSource1_Deleting(ByVal sender As Object, ByVal e As System.Web.UI.WebControls.SqlDataSourceCommandEventArgs)
    EnumerateCommandParameters(e.Command)
    ' For demonstration purposes only, cancel the delete
    e.Cancel = True
    Response.Write("<br/>Delete canceled")
  End Sub
  
  Protected Sub SqlDataSource1_Inserting(ByVal sender As Object, ByVal e As System.Web.UI.WebControls.SqlDataSourceCommandEventArgs)
    EnumerateCommandParameters(e.Command)
    ' For demonstration purposes only, cancel the insert
    e.Cancel = True
    Response.Write("<br/>Insert canceled")
  End Sub
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
      <asp:SqlDataSource ConnectionString="<%$ ConnectionStrings:Northwind %>" ID="SqlDataSource1" runat="server"
        SelectCommand="SELECT [OrderID], [OrderDate], [ShipCountry] FROM [Orders]" DeleteCommand="DELETE FROM [Orders] WHERE [OrderID] = @OrderID"
        InsertCommand="INSERT INTO [Orders] ([OrderDate], [ShipCountry]) VALUES (@OrderDate, @ShipCountry)"
        UpdateCommand="UPDATE [Orders] SET [OrderDate] = @OrderDate, [ShipCountry] = @ShipCountry WHERE [OrderID] = @OrderID" OnUpdating="SqlDataSource1_Updating" OnDeleting="SqlDataSource1_Deleting" OnInserting="SqlDataSource1_Inserting">
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
