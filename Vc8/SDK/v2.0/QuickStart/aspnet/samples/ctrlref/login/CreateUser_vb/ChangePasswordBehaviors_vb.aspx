<%@ Page Language="VB" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
  <title>ChangePassword Behaviors Sample</title>
</head>
<body>
  <form id="form1" runat="server">
    <div>
      <h2>
        ChangePassword Behaviors Sample</h2>
      This sample demonstrates how to set a CancelDestinationPageUrl and 
      SuccessPageUrl.  This sample also enables non-authenticated users 
      to change their password after verifying their current password. You will also 
      notice that the optional Help and Profile links are displayed within the control.
      <br />
      <br />
      <b>Note: </b>You must first create a user for this application.
      <asp:HyperLink ID="HyperLink2" NavigateUrl="~/CreateUserWizardBasic_vb.aspx" 
        runat="server">Create a user</asp:HyperLink><br />
      <hr />
      <br />
      <asp:LoginName ID="LoginName1" runat="server" />
      <asp:LoginStatus ID="LoginStatus1" runat="server" />
      &nbsp;&nbsp;<br />
      <br />
      <br />
      <asp:ChangePassword ID="ChangePassword1" runat="server" 
        CancelDestinationPageUrl="~/Home.htm" DisplayUserName="True" 
        EditProfileText="Edit Profile" EditProfileUrl="~/Profile.htm" 
        HelpPageText="Need Help?" HelpPageUrl="~/Help.htm" 
        InstructionText="Enter your username and old password."
        BackColor="#F7F6F3" BorderColor="#E6E2D8" BorderPadding="4" 
        BorderStyle="Solid"
        BorderWidth="1px" Font-Names="Verdana" SuccessPageUrl="~/Help.htm">
        <CancelButtonStyle BackColor="#FFFBFF" BorderColor="#CCCCCC" 
          BorderStyle="Solid" BorderWidth="1px" Font-Names="Verdana" 
          ForeColor="#284775" />
        <ChangePasswordButtonStyle BackColor="#FFFBFF" BorderColor="#CCCCCC" 
          BorderStyle="Solid" BorderWidth="1px" Font-Names="Verdana" 
          ForeColor="#284775" />
        <ContinueButtonStyle BackColor="#FFFBFF" BorderColor="#CCCCCC" 
          BorderStyle="Solid" BorderWidth="1px" Font-Names="Verdana" 
          ForeColor="#284775" />
        <TitleTextStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
        <PasswordHintStyle Font-Italic="True" ForeColor="#888888" />
        <InstructionTextStyle Font-Italic="True" ForeColor="Black" />
      </asp:ChangePassword>
    </div>
  </form>
</body>
</html>
