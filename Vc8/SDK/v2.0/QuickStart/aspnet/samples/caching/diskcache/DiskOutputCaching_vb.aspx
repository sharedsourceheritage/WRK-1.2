<%@ Page Language="VB" %>
<%@ OutputCache Duration="3600" VaryByParam="name" DiskCacheable="true" %>
<html>
<head runat="server">
    <title>Disk Output Caching.</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    <b>This page uses disk output caching.</b>
    <br /><br /> 
    The time right now is <%= Now.ToString() %>.
    <br /><br />  
    </div>
    </form>
</body>
</html>