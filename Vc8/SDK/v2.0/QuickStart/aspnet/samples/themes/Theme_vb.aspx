<%@ Page Language="VB" Theme="ExampleTheme" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
  <title>Page with Example Theme Applied</title>
</head>
<body>
  <form id="form1" runat="server">
    <div>
      <h3>
        Page with Example Theme Applied</h3>
      <asp:Label ID="Label1" runat="server" Text="Hello 1" /><br />
      <asp:Label ID="Label2" runat="server" Text="Hello 2" /><br />
      <asp:Label ID="Label3" runat="server" Text="Hello 3" /><br />
      <br />
      This is some example text: The quick brown fox jumped over the lazy dog.<br />
      <br />
      <asp:Calendar ID="Calendar1" runat="server"/>
      <br />
      <asp:GridView ID="GridView1" AutoGenerateColumns="False" DataSourceID="SqlDataSource1"
        DataKeyNames="au_id" runat="server">
        <Columns>
          <asp:BoundField DataField="au_id" HeaderText="au_id" ReadOnly="True" SortExpression="au_id" />
          <asp:BoundField DataField="au_lname" HeaderText="au_lname" SortExpression="au_lname" />
          <asp:BoundField DataField="au_fname" HeaderText="au_fname" SortExpression="au_fname" />
          <asp:BoundField DataField="state" HeaderText="state" SortExpression="state" />
        </Columns>
      </asp:GridView>
      <asp:SqlDataSource ConnectionString="<%$ ConnectionStrings:Pubs %>" ID="SqlDataSource1"
        runat="server" SelectCommand="SELECT [au_id], [au_lname], [au_fname], [state] FROM [authors]">
      </asp:SqlDataSource>
    </div>
  </form>
</body>
</html>
