<%@ Page Language="C#" %>
<%@ OutputCache Duration="60" VaryByParam = "none" %>

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
    <div>
    <b>This page uses post cache substitution to insert a dynamic value into a cached page.</b>
    <br /><br />
    Time: <%= DateTime.Now.ToString() %>
    <br /><br />
    <b>   
    Real Time: <% Response.WriteSubstitution(new HttpResponseSubstitutionCallback(GetCurrentDate)); %>
    </b>
    </div>
    </div>
    </form>
</body>
</html>

