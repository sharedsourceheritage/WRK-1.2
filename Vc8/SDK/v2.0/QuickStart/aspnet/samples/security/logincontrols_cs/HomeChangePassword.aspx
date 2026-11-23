<%@ Page Language="C#" MasterPageFile="~/Site.master"%>

<asp:Content ID="Content1" ContentPlaceHolderId="MainBody" runat="server">

  <asp:loginview ID="LoginView1" runat="server">
    <loggedintemplate>
      <h1>
        Welcome
        <asp:loginname id="LoginName1" runat="server" />
      </h1>
      <a href="ChangePassword.aspx">Change Your Password</a>
    </loggedintemplate>
    <anonymoustemplate>
      <h1>Welcome to Login Controls</h1>
    </anonymoustemplate>
  </asp:LoginView>

</asp:Content>



