<%@ Import namespace="System.Data" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >

    <head id="Head1" runat="server">
        <title>Databinding to a DataView</title>
    </head>

    <script language="C#" runat="server">

        void Page_Load(Object sender, EventArgs e ) {
        
            if (!Page.IsPostBack) {
            
                DataTable dt = new DataTable();
                DataRow dr;

                dt.Columns.Add(new DataColumn("IntegerValue", typeof(Int32)));
                dt.Columns.Add(new DataColumn("StringValue", typeof(string)));
                dt.Columns.Add(new DataColumn("DateTimeValue", typeof(DateTime)));
                dt.Columns.Add(new DataColumn("BooleanValue", typeof(bool)));

                for (int i = 1; i <= 9; i++) {
                
                    dr = dt.NewRow();

                    dr[0] = i;
                    dr[1] = "Item " + i.ToString();
                    dr[2] = DateTime.Now;
                    dr[3] = (i % 2 != 0) ? true : false;

                    dt.Rows.Add(dr);
                }
           
                GridView1.DataSource = new DataView(dt);
                GridView1.DataBind();
            }
        }

    </script>

<body>

    <h3 style="font-family:Verdana">Databinding to a DataView</h3>

    <form action="DataBind4_cs.aspx" runat="server">

        <asp:GridView id="GridView1" runat="server"
          BorderColor="black"
          BorderWidth="1"
          GridLines="Both"
          CellPadding="3"
          CellSpacing="0"
          HeaderStyle-BackColor="#aaaadd"
        />

    </form>

</body>
</html>
