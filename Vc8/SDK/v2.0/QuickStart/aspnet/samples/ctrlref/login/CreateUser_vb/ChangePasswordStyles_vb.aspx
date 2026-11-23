<%@ Page Language="VB" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
  <title>ChangePassword Styles</title>
</head>
<body text="#c">
  <form id="form1" runat="server">
    <div>
      <h2>
        ChangePassword Styles Sample</h2>
      This sample demonstrates various style properties on the control. This sample 
      also enables non-authenticated users to change their password after verifying their 
      current password. This is particularly useful in systems that allow a user to have 
      several screen accounts.
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
      <asp:ChangePassword ID="ChangePassword1" runat="server" DisplayUserName="True" 
        EditProfileText="Edit Profile" EditProfileUrl="~/Profile.htm" 
        HelpPageText="Need Help?" HelpPageUrl="~/Help.htm"
        InstructionText="Enter your username and old password." BackColor="#EFF3FB" 
        BorderColor="#B5C7DE" BorderPadding="4" BorderStyle="Solid" 
        BorderWidth="1px" Font-Names="Verdana" Font-Size="0.8em">
        <CancelButtonStyle BackColor="White" BorderColor="#507CD1" 
          BorderStyle="Solid" BorderWidth="1px" Font-Names="Verdana" 
          Font-Size="0.8em" ForeColor="#284E98" />
        <ChangePasswordButtonStyle BackColor="White" BorderColor="#507CD1" 
          BorderStyle="Solid" BorderWidth="1px" Font-Names="Verdana" 
          Font-Size="0.8em" ForeColor="#284E98" />
        <ContinueButtonStyle BackColor="White" BorderColor="#507CD1" 
          BorderStyle="Solid" BorderWidth="1px" Font-Names="Verdana" 
          Font-Size="0.8em" ForeColor="#284E98" />
        <TitleTextStyle BackColor="#507CD1" Font-Bold="True" Font-Size="0.9em" 
          ForeColor="White" />
        <PasswordHintStyle Font-Italic="True" ForeColor="#507CD1" />
        <InstructionTextStyle Font-Italic="True" ForeColor="Black" />
      </asp:ChangePassword>
    </div>
  </form>
</body>
</html>
