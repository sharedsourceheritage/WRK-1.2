<html>
<head>

    <style>
        .applyBorder { border:0.2cm solid blue }
        .removeBorder { border:0.2cm solid gainsboro }
    </style>

    <script language="C#" runat="server">

       void Button1_Click(object Source, ImageClickEventArgs e) {

          Label1.Text="You clicked button1";
       }

       void Button2_Click(object Source, ImageClickEventArgs e) {

          Label1.Text="You clicked button2";
       }

       void Button3_Click(object Source, ImageClickEventArgs e) {

          Label1.Text="You clicked button3";
       }

    </script>

</head>
<body>

    <h3><font face="Verdana">Mouse-Over Effects on ImageButton</font></h3>

    <form runat=server>

        <asp:ImageButton id=Button1 runat="server"
            ImageUrl="images/banana.jpg"
            BorderWidth="0.2cm"
            BorderColor="Gainsboro"
            onmouseover="this.style.border='0.2cm solid black';"
            onmouseout="this.style.border='0.2cm solid gainsboro';"
            onclick="Button1_Click" />

            &nbsp;&nbsp;
            Applies an inline CSS style...

        <br>

        <asp:ImageButton id=Button2 runat="server"
            ImageUrl="images/banana.jpg"
            CssClass="removeBorder"
            BorderWidth="0.2cm"
            onmouseover="this.className='applyBorder'"
            onmouseout="this.className='removeBorder'"
            onclick="Button2_Click" />

            &nbsp;&nbsp;
            Applies a predefined CSS style...

        <br>

        <asp:ImageButton id=Button3 runat="server"
            ImageUrl="images/banana.jpg"
            BorderWidth="0.2cm"
            BorderColor="Gainsboro"
            onmouseover="this.src='images/mango.jpg';"
            onmouseout="this.src='images/banana.jpg';"
            onclick="Button3_Click" />

            &nbsp;&nbsp;
            Changes the source image...

        <p>
        
        <asp:Label id=Label1 runat=server />

    </form>

</body>
</html>


