<%@ page language="C#" CodeFile="CodeBehind_cs.aspx.cs" Inherits="CodeBehind_cs_aspx" %>

<html>
<head>
    <title>ASP.NET CodeBehind Pages</title>
</head>
<body>
    <form runat="server">
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
