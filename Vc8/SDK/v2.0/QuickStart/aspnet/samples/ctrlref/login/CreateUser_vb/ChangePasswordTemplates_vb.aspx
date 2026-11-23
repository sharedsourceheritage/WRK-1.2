<%@ Page Language="VB" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">
  ' This code demonstrates how to find a control inside of teh ChangePassword template.
  Sub AccountType(ByVal sender As Object, ByVal e As EventArgs)
    Dim dropDown As DropDownList = ChangePassword1.ChangePasswordTemplateContainer.FindControl("MyAccountDropDown")
    Label1.Text = "Your account type is " & dropDown.SelectedItem.Text
  End Sub
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head id="Head1" runat="server">
    <title>ChangePassword Template Sample</title>
</head>
<body >
    <form id="form1" runat="server">
    <div>
    <h2>
        ChangePassword Template Sample</h2>
      This sample demonstrates the correct control IDs
      and command names for key features of the ChangePassword control
      as well as how to programmatically find a control inside a template.
      Be sure to choose an account type when you are changing your password.
      <br />
      <br />
      <b>Note: </b>You must first create a user for this application.
      <asp:HyperLink ID="HyperLink2" NavigateUrl="~/CreateUserWizardBasic_vb.aspx" 
        runat="server">Create a user</asp:HyperLink><br />
      <hr />
      <br />
        <asp:LoginName ID="LoginName1" runat="server" />
        <asp:LoginStatus ID="LoginStatus1" runat="server" />
      <br />
      <br />
    
        <asp:Label ID="Label1" runat="server"></asp:Label>
        <br />
        <br />
        <asp:ChangePassword ID="ChangePassword1" runat="server" 
            DisplayUserName="True" EditProfileText="Edit Profile" 
            EditProfileUrl="~/Profile.htm" HelpPageText="Need Help?" 
            HelpPageUrl="~/Help.htm" 
            InstructionText="Enter your username and old password." 
            OnChangedPassword=AccountType BackColor="#E3EAEB" 
            BorderColor="#E6E2D8" BorderPadding="4" BorderStyle="Solid" 
            BorderWidth="1px" Font-Names="Verdana">
            <CancelButtonStyle BackColor="White" BorderColor="#C5BBAF" 
              BorderStyle="Solid" BorderWidth="1px" Font-Names="Verdana" 
              ForeColor="#1C5E55" />
            <ChangePasswordButtonStyle BackColor="White" BorderColor="#C5BBAF" 
              BorderStyle="Solid" BorderWidth="1px" Font-Names="Verdana" 
              ForeColor="#1C5E55" />
            <ContinueButtonStyle BackColor="White" BorderColor="#C5BBAF" 
              BorderStyle="Solid" BorderWidth="1px" Font-Names="Verdana" 
              ForeColor="#1C5E55" />
            <TitleTextStyle BackColor="#1C5E55" Font-Bold="True" 
              ForeColor="White" />
            <SuccessTemplate>
                <table border="0" cellpadding="4">
                    <tr>
                        <td>
                            <table border="0" cellpadding="0" 
                                style="font-family: Verdana;">
                                <tr>
                                    <td align="center" colspan="2" 
                                        style="color: White; 
                                        background-color: #1C5E55; 
                                        font-weight: bold;">
                                        Change Password Complete</td>
                                </tr>
                                <tr>
                                    <td>
                                        Your password has been changed!</td>
                                </tr>
                                <tr>
                                    <td align="right" colspan="2">
                                        <asp:Button BackColor="White" 
                                            BorderColor="#C5BBAF" 
                                            BorderStyle="Solid" 
                                            BorderWidth="1px"
                                            CausesValidation="False" 
                                            CommandName="Continue" 
                                            Font-Names="Verdana" 
                                            ForeColor="#1C5E55" 
                                            ID="ContinuePushButton" 
                                            runat="server" Text="Continue" />
                                    </td>
                                </tr>
                                <tr>
                                    <td colspan="2">
                                        <asp:HyperLink 
                                          ID="EditProfileLinkSuccess" 
                                          NavigateUrl="~/Profile.htm" 
                                          runat="server">Edit Profile</asp:HyperLink>
                                    </td>
                                </tr>
                            </table>
                        </td>
                    </tr>
                </table>
            </SuccessTemplate>
            <ChangePasswordTemplate>
                <table border="0" cellpadding="4">
                    <tr>
                        <td>
                            <table border="0" cellpadding="0" 
                                style="font-family: Verdana;">
                                <tr>
                                    <td align="center" colspan="2" 
                                      style="color: White; 
                                      background-color: #1C5E55;                                        
                                      font-weight: bold;">
                                        Change Your Password</td>
                                </tr>
                                <tr>
                                    <td align="center" colspan="2" 
                                      style="color: Black; 
                                      font-style: italic;">
                                        Enter your username and old password.
                                      </td>
                                </tr>
                                <tr>
                                    <td align="right">
                                        <asp:Label 
                                          AssociatedControlID="UserName" 
                                          ID="UserNameLabel" runat="server">
                                          User Name:</asp:Label>
                                     </td>
                                    <td>
                                        <asp:TextBox ID="UserName" 
                                          runat="server"></asp:TextBox>
                                        <asp:RequiredFieldValidator 
                                            ControlToValidate="UserName" 
                                            ErrorMessage="User Name is required."
                                            ID="UserNameRequired" 
                                            runat="server" 
                                            ToolTip="User Name is required." 
                                            ValidationGroup="ChangePassword1">*</asp:RequiredFieldValidator>
                                    </td>
                                </tr>
                                <tr>
                                    <td align="right">
                                        <asp:Label 
                                          AssociatedControlID="CurrentPassword"
                                          ID="CurrentPasswordLabel" 
                                          runat="server">Password:</asp:Label>
                                          </td>
                                    <td>
                                        <asp:TextBox ID="CurrentPassword" 
                                          runat="server" TextMode="Password">
                                          </asp:TextBox>
                                        <asp:RequiredFieldValidator 
                                          ControlToValidate="CurrentPassword" 
                                            ErrorMessage="Password is required."
                                            ID="CurrentPasswordRequired" 
                                            runat="server" 
                                            ToolTip="Password is required." 
                                            ValidationGroup="ChangePassword1">*</asp:RequiredFieldValidator>
                                    </td>
                                </tr>
                                <tr>
                                    <td align="right">
                                        <asp:Label 
                                          AssociatedControlID="NewPassword" 
                                            ID="NewPasswordLabel" 
                                            runat="server">New Password:
                                            </asp:Label></td>
                                    <td>
                                        <asp:TextBox ID="NewPassword" 
                                          runat="server" TextMode="Password">
                                         </asp:TextBox>
                                        <asp:RequiredFieldValidator 
                                          ControlToValidate="NewPassword" 
                                          ErrorMessage="New Password is required."
                                          ID="NewPasswordRequired" 
                                          runat="server" 
                                          ToolTip="New Password is required." 
                                          ValidationGroup="ChangePassword1">*
                                          </asp:RequiredFieldValidator>
                                    </td>
                                </tr>
                                <tr>
                                    <td align="right">
                                        <asp:Label 
                                          AssociatedControlID="ConfirmNewPassword" 
                                          ID="ConfirmNewPasswordLabel"
                                           runat="server">Confirm New Password:
                                         </asp:Label>
                                     </td>
                                    <td>
                                        <asp:TextBox ID="ConfirmNewPassword" 
                                          runat="server" 
                                          TextMode="Password">
                                         </asp:TextBox>
                                        <asp:RequiredFieldValidator 
                                          ControlToValidate="ConfirmNewPassword" 
                                          ErrorMessage="Confirm New Password is required."
                                          ID="ConfirmNewPasswordRequired" 
                                          runat="server" 
                                          ToolTip="Confirm New Password is required."
                                          ValidationGroup="ChangePassword1">*
                                        </asp:RequiredFieldValidator>
                                    </td>
                                </tr>
                                <tr>
                                    <td align="right">
                                        <asp:Label 
                                          AssociatedControlID="MyAccountDropDown" 
                                           ID="Label2" runat="server">
                                           Account Type:</asp:Label>
                                      </td>
                                    <td>
                                        <asp:DropDownList ID="MyAccountDropDown" 
                                          runat="server" >
                                            <asp:ListItem>Bronze</asp:ListItem>
                                            <asp:ListItem>Silver</asp:ListItem>
                                            <asp:ListItem>Gold</asp:ListItem>
                                          </asp:DropDownList>
                                     </td>
                                </tr>
                                <tr>
                                    <td align="center" colspan="2">
                                        <asp:CompareValidator 
                                          ControlToCompare="NewPassword" 
                                           ControlToValidate="ConfirmNewPassword"
                                            Display="Dynamic" 
                                            ErrorMessage="The confirm New Password must match the New Password entry."
                                            ID="NewPasswordCompare" 
                                            runat="server" 
                                            ValidationGroup="ChangePassword1">
                                         </asp:CompareValidator>
                                    </td>
                                </tr>
                                <tr>
                                    <td align="center" colspan="2" 
                                        style="color: Red;">
                                        <asp:Literal EnableViewState="False" 
                                            ID="FailureText" runat="server">
                                        </asp:Literal>
                                    </td>
                                </tr>
                                <tr>
                                    <td align="right">
                                        <asp:Button BackColor="White" 
                                            BorderColor="#C5BBAF" 
                                            BorderStyle="Solid" 
                                            BorderWidth="1px"
                                            CommandName="ChangePassword" 
                                            Font-Names="Verdana" 
                                            ForeColor="#1C5E55"
                                            ID="ChangePasswordPushButton" 
                                            runat="server" 
                                            Text="Change Password" 
                                            ValidationGroup="ChangePassword1" />
                                    </td>
                                    <td>
                                        <asp:Button BackColor="White" 
                                          BorderColor="#C5BBAF" 
                                          BorderStyle="Solid" 
                                          BorderWidth="1px"
                                          CausesValidation="False" 
                                          CommandName="Cancel" 
                                          Font-Names="Verdana" 
                                          ForeColor="#1C5E55" 
                                          ID="CancelPushButton" 
                                          runat="server" 
                                          Text="Cancel" />
                                    </td>
                                </tr>
                                <tr>
                                    <td colspan="2">
                                        <asp:HyperLink ID="HelpLink" 
                                          NavigateUrl="~/Help.htm" 
                                          runat="server">Need Help?
                                        </asp:HyperLink>
                                        <br />
                                        <asp:HyperLink ID="EditProfileLink" 
                                          NavigateUrl="~/Profile.htm" 
                                          runat="server">Edit Profile
                                        </asp:HyperLink>
                                    </td>
                                </tr>
                            </table>
                        </td>
                    </tr>
                </table>
            </ChangePasswordTemplate>
            <PasswordHintStyle Font-Italic="True" ForeColor="#1C5E55" />
            <TextBoxStyle Font-Size="0.8em" />
            <InstructionTextStyle Font-Italic="True" ForeColor="Black" />
        </asp:ChangePassword>
   
      
    </div>
    </form>
</body>
</html>
