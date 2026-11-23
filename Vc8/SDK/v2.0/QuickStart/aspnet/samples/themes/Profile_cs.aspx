<%@ Page Language="C#" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<script runat="server">

  protected void Page_Load(Object sender, System.EventArgs e) {

    if (!Page.IsPostBack && Profile.FavoriteColor != "")
      DropDownList1.DataBind();
  }

  protected void Button1_Click(object sender, EventArgs e)
  {
    Profile.FavoriteColor = DropDownList1.SelectedValue;
    Response.Redirect("ProfileTheme_cs.aspx");
  }
</script>
<html>
<head id="Head1" runat="server">
  <title>Profile Page</title>
</head>
<body>
  <form id="Form1" runat="server">
    <h2>
      Profile Page</h2>
    
      <b>Favorite Color:</b> 
      <asp:DropDownList ID="DropDownList1" SelectedValue='<%# Profile.FavoriteColor %>' runat="server">
        <asp:ListItem Value="OrangeTheme">Orange</asp:ListItem>
        <asp:ListItem Value="GreenTheme">Green</asp:ListItem>
      </asp:DropDownList>
    <br />
    <br />
    
    <asp:Button ID="Button1" runat="server" Text="Submit" OnClick="Button1_Click" />
  </form>
</body>
</html>
