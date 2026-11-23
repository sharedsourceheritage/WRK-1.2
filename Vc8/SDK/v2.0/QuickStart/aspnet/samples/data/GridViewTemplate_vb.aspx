<%@ Page Language="VB" %>
<html>
  <head runat="server">
    <title>Filtering Data In A GridView Using a DropDownList</title>
  </head>
  <body>
    <form id="form1" runat="server">
      <b>Choose a state:</b>
      <asp:DropDownList ID="DropDownList1" DataSourceID="SqlDataSource2" AutoPostBack="true"
        DataTextField="state" Runat="server" />
      <asp:SqlDataSource ID="SqlDataSource2" Runat="server" SelectCommand="SELECT DISTINCT [state] FROM [authors]"
        ConnectionString="<%$ ConnectionStrings:Pubs %>" />
      <br />
      <br />
      <asp:GridView ID="GridView1" AllowSorting="True" AllowPaging="True" Runat="server"
        DataSourceID="SqlDataSource1" AutoGenerateEditButton="True" DataKeyNames="au_id"
        AutoGenerateColumns="False">
        <Columns>
          <asp:BoundField ReadOnly="true" HeaderText="au_id" DataField="au_id" SortExpression="au_id" />
          <asp:BoundField HeaderText="au_lname" DataField="au_lname" SortExpression="au_lname" />
          <asp:BoundField HeaderText="au_fname" DataField="au_fname" SortExpression="au_fname" />
          <asp:BoundField HeaderText="phone" DataField="phone" SortExpression="phone" />
          <asp:BoundField HeaderText="address" DataField="address" SortExpression="address" />
          <asp:BoundField HeaderText="city" DataField="city" SortExpression="city" />
          <asp:TemplateField SortExpression="state" HeaderText="state"><EditItemTemplate>
            <asp:DropDownList ID="DropDownList2" Runat="server" DataTextField="state" DataSourceID="SqlDataSource2"
              SelectedValue='<%# Bind("state") %>' DataValueField="state" />
          </EditItemTemplate>
            <ItemTemplate>
              <asp:Label ID="Label1" Runat="server" Text='<%# Eval("state") %>' />
            </ItemTemplate>
          </asp:TemplateField>
          <asp:BoundField HeaderText="zip" DataField="zip" SortExpression="zip" />
          <asp:CheckBoxField HeaderText="contract" SortExpression="contract" DataField="contract" />
          <asp:HyperLinkField HeaderText="View Details..." Text="View Details..." DataNavigateUrlFields="au_id"
            DataNavigateUrlFormatString="DetailsView_vb.aspx?ID={0}" />
        </Columns>
      </asp:GridView>
      <asp:SqlDataSource ID="SqlDataSource1" Runat="server" SelectCommand="SELECT [au_id], [au_lname], [au_fname], [phone], [address], [city], [state], [zip], [contract] FROM [authors] WHERE [state] = @state"
        UpdateCommand="UPDATE [authors] SET [au_lname] = @au_lname, [au_fname] = @au_fname, [phone] = @phone, [address] = @address, [city] = @city, [state] = @state, [zip] = @zip, [contract] = @contract WHERE [au_id] = @au_id"
        ConnectionString="<%$ ConnectionStrings:Pubs %>">
        <SelectParameters>
          <asp:ControlParameter Name="state" ControlID="DropDownList1" />
        </SelectParameters>
      </asp:SqlDataSource>
    </form>
  </body>
</html>
