<%@ Page Language="C#"  MasterPageFile="~/UserInfo.master" %>

    <asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
       <h2>Basic Login Sample</h2>
        Use one of the example accounts to log in to the website. 
        <br /><br />
        <asp:Login ID="Login1" runat="server" BackColor="#F7F6F3" BorderColor="#E6E2D8"
         BorderPadding="4" BorderStyle="Solid" BorderWidth="1px" 
         DestinationPageUrl="~/LoginNameStatusBasic.aspx" Font-Names="Verdana" 
         ForeColor="#333333">
          <TitleTextStyle BackColor="#5D7B9D" Font-Bold="True" ForeColor="White" />
          <LoginButtonStyle BackColor="#FFFBFF" BorderColor="#CCCCCC" 
          BorderStyle="Solid" BorderWidth="1px" Font-Names="Verdana" ForeColor="#284775" />
          <InstructionTextStyle Font-Italic="True" ForeColor="Black" />
        </asp:Login>
    </asp:Content>