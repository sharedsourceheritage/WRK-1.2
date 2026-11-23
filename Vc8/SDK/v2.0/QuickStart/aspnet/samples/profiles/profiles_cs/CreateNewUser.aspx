<%@ Page Language="C#" %>

<script runat="server">

</script>

<html>
  <head runat="server">
      <title>Create New User for Profile QuickStart</title>
  </head>
  <body>
      <form id="form1" runat="server">
      <div>
        <asp:CreateUserWizard 
          ID="CreateUserWizard1" 
          Runat="server" 
          CancelDestinationPageUrl="~/HomePage.aspx" 
          ContinueDestinationPageUrl="~/secured/ProfileProperties.aspx" 
          BorderWidth="1px" 
          BorderColor="#CCCC99" 
          BorderStyle="Solid" 
          BackColor="#F7F7DE" 
          Font-Names="Verdana" 
          Font-Size="10pt" 
          CreateUserTitleText="Create a New Account for the Profile QuickStart" 
          CompleteSuccessText="Your account has been successfully created for the Profile QuickStart." 
          LoginCreatedUser="true" 
          RequireEmail="false">
          <TitleTextStyle Font-Bold="True" BackColor="#6B696B" ForeColor="#FFFFFF"></TitleTextStyle>
        </asp:CreateUserWizard>
      </div>
      </form>
  </body>
</html>
