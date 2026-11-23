<%@ Page Language="VB" %>

<script runat="server">
  Sub btnCreateRole_Click(ByVal sender As Object, ByVal e As System.EventArgs)
    Dim roleName As String = txtCreateRole.Text
      
    Try
      Roles.CreateRole(roleName)

      lblResults.Text = Nothing
      lblResults.Visible = False

      txtCreateRole.Text = Nothing
    Catch ex As Exception
      lblResults.Text = "Could not create the role: " + Server.HtmlEncode(ex.Message)
      lblResults.Visible = True
    End Try

    RefreshAvailableRolesListBox()
  End Sub

  Sub btnDeleteRole_Click(ByVal sender As Object, ByVal e As System.EventArgs)
    If (lbxAvailableRoles.SelectedIndex <> -1) Then
      Try
        Roles.DeleteRole(lbxAvailableRoles.SelectedValue)

        lblResults.Text = Nothing
        lblResults.Visible = False
      Catch ex As Exception
        lblResults.Text = "Could not delete the role: " + Server.HtmlEncode(ex.Message)
        lblResults.Visible = True
      End Try
    End If

    RefreshAvailableRolesListBox()
  End Sub

  Private Sub RefreshAvailableRolesListBox()
    lbxAvailableRoles.SelectedIndex = -1
    lbxAvailableRoles.DataSource = Roles.GetAllRoles()
    lbxAvailableRoles.DataBind()

    If (lbxAvailableRoles.Items.Count = 0) Then
      lblRoleInfoText.Text = "There are currently no roles for this application."
      lbxAvailableRoles.Visible = False
      btnDeleteRole.Visible = False
    Else
      lblRoleInfoText.Text = "The list of available roles is shown below."
      lbxAvailableRoles.Visible = True
      btnDeleteRole.Visible = True
    End If
  End Sub
  
  Sub Page_Init(ByVal sender As Object, ByVal e As System.EventArgs)
    RefreshAvailableRolesListBox()
  End Sub
  
  Sub Page_Load(ByVal sender As Object, ByVal e As System.EventArgs)
    If Not Page.IsPostBack Then
      If Not Roles.RoleExists("Administrators") Then
        txtCreateRole.Text = "Administrators"
      End If
    End If 
  End Sub
</script>

<html>
  <head id="Head1" runat="server">
      <title>Create and Delete Roles</title>
  </head>
  <body>
      <form id="form1" runat="server">
        <table id="Table1" cellspacing="1" cellpadding="1" style="border-right: black thin solid; border-top: black thin solid; border-left: black thin solid; border-bottom: black thin solid">
            <tr>
                <td>
                    <b>Enter the name of a new role:</b>
                </td>
                <td>
                  <asp:textbox id="txtCreateRole" runat="server"></asp:textbox>
                </td>
            </tr>
            <tr>
                <td colspan=2 style="TEXT-ALIGN: center;">
                    <asp:button id="btnCreateRole" runat="server" text="Create Role" onclick="btnCreateRole_Click" />
                </td>
            </tr>
            <tr>
              <td>&nbsp;</td>
            </tr>
            <tr>
                <td colspan=2 style="TEXT-ALIGN: center;">
                    <b><asp:label id="lblRoleInfoText" runat="server" Visible=true /></b>
                </td>
            </tr>
            <tr>
                <td colspan=2 style="TEXT-ALIGN: center;">
                    <asp:listbox id="lbxAvailableRoles" runat="server">
                    </asp:listbox>
                </td>
            </tr>
            <tr>
                <td>&nbsp;</td>
            </tr>
            <tr>
                <td colspan=2 style="TEXT-ALIGN: center;">
                    <asp:button id="btnDeleteRole" runat="server" text="Delete Selected Role" onclick="btnDeleteRole_Click" />
                </td>
            </tr>
        </table>
        <br />
        <br />
        <asp:label id="lblResults" runat="server" Visible=false ForeColor=Red>Results:</asp:label>
        <br />
        <a href="Add_Delete_UserRoles.aspx">Click here to manage roles for the logged in user.</a>
        <br />
        <small>(Note: For the sample pages that demonstrate authorization, you will need to add roles called "Administrators", "Regular Users", and "Power Users".).</small>
      </form>
  </body>
</html>