<%@ Page Language="VB" %>

<script runat="server">
  Protected memUser As MembershipUser
  
  Sub Page_Load(ByVal sender As Object, ByVal e As System.EventArgs)
    memUser = Membership.GetUser()
  End Sub
  
  
  Sub linkLogout_Click(ByVal sender As Object, ByVal e As System.EventArgs)
    FormsAuthentication.SignOut()
    Roles.DeleteCookie()
    FormsAuthentication.RedirectToLoginPage()
  End Sub
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
                <% = Server.HtmlEncode(memUser.Username) %>
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
                  User approved?</td>
              <td class="rcol">
                <% =IIf(memUser.IsApproved = True, "Approved", "Not Approved")%>
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
                <% =IIf(memUser.IsOnline = True, "Online", "Not online")%>
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

