<%@ Page Language="C#" Theme="OrangeTheme" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<script runat="server">

</script>
<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
  <title>Disabling Themes for a Control</title>
</head>
<body>
  <form id="form1" runat="server">
    <div>
    <h3>Disabling Themes for a Control</h3>
      <asp:Label ID="Label1" runat="server" Text="Hello 1" /><br />
      <asp:Label ID="Label2" runat="server" Text="Hello 2" EnableTheming="False" /><br />
      <asp:Label ID="Label3" runat="server" Text="Hello 3" /><br />
    </div>
  </form>
</body>
</html>
