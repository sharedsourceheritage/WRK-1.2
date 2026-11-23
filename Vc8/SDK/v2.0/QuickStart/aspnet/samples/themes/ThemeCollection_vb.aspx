<%@ Page Language="VB" Theme="MyTheme" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<script runat="server">

</script>
<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
  <title>Theming Collections</title>
</head>
<body>
  <form id="form1" runat="server">
    <div>
    <h3>Theming Collections</h3>
      <asp:RadioButtonList ID="RadioButtonList1" runat="server">
        <asp:ListItem Value="1">Option 1</asp:ListItem>
        <asp:ListItem Value="2">Option 2</asp:ListItem>
        <asp:ListItem Value="3">Option 3</asp:ListItem>
        <asp:ListItem Value="4">Option 4</asp:ListItem>
      </asp:RadioButtonList>
    </div>
  </form>
</body>
</html>
