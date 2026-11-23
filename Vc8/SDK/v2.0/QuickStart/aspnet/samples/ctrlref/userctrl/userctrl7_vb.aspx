<%@ Register TagPrefix="Acme" TagName="BookList" Src="userctrl7_vb.ascx" %>

<html>

    <script language="VB" runat="server">

        Sub Page_Load(Sender As Object, E As EventArgs)

            Page.Controls.Add(New HtmlGenericControl("hr"))

            Dim c1 As Control = LoadControl("userctrl7_vb.ascx")
            CType(c1, UserCtrl7VB).Category = "business"
            Page.Controls.Add(c1)

            Page.Controls.Add(New HtmlGenericControl("hr"))

            Dim c2 As Control = LoadControl("userctrl7_vb.ascx")
            CType(c2, UserCtrl7VB).Category = "trad_cook"
            Page.Controls.Add(c2)

            Page.Controls.Add(New HtmlGenericControl("hr"))

            Dim c3 As Control = LoadControl("userctrl7_vb.ascx")
            CType(c3, UserCtrl7VB).Category = "mod_cook"
            Page.Controls.Add(c3)
        End Sub

    </script>

<body style="font: 10pt verdana">

  <h3>Creating User Controls Programmatically</h3>

</body>
</html>
