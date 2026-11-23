<%@ Import Namespace="System.Data" %>
<%@ Import Namespace="System.Data.SqlClient" %>

<html>

<script language="VB" runat="server">

    Dim MyConnection As SqlConnection

    Sub Page_Load(Sender As Object, E As EventArgs)

    MyConnection = New SqlConnection(ConfigurationManager.ConnectionStrings("Pubs").ConnectionString)

        If Not (Page.IsPostBack)

            Dim DS As New DataSet
            Dim MyCommand As New SqlDataAdapter("select * from Titles where type = 'business'", MyConnection)

            MyCommand.Fill(DS, "Titles")

            MyDataList.DataSource = DS.Tables("Titles").DefaultView
            MyDataList.DataBind()

        End If
    End Sub

    Sub MyDataList_Select(Sender As Object, E As EventArgs)

        Dim Title As String = MyDataList.DataKeys(MyDataList.SelectedItem.ItemIndex)
        Dim MyCommand As New SqlDataAdapter("select * from Titles where title_id = '" & Title & "'" , MyConnection)

        Dim DS As New DataSet
        MyCommand.Fill(DS, "TitleDetails")

        Dim RowView As DataRowView = DS.Tables("TitleDetails").DefaultView(0)

    DetailsImage.Src = "images/" & RowView("title_id") & ".gif"
        DetailsPubId.InnerHtml = "<b>Publisher ID: </b>" & RowView("pub_id").ToString() & "<br>"
        DetailsTitleId.InnerHtml = "<b>Title ID: </b>" & RowView("title_id").ToString() & "<br>"
        DetailsType.InnerHtml = "<b>Category: </b>" & RowView("type").ToString() + "<br>"
        DetailsPrice.InnerHtml = "<b>Price: </b> $ " & RowView("price").ToString() + "<p>"
        PurchaseLink.InnerHtml = "<img alt='purchase book' border='0' src='images/purchase_book.gif' >"
        PurchaseLink.HRef="purchase_vb.aspx?titleid=" & RowView("title_id").ToString()
        DetailsTitle.InnerHtml = RowView("title").ToString()

        DetailsImage.Visible = true

    End Sub

</script>

<body topmargin="0" leftmargin="0">

  <form runat="server">

  <!-- #include virtual="header.inc" -->

  <table width="100%">
    <tr>
      <td width="50%">

        <ASP:DataList id="MyDataList" OnSelectedIndexChanged="MyDataList_Select" DataKeyField="title_id" runat="server">

          <ItemTemplate>

            <table cellpadding=10 style="font: 10pt verdana">
              <tr>
                <td valign="top">
                  <img alt="book image" align="top" width="25" border=1 src='<%# DataBinder.Eval(Container.DataItem, "title_id", "images/{0}.gif") %>' runat="server"/>
                </td>
                <td valign="top">
                  <b>Title: </b>
                  <asp:linkbutton Text='<%# DataBinder.Eval(Container.DataItem, "title") %>' CommandName="Select" style="color:darkred" runat="server"/>
                  <br>
                  <b>Price: </b><%# DataBinder.Eval(Container.DataItem, "price", "$ {0}") %><br>
                </td>
              </tr>
            </table>

          </ItemTemplate>

        </ASP:DataList>

      </td>

      <td valign="top" style="padding-top:15" width="50%">
        <table cellpadding="5" width="100%" style="font: 10pt verdana">
          <tr>
            <td>
              <img alt="book image" id="DetailsImage" visible="false" runat="server">
            </td>
            <td valign="top" width="400">
              <div style="font: 12pt verdana;color:darkred">
                <i><b><span id="DetailsTitle" runat="server"/></b></i><br>
              </div>
              <span id="DetailsTitleId" runat="server"/>
              <span id="DetailsPubId" runat="server"/>
              <span id="DetailsType" runat="server"/>
              <span id="DetailsPrice" runat="server"/>
              <a id="PurchaseLink" runat="server"/>
            </td>
          </tr>
        </table>
      </td>

    </tr>
  </table>

  <!-- #include virtual="footer.inc" -->

  </form>

</body>
</html>
