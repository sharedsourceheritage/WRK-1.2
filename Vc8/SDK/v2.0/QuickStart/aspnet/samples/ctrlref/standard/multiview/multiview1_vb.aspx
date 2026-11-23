<%@ Page Language="VB" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<script runat="server">

    Protected Sub DropDownList1_SelectedIndexChanged(ByVal sender As Object, ByVal e As System.EventArgs)
        MultiView1.ActiveViewIndex = DropDownList1.SelectedValue
    End Sub
    
</script>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <h3>
                <font face="Verdana">MultiView with 3 Views</font>
            </h3>
            <asp:DropDownList ID="DropDownList1" OnSelectedIndexChanged="DropDownList1_SelectedIndexChanged"
                runat="server" AutoPostBack="True">
                <asp:ListItem Value="0">View 1</asp:ListItem>
                <asp:ListItem Value="1">View 2</asp:ListItem>
                <asp:ListItem Value="2">View 3</asp:ListItem>
            </asp:DropDownList><br />
            <hr />
            <asp:MultiView ID="MultiView1" runat="server" ActiveViewIndex="0">
                <asp:View ID="View1" runat="server">
                    Now showing View #1<br />
                    <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox><strong> </strong>
                    <asp:Button ID="Button1" runat="server" Text="Button" /></asp:View>
                <asp:View ID="View2" runat="server">
                    Now showing View #2<br />
                    <asp:HyperLink ID="HyperLink1" runat="server" NavigateUrl="http://www.asp.net">HyperLink</asp:HyperLink>
                    <asp:HyperLink ID="HyperLink2" runat="server" NavigateUrl="http://www.asp.net">HyperLink</asp:HyperLink></asp:View>
                <asp:View ID="View3" runat="server">
                    Now showing View #3<br />
                    <asp:Calendar ID="Calendar1" runat="server"></asp:Calendar>
                </asp:View>
            </asp:MultiView></div>
    </form>
</body>
</html>
