<%@ Page Language="VB" StylesheetTheme="White"  %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Binding to a Visual Studio DataSet</title>
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
                    <asp:BoundField HeaderText="AlbumName" DataField="AlbumName" SortExpression="AlbumName" />
                    <asp:BoundField HeaderText="Owner" DataField="Owner" SortExpression="Owner" />
                    <asp:BoundField HeaderText="DateCreated" DataField="DateCreated" SortExpression="DateCreated" />
                    <asp:BoundField HeaderText="AlbumPath" DataField="AlbumPath" SortExpression="AlbumPath" />
                    <asp:CheckBoxField HeaderText="Visible" SortExpression="Visible" DataField="Visible" />
                    <asp:HyperLinkField HeaderText="View Photos..." Text="View Photos..." DataNavigateUrlFields="AlbumID,AlbumName"
                        DataNavigateUrlFormatString="PhotosDetailsView.aspx?ID={0}&amp;Name={1}" />
                </Columns>
            </asp:GridView>
            <br />
            <asp:ObjectDataSource ID="ObjectDataSource1" runat="server" TypeName="DataComponentTableAdapters.AlbumsTableAdapter"
                SelectMethod="GetAlbumsByOwner" UpdateMethod="Update" ConvertNullToDBNull="true" OldValuesParameterFormatString="original_{0}">
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
