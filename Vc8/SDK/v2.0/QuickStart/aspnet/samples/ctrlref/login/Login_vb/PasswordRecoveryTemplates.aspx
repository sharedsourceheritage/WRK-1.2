<%@ Page Language="VB" MasterPageFile="~/UserInfo.master"%>

<script Language="VB" runat="server">
  'This illustrates how to find a control in the Question template. 
  Sub GetQuestionandAnswer(ByVal sender As Object, ByVal e As System.Web.UI.WebControls.LoginCancelEventArgs)
    Label1.Text = "Your answer was: " & CType(PasswordRecovery1.QuestionTemplateContainer.FindControl("RequestDropDownList"), DropDownList).Text
  End Sub

  'Remove this code in production.
  'For sample purposes only we have canceled the email
  'that the PasswordRecovery control is attempting to send to the end user.

    Sub CancelEmail(ByVal sender As Object, ByVal e As MailMessageEventArgs)
        e.Cancel = True
    End Sub

</script>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
<h2>
    PasswordRecovery Template FindControl Sample</h2>
  Use the pre-created sample accounts listed below and select a request priority
  from the Question template.
  <br />
  <br />
  <asp:Label ID="Label1" runat="server" Font-Bold="True"></asp:Label><br />
  <br />
  <asp:PasswordRecovery ID="PasswordRecovery1" runat="server" OnVerifyingAnswer="GetQuestionandAnswer"
    OnSendingMail="CancelEmail" BorderColor="Black" BorderStyle="Solid" BorderWidth="1px">
    <UserNameTemplate>
      <table border="0" cellpadding="1">
        <tr>
          <td>
            <table border="0" cellpadding="0">
              <tr>
                <td align="center" colspan="2">
                  Forgot Your Password?</td>
              </tr>
              <tr>
                <td align="center" colspan="2">
                  Enter your User Name to receive your password.</td>
              </tr>
              <tr>
                <td align="right">
                  <asp:Label ID="UserNameLabel" runat="server" AssociatedControlID="UserName">User Name:</asp:Label></td>
                <td>
                  <asp:TextBox ID="UserName" runat="server"></asp:TextBox>
                  <asp:RequiredFieldValidator ID="UserNameRequired" runat="server" ControlToValidate="UserName"
                    ErrorMessage="User Name is required." ToolTip="User Name is required." ValidationGroup="PasswordRecovery1">*</asp:RequiredFieldValidator>
                </td>
              </tr>
              <tr>
                <td align="center" colspan="2" style="color: red">
                  <asp:Literal ID="FailureText" runat="server" EnableViewState="False"></asp:Literal>
                </td>
              </tr>
              <tr>
                <td align="right" colspan="2">
                  <asp:Button ID="SubmitButton" runat="server" CommandName="Submit" Text="Submit" ValidationGroup="PasswordRecovery1" />
                </td>
              </tr>
            </table>
          </td>
        </tr>
      </table>
    </UserNameTemplate>
    <QuestionTemplate>
      <table border="0" cellpadding="1">
        <tr>
          <td>
            <table border="0" cellpadding="0">
              <tr>
                <td align="center" colspan="2">
                  Identity Confirmation</td>
              </tr>
              <tr>
                <td align="center" colspan="2">
                  Answer the following question to receive your password.</td>
              </tr>
              <tr>
                <td align="right">
                  User Name:</td>
                <td>
                  <asp:Literal ID="UserName" runat="server"></asp:Literal>
                </td>
              </tr>
              <tr>
                <td align="right">
                  Question:</td>
                <td>
                  <asp:Literal ID="Question" runat="server"></asp:Literal>
                </td>
              </tr>
              <tr>
                <td align="right">
                  <asp:Label ID="AnswerLabel" runat="server" AssociatedControlID="Answer">Answer:</asp:Label></td>
                <td>
                  <asp:TextBox ID="Answer" runat="server"></asp:TextBox>
                  <asp:RequiredFieldValidator ID="AnswerRequired" runat="server" ControlToValidate="Answer"
                    ErrorMessage="Answer is required." ToolTip="Answer is required." ValidationGroup="PasswordRecovery1">*</asp:RequiredFieldValidator>
                </td>
              </tr>
              <tr>
                <td align="right">
                  <asp:Label ID="Request" runat="server" Text="Request Priority:"></asp:Label>
                </td>
                <td>
                  <asp:DropDownList ID="RequestDropDownList" runat="server">
                    <asp:ListItem>Low</asp:ListItem>
                    <asp:ListItem>Medium</asp:ListItem>
                    <asp:ListItem>High</asp:ListItem>
                  </asp:DropDownList></td>
              </tr>
              <tr>
                <td align="center" colspan="2" style="color: red">
                  <asp:Literal ID="FailureText" runat="server" EnableViewState="False"></asp:Literal>
                </td>
              </tr>
              <tr>
                <td align="right" colspan="2">
                  <asp:Button ID="SubmitButton" runat="server" CommandName="Submit" Text="Submit" ValidationGroup="PasswordRecovery1" />
                </td>
              </tr>
            </table>
          </td>
        </tr>
      </table>
    </QuestionTemplate>
    <SuccessTemplate>
      <table border="0" cellpadding="1">
        <tr>
          <td>
            <table border="0" cellpadding="0">
              <tr>
                <td>
                  Your password has been sent to you.</td>
              </tr>
            </table>
          </td>
        </tr>
      </table>
    </SuccessTemplate>
    <MailDefinition From="someone@example.com">
    </MailDefinition>
  </asp:PasswordRecovery>
  <br />
  <br />
  <b>Sample Notes:</b>
  <ul>
    <li>The PasswordRecovery email is being cancelled for demonostration purposes.</li><li>
      Close and reopen your browser or add a ? in the URL of your browser and press enter
      to start the sample over again.</li><li><b>SECURITY NOTE:</b> The most secure passwordFormat
        is hashed. The hashed option only supports enablePasswordReset. If you need to enablePasswordRetrieval
        the most secure format is encrypted. Encrypting your password requires a pre-defined
        machinekey. To enable these samples to run on all machines without machine key configuration
        and with a consistent password we are using the clear password format. In production
        you should change this setting in the Membership provider in web.config.</li></ul>
</asp:Content>