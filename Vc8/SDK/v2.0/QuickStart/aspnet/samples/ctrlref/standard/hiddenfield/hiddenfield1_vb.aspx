<html>
<head>

    <script language="VB" runat="server">

       Sub Button1_Click(sender As Object, e As EventArgs)
			if (HiddenField1.Value = Nothing)
			   HiddenField1.Value = "0"
			end if

			'Increment the hidden field value by 1			
			HiddenField1.Value = Convert.ToInt32(HiddenField1.Value)+1
			 
			Label1.Text = HiddenField1.Value
       End Sub

    </script>

</head>
<body>

    <h3><font face="Verdana">HiddenField</font></h3>

    <form runat=server>
		<asp:HiddenField id=HiddenField1 runat=Server />

        <asp:Button id=Button1 Text="Click Me" onclick="Button1_Click" runat="server" />
        Clicked <asp:Label id=Label1 Text="0" runat=server /> times

    </form>
	
</body>
</html>


