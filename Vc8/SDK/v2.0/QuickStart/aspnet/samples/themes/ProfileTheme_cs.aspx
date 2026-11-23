<%@ Page Language="C#" Theme="Default" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<script runat="server">

  protected void Page_PreInit()
  {
    if (Profile.FavoriteColor != "")
      Page.Theme = Profile.FavoriteColor;
  }
  
</script>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
  <title>Assigning a Theme Based on User Profile</title>
</head>
<body>
  <form id="form1" runat="server">
    <div>
      <h2>
        Assigning a Theme Based on User Profile</h2>
      <asp:Label ID="Label1" runat="server" Text="Welcome to my page.  Please login with User=Test, Password=Test@1234"></asp:Label><br />
      <br />
      <asp:Login ID="Login1" runat="server" />
      <br />
      <asp:LoginView ID="LoginView1" runat="server">
        <LoggedInTemplate>
          <asp:HyperLink ID="HyperLink1" NavigateUrl="Profile_cs.aspx" Text="Edit Profile..."
            runat="server" />
          <br />
          <asp:LoginStatus ID="LoginStatus1" runat="server"/>
        </LoggedInTemplate>
      </asp:LoginView>
    </div>
  </form>
</body>
</html>
