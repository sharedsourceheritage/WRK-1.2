<%@ Page Language="VB" Theme="MyTheme" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<script runat="server">

</script>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
  <title>Data Binding in Themes</title>
</head>
<body>
  <form id="form1" runat="server">
    <div>
      <h2>Data Binding in Themes</h2>
      <asp:DataList DataKeyField="title_id" DataSourceID="SqlDataSource1" ID="DataList1"
        runat="server" />
      <asp:SqlDataSource ConnectionString="<%$ ConnectionStrings:Pubs %>" ID="SqlDataSource1"
        runat="server" SelectCommand="SELECT [title_id], [title], [type], [price], [notes] FROM [titles]">
      </asp:SqlDataSource>
    </div>
  </form>
</body>
</html>
