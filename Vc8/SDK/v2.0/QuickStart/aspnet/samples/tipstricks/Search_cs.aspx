<%@ Page Language="C#" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
  <title>Search Page</title>
</head>
<script language="C#" runat="server">

  void Page_Load(object sender, EventArgs e)
  {
    TextBox SearchTerm;

    SearchTerm = (TextBox)Page.PreviousPage.FindControl("SearchTerm");
    Label1.Text = SearchTerm.Text;
  }

</script>
<body>
  <form id="form1" runat="server">
    <div>
      <span style="font-size: 32pt; color: #ff0066">Search Page (Search_cs.aspx)</span><br />
    </div>
    <div>
      <hr />
    </div>
    <div>
      <span style="font-size: 16pt">You searched for: </span>
      <asp:Label ID="Label1" runat="server" Text="Label" Font-Size="16pt" ForeColor="#FF0066"
        Font-Italic="True" /><span style="font-size: 16pt"> </span>
    </div>
    <span style="font-size: 32pt"></span>
    <p>
      <br />
    </p>
  </form>
</body>
</html>
