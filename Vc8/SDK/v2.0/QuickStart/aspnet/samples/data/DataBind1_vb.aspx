<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >

    <head id="Head1" runat="server">
        <title>DataBinding to a Property on the Page</title>
    </head>
    
    <script language="VB" runat="server">

        Sub Page_Load(sender As Object, e As EventArgs) 
            Page.DataBind
        End Sub
        
        ReadOnly Property custID() As String
            Get
                Return "ALFKI"
            End Get
        End Property
        
        ReadOnly Property orderCount() As Integer
            Get
                Return 11
            End Get
        End Property    

    </script>

<body>

    <h3 style="font-family:Verdana">DataBinding to a Property on the Page</h3>

    <form action="DataBind1_vb.aspx" runat="server">
    
        Customer: <b><%# custID %></b><br />
        Open Orders: <b><%# orderCount %></b>

    </form>

</body>
</html>
