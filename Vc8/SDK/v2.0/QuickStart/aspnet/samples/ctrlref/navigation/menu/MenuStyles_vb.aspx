<%@ Page Language="VB" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
  <title>Menu Styles</title>
</head>
<body>
  <form id="form1" runat="server">
    <div>
      <h2>
        Menu Styles Sample</h2>
      This sample illustrates several menu styles. By adding a Head runat=server to the
      page the Menu control will generate style classes instead of inline styles.
      <br />
      <br />
      <asp:Menu ID="Menu1" Height="20" runat="server" DynamicHorizontalOffset="-10" 
        DynamicVerticalOffset="20" StaticEnableDefaultPopOutImage="false">
        <StaticMenuStyle BorderStyle="Outset" BorderWidth="1px" BackColor="#D6D3CE" />
        <StaticMenuItemStyle ForeColor="black" HorizontalPadding="2px" 
          Font-Names="Tahoma" Font-Size="8pt" />
        <DynamicMenuStyle BorderStyle="Outset" BorderWidth="1px" BackColor="#D6D3CE" />
        <DynamicMenuItemStyle ForeColor="black" HorizontalPadding="2px" 
          Font-Names="Tahoma" Font-Size="8pt" />
        <DynamicHoverStyle BackColor="SteelBlue" ForeColor="White" />
        <Items>
          <asp:MenuItem NavigateUrl="~/MenuStyles_cs.aspx" Text="Library Home" Value="Library Home"
            ImageUrl="images/book.jpg">
            <asp:MenuItem NavigateUrl="~/MenuStyles_cs.aspx" Text="Book 0" Value="Book 0" />
            <asp:MenuItem NavigateUrl="~/MenuStyles_cs.aspx" Text="Book 1" Value="Book 1">
              <asp:MenuItem NavigateUrl="~/MenuStyles_cs.aspx" Text="Chapter 0" Value="Chapter 0" />
              <asp:MenuItem NavigateUrl="~/MenuStyles_cs.aspx" Text="Chapter 1" Value="Chapter 1">
                <asp:MenuItem NavigateUrl="~/MenuStyles_cs.aspx" Text="Page 1" Value="Page 1" />
              </asp:MenuItem>
            </asp:MenuItem>
            <asp:MenuItem Text="Book 2" Value="Book 2">
              <asp:MenuItem NavigateUrl="~/MenuStyles_cs.aspx" Text="Chapter 0" Value="Chapter 0" />
              <asp:MenuItem NavigateUrl="~/MenuStyles_cs.aspx" Text="Chapter 1" Value="Chapter 1">
                <asp:MenuItem NavigateUrl="~/MenuStyles_cs.aspx" Text="Page 1" Value="Page 1" />
              </asp:MenuItem>
              <asp:MenuItem NavigateUrl="~/MenuStyles_cs.aspx" Text="Chapter 2" Value="Chapter 2">
                <asp:MenuItem NavigateUrl="~/MenuStyles_cs.aspx" Text="Page 1" Value="Page 1" />
                <asp:MenuItem NavigateUrl="~/MenuStyles_cs.aspx" Text="Page 2" Value="Page 2" />
              </asp:MenuItem>
            </asp:MenuItem>
            <asp:MenuItem NavigateUrl="~/MenuStyles_cs.aspx" Text="Book 3" Value="Book 3">
              <asp:MenuItem NavigateUrl="~/MenuStyles_cs.aspx" Text="Chapter 0" Value="Chapter 0" />
              <asp:MenuItem NavigateUrl="~/MenuStyles_cs.aspx" Text="Chapter 1" Value="Chapter 1">
                <asp:MenuItem NavigateUrl="~/MenuStyles_cs.aspx" Text="Page 1" Value="Page 1" />
              </asp:MenuItem>
              <asp:MenuItem NavigateUrl="~/MenuStyles_cs.aspx" Text="Chapter 2" Value="Chapter 2">
                <asp:MenuItem NavigateUrl="~/MenuStyles_cs.aspx" Text="Page 1" Value="Page 1" />
                <asp:MenuItem NavigateUrl="~/MenuStyles_cs.aspx" Text="Page 2" Value="Page 2" />
              </asp:MenuItem>
              <asp:MenuItem NavigateUrl="~/MenuStyles_cs.aspx" Text="Chapter 3" Value="Chapter 3">
                <asp:MenuItem NavigateUrl="~/MenuStyles_cs.aspx" Text="Page 1" Value="Page 1" />
                <asp:MenuItem NavigateUrl="~/MenuStyles_cs.aspx" Text="Page 2" Value="Page 2" />
                <asp:MenuItem NavigateUrl="~/MenuStyles_cs.aspx" Text="Page 3" Value="Page 3" />
              </asp:MenuItem>
            </asp:MenuItem>
          </asp:MenuItem>
        </Items>
      </asp:Menu>
      <br />
      <br />
      <br />
      <br />
      <b>Sample Note: </b>All menu items in this sample point to the same page.
    </div>
  </form>
</body>
</html>