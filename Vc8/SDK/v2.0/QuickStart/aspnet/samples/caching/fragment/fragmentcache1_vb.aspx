<%@ Page Language="VB" %>
<%@ Register TagPrefix="Acme" TagName="DataControl" Src="datactrl_vb.ascx" %>

<html>

<script runat="server">
    Sub Page_Load(Src As Object, E As EventArgs)
        TimeMsg.Text = Now.ToString("G")
    End Sub
</script>

<body>
<form runat=server>
    <h3>
        <font face="Verdana">Fragment Caching</font></h3>
    <Acme:DataControl runat="server" />
    <br>
    <i>Page last generated on:</i>
    <asp:Label ID="TimeMsg" runat="server" />
    </form>
</body>
</html>

