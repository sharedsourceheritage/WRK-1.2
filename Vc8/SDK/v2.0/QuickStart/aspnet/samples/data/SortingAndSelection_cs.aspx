<%@ Page Language="C#" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<script runat="server">

  void GridView1_DataBound(Object sender, System.EventArgs e) {
        
    String selectedValue = (String)ViewState["SelectedValue"];
    if (selectedValue == null) {
      return;
    }

    // Determine if the selected row is visible and re-select it
    foreach (GridViewRow row in GridView1.Rows) {
        String keyValue = GridView1.DataKeys[row.RowIndex].Value.ToString();
        if (keyValue == selectedValue) {
          GridView1.SelectedIndex = row.RowIndex;
      }
    }
  }

  void GridView1_SelectedIndexChanged(Object sender, System.EventArgs e) {
    // Save selected index
    if (GridView1.SelectedIndex != -1) {
      ViewState["SelectedValue"] = GridView1.SelectedValue;
    }
  }

  void GridView1_PageIndexChanging(Object sender, System.Web.UI.WebControls.GridViewPageEventArgs e) {
    // Reset selected index
    GridView1.SelectedIndex = -1;
  }
  
  void GridView1_Sorting(Object sender, System.Web.UI.WebControls.GridViewSortEventArgs e) {
    // Reset selected index
    GridView1.SelectedIndex = -1;
  }

  </script>
<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
  <title>Untitled Page</title>
</head>
<body>
  <form id="form1" runat="server">
    <div>
      <asp:GridView ID="GridView1" runat="server" DataSourceID="SqlDataSource1" DataKeyNames="au_id"
        AutoGenerateColumns="False" AllowPaging="True" AllowSorting="True" OnSorting="GridView1_Sorting"
        OnDataBound="GridView1_DataBound" OnSelectedIndexChanged="GridView1_SelectedIndexChanged" OnPageIndexChanging="GridView1_PageIndexChanging">
        <Columns>
          <asp:CommandField ShowSelectButton="True" />
          <asp:BoundField ReadOnly="True" HeaderText="au_id" DataField="au_id" SortExpression="au_id" />
          <asp:BoundField HeaderText="au_lname" DataField="au_lname" SortExpression="au_lname" />
          <asp:BoundField HeaderText="au_fname" DataField="au_fname" SortExpression="au_fname" />
        </Columns>
        <SelectedRowStyle BackColor="#C0FFC0" />
      </asp:GridView>
      <asp:SqlDataSource ID="SqlDataSource1" runat="server" ProviderName="System.Data.SqlClient"
        ConnectionString="<%$ ConnectionStrings:Pubs %>" SelectCommand="SELECT [au_id], [au_lname], [au_fname] FROM [authors]" />
    </div>
  </form>
</body>
</html>
