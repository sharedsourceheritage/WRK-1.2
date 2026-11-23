<%@ Page Language="VB" %>
<script runat="server">

  Protected Sub GridView1_RowEditing(ByVal sender As Object, ByVal e As System.Web.UI.WebControls.GridViewEditEventArgs)

    ' Fired when the user clicks the Edit button in read-only mode
    Response.Write("Row editing...")
    
    ' If GridView is already in edit mode, cancel Edit operation
    If Not GridView1.EditIndex = -1 Then
      e.Cancel = True
    End If
  End Sub
  
  Protected Sub GridView1_RowUpdating(ByVal sender As Object, ByVal e As System.Web.UI.WebControls.GridViewUpdateEventArgs)
 
    ' Fired when the user clicks the Update button in edit mode
    Response.Write("GridView: Row updating...<br/>")
    
    'Can optionally cancel the event here too, for example if user should not be allowed to update data
        If User.IsInRole("Restricted") Then
            e.Cancel = True
        End If
  End Sub
  
  Protected Sub GridView1_RowUpdated(ByVal sender As Object, ByVal e As System.Web.UI.WebControls.GridViewUpdatedEventArgs)

    ' Fired when after the update operation is complete
    Response.Write("GridView: Row updated<br/>")
    
    If Not e.Exception Is Nothing Then
      ' Can perform custom error handling here, set ExceptionHandled = true when done
      e.ExceptionHandled = True
    End If

    ' Can check the number of rows affected by the update
    Response.Write("<br />Affected rows: " & Server.HtmlEncode(e.AffectedRows))
  End Sub
  
  Protected Sub GridView1_RowCancelingEdit(ByVal sender As Object, ByVal e As System.Web.UI.WebControls.GridViewCancelEditEventArgs)
    ' Fired when the user clicks the Cancel button in edit mode
        Response.Write("Edit canceled")
  End Sub

  Protected Sub SqlDataSource1_Updated(ByVal sender As Object, ByVal e As System.Web.UI.WebControls.SqlDataSourceStatusEventArgs)
    
    ' Fired when the update operation is complete
    Response.Write("SqlDataSource: Update complete<br />")
  End Sub

  Protected Sub SqlDataSource1_Updating(ByVal sender As Object, ByVal e As System.Web.UI.WebControls.SqlDataSourceCommandEventArgs)
 
    ' Fired when the update operation is invoked
    Response.Write("SqlDataSource: Updating...")
  End Sub
</script>
<html>
  <head runat="server">
    <title>Handling Data Control Events</title>
  </head>
  <body>
    <form id="form1" runat="server">
      <asp:GridView ID="GridView1" AllowSorting="True" AllowPaging="True" Runat="server"
        DataSourceID="SqlDataSource1" AutoGenerateEditButton="True" DataKeyNames="au_id"
        AutoGenerateColumns="False" OnRowUpdating="GridView1_RowUpdating" OnRowUpdated="GridView1_RowUpdated" OnRowEditing="GridView1_RowEditing" OnRowCancelingEdit="GridView1_RowCancelingEdit">
        <Columns>
          <asp:BoundField ReadOnly="True" HeaderText="ID" DataField="au_id" SortExpression="au_id" />
          <asp:BoundField HeaderText="Last Name" DataField="au_lname" SortExpression="au_lname" />
          <asp:BoundField HeaderText="First Name" DataField="au_fname" SortExpression="au_fname" />
          <asp:BoundField HeaderText="Phone" DataField="phone" SortExpression="phone" />
          <asp:BoundField HeaderText="Address" DataField="address" SortExpression="address" />
          <asp:BoundField HeaderText="City" DataField="city" SortExpression="city" />
          <asp:BoundField HeaderText="State" DataField="state" SortExpression="state" />
          <asp:BoundField HeaderText="Zip Code" DataField="zip" SortExpression="zip" />
          <asp:CheckBoxField HeaderText="Contract" SortExpression="contract" DataField="contract" />
        </Columns>
      </asp:GridView>
      <asp:SqlDataSource ID="SqlDataSource1" Runat="server" SelectCommand="SELECT [au_id], [au_lname], [au_fname], [phone], [address], [city], [state], [zip], [contract] FROM [authors]"
        UpdateCommand="UPDATE [authors] SET [au_lname] = @au_lname, [au_fname] = @au_fname, [phone] = @phone, [address] = @address, [city] = @city, [state] = @state, [zip] = @zip, [contract] = @contract WHERE [au_id] = @au_id"
        ConnectionString="<%$ ConnectionStrings:Pubs %>" OnUpdated="SqlDataSource1_Updated" OnUpdating="SqlDataSource1_Updating" />
    </form>
  </body>
</html>
