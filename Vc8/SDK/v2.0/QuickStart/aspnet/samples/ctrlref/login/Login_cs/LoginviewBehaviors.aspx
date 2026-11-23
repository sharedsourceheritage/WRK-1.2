<%@ Page Language="C#" MasterPageFile="~/UserInfo.master" %>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
  <h2>
    LoginView RoleGroup Sequence Sample</h2>
  Only one LoginView is shown to an authenticated user. If a user belongs to multiple
  roles that each have a unique template, the user will be shown the first template
  that their role matches. <b>Log in as User1 </b>and notice that you are shown different
  role's templates in the different examples because the templates are ordered differently
  within the LoginView control.
  <br />
  <br />
  <table cellpadding="8" width="100%">
    <tr>
      <td bgcolor="#ffffcc">
        In this example the templates are in the following order:
        <ol>
          <li>Admins</li>
          <li>Users</li>
          <li>Customers</li>
          <li>*Annonymous</li>
          <li>*LoggedIn</li>
        </ol>
      </td>
      <td width="10">
      </td>
      <td bgcolor="#ffccff" bordercolor="#cc00ff" valign="top">
        In this example the templates are in the following order:
        <ol>
          <li>Admins</li>
          <li>Customers</li>
          <li>Users</li>
          <li>*Annonymous</li>
          <li>*LoggedIn</li>
        </ol>
      </td>
    </tr>
    <tr>
      <td bgcolor="#ffffcc" valign="top">
        <asp:LoginView ID="LoginView1" runat="server">
          <LoggedInTemplate>
            <br />
            You are logged in as:<asp:LoginName ID="LoginName1" runat="server" />
            <br />
            <br />
            <asp:LoginStatus ID="LoginStatus1" runat="server" />
          </LoggedInTemplate>
          <AnonymousTemplate>
            You are not logged in. Please Login.<br />
            <br />
            <asp:Login ID="Login1" runat="server" BorderColor="Sienna" 
            BorderStyle="Solid" BorderWidth="1px">
            </asp:Login>
          </AnonymousTemplate>
          <RoleGroups>
            <asp:RoleGroup Roles="Admins">
              <ContentTemplate>
                <asp:LoginName ID="LoginName4" runat="server" />
                &nbsp;is viewing the <b>Admin Role </b>template.<br />
                <br />
                <asp:LoginStatus ID="LoginStatus2" runat="server" />
              </ContentTemplate>
            </asp:RoleGroup>
            <asp:RoleGroup Roles="Users">
              <ContentTemplate>
                <asp:LoginName ID="LoginName2" runat="server" />
                &nbsp;is viewing the <b>User Role</b> Template.<br />
                <asp:LoginStatus ID="LoginStatus3" runat="server" />
              </ContentTemplate>
            </asp:RoleGroup>
            <asp:RoleGroup Roles="Customers">
              <ContentTemplate>
                <asp:LoginName ID="LoginName3" runat="server" />
                is viewing the <b>Customer role</b> template.<br />
                <asp:LoginStatus ID="LoginStatus4" runat="server" />
              </ContentTemplate>
            </asp:RoleGroup>
          </RoleGroups>
        </asp:LoginView>
      </td>
      <td width="10">
      </td>
      <td bgcolor="#ffccff" bordercolor="#cc00ff" valign="top">
        <asp:LoginView ID="LoginView2" runat="server">
          <RoleGroups>
            <asp:RoleGroup Roles="Admins">
              <ContentTemplate>
                <asp:LoginName ID="LoginName4" runat="server" />
                &nbsp;is viewing the <b>Admin Role </b>template.<br />
                <br />
                <asp:LoginStatus ID="LoginStatus2" runat="server" />
              </ContentTemplate>
            </asp:RoleGroup>
            <asp:RoleGroup Roles="Customers">
              <ContentTemplate>
                <asp:LoginName ID="LoginName3" runat="server" />
                is viewing the <b>Customer Role</b> template.<br />
                <asp:LoginStatus ID="LoginStatus4" runat="server" />
              </ContentTemplate>
            </asp:RoleGroup>
            <asp:RoleGroup Roles="Users">
              <ContentTemplate>
                <asp:LoginName ID="LoginName2" runat="server" />
                &nbsp;is viewing the <b>User Role</b> Template.<br />
                <asp:LoginStatus ID="LoginStatus3" runat="server" />
              </ContentTemplate>
            </asp:RoleGroup>
          </RoleGroups>
          <LoggedInTemplate>
            <br />
            You are logged in as:<asp:LoginName ID="LoginName1" runat="server" />
            <br />
            <br />
            <asp:LoginStatus ID="LoginStatus1" runat="server" />
          </LoggedInTemplate>
          <AnonymousTemplate>
            You are not logged in. Please Login.<br />
            <br />
            <asp:Login ID="Login1" runat="server" BorderColor="DarkSlateGray" 
            BorderStyle="Solid" BorderWidth="1px">
            </asp:Login>
          </AnonymousTemplate>
        </asp:LoginView>
      </td>
    </tr>
  </table>
  <br />
  <br />
</asp:Content>
