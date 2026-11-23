<%@ Page Language="VB" Theme="MyTheme" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
  <title>Images in a Theme</title>
</head>
<body>
  <form id="form1" runat="server">
    <div>
      <h2>
        Images in a Theme</h2>
      <asp:Image ID="Image1" SkinID="Warning" runat="server" />
      <asp:Label ID="Label1" runat="server" Text="Hello 1" /><br />
      <asp:Image ID="Image2" SkinID="Warning" runat="server" />
      <asp:Label ID="Label2" runat="server" Text="Hello 2" /><br />
      <asp:Image ID="Image3" SkinID="Warning" runat="server" />
      <asp:Label ID="Label3" runat="server" Text="Hello 3" /><br />
    </div>
  </form>
</body>
</html>
