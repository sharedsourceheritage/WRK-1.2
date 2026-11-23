<html>
<head>
    <script language="C#" runat=server>

        void ValidateBtn_OnClick(object sender, EventArgs e) {

            if (Page.IsValid) {
               lblOutput.Text = "Page is valid!";
            }
            else {
               lblOutput.Text = "Page is not valid! :-(";
            }
        }

	void ServerValidate (object source, ServerValidateEventArgs value) {
	    int num;
            // even number?
	    if (int.TryParse(value.Value, out num) ) {
	        value.IsValid = (num % 2 == 0);
	    }
	    else {
	        value.IsValid = false;
	    }
	}

   </script>

</head>
<body>

<h3><font face="Verdana">CustomValidator Example</font></h3>

<form runat="server">

    <asp:Label id=lblOutput runat="server"
        Text="Enter an even number:"
        Font-Names="Verdana"
        Font-Size="10pt" /><br>

    <p>

    <asp:TextBox id=Text1 runat="server" />

    &nbsp;&nbsp;

    <asp:CustomValidator id="CustomValidator1" runat="server"
        ControlToValidate="Text1"
        OnServerValidate="ServerValidate"
        Display="Static"
        Font-Names="verdana" Font-Size="10pt">
           Not an even number!
    </asp:CustomValidator>

    <p>

    <asp:Button text="Validate" onclick="ValidateBtn_OnClick" runat="server" />

</form>

</body>
</html>
