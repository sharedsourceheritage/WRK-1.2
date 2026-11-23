<%@ page language="C#" %>

<script runat="server">

  void Button1_Click(object sender, EventArgs e)
  {
    Label1.Text = "Hello " + TextBox1.Text;
  }
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
