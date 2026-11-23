<%@ Page Language="VB" %>
<%@ Import Namespace="System.Drawing" %>
<%@ Import Namespace="System.Collections.Generic" %>

<script runat="server">
  Sub btnUpdatePreferences_Click(ByVal sender As Object, ByVal e As System.EventArgs)
    Profile.Name = txtName.Text

    If IsNumeric(txtPricePoint.Text) Then
      Profile.AutomobilePreferences.PricePoint = CInt(txtPricePoint.Text)
    Else
      Profile.AutomobilePreferences.PricePoint = 0
    End If

    Dim colorPreference As Color = Color.FromName(ddlColor.SelectedValue)
    
    If (colorPreference.IsKnownColor) Then
      Profile.PreferredBackgroundColor = colorPreference
    Else
      Profile.PreferredBackgroundColor = Color.Empty
    End If

    If (txtFavoriteModels.Text <> String.Empty) Then
      Dim carModels() As String = txtFavoriteModels.Text.Split(";".ToCharArray())
      Dim modelsList As ArrayList = New ArrayList()
      
      For Each carModel As String In carModels
        modelsList.Add(carModel)
      Next

      Profile.AutomobilePreferences.CarModels = modelsList
    Else
      Profile.AutomobilePreferences.CarModels = Nothing
    End If

    if Not Profile.JunkFood Is Nothing Then
      Profile.JunkFood.Clear()
    Else
      Profile.JunkFood = new List(Of String)()
    End If

    For Each item as ListItem in lbxMunchies.Items
        If (item.Selected = true)
             Profile.JunkFood.Add(item.Value)
        End If 
    Next
 
    Response.Redirect(Request.Url.LocalPath)
  End Sub
  
  Sub Page_Load(ByVal sender As Object, ByVal e As System.EventArgs)
    If Not Page.IsPostBack Then
      If (Profile.PreferredBackgroundColor.IsKnownColor) Then
        styleContainer.Style.Add(HtmlTextWriterStyle.BackgroundColor, Profile.PreferredBackgroundColor.ToKnownColor().ToString())
        ddlColor.SelectedValue = Profile.PreferredBackgroundColor.ToKnownColor().ToString()
      End If

      txtName.Text = Server.HtmlEncode(Profile.Name)
      txtPricePoint.Text = Profile.AutomobilePreferences.PricePoint.ToString()

      Dim sb As System.Text.StringBuilder = New System.Text.StringBuilder()
      If Not Profile.AutomobilePreferences.CarModels Is Nothing Then
        For Each carModel As String In Profile.AutomobilePreferences.CarModels
          sb.Append(carModel + ";")
        Next
      End If
      
      If sb.Length > 0 Then
        txtFavoriteModels.Text = Server.HtmlEncode(sb.ToString().Substring(0, sb.Length - 1))
      Else
        txtFavoriteModels.Text = String.Empty
      End If

      If Not Profile.JunkFood Is Nothing Then
         For Each item as string in Profile.JunkFood
             lbxMunchies.Items.FindByValue(item).Selected = true
         Next
      End If
       
    End If
  End Sub
</script>

<html>
  <head id="Head1" runat="server">
      <title>View and Change your Profile Properties</title>
  </head>
  <body>
      <form id="form1" runat="server">
        <div id="styleContainer" runat=server>
            <table id="tblLogin" cellspacing="0" cellpadding="0" >
                <tr align=center>
                    <td colspan="2" style="border-top: black thin solid;border-right: black thin solid;border-left: black thin solid">
                        <b><span style="text-decoration: underline">Profile Values</span></b></td>
                </tr>
                <tr>
                    <td width="40%" class="lcol">
                        What is your name?</td>
                    <td class=rcol>
                        <asp:textbox id="txtName" runat="server" width="100%"></asp:textbox>
                    </td>
                </tr>
                <tr>
                    <td width="40%" class="lcol">
                        Preferred background color:</td>
                    <td class=rcol>
                        Enter your preferred background color:
	                      <asp:dropdownlist id="ddlColor" runat="server">
	                        <asp:ListItem>&nbsp;</asp:ListItem>
	                        <asp:ListItem>Aqua</asp:ListItem>	      
	                        <asp:ListItem>Blue</asp:ListItem>	        
	                        <asp:ListItem>Fuchsia</asp:ListItem>	        
	                        <asp:ListItem>Lime</asp:ListItem>
	                        <asp:ListItem>Red</asp:ListItem>
	                        <asp:ListItem>Silver</asp:ListItem>	    	        
	                        <asp:ListItem>Teal</asp:ListItem>	        
	                        <asp:ListItem>Yellow</asp:ListItem>
	                      </asp:dropdownlist>
                    </td>
                </tr>                              
                <tr>
                    <td width="40%" class="lcol">
                        Maximum automobile price point:</td>
                    <td class=rcol>
                        <asp:textbox id="txtPricePoint" runat="server" width="100%"></asp:textbox>
                    </td>
                </tr>
                <tr>
                    <td width="40%" class="lcol">
                        Favorite Car Models (delimited by semi-colons):</td>
                    <td class=rcol>
                        <asp:textbox id="txtFavoriteModels" runat="server" width="100%"></asp:textbox>
                    </td>
                </tr>   
                <tr>
                    <td width="40%" class="lcol">
                        Favorite Junk Food:</td>                
                    <td align="center" class="rcol" >
                        <asp:ListBox ID="lbxMunchies" runat="server" SelectionMode=Multiple>
                          <asp:ListItem Value="HD" Text="Hot Dogs" />
                          <asp:ListItem Value="CH" Text="Cheeseburgers" />
                          <asp:ListItem Value="TC" Text="Tacos" />
                          <asp:ListItem Value="IC" Text="Ice Cream" /> 
                        </asp:ListBox>
                    </td>
                </tr>                             
                <tr>
                    <td align="center" colspan="2"   class="lcol" style="border-bottom: black thin solid">
                        &nbsp;<asp:button id="btnUpdatePreferences" runat="server" text="Update Preferences" onclick="btnUpdatePreferences_Click"  />
                    </td>
                </tr>
            </table>
        </div>
            <br />
            <br />
            After typing in property values, and clicking the update button,
            <br />
            logout of the application and log back in again.  You will see that
            <br />
            the profile values have been retained.
            <br />
            <br />
            <hr />
            <div align=center>
              <asp:LoginStatus ID="LoginStatus1" Runat="server" LogoutText="Click here to logout." LogoutAction="RedirectToLoginPage" />
              <br />
              <br />
              <a href="../HomePage.aspx">Click here to go to the home page.</a>
            </div>
      </form>
  </body>
</html>
