<%@ Page Language="VB" %>
<html>
  <head runat="server">
    <title>FormView</title>
  </head>
  <body>
    <form id="form1" runat="server">
      <asp:FormView ID="FormView1" Runat="server" DataSourceID="SqlDataSource1"
        HeaderText="Books for Author" AllowPaging="True">
        <ItemTemplate>
          <table>
            <tr>
              <td valign="top">
                <asp:Image ID="Image1" ImageUrl='<%# Eval("title_id","~/Images/{0}.gif") %>' Runat="server" />
              </td>
              <td valign="top">
                <asp:Label ID="Label1" Font-Size="1.2em" Font-Bold="true" Text='<%# Eval("title") %>' runat="server" />
                <br/>
                <asp:Label ID="Label2" Text='<%# Eval("price","{0:c}") %>' runat="server" />
              </td>
            </tr>
          </table>
        </ItemTemplate>
      </asp:FormView>
      <asp:SqlDataSource ID="SqlDataSource1" Runat="server" SelectCommand="SELECT dbo.authors.au_id, dbo.titles.title_id, dbo.titles.title, dbo.titles.type, dbo.titles.price, dbo.titles.notes FROM dbo.authors INNER JOIN dbo.titleauthor ON dbo.authors.au_id = dbo.titleauthor.au_id INNER JOIN dbo.titles ON dbo.titleauthor.title_id = dbo.titles.title_id WHERE (dbo.authors.au_id = @au_id)"
        ConnectionString="<%$ ConnectionStrings:Pubs %>">
        <SelectParameters>
          <asp:QueryStringParameter Name="au_id" DefaultValue="213-46-8915" QueryStringField="ID" />
        </SelectParameters>
      </asp:SqlDataSource>
    </form>
  </body>
</html>
