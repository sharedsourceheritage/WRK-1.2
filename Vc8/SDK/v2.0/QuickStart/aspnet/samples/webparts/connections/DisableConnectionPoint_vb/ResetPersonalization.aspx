<%@ Page Language="VB" %>
<script runat="server">

  Sub PerUserDataReset_Click(ByVal sender As Object, ByVal e As EventArgs)
    
    If (PersonalizationAdministration.ResetUserState("~/Default.aspx", Page.User.Identity.Name)) Then
      Result.Text = "Data for user : " & Page.User.Identity.Name & " has been reset sucessfully"
    Else
      Result.Text = "Data for user : " & Page.User.Identity.Name & " has NOT been reset"
      Result.Visible = True
    End If
  End Sub
  
  Sub SharedDataReset_Click(ByVal sender As Object, ByVal e As EventArgs)
    
    If (PersonalizationAdministration.ResetSharedState("~/Default.aspx")) Then
      Result.Text = "Shared Data for page Default_CS.aspx has been reset sucessfully"
    Else
      Result.Text = "Shared Data for page Default_CS.aspx has NOT been reset"           
      Result.Visible = True
    End If
  End Sub
    
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
