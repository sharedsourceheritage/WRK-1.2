<%@ Page Language="VB" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<script runat="server">

  Protected Sub GridView1_SelectedIndexChanged(ByVal sender As Object, ByVal e As System.EventArgs)

    Response.Write("<b>SelectedDataKey.Value: </b>" & Server.HtmlEncode(GridView1.SelectedDataKey.Value) & "<br />")
    Response.Write("<b>DataKey Field 1: </b>" & Server.HtmlEncode(GridView1.SelectedDataKey.Values("au_id")) & "<br />")
    Response.Write("<b>DataKey Field 2: </b>" & Server.HtmlEncode(GridView1.SelectedDataKey.Values("title_id")) & "<br />")
  End Sub

  Protected Sub GridView1_DataBound(ByVal sender As Object, ByVal e As System.EventArgs)
    Dim key As DataKey
    Response.Write("<b>GridView DataKeys: </b><br />")
    For Each key In GridView1.DataKeys
      Response.Write(Server.HtmlEncode(key.Values(0)) & ", ")
      Response.Write(Server.HtmlEncode(key.Values(1)) & "<br/>")
    Next
  End Sub

  Protected Sub GridView1_PageIndexChanging(ByVal sender As Object, ByVal e As System.Web.UI.WebControls.GridViewPageEventArgs)
    GridView1.SelectedIndex = -1
  End Sub
  
  Protected Sub GridView1_Sorting(ByVal sender As Object, ByVal e As System.Web.UI.WebControls.GridViewSortEventArgs)
    GridView1.SelectedIndex = -1
  End Sub
</script>
<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
  <title>DataKeys</title>
</head>
<body>
  <form id="form1" runat="server">
    <div>
      <asp:GridView ID="GridView1" runat="server" DataSourceID="SqlDataSource1" DataKeyNames="au_id,title_id"
        AutoGenerateColumns="False" AllowPaging="True" AllowSorting="True" OnSelectedIndexChanged="GridView1_SelectedIndexChanged" OnDataBound="GridView1_DataBound" OnPageIndexChanging="GridView1_PageIndexChanging" OnSorting="GridView1_Sorting">
        <Columns>
          <asp:CommandField ShowSelectButton="True" />
          <asp:BoundField DataField="au_id" HeaderText="au_id" ReadOnly="True" SortExpression="au_id" />
          <asp:BoundField DataField="title_id" HeaderText="title_id" ReadOnly="True" SortExpression="title_id" />
          <asp:BoundField DataField="royaltyper" HeaderText="royaltyper" SortExpression="royaltyper" />
        </Columns>
        <SelectedRowStyle BackColor="#C0FFC0" />
      </asp:GridView>
      <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:Pubs %>"
        SelectCommand="SELECT [au_id], [title_id], [royaltyper] FROM [titleauthor]" />
    </div>
  </form>
</body>
</html>
