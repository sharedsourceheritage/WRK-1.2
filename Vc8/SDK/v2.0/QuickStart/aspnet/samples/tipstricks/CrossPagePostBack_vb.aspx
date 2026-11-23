<%@ Page Language="VB" Title="MaintainScrollPositionOnPostBack=true"  %>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>Cross Page PostBack</title>
</head>

<script language="VB" runat=server>
    Sub Button1_Click(ByVal sender As Object, ByVal e As System.EventArgs)
        Label1.Text = "Hello " & TextBox1.Text & ", you selected " & Calendar1.SelectedDate
    End Sub
</script>

<body>
  <form id="form1" runat="server">
    <div>
      <h3>Cross Page PostBack</h3>
      Enter Search Term:
      <asp:TextBox ID="SearchTerm" runat="server" />
      <asp:Button ID="Button2" runat="server" Text="Search" PostBackUrl="Search_vb.aspx" /> 
      <br /><br />
      <hr />
      <br />
      <h3>PostBack to Same Page</h3>
      <table cellpadding="5">
        <tr>
          <td valign="top">
            Enter name:</td>
          <td valign="top">
            <asp:TextBox ID="TextBox1" runat="server" Width="247px" Height="22px" />
          </td>
        </tr>
        <tr>
          <td valign="top">
            Enter meeting time:
          </td>
          <td valign="top">
            <asp:Calendar ID="Calendar1" runat="server" />
            <br />
            <asp:Button ID="Button1" runat="server" Text="Postback to Same Page" OnClick="Button1_Click" />
            <br />
          </td>
        </tr>
      </table>
      <br />
      <asp:Label ID="Label1" runat="server" Text="Label" Font-Bold="true" />
  </form>
</body>
</html>

