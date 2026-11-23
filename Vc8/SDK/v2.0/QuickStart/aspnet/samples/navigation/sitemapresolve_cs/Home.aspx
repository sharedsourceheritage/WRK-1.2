<%@ page language="C#" %>

<script runat="server">

</script>

<html>
<head runat="server">
    <title>Home Page</title>
</head>
<body>
    <form id="form1" runat="server">
    <span style="background-color:moccasin">
        <asp:sitemappath id="SiteMapPath1" runat="server" RenderCurrentNodeAsLink=true>
            <CurrentNodeStyle Font-Bold=true />
        </asp:sitemappath>
    </span>
        <br />
        <br />
        <br />
        <asp:hyperlink id="HyperLink1" runat="server" navigateurl="~/Newsgroup.aspx?type=Breaking">
            Newsgroup Landing Page - Breaking News</asp:hyperlink>
        <br />
        <br />
        <br />
        <asp:hyperlink id="HyperLink2" runat="server" navigateurl="~/Newsgroup.aspx?type=Financial">
            Newsgroup Landing Page - Financial News</asp:hyperlink>            

    </form>
</body>
</html>
