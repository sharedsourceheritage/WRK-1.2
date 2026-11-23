<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Retrieving Configuration</h2>

You can access configuration settings from within an ASP.NET application by using either the 
<b>ConfigurationManager</b> class, or the <b>GetConfig</b> or <b>GetAppConfig</b> method of the current <b>HttpContext</b>.
The object returned by <b>ConfigurationManager.GetSection</b>
depends on the section type mapped to the configuration section.
<p>
The following code demonstrates how you can access the configuration data exposed for a <b>&lt;customConfig&gt;</b>
section.  In this example, it is assumed that the configuration section handler returns an object of type
<b>CustomConfigSettings</b> with the property <b>Enabled</b>.

<p>
<Acme:TabControl runat="server">

<Tab Name="C#">
CustomConfigSettings settings = (CustomConfigSettings)ConfigurationManager.GetSection("customConfig");
if (settings.Enabled) {
    // Do something here.
}
</Tab>

<Tab Name="VB">
Dim settings as CustomConfigSettings = CType(ConfigurationManager.GetSection("customConfig"), CustomConfigSettings)
If settings.Enabled
    ' Do something here.
End If
</Tab>

</Acme:TabControl>

<p>

Note: the runtime API will return a read-only instance of the configuration section. 
<p>

<a name="appsettings"></a>
<h3>Using Application Settings</h3>
Configuration files are perfectly suited for storing custom application settings, such as database
file paths, or remote XML Web service URLs. The default configuration sections (defined
in the machine.config file) include an <b>&lt;appSettings&gt;</b> section that may be used to store these settings as name/value
pairs.  The following example shows an <b>&lt;appSettings&gt;</b> configuration section that defines 
web service URLs for an application

<p>
<pre class="code">
&lt;configuration&gt;
  &lt;appSettings&gt;
    &lt;add key="currencyService" value="http://www.microsoft.com/services/currencyService.asmx" /&gt;
    &lt;add key="creditCardValidationService" value="http://www.microsoft.com/services/cc.asmx" /&gt;
  &lt;/appSettings&gt;
&lt;/configuration&gt;
</pre>
<p>
The <b>ConfigurationManager</b> object exposes a special <b>AppSettings</b> property that you can use to retrieve
these settings:
<p>
<Acme:TabControl runat="server">

<Tab Name="C#">
String service = ConfigurationManager.AppSettings["currencyService"];
</Tab>

<Tab Name="VB">
Dim service As String = ConfigurationManager.AppSettings("currencyService")
</Tab>

</Acme:TabControl>
<p>

The following sample illustrates this technique.
<p>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/management/AppSettings/UsingAppSettings_cs.aspx"
        ViewSource="~/aspnet/samples/management/AppSettings/UsingAppSettings.src"
        Caption="C# Using Application Settings"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/management/AppSettings/UsingAppSettings_vb.aspx"
        ViewSource="~/aspnet/samples/management/AppSettings/UsingAppSettings.src"
        Caption="VB Using Application Settings"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="connectionstrings"></a>
<h3>Using Connection Strings</h3>
Like general application settings, ASP.NET provides a configuration section specifically for storing
database connection strings, used by ADO.NET.
The following example shows a <b>&lt;connectionString&gt;</b> configuration section for an application
that uses the Northwind sample database.

<p>
<pre class="code">
&lt;configuration&gt;
  &lt;connectionStrings&gt;
    &lt;add name="northwind" 
          connectionString="server=(local)\SQLExpress;database=Northwind;Integrated Security=SSPI" 
          providerName="System.Data.SqlClient" /&gt;
  &lt;/connectionStrings&gt;
&lt;/configuration&gt;
</pre>
<p>

The <b>ConfigurationManager</b> object exposes a special <b>ConnectionStrings</b> property that you can use to retrieve
these settings. 
<p>
<Acme:TabControl runat="server">

<Tab Name="C#">
SqlConnection connection = new SqlConnection(ConfigurationManager.ConnectionStrings["northwind"].Name);
</Tab>

<Tab Name="VB">
Dim connection As SqlConnection = New SqlConnection(ConfigurationManager.ConnectionStrings("northwind").Name)
</Tab>

</Acme:TabControl>
<p>
If the <b>providerName</b> property of each connection string is set, you can use it to create and connect to
the database generically using ADO.NET provider factories, rather than using 
code specific to the type of ADO.NET provider.
The following sample illustrates this technique.
<p>
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/management/ConnectionStrings/UsingConnectionStrings_cs.aspx"
        ViewSource="~/aspnet/samples/management/ConnectionStrings/UsingConnectionStrings.src"
        Caption="C# Using Connection Strings"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/management/ConnectionStrings/UsingConnectionStrings_vb.aspx"
        ViewSource="~/aspnet/samples/management/ConnectionStrings/UsingConnectionStrings.src"
        Caption="VB Using Connection Strings"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br /><br />

</asp:Content>

