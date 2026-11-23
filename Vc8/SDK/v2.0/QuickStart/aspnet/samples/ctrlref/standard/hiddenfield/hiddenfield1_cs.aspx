<html>
<head>

    <script language="C#" runat="server">

       void Button1_Click(object sender, EventArgs e)
	   {
			if (HiddenField1.Value == String.Empty)
			   HiddenField1.Value = "0";
			
			//Increment the hidden field value by 1
			HiddenField1.Value = (Convert.ToInt32(HiddenField1.Value)+1).ToString();
			 
			Label1.Text = HiddenField1.Value;
       }

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
