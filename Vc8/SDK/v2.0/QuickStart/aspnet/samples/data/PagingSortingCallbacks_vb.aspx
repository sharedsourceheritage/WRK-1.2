<%@ Page Language="VB" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>Paging and Sorting Using Callbacks</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
      <asp:GridView AllowPaging="True" AllowSorting="True" AutoGenerateColumns="False"
        DataKeyNames="au_id" DataSourceID="SqlDataSource1" EnableSortingAndPagingCallbacks="True"
        ID="GridView1" runat="server">
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
