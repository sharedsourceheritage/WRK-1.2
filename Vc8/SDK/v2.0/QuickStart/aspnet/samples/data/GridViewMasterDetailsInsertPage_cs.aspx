<%@ Page Language="C#" %>

<script runat="server">

    protected void GridView1_RowDeleted(object sender, GridViewDeletedEventArgs e)
    {
        if (e.Exception != null)
        {
            ErrorMessageLabel.Text = "Failed to DELETE due to foreign key contstraint on the table.  You may only delete rows which have no related records.";
            e.ExceptionHandled = true;
        }
    }
    
</script>

<html>
<head id="Head1" runat="server">
  <title>GridView DetailsView Master-Details (Edit and Insert Pages)</title>
</head>
<body>
  <form id="form1" runat="server">
    <b>Choose a state:</b>
    <asp:DropDownList ID="DropDownList1" DataSourceID="SqlDataSource2" AutoPostBack="true"
      DataTextField="state" runat="server" />
    <asp:SqlDataSource ID="SqlDataSource2" runat="server" SelectCommand="SELECT DISTINCT [state] FROM [authors]"
      ConnectionString="<%$ ConnectionStrings:Pubs %>" />
    <br />
    <br />
          <asp:GridView ID="GridView1" AllowSorting="True" AllowPaging="True" runat="server"
            DataSourceID="SqlDataSource1" DataKeyNames="au_id"
            AutoGenerateColumns="False" Width="500px" OnRowDeleted="GridView1_RowDeleted">
            <Columns>
              <asp:CommandField ShowDeleteButton="True" />
              <asp:BoundField DataField="au_id" HeaderText="au_id" ReadOnly="True" SortExpression="au_id" />
              <asp:BoundField DataField="au_lname" HeaderText="au_lname" SortExpression="au_lname" />
              <asp:BoundField DataField="au_fname" HeaderText="au_fname" SortExpression="au_fname" />
              <asp:BoundField DataField="state" HeaderText="state" SortExpression="state" />
              <asp:HyperLinkField HeaderText="Edit..." Text="Edit..." DataNavigateUrlFields="au_id"
                DataNavigateUrlFormatString="DetailsViewEdit_cs.aspx?ID={0}" />          
            </Columns>
          </asp:GridView>
          <br />
          <asp:HyperLink ID="HyperLink1" Text="Add New Author..." NavigateUrl="DetailsViewInsert_cs.aspx" runat="server" />
          <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
            ConnectionString="<%$ ConnectionStrings:Pubs %>"
            SelectCommand="SELECT [au_id], [au_lname], [au_fname], [state] FROM [authors] WHERE ([state] = @state)"
            DeleteCommand="DELETE FROM [authors] WHERE [au_id] = @au_id">
            <SelectParameters>
              <asp:ControlParameter ControlID="DropDownList1" Name="state" PropertyName="SelectedValue"
                Type="String" />
            </SelectParameters>
            <DeleteParameters>
              <asp:Parameter Name="au_id" Type="String" />
            </DeleteParameters>
          </asp:SqlDataSource>
          <br />
          <br />
          <asp:Label ID="ErrorMessageLabel" EnableViewState="false" runat="server" />
  </form>
</body>
</html>
