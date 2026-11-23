<html>
<head>

    <script language="C#" runat="server">

        void SubmitBtn_Click(Object sender, EventArgs e) {
           Label1.Text = "You chose: " + DropDown1.SelectedItem.Text;
        }

    </script>

</head>
<body>

    <h3><font face="Verdana">DataBinding DropDownList</font></h3>

    <form runat=server>
    
        <asp:DropDownList id="DropDown1" DataSourceID="SqlDataSource1" 
          DataTextField="au_lname" DataValueField="au_id" runat="server" />

        <asp:SqlDataSource id="SqlDataSource1" 
          ConnectionString='<%$ ConnectionStrings:Pubs %>'
          SelectCommand="select DISTINCT au_id, au_lname from authors"
          runat="server"/>

        <asp:button Text="Submit" OnClick="SubmitBtn_Click" runat=server/>

        <p>
        
        <asp:Label id=Label1 Font-Names="Verdana" font-size="10pt" runat="server" />

    </form>

</body>
</html>

