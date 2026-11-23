<%@ Import Namespace="System.Data" %>

<html>

  <script language="VB" runat="server">

      Sub Page_Load(Src As Object, E As EventArgs)
      
          Dim Source As DataView = Application("Source")
          MySpan.Controls.Add(New LiteralControl(Source.Table.TableName))
          MyGridView.DataSource = Source
          MyGridView.DataBind()
      End Sub

  </script>

<body>
<form runat="server">

  <h3><font face="Verdana">Reading Data in Application_OnStart</font></h3>
  <h4><font face="Verdana">XML Data for Table: <asp:PlaceHolder runat="server" id="MySpan"/></font></h4>

  <asp:GridView id="MyGridView" runat="server"
    Width="900"
    BackColor="#ccccff" 
    BorderColor="black"
    ShowFooter="false" 
    CellPadding=3 
    CellSpacing="0"
    Font-Names="Verdana"
    Font-Size="8pt"
    HeaderStyle-BackColor="#aaaadd"
    EnableViewState="false"
  />

</form>
</body>
</html>

