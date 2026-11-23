<%@ Import Namespace="System.Data" %>
<%@ Import Namespace="System.Data.SqlClient" %>

<html>

<body topmargin="0" leftmargin="0" marginwidth="0" marginheight="0">

  <!-- #include virtual="header.inc" -->

  <ASP:Repeater id="MyRepeater" runat="server" DataSourceID="SqlDataSource1">

      <HeaderTemplate>

        <table width="100%" style="font: 8pt verdana">
          <tr style="background-color:DFA894">
            <th>
              Title
            </th>
            <th>
              Title ID
            </th>
            <th>
              Type
            </th>
            <th>
              Publisher ID
            </th>
            <th>
              Price
            </th>
          </tr>

      </HeaderTemplate>

      <ItemTemplate>

        <tr style="background-color:FFECD8">
          <td>
            <%# DataBinder.Eval(Container.DataItem, "title") %>
          </td>
          <td>
            <%# DataBinder.Eval(Container.DataItem, "title_id") %>
          </td>
          <td>
            <%# DataBinder.Eval(Container.DataItem, "type") %>
          </td>
          <td>
            <%# DataBinder.Eval(Container.DataItem, "pub_id") %>
          </td>
          <td>
            <%# DataBinder.Eval(Container.DataItem, "price", "$ {0}") %>
          </td>
        </tr>

      </ItemTemplate>

      <FooterTemplate>

        </table>

      </FooterTemplate>

  </ASP:Repeater>
  <asp:SqlDataSource ConnectionString="<%$ ConnectionStrings:Pubs %>" ID="SqlDataSource1"
    runat="server" SelectCommand="SELECT * FROM [titles]"/>

  <!-- #include virtual="footer.inc" -->

</body>
</html>
