<%@ Page Language="C#" StylesheetTheme="White" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
  <title>View Photo</title>
</head>
<body>
  <form id="form1" runat="server">
    <div>
      <asp:FormView ID="FormView1" runat="server" DataSourceID="ObjectDataSource1">
        <ItemTemplate>
          <asp:Label ID="CaptionLabel" runat="server" Text='<%# Eval("Caption") %>' Font-Size="32pt" /><br />
          <br />
          <asp:Image ID="Image1" runat="server" ImageUrl='<%# Eval("FileName", "images/{0}") %>' />
          <br />
          <br />
          <asp:HyperLink ID="HyperLink1" Text="Back to Album" NavigateUrl='<%# Eval("AlbumID", "PhotosDataList.aspx?ID={0}") %>'
            runat="server" />
        </ItemTemplate>
      </asp:FormView>
      <br />
      <br />
      <asp:ObjectDataSource ID="ObjectDataSource1" runat="server" TypeName="DataComponentTableAdapters.PhotosTableAdapter"
        SelectMethod="GetPhoto">
        <SelectParameters>
          <asp:QueryStringParameter Name="PhotoID" DefaultValue="9" QueryStringField="ID" />
        </SelectParameters>
      </asp:ObjectDataSource>
    </div>
  </form>
</body>
</html>
