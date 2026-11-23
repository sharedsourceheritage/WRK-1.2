<%@ Page Language="C#" %>

<html>
  <head runat="server">
    <title>
      Output Caching With Sql Cache Dependency
    </title>
  </head>
  <body>
    <form id="form1" runat="server">
        Notice that the time stamp does not change until you edit a record.
        <br/><br/>
        <asp:GridView ID="GridView1" AllowSorting="true" AllowPaging="true" Runat="server"
          DataSourceID="SqlDataSource1" AutoGenerateEditButton="true" DataKeyNames="au_id"
          AutoGenerateColumns="False">
          <Columns>
            <asp:BoundField ReadOnly="true" HeaderText="TimeStamp" DataField="TimeStamp" />
            <asp:BoundField ReadOnly="true" HeaderText="au_id" DataField="au_id" SortExpression="au_id" />
            <asp:BoundField HeaderText="au_lname" DataField="au_lname" SortExpression="au_lname" />
            <asp:BoundField HeaderText="au_fname" DataField="au_fname" SortExpression="au_fname" />
            <asp:BoundField HeaderText="phone" DataField="phone" SortExpression="phone" />
            <asp:BoundField HeaderText="address" DataField="address" SortExpression="address" />
            <asp:BoundField HeaderText="city" DataField="city" SortExpression="city" />
            <asp:BoundField HeaderText="state" DataField="state" SortExpression="state" />
            <asp:BoundField HeaderText="zip" DataField="zip" SortExpression="zip" />
            <asp:CheckBoxField HeaderText="contract" SortExpression="contract" DataField="contract" />
          </Columns>
        </asp:GridView>
        <asp:SqlDataSource ID="SqlDataSource1" Runat="server" EnableCaching="true" CacheDuration="Infinite" SqlcacheDependency="PubsDB:Authors"
          SelectCommand="SELECT DatePart(second, GetDate()) As TimeStamp, [au_id], [au_lname], [au_fname], [phone], [address], [city], [state], [zip], [contract] FROM [authors]"
          UpdateCommand="UPDATE [authors] SET [au_lname] = @au_lname, [au_fname] = @au_fname, [phone] = @phone, [address] = @address, [city] = @city, [state] = @state, [zip] = @zip, [contract] = @contract WHERE [au_id] = @au_id"
          ConnectionString="<%$ ConnectionStrings:Pubs %>" />
    </form>
  </body>
</html>