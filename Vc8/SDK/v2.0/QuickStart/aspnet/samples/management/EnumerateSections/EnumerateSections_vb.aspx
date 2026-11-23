<%@ Import Namespace="System.Configuration" %>
<%@ Import Namespace="System.Web.Configuration" %>
<%@ Import Namespace="System.IO" %>
<%@ Import Namespace="System.Xml" %>

  <script runat="server" language="VB">
    
    Public Sub Page_Load(source As Object, e As EventArgs)

        ' Determine current directory.
        Dim path As String = Request.CurrentExecutionFilePath
        path = path.Substring(0, path.LastIndexOf("/"))
        AppPath.Text = path

        ' Open configuration.
        Dim config As System.Configuration.Configuration = WebConfigurationManager.OpenWebConfiguration(path)

        ' Start with root section group, and enumerate recursively.
        Dim writer As StringWriter = New StringWriter()
        Dim xmlWriter As XmlTextWriter = New XmlTextWriter(writer)
        xmlWriter.Formatting = Formatting.Indented
        xmlWriter.WriteStartElement("configuration")
        Enumerate(config.RootSectionGroup, xmlWriter)
        xmlWriter.WriteFullEndElement()

        xmlWriter.Flush()
        ConfigSections.Text = Chr(13) & Chr(10) & Server.HtmlEncode(writer.ToString())
    End Sub

    Sub Enumerate(group As ConfigurationSectionGroup, writer As XmlWriter)

        Dim i As Integer

        ' Do all subgroups first.
        Dim subGroups As ConfigurationSectionGroupCollection = group.SectionGroups
        For i = 0 To subGroups.Count - 1
            writer.WriteStartElement(subGroups(i).Name)
            Enumerate(subGroups(i), writer)
            writer.WriteFullEndElement()
        Next

        ' Now do sections.
        Dim sections As ConfigurationSectionCollection = group.Sections
        For i = 0 To sections.Count - 1
            writer.WriteStartElement(sections(i).SectionInformation.Name)
            writer.WriteEndElement()
        Next
    End Sub

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
