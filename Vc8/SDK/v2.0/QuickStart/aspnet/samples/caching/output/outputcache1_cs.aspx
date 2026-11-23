<%@ Page Language="C#" %>
<%@ OutputCache Duration="60" VaryByParam="none" %>
<html>
<script runat="server">

    void Page_Load(Object sender, EventArgs e)
    {
        TimeMsg.Text = DateTime.Now.ToString("G");
    }

  </script>
<body>
    <h3>
        <font face="Verdana">Using the Output Cache</font></h3>
    <p>
        <i>Last generated on:</i>
        <asp:Label ID="TimeMsg" runat="server" />
</body>
</html>
