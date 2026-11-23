<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >

    <head id="Head1" runat="server">
        <title>Databinding to Methods and Expressions</title>
    </head>

    <script language="C#" runat="server">

        void Page_Load(Object Src, EventArgs E) {

            if (!Page.IsPostBack) {

               ArrayList values = new ArrayList();

               values.Add (0);
               values.Add (1);
               values.Add (2);
               values.Add (3);
               values.Add (4);
               values.Add (5);
               values.Add (6);

               DataList1.DataSource = values;
               DataList1.DataBind();
            }
        }

        String EvenOrOdd(int number) {
            if ((number % 2) == 0)
              return "Even";
            else
              return "Odd";
        }

    </script>

<body>

    <h3 style="font-family:Verdana">Databinding to Methods and Expressions</h3>

    <form action="DataBind6_cs.aspx" runat="server">

      <asp:DataList id="DataList1" runat="server"
        BorderColor="black"
        BorderWidth="1"
        GridLines="Both"
        CellPadding="3"
        CellSpacing="0"
        >

        <ItemTemplate>
          Number Value: <%# Container.DataItem %>
          Even/Odd: <%# EvenOrOdd((int) Container.DataItem) %>
        </ItemTemplate>

      </asp:DataList>

    </form>

</body>
</html>
