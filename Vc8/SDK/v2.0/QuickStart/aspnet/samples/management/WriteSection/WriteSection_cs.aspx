<%@ Import Namespace="System.Configuration" %>
<%@ Import Namespace="System.Web.Configuration" %>

  <script runat="server" language="C#">
    
    public void Page_Load(object source, EventArgs e)
    {
        if (!IsPostBack) {
            NameValueCollection appSettings = ConfigurationManager.AppSettings;
            AppSettingsList.DataSource = appSettings.Keys;
            AppSettingsList.DataBind();
            ShowXml();
        }
    }

    void AppSettingsList_SelectedIndexChanged(Object source, EventArgs e)
    {
        AppSettingValue.Text = ConfigurationManager.AppSettings[AppSettingsList.SelectedValue];
    }

    void ModifySetting_OnClick(Object source, EventArgs e)
    {
        String path = Request.CurrentExecutionFilePath;
        path = path.Substring(0, path.LastIndexOf('/'));

        // Get configuration.
        Configuration config = WebConfigurationManager.OpenWebConfiguration(path);

        // Find app setting to change
        KeyValueConfigurationElement element = (KeyValueConfigurationElement)config.AppSettings.Settings[AppSettingsList.SelectedValue];
        if (element != null) {
            int value = Int32.Parse(AppSettingValue.Text);
            element.Value = value.ToString();

            try
            {
              config.Save();

              // Redirect to self.
              Response.Redirect(Request.CurrentExecutionFilePath);
            }
            catch (Exception ex)
            {
              Response.Write("In order to modify configuration settings, the ASP.NET process account (either the local ASPNET or Network Service account, by default) ");
              Response.Write("must have write permission granted for the Web.config file in the sample directory");
            }              
        }
    }

    void ShowXml()
    {
        String path = Request.CurrentExecutionFilePath;
        path = path.Substring(0, path.LastIndexOf('/'));

        // Get configuration.
        Configuration config = WebConfigurationManager.OpenWebConfiguration(path);

        // Show XML for app settings.
        ConfigurationSection appSettings = config.GetSection("appSettings");
        AppSettingsXml.Text = "\r\n" + Server.HtmlEncode(appSettings.SectionInformation.GetRawXml());
    }

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
