<%@ Page Language="VB" Theme="OrangeTheme" StyleSheetTheme="GreenTheme" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
  <title>Precedence: Theme Overrides Page Overrides StyleSheetTheme</title>
</head>
<body>
  <form id="form1" runat="server">
    <div>
    <h3>Precedence: Theme Overrides Page Overrides StyleSheetTheme</h3>
      <asp:Label ID="Label1" runat="server" Text="Hello 1" /><br />
      <asp:Label ID="Label2" runat="server" Text="Hello 2" ForeColor="blue" Font-Italic="false" />
      &lt;-- Page overrides Font-Italic property of StyleSheetTheme, but Theme ForeColor overrides everywhere
      <br />
      <asp:Label ID="Label3" runat="server" Text="Hello 3" /><br />
    </div>
  </form>
</body>
</html>
