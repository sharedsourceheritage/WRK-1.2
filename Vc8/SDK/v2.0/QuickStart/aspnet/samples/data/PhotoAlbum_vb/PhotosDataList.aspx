<%@ Page Language="VB" StylesheetTheme="White" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
  <title>View Photos</title>
</head>
<body>
  <form id="form1" runat="server">
    <div>
      <h1>
        Album: <%= Server.HtmlEncode(Request.QueryString("Name")) %></h1>
      <asp:DataList ID="DataList1" SkinID="PhotosList" runat="server" DataSourceID="ObjectDataSource1">
        <ItemTemplate>
          <br />
          <asp:HyperLink ID="HyperLink1" runat="server" NavigateUrl='<%# Eval("PhotoID", "PhotoFormViewEdit.aspx?ID={0}") %>'>
          <asp:Image ID="Image1" Runat="server" ImageUrl='<%# Eval("FileName", "images/thumbs/{0}") %>' /></asp:HyperLink>
          <br />
          <asp:Label ID="CaptionLabel" runat="server" Text='<%# Eval("Caption") %>' />
        </ItemTemplate>
      </asp:DataList><br />
      <asp:ObjectDataSource ID="ObjectDataSource1" runat="server" TypeName="DataComponentTableAdapters.PhotosTableAdapter"
        SelectMethod="GetPhotosForAlbum">
        <SelectParameters>
          <asp:QueryStringParameter Name="AlbumID" QueryStringField="ID" DefaultValue="1" />
        </SelectParameters>
      </asp:ObjectDataSource>
    </div>
  </form>
</body>
</html>
