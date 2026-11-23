<%@ Page Language="C#" Debug="true" %>
<html>
  <head runat="server">
    <title>GridView Bound to Data Access Layer</title>
  </head>
  <body>
    <form id="form1" runat="server">
      <asp:DropDownList ID="DropDownList1" Runat="server" DataSourceID="ObjectDataSource2"
        AutoPostBack="True" DataTextField="state" DataValueField="state" />
      <asp:ObjectDataSource ID="ObjectDataSource2" Runat="server" TypeName="AuthorsDB"
        SelectMethod="GetStates"/>
      <br />
      <br />
      <asp:GridView ID="GridView1" Runat="server" DataSourceID="ObjectDataSource1" AutoGenerateColumns="False"
        AllowPaging="True" AllowSorting="True" DataKeyNames="au_id">
        <Columns>
          <asp:CommandField ShowEditButton="True" />
          <asp:BoundField HeaderText="ID" DataField="au_id" SortExpression="au_id" ReadOnly="true" />
          <asp:BoundField HeaderText="Name" DataField="au_fname" SortExpression="au_fname" />
          <asp:BoundField HeaderText="LastName" DataField="au_lname" SortExpression="au_lname" />
          <asp:BoundField HeaderText="State" DataField="state" SortExpression="state" />
        </Columns>
      </asp:GridView>
      <asp:ObjectDataSource ID="ObjectDataSource1" Runat="server" TypeName="AuthorsDB"
        SelectMethod="GetAuthorsByState" UpdateMethod="UpdateAuthor" OldValuesParameterFormatString="{0}">
        <SelectParameters>
          <asp:ControlParameter Name="state" PropertyName="SelectedValue" ControlID="DropDownList1"/>
        </SelectParameters>
      </asp:ObjectDataSource>
    </form>
  </body>
</html>
