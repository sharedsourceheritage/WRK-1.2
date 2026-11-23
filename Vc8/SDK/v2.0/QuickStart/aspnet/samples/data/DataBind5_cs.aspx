<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >

    <head id="Head1" runat="server">
        <title>DataBinding to a Hashtable</title>
    </head>

    <script language="C#" runat="server">

        void Page_Load(Object sender, EventArgs e) {
            if (!Page.IsPostBack) {

                Hashtable h = new Hashtable();
                h.Add ("key1", "value1");
                h.Add ("key2", "value2");
                h.Add ("key3", "value3");

                MyDataList.DataSource = h;
                MyDataList.DataBind();
            }
        }

    </script>

<body>

    <h3 style="font-family:Verdana">DataBinding to a Hashtable</h3>

    <form action="DataBind5_cs.aspx" runat="server">

        <asp:DataList id="MyDataList" runat="server"
          BorderColor="black"
          BorderWidth="1"
          GridLines="Both"
          CellPadding="4"
          CellSpacing="0"
          >

            <ItemTemplate>
                <%# ((DictionaryEntry)Container.DataItem).Key %> :
                <%# ((DictionaryEntry)Container.DataItem).Value %>
            </ItemTemplate>

        </asp:DataList>

    </form>

</body>
</html>
