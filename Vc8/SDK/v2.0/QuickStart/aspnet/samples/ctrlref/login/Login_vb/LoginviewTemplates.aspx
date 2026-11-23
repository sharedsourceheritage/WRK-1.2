<%@ Page Language="VB" MasterPageFile="~/UserInfo.master"%>

<script language="VB" runat="server">
    Protected Sub DropDownList1_SelectedIndexChanged(sender As Object, e As EventArgs)
    Label1.Text = "The Admin of the site is" & CType(LoginView1.FindControl("DropDownList1"), DropDownList).SelectedItem.Text
    End Sub
</script>
<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
<h2>
    LoginView Template Find Control Sample</h2>
  This sample demonstrates how to find and retrieve a value from a control contained
  in a LoginView template. In this example <b>log in as User2 and select a choice from
    the drop down list displayed in the Admin template.</b>
  <br />
  <br />
  <table cellpadding="8" width="90%">
    <tr>
      <td bgcolor="#ffffcc">
        In this example the templates are in the following order:
        <ol>
          <li>Admins</li><li>Users</li><li>Customers</li><li>*Annonymous</li><li>*LoggedIn</li>
        </ol>
      </td>
      <td width="10">
      </td>
      <td bgcolor="#ffccff" bordercolor="#cc00ff" valign="top">
        In this example the templates are in the following order:
        <ol>
          <li>Admins</li><li>Customers</li><li>Users</li><li>*Annonymous</li><li>*LoggedIn</li>
        </ol>
      </td>
    </tr>
    <tr>
      <td bgcolor="#ff00cc" colspan="3">
        <asp:Label ID="Label1" runat="server" Font-Bold="True"></asp:Label></td>
    </tr>
    <tr>
      <td bgcolor="#ffffcc">
        <asp:LoginView ID="LoginView1" runat="server">
          <LoggedInTemplate>
            <br />
            You are logged in as:<asp:LoginName ID="LoginName1" runat="server" />
            <br />
            <br />
            <asp:LoginStatus ID="LoginStatus1" runat="server" />
          </LoggedInTemplate>
          <AnonymousTemplate>
            <br />
            You are not logged in. Please Login.
            <br />            <br />
            <asp:Login ID="Login1" runat="server" BorderColor="Peru" 
            BorderStyle="Solid" BorderWidth="1px">
            </asp:Login>
          </AnonymousTemplate>
          <RoleGroups>
            <asp:RoleGroup Roles="Admins">
              <ContentTemplate>
                <b>How hard are you working:</b>
                <asp:DropDownList ID="DropDownList1" runat="server" 
                AutoPostBack="True" 
                OnSelectedIndexChanged="DropDownList1_SelectedIndexChanged">
                  <asp:ListItem>WorkingHard</asp:ListItem>
                  <asp:ListItem>WorkingVeryHard</asp:ListItem>
                  <asp:ListItem>WorkingExtraHard</asp:ListItem>
                </asp:DropDownList>
                <asp:LoginName ID="LoginName4" runat="server" />
                &nbsp;is viewing the <b>Admin Role</b> template and is
                <br />
                <br />
                <asp:LoginStatus ID="LoginStatus2" runat="server" />
                <br />
                <br />
                <br />
              </ContentTemplate>
            </asp:RoleGroup>
            <asp:RoleGroup Roles="Users">
              <ContentTemplate>
                <asp:LoginName ID="LoginName2" runat="server" />
                &nbsp;is viewing the <b>User Role</b> template.<br />
                <asp:LoginStatus ID="LoginStatus3" runat="server" />
              </ContentTemplate>
            </asp:RoleGroup>
            <asp:RoleGroup Roles="Customers">
              <ContentTemplate>
                <asp:LoginName ID="LoginName3" runat="server" />
                is viewing the <b>Customer Role</b>template.<br />
                <asp:LoginStatus ID="LoginStatus4" runat="server" />
              </ContentTemplate>
            </asp:RoleGroup>
          </RoleGroups>
        </asp:LoginView>
      </td>
      <td>
      </td>
      <td bgcolor="#ffccff" bordercolor="#cc00ff">
        <asp:LoginView ID="LoginView2" runat="server">
          <RoleGroups>
            <asp:RoleGroup Roles="Admins">
              <ContentTemplate>
                <asp:LoginName ID="LoginName4" runat="server" />
                &nbsp;is viewing the <b>Admin Role</b> template.<br />
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
                &nbsp;is viewing the <b>User Role</b> template.<br />
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
            <asp:Login ID="Login1" runat="server" BorderColor="MidnightBlue"
            BorderStyle="Solid" BorderWidth="1px">
            </asp:Login>
          </AnonymousTemplate>
        </asp:LoginView>
      </td>
    </tr>
  </table>
    </asp:Content>
