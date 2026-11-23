<%@ Page Language="C#" %>

<script runat="server">

  protected MembershipUser memUser;
  
  void Page_Load(object sender, EventArgs e)
  {
    memUser = Membership.GetUser();
  }


  void linkLogout_Click(object sender, EventArgs e)
  {
    FormsAuthentication.SignOut();
    Roles.DeleteCookie();
    FormsAuthentication.RedirectToLoginPage();
  }
</script>

<html>
  <head id="Head1" runat="server">
      <title>Display User Properties</title>
  </head>
  <body>
      <form id="form1" runat="server">
        <table id="tblLogin" cellpadding=0 cellspacing=0 >
          <tr>
              <td colspan="2" style="border-top: black thin solid;border-right: black thin solid;border-left: black thin solid">
                  <div style="text-align: center">
                      <strong><span style="text-decoration: underline">User Properties</span></strong>
                  </div>
              </td>
          </tr>
          <tr>
              <td width="40%" class="lcol">User Name/ID:</td>
              <td class=rcol>
                <% = Server.HtmlEncode(memUser.UserName) %>
              </td>
          </tr>
          <tr>
              <td class="lcol">
                  Email:</td>
              <td class="rcol">
                <% = Server.HtmlEncode(memUser.Email) %>
              </td>
          </tr>
          <tr>
              <td class="lcol">
                  Comment:</td>
              <td class="rcol">
                <% = memUser.Comment == null ? "No comment was provided." : Server.HtmlEncode(memUser.Comment) %>
              </td>
          </tr>          
          <tr>
              <td class="lcol">
                  User approved?</td>
              <td class="rcol">
                <% = memUser.IsApproved == true ? "Approved" : "Not Approved" %>
              </td>
          </tr>
          <tr>
              <td class="lcol">
                  Password Question:</td>
              <td class="rcol">
                <% = Server.HtmlEncode(memUser.PasswordQuestion) %>
              </td>
          </tr> 
          <tr>
              <td class="lcol">
                  Is this user online?</td>
              <td class="rcol">
                <% = memUser.IsOnline == true ? "Online" : "Not online" %>
              </td>
          </tr>
          <tr>
              <td class="lcol">
                  User account created on (local server time):</td>
              <td class="rcol">
                <% = memUser.CreationDate.ToString("F") %>
              </td>
          </tr>
          <tr>
              <td class="lcol">
                  User last logged in at (local server time):</td>
              <td class="rcol">
                <% = memUser.LastLoginDate.ToString("F") %>
              </td>
          </tr>
          <tr>
              <td class="lcol">
                  User was last active on the system at (local server time):</td>
              <td class="rcol">
                <% = memUser.LastActivityDate.ToString("F") %>
              </td>
          </tr>
          <tr>
              <td  class="lcol" style="border-bottom: black thin solid">
                  Password last changed at (local server time):</td>
              <td  class="rcol" style="border-bottom: black thin solid">
                <% = memUser.LastPasswordChangedDate.ToString("F") %>
              </td>
          </tr>
        </table>
        <hr />
        <br />
        <div align=center>
          <asp:LinkButton ID="linkLogout" Runat="server" OnClick="linkLogout_Click">Click here to logout</asp:LinkButton>
        </div>
      </form>
  </body>
</html>
