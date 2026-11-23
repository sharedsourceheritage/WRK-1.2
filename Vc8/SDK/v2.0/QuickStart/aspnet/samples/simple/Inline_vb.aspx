<%@ page language="VB" %>

<script runat="server">

  Sub Button1_Click(ByVal sender As Object, ByVal e As System.EventArgs)
    Label1.Text = "Hello " & TextBox1.Text
  End Sub
</script>

<html>
<head>
    <title>ASP.NET Inline Pages</title>
</head>
<body>
    <form id="Form1" runat="server">
      <h1>Welcome to ASP.NET 2.0!</h1>
      <b>Enter Your Name:</b>
      <asp:TextBox ID="TextBox1" Runat="server"/>
      <asp:Button ID="Button1" Text="Click Me" OnClick="Button1_Click" Runat="server"/>
      <br />
      <br />
      <asp:Label ID="Label1" Text="Hello" Runat="server" />
    </form>
</body>
</html>
