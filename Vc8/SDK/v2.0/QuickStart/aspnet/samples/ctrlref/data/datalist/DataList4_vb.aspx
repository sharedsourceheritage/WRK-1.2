<%@ Import Namespace="System.Data" %>
<%@ Import Namespace="System.Data.SqlClient" %>

<html>

<body topmargin="0" leftmargin="0" marginwidth="0" marginheight="0">

  <!-- #include virtual="header.inc" -->

  <asp:DataList id="MyDataList" DataSourceID="SqlDataSource1" RepeatColumns="2" RepeatDirection="Horizontal" runat="server">

      <ItemTemplate>

        <div style="padding:15,15,15,15;font-size:10pt;font-family:Verdana">

          <div style="font:12pt verdana;color:darkred">
            <i><b><%# DataBinder.Eval(Container.DataItem, "title") %></i></b>
          </div>

          <br>

          <b>Title ID: </b><%# DataBinder.Eval(Container.DataItem, "title_id") %><br>
          <b>Category: </b><%# DataBinder.Eval(Container.DataItem, "type") %><br>
          <b>Publisher ID: </b><%# DataBinder.Eval(Container.DataItem, "pub_id") %><br>
          <b>Price: </b><%# DataBinder.Eval(Container.DataItem, "price", "$ {0}") %><p>

        </div>

      </ItemTemplate>

  </asp:DataList>

  <asp:SqlDataSource ConnectionString="<%$ ConnectionStrings:Pubs %>" ID="SqlDataSource1"
    runat="server" SelectCommand="SELECT * FROM [titles]"/>
    
  <!-- #include virtual="footer.inc" -->

</body>
</html>
