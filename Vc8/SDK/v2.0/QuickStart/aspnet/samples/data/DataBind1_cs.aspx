<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">

    <head id="Head1" runat="server">
        <title>DataBinding to a Property on the Page</title>
    </head>

    <script language="C#" runat="server">

        void Page_Load(Object sender, EventArgs e) {
            Page.DataBind();
        }
        
        string custID{
            get {
                return "ALFKI";
            }
        }
        
        int orderCount{
            get {
                return 11;
            }
        }


    </script>

<body>

    <h3 style="font-family:Verdana">DataBinding to a Property on the Page</h3>

    <form action="DataBind1_cs.aspx" runat="server">
    
        Customer: <b><%# custID %></b><br />
        Open Orders: <b><%# orderCount %></b>

    </form>

</body>
</html>
