<%@ Page Language="C#" %>
<%@ Import Namespace="System.Drawing" %>

<script runat="server">
  void Page_Load(object sender, EventArgs e)
  {
    if (!Page.IsPostBack)
    {
      if (Profile.PreferredBackgroundColor != Color.Empty)
        ddlColor.SelectedValue = Profile.PreferredBackgroundColor.ToKnownColor().ToString();
      styleContainer.Style.Add(HtmlTextWriterStyle.BackgroundColor, Profile.PreferredBackgroundColor.ToKnownColor().ToString());
    }
  }

  void btnUpdatePreferences_Click(object sender, EventArgs e)
  {
    Profile.PreferredBackgroundColor = Color.FromName(ddlColor.SelectedValue);

    Response.Redirect(Request.Url.LocalPath);
  }
</script>

<html>
  <head runat="server">
      <title>Setting Anonymous Profile Values</title>
  </head>
  <body>
      <form id="form1" runat="server">
      <div id="styleContainer" runat=server>
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
        <asp:Label id="lblIndicator" runat=Server />
      </div>
      </form>
  </body>
</html>
