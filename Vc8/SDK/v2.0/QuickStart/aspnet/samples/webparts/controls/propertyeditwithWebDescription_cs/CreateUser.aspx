<%@ Page Language="C#" %>
<html>
  <head runat="server">
    <title>
      WebPart Create User Page</title>
  </head>
  <body>
    <form id="form1" runat="server">
      <div>
        <asp:CreateUserWizard ID="CreateUserWizard1" Runat="server" ContinueDestinationPageUrl="default.aspx" />
      </div>
    </form>
  </body>
</html>
