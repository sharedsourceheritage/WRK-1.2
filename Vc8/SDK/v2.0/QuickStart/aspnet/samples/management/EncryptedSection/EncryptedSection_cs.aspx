<%@ Import Namespace="System.Configuration" %>
<%@ Import Namespace="System.Web.Configuration" %>
<%@ Import Namespace="System.Xml" %>

  <script runat="server" language="C#">
    
    public void Page_Load(object source, EventArgs e)
    {
        if (!IsPostBack) {
            UpdateUI();
        }
    }

    void ProtectButton_OnClick(Object source, EventArgs e)
    {
        String path = Request.CurrentExecutionFilePath;
        path = path.Substring(0, path.LastIndexOf('/'));

        // Get configuration.
        Configuration config = WebConfigurationManager.OpenWebConfiguration(path);
        ConfigurationSection appSettings = config.GetSection("appSettings");
        if (appSettings.SectionInformation.IsProtected) 
        {
            appSettings.SectionInformation.UnprotectSection();
        }
        else
        {
            appSettings.SectionInformation.ProtectSection("DataProtectionConfigurationProvider");
        }

        try
        {
          config.Save();
          UpdateUI();
        }
        catch (Exception ex)
        {
          Response.Write("In order to modify configuration settings, the ASP.NET process account (either the local ASPNET or Network Service account, by default) ");
          Response.Write("must have write permission granted for the Web.config file in the sample directory");
        }
    }

    void UpdateUI()
    {
        String path = Request.CurrentExecutionFilePath;
        path = path.Substring(0, path.LastIndexOf('/'));

        // Get configuration.
        Configuration config = WebConfigurationManager.OpenWebConfiguration(path);

        // Show XML for app settings.
        ConfigurationSection appSettings = config.GetSection("appSettings");

        // Set protect button appropriately.
        if (appSettings.SectionInformation.IsProtected) 
        {
            Encrypted.Text = "Yes";
            ProtectButton.Text = "Unprotect";
        }
        else
        {
            Encrypted.Text = "No";
            ProtectButton.Text = "Protect";
        }

        // Show XML for app settings.
        AppSettingsXml.Text = "\r\n" + Server.HtmlEncode(appSettings.SectionInformation.GetRawXml());

        // Load XML directly from config file, to show encrypted XML.

        String configPath = Server.MapPath("web.config");
        XmlDocument doc = new XmlDocument();
        doc.PreserveWhitespace = true;
        doc.Load(configPath);
        XmlNode appSettingsXml = doc.SelectSingleNode("configuration/appSettings");
        AppSettingsEncrypted.Text = "\r\n" + Server.HtmlEncode(appSettingsXml.OuterXml);
    }

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
