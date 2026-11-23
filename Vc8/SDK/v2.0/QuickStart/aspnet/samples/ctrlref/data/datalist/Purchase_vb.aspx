<%@ Import Namespace="System.Data" %>
<%@ Import Namespace="System.Data.SqlClient" %>

<html>

<script language="VB" runat="server">

    Sub Page_Load(Sender As Object, E As EventArgs)
        If Not Request.QueryString("titleid") Is Nothing

                Dim DS As DataSet
                Dim MyConnection As SqlConnection
                Dim MyCommand As SqlDataAdapter

                Dim Query As String
                Query = "select * from Titles where title_id = @title_id"

                MyConnection = New SqlConnection(ConfigurationManager.ConnectionStrings("Pubs").ConnectionString)
                MyCommand = New SqlDataAdapter(Query, MyConnection)


                Dim param As SqlParameter = New SqlParameter("@title_id", DbType.String)
                param.Value = Server.HtmlEncode(Request.QueryString("titleid"))
                myCommand.SelectCommand.Parameters.Add(param)

                DS = New DataSet()
                MyCommand.Fill(DS, "Titles")

                MyDataList.DataSource = DS.Tables("Titles").DefaultView
                MyDataList.DataBind()
            End If

    End Sub


    Sub Submit_Click(Src As Object, E As EventArgs)

        Message.InnerHtml = "<h2>Purchase Made!!!</h2>"
    End Sub

</script>

<body topmargin="0" leftmargin="0" marginwidth="0" marginheight="0">

  <!-- #include virtual="header.inc" -->

  <form runat="server">

    <table>
      <tr>
        <td valign="top">

          <ASP:DataList id="MyDataList" runat="server">

              <ItemTemplate>

                <table cellpadding=10 style="font: 10pt verdana">
                  <tr>
                    <td width=1 bgcolor="BD8672"/>
                    <td valign="top">
                      <img alt="book image" align="top" src='<%# Eval("title_id", "images/{0}.gif") %>' >
                    </td>
                    <td valign="top">
                      <b>Title: </b><%# Eval("title") %><br>
                      <b>Category: </b><%# Eval("type") %><br>
                      <b>Publisher ID: </b><%# Eval("pub_id") %><br>
                      <b>Price: </b><%# Eval("price", "{0:c}") %><br>
                    </td>
                  </tr>
                </table>

              </ItemTemplate>

          </ASP:DataList>

        </td>
        <td valign="top" style="padding-top:15;font: 10pt verdana">

          Thank you for your business!  Please complete the form below to confirm your purchase.
          <p>
          <table style="font: 10pt verdana" cellpadding="3">
            <tr><td><b>Name: </b></td><td><input size="30" type="text" runat="server"></td></tr>
            <tr><td><b>Mailing Address: </b></td><td><input size="50" type="text" runat="server"></td></tr>
            <tr><td><b>Account Number: </b></td><td><input size="10" type="text" runat="server"></td></tr>
          </table>
          <p>
          <input type="submit" value="Purchase" runat="server" OnServerClick="Submit_Click"/>
          <p>

        </td>
      </tr>

    </table>

    <div style="font: 10pt verdana;padding:0,15,15,15" id="Message" runat="server"/>

  </form>

  <!-- #include virtual="footer.inc" -->

</body>
</html>
