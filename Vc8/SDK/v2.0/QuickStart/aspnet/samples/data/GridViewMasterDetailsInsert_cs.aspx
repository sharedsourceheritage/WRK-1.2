<%@ Page Language="C#" %>
<script runat="server">

    protected void DetailsView1_ItemInserted(Object sender, System.Web.UI.WebControls.DetailsViewInsertedEventArgs e) 
    {
        if (e.Exception != null)
        {
            ErrorMessageLabel.Text = "An error occured while entering this record.  Please verify you have entered data in the correct format.";
            e.ExceptionHandled = true;
        }
        GridView1.DataBind();
    }

    protected void DetailsView1_ItemUpdated(Object sender, System.Web.UI.WebControls.DetailsViewUpdatedEventArgs e)
    {
        GridView1.DataBind();
    }

    protected void DropDownList1_SelectedIndexChanged(object sender, EventArgs e)
    {
        DetailsView1.ChangeMode(DetailsViewMode.ReadOnly);
    }

    protected void GridView1_SelectedIndexChanged(object sender, EventArgs e)
    {
        DetailsView1.ChangeMode(DetailsViewMode.ReadOnly);
    }

    protected void GridView1_PageIndexChanged(object sender, EventArgs e)
    {
        DetailsView1.ChangeMode(DetailsViewMode.ReadOnly);
    }

    protected void GridView1_Sorted(object sender, EventArgs e)
    {
        DetailsView1.ChangeMode(DetailsViewMode.ReadOnly);
    }
    
    protected void GridView1_RowDeleted(object sender, GridViewDeletedEventArgs e)
    {
        if (e.Exception != null)
        {
            ErrorMessageLabel.Text = "Failed to DELETE due to foreign key contstraint on the table.  You may only delete rows which have no related records.";
            e.ExceptionHandled = true;
        }
    }

    protected void DetailsView1_DataBound(object sender, EventArgs e)
    {
        if (DetailsView1.CurrentMode == DetailsViewMode.Insert)
        {
            TextBox stateTextBox = (TextBox)DetailsView1.Rows[6].Cells[1].Controls[0];
            stateTextBox.Text = DropDownList1.SelectedValue;
            stateTextBox.Enabled = false;
        }
    }

</script>
<html>
<head runat="server">
  <title>GridView DetailsView Master-Details (Insert)</title>
</head>
<body>
  <form id="form1" runat="server">
    <b>Choose a state:</b>
    <asp:DropDownList ID="DropDownList1" DataSourceID="SqlDataSource2" AutoPostBack="true"
      DataTextField="state" runat="server" OnSelectedIndexChanged="DropDownList1_SelectedIndexChanged" />
    <asp:SqlDataSource ID="SqlDataSource2" runat="server" SelectCommand="SELECT DISTINCT [state] FROM [authors]"
      ConnectionString="<%$ ConnectionStrings:Pubs %>" />
    <br />
    <br />
    <table>
      <tr>
        <td valign="top">
          <asp:GridView ID="GridView1" AllowSorting="True" AllowPaging="True" runat="server"
            DataSourceID="SqlDataSource1" DataKeyNames="au_id"
            AutoGenerateColumns="False" Width="500px" SelectedIndex="0" OnSelectedIndexChanged="GridView1_SelectedIndexChanged" OnPageIndexChanged="GridView1_PageIndexChanged" OnRowDeleted="GridView1_RowDeleted" OnSorted="GridView1_Sorted">
            <Columns>
              <asp:CommandField ShowSelectButton="true" ShowDeleteButton="true" />
              <asp:BoundField DataField="au_id" HeaderText="au_id" ReadOnly="True" SortExpression="au_id" />
              <asp:BoundField DataField="au_lname" HeaderText="au_lname" SortExpression="au_lname" />
              <asp:BoundField DataField="au_fname" HeaderText="au_fname" SortExpression="au_fname" />
              <asp:BoundField DataField="state" HeaderText="state" SortExpression="state" />
            </Columns>
          </asp:GridView>
          <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:Pubs %>"
            SelectCommand="SELECT [au_id], [au_lname], [au_fname], [state] FROM [authors] WHERE ([state] = @state)"
            DeleteCommand="DELETE FROM [authors] WHERE [au_id] = @au_id">
            <SelectParameters>
              <asp:ControlParameter ControlID="DropDownList1" Name="state" PropertyName="SelectedValue"
                Type="String" />
            </SelectParameters>
          </asp:SqlDataSource>
        </td>
        <td valign="top">
          <asp:DetailsView AutoGenerateRows="False" DataKeyNames="au_id" DataSourceID="SqlDataSource3"
            HeaderText="Author Details" ID="DetailsView1" runat="server" Width="275px" OnItemUpdated="DetailsView1_ItemUpdated" OnItemInserted="DetailsView1_ItemInserted" OnDataBound="DetailsView1_DataBound">
            <Fields>
              <asp:BoundField DataField="au_id" HeaderText="au_id" ReadOnly="True" SortExpression="au_id" />
              <asp:BoundField DataField="au_lname" HeaderText="au_lname" SortExpression="au_lname" />
              <asp:BoundField DataField="au_fname" HeaderText="au_fname" SortExpression="au_fname" />
              <asp:BoundField DataField="phone" HeaderText="phone" SortExpression="phone" />
              <asp:BoundField DataField="address" HeaderText="address" SortExpression="address" />
              <asp:BoundField DataField="city" HeaderText="city" SortExpression="city" />
              <asp:BoundField DataField="state" HeaderText="state" SortExpression="state" />
              <asp:BoundField DataField="zip" HeaderText="zip" SortExpression="zip" />
              <asp:CheckBoxField DataField="contract" HeaderText="contract" SortExpression="contract" />
              <asp:CommandField ShowEditButton="True" ShowInsertButton="True" />
            </Fields>
          </asp:DetailsView>
          <asp:SqlDataSource ID="SqlDataSource3" runat="server" ConnectionString="<%$ ConnectionStrings:Pubs %>"
            SelectCommand="SELECT [au_id], [au_lname], [au_fname], [phone], [address], [city], [state], [zip], [contract] FROM [authors] WHERE ([au_id] = @au_id)"
            UpdateCommand="UPDATE [authors] SET [au_lname] = @au_lname, [au_fname] = @au_fname, [phone] = @phone, [address] = @address, [city] = @city, [state] = @state, [zip] = @zip, [contract] = @contract WHERE [au_id] = @au_id"
            InsertCommand="INSERT INTO [authors] ([au_id], [au_lname], [au_fname], [phone], [address], [city], [state], [zip], [contract]) VALUES (@au_id, @au_lname, @au_fname, @phone, @address, @city, @state, @zip, @contract)">
            <SelectParameters>
              <asp:ControlParameter ControlID="GridView1" Name="au_id" PropertyName="SelectedValue"
                Type="String" />
            </SelectParameters>
            <UpdateParameters>
              <asp:Parameter Name="au_lname" Type="String" />
              <asp:Parameter Name="au_fname" Type="String" />
              <asp:Parameter Name="phone" Type="String" />
              <asp:Parameter Name="address" Type="String" />
              <asp:Parameter Name="city" Type="String" />
              <asp:Parameter Name="state" Type="String" />
              <asp:Parameter Name="zip" Type="String" />
              <asp:Parameter Name="contract" Type="Boolean" />
              <asp:Parameter Name="au_id" Type="String" />
            </UpdateParameters>
            <InsertParameters>
              <asp:Parameter Name="au_id" Type="String" />
              <asp:Parameter Name="au_lname" Type="String" />
              <asp:Parameter Name="au_fname" Type="String" />
              <asp:Parameter Name="phone" Type="String" />
              <asp:Parameter Name="address" Type="String" />
              <asp:Parameter Name="city" Type="String" />
              <asp:Parameter Name="state" Type="String" />
              <asp:Parameter Name="zip" Type="String" />
              <asp:Parameter Name="contract" Type="Boolean" />
            </InsertParameters>
          </asp:SqlDataSource>
        </td>
      </tr>
    </table>
    <br />
    <asp:Label ID="ErrorMessageLabel" EnableViewState="false" runat="server" />
  </form>
</body>
</html>
