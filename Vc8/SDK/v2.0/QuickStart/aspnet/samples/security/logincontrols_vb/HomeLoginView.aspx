<%@ Page Language="VB" MasterPageFile="~/Site.master"%>

<asp:Content ID="Content1" ContentPlaceHolderId="MainBody" runat="server">

  <asp:loginview ID="LoginView1" runat="server">
    <loggedintemplate>
      <h1>
        <asp:loginname id="LoginName1" runat="server" formatstring="Welcome {0}" />
      </h1>
    </loggedintemplate>
    <anonymoustemplate>
      <h1>Welcome to Login Controls</h1>
      <asp:login ID="Login1" runat="server" createuserurl="CreateUser.aspx" createusertext="Create a New Account" />
    </anonymoustemplate>
    
  </asp:LoginView>
  
</asp:Content>



