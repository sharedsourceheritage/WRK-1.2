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

        // Start with root section group, and enumerate recursively.
        StringWriter writer = new StringWriter();
        XmlTextWriter xmlWriter = new XmlTextWriter(writer);
        xmlWriter.Formatting = Formatting.Indented;
        xmlWriter.WriteStartElement("configuration");
        Enumerate(config.RootSectionGroup, xmlWriter);
        xmlWriter.WriteFullEndElement();

        xmlWriter.Flush();
        ConfigSections.Text = "\r\n" + Server.HtmlEncode(writer.ToString());
    }

    void Enumerate(ConfigurationSectionGroup group, XmlWriter writer)
    {
        // Do all subgroups first.
        ConfigurationSectionGroupCollection subGroups = group.SectionGroups;
        for (int i = 0; i < subGroups.Count; i++) 
        {
            writer.WriteStartElement(subGroups[i].Name);
            Enumerate(subGroups[i], writer);
            writer.WriteFullEndElement();
        }

        // Now do sections.
        ConfigurationSectionCollection sections = group.Sections;
        for (int i = 0; i < sections.Count; i++) 
        {
            writer.WriteStartElement(sections[i].SectionInformation.Name);
            writer.WriteEndElement();
        }
    }

</script>

<html>
 <head>
   <title>Enumerating Configuration Sections</title>
 </head>
  <body>
    <form id="form1" runat="server">
      <div>
        <h2>Configuration Sections for <asp:Label runat="server" id="AppPath" /></h2>
        <pre>
            <asp:Label runat="server" id="ConfigSections" />
        </pre>
      </div>
    </form>
  </body>
</html>
