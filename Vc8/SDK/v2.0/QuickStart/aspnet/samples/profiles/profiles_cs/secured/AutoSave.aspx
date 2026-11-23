<%@ Page Language="C#" %>
<%@ Import Namespace="System.Drawing" %>

<script runat="server">
    protected void btnCancelAutoSave_Click(object sender, EventArgs e)
    {
        Context.Items["CancelProfileAutoSave"] = true;
        Response.Redirect(Request.Url.LocalPath); 
    }
      
    void btnUpdatePreferences_Click(object sender, EventArgs e)
    {
      Profile.Name = txtName.Text;

      int pricePoint = 0;
      bool parseResult = Int32.TryParse(txtPricePoint.Text,out pricePoint);

      Profile.AutomobilePreferences.PricePoint = pricePoint;

      Color colorPreference = Color.FromName(ddlColor.SelectedValue);
      if (colorPreference.IsKnownColor)
        Profile.PreferredBackgroundColor = colorPreference;
      else
        Profile.PreferredBackgroundColor = Color.Empty;

      if (txtFavoriteModels.Text != String.Empty)
      {
        string[] carModels = txtFavoriteModels.Text.Split(";".ToCharArray());
        ArrayList modelsList = new ArrayList();
        foreach (string carModel in carModels)
        {
          modelsList.Add(carModel);
        }

        Profile.AutomobilePreferences.CarModels = modelsList;
      }
      else
        Profile.AutomobilePreferences.CarModels = null;
        
      Profile.JunkFood.Clear();
      foreach (ListItem item in lbxMunchies.Items)
      {
          if (item.Selected == true)
              Profile.JunkFood.Add(item.Value);
      }

      Response.Redirect(Request.Url.LocalPath);
    }
  
    void Page_Load(object sender, EventArgs e)
    {    
        if (!Page.IsPostBack)
        {
          if (Profile.PreferredBackgroundColor.IsKnownColor)
          {
            styleContainer.Style.Add(HtmlTextWriterStyle.BackgroundColor, Profile.PreferredBackgroundColor.ToKnownColor().ToString());
            ddlColor.SelectedValue = Profile.PreferredBackgroundColor.ToKnownColor().ToString();
          }
          
          txtName.Text = Server.HtmlEncode(Profile.Name);
          txtPricePoint.Text = Profile.AutomobilePreferences.PricePoint.ToString();

          System.Text.StringBuilder sb = new System.Text.StringBuilder();
          if (Profile.AutomobilePreferences.CarModels != null)
          {
            foreach (string carModel in Profile.AutomobilePreferences.CarModels)
            {
                  sb.Append(carModel + ";");
              }
          }
          txtFavoriteModels.Text = (sb.Length > 0) ? Server.HtmlEncode(sb.ToString().Substring(0, sb.Length - 1)) : String.Empty;

          foreach (string item in Profile.JunkFood)
          {
              lbxMunchies.Items.FindByValue(item).Selected = true;
          }  
        }
    }

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
                        <asp:button id="btnCancelAutoSave" runat="server" text="Clicking this Button Cancels Automatic Saves" OnClick="btnCancelAutoSave_Click"  />
                    </td>
                </tr>
            </table>
        </div>
            <br />
            <br />
            Clicking on the cancel button refreshes the page.  However, 
            <br />
            none of the properties are updated because the automatic Profile
            <br />
            save was cancelled.
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
