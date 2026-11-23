<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">
    void Buttons_Clicked(object sender, ImageMapEventArgs e)
    {
        label1.Text = e.PostBackValue + " clicked!";
        
    }
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <h3><font face="Verdana">ImageMap Class Mixed HotSpotMode Example</font></h3>
            
            <asp:imagemap id="Buttons" imageurl="hotspot.jpg" alternatetext="Navigate buttons"
                hotspotmode="Postback" onclick="Buttons_Clicked" runat="Server">                 
        
                <asp:RectangleHotSpot
                hotspotmode="Postback"
                postbackvalue="Button1"
                alternatetext="Button 1"
                top="30"
                left="175"
                bottom="110"
                right="355">
                </asp:RectangleHotSpot>
                
                <asp:RectangleHotSpot  
                hotspotmode="Postback"
                postbackvalue="Button2"
                alternatetext="Button 2"        
                top="155"
                left="175"
                bottom="240"
                right="355">          
                </asp:RectangleHotSpot>
                
                <asp:RectangleHotSpot
                hotspotmode="Postback"
                postbackvalue="Button3"
                alternatetext="Button 3"          
                top="285"
                left="175"
                bottom="365"
                right="355">
                </asp:RectangleHotSpot> 
                      
                <asp:RectangleHotSpot
                hotspotmode="Postback"
                postbackvalue="Background"
                alternatetext="Background"          
                top="0"
                left="0"
                bottom="390"
                right="540">
                </asp:RectangleHotSpot> 

            </asp:imagemap>
            
            <p>
                <h3><font face="verdana"><asp:label id="label1" runat="server" ></asp:label></font></h3>
            </p>
                        
        </div>
    </form>
</body>
</html>
