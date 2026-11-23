<%@ Page Language="C#" %>
<html>
<head runat="server">
  <title>GridView Bound to SqlDataSource</title>
</head>
<body>
  <form id="form1" runat="server">
    <asp:GridView ID="GridView1" DataSourceID="SqlDataSource1" runat="server" />
    <asp:SqlDataSource ID="SqlDataSource1" runat="server" 
      SelectCommand="SELECT [au_id], [au_lname], [au_fname], [phone], [address], [city], [state], [zip], [contract] FROM [authors]"
      ConnectionString="<%$ ConnectionStrings:Pubs %>" />
  </form>
</body>
</html>
