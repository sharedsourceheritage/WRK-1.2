<%@ Page Language="C#" MasterPageFile="~/Site.master"%>

<asp:Content ID="Content1" ContentPlaceHolderId="MainBody" runat="server">
  <asp:CreateUserWizard ID="CreateUserWizard1" runat="server" continuedestinationpageurl="Home.aspx"/><br />
  <a href="Home.aspx">Return to Default Home Page</a><br />
  <a href="HomeLoginView.aspx">Return to LoginView Home Page</a><br />
  <a href="HomeChangePassword.aspx">Return to ChangePassword Home Page</a><br />
</asp:Content>
