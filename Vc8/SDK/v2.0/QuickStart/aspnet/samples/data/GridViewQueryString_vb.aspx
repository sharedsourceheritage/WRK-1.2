<%@ Page Language="VB" %>
<html>
  <head runat="server">
    <title>Filtering Data In A GridView Using a QueryString</title>
  </head>
  <body>
    <form id="form1" runat="server">
      <h4>Enter a query string on the URL, for example: GridViewQueryString_vb.aspx?state=IN</h4>
      <asp:GridView ID="GridView1" AllowSorting="True" AllowPaging="True" Runat="server"
        DataSourceID="SqlDataSource1" AutoGenerateEditButton="True" DataKeyNames="au_id"
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
        </Columns>
      </asp:GridView>
      <asp:SqlDataSource ID="SqlDataSource1" Runat="server" SelectCommand="SELECT [au_id], [au_lname], [au_fname], [phone], [address], [city], [state], [zip], [contract] FROM [authors] WHERE [state] = @state"
        UpdateCommand="UPDATE [authors] SET [au_lname] = @au_lname, [au_fname] = @au_fname, [phone] = @phone, [address] = @address, [city] = @city, [state] = @state, [zip] = @zip, [contract] = @contract WHERE [au_id] = @au_id"
        ConnectionString="<%$ ConnectionStrings:Pubs %>">
        <SelectParameters>
          <asp:QueryStringParameter Name="state" QueryStringField="state" DefaultValue="CA" />
        </SelectParameters>
        <UpdateParameters>
          <asp:Parameter Name="au_lname" />
          <asp:Parameter Name="au_fname" />
          <asp:Parameter Name="phone" />
          <asp:Parameter Name="address" />
          <asp:Parameter Name="city" />
          <asp:Parameter Name="state" />
          <asp:Parameter Name="zip" />
          <asp:Parameter Name="contract" />
          <asp:Parameter Name="au_id" />
        </UpdateParameters>
      </asp:SqlDataSource>
    </form>
  </body>
</html>
