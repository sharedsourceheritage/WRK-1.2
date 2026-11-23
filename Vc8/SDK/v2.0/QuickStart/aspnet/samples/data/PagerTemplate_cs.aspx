<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>PagerTemplate</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
      <asp:GridView AllowPaging="True" AutoGenerateColumns="False" DataKeyNames="au_id"
        DataSourceID="SqlDataSource1" ID="GridView1" runat="server">
        <Columns>
          <asp:BoundField DataField="au_id" HeaderText="au_id" ReadOnly="True" SortExpression="au_id" />
          <asp:BoundField DataField="au_lname" HeaderText="au_lname" SortExpression="au_lname" />
          <asp:BoundField DataField="au_fname" HeaderText="au_fname" SortExpression="au_fname" />
          <asp:BoundField DataField="state" HeaderText="state" SortExpression="state" />
        </Columns>
        <PagerTemplate>
          <asp:LinkButton CommandName="Page" CommandArgument="First" ID="LinkButton1" runat="server" Style="color: white">&lt;&lt; First</asp:LinkButton>
          <asp:LinkButton CommandName="Page" CommandArgument="Prev" ID="LinkButton2" runat="server" Style="color: white">&lt; Prev</asp:LinkButton>
          [Records <%= GridView1.PageIndex * GridView1.PageSize %> - <%= GridView1.PageIndex * GridView1.PageSize + GridView1.PageSize - 1 %>]
          <asp:LinkButton CommandName="Page" CommandArgument="Next" ID="LinkButton3" runat="server" Style="color: white">Next &gt;</asp:LinkButton>
          <asp:LinkButton CommandName="Page" CommandArgument="Last" ID="LinkButton4" runat="server" Style="color: white">Last &gt;&gt;</asp:LinkButton>          
        </PagerTemplate>
      </asp:GridView>
      <asp:SqlDataSource ConnectionString="<%$ ConnectionStrings:Pubs %>" ID="SqlDataSource1"
        runat="server" SelectCommand="SELECT [au_id], [au_lname], [au_fname], [state] FROM [authors]">
      </asp:SqlDataSource>
      &nbsp;<br />
      <asp:DetailsView AllowPaging="True" AutoGenerateRows="False" DataKeyNames="au_id"
        DataSourceID="SqlDataSource1" Height="50px" ID="DetailsView1" runat="server" Width="399px" HeaderText="Author Details">
        <Fields>
          <asp:BoundField DataField="au_id" HeaderText="au_id" ReadOnly="True" SortExpression="au_id" />
          <asp:BoundField DataField="au_lname" HeaderText="au_lname" SortExpression="au_lname" />
          <asp:BoundField DataField="au_fname" HeaderText="au_fname" SortExpression="au_fname" />
          <asp:BoundField DataField="state" HeaderText="state" SortExpression="state" />
        </Fields>
        <PagerTemplate>
          <asp:LinkButton CommandName="Page" CommandArgument="First" ID="LinkButton1" runat="server" Style="color: white">&lt;&lt; First</asp:LinkButton>
          <asp:LinkButton CommandName="Page" CommandArgument="Prev" ID="LinkButton2" runat="server" Style="color: white">&lt; Prev</asp:LinkButton>
          [Record <%= DetailsView1.DataItemIndex %> of <%= DetailsView1.PageCount - 1 %>]
          <asp:LinkButton CommandName="Page" CommandArgument="Next"  ID="LinkButton3" runat="server" Style="color: white">Next &gt;</asp:LinkButton>
          <asp:LinkButton CommandName="Page" CommandArgument="Last" ID="LinkButton4" runat="server" Style="color: white">Last &gt;&gt;</asp:LinkButton>                    
        </PagerTemplate>
      </asp:DetailsView>
    </div>
    </form>
</body>
</html>
