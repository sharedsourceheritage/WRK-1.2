<%@ Page Language="VB" %>
<%@ OutputCache Duration="60" VaryByParam="none" %>
<html>
<script runat="server">

    Sub Page_Load(ByVal Src As Object, ByVal e As EventArgs)
        TimeMsg.Text = Now.ToString("G")
    End Sub

   </script>
<body>
    <h3>
        <font face="Verdana">Using the Output Cache</font></h3>
    <p>
        <i>Last generated on:</i>
        <asp:Label ID="TimeMsg" runat="server" />
</body>
</html>
