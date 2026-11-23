<%@ page language="C#" EnableViewState="false" %>

<script runat="server">
    void btnCreateRole_Click(object sender, EventArgs e)
    {
      string roleName = txtCreateRole.Text;
      
      try
      {
        Roles.CreateRole(roleName);

        lblResults.Text = null;
        lblResults.Visible = false;

        txtCreateRole.Text = null;
      }
      catch (Exception ex)
      {
        lblResults.Text = "Could not create the role: " + Server.HtmlEncode(ex.Message);
        lblResults.Visible = true;
      }

      RefreshAvailableRolesListBox();
    }      
     
    void btnDeleteRole_Click(object sender, EventArgs e)
    {
        if (lbxAvailableRoles.SelectedIndex != -1)
        {
          try
          {
            Roles.DeleteRole(lbxAvailableRoles.SelectedValue);

            lblResults.Text = null;
            lblResults.Visible = false;
          }
          catch (Exception ex)
          {
            lblResults.Text = "Could not delete the role: " + Server.HtmlEncode(ex.Message);
            lblResults.Visible = true;
          }
        }

        RefreshAvailableRolesListBox();
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
          btnDeleteRole.Visible = false;
        }
        else
        {
          lblRoleInfoText.Text = "The list of available roles is shown below.";
          lbxAvailableRoles.Visible = true;
          btnDeleteRole.Visible = true;
        }
      }

    void Page_Load(object sender, EventArgs e)
    {
      if (!Page.IsPostBack)
      {
        if (!Roles.RoleExists("Administrators"))
        {
          txtCreateRole.Text = "Administrators";
        }
      }
    }

    void Page_Init(object sender, EventArgs e)
    {
      RefreshAvailableRolesListBox();
    }  
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


