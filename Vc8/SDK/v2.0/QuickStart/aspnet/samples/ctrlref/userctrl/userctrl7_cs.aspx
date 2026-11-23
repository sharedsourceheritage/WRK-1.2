<%@ Register TagPrefix="Acme" TagName="BookList" Src="userctrl7_cs.ascx" %>

<html>

    <script language="C#" runat="server">

        void Page_Load(Object sender, EventArgs E) {

            Page.Controls.Add(new HtmlGenericControl("hr"));

            Control c1 = LoadControl("userctrl7_cs.ascx");
            ((UserCtrl7CS)c1).Category = "business";
            Page.Controls.Add(c1);

            Page.Controls.Add(new HtmlGenericControl("hr"));

            Control c2 = LoadControl("userctrl7_cs.ascx");
            ((UserCtrl7CS)c2).Category = "trad_cook";
            Page.Controls.Add(c2);

            Page.Controls.Add(new HtmlGenericControl("hr"));

            Control c3 = LoadControl("userctrl7_cs.ascx");
            ((UserCtrl7CS)c3).Category = "mod_cook";
            Page.Controls.Add(c3);
        }

    </script>

<body style="font: 10pt verdana">

  <h3>Creating User Controls Programmatically</h3>

</body>
</html>
