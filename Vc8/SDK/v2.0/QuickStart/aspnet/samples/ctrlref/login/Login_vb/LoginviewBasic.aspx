<%@ Page Language="VB" MasterPageFile="~/UserInfo.master"%>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
<h2>
    Basic LoginView Sample</h2>
  Notice that different content is displayed to the user depending on their authentication
  status.
  <br />
  <br />
  <asp:LoginView ID="LoginView1" runat="server">
    <LoggedInTemplate>
      <br />
      You are logged in as
      <asp:LoginName ID="LoginName1" runat="server" />
      .<br />
      <br />
      <asp:LoginStatus ID="LoginStatus1" runat="server" />
    </LoggedInTemplate>
    <AnonymousTemplate>
      <strong>You are not logged in. Please Login.<br />
      </strong>
      <br />
      <asp:Login ID="Login1" runat="server" BackColor="#EFF3FB" BorderColor="#B5C7DE" BorderPadding="4"
        BorderStyle="Solid" BorderWidth="1px" Font-Names="Verdana" ForeColor="#333333">
        <TitleTextStyle BackColor="#507CD1" Font-Bold="True" Font-Size="0.9em" 
           ForeColor="White" />
        <LoginButtonStyle BackColor="White" BorderColor="#507CD1" BorderStyle="Solid" BorderWidth="1px"
          Font-Names="Verdana" ForeColor="#284E98" />
        <InstructionTextStyle Font-Italic="True" ForeColor="Black" />
      </asp:Login>
    </AnonymousTemplate>
  </asp:LoginView>
   </asp:Content>
