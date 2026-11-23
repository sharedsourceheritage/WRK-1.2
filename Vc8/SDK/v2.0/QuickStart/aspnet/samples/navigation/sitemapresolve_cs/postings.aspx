<%@ page language="C#" %>

<script runat="server">

</script>

<html>
<head runat="server">
    <title>Postings Page</title>
</head>
<body>
    <form id="form1" runat="server">
        &nbsp;
        
    <span style="background-color:moccasin">
      <asp:sitemappath id="SiteMapPath1" runat="server" RenderCurrentNodeAsLink=true>
          <CurrentNodeStyle Font-Bold=true />
      </asp:sitemappath>
    </span>
        <br />
        <br />
        <br />
        You clicked on posting: <b> <% = Server.HtmlEncode(Request.QueryString["PostingID"]) %></b>

    </form>
</body>
</html>
