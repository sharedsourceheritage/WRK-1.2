<%@ Import namespace="System.Data" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >

    <head id="Head1" runat="server">
        <title>Databinding Using DataBinder.Eval</title>
    </head>

    <script language="C#" runat="server">

        void Page_Load(Object sender, EventArgs e) {

            if (!Page.IsPostBack) {

                DataTable dt = new DataTable();
                DataRow dr;

                dt.Columns.Add(new DataColumn("IntegerValue", typeof(Int32)));
                dt.Columns.Add(new DataColumn("StringValue", typeof(string)));
                dt.Columns.Add(new DataColumn("DateTimeValue", typeof(DateTime)));
                dt.Columns.Add(new DataColumn("BoolValue", typeof(bool)));

                for (int i = 0; i < 9; i++) {

                    dr = dt.NewRow();

                    dr[0] = i;
                    dr[1] = "Item " + i.ToString();
                    dr[2] = DateTime.Now;
                    dr[3] = (i % 2 != 0) ? true : false;

                    dt.Rows.Add(dr);
                }

                dataList1.DataSource = new DataView(dt);
                dataList1.DataBind();
            }
        }

    </script>

<body>

    <h3 style="font-family:Verdana">Databinding Using DataBinder.Eval</h3>

    <form action="DataBind7_cs.aspx" runat="server">

        <asp:DataList id="dataList1" runat="server"
          RepeatColumns="3"
          Width="80%"
          BorderColor="black"
          BorderWidth="1"
          GridLines="Both"
          CellPadding="4"
          CellSpacing="0"
          >

            <ItemTemplate>

                Order Date: <%# DataBinder.Eval(Container.DataItem, "DateTimeValue", "{0:d}") %>

                <br /><br />

                Quantity: <%# DataBinder.Eval(Container.DataItem, "IntegerValue", "{0:N2}") %>

                <br /><br />

                Item: <%# DataBinder.Eval(Container.DataItem, "StringValue") %>

                Order Date: <asp:CheckBox id="chk1" Checked='<%# (bool)DataBinder.Eval(Container.DataItem, "BoolValue") %>' runat="server"/>

                <br /><br />

            </ItemTemplate>

        </asp:DataList>

    </form>

</body>
</html>
