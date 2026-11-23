<%@ Page Language="VB" %>

<script runat="server">
  Sub btnDeleteCurrentUser_Click(ByVal sender As Object, ByVal e As System.EventArgs)
    If (Membership.DeleteUser(User.Identity.Name)) Then
      FormsAuthentication.SignOut()
      Roles.DeleteCookie()
      Response.Redirect("~/CreatingUsers.aspx")
    Else
      lblResult.Visible = True
      lblResult.Text = "The Membership user was not deleted."
    End If
  End Sub
</script>

<html >
  <head id="Head1" runat="server">
      <title>Delete the Logged In User</title>
  </head>
  <body>
      <form id="form1" runat="server">
      <div>
        <br />
        <asp:Button ID="btnDeleteCurrentUser" Runat="server" Text="Click to delete the logged in user." OnClick="btnDeleteCurrentUser_Click" />
        <br />
        <asp:Label id="lblResult" Runat=Server Visible=false BackColor=Red />
        <br />
        <br />
        Clicking the button above will delete the logged in user.
        <br />
        The page will then log you out and return you to the page where you can create a new user.
      </div>
      </form>
  </body>
</html>
