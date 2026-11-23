<%@ Page Language="C#" %>

<script runat="server">

  void btnDeleteCurrentUser_Click(object sender, EventArgs e)
  {
    if (Membership.DeleteUser(User.Identity.Name))
    {
      FormsAuthentication.SignOut();
      Roles.DeleteCookie();
      Response.Redirect("~/CreatingUsers.aspx");
    }
    else
    {
      lblResult.Visible = true;
      lblResult.Text = "The Membership user was not deleted.";
    }
  }
</script>

<html >
  <head runat="server">
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
