<%@ page language="C#" %>

<script runat="server">

  void Button1_Click(object sender, EventArgs e)
  {
    CustomClass c = new CustomClass();
    Label1.Text = c.GetMessage(TextBox1.Text);

    CustomClass2 c2 = new CustomClass2();
    Label2.Text = c2.GetMessage(TextBox1.Text);
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
      <asp:Label ID="Label1" Runat="server" />
      <br />
      <asp:Label ID="Label2" Runat="server" />
    </form>
</body>
</html>
