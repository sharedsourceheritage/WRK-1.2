<%@ Page Language="c#" %>
<%@ OutputCache Duration="60" VaryByParam="none" %>

<script runat="server">

    void Page_Load(Object Src, EventArgs E)
    {
        TimeMsg.Text = DateTime.Now.ToString("G");
    }
</script>

<html>
<body>
    <form id="Form1" runat="server">
        <h3>
            <font face="Verdana">Using the Output Cache</font></h3>
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:Pubs %>"
            SelectCommand="SELECT [au_id], [au_lname], [au_fname], [phone], [address], [city], [state], [zip], [contract] FROM [authors]" />
        <asp:GridView ID="GridView1" runat="server" DataSourceID="sqldatasource1" />
        <p>
            <i>Last generated on:</i>
            <asp:Label ID="TimeMsg" runat="server" /></p>
    </form>
</body>
</html>

