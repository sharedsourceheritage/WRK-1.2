<%@ Page Language="C#" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<script runat="server">

  public String myVariable = "Databound";

  protected void Page_Load(object sender, EventArgs e)
  {
    if (!Page.IsPostBack)
      Label2.DataBind();
  }
</script>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
  <title>Databinding a Label</title>
</head>
<body>
  <form id="form1" runat="server">
    <div>
      <h2>Databinding a Label</h2>
      <b>In a templated data-bound control...</b><br />
      <br />
      <asp:FormView ID="FormView1" runat="server" DataSourceID="SqlDataSource1">
        <ItemTemplate>
          <asp:Label ID="Label1" runat="server" Text='<%# Eval("au_lname") %>' />
        </ItemTemplate>
      </asp:FormView>
      <asp:SqlDataSource ConnectionString="<%$ ConnectionStrings:Pubs %>" ID="SqlDataSource1"
        runat="server" SelectCommand="SELECT [au_lname] FROM [authors] where [au_id] = '409-56-7008'">
      </asp:SqlDataSource>
      <br />
      <b>In the page...</b><br />
      <br />
      <asp:Label ID="Label2" runat="server" Text='<%# myVariable %>' />
    </div>
  </form>
</body>
</html>
