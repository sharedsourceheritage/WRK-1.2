<%@ Control Language="C#" %>
<%@ OutputCache Duration="60" VaryByParam="none" %>

<script runat="server">
    void Page_Load(Object Src, EventArgs E)
    {
        TimeMsg.Text = DateTime.Now.ToString("G");
    }
  </script>

<asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:Pubs %>"
    SelectCommand="SELECT [au_id], [au_lname], [au_fname], [phone], [address], [city], [state], [zip], [contract] FROM [authors]" />
<asp:GridView ID="GridView1" runat="server" DataSourceID="sqldatasource1" />
<p>
    <i>Control last generated on:</i>
    <asp:Label ID="TimeMsg" runat="server" /></p>
