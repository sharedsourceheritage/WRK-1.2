<html>
<head>

  <script language="VB" runat="server">

    Sub SubmitBtn_Click(ByVal sender As Object, ByVal e As EventArgs)
      If ListBox1.SelectedIndex > -1 Then
        Label1.Text = "You chose: " + ListBox1.SelectedItem.Text
      End If
    End Sub

  </script>

</head>
<body>
  <form id="Form1" runat="server">
    <h3>
      <font face="Verdana">ListBox Example</font></h3>
    <p>
      <asp:ListBox ID="ListBox1" Width="100px" runat="server">
        <asp:ListItem>Item 1</asp:ListItem>
        <asp:ListItem>Item 2</asp:ListItem>
        <asp:ListItem>Item 3</asp:ListItem>
        <asp:ListItem>Item 4</asp:ListItem>
        <asp:ListItem>Item 5</asp:ListItem>
        <asp:ListItem>Item 6</asp:ListItem>
      </asp:ListBox>
      <asp:Button Text="Submit" ID=submit1 OnClick="SubmitBtn_Click" runat="server" />
    <p>
      <asp:Label ID="Label1" Font-Names="Verdana" Font-Size="10pt" runat="server" />
  </form>
</body>
</html>
