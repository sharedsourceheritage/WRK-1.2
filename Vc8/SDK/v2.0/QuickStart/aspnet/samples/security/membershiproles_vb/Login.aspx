<%@ Page Language="VB" %>

<script runat="server">

  Sub btnLogin_Click(ByVal sender As Object, ByVal e As System.EventArgs)
    Dim userName As String = txtUserId.Text
    Dim password As String = txtPassword.Text

    If (Membership.ValidateUser(userName, password)) Then
      If Not (Request.QueryString("ReturnUrl") Is Nothing) Then
        FormsAuthentication.RedirectFromLoginPage(userName, False)
      Else
        FormsAuthentication.SetAuthCookie(userName, False)
        Response.Redirect("~/secured/DisplayUserProperties.aspx")
      End If
    Else
      lblResults.Visible = True
      lblResults.Text = "Unsuccessful login.  Please re-enter your information and try again."

      If (Not Membership.GetUser(userName) Is Nothing)
          If(Membership.GetUser(userName).IsLockedOut = true)
               lblResults.Text = lblResults.Text & "  <b>Your account has been locked out.</b>"
          End If
      End If
    End If
  End Sub

  Sub Page_Load(ByVal sender as Object, ByVal e as System.EventArgs)
       Me.DataBind()
  End Sub
</script>

<html>
  <head id="Head1" runat="server">
      <title>Login Page</title>
  </head>
  <body>
      <form id="form1" runat="server">
        <table id="tblLogin" cellspacing="1" cellpadding="1" style="border-right: black thin solid; border-top: black thin solid; border-left: black thin solid; border-bottom: black thin solid;">
          <tr>
              <td colspan="2" >
                  <div style="text-align: center">
                      <strong><span style="text-decoration: underline">Login Form</span></strong>
                  </div>
              </td>
          </tr>
          <tr>
              <td width="40%">Enter User Name/ID:</td>
              <td>
                  <asp:textbox id="txtUserId" runat="server" width="100%"></asp:textbox>
              </td>
          </tr>
          <tr>
              <td>Enter Password:</td>
              <td>
                  <asp:textbox id="txtPassword" runat="server" textmode="Password" width="100%"></asp:textbox>
              </td>
          </tr>                    
          <tr>
              <td style="TEXT-ALIGN: center" colspan="2">
                  <asp:button id="btnLogin" runat="server" text="Click to Login" OnClick="btnLogin_Click" />
              </td>
          </tr>
          <tr>
            <td colspan="2">
              <asp:Label ID="lblNumberOfAttempts" runat="server" Text=<%# "The application locks a user out after <B>" & Membership.Provider.MaxInvalidPasswordAttempts & " </B>failed login attempts."  %> />
             </td> 
          </tr>
        </table>
        <br />
        <a href=CreatingUsers.aspx>Click Here to Create New User</a>
        <br />
        <br />
        <asp:label id="lblResults" runat="server" BackColor=Red Visible=false>Results:</asp:label>&nbsp;<br />
      </form>
  </body>
</html>
