<%@ page language="C#" EnableViewState="false" %>

<script runat="server">
    void btnAddUserToRole_Click(object sender, EventArgs e)
    {    
      if (lbxAvailableRoles.SelectedIndex != -1)
      {
        string selectedRole = lbxAvailableRoles.SelectedValue;

        if (!Roles.IsUserInRole(selectedRole))
        {
          try
          {
            Roles.AddUserToRole(User.Identity.Name, selectedRole);
            RefreshCurrentRolesListBox();
          }
          catch (Exception ex)
          {
            lblResults.Text = "Could not add the user to the role: " + Server.HtmlEncode(ex.Message);
            lblResults.Visible = true;
          }
        }
        else
        {
          lbxAvailableRoles.SelectedIndex = -1;
        }
      }
    }       
      
    void btnDeleteUserFromRole_Click(object sender, EventArgs e)
    {
      if (lbxUserRoles.SelectedIndex != -1)
      {
        string selectedRole = lbxUserRoles.SelectedValue;
           
        try
        {
          Roles.RemoveUserFromRole(User.Identity.Name, selectedRole);
          RefreshCurrentRolesListBox();
        }
        catch (Exception ex)
        {
          lblResults.Text = "Could not remove the user from the role: " + Server.HtmlEncode(ex.Message);
          lblResults.Visible = true;
        }
      }
    }

    private void RefreshAvailableRolesListBox()
    {
      lbxAvailableRoles.SelectedIndex = -1; 
      lbxAvailableRoles.DataSource = Roles.GetAllRoles();
      lbxAvailableRoles.DataBind();
      if (lbxAvailableRoles.Items.Count == 0)
      {
        lblRoleInfoText.Text = "There are currently no roles for this application.";
        lbxAvailableRoles.Visible = false;
        btnAddUserToRole.Visible = false;
      }
      else
      {
        lblRoleInfoText.Text = "The list of available roles is shown below.";
        lbxAvailableRoles.Visible = true;
        btnAddUserToRole.Visible = true;
      }
    }   
    
    private void RefreshCurrentRolesListBox()
    {
      lbxUserRoles.SelectedIndex = -1;
        
      //Could also call Roles.GetRolesForUser();
      lbxUserRoles.DataSource = ((RolePrincipal)User).GetRoles();
        
      lbxUserRoles.DataBind();
        
      if (lbxUserRoles.Items.Count == 0)
      {
        lblUserRoleInfoText.Text = "The user currently does not belong to any roles.";
        lbxUserRoles.Visible = false;
        btnDeleteUserFromRole.Visible = false;
      }
      else
      {
        lblUserRoleInfoText.Text = "The user is a member of the following roles.";
        lbxUserRoles.Visible = true;
        btnDeleteUserFromRole.Visible = true;
      }

     }

    void Page_Init(object sender, EventArgs e)
    {
      RefreshAvailableRolesListBox();
      RefreshCurrentRolesListBox();
    }  
</script>

<html>
  <head id="Head1" runat="server">
      <title>Manage Roles for the Current User</title>
  </head>
  <body>
    <form id="form1" runat="server">
        <table id="Table1" cellspacing="1" cellpadding="1" style="border-right: black thin solid; border-top: black thin solid; border-left: black thin solid; border-bottom: black thin solid">
            <tr>
                <td style="TEXT-ALIGN: center;">
                    <b><asp:label id="lblRoleInfoText" runat="server"/></b>
                </td>
            </tr>
            <tr>
                <td style="TEXT-ALIGN: center;">
                    <asp:listbox id="lbxAvailableRoles" runat="server">
                    </asp:listbox>
                </td>
            </tr>            
            <tr>
                <td style="TEXT-ALIGN: center;">
                    <asp:button id="btnAddUserToRole" runat="server" text="Add Current User to Selected Role" onclick="btnAddUserToRole_Click"/>
                
                </td>
            </tr>
            <tr>
                <td>&nbsp;</td>
            </tr>
            <tr>
                <td style="TEXT-ALIGN: center;">
                    <b><asp:label id="lblUserRoleInfoText" runat="server" Visible=true /></b>
                </td>
            </tr>            
            <tr>
                <td>
                    <asp:listbox id="lbxUserRoles" runat="server" width="100%" />
                </td>
            </tr>
            <tr>
                <td align=center>
                    <asp:button id="btnDeleteUserFromRole" runat="server" text="Delete User from Selected Role" onclick="btnDeleteUserFromRole_Click" />
                </td>
            </tr>
        </table>
        <br />
        <a href="Add_Delete_Roles.aspx">Click here to manage roles for the application.</a>
        <br />
        <br />
        <a href="IsInRole.aspx">Click here to see the results of IsInRole checks for the current user.</a>
        <br />
        <br />        
        <a href="../administrators_role/Administrators_Page.aspx">Click here to access the "Administrators-only" page<br /> (note - you need to be in the Administrators role to get to the page).</a>
        <br />
        <br />
        <asp:label id="lblResults" runat="server" Visible=false ForeColor=Red>Results:</asp:label>
    </form>
  </body>
</html>
