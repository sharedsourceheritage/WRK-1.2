<%@ Page Language="VB" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<script runat="server">

  Protected Sub DetailsView1_ItemUpdated(ByVal sender As Object, ByVal e As System.Web.UI.WebControls.DetailsViewUpdatedEventArgs)
    If e.AffectedRows = 0 Then
      
      ' Keep DetailsView in edit mode and synchronize to database
      e.KeepInEditMode = True
      DetailsView1.DataBind()

      ' Re-populate DetailsView with values entered by user
      Dim t As TextBox
      t = DetailsView1.Rows(1).Cells(1).Controls(0)
      t.Text = e.NewValues("OrderDate")
      t = DetailsView1.Rows(2).Cells(1).Controls(0)
      t.Text = e.NewValues("ShipCountry")

      ErrorPanel.Visible = True
    Else
      ErrorPanel.Visible = False
    End If
  End Sub

  Protected Sub DetailsView1_ModeChanging(ByVal sender As Object, ByVal e As System.Web.UI.WebControls.DetailsViewModeEventArgs)
    If e.CancelingEdit = True AndAlso ErrorPanel.Visible = True Then
      ErrorPanel.Visible = False
    End If
  End Sub
</script>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
  <title>Handling Optimistic Concurrency Failures</title>
</head>
<body>
  <form id="form1" runat="server">
    <div>
      <asp:Panel ID="ErrorPanel" runat="server" Visible="False" Width="582px">
        <span style="color: #ff0000">Another user has updated this row (details below).
          Click "Update" to overwite this row with your values. Click "Cancel" to
          abort the update operation.</span><br /><br />
        <asp:GridView AutoGenerateColumns="False" DataKeyNames="OrderID" DataSourceID="SqlDataSource2"
          ID="GridView1" runat="server" Width="518px">
          <Columns>
            <asp:BoundField DataField="OrderID" HeaderText="OrderID" InsertVisible="False" ReadOnly="True"
              SortExpression="OrderID" />
            <asp:BoundField DataField="OrderDate" HeaderText="OrderDate" SortExpression="OrderDate" />
            <asp:BoundField DataField="ShipCountry" HeaderText="ShipCountry" SortExpression="ShipCountry" />
          </Columns>
        </asp:GridView>
        <asp:SqlDataSource ConnectionString="<%$ ConnectionStrings:Northwind %>" ID="SqlDataSource2"
          runat="server" SelectCommand="SELECT [OrderID], [OrderDate], [ShipCountry] FROM [Orders] WHERE ([OrderID] = @OrderID)">
          <SelectParameters>
            <asp:ControlParameter ControlID="DetailsView1" Name="OrderID" PropertyName="SelectedValue"
              Type="Int32" />
          </SelectParameters>
        </asp:SqlDataSource>
        <br />
        <br />
      </asp:Panel>
      <asp:DetailsView AutoGenerateRows="False" DataKeyNames="OrderID" DataSourceID="SqlDataSource1"
        HeaderText=" Order Details" ID="DetailsView1" runat="server" Width="314px" OnItemUpdated="DetailsView1_ItemUpdated" OnModeChanging="DetailsView1_ModeChanging">
        <Fields>
          <asp:BoundField DataField="OrderID" HeaderText="OrderID" InsertVisible="False" ReadOnly="True"
            SortExpression="OrderID" />
          <asp:BoundField DataField="OrderDate" HeaderText="OrderDate" SortExpression="OrderDate" />
          <asp:BoundField DataField="ShipCountry" HeaderText="ShipCountry" SortExpression="ShipCountry" />
          <asp:CommandField ShowEditButton="True" />
        </Fields>
      </asp:DetailsView>
      <asp:SqlDataSource ConnectionString="<%$ ConnectionStrings:Northwind %>" ID="SqlDataSource1"
        runat="server" SelectCommand="SELECT [OrderID], [OrderDate], [ShipCountry] FROM [Orders]"
        UpdateCommand="UPDATE [Orders] SET [OrderDate] = @OrderDate, [ShipCountry] = @ShipCountry WHERE [OrderID] = @original_OrderID AND [OrderDate] = @original_OrderDate AND [ShipCountry] = @original_ShipCountry"
        ConflictDetection="CompareAllValues" OldValuesParameterFormatString="original_{0}">
        <UpdateParameters>
          <asp:Parameter Name="OrderDate" Type="DateTime" />
          <asp:Parameter Name="ShipCountry" Type="String" />
          <asp:Parameter Name="original_OrderID" Type="Int32" />
          <asp:Parameter Name="original_OrderDate" Type="DateTime" />
          <asp:Parameter Name="original_ShipCountry" Type="String" />
        </UpdateParameters>
      </asp:SqlDataSource>
    </div>
  </form>
</body>
</html>
