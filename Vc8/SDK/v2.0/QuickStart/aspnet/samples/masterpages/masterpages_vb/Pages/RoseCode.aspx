<%@ page language="VB" masterpagefile="~/Site3.master" %>
<%@ mastertype virtualpath="~/Site3.master" %>

<script runat="server">

  Sub Page_Load()

    Master.FooterText = "This is a custom footer"
    Dim ad As AdRotator = Master.FindControl("MyAdRotator")
    If (Not ad Is Nothing)
    
      ad.BorderColor = System.Drawing.Color.Purple
      ad.BorderWidth = 10
    End If
  End Sub
    
</script>

<asp:content id="Content1" contentplaceholderid="FlowerText" runat="server">
    With sunshine, water, and careful tending, roses will bloom several times in a season.
</asp:content>
<asp:content id="Content2" contentplaceholderid="FlowerPicture" runat="server">   
    <asp:Image id="image1" imageurl="~/images/rose.jpg" runat="server"/>
</asp:content>

