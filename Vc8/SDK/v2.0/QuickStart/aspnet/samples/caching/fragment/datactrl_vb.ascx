<%@ Control Language="vb" %>
<%@ OutputCache Duration="60" VaryByParam="none" %>


<script runat=server>
    Sub Page_Load(Src As Object, E As EventArgs)
        TimeMsg.Text = Now.ToString("G")
    End Sub
</script>

<asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:Pubs %>"
    SelectCommand="SELECT [au_id], [au_lname], [au_fname], [phone], [address], [city], [state], [zip], [contract] FROM [authors]" />
<asp:GridView ID="GridView1" runat="server" DataSourceID="sqldatasource1" />
<p>
    <i>Control last generated on:</i>
    <asp:Label ID="TimeMsg" runat="server" /></p>
