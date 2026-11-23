<%@ Page Language="VB" MasterPageFile="~/UserInfo.master"%>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
<h2>
    Templated Login Control Sample</h2>
  This sample shows a templated Login control with the correct control IDs and command
  names to ensure proper functionality of the control.
  <br />
  <asp:Login ID="Login1" runat="server">
    <LayoutTemplate>
      <table border="0" cellpadding="1">
        <tr>
          <td>
            <table border="0" cellpadding="0">
              <tr>
                <td align="center" colspan="2">
                  Log In</td>
              </tr>
              <tr>
                <td align="right">
                  <asp:Label ID="UserNameLabel" runat="server" 
                  AssociatedControlID="UserName">User Name:</asp:Label></td>
                <td>
                  <asp:TextBox ID="UserName" runat="server"></asp:TextBox>
                  <asp:RequiredFieldValidator ID="UserNameRequired" runat="server" 
                   ControlToValidate="UserName" ErrorMessage="User Name is required." 
                   ToolTip="User Name is required." ValidationGroup="Login1">*
                   </asp:RequiredFieldValidator>
                </td>
              </tr>
              <tr>
                <td align="right">
                  <asp:Label ID="PasswordLabel" runat="server" AssociatedControlID="Password">
                    Password:</asp:Label></td>
                <td>
                  <asp:TextBox ID="Password" runat="server" TextMode="Password"></asp:TextBox>
                  <asp:RequiredFieldValidator ID="PasswordRequired" runat="server" 
                   ControlToValidate="Password" ErrorMessage="Password is required." 
                   ToolTip="Password is required." ValidationGroup="Login1">*
                  </asp:RequiredFieldValidator>
                </td>
              </tr>
              <tr>
                <td colspan="2">
                  <asp:CheckBox ID="RememberMe" runat="server" 
                    Text="Remember me next time." />
                </td>
              </tr>
              <tr>
                <td align="center" colspan="2" style="color: red">
                  <asp:Literal ID="FailureText" runat="server" EnableViewState="False">
                  </asp:Literal>
                </td>
              </tr>
              <tr>
                <td align="right" colspan="2">
                  <asp:Button ID="LoginButton" runat="server" CommandName="Login" 
                  Text="Log In" ValidationGroup="Login1" />
                </td>
              </tr>
            </table>
          </td>
        </tr>
      </table>
    </LayoutTemplate>
  </asp:Login>
  <br />
  <br />
  <asp:LoginName ID="LoginName1" runat="server" />
  <asp:LoginStatus ID="LoginStatus1" runat="server" />
  <br />
  <br />
  Sample Note: All links in the Login control point to this page.
  </asp:Content>