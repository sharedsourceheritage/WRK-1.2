<%@ Page Language="VB" %>
<%@ OutputCache Duration="60" VaryByParam="state" %>

<script runat="server">

    Sub page_Load(ByVal sender As Object, ByVal e As EventArgs)
        TimeMsg.Text = Now.ToString("G")
    End Sub

</script>

<html>
<body>
    <form id="Form1" runat="server">
        <h3>
            <font face="Verdana">Using the Output Cache</font></h3>
        <b>Authors by State:</b>
        <table cellspacing="0" cellpadding="3" rules="all" style="background-color: #AAAADD;
            border-color: black; border-color: black; width: 700px; border-collapse: collapse;">
            <tr>
                <td>
                    <a href="outputcache3_vb.aspx?state=CA">CA</a></td>
                <td>
                    <a href="outputcache3_vb.aspx?state=IN">IN</a></td>
                <td>
                    <a href="outputcache3_vb.aspx?state=KS">KS</a></td>
                <td>
                    <a href="outputcache3_vb.aspx?state=MD">MD</a></td>
                <td>
                    <a href="outputcache3_vb.aspx?state=MI">MI</a></td>
                <td>
                    <a href="outputcache3_vb.aspx?state=OR">OR</a></td>
                <td>
                    <a href="outputcache3_vb.aspx?state=TN">TN</a></td>
                <td>
                    <a href="outputcache3_vb.aspx?state=UT">UT</a></td>
            </tr>
        </table>
        <p>
        </p>
        <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:Pubs %>"
            SelectCommand="SELECT [au_id], [au_lname], [au_fname], [phone], [address], [city], [state], [zip], [contract] FROM [authors] where state=@state">
            <SelectParameters>
                <asp:QueryStringParameter Name="state" QueryStringField="state" DefaultValue="CA" />
            </SelectParameters>
        </asp:SqlDataSource>
        <asp:GridView ID="GridView1" runat="server" DataSourceID="sqldatasource1" />
        <p>
            <i>Last generated on:</i>
            <asp:Label ID="TimeMsg" runat="server" />
        </p>
    </form>
</body>
</html>

