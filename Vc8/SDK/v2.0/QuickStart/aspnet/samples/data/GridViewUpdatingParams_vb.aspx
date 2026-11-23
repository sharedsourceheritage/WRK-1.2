<%@ Page Language="VB" %>
<html>
  <head runat="server">
    <title>Updating Data Using GridView</title>
  </head>
  <body>
    <form id="form1" runat="server">
      <asp:GridView ID="GridView1" AllowSorting="true" AllowPaging="true" Runat="server"
        DataSourceID="SqlDataSource1" AutoGenerateEditButton="true" DataKeyNames="au_id"
        AutoGenerateColumns="False">
        <Columns>
          <asp:BoundField ReadOnly="true" HeaderText="ID" DataField="au_id" SortExpression="au_id" />
          <asp:BoundField HeaderText="Last Name" DataField="au_lname" SortExpression="au_lname" />
          <asp:BoundField HeaderText="First Name" DataField="au_fname" SortExpression="au_fname" />
          <asp:BoundField HeaderText="Phone" DataField="phone" SortExpression="phone" />
          <asp:BoundField HeaderText="Address" DataField="address" SortExpression="address" NullDisplayText="(not listed)"/>
          <asp:BoundField HeaderText="City" DataField="city" SortExpression="city" />
          <asp:BoundField HeaderText="State" DataField="state" SortExpression="state" />
          <asp:BoundField HeaderText="Zip Code" DataField="zip" SortExpression="zip" />
          <asp:CheckBoxField HeaderText="Contract" SortExpression="contract" DataField="contract" />
        </Columns>
      </asp:GridView>
      <asp:SqlDataSource ID="SqlDataSource1" Runat="server" SelectCommand="SELECT [au_id], [au_lname], [au_fname], [phone], [address], [city], [state], [zip], [contract] FROM [authors]"
        UpdateCommand="UPDATE [authors] SET [au_lname] = @au_lname, [au_fname] = @au_fname, [phone] = @phone, [address] = @address, [city] = @city, [state] = @state, [zip] = @zip, [contract] = @contract WHERE [au_id] = @au_id"
        ConnectionString="<%$ ConnectionStrings:Pubs %>">
        <UpdateParameters>
          <asp:Parameter Name="au_lname" Type="String" Size="40"/>
          <asp:Parameter Name="au_fname" Type="String" Size="20"/>
          <asp:Parameter Name="phone" Type="String" Size="12"/>
          <asp:Parameter Name="address" Type="String" ConvertEmptyStringToNull="true" Size="40"/>
          <asp:Parameter Name="city" Type="String" Size="20"/>
          <asp:Parameter Name="state" Type="String" DefaultValue="CA" Size="2"/>
          <asp:Parameter Name="zip" Type="String" Size="5"/>
          <asp:Parameter Name="contract" Type="Boolean" Size="1"/>
          <asp:Parameter Name="au_id" Type="String" Size="40"/>
        </UpdateParameters>        
      </asp:SqlDataSource>
    </form>
  </body>
</html>
