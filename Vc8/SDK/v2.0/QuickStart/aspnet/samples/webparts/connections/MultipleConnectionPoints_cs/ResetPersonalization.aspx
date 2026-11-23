<%@ Page Language="C#" %>
<script runat="server">

    void PerUserDataReset_Click(object sender, EventArgs e)
    {
       if (PersonalizationAdministration.ResetUserState("~/Default.aspx", Page.User.Identity.Name))
            Result.Text ="Data for user : " + Page.User.Identity.Name + " has been reset sucessfully";
        else
            Result.Text ="Data for user : " + Page.User.Identity.Name + " has NOT been reset";
           
        Result.Visible = true;
    }
    void SharedDataReset_Click(object sender, EventArgs e)
    {
       if ( PersonalizationAdministration.ResetSharedState("~/Default.aspx"))
            Result.Text ="Shared Data for page Default_CS.aspx has been reset sucessfully";
        else
            Result.Text ="Shared Data for page Default_CS.aspx has NOT been reset";
           
        Result.Visible = true;
    }
    
</script>
<html>
  <head runat="server">
    <title>Reset Personalization</title>
  </head>
  <body>
    <form id="form1" runat="server">
      <div>
        This page allows you to reset the personalization data
      </div>
      <div>
        <table>
          <tr>
            <td>
              <asp:Label ID="Label1" Runat="server" Text="Reset PerUser Data "/>
            </td>
            <td>
              <asp:Button ID="PerUserDataReset" Runat="server" Text="Reset My Data" OnClick="PerUserDataReset_Click" />
            </td>
          </tr>
          <tr>
            <td>
              <asp:Label ID="Label2" Runat="server" Text="Reset Shared Data "/>
            </td>
            <td>
              <asp:Button ID="SharedDataReset" Runat="server" Text="Reset  Data for Share Mode"
                OnClick="SharedDataReset_Click" />
            </td>
          </tr>
        </table>
      </div>
      <div>
        <asp:Label ID="Result" Runat="server" Text="Label" Visible="False" EnableViewState="False"/>
      </div>
      <div>
        <asp:Label ID="Label3" Text='Click <a href="default.aspx">here </a> to return to the Default Page'
          Runat="server"/>
      </div>
    </form>
  </body>
</html>
