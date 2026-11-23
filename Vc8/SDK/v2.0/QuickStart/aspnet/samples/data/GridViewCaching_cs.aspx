<%@ Page Language="C#" %>
<html>
  <head id="Head1" runat="server">
    <title>Caching Data</title>
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
          <asp:BoundField DataField="TimeStamp" HeaderText="TimeStamp" ReadOnly="True">
            <ItemStyle Font-Bold="True" />
          </asp:BoundField>
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
      <asp:SqlDataSource ID="SqlDataSource1" Runat="server" SelectCommand="SELECT DatePart(second, GetDate()) As TimeStamp, [au_id], [au_lname], [au_fname], [phone], [address], [city], [state], [zip], [contract] FROM [authors] WHERE [state] = @state"
        UpdateCommand="UPDATE [authors] SET [au_lname] = @au_lname, [au_fname] = @au_fname, [phone] = @phone, [address] = @address, [city] = @city, [state] = @state, [zip] = @zip, [contract] = @contract WHERE [au_id] = @au_id"
        ConnectionString="<%$ ConnectionStrings:Pubs %>" CacheDuration="5" EnableCaching="True">
        <SelectParameters>
          <asp:ControlParameter Name="state" ControlID="DropDownList1" />
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
