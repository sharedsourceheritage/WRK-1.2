<%@ Page Language="VB" StylesheetTheme="White" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
  <title>Performing Validation in Templates</title>
</head>
<body>
  <form id="form1" runat="server">
    <div>
      <h1>
        My Photo Album Site</h1>
      <b>Select an owner:
        <asp:DropDownList ID="DropDownList1" runat="server" DataSourceID="ObjectDataSource2"
          DataTextField="Owner" DataValueField="Owner" AutoPostBack="True" /></b>
      <br />
      <br />
      <asp:GridView ID="GridView1" runat="server" DataSourceID="ObjectDataSource1" AutoGenerateColumns="False"
        AllowPaging="True" AllowSorting="True" DataKeyNames="AlbumID">
        <Columns>
          <asp:CommandField ShowEditButton="True" />
          <asp:BoundField ReadOnly="True" HeaderText="AlbumID" DataField="AlbumID" SortExpression="AlbumID" />
          <asp:TemplateField HeaderText="AlbumName" SortExpression="AlbumName">
            <ItemTemplate>
              <asp:Label ID="Label1" runat="server" Text='<%# Eval("AlbumName") %>'></asp:Label>
            </ItemTemplate>
            <EditItemTemplate>
              &nbsp;<asp:TextBox ID="TextBox1" runat="server" Text='<%# Bind("AlbumName") %>'></asp:TextBox>
              <asp:RequiredFieldValidator ControlToValidate="TextBox1" ErrorMessage="AlbumName cannot be empty"
                ID="RequiredFieldValidator1" Display="Dynamic" runat="server">*</asp:RequiredFieldValidator>
            </EditItemTemplate>
            <ItemStyle Wrap="False" />
          </asp:TemplateField>
          <asp:TemplateField HeaderText="Owner" SortExpression="Owner">
            <ItemTemplate>
              <asp:Label ID="Label2" runat="server" Text='<%# Eval("Owner") %>'></asp:Label>
            </ItemTemplate>
            <EditItemTemplate>
              <asp:DropDownList DataSourceID="ObjectDataSource2" DataTextField="Owner" DataValueField="Owner"
                ID="DropDownList2" runat="server" SelectedValue='<%# Bind("Owner") %>'>
              </asp:DropDownList>
            </EditItemTemplate>
            <ItemStyle Wrap="False" />
          </asp:TemplateField>
          <asp:TemplateField HeaderText="DateCreated" SortExpression="DateCreated">
            <ItemTemplate>
              <asp:Label ID="Label3" runat="server" Text='<%# Eval("DateCreated", "{0:d}") %>'></asp:Label>
            </ItemTemplate>
            <EditItemTemplate>
              <asp:TextBox ID="TextBox3" runat="server" Text='<%# Bind("DateCreated", "{0:d}") %>'></asp:TextBox>
              <asp:RequiredFieldValidator ControlToValidate="TextBox3" ErrorMessage="DateCreated cannot be empty"
                ID="RequiredFieldValidator3" Display="Dynamic" runat="server">*</asp:RequiredFieldValidator>
              <asp:CompareValidator ErrorMessage="DateCreated must be a valid DateTime" ID="CompareValidator1"
                ControlToValidate="TextBox3" Operator="DataTypeCheck" Type="Date" Display="Dynamic"
                runat="server">*</asp:CompareValidator>
            </EditItemTemplate>
            <ItemStyle Wrap="False" />
          </asp:TemplateField>
          <asp:TemplateField HeaderText="AlbumPath" SortExpression="AlbumPath">
            <ItemTemplate>
              <asp:Label ID="Label4" runat="server" Text='<%# Eval("AlbumPath") %>'></asp:Label>
            </ItemTemplate>
            <EditItemTemplate>
              <asp:TextBox ID="TextBox4" runat="server" Text='<%# Bind("AlbumPath") %>'></asp:TextBox>
              <asp:RequiredFieldValidator ControlToValidate="TextBox4" ErrorMessage="AlbumPath cannot be empty"
                ID="RequiredFieldValidator4" Display="Dynamic" runat="server">*</asp:RequiredFieldValidator>
            </EditItemTemplate>
            <ItemStyle Wrap="False" />
          </asp:TemplateField>
          <asp:CheckBoxField HeaderText="Visible" SortExpression="Visible" DataField="Visible" />
          <asp:HyperLinkField HeaderText="View Photos..." Text="View Photos..." DataNavigateUrlFields="AlbumID,AlbumName"
            DataNavigateUrlFormatString="PhotosDataList.aspx?ID={0}&amp;Name={1}" />
        </Columns>
      </asp:GridView>
      <br />
      <br />
      <asp:ValidationSummary ID="ValidationSummary1" runat="server" />
      <asp:ObjectDataSource ID="ObjectDataSource1" runat="server" ConvertNullToDBNull="true"
        TypeName="DataComponentTableAdapters.AlbumsTableAdapter" SelectMethod="GetAlbumsByOwner"
        UpdateMethod="Update" OldValuesParameterFormatString="original_{0}">
        <SelectParameters>
          <asp:ControlParameter ControlID="DropDownList1" Name="Owner" PropertyName="SelectedValue"
            Type="String" />
        </SelectParameters>
        <UpdateParameters>
          <asp:Parameter Name="AlbumName" Type="String" />
          <asp:Parameter Name="Owner" Type="String" />
          <asp:Parameter Name="DateCreated" Type="DateTime" />
          <asp:Parameter Name="AlbumPath" Type="String" />
          <asp:Parameter Name="Visible" Type="Boolean" />
          <asp:Parameter Name="Original_AlbumID" Type="Int32" />
        </UpdateParameters>
      </asp:ObjectDataSource>
      <asp:ObjectDataSource ID="ObjectDataSource2" runat="server" TypeName="DataComponentTableAdapters.OwnersTableAdapter"
        SelectMethod="GetOwners" />
    </div>
  </form>
</body>
</html>
