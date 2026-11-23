<%@ Page Language="C#" %>
<html>
  <head runat="server">
    <title>DetailsView</title>
  </head>
  <body>
    <form id="form1" runat="server">
      <asp:DetailsView ID="DetailsView1" Runat="server" DataSourceID="SqlDataSource1" AutoGenerateRows="False"
        HeaderText="Books for Author" AllowPaging="True">
        <Fields>
          <asp:BoundField HeaderText="au_id" DataField="au_id" SortExpression="au_id" />
          <asp:BoundField HeaderText="title_id" DataField="title_id" SortExpression="title_id" />
          <asp:BoundField HeaderText="title" DataField="title" SortExpression="title" />
          <asp:BoundField HeaderText="type" DataField="type" SortExpression="type" />
          <asp:BoundField HeaderText="price" DataField="price" SortExpression="price" />
          <asp:BoundField HeaderText="notes" DataField="notes" SortExpression="notes" />
        </Fields>
      </asp:DetailsView>
      <asp:SqlDataSource ID="SqlDataSource1" Runat="server" SelectCommand="SELECT dbo.authors.au_id, dbo.titles.title_id, dbo.titles.title, dbo.titles.type, dbo.titles.price, dbo.titles.notes FROM dbo.authors INNER JOIN dbo.titleauthor ON dbo.authors.au_id = dbo.titleauthor.au_id INNER JOIN dbo.titles ON dbo.titleauthor.title_id = dbo.titles.title_id WHERE (dbo.authors.au_id = @au_id)"
        ConnectionString="<%$ ConnectionStrings:Pubs %>">
        <SelectParameters>
          <asp:QueryStringParameter Name="au_id" DefaultValue="213-46-8915" QueryStringField="ID" />
        </SelectParameters>
      </asp:SqlDataSource>
    </form>
  </body>
</html>
