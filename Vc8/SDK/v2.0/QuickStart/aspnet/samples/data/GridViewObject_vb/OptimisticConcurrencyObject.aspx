<%@ Page Language="VB" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<script runat="server">

  Sub DetailsView1_ItemUpdated(sender As Object, e As System.Web.UI.WebControls.DetailsViewUpdatedEventArgs)
  
    If e.AffectedRows = 0 Then
    
      ' Keep DetailsView in edit mode and synchronize to database
      e.KeepInEditMode = true
      DetailsView1.DataBind()

      ' Re-populate DetailsView with values entered by user
      Dim t As TextBox
      t = DetailsView1.Rows(1).Cells(1).Controls(0)
      t.Text = e.NewValues("ContactName")

      ErrorPanel.Visible = true
    
    Else
    
      ErrorPanel.Visible = false
    End If
  End Sub

  Sub DetailsView1_ModeChanging(ByVal sender As Object, ByVal e As System.Web.UI.WebControls.DetailsViewModeEventArgs)
  
    If e.CancelingEdit = True AndAlso ErrorPanel.Visible = True Then
    
      ErrorPanel.Visible = False
    End If
  End Sub

  Protected Sub ObjectDataSource1_Updated(ByVal sender As Object, ByVal e As System.Web.UI.WebControls.ObjectDataSourceStatusEventArgs)
    e.AffectedRows = e.ReturnValue
  End Sub
  
</script>
<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
  <title>Handling Optimistic Concurrency Failures</title>
</head>
<body>
  <form id="form1" runat="server">
    <div>
      <asp:Panel ID="ErrorPanel" runat="server" Visible="False" Width="582px">
        <span style="color: #ff0000">Another user has updated this row (details below). Click
          "Update" to overwite this row with your values. Click "Cancel" to abort the update
          operation.</span><br />
        <br />
        <asp:GridView AutoGenerateColumns="False" DataSourceID="ObjectDataSource2"
          ID="GridView1" runat="server" Width="518px">
          <Columns>
            <asp:BoundField DataField="ContactID" HeaderText="ContactID" SortExpression="ContactID" />
            <asp:BoundField DataField="ContactName" HeaderText="ContactName" SortExpression="ContactName" />
          </Columns>
        </asp:GridView>
        <asp:ObjectDataSource ID="ObjectDataSource2" runat="server" SelectMethod="GetContact"
          TypeName="ContactsListOptimistic">
          <SelectParameters>
            <asp:ControlParameter ControlID="DetailsView1" Name="contactID" PropertyName="SelectedValue"
              Type="Int32" />
          </SelectParameters>
        </asp:ObjectDataSource>
        <br />
        <br />
      </asp:Panel>
      <asp:DetailsView AutoGenerateRows="False" DataSourceID="ObjectDataSource1"
        HeaderText="Contact Details" ID="DetailsView1" runat="server" Width="314px" OnItemUpdated="DetailsView1_ItemUpdated"
        OnModeChanging="DetailsView1_ModeChanging" DataKeyNames="ContactID">
        <Fields>
          <asp:BoundField DataField="ContactID" HeaderText="ContactID" SortExpression="ContactID" ReadOnly="True" />
          <asp:BoundField DataField="ContactName" HeaderText="ContactName" SortExpression="ContactName" />
          <asp:CommandField ShowEditButton="True" />
        </Fields>
      </asp:DetailsView>
      <asp:ObjectDataSource TypeName="ContactsListOptimistic" ID="ObjectDataSource1" runat="server"
        SelectMethod="GetContacts" UpdateMethod="UpdateContact" ConflictDetection="CompareAllValues"
        OldValuesParameterFormatString="original_{0}" OnUpdated="ObjectDataSource1_Updated">
        <UpdateParameters>
          <asp:Parameter Name="contactName" Type="String" />
          <asp:Parameter Name="original_contactID" Type="Int32" />
          <asp:Parameter Name="original_contactName" Type="String" />
        </UpdateParameters>
      </asp:ObjectDataSource>
    </div>
  </form>
</body>
</html>
