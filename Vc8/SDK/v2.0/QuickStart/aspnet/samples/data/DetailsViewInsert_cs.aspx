<%@ Page Language="C#" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<script runat="server">

  protected void DetailsView1_ItemInserted(Object sender, System.Web.UI.WebControls.DetailsViewInsertedEventArgs e)
  {
    Response.Redirect("GridViewMasterDetailsInsertPage_cs.aspx");
  }

  protected void DetailsView1_ModeChanging(Object sender, System.Web.UI.WebControls.DetailsViewModeEventArgs e)
  {
    if (e.CancelingEdit == true)
    {
      Response.Redirect("GridViewMasterDetailsInsertPage_cs.aspx");
    }
  }
</script>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
  <title>DetailsView Insert</title>
</head>
<body>
  <form id="form1" runat="server">
    <asp:DetailsView DefaultMode="Insert" AutoGenerateRows="False" DataKeyNames="au_id"
      DataSourceID="SqlDataSource3" HeaderText="Insert Author" ID="DetailsView1" runat="server"
      Width="275px" OnItemInserted="DetailsView1_ItemInserted" OnModeChanging="DetailsView1_ModeChanging">
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
        <asp:CommandField ShowInsertButton="True" />
      </Fields>
    </asp:DetailsView>
    <asp:SqlDataSource ID="SqlDataSource3" runat="server" ConnectionString="<%$ ConnectionStrings:Pubs %>"
      SelectCommand="SELECT [au_id], [au_lname], [au_fname], [phone], [address], [city], [state], [zip], [contract] FROM [authors] WHERE ([au_id] = @au_id)"
      InsertCommand="INSERT INTO [authors] ([au_id], [au_lname], [au_fname], [phone], [address], [city], [state], [zip], [contract]) VALUES (@au_id, @au_lname, @au_fname, @phone, @address, @city, @state, @zip, @contract)">
      <SelectParameters>
        <asp:QueryStringParameter Name="au_id" QueryStringField="ID" Type="String" />
      </SelectParameters>
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
  </form>
</body>
</html>
