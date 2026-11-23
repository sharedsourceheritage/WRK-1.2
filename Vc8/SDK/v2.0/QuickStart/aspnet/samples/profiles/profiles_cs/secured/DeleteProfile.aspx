<%@ Page Language="C#" %>

<script runat="server">

  void btnDeleteProfile_Click(object sender, EventArgs e)
  {
    ProfileManager.DeleteProfile(User.Identity.Name);

    Response.Redirect("ProfileProperties.aspx");
  }
</script>

<html>
  <head runat="server">
      <title>Delete Profile for Current User</title>
  </head>
  <body>
      <form id="form1" runat="server">
      <div>
        <br />
        <br />
        <asp:Button ID="btnDeleteProfile" Runat="server" Text="Click to delete Profile for the current user" OnClick="btnDeleteProfile_Click" />
      </div>
      </form>
  </body>
</html>
