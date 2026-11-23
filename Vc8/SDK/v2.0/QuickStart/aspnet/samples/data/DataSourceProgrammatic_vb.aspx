<%@ Page Language="VB" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">

  Protected Sub Page_Load(ByVal sender As Object, ByVal e As System.EventArgs)
    Dim s As New SqlDataSource
    s.ConnectionString = ConfigurationManager.ConnectionStrings("Pubs").ConnectionString
    s.SelectCommand = "SELECT [title_id], [title], [type], [price], [notes] FROM [titles]"
    DataList1.DataSource = s
    DataList1.DataBind()
  End Sub

</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
      <asp:DataList DataKeyField="title_id" ID="DataList1"
        runat="server" Width="868px">
        <ItemTemplate>
          <table width="100%" cellpadding="10">
            <tr>
              <td valign="top" width="10%">
                <asp:Image ID="Image1" ImageUrl='<%# Eval("title_id", "Images/{0}.gif") %>' runat="server" />
              </td>
              <td valign="top">
                <asp:Label Font-Size="18pt" ID="titleLabel" runat="server" Text='<%# Eval("title") %>'></asp:Label><br />
                <strong>ID:</strong>
                <asp:Label ID="title_idLabel" runat="server" Text='<%# Eval("title_id") %>'></asp:Label><br />
                <strong>Type:</strong>
                <asp:Label ID="typeLabel" runat="server" Text='<%# Eval("type") %>'></asp:Label><br />
                <strong>Price:</strong>
                <asp:Label ID="priceLabel" runat="server" Text='<%# Eval("price") %>'></asp:Label><br />
                <strong>Notes:</strong>
                <asp:Label ID="notesLabel" runat="server" Text='<%# Eval("notes") %>'></asp:Label></td>
              </td>
            </tr>
          </table>
        </ItemTemplate>
      </asp:DataList>
    
    </div>
    </form>
</body>
</html>
