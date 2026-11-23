<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Using the Management API</h2>

ASP.NET 2.0 now includes a full configuration management API that enables
you to navigate, read, and write application configuration.
The management API has the following benefits:
<ul>
<li>Configuration settings are exposed as a set of strongly typed objects
that you can easily program against.
<br><br>
<li>The management API includes built-in support for configuration inheritance.
At each level of the application hierarchy, the management API provides
a readable view that represents the merged configuration settings that apply to 
that level. When you modify these settings, the API automatically
"unmerges" these settings, calculating and writing out the correct set of overrides
at that node.
<br><br>
<li>You can easily navigate the configuration hierarchy of the entire application.
<br><br>
<li>You can use the management API to read and write configuration settings of local
and remote web applications.
<br><br>
<li>New configuration sections written using the configuration API are automatically
manageable through the configuration API.</a>
</ul>

To open a configuration file, you use one of several static members on the
<b>System.Configuration.ConfigurationManager</b> or the <b>System.Web.Configuration.WebConfigurationManager</b>
classes. Each of these members returns a <b>System.Configuration.Configuration</b>
object representing the merged configuration settings for the corresponding level.
The following are some examples:

<p>
<pre class="code">
<b>1. Open machine.config on the local machine.</b>
WebConfigurationManager.OpenMachineConfiguration()

<b>2. Open root web.config on the local machine.</b>
WebConfigurationManager.OpenWebConfiguration(null)

<b>3. Open web.config for the application at the root of the default web site.</b>
WebConfigurationManager.OpenWebConfiguration("/")

<b>4. Open web.config for a subdirectory of the application found at /MyApp.</b>
WebConfigurationManager.OpenWebConfiguration("/MyApp/subdir")

<b>5. Open web.config for an application at the root of another site.</b>
WebConfigurationManager.OpenWebConfiguration("/", "Another Site")

<b>6. Open the &lt;location&gt; tag for a subdirectory at the application level.</b>
WebConfigurationManager.OpenWebConfiguration("/", null, "/subdir")

<b>7. Open machine.config on another computer, using credentials provided.</b>
WebConfigurationManager.OpenMachineConfiguration(null, "remotemachine", "user", "password")
</pre>

<p>
To open and read a configuration, you must have read privileges for the directory
that contains the configuration, as well as all directories that are in the parent
hierarchy (including machine.config). To write a configuration, you must also have
write and create privileges for the directory that contains the configuration. 
<p>
<a name="examine"></a>
<h3>Examining Configuration Settings</h3>
The Configuration object contains a hierarchy of configuration sections and 
configuration section groups, corresponding to the hierarchy of sections and groups in the configuration file.
To obtain the root of this hierarchy, you can call the <b>Configuration.RootSectionGroup</b>
property. From this object, you can navigate the <b>Sections</b> collection, which contains
all sections that are direct children of the section group, or the <b>SectionGroups</b> collection,
which contain all section groups that are direct children.
The collections returned contain all configuration sections and groups that are
hierarchically inherited by the current level of configuration, and not just sections
that are physically declared at the current level.
<p>
You can also access a section directly by calling the <b>Configuration.GetSection</b> method,
passing in the path to the section required.
<p>
The following example opens the configuration file for its own root, and
recursively enumerates all the section groups and sections. 
<p>
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/management/EnumerateSections/EnumerateSections_cs.aspx"
        ViewSource="~/aspnet/samples/management/EnumerateSections/EnumerateSections.src"
        Caption="C# Enumerating Configuration Sections"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/management/EnumerateSections/EnumerateSections_vb.aspx"
        ViewSource="~/aspnet/samples/management/EnumerateSections/EnumerateSections.src"
        Caption="VB Enumerating Configuration Sections"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<p>
Configuration sections are represented by the <b>ConfigurationSection</b> type. Each
section returned is typically a strongly typed object that inherits from this type.
The returned object includes all property values that are hiearchically inherited
by the current level of configuration, and not just values that are declared at the current level.
<p>
All sections also allow you to read and write their raw XML. This is useful particularly
for legacy third-party ASP.NET 1.x sections that do not support a strongly typed management API.
The raw XML returned is for the current level only, and does not automatically reflect
inherited settings.
<p>
The following example opens the configuration file for its own root, and displays
strongly typed settings for the &lt;pages&gt; section, and the raw XML for the &lt;appSettings&gt;
section. Note that all inherited values for the &lt;pages&gt; section are shown, even though
the web.config for this application does not contain such a section.
<p>
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/management/ReadSection/ReadSection_cs.aspx"
        ViewSource="~/aspnet/samples/management/ReadSection/ReadSection.src"
        Caption="C# Reading Configuration Sections"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/management/ReadSection/ReadSection_vb.aspx"
        ViewSource="~/aspnet/samples/management/ReadSection/ReadSection.src"
        Caption="VB Reading Configuration Sections"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<p>
<a name="update"></a>
<h3>Updating Configuration Settings</h3>
To update a configuration setting, you can simply set the corresponding property on
a ConfigurationSection object, and then call the <b>Save</b> method on the Configuration
object. 
<p>
Although the ConfigurationSection object provides a merged view of settings hierarchically
inherited by the current level of configuration, the management API keeps track of
settings specifically applied at the current level. When you call Save, only these
settings are physically written to the configuration file at the current level.
<p>
The following example modifies an application setting for the current application using
the management API.
<p>
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/management/WriteSection/WriteSection_cs.aspx"
        ViewSource="~/aspnet/samples/management/WriteSection/WriteSection.src"
        Caption="C# Writing Configuration Sections"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/management/WriteSection/WriteSection_vb.aspx"
        ViewSource="~/aspnet/samples/management/WriteSection/WriteSection.src"
        Caption="VB Writing Configuration Sections"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<p>
<a name="encrypt"></a>
<h3>Encypting a Section</h3>
Some configuration sections may contain sensitive data such as usernames and passwords.
Although ASP.NET configures IIS to prevent browser access to web.config files,
it is nonetheless a good practice to never store such data as plain text in a configuration
file. ASP.NET 2.0 now allows you to encrypt individual sections of a configuration file,
so that they are virtually impossible to read using a text editor.
<p>
ASP.NET includes two built-in protected configuration providers: RSA and DPAPI
The DPAPI provider uses a machine-specific key, so you must physically encrypt the 
configuration settings on each machine.
The RSA provider, which is used by default, allows you the option to create an RSA key and install it on other
machines, so that you can copy the same configuration file between these machines. 
In addition, you can install other protected configuration providers for use with the system.
<p>
Calls to the configuration management API can transparently work with encrypted sections,
because the API automatically handles encryption and decryption.
To programmatically set a configuration section to be encrypted, you can get the
<b>ConfigurationSection.SectionInformation</b> property, and call the <b>ProtectSection</b> method,
passing in the protection provider of your choice.
To use the default provider, you can pass null or the empty string.
The <b>UnprotectSection</b> method turns off encryption of a section.
<p>
The following example shows how sections can be programmatically encrypted, and how the
configuration API automatically handles encrypted sections.
<p>
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/management/EncryptedSection/EncryptedSection_cs.aspx"
        ViewSource="~/aspnet/samples/management/EncryptedSection/EncryptedSection.src"
        Caption="C# Encrypted Configuration Sections"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/management/EncryptedSection/EncryptedSection_vb.aspx"
        ViewSource="~/aspnet/samples/management/EncryptedSection/EncryptedSection.src"
        Caption="VB Encrypted Configuration Sections"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<p>
You can also use the <b>aspnet_regiis</b> command line tool to encrypt configuration sections.
To see available encryption options, run this tool with the <b>/?</b> option. For details on
how to run aspnet_regiis, see <a href="tools.aspx#regiis">The ASPNET_REGIIS Tool</a>.
<br /><br />

</asp:Content>

