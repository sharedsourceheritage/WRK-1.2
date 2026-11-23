<%@ Page Language="C#" %>
<%@ OutputCache Duration="60" VaryByParam="none" %>

<script runat="server">
    static string GetCurrentDate(HttpContext context)
    {
        return DateTime.Now.ToString();
    }
</script>

<html>
<head id="Head1" runat="server">
    <title>Post Cache Substitution</title>
</head>
<body>
    <form id="form1" runat="server">
        <h4>
            This page uses post cache substitution to insert a dynamic value into a cached page.</h4>
        <p>
            Time:
            <%= DateTime.Now.ToString() %>
        </p>
        <p>
            <b>Real Time:
                <asp:Substitution ID="Substitution1" runat="server" MethodName="GetCurrentDate" />
            </b>
        </p>
    </form>
</body>
</html>

