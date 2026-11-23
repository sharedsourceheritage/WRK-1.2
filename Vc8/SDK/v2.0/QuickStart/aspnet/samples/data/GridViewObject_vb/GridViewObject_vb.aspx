<%@ Page Language="VB" %>
<html>
  <head id="Head1" runat="server">
    <title>GridView Bound to Data Component</title>
  </head>
  <body>
    <form id="form1" runat="server">
      <asp:DropDownList ID="DropDownList1" Runat="server" DataSourceID="ObjectDataSource2"
        AutoPostBack="True" />
      <asp:ObjectDataSource ID="ObjectDataSource2" Runat="server" TypeName="AuthorsComponent"
        SelectMethod="GetStates"/>
      <br />
      <br />
      <asp:GridView ID="GridView1" Runat="server" DataSourceID="ObjectDataSource1" AutoGenerateColumns="False"
        AllowPaging="True" AllowSorting="True">
        <Columns>
          <asp:CommandField ShowEditButton="True" />
          <asp:BoundField HeaderText="ID" DataField="ID" SortExpression="ID" />
          <asp:BoundField HeaderText="Name" DataField="Name" SortExpression="Name" />
          <asp:BoundField HeaderText="LastName" DataField="LastName" SortExpression="LastName" />
          <asp:BoundField HeaderText="State" DataField="State" SortExpression="State" />
        </Columns>
      </asp:GridView>
      <asp:ObjectDataSource ID="ObjectDataSource1" Runat="server" TypeName="AuthorsComponent"
        SelectMethod="GetAuthorsByState" UpdateMethod="UpdateAuthor" DataObjectTypeName="Author" SortParameterName="sortExpression">
        <SelectParameters>
          <asp:ControlParameter Name="state" PropertyName="SelectedValue" ControlID="DropDownList1"></asp:ControlParameter>
        </SelectParameters>
      </asp:ObjectDataSource>
    </form>
  </body>
</html>
