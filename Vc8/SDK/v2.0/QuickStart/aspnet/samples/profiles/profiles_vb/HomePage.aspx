<%@ Page Language="VB" %>
<%@ Import Namespace="System.Drawing" %>

<script runat="server">
  Sub Page_Load(ByVal sender As Object, ByVal e As System.EventArgs)
    If ((Not Page.IsPostBack) And (Profile.PreferredBackgroundColor.IsKnownColor)) Then
      ddlColor.SelectedValue = Profile.PreferredBackgroundColor.ToKnownColor().ToString()
      styleContainer.Style.Add(HtmlTextWriterStyle.BackgroundColor, Profile.PreferredBackgroundColor.ToKnownColor().ToString())
    End If

    ToggleViewForAuthenticatedUsers()
  End Sub
  
  Sub btnUpdatePreferences_Click(ByVal sender As Object, ByVal e As System.EventArgs)
    Profile.PreferredBackgroundColor = Color.FromName(ddlColor.SelectedValue)

    Response.Redirect(Request.Url.LocalPath)
  End Sub
  
  Sub ToggleViewForAuthenticatedUsers()
    If (Request.IsAuthenticated) Then
      lblName.Text = IIf(Not String.IsNullOrEmpty(Profile.Name), Server.HtmlEncode(Profile.Name), "(You have not set your name yet!)")
      Login1.Visible = False
      linkLoggedInUser.Visible = True
      lblIndicator.Text = "You are currently logged in.  Updates to color will be saved<br /> to the Profile associated with the authenticated user."
    Else
      Login1.Visible = True
      lblName.Text = "Anonymous User"
      lblIndicator.Text = "You are not logged in.  Updates to color will be saved to the Profile associated with an anonymous user.<br />The code in global.asax will automatically migrate the background<br />color preference to your authenticated profile once you choose to log in."
    End If
  End Sub
</script>

<html>
  <head id="Head1" runat="server">
      <title>Home Page - Uses Authenticated or Anonymous Profile</title>
  </head>
  <body>
      <form id="form1" runat="server">
      <div id="styleContainer" runat=server>
        <h1>Hello <asp:Label Runat=Server ID="lblName" /></h1>
        Enter your preferred background color:
	      <asp:dropdownlist id="ddlColor" runat="server">
	        <asp:ListItem>Aqua</asp:ListItem>	      
	        <asp:ListItem>Blue</asp:ListItem>	        
	        <asp:ListItem>Fuchsia</asp:ListItem>	        
	        <asp:ListItem>Lime</asp:ListItem>
	        <asp:ListItem>Red</asp:ListItem>
	        <asp:ListItem>Silver</asp:ListItem>	    	        
	        <asp:ListItem>Teal</asp:ListItem>	        
	        <asp:ListItem>Yellow</asp:ListItem>
	      </asp:dropdownlist>
        <br />
        <asp:button id="btnUpdatePreferences" runat="server" text="Click to update background color" onclick="btnUpdatePreferences_Click"  />
        <br />        
        <br />
        <asp:Label id="lblIndicator" runat=Server />  
        <br />
        <br />
        <hr />
        <div align=center>
          <asp:Login ID="Login1" Runat="server" CreateUserText="<br />Click here to create a new user for <br />the Profile QuickStart" CreateUserUrl="CreateNewUser.aspx" BorderWidth="1px" BorderColor="#CCCC99" BorderPadding="0" BorderStyle="Solid" BackColor="#F7F7DE" Font-Names="Verdana" Font-Size="10pt" DisplayRememberMe="False" TitleText="Log In to Profile QuickStart" >
            <InstructionTextStyle Font-Italic="False"></InstructionTextStyle>
            <TitleTextStyle Font-Bold="True" BackColor="#6B696B" ForeColor="#FFFFFF"></TitleTextStyle>
          </asp:Login>  
          <br />
          <br />
          <asp:LoginStatus ID="LoginStatus1" Runat="server" LogoutText="Click here to logout." LogoutAction="RedirectToLoginPage" LoginText="Use the login control above to log back in." />
          <br />
          <br /> 
          <asp:LinkButton ID="linkLoggedInUser" PostBackUrl="secured/ProfileProperties.aspx" Runat="server" Visible=false>Click here to display all of your Profile properties.</asp:LinkButton>
        </div>
      </div>
      </form>
  </body>
</html>
