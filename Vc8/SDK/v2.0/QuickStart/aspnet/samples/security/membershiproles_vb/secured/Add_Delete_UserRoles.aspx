<%@ Page Language="VB" %>

<script runat="server"> 
  Sub btnAddUserToRole_Click(ByVal sender As Object, ByVal e As System.EventArgs)
    If (lbxAvailableRoles.SelectedIndex <> -1) Then
      Dim selectedRole As String = lbxAvailableRoles.SelectedValue

      If Not Roles.IsUserInRole(selectedRole) Then
        Try
          Roles.AddUserToRole(User.Identity.Name, selectedRole)
          RefreshCurrentRolesListBox()
        Catch ex As Exception
          lblResults.Text = "Could not add the user to the role: " + Server.HtmlEncode(ex.Message)
          lblResults.Visible = True
        End Try
      Else
        lbxAvailableRoles.SelectedIndex = -1
      End If
      
    End If
  End Sub
  
  
  Sub btnDeleteUserFromRole_Click(ByVal sender As Object, ByVal e As System.EventArgs)
    Dim selectedRole As String = lbxUserRoles.SelectedValue

    If (lbxUserRoles.SelectedIndex <> -1) Then
      Try
        Roles.RemoveUserFromRole(User.Identity.Name, selectedRole)
        RefreshCurrentRolesListBox()
      Catch ex As Exception
        lblResults.Text = "Could not remove the user from the role: " + Server.HtmlEncode(ex.Message)
        lblResults.Visible = True
      End Try
    End If
  End Sub
  
  
  Sub Page_Init(ByVal sender As Object, ByVal e As System.EventArgs)
    RefreshAvailableRolesListBox()
    RefreshCurrentRolesListBox()
  End Sub
  
  Private Sub RefreshAvailableRolesListBox()
    lbxAvailableRoles.SelectedIndex = -1
    lbxAvailableRoles.DataSource = Roles.GetAllRoles()
    lbxAvailableRoles.DataBind()
    If (lbxAvailableRoles.Items.Count = 0) Then
      lblRoleInfoText.Text = "There are currently no roles for this application."
      lbxAvailableRoles.Visible = False
      btnAddUserToRole.Visible = False
    Else
      lblRoleInfoText.Text = "The list of available roles is shown below."
      lbxAvailableRoles.Visible = True
      btnAddUserToRole.Visible = True
    End If
  End Sub
    
  Private Sub RefreshCurrentRolesListBox()
    lbxUserRoles.SelectedIndex = -1

    'Could also call Roles.GetRolesForUser();
    lbxUserRoles.DataSource = (CType(User,RolePrincipal)).GetRoles()
    lbxUserRoles.DataBind()

    If (lbxUserRoles.Items.Count = 0)
      lblUserRoleInfoText.Text = "The user currently does not belong to any roles."
      lbxUserRoles.Visible = false
      btnDeleteUserFromRole.Visible = false
    Else
      lblUserRoleInfoText.Text = "The user is a member of the following roles."
      lbxUserRoles.Visible = true
      btnDeleteUserFromRole.Visible = true
    End If

  End Sub
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
