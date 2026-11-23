<%@ Page Language="C#" Theme="OrangeTheme2" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
  <title>Named Skins</title>
</head>
<body>
  <form id="form1" runat="server">
    <div>
    <h3>Named Skins</h3>
      <asp:Label ID="Label1" runat="server" Text="Hello 1" /><br />
      <asp:Label ID="Label2" runat="server" Text="Hello 2" SkinID="Blue" /><br />
      <asp:Label ID="Label3" runat="server" Text="Hello 3" /><br />
      <br />
      <asp:Calendar ID="Calendar1" runat="server"/>
      <br />
      <asp:Calendar ID="Calendar2" SkinID="Simple" runat="server"/>      
    </div>
  </form>
</body>
</html>
