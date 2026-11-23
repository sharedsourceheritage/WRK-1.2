<%@ Page Language="C#" Theme="OrangeTheme" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
  <title>Theme Overrides Page Properties</title>
</head>
<body>
  <form id="form1" runat="server">
    <div>
    <h3>Properties in the Page are Overridden By Theme</h3>
      <asp:Label ID="Label1" runat="server" Text="Hello 1" /><br />
      <asp:Label ID="Label2" runat="server" Text="Hello 2" ForeColor="blue" />
      &lt;-- Notice that this Label is orange (from Theme) instead of blue (from Page)
      <br />
      <asp:Label ID="Label3" runat="server" Text="Hello 3" /><br />
    </div>
  </form>
</body>
</html>
