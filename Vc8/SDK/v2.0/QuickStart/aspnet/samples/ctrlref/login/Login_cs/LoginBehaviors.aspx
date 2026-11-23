<%@ Page Language="C#" MasterPageFile="~/UserInfo.master" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
  <h2>
    Horizontal Login Control</h2>
  In this sample the login control is oriented horizontally with the labels displayed
  above the textboxes. The instruction text and remember me checkbox have also been
  removed.
  <br />
  <br />
  <asp:Login ID="Login1" runat="server" VisibleWhenLoggedIn="False" Orientation="Horizontal"
    TextLayout="TextOnTop" BackColor="#E3EAEB" BorderColor="#E6E2D8" BorderPadding="4"
    BorderStyle="Solid" BorderWidth="1px" Font-Names="Verdana" ForeColor="#333333"
    DisplayRememberMe="False">
    <TitleTextStyle BackColor="#1C5E55" Font-Bold="True" ForeColor="White" />
    <LoginButtonStyle BackColor="White" BorderColor="#C5BBAF" BorderStyle="Solid" 
      BorderWidth="1px" Font-Names="Verdana" ForeColor="#1C5E55" />
  </asp:Login>
  <br />
  <br />
  <asp:LoginName ID="LoginName1" runat="server" ForeColor="#1C5E55" 
    FormatString="Welcome {0}!" />
  <asp:LoginStatus ID="LoginStatus1" runat="server" BackColor="White" 
    BorderColor="#C5BBAF" BorderStyle="Solid" BorderWidth="1px" 
    Font-Names="Verdana" ForeColor="#1C5E55" />
</asp:Content>
