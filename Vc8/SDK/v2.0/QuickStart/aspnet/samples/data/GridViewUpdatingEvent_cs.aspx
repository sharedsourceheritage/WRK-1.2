<%@ Page Language="C#" %>
<script runat="server">

  void GridView1_RowEditing(Object sender, System.Web.UI.WebControls.GridViewEditEventArgs e) {

    // Fired when the user clicks the Edit button in read-only mode
    Response.Write("Row editing...");
    
    // If GridView is already in edit mode, cancel Edit operation
    if (GridView1.EditIndex != -1) {
      e.Cancel = true;
    }
  }
  
  void GridView1_RowUpdating(Object sender, System.Web.UI.WebControls.GridViewUpdateEventArgs e) {
 
    // Fired when the user clicks the Update button in edit mode
    Response.Write("GridView: Row updating...<br/>");
    
     // Can optionally cancel the event here too, for example if user should not be allowed to update data
    if (User.IsInRole("Restricted")) {
      e.Cancel = true;
    }
  }
  
  void GridView1_RowUpdated(Object sender, System.Web.UI.WebControls.GridViewUpdatedEventArgs e) {

    // Fired when after the update operation is complete
    Response.Write("GridView: Row updated<br/>");
    
    if (e.Exception != null) {
      // Can perform custom error handling here, set ExceptionHandled = true when done
      e.ExceptionHandled = true;
    }

    // Can check the number of rows affected by the update
    Response.Write("<br />Affected rows: " + Server.HtmlEncode(e.AffectedRows.ToString()));
  }
  
  void GridView1_RowCancelingEdit(Object sender, System.Web.UI.WebControls.GridViewCancelEditEventArgs e) {
    // Fired when the user clicks the Cancel button in edit mode
    Response.Write("Edit canceled");
  }

  void SqlDataSource1_Updated(Object sender, System.Web.UI.WebControls.SqlDataSourceStatusEventArgs e) {
    
    // Fired when the update operation is complete
    Response.Write("SqlDataSource: Update complete<br />");
  }

  void SqlDataSource1_Updating(Object sender, System.Web.UI.WebControls.SqlDataSourceCommandEventArgs e) {
 
    // Fired when the update operation is invoked
    Response.Write("SqlDataSource: Updating...");
  }
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
