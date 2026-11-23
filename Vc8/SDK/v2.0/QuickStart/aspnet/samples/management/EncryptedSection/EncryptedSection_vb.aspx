<%@ Import Namespace="System.Configuration" %>
<%@ Import Namespace="System.Web.Configuration" %>
<%@ Import Namespace="System.Xml" %>

  <script runat="server" language="VB">
    
    Public Sub Page_Load(source As Object, e As EventArgs)
        
        If Not IsPostBack
            UpdateUI()
        End If

    End Sub

    Sub ProtectButton_OnClick(source As Object, e As EventArgs)
    
        Dim path As String = Request.CurrentExecutionFilePath
        path = path.Substring(0, path.LastIndexOf("/"))

        ' Get configuration.
        Dim config As System.Configuration.Configuration = WebConfigurationManager.OpenWebConfiguration(path)
        Dim appSettings As ConfigurationSection = config.GetSection("appSettings")
        If (appSettings.SectionInformation.IsProtected) 
            appSettings.SectionInformation.UnprotectSection()
        Else
            appSettings.SectionInformation.ProtectSection("DataProtectionConfigurationProvider")
      End If
      Try
        config.Save()
        UpdateUI()
      Catch ex As Exception
        Response.Write("In order to modify configuration settings, the ASP.NET process account (either the local ASPNET or Network Service account, by default) ")
        Response.Write("must have write permission granted for the Web.config file in the sample directory")
      End Try

    End Sub

    Sub UpdateUI()

        Dim path As String = Request.CurrentExecutionFilePath
        path = path.Substring(0, path.LastIndexOf("/"))

        ' Get configuration.
        Dim config As System.Configuration.Configuration = WebConfigurationManager.OpenWebConfiguration(path)

        ' Show XML for app settings.
        Dim appSettings As ConfigurationSection = config.GetSection("appSettings")

        ' Set protect button appropriately.
        If (appSettings.SectionInformation.IsProtected) 
        
            Encrypted.Text = "Yes"
            ProtectButton.Text = "Unprotect"
        
        Else

            Encrypted.Text = "No"
            ProtectButton.Text = "Protect"

        End If

        ' Show XML for app settings.
        AppSettingsXml.Text = Chr(13) & Chr(10) & Server.HtmlEncode(appSettings.SectionInformation.GetRawXml())

        ' Load XML directly from config file, to show encrypted XML.

        Dim configPath As String = Server.MapPath("web.config")
        Dim doc As XmlDocument = New XmlDocument()
        doc.PreserveWhitespace = True
        doc.Load(configPath)
        Dim appSettingsXmlNode As XmlNode = doc.SelectSingleNode("configuration/appSettings")
        AppSettingsEncrypted.Text = Chr(13) & Chr(10) & Server.HtmlEncode(appSettingsXmlNode.OuterXml)

    End Sub

</script>

<html>
 <head>
   <title>Encrypted Configuration Sections</title>
 </head>
  <body>
    <form id="form1" runat="server">
      <div>
        <h2>Encrypted:<asp:Label runat="server" id="Encrypted" /></h2><asp:Button runat="server" id="ProtectButton" OnClick="ProtectButton_OnClick" />
        <h2>Current XML (decrypted):</h2>
        <pre>
        <asp:Label runat="server" ID="AppSettingsXml" />
        </pre>
        <h2>Encrypted contents:</h2>
        <pre>
        <asp:Label runat="server" ID="AppSettingsEncrypted" />
        </pre>
      </div>
    </form>
  </body>
</html>
