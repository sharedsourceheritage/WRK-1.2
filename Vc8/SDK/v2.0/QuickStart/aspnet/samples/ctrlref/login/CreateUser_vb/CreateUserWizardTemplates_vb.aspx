<%@ Page Language="VB" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">
  'How to access controls inside an additional non-templated wizard step.
    Sub AddressWrite(ByVal sender As Object, ByVal e As WizardNavigationEventArgs)
    
        Label3.Text = "Your Address Information is:"
    Label1.Text = Server.HtmlEncode(TextBox1.Text)
    Label2.Text = Server.HtmlEncode(TextBox2.Text)
    End Sub
  
  'How to access controls inside templated CreateUser wizard step.   
    Sub PhoneWrite(ByVal sender As Object, ByVal e As EventArgs)
        Label4.Text = "Your Phone number is:"
        Dim myStep As New CreateUserWizardStep
    Dim myText As TextBox = CreateUserWizardStep1.ContentTemplateContainer.FindControl("TextBoxPhone")
        CreateUserWizardStep1.ContentTemplateContainer.FindControl("TextBoxPhone")
    Label5.Text = Server.HtmlEncode(myText.Text)
    End Sub
</script>

<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
  <title>CreateUserWizard Templated Sample</title>
</head>
<body>
  <form id="form1" runat="server">
    <div>
      <h2>
        CreateUserWizard Templated Sample</h2>
      This sample demonstrates how to access controls inside the templated CreateUser
      Step as well as controls inside additional Wizard steps. No graphical elements have
      been added to the template in an attempt to simplify the sample. This sample contains
      the well known control IDs and command names required for a templated CreateUser Step.
      <br />
      <br />
      <b>Note: </b>Users created on this page are valid for ChangePassword control samples.
      <asp:HyperLink ID="HyperLink1" NavigateUrl="~/CreateUserWizardBasic_vb.aspx" runat="server">Create a user</asp:HyperLink><br />
      <hr />
      <br />
      <asp:CreateUserWizard ID="CreateUserWizard1" runat="server" HelpPageText="Help" HelpPageUrl="~/Help.htm"
        EditProfileText="Edit Your Profile" EditProfileUrl="~/Profile.htm" OnFinishButtonClick="AddressWrite"
        OnCreatedUser="PhoneWrite" ContinueDestinationPageUrl="~/Home.htm">
        <WizardSteps>
          <asp:CreateUserWizardStep ID="CreateUserWizardStep1" runat="server">
            <ContentTemplate>
              <table border="0">
                <tr>
                  <td align="center" colspan="2">
                    Sign Up for Your New Account</td>
                </tr>
                <tr>
                  <td align="right">
                    <label for="UserName">
                      User Name:</label></td>
                  <td>
                    <asp:TextBox ID="UserName" runat="server"></asp:TextBox>
                    <asp:RequiredFieldValidator ControlToValidate="UserName" ErrorMessage="User Name is required."
                      ID="UserNameRequired" runat="server" ToolTip="User Name is required." ValidationGroup="CreateUserWizard1">*</asp:RequiredFieldValidator>
                  </td>
                </tr>
                <tr>
                  <td align="right">
                    <label for="Password">
                      Password:</label></td>
                  <td>
                    <asp:TextBox ID="Password" runat="server" TextMode="Password"></asp:TextBox>
                    <asp:RequiredFieldValidator ControlToValidate="Password" ErrorMessage="Password is required."
                      ID="PasswordRequired" runat="server" ToolTip="Password is required." ValidationGroup="CreateUserWizard1">*</asp:RequiredFieldValidator>
                  </td>
                </tr>
                <tr>
                  <td align="right">
                    <label for="ConfirmPassword">
                      Confirm Password:</label></td>
                  <td>
                    <asp:TextBox ID="ConfirmPassword" runat="server" TextMode="Password"></asp:TextBox>
                    <asp:RequiredFieldValidator ControlToValidate="ConfirmPassword" ErrorMessage="Confirm Password is required."
                      ID="ConfirmPasswordRequired" runat="server" ToolTip="Confirm Password is required."
                      ValidationGroup="CreateUserWizard1">*</asp:RequiredFieldValidator>
                  </td>
                </tr>
                <tr>
                  <td align="right">
                    <label for="Email">
                      E-mail:</label></td>
                  <td>
                    <asp:TextBox ID="Email" runat="server"></asp:TextBox>
                    <asp:RequiredFieldValidator ControlToValidate="Email" ErrorMessage="E-mail is required."
                      ID="EmailRequired" runat="server" ToolTip="E-mail is required." ValidationGroup="CreateUserWizard1">*</asp:RequiredFieldValidator>
                  </td>
                </tr>
                <tr>
                  <td align="right">
                    <label for="Question">
                      Security Question:</label></td>
                  <td>
                    <asp:TextBox ID="Question" runat="server"></asp:TextBox>
                    <asp:RequiredFieldValidator ControlToValidate="Question" ErrorMessage="Security question is required."
                      ID="QuestionRequired" runat="server" ToolTip="Security question is required." ValidationGroup="CreateUserWizard1">*</asp:RequiredFieldValidator>
                  </td>
                </tr>
                <tr>
                  <td align="right">
                    <label for="Answer">
                      Security Answer:</label></td>
                  <td>
                    <asp:TextBox ID="Answer" runat="server"></asp:TextBox>
                    <asp:RequiredFieldValidator ControlToValidate="Answer" ErrorMessage="Security answer is required."
                      ID="AnswerRequired" runat="server" ToolTip="Security answer is required." ValidationGroup="CreateUserWizard1">*</asp:RequiredFieldValidator>
                  </td>
                </tr>
                <tr>
                  <td align="right">
                    <label id="LabelPhone" runat="server" for="Phone">
                      Phone:</label></td>
                  <td>
                    <asp:TextBox ID="TextBoxPhone" runat="server"></asp:TextBox>
                    <asp:RequiredFieldValidator ControlToValidate="TextBoxPhone" ErrorMessage="Phone number is required"
                      ID="RequiredFieldValidator1" runat="server" ToolTip="Phone number is required."
                      ValidationGroup="CreateUserWizard1">*</asp:RequiredFieldValidator>
                  </td>
                </tr>
                <tr>
                  <td align="center" colspan="2">
                    <asp:CompareValidator ControlToCompare="Password" ControlToValidate="ConfirmPassword"
                      Display="Dynamic" ErrorMessage="The Password and Confirmation Password must match."
                      ID="PasswordCompare" runat="server" ValidationGroup="CreateUserWizard1"></asp:CompareValidator>
                  </td>
                </tr>
                <tr>
                  <td align="center" colspan="2" style="color: red">
                    <asp:Literal EnableViewState="False" ID="ErrorMessage" runat="server"></asp:Literal>
                  </td>
                </tr>
                <tr>
                  <td colspan="2">
                    <asp:HyperLink ID="HelpLink" NavigateUrl="~/Help.htm" runat="server">Help</asp:HyperLink>
                  </td>
                </tr>
                <tr>
                  <td colspan="2">
                  </td>
                </tr>
                <tr>
                  <td colspan="2">
                  </td>
                </tr>
              </table>
            </ContentTemplate>
          </asp:CreateUserWizardStep>
          <asp:WizardStep ID="Address" runat="server" Title="Address">
            Address1<asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
            <br />
            Address2<asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
          </asp:WizardStep>
          <asp:CompleteWizardStep ID="CompleteWizardStep1" runat="server">
            <ContentTemplate>
              <table border="0">
                <tr>
                  <td align="center" colspan="2">
                    Complete</td>
                </tr>
                <tr>
                  <td>
                    Your account has been successfully created.</td>
                </tr>
                <tr>
                  <td align="right" colspan="2">
                    <asp:Button CausesValidation="False" CommandName="Continue" ID="ContinueButton" runat="server"
                      Text="Continue" ValidationGroup="CreateUserWizard1" />
                  </td>
                </tr>
                <tr>
                  <td colspan="2">
                    <asp:HyperLink ID="EditProfileLink" NavigateUrl="~/Profile.htm" runat="server">Edit Your Profile</asp:HyperLink>
                  </td>
                </tr>
              </table>
            </ContentTemplate>
          </asp:CompleteWizardStep>
        </WizardSteps>
      </asp:CreateUserWizard>
      <br />
      <asp:LoginName FormatString="Welcome {0}!" ID="LoginName1" runat="server" />
      <asp:LoginStatus ID="LoginStatus1" runat="server" />
      &nbsp;&nbsp;<br />
      <br />
      <asp:Label ID="Label4" runat="server"></asp:Label><br />
      <br />
      <asp:Label ID="Label5" runat="server"></asp:Label><br />
      <br />
      <br />
      <asp:Label ID="Label3" runat="server"></asp:Label>
      <br />
      <br />
      <asp:Label ID="Label1" runat="server"></asp:Label><br />
      <br />
      <asp:Label ID="Label2" runat="server"></asp:Label>&nbsp;
      <br />
    </div>
  </form>
</body>
</html>
