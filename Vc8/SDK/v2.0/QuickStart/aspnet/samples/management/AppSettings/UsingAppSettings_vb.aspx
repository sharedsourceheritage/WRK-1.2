<%@ Import Namespace="System.Configuration" %>
<%@ Import Namespace="System.Web.Configuration" %>

  <script runat="server" language="vb">
    
    Public Sub Page_Load(source As Object, e As EventArgs)
        If Not IsPostBack
            Dim appSettings As NameValueCollection = ConfigurationManager.AppSettings
            AppSettingsList.DataSource = appSettings.Keys
            AppSettingsList.DataBind()
        End If
    End Sub

    Sub AppSettingsList_SelectedIndexChanged(source As Object, e As EventArgs)
        AppSettingValue.Text = ConfigurationManager.AppSettings(AppSettingsList.SelectedValue)
    End Sub

</script>

<html>
 <head>
   <title>Enumerating Application Settings</title>
 </head>
  <body>
    <form id="form1" runat="server">
      <div>
        <b>Application Setting:</b><br />
        <asp:DropDownList runat="server" id="AppSettingsList" AutoPostBack="true" OnSelectedIndexChanged="AppSettingsList_SelectedIndexChanged" /><br />
        <br />
        <b>Value:</b><br />
        <asp:Label runat="server" id="AppSettingValue" />
      </div>
    </form>
  </body>
</html>
