<%@ Page Language="VB" %>

<script runat="server">

  Sub btnCreate_Click(ByVal sender As Object, ByVal e As System.EventArgs)
    Dim userName As String = txtUserId.Text

    'this value is either encrypted or hashed and is never displayed 
    Dim password As String = txtPassword.Text

    Dim email As String = txtEmail.Text
    Dim passwordQuestion As String = ddlPasswordQuestion.SelectedValue

    'this value is either encrypted or hashed and is never displayed
    Dim passwordAnswer As String = txtPasswordAnswer.Text

    Dim result As MembershipCreateStatus
    Membership.CreateUser(userName, password, email, passwordQuestion, passwordAnswer, True, result)

    lblResults.Visible = True
    
    Select Case result
      Case MembershipCreateStatus.Success
        txtUserId.Text = Nothing
        txtPassword.Text = Nothing
        txtEmail.Text = Nothing
        ddlPasswordQuestion.SelectedIndex = -1
        txtPasswordAnswer.Text = Nothing
        lblResults.Text = "User successfully created!"
      Case MembershipCreateStatus.InvalidUserName
        lblResults.Text = "The username format was invalid.  Please enter a different username."
      Case MembershipCreateStatus.InvalidPassword
        lblResults.Text = "The password was invalid:  A password cannot be an empty string and must also meet the pasword strength requirements of the configured provider.  Please enter a new password."
      Case MembershipCreateStatus.InvalidEmail
        lblResults.Text = "The email format was invalid.  Please enter a different username."
      Case MembershipCreateStatus.InvalidQuestion
        lblResults.Text = "The password question format was invalid.  Please enter a different question."
      Case MembershipCreateStatus.InvalidAnswer
        lblResults.Text = "The password answer format was invalid.  Please enter a different answer."
      Case MembershipCreateStatus.DuplicateUsername
        lblResults.Text = "The username is already in use.  Please enter a new username."
      Case MembershipCreateStatus.DuplicateEmail
        lblResults.Text = "The email address is already in use.  Please enter a different email address."
      Case Else
        lblResults.Text = "An error occurred while creating the user."
    End Select
  End Sub
  
</script>

<html>
  <head id="Head1" runat="server">
      <title>Creating Users</title>
  </head>
  <body>
      <form id="form1" runat="server">
        <table id="tblLogin" cellspacing="1" cellpadding="1" style="border-right: black thin solid; border-top: black thin solid; border-left: black thin solid; border-bottom: black thin solid; width: 422px; height: 189px;">
          <tr>
              <td colspan="2" >
                  <div style="text-align: center">
                      <strong><span style="text-decoration: underline">Create New User</span></strong>
                  </div>
              </td>
          </tr>
          <tr>
              <td width="40%">User ID:</td>
              <td>
                  <asp:textbox id="txtUserId" runat="server" width="100%">username</asp:textbox>
              </td>
          </tr>
          <tr>
              <td>Password:</td>
              <td>
                  <asp:textbox id="txtPassword" runat="server" textmode="Password" width="100%"></asp:textbox>
              </td>
          </tr>
          <tr>
              <td>
                  Email:</td>
              <td>
                  <asp:textbox id="txtEmail" runat="server" width="100%">myemail@foo.org</asp:textbox>
              </td>
          </tr>
          <tr>
              <td>
                  Password Question:</td>
              <td>
                <asp:DropDownList ID="ddlPasswordQuestion" Runat="server" Width="100%">
                  <asp:ListItem>What is your mother's maiden name?</asp:ListItem>
                  <asp:ListItem>Where were you born?</asp:ListItem>
                  <asp:ListItem>What kind of car do you drive?</asp:ListItem>
                </asp:DropDownList>
              </td>
          </tr>
          <tr>
              <td>
                  Password Answer:</td>
              <td>
                  <asp:textbox id="txtPasswordAnswer" runat="server" width="100%"></asp:textbox>
              </td>
          </tr>                    
          <tr>
              <td style="TEXT-ALIGN: center" colspan="2">
                  <asp:button id="btnCreate" runat="server" text="Click to Create User" OnClick="btnCreate_Click" />
              </td>
          </tr>
        </table>
        <br />
        <br />
        <asp:label id="lblResults" runat="server" Visible=false>Results:</asp:label>&nbsp;<br />
      </form>
  </body>
</html>
