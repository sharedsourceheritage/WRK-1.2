<%@ Import Namespace="System.Configuration" %>
<%@ Import Namespace="System.Web.Configuration" %>

  <script runat="server" language="C#">
    
    public void Page_Load(object source, EventArgs e)
    {
        if (!IsPostBack) {
            NameValueCollection appSettings = ConfigurationManager.AppSettings;
            AppSettingsList.DataSource = appSettings.Keys;
            AppSettingsList.DataBind();
        }
    }

    void AppSettingsList_SelectedIndexChanged(Object source, EventArgs e)
    {
        AppSettingValue.Text = ConfigurationManager.AppSettings[AppSettingsList.SelectedValue];
    }

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
