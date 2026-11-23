<%@ Page Language="VB" MasterPageFile="~/UserInfo.master"%>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
       <h2>
    Login Style Sample</h2>
  <asp:Login ID="Login1" runat="server" BackColor="#F7F6F3" BorderColor="#E6E2D8" 
     BorderPadding="4" BorderStyle="Solid" BorderWidth="1px" CreateUserText="New User?" 
     CreateUserUrl="~/LoginStyles.aspx" Font-Names="Verdana" Font-Size="0.8em"
     ForeColor="#333333" HelpPageText="Help" HelpPageUrl="~/LoginStyles.aspx"
     InstructionText="Please enter your information." 
     PasswordRecoveryText="Forgot your password." PasswordRecoveryUrl="~/LoginStyles.aspx">
    <TitleTextStyle BackColor="#5D7B9D" Font-Bold="True" Font-Size="0.9em" 
     ForeColor="White" />
    <LoginButtonStyle BackColor="#FFFBFF" BorderColor="#CCCCCC" BorderStyle="Solid" 
      BorderWidth="1px" Font-Names="Verdana" ForeColor="#284775" />
    <InstructionTextStyle Font-Italic="True" ForeColor="Black" />
  </asp:Login>
  <br />
  <br />
  <asp:LoginName ID="LoginName1" runat="server" ForeColor="#284775" 
    FormatString="Welcome {0}!" />
  <asp:LoginStatus ID="LoginStatus1" runat="server" BackColor="#FFFBFF" 
   BorderColor="#CCCCCC" BorderStyle="Solid" BorderWidth="1px" Font-Names="Verdana" 
   ForeColor="#284775" />
  <br />
  <br />
  Sample Note: For demonostration purposes all links in this sample point to this
  page.
</asp:Content>
