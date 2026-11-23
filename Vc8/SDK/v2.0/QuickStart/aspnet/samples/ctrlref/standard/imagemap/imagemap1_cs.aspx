<%@ Page Language="C#" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<script runat="server">

</script>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <h3><font face="Verdana">ImageMap Class Mixed HotSpotMode Example</font></h3>
            
            <asp:imagemap id="Buttons" imageurl="hotspot.jpg" alternatetext="Navigate buttons"
                runat="Server">                 
        
                <asp:RectangleHotSpot
                hotspotmode="Navigate"
                NavigateUrl="navigate1.htm"
                alternatetext="Button 1"
                top="30"
                left="175"
                bottom="110"
                right="355">
                </asp:RectangleHotSpot>
                
                <asp:RectangleHotSpot  
                hotspotmode="Navigate"
                NavigateUrl="navigate2.htm"
                alternatetext="Button 2"        
                top="155"
                left="175"
                bottom="240"
                right="355">          
                </asp:RectangleHotSpot>
                
                <asp:RectangleHotSpot
                hotspotmode="Navigate"
                NavigateUrl="navigate3.htm"
                alternatetext="Button 3"          
                top="285"
                left="175"
                bottom="365"
                right="355">
                </asp:RectangleHotSpot> 
                      
            </asp:imagemap>
            
        </div>
    </form>
</body>
</html>
