<%@ Page Language="VB" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
  <title>Page with No Theme Applied</title>
</head>
<body>
  <form id="form1" runat="server">
    <div>
      <h3>
        Page with No Theme Applied</h3>
      <asp:Label ID="Label1" runat="server" Text="Hello 1" Font-Bold="true" ForeColor="orange" /><br />
      <asp:Label ID="Label2" runat="server" Text="Hello 2" Font-Bold="true" ForeColor="orange" /><br />
      <asp:Label ID="Label3" runat="server" Text="Hello 3" Font-Bold="true" ForeColor="orange" /><br />
      <br />
      This is some example text: The quick brown fox jumped over the lazy dog.<br />
      <br />
      <asp:Calendar BackColor="White" BorderColor="Black" BorderStyle="Solid" CellSpacing="1"
        Font-Names="Verdana" Font-Size="9pt" ForeColor="Black" Height="250px" ID="Calendar1"
        NextPrevFormat="ShortMonth" runat="server" Width="330px">
        <SelectedDayStyle BackColor="#333399" ForeColor="White" />
        <OtherMonthDayStyle ForeColor="#999999" />
        <TodayDayStyle BackColor="#999999" ForeColor="White" />
        <DayStyle BackColor="#CCCCCC" />
        <NextPrevStyle Font-Bold="True" Font-Size="8pt" ForeColor="White" />
        <DayHeaderStyle Font-Bold="True" Font-Size="8pt" ForeColor="#333333" Height="8pt" />
        <TitleStyle BackColor="#333399" BorderStyle="Solid" Font-Bold="True" Font-Size="12pt"
          ForeColor="White" Height="12pt" />
      </asp:Calendar>
      <br />
      <asp:GridView AutoGenerateColumns="False" CellPadding="4" DataKeyNames="au_id" DataSourceID="SqlDataSource1"
        ForeColor="#333333" GridLines="None" ID="GridView1" runat="server" Width="461px">
        <FooterStyle BackColor="#1C5E55" Font-Bold="True" ForeColor="White" />
        <Columns>
          <asp:BoundField DataField="au_id" HeaderText="au_id" ReadOnly="True" SortExpression="au_id" />
          <asp:BoundField DataField="au_lname" HeaderText="au_lname" SortExpression="au_lname" />
          <asp:BoundField DataField="au_fname" HeaderText="au_fname" SortExpression="au_fname" />
          <asp:BoundField DataField="state" HeaderText="state" SortExpression="state" />
        </Columns>
        <RowStyle BackColor="#E3EAEB" />
        <PagerStyle BackColor="#666666" ForeColor="White" HorizontalAlign="Center" />
        <SelectedRowStyle BackColor="#C5BBAF" Font-Bold="True" ForeColor="#333333" />
        <HeaderStyle BackColor="#1C5E55" Font-Bold="True" ForeColor="White" />
        <EditRowStyle BackColor="#7C6F57" />
        <AlternatingRowStyle BackColor="White" />
      </asp:GridView>
      <asp:SqlDataSource ConnectionString="<%$ ConnectionStrings:Pubs %>" ID="SqlDataSource1"
        runat="server" SelectCommand="SELECT [au_id], [au_lname], [au_fname], [state] FROM [authors]">
      </asp:SqlDataSource>
    </div>
  </form>
</body>
</html>
