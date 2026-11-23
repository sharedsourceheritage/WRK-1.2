<%@ Page Language="VB" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head id="Head1" runat="server">
    <title>CreateUserWizard Basic Sample</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
     <h2>CreateUserWizard Basic Sample</h2>
        This sample demonstrates basic CreateUserWizard functionality. This sample uses
        a regular expression to validate the email address.<br /><br />
        <b>Note: </b>Users created on this page are valid for ChangePassword control samples.
        <asp:HyperLink ID="HyperLink1" NavigateUrl="~/CreateUserWizardBasic_vb.aspx" 
          runat="server">Create a user</asp:HyperLink><br />
        <hr />
        <br />
        <asp:LoginView ID="LoginView1" runat="server">
            <LoggedInTemplate>
                <asp:LoginName FormatString="Welcome {0}!" ID="LoginName1" runat="server" />
                <asp:LoginStatus ID="LoginStatus1" runat="server" />
            </LoggedInTemplate>
        </asp:LoginView>
        <br />
        <br />
        <asp:CreateUserWizard ID="CreateUserWizard1" runat="server" BackColor="#F7F6F3" 
          BorderColor="#E6E2D8" BorderStyle="Solid" BorderWidth="1px" 
          Font-Names="Verdana" Font-Size="0.8em" 
          EmailRegularExpression="\w+([-+.']\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*">
            <WizardSteps>
                <asp:CreateUserWizardStep ID="CreateUserWizardStep1" runat="server">
                </asp:CreateUserWizardStep>
                <asp:CompleteWizardStep ID="CompleteWizardStep1" runat="server">
                </asp:CompleteWizardStep>
            </WizardSteps>
          <SideBarStyle BackColor="#5D7B9D" BorderWidth="0px" VerticalAlign="Top" />
          <SideBarButtonStyle BorderWidth="0px" Font-Names="Verdana" ForeColor="White" />
          <NavigationButtonStyle BackColor="#FFFBFF" BorderColor="#CCCCCC" 
            BorderStyle="Solid" BorderWidth="1px" Font-Names="Verdana" 
            ForeColor="#284775" />
          <HeaderStyle BackColor="#5D7B9D" BorderStyle="Solid" 
            Font-Bold="True" ForeColor="White" HorizontalAlign="Left" />
          <CreateUserButtonStyle BackColor="#FFFBFF" BorderColor="#CCCCCC" 
            BorderStyle="Solid" BorderWidth="1px" Font-Names="Verdana" 
            ForeColor="#284775" />
          <ContinueButtonStyle BackColor="#FFFBFF" BorderColor="#CCCCCC" 
            BorderStyle="Solid" BorderWidth="1px" Font-Names="Verdana" 
            ForeColor="#284775" />
          <StepStyle BorderWidth="0px" />
          <TitleTextStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
        </asp:CreateUserWizard>
       </div>
    </form>
</body>
</html>
