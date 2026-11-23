<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>Showing all items in a filtered list</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <asp:DropDownList AppendDataBoundItems="True" AutoPostBack="True" DataSourceID="SqlDataSource2"
            DataTextField="state" DataValueField="state" ID="DropDownList1" runat="server">
            <asp:ListItem Value="">ALL</asp:ListItem>
        </asp:DropDownList><asp:SqlDataSource ConnectionString="<%$ ConnectionStrings:Pubs %>"
            ID="SqlDataSource2" runat="server" SelectCommand="SELECT DISTINCT [state] FROM [authors]">
        </asp:SqlDataSource>
        <br />
        <br />
        <asp:GridView AutoGenerateColumns="False" DataSourceID="SqlDataSource1"
            ID="GridView1" runat="server" DataKeyNames="au_id">
            <Columns>
              <asp:BoundField DataField="au_id" HeaderText="au_id" ReadOnly="True" SortExpression="au_id" />
              <asp:BoundField DataField="au_lname" HeaderText="au_lname" SortExpression="au_lname" />
              <asp:BoundField DataField="au_fname" HeaderText="au_fname" SortExpression="au_fname" />
              <asp:BoundField DataField="state" HeaderText="state" SortExpression="state" />
            </Columns>
        </asp:GridView>
        <asp:SqlDataSource ConnectionString="<%$ ConnectionStrings:Pubs %>"
            ID="SqlDataSource1" runat="server" SelectCommand="SELECT au_id, au_lname, au_fname, state FROM authors WHERE state = IsNull(@state, state)" CancelSelectOnNullParameter="False">
            <SelectParameters>
                <asp:ControlParameter ControlID="DropDownList1" Name="state" PropertyName="SelectedValue" Type="String" />
            </SelectParameters>
        </asp:SqlDataSource>    
    </div>
    </form>
</body>
</html>
