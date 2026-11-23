<%@ Page Language="C#" %>
<script runat="server">

    void linkLogout_Click(object sender, EventArgs e)
    {
        FormsAuthentication.SignOut();
        Roles.DeleteCookie();
        FormsAuthentication.RedirectToLoginPage(); 
    }

    protected void DetailsView1_ItemUpdating(object sender, DetailsViewUpdateEventArgs e)
    {
        //Need to handle the update manually because MembershipUser does not have a
        //parameterless constructor  
        MembershipUser memUser = Membership.GetUser();
         
        memUser.Email = (string)e.NewValues[0];
        memUser.Comment = (string)e.NewValues[1];

        try
        {
          Membership.UpdateUser(memUser);

          e.Cancel = true;
          DetailsView1.ChangeMode(DetailsViewMode.ReadOnly);
        }
        catch(Exception ex)
        {
          Response.Write("<div>The following error occurred:<font color='red'> " + ex.Message + "</font></div>");
          
          e.Cancel = true;
        }
    }
</script>
<html>
<head id="Head1" runat="server">
    <title>Update User Properties</title>
</head>
<body>
    <form id="form1" runat="server">
    <table id="tblUpdateUserProperties" cellpadding=0 cellspacing=0 >
          <tr>
              <td>
              <asp:DetailsView AutoGenerateRows="False" DataSourceID="ObjectDataSource1" Height="50px"
                  ID="DetailsView1" runat="server" Width="125px" AutoGenerateEditButton="True" OnItemUpdating="DetailsView1_ItemUpdating">
                  <Fields>
                      <asp:BoundField DataField="CreationDate" HeaderText="CreationDate" ReadOnly="True"
                          SortExpression="CreationDate"></asp:BoundField>
                      <asp:BoundField DataField="LastActivityDate" HeaderText="LastActivityDate" SortExpression="LastActivityDate" ReadOnly="True">
                      </asp:BoundField>
                      <asp:BoundField DataField="Email" HeaderText="Email" SortExpression="Email"></asp:BoundField>
                      <asp:BoundField DataField="ProviderUserKey" HeaderText="ProviderUserKey" ReadOnly="True"
                          SortExpression="ProviderUserKey"></asp:BoundField>
                      <asp:BoundField DataField="Comment" HeaderText="Comment" SortExpression="Comment"></asp:BoundField>
                      <asp:BoundField DataField="IsOnline" HeaderText="IsOnline" SortExpression="IsOnline" ReadOnly="True">
                      </asp:BoundField>
                      <asp:BoundField DataField="IsApproved" HeaderText="IsApproved" SortExpression="IsApproved" ReadOnly="True">
                      </asp:BoundField>
                      <asp:BoundField DataField="IsLockedOut" HeaderText="IsLockedOut" SortExpression="IsLockedOut" ReadOnly="True">
                      </asp:BoundField>
                      <asp:BoundField DataField="PasswordQuestion" HeaderText="PasswordQuestion" ReadOnly="True"
                          SortExpression="PasswordQuestion"></asp:BoundField>
                      <asp:BoundField DataField="ProviderName" HeaderText="ProviderName" ReadOnly="True"
                          SortExpression="ProviderName"></asp:BoundField>
                      <asp:BoundField DataField="LastLoginDate" HeaderText="LastLoginDate" SortExpression="LastLoginDate" ReadOnly="True">
                      </asp:BoundField>
                      <asp:BoundField DataField="LastLockoutDate" HeaderText="LastLockoutDate" ReadOnly="True"
                          SortExpression="LastLockoutDate"></asp:BoundField>
                      <asp:BoundField DataField="UserName" ItemStyle-Font-Bold=true HeaderText="UserName" HeaderStyle-Font-Bold=true ReadOnly="True" SortExpression="UserName">
                      </asp:BoundField>
                      <asp:BoundField DataField="LastPasswordChangedDate" HeaderText="LastPasswordChangedDate"
                          ReadOnly="True" SortExpression="LastPasswordChangedDate"></asp:BoundField>
                  </Fields>
                  <HeaderTemplate>
                      <div style="text-align: center">
                          <strong>User Properties</strong>
                      </div>
                  </HeaderTemplate>
              </asp:DetailsView>
              <asp:ObjectDataSource ID="ObjectDataSource1" runat="server" DataObjectTypeName="System.Web.Security.MembershipUser" SelectMethod="GetUser" TypeName="System.Web.Security.Membership"></asp:ObjectDataSource> 
             </td> 
          </tr>
        </table>
        <hr />
        <br />       
        <div align=center>
          <asp:LinkButton ID="linkLogout" Runat="server" OnClick="linkLogout_Click">Click here to logout</asp:LinkButton>
        </div>        
    </form>    
</body>
</html>
