<%@ page language="VB" %>

<script runat="server">

  Sub Button1_Click(ByVal sender As Object, ByVal e As System.EventArgs)
    Dim c As New CustomClass
    Label1.Text = c.GetMessage(TextBox1.Text)

    Dim c2 As New CustomClass2
    Label2.Text = c2.GetMessage(TextBox1.Text)
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
      <asp:Label ID="Label1" Runat="server" />
      <br />
      <asp:Label ID="Label2" Runat="server" />
    </form>
</body>
</html>
