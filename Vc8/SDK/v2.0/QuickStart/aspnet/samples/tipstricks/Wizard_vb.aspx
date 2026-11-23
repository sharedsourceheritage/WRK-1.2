<%@ Page Language="VB" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<script runat="server">

  Protected Sub Wizard1_FinishButtonClick(ByVal sender As Object, ByVal e As System.Web.UI.WebControls.WizardNavigationEventArgs)
    
        Try
            ' Create User In Membership System
            Membership.CreateUser(Email.Text, Password.Text)

            ' Issue Authentication Ticket
            FormsAuthentication.SetAuthCookie(Email.Text, False)

            ' Update Profile with Registration Options
            Profile.Initialize(Email.Text, True)

            Profile.PhoneNumber = Phone.Text
            Profile.Age = CInt(Age.Text)
            Profile.Gender = Gender.SelectedValue
            Profile.ZipCode = CInt(ZipCode.Text)

            Response.Redirect("Profile_vb.aspx")
        Catch ex As Exception
            ErrorLabel.Text = "An error occured creating the new user. Exception details: " & ex.Message
        End Try
        
    End Sub
</script>
<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
  <title>Wizard Control</title>
</head>
<body>
  <form id="form1" runat="server">
    <div>
    <h3>Wizard Control Example</h3>
      <asp:Wizard ID="Wizard1" Width="500" runat="server" ActiveStepIndex="0" OnFinishButtonClick="Wizard1_FinishButtonClick"
        BackColor="#F7F6F3" Font-Names="Verdana" BorderWidth="1px" BorderColor="#CCCCCC" CellPadding="10" >
        <StepStyle ForeColor="#5D7B9D" Font-Size="Small" BorderWidth="0px" />
        <WizardSteps>
          <asp:WizardStep ID="WizardStep1" runat="server" Title="Email/Password">
            <b>Register Account</b><br />
            <br />
            <table>
              <tr>
                <td style="width: 100px" valign="top">
                  Email:</td>
                <td style="width: 100px" valign="top">
                  <asp:TextBox runat="server" ID="Email" />
                </td>
              </tr>
              <tr>
                <td style="width: 100px" valign="top">
                  Password:</td>
                <td style="width: 100px" valign="top">
                  <asp:TextBox runat="server" ID="Password" />
                </td>
              </tr>
            </table>
          </asp:WizardStep>
          <asp:WizardStep ID="WizardStep2" runat="server" Title="Age/Gender">
            <b>Register Account</b><br />
            <br />
            <table>
              <tr>
                <td style="width: 100px" valign="top">
                  Age:
                </td>
                <td style="width: 100px" valign="top">
                  <asp:TextBox runat="server" Width="63px" ID="Age" />
                </td>
              </tr>
              <tr>
                <td style="width: 100px" valign="top">
                  Gender:
                </td>
                <td style="width: 100px" valign="top">
                  <asp:RadioButtonList runat="server" ID="Gender">
                    <asp:ListItem>Male</asp:ListItem>
                    <asp:ListItem>Female</asp:ListItem>
                  </asp:RadioButtonList>
                </td>
              </tr>
            </table>
            &nbsp;</asp:WizardStep>
          <asp:WizardStep ID="WizardStep3" runat="server" Title="ZipCode/Phone">
            <b>Register Account<br />
            </b>
            <br />
            <table>
              <tr>
                <td style="width: 100px" valign="top">
                  Zip Code:</td>
                <td style="width: 100px" valign="top">
                  <asp:TextBox runat="server" ID="ZipCode" />
                </td>
              </tr>
              <tr>
                <td style="width: 100px" valign="top">
                  Phone:
                </td>
                <td style="width: 100px" valign="top">
                  <asp:TextBox runat="server" ID="Phone" />
                </td>
              </tr>
            </table>
          </asp:WizardStep>
        </WizardSteps>
        <NavigationButtonStyle Font-Names="Verdana" Font-Size="0.8em" BorderStyle="Solid"
          BorderWidth="1px" BorderColor="#CCCCCC" BackColor="#FFFBFF" ForeColor="#284775" />
        <SideBarButtonStyle Font-Names="Verdana" BorderWidth="0px" ForeColor="White" />
        <HeaderStyle ForeColor="White" HorizontalAlign="Left" Font-Size="0.9em" Font-Bold="True"
          BackColor="#5D7B9D" BorderStyle="Solid" />
        <SideBarStyle VerticalAlign="Top" Font-Size="0.9em" BackColor="#7C6F57" BorderWidth="0px" />
      </asp:Wizard>
      <br />
      <asp:Label ID="ErrorLabel" runat=server />
    </div>
  </form>
</body>
</html>
