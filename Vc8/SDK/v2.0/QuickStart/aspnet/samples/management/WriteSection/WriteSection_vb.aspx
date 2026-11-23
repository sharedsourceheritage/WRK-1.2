<%@ Import Namespace="System.Configuration" %>
<%@ Import Namespace="System.Web.Configuration" %>

  <script runat="server" language="VB">
    
    Public Sub Page_Load(source As Object, e As EventArgs)
    
        if Not IsPostBack
            
            Dim appSettings As NameValueCollection = ConfigurationManager.AppSettings
            AppSettingsList.DataSource = appSettings.Keys
            AppSettingsList.DataBind()
            ShowXml()

        End If

    End Sub

    Sub AppSettingsList_SelectedIndexChanged(source As Object, e As EventArgs)
    
        AppSettingValue.Text = ConfigurationManager.AppSettings(AppSettingsList.SelectedValue)

    End Sub

    Sub ModifySetting_OnClick(source As Object, e As EventArgs)
    
        Dim path As String = Request.CurrentExecutionFilePath
        path = path.Substring(0, path.LastIndexOf("/"))

        ' Get configuration.
        Dim config As System.Configuration.Configuration = WebConfigurationManager.OpenWebConfiguration(path)

        ' Find app setting to change
        Dim element As KeyValueConfigurationElement = CType(config.AppSettings.Settings(AppSettingsList.SelectedValue), KeyValueConfigurationElement)
        If Not element Is Nothing
            Dim value As Integer = Int32.Parse(AppSettingValue.Text)
            element.Value = value.ToString()
        Try
          config.Save()
          
          ' Redirect to self.
          Response.Redirect(Request.CurrentExecutionFilePath)

        Catch ex As Exception
          Response.Write("In order to modify configuration settings, the ASP.NET process account (either the local ASPNET or Network Service account, by default) ")
          Response.Write("must have write permission granted for the Web.config file in the sample directory")
        End Try
      End If
    End Sub

    Sub ShowXml()
    
        Dim path As String = Request.CurrentExecutionFilePath
        path = path.Substring(0, path.LastIndexOf("/"))

        ' Get configuration.
        Dim config As System.Configuration.Configuration = WebConfigurationManager.OpenWebConfiguration(path)

        ' Show XML for app settings.
        Dim appSettings As ConfigurationSection = config.GetSection("appSettings")
        AppSettingsXml.Text = Chr(13) & Chr(10) & Server.HtmlEncode(appSettings.SectionInformation.GetRawXml())

    End Sub

</script>

<html>
 <head>
   <title>Writing Configuration Sections</title>
 </head>
  <body>
    <form id="form1" runat="server">
      <div>
        <b>Application Setting:</b><br />
        <asp:DropDownList runat="server" id="AppSettingsList" AutoPostBack="true" OnSelectedIndexChanged="AppSettingsList_SelectedIndexChanged" /><br />
        <br />
        <b>Value (integer):</b><br />
        <asp:TextBox runat="server" id="AppSettingValue" />
        <asp:Button runat="server" id="ModifySetting" OnClick="ModifySetting_OnClick" Text="Modify" /> <br>
        <h2>Current XML:</h2>
        <pre>
        <asp:Label runat="server" ID="AppSettingsXml" />
        </pre>
      </div>
    </form>
  </body>
</html>
