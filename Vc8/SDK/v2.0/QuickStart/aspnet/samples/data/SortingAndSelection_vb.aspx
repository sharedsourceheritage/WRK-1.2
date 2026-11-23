<%@ Page Language="VB" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<script runat="server">

  Sub GridView1_DataBound(ByVal sender As Object, ByVal e As System.EventArgs)
        
    Dim Row As GridViewRow
    Dim SelectedValue As String = ViewState("SelectedValue")
    If SelectedValue Is Nothing Then
      Return
    End If

    ' Determine if the selected row is visible and re-select it
    For Each Row In GridView1.Rows
      Dim KeyValue As String = GridView1.DataKeys(Row.RowIndex).Value
      If (KeyValue = SelectedValue) Then
        GridView1.SelectedIndex = Row.RowIndex
      End If
    Next
  End Sub

  Protected Sub GridView1_SelectedIndexChanged(ByVal sender As Object, ByVal e As System.EventArgs)
    ' Save selected index
    If (Not GridView1.SelectedIndex = -1) Then
      ViewState("SelectedValue") = GridView1.SelectedValue
    End If
  End Sub

  Protected Sub GridView1_PageIndexChanging(ByVal sender As Object, ByVal e As System.Web.UI.WebControls.GridViewPageEventArgs)
    ' Reset selected index
    GridView1.SelectedIndex = -1
  End Sub
  
  Sub GridView1_Sorting(ByVal sender As Object, ByVal e As System.Web.UI.WebControls.GridViewSortEventArgs)
    ' Reset selected index
    GridView1.SelectedIndex = -1
  End Sub

  </script>
<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
  <title>Untitled Page</title>
</head>
<body>
  <form id="form1" runat="server">
    <div>
      <asp:GridView ID="GridView1" runat="server" DataSourceID="SqlDataSource1" DataKeyNames="au_id"
        AutoGenerateColumns="False" AllowPaging="True" AllowSorting="True" OnSorting="GridView1_Sorting"
        OnDataBound="GridView1_DataBound" OnSelectedIndexChanged="GridView1_SelectedIndexChanged" OnPageIndexChanging="GridView1_PageIndexChanging">
        <Columns>
          <asp:CommandField ShowSelectButton="True" />
          <asp:BoundField ReadOnly="True" HeaderText="au_id" DataField="au_id" SortExpression="au_id" />
          <asp:BoundField HeaderText="au_lname" DataField="au_lname" SortExpression="au_lname" />
          <asp:BoundField HeaderText="au_fname" DataField="au_fname" SortExpression="au_fname" />
        </Columns>
        <SelectedRowStyle BackColor="#C0FFC0" />
      </asp:GridView>
      <asp:SqlDataSource ID="SqlDataSource1" runat="server" ProviderName="System.Data.SqlClient"
        ConnectionString="<%$ ConnectionStrings:Pubs %>" SelectCommand="SELECT [au_id], [au_lname], [au_fname] FROM [authors]" />
    </div>
  </form>
</body>
</html>
