<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >

    <head id="Head1" runat="server">
        <title>DataBinding DropDownList</title>
    </head>

    <script language="C#" runat="server">

        void Page_Load(Object Sender, EventArgs E) {

            if (!Page.IsPostBack) {

               ArrayList values = new ArrayList();

               values.Add ("IN");
               values.Add ("KS");
               values.Add ("MD");
               values.Add ("MI");
               values.Add ("OR");
               values.Add ("TN");

               DropDown1.DataSource = values;
               DropDown1.DataBind();
            }
        }

        void SubmitBtn_Click(Object sender, EventArgs e) {
           Label1.Text = "You chose: " + DropDown1.SelectedItem.Text;
        }

    </script>

<body>

    <h3 style="font-family:Verdana">DataBinding DropDownList</h3>

    <form action="DataBind3_cs.aspx" runat="server">
    
        <asp:DropDownList id="DropDown1" runat="server" />

        <asp:button ID="Button1" Text="Submit" OnClick="SubmitBtn_Click" runat="server" />

        <br />
        
        <asp:Label ID="Label1" font-names="Verdana" font-size="10pt" runat="server" />

    </form>

</body>
</html>

