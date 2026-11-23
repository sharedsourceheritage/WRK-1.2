<%@ Page Language="VB" MasterPageFile="~/Site.master"%>

<asp:Content ID="Content1" ContentPlaceHolderId="MainBody" runat="server">
  <asp:ChangePassword ID="ChangePassword1" runat="server" createuserurl="CreateUser.aspx" createusertext="Create a New Account"  canceldestinationpageurl="HomeChangePassword.aspx" displayusername="true" continuedestinationpageurl="HomeChangePassword.aspx"/>
</asp:Content>
