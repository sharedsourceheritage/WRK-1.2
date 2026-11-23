<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">
// Writes the values of the textboxes in the additional wizardsteps to labels.
  void AddressWrite(object sender, WizardNavigationEventArgs e)
  {
    Label3.Text = "Your Address Information is:";
    Label1.Text = Server.HtmlEncode(TextBox1.Text);
    Label2.Text = Server.HtmlEncode(TextBox2.Text);
    
 }
    
</script>

<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
    <title>CreateUserWizard Behaviors Sample</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
     <h2>CreateUserWizard Behaviors Sample</h2>
        This sample demonstrates how to add an additional WizardStep to the 
        CreateUserWizard.<br /><br />
        <b>Note: </b>Users created on this page are valid for ChangePassword control 
          samples.
        <asp:HyperLink ID="HyperLink1" NavigateUrl="~/CreateUserWizardBasic_cs.aspx" 
          runat="server">Create a user</asp:HyperLink><br />
        <hr />
        <br />
      <asp:CreateUserWizard ID="CreateUserWizard1" runat="server" HelpPageText="Help" 
        HelpPageUrl="~/Help.htm" EditProfileText="Edit Your Profile" 
        EditProfileUrl="~/Profile.htm" OnFinishButtonClick="AddressWrite"
        ContinueDestinationPageUrl="~/Home.htm" BackColor="#E3EAEB" 
        BorderColor="#E6E2D8" BorderStyle="Solid" BorderWidth="1px" 
        Font-Names="Verdana" 
        EmailRegularExpression="\w+([-+.']\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*">
        <WizardSteps>
          <asp:CreateUserWizardStep runat="server">
          </asp:CreateUserWizardStep>
          <asp:WizardStep ID="Address" runat="server" Title="Address">
            Address1<asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
            <br />
            Address2<asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
          </asp:WizardStep>
          <asp:CompleteWizardStep runat="server">
          </asp:CompleteWizardStep>
        </WizardSteps>
        <SideBarStyle BackColor="#1C5E55" VerticalAlign="Top" />
        <SideBarButtonStyle ForeColor="White" />
        <NavigationButtonStyle BackColor="White" BorderColor="#C5BBAF" 
         BorderStyle="Solid" BorderWidth="1px" Font-Names="Verdana" 
         ForeColor="#1C5E55" />
        <HeaderStyle BackColor="#666666" BorderColor="#E6E2D8" 
          BorderStyle="Solid" BorderWidth="2px" Font-Bold="True" 
          ForeColor="White" HorizontalAlign="Center" />
        <CreateUserButtonStyle BackColor="White" BorderColor="#C5BBAF" 
         BorderStyle="Solid" BorderWidth="1px" Font-Names="Verdana" 
           ForeColor="#1C5E55" />
        <ContinueButtonStyle BackColor="White" BorderColor="#C5BBAF" 
          BorderStyle="Solid"
          BorderWidth="1px" Font-Names="Verdana" ForeColor="#1C5E55" />
        <StepStyle BorderWidth="0px" />
        <TitleTextStyle BackColor="#1C5E55" Font-Bold="True" 
          ForeColor="White" />
      </asp:CreateUserWizard>
      <br />
      <asp:LoginName FormatString="Welcome {0}!" ID="LoginName1" 
          runat="server" />
      <asp:LoginStatus ID="LoginStatus1" runat="server" />
      &nbsp;<br />
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
