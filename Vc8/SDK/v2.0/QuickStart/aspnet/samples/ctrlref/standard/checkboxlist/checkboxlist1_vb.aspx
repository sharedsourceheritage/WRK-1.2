<html>
<head>

  <script language="VB" runat="server">

    Sub Button1_Click(ByVal sender As Object, ByVal e As EventArgs)
            
      Dim s As String = "Selected items:<br>"
      Dim i As Int32

      For i = 0 To Check1.Items.Count - 1
        If Check1.Items(i).Selected Then
          ' List the selected items
          s = s & Check1.Items(i).Text
          s = s & "<br>"
        End If
      Next

      Label1.Text = s
    End Sub

    Sub chkLayout_CheckedChanged(ByVal sender As Object, ByVal e As EventArgs)
       
      If chkLayout.Checked = True Then
        Check1.RepeatLayout = RepeatLayout.Table
      Else
        Check1.RepeatLayout = RepeatLayout.Flow
      End If
    End Sub
       
    Sub chkDirection_CheckedChanged(ByVal sender As Object, ByVal e As EventArgs)
       
      If chkDirection.Checked = True Then
        Check1.RepeatDirection = RepeatDirection.Horizontal
      Else
        Check1.RepeatDirection = RepeatDirection.Vertical
      End If
    End Sub

  </script>

</head>
<body>
  <h3>
    <font face="Verdana">CheckBoxList Example</font></h3>
  <form runat="server">
    <asp:CheckBoxList ID="Check1" runat="server">
      <asp:ListItem>Item 1</asp:ListItem>
      <asp:ListItem>Item 2</asp:ListItem>
      <asp:ListItem>Item 3</asp:ListItem>
      <asp:ListItem>Item 4</asp:ListItem>
      <asp:ListItem>Item 5</asp:ListItem>
      <asp:ListItem>Item 6</asp:ListItem>
    </asp:CheckBoxList>
    <p>
      <asp:CheckBox ID="chkLayout" OnCheckedChanged="chkLayout_CheckedChanged" Text="Display Table Layout"
        Checked="true" AutoPostBack="true" runat="server" />
      <br>
      <asp:CheckBox ID="chkDirection" OnCheckedChanged="chkDirection_CheckedChanged" Text="Display Horizontally"
        AutoPostBack="true" runat="server" />
    <p>
      <asp:Button ID="Button1" Text="Submit" OnClick="Button1_Click" runat="server" />
    <p>
      <asp:Label ID="Label1" Font-Names="Verdana" Font-Size="8pt" runat="server" />
  </form>
</body>
</html>
