<%@ Page Language="C#" %>

<script runat="server">

  void btnLogin_Click(object sender, EventArgs e)
  { 
    string userName = Server.HtmlEncode(txtUserId.Text);
    string password = Server.HtmlEncode(txtPassword.Text);

    if (FormsAuthentication.Authenticate(userName, password))
    {
        FormsAuthentication.RedirectFromLoginPage(userName, false);
    }
    else
    {
      lblResults.Visible = true;
      lblResults.Text = "Unsuccessful login.  Please re-enter your information and try again.";
    }
  }
</script>

<html>
  <head runat="server">
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
              <td width="40%">Enter User Name:</td>
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
        </table>
        <br />
        <br /> 
        Enter a username of "SectionOne", "SectionTwo", or "AllSections".  The password is the same as the username. 
        <br />
        <br />
        <asp:label id="lblResults" runat="server" BackColor=Red Visible=false>Results:</asp:label>&nbsp;<br />
      </form>
  </body>
</html>
