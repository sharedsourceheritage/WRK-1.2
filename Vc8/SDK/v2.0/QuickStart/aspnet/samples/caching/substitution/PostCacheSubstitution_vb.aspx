<%@ Page Language="VB" %>
<%@ OutputCache Duration="60" VaryByParam = "none" %>

<script runat="server">

Shared Function GetCurrentDate(context As HttpContext) As String

    return DateTime.Now.ToString()
End Function

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
    Real Time: <% Response.WriteSubstitution(New HttpResponseSubstitutionCallback(AddressOf GetCurrentDate)) %>
    </b>
    </div>
    </div>
    </form>
</body>
</html>

