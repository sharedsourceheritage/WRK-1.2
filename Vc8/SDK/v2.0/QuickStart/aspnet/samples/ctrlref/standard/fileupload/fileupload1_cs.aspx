<html>
<head>

	<script language="C#" runat="server">
	
	void Button1_Click(object sender, EventArgs e)
	{
		if (FileUpLoad1.HasFile)
		{
			//Uncomment this line to Save the uploaded file
			//FileUpLoad1.SaveAs("C:\SomePhysicalPath" + FileUpLoad1.Filename);
			Label1.Text = "Received " + FileUpLoad1.FileName + " Content Type " + FileUpLoad1.PostedFile.ContentType + " Length " + FileUpLoad1.PostedFile.ContentLength;
		}
		else
		{
			Label1.Text = "No uploaded file";
		}
		
	}
	
	</script>

</head>
<body>

    <h3><font face="Verdana">File Upload</font></h3>

    <form runat=server>

		<asp:FileUpLoad id="FileUpLoad1" AlternateText="You cannot upload files" runat="server" />
		<asp:Button id="Button1" Text="Upload" OnClick="Button1_Click" runat="server" />
		<asp:Label id="Label1" runat="server" />
    </form>

</body>
</html>


