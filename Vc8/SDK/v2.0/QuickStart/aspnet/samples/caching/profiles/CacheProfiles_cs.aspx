<%@ Page Language="C#" %>
<%@ OutputCache CacheProfile="CacheFor60Seconds" VaryByParam="name" %>

<html>
<head runat="server">
    <title>Output Caching With Cache Profiles</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    <b>This page is output cached with a cache profile.</b>
    <br /><br />
    Hello <%= Server.HtmlEncode(name.Text) %>!
    <br /><br /> 
    The time right now is <%= DateTime.Now.ToString() %>
    <br /><br />
    Name: <asp:TextBox Runat="server" Id="name" />
    <asp:Button Runat="server" Text="Refresh" />
    </div>
    </form>
</body>
</html>
