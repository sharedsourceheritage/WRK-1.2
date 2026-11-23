<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >

    <head id="Head1" runat="server">
        <title>DataBinding DropDownList</title>
    </head>

    <script language="VB" runat="server">

        Sub Page_Load(sender As Object, e As EventArgs) 
            If Not IsPostBack Then

               Dim values as ArrayList= new ArrayList()

               values.Add ("IN")
               values.Add ("KS")
               values.Add ("MD")
               values.Add ("MI")
               values.Add ("OR")
               values.Add ("TN")

               DropDown1.DataSource = values
               DropDown1.DataBind
            End If
        End Sub

        Sub SubmitBtn_Click(sender As Object, e As EventArgs)
           Label1.Text = "You chose: " + DropDown1.SelectedItem.Text
        End Sub

    </script>

<body>

    <h3 style="font-family:Verdana">DataBinding DropDownList</h3>

    <form action="DataBind3_vb.aspx" runat="server">
    
        <asp:DropDownList id="DropDown1" runat="server" />

        <asp:button ID="Button1" Text="Submit" OnClick="SubmitBtn_Click" runat="server"/>

        <br />
        
        <asp:Label id="Label1" font-names="Verdana" font-size="10pt" runat="server" />

    </form>

</body>
</html>

