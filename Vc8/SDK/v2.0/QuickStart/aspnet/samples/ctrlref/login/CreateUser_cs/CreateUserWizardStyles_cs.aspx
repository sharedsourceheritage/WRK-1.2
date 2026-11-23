<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>CreateUserWizard Styles Sample</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    <h2>CreateUserWizard Styles Sample</h2>
        This sample demonstrates various CreateUserWizard styles.
        <br /><br />
        <b>Note: </b>Users created on this page are valid for ChangePassword control 
          samples.
        <asp:HyperLink ID="HyperLink1" NavigateUrl="~/CreateUserWizardBasic_cs.aspx" 
          runat="server">Create a user</asp:HyperLink><br />
        <hr />
        <br />
                <asp:CreateUserWizard ID="CreateUserWizard1" runat="server" 
                  HelpPageText="Help" HelpPageUrl="~/Help.htm" 
                  EditProfileText="Edit Your Profile" 
                  EditProfileUrl="~/Profile.htm" 
                  ContinueDestinationPageUrl="~/Home.htm" 
                  BackColor="#F7F7DE" BorderColor="#CCCC99" 
                  BorderStyle="Solid" BorderWidth="1px" Font-Names="Verdana">
                    <WizardSteps>
                        <asp:CreateUserWizardStep runat="server">
                        </asp:CreateUserWizardStep>
                        <asp:CompleteWizardStep runat="server">
                        </asp:CompleteWizardStep>
                    </WizardSteps>
                    <SideBarStyle BackColor="#7C6F57" BorderWidth="0px" 
                      VerticalAlign="Top" />
                    <SideBarButtonStyle BorderWidth="0px" 
                      Font-Names="Verdana" ForeColor="#FFFFFF" />
                    <NavigationButtonStyle BackColor="#FFFBFF" 
                      BorderColor="#CCCCCC" BorderStyle="Solid"
                        BorderWidth="1px" Font-Names="Verdana" 
                        ForeColor="#284775" />
                    <HeaderStyle BackColor="#F7F7DE" BorderStyle="Solid" 
                        Font-Bold="True" ForeColor="#FFFFFF" 
                        HorizontalAlign="Left" />
                    <CreateUserButtonStyle BackColor="#FFFBFF" 
                      BorderColor="#CCCCCC" BorderStyle="Solid"
                        BorderWidth="1px" Font-Names="Verdana" 
                        ForeColor="#284775" />
                    <ContinueButtonStyle BackColor="#FFFBFF" 
                        BorderColor="#CCCCCC" BorderStyle="Solid"
                        BorderWidth="1px" Font-Names="Verdana" 
                        ForeColor="#284775" />
                    <StepStyle BorderWidth="0px" />
                    <TitleTextStyle BackColor="#6B696B" 
                      Font-Bold="True" ForeColor="#FFFFFF" />
                </asp:CreateUserWizard>
        <br />
        <asp:LoginName FormatString="Welcome {0}!" ID="LoginName1" 
          runat="server" />
        <asp:LoginStatus ID="LoginStatus1" runat="server" />
       <br />
        <br />
        </div>
    </form>
</body>
</html>
