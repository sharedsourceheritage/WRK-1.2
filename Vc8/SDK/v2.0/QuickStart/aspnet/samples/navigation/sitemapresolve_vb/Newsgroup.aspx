<%@ page language="VB"%>

<script runat="server">

    Sub Page_Load(ByVal sender As Object, ByVal e As EventArgs)
        If (Request.QueryString("type") = "Breaking")
            pnlBreaking.Visible = true
            pnlFinancial.Visible = false
        Else If (Request.QueryString("type") = "Financial")
            pnlBreaking.Visible = false
            pnlFinancial.Visible = true
        Else
	    pnlBreaking.Visible = false
            pnlFinancial.Visible = false
        End If
    End Sub
    
</script>

<html>
<head runat="server" id="Head1">
    <title>Example page for a Newsgroup</title>
</head>
<body>
    <form id="form1" runat="server">
      <span style="background-color:moccasin">
        <asp:sitemappath id="SiteMapPath1" runat="server" PathSeparator="-->" RenderCurrentNodeAsLink=true>
            <CurrentNodeStyle Font-Bold=true />
        </asp:sitemappath>
      </span>
        <br />
        <br />
        <h3>This is the newsgroup for <%= Server.HtmlEncode(Request.QueryString("type")) %> news</h3>
        <br />
        <br />
        <br />
        <i>
    Current Postings:<br />
        </i>
    <br />
        <asp:Panel ID="pnlFinancial" Runat="server">
            <asp:hyperlink id="HyperLink1" runat="server" navigateurl="~/postings.aspx?type=Financial&postingID=goldbug">Gold market info</asp:hyperlink>
        <br />
            <asp:hyperlink id="HyperLink2" runat="server" navigateurl="~/postings.aspx?type=Financial&postingID=oilmarket">Oil prices increase</asp:hyperlink>
        <br />
        </asp:Panel>
        <asp:Panel ID="pnlBreaking" Runat="server">
            <asp:hyperlink id="HyperLink3" runat="server" navigateurl="~/postings.aspx?type=Breaking&postingID=CityCouncilMeets">City Council Votes Tonight</asp:hyperlink>
        </asp:Panel>

    </form>
</body>
</html>
