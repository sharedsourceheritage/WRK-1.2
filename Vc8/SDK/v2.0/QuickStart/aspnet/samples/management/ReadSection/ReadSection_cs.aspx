<%@ Import Namespace="System.Configuration" %>
<%@ Import Namespace="System.Web.Configuration" %>
<%@ Import Namespace="System.IO" %>
<%@ Import Namespace="System.Xml" %>

  <script runat="server" language="C#">
    
    public void Page_Load(object source, EventArgs e)
    {
        // Determine current directory.
        String path = Request.CurrentExecutionFilePath;
        path = path.Substring(0, path.LastIndexOf('/'));
        AppPath.Text = path;

        // Open configuration.
        Configuration config = WebConfigurationManager.OpenWebConfiguration(path);

        // Get pages section.
        PagesSection pages = (PagesSection)config.GetSection("system.web/pages");
        EnableSessionState.Text = pages.EnableSessionState.ToString();
        EnableViewState.Text = pages.EnableViewState.ToString();
        MaxPageStateFieldLength.Text = pages.MaxPageStateFieldLength.ToString();
        AutoEventWireup.Text = pages.AutoEventWireup.ToString();

        // Get app settings XML, and write it.
        ConfigurationSection appSettings = config.GetSection("appSettings");
        AppSettingsXml.Text = "\r\n" + Server.HtmlEncode(appSettings.SectionInformation.GetRawXml());
    }

</script>

<html>
 <head>
   <title>Reading Configuration Sections</title>
 </head>
  <body>
    <form id="form1" runat="server">
      <div>
        <h2>Configuration Settings for <asp:Label runat="server" id="AppPath" /></h2>
        <h3>Pages</h3>
        <b>Enable Session State: </b><asp:Label runat="server" id="EnableSessionState" /><br/>
        <b>Enable Viewstate: </b><asp:Label runat="server" id="EnableViewState" /><br/>
        <b>Maximum Page State Field Length: </b><asp:Label runat="server" id="MaxPageStateFieldLength" /><br/>
        <b>Auto Event Wireup: </b><asp:Label runat="server" id="AutoEventWireup" /><br/>
        <h3>App Settings (Raw XML)</h3>
        <pre>
        <asp:Label runat="server" ID="AppSettingsXml" />
        </pre>
      </div>
    </form>
  </body>
</html>
