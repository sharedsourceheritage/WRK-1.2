<%@ Page Language="VB" %>

<script runat="server">
  Sub btnDeleteProfile_Click(ByVal sender As Object, ByVal e As System.EventArgs)
    ProfileManager.DeleteProfile(User.Identity.Name)

    Response.Redirect("ProfileProperties.aspx")
  End Sub
</script>

<html>
  <head id="Head1" runat="server">
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
