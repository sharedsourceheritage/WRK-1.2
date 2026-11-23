<%@ Page Language="C#" %>

<script runat="server">
    
    protected void btnUnlockUser_Click(object sender, EventArgs e)
    {
        MembershipUser memUser = Membership.GetUser(txtUserName.Text);
        if (memUser != null && memUser.IsLockedOut == true)
            memUser.UnlockUser();
        
        //Refresh the information about the selected user.  
        DetailsView1.DataBind(); 
    }

    
     
    void linkLogout_Click(object sender, EventArgs e)
    {
        FormsAuthentication.SignOut();
        Roles.DeleteCookie();
        FormsAuthentication.RedirectToLoginPage();
    }

    protected void Page_Load(object sender, EventArgs e)
    {
        if (!Page.IsPostBack)
            txtUserName.Text = User.Identity.Name; 
    }
</script>

<html>
<head runat="server">
    <title>Unlock a User Account</title>
</head>
<body>
    <form id="form1" runat="server">
    <table id="tblUpdateUserProperties" cellpadding=0 cellspacing=0 >
          <tr>
            <td>
                Enter the username to view:  
                <asp:TextBox ID="txtUserName" runat="server" Width="226px" />
                <input type="submit" name="GetUser" id="GetUser" style="display:none" />
            </td>
          </tr>
          <tr>
              <td>
              <asp:DetailsView DataSourceID="ObjectDataSource1" Height="50px"
                  ID="DetailsView1" runat="server" Width="125px" AutoGenerateRows="False" >
                  <Fields>
                      <asp:BoundField DataField="CreationDate" HeaderText="CreationDate" ReadOnly="True"
                          SortExpression="CreationDate"></asp:BoundField>
                      <asp:BoundField DataField="LastActivityDate" HeaderText="LastActivityDate" SortExpression="LastActivityDate">
                      </asp:BoundField>
                      <asp:BoundField DataField="Email" HeaderText="Email" SortExpression="Email"></asp:BoundField>
                      <asp:BoundField DataField="ProviderUserKey" HeaderText="ProviderUserKey" ReadOnly="True"
                          SortExpression="ProviderUserKey"></asp:BoundField>
                      <asp:BoundField DataField="Comment" HeaderText="Comment" SortExpression="Comment"></asp:BoundField>
                      <asp:CheckBoxField DataField="IsLockedOut" HeaderText="IsLockedOut" ReadOnly="True"
                          SortExpression="IsLockedOut">
                          <HeaderStyle Font-Bold="True" />
                      </asp:CheckBoxField>
                      <asp:CheckBoxField DataField="IsOnline" HeaderText="IsOnline" ReadOnly="True" SortExpression="IsOnline">
                      </asp:CheckBoxField>
                      <asp:BoundField DataField="PasswordQuestion" HeaderText="PasswordQuestion" ReadOnly="True"
                          SortExpression="PasswordQuestion"></asp:BoundField>
                      <asp:BoundField DataField="ProviderName" HeaderText="ProviderName" ReadOnly="True"
                          SortExpression="ProviderName"></asp:BoundField>
                      <asp:BoundField DataField="LastLoginDate" HeaderText="LastLoginDate" SortExpression="LastLoginDate">
                      </asp:BoundField>
                      <asp:BoundField DataField="LastLockoutDate" HeaderText="LastLockoutDate" ReadOnly="True"
                          SortExpression="LastLockoutDate"></asp:BoundField>
                      <asp:BoundField DataField="UserName" HeaderText="UserName" ReadOnly="True" SortExpression="UserName">
                          <ItemStyle Font-Bold="True" />
                          <HeaderStyle Font-Bold="True" />
                      </asp:BoundField>
                      <asp:BoundField DataField="LastPasswordChangedDate" HeaderText="LastPasswordChangedDate"
                          ReadOnly="True" SortExpression="LastPasswordChangedDate"></asp:BoundField>
                      <asp:CheckBoxField DataField="IsApproved" HeaderText="IsApproved" SortExpression="IsApproved">
                      </asp:CheckBoxField>
                  </Fields>
                  <HeaderTemplate>
                      <div style="text-align: center">
                          <strong>User Properties</strong>
                      </div>
                  </HeaderTemplate>
                  <FooterTemplate>
                    <div style="text-align: center"> 
                      <asp:Button ID="btnUnlockUser" runat="server" Text="Unlock Currently Displayed User" OnClick="btnUnlockUser_Click" />
                     </div> 
                  </FooterTemplate>
              </asp:DetailsView>
              <asp:ObjectDataSource ID="ObjectDataSource1" runat="server" SelectMethod="GetUser" TypeName="System.Web.Security.Membership">
                  <SelectParameters>
                      <asp:ControlParameter ControlID="txtUserName" DefaultValue=" " Name="username"
                          PropertyName="Text" Type="String" />
                  </SelectParameters>
              </asp:ObjectDataSource> 
             </td> 
          </tr>
        </table>  
        <div align=center>
          <asp:LinkButton ID="linkLogout" Runat="server" OnClick="linkLogout_Click">Click here to logout</asp:LinkButton>
        </div>                
    </form> 
</body>
</html>