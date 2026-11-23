<%@ Import Namespace="System.Data" %>
<%@ Import Namespace="System.Data.SqlClient" %>

<html>

<body topmargin="0" leftmargin="0" marginwidth="0" marginheight="0">

  <!-- #include virtual="header.inc" -->

  <ASP:DataList id="MyDataList" DataSourceID="SqlDataSource1" RepeatColumns="2" runat="server">

      <ItemTemplate>

        <table cellpadding=10 style="font: 10pt verdana">
          <tr>
            <td width=1 bgcolor="BD8672"/>

            <td valign="top">
              <img alt="book image" align="top" src='<%# DataBinder.Eval(Container.DataItem, "title_id", "images/{0}.gif") %>' >
            </td>

            <td valign="top">

              <b>Title: </b><%# DataBinder.Eval(Container.DataItem, "title") %><br>
              <b>Category: </b><%# DataBinder.Eval(Container.DataItem, "type") %><br>
              <b>Publisher ID: </b><%# DataBinder.Eval(Container.DataItem, "pub_id") %><br>
              <b>Price: </b><%# DataBinder.Eval(Container.DataItem, "price", "$ {0}") %>

              <p>

              <a href='<%# DataBinder.Eval(Container.DataItem, "title_id", "purchase_vb.aspx?titleid={0}") %>' >
                <img alt="purchase book" border="0" src="images/purchase_book.gif" >
              </a>

            </td>
          </tr>
        </table>

      </ItemTemplate>

  </ASP:DataList>
  
  <asp:SqlDataSource ConnectionString="<%$ ConnectionStrings:Pubs %>" ID="SqlDataSource1"
  runat="server" SelectCommand="SELECT * FROM [titles]"/>

  <!-- #include virtual="footer.inc" -->

</body>
</html>
