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
      <asp:DetailsView AutoGenerateRows="False" DataKeyNames="PhotoID" DataSourceID="ObjectDataSource1"
        HeaderText="Album Photos" Height="50px" ID="DetailsView1" runat="server" Width="125px">
        <Fields>
          <asp:BoundField DataField="Caption" HeaderText="Caption" ShowHeader="False" SortExpression="Caption" />
          <asp:ImageField DataImageUrlField="FileName" DataImageUrlFormatString="~/Images/{0}"
            NullDisplayText="No Image to Display" ReadOnly="True" ShowHeader="False">
          </asp:ImageField>
        </Fields>
      </asp:DetailsView>
      <br />
      <br />
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
