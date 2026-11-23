<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">


<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>Menu Behaviors</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    <h2>Menu Behaviors Sample</h2>
    This sample demonstrates the Menu in the horizontal orientation using a
    StaticFormatString and a StaticPopOutImage. Menu items
    that are constantly on display contain the prefix <b>Read</b>
    before their title. Static menu items that contain
      child items also display an image to indicate that there is pop-up functionality.<br /><br />
        <asp:Menu ID="Menu1" runat="server" Orientation="Horizontal" 
          StaticItemFormatString="Read {0} " StaticPopOutImageUrl="images/separator1.bmp">
            <Items>
                <asp:MenuItem NavigateUrl="~/MenuBehaviors_cs.aspx" Text="Book 0" 
                  Value="Book 0"/>
                <asp:MenuItem NavigateUrl="~/MenuBehaviors_cs.aspx" Text="Book 1" 
                  Value="Book 1">
                    <asp:MenuItem NavigateUrl="~/MenuBehaviors_cs.aspx" Text="Chapter 0" 
                      Value="Chapter 0"/>
                    <asp:MenuItem NavigateUrl="~/MenuBehaviors_cs.aspx" Text="Chapter 1" 
                      Value="Chapter 1">
                        <asp:MenuItem NavigateUrl="~/MenuBehaviors_cs.aspx" Text="Page 1" 
                          Value="Page 1"/>
                    </asp:MenuItem>
                </asp:MenuItem>
                <asp:MenuItem Text="Book 2" Value="Book 2">
                    <asp:MenuItem NavigateUrl="~/MenuBehaviors_cs.aspx" Text="Chapter 0" 
                      Value="Chapter 0"/>
                    <asp:MenuItem NavigateUrl="~/MenuBehaviors_cs.aspx" Text="Chapter 1" 
                      Value="Chapter 1">
                        <asp:MenuItem NavigateUrl="~/MenuBehaviors_cs.aspx" Text="Page 1" 
                          Value="Page 1"/>
                    </asp:MenuItem>
                    <asp:MenuItem NavigateUrl="~/MenuBehaviors_cs.aspx" Text="Chapter 2" 
                      Value="Chapter 2">
                        <asp:MenuItem NavigateUrl="~/MenuBehaviors_cs.aspx" Text="Page 1" 
                          Value="Page 1"/>
                        <asp:MenuItem NavigateUrl="~/MenuBehaviors_cs.aspx" Text="Page 2" 
                          Value="Page 2"/>
                    </asp:MenuItem>
                </asp:MenuItem>
                <asp:MenuItem NavigateUrl="~/MenuBehaviors_cs.aspx" Text="Book 3" 
                  Value="Book 3">
                    <asp:MenuItem NavigateUrl="~/MenuBehaviors_cs.aspx" Text="Chapter 0" 
                      Value="Chapter 0"/>
                    <asp:MenuItem NavigateUrl="~/MenuBehaviors_cs.aspx" Text="Chapter 1" 
                      Value="Chapter 1">
                         <asp:MenuItem NavigateUrl="~/MenuBehaviors_cs.aspx" Text="Page 1" 
                         Value="Page 1"/>
                     </asp:MenuItem>    
                    <asp:MenuItem NavigateUrl="~/MenuBehaviors_cs.aspx" Text="Chapter 2" 
                      Value="Chapter 2">
                         <asp:MenuItem NavigateUrl="~/MenuBehaviors_cs.aspx" Text="Page 1" 
                          Value="Page 1"/>
                         <asp:MenuItem NavigateUrl="~/MenuBehaviors_cs.aspx" Text="Page 2" 
                          Value="Page 2"/>
                    </asp:MenuItem>
                    <asp:MenuItem NavigateUrl="~/MenuBehaviors_cs.aspx" Text="Chapter 3" 
                      Value="Chapter 3">
                         <asp:MenuItem NavigateUrl="~/MenuBehaviors_cs.aspx" Text="Page 1" 
                          Value="Page 1"/>
                         <asp:MenuItem NavigateUrl="~/MenuBehaviors_cs.aspx" Text="Page 2" 
                          Value="Page 2"/>
                         <asp:MenuItem NavigateUrl="~/MenuBehaviors_cs.aspx" Text="Page 3" 
                          Value="Page 3"/>
                    </asp:MenuItem>
                 </asp:MenuItem>
            </Items>
            <StaticMenuItemStyle BorderColor="Black" BorderStyle="Solid" BorderWidth="2px"
               HorizontalPadding="10px" />
        </asp:Menu>
        <br />
        <br />
        <br />
        <br />
        <b>Sample Note: </b>All menu items in this example point to the same page.
        </div>
    </form>
</body>
</html>
