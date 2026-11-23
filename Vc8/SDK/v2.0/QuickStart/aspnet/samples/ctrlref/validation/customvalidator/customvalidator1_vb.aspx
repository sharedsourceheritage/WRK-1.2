<html>
<head>
    <script language="VB" runat=server>

        Sub ValidateBtn_OnClick(sender As Object, e As EventArgs)
            If (Page.IsValid) Then
               lblOutput.Text = "Page is valid!"
            Else
               lblOutput.Text = "Page is not valid! :-("
            End If
        End Sub

	Sub ServerValidate (sender As Object, value As ServerValidateEventArgs)
	    Dim num As Integer
            ' even number?
	    If Integer.TryParse(value.Value, num) Then
	        value.IsValid = (num Mod 2 = 0)
	    
	    Else 
	        value.IsValid = false
	    End If
	End Sub

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

    &nbsp&nbsp

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
