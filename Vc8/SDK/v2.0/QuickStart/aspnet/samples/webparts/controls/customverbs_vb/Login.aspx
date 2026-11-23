<%@ Page Language="VB" %>
<html>
  <head runat="server">
    <title>
      WebPart Login Page</title>
  </head>
  <body>
    <form id="form1" runat="server">
      <div>
        <asp:Login ID="Login1" CreateUserUrl="CreateUser.aspx" CreateUserText="Create a New Account"
          Runat="server" />
      </div>
    </form>
  </body>
</html>
