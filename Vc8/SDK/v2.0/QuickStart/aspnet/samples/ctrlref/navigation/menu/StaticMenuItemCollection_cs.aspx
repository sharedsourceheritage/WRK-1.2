<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
  <title>Basic Menu Control with Menu Item Collection</title>
</head>
<body>
  <form id="form1" runat="server">
    <div>
      <h2>
        Basic Menu Control with Menu Item Collection</h2>
      This sample shows basic Menu functionality with the Menu Items are stored as a 
      collection of items within the control. Although this sample demonstrates a 
      navigation scenario, the Menu control can be used in non-navigation scenarios, 
      for example selecting your city from a list of regions.
      <br />
      <br />
      <asp:Menu ID="Menu1" runat="server" BackColor="#FFFBD6" DynamicHorizontalOffset="2"
        Font-Names="Verdana" ForeColor="#990000" StaticSubMenuIndent="10px">
        <Items>
          <asp:MenuItem NavigateUrl="~/StaticMenuItemCollection_cs.aspx" Text="Book 0" Value="Book 0" />
          <asp:MenuItem NavigateUrl="~/StaticMenuItemCollection_cs.aspx" Text="Book 1" Value="Book 1">
            <asp:MenuItem NavigateUrl="~/StaticMenuItemCollection_cs.aspx" Text="Chapter 0" Value="Chapter 0" />
            <asp:MenuItem NavigateUrl="~/StaticMenuItemCollection_cs.aspx" Text="Chapter 1" Value="Chapter 1">
              <asp:MenuItem NavigateUrl="~/StaticMenuItemCollection_cs.aspx" Text="Page 1" Value="Page 1" />
            </asp:MenuItem>
          </asp:MenuItem>
          <asp:MenuItem Text="Book 2" Value="Book 2">
            <asp:MenuItem NavigateUrl="~/StaticMenuItemCollection_cs.aspx" Text="Chapter 0" Value="Chapter 0" />
            <asp:MenuItem NavigateUrl="~/StaticMenuItemCollection_cs.aspx" Text="Chapter 1" Value="Chapter 1">
              <asp:MenuItem NavigateUrl="~/StaticMenuItemCollection_cs.aspx" Text="Page 1" Value="Page 1" />
            </asp:MenuItem>
            <asp:MenuItem NavigateUrl="~/StaticMenuItemCollection_cs.aspx" Text="Chapter 2" Value="Chapter 2">
              <asp:MenuItem NavigateUrl="~/StaticMenuItemCollection_cs.aspx" Text="Page 1" Value="Page 1" />
              <asp:MenuItem NavigateUrl="~/StaticMenuItemCollection_cs.aspx" Text="Page 2" Value="Page 2" />
            </asp:MenuItem>
          </asp:MenuItem>
          <asp:MenuItem NavigateUrl="~/StaticMenuItemCollection_cs.aspx" Text="Book 3" Value="Book 3">
            <asp:MenuItem NavigateUrl="~/StaticMenuItemCollection_cs.aspx" Text="Chapter 0" Value="Chapter 0" />
            <asp:MenuItem NavigateUrl="~/StaticMenuItemCollection_cs.aspx" Text="Chapter 1" Value="Chapter 1">
              <asp:MenuItem NavigateUrl="~/StaticMenuItemCollection_cs.aspx" Text="Page 1" Value="Page 1" />
            </asp:MenuItem>
            <asp:MenuItem NavigateUrl="~/StaticMenuItemCollection_cs.aspx" Text="Chapter 2" Value="Chapter 2">
              <asp:MenuItem NavigateUrl="~/StaticMenuItemCollection_cs.aspx" Text="Page 1" Value="Page 1" />
              <asp:MenuItem NavigateUrl="~/StaticMenuItemCollection_cs.aspx" Text="Page 2" Value="Page 2" />
            </asp:MenuItem>
            <asp:MenuItem NavigateUrl="~/StaticMenuItemCollection_cs.aspx" Text="Chapter 3" Value="Chapter 3">
              <asp:MenuItem NavigateUrl="~/StaticMenuItemCollection_cs.aspx" Text="Page 1" Value="Page 1" />
              <asp:MenuItem NavigateUrl="~/StaticMenuItemCollection_cs.aspx" Text="Page 2" Value="Page 2" />
              <asp:MenuItem NavigateUrl="~/StaticMenuItemCollection_cs.aspx" Text="Page 3" Value="Page 3" />
            </asp:MenuItem>
          </asp:MenuItem>
        </Items>
        <StaticSelectedStyle BackColor="#FFCC66" />
        <StaticMenuItemStyle HorizontalPadding="5px" VerticalPadding="2px" />
        <DynamicMenuStyle BackColor="#FFFBD6" />
        <DynamicSelectedStyle BackColor="#FFCC66" />
        <DynamicMenuItemStyle HorizontalPadding="5px" VerticalPadding="2px" />
        <DynamicHoverStyle BackColor="#990000" Font-Bold="False" ForeColor="White" />
        <StaticHoverStyle BackColor="#990000" Font-Bold="False" ForeColor="White" />
      </asp:Menu>
      <br />
      <br />
      <b>Note:</b> All items in the Menu point to the same page to simplify the sample.
      </div>
  </form>
</body>
</html>
