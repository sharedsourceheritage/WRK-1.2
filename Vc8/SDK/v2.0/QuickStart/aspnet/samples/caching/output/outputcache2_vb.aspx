<%@ Page Language="vb" %>
<%@ OutputCache Duration="60" VaryByParam="none" %>

<script runat="server">
    Sub Page_Load(Src As Object, E As EventArgs)
        TimeMsg.Text = Now.ToString("G")
    End Sub
</script>

<html>
<body>
    <form id="Form1" runat="server">
        <h3>
            <font face="Verdana">Using the Output Cache</font></h3>
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" SelectCommand="SELECT [au_id], [au_lname], [au_fname], [phone], [address], [city], [state], [zip], [contract] FROM [authors]"
            ConnectionString="<%$ ConnectionStrings:Pubs %>" />
        <asp:GridView ID="GridView1" runat="server" DataSourceID="sqldatasource1">
        </asp:GridView>
        <p>
            <i>Last generated on:</i>
            <asp:Label ID="TimeMsg" runat="server" />
    </form>
</body>
</html>

