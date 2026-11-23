<%@ Page Language="VB" %>
<html>
  <head runat="server">
    <title>GridView DetailsView Master-Details (2 Page)</title>
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
        DataSourceID="SqlDataSource1" DataKeyNames="au_id"
        AutoGenerateColumns="False">
        <Columns>
          <asp:BoundField ReadOnly="true" HeaderText="ID" DataField="au_id" SortExpression="au_id" />
          <asp:BoundField HeaderText="Last Name" DataField="au_lname" SortExpression="au_lname" />
          <asp:BoundField HeaderText="First Name" DataField="au_fname" SortExpression="au_fname" />
          <asp:BoundField HeaderText="Phone" DataField="phone" SortExpression="phone" />
          <asp:BoundField HeaderText="Address" DataField="address" SortExpression="address" />
          <asp:BoundField HeaderText="City" DataField="city" SortExpression="city" />
          <asp:BoundField HeaderText="State" DataField="state" SortExpression="state" />
          <asp:BoundField HeaderText="Zip Code" DataField="zip" SortExpression="zip" />
          <asp:CheckBoxField HeaderText="Contract" SortExpression="contract" DataField="contract" />
          <asp:HyperLinkField HeaderText="View Details..." Text="View Details..." DataNavigateUrlFields="au_id"
            DataNavigateUrlFormatString="DetailsView_vb.aspx?ID={0}" />          
        </Columns>
      </asp:GridView>
      <asp:SqlDataSource ID="SqlDataSource1" Runat="server" SelectCommand="SELECT [au_id], [au_lname], [au_fname], [phone], [address], [city], [state], [zip], [contract] FROM [authors] WHERE [state] = @state"
        ConnectionString="<%$ ConnectionStrings:Pubs %>">
        <SelectParameters>
          <asp:ControlParameter Name="state" ControlID="DropDownList1" />
        </SelectParameters>
      </asp:SqlDataSource>
    </form>
  </body>
</html>
