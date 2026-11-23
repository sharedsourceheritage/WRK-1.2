<html>
<head>

    <script language="VB" runat="server">

       Sub Button1_Click(sender As Object, e As ImageClickEventArgs) 
          Span1.InnerHtml="You clicked button1"
       End Sub

       Sub Button2_Click(sender As Object, e As ImageClickEventArgs) 
          Span1.InnerHtml="You clicked button2"
       End Sub

    </script>

</head>
<body>

    <h3><font face="Verdana">HtmlInputImage Sample</font></h3>

    <form runat=server>

        <input type=image id="InputImage1" src="images/mango.jpg" OnServerClick="Button1_Click" runat="server">
        
        <p>

        <input type=image id="InputImage2" src="images/mango.jpg"
            onmouseover="this.src='images/banana.jpg';"
            onmouseout="this.src='images/mango.jpg';"
            OnServerClick="Button2_Click"
            runat="server">

        &nbsp;With rollover effect (HTML 4.0)

        <p>

        <span id=Span1 runat=server />

    </form>

</body>
</html>


