<%@ Page Language="VB" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">

  Protected Sub Button1_Click(ByVal sender As Object, ByVal e As System.EventArgs)
    Response.Write("Server-side click event fired too")
  End Sub
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>Client Click Event</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
      <h3>Client Click Event</h3>
      <asp:Button ID="Button1" OnClientClick='javascript:alert("clicked!")' Text="Click Me!" runat="server" OnClick="Button1_Click"/></div>
    </form>
</body>
</html>
