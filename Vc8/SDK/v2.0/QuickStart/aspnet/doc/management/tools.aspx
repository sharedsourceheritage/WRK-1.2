<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Using Management Tools</h2>

ASP.NET 2.0 includes a full range of management tools that you can use to 
configure your web application:
<ul>
<li>
An <b>ASP.NET Microsoft Management Console Snapin</b> that integrates with the Internet Information Services (IIS)
MMC administration tool, allowing you to change the ASP.NET version of any 
IIS application, and inspect and change many common settings of ASP.NET 2.0 applications.<br><br>
<li>
A <b>Web Application Administration Tool</b> integrated with all versions of Visual Studio,
allowing you to configure application configuration such as authentication and
authorization settings.<br><br>
<li>
<b>Command line tools</b> such as aspnet_regsql, which allows you to configure
your SQL database for use with ASP.NET, and aspnet_regiis, which allows you to 
configure common ASP.NET settings from the command line,
</ul>

<a name="mmc"></a>
<h3>ASP.NET MMC Snapin</h3>
The ASP.NET MMC Snapin is integrated into the IIS MMC administration tool. To use the snapin,
use the following steps:

<ol>
<li>Open the IIS MMC console, by using <b>Administrative Tools/Internet Information Services</b>.
<br><br>
<li>Select the application or directory you want to configure, and select <b>Properties</b> from the <b>Action</b> menu.
<br><br>
<li>From the property sheet, click on the ASP.NET tab.
<br><br>
<li>On this tab, you can review or change the ASP.NET version used for the current application. 
Any change you make to this setting applies to all child applications.
<br><br>
<img src="../../images/mmc1.gif" alt="ASP.NET tab" /><br><br>
<li>To make changes to configuration settings at this level, click on <b>Edit configuration</b>.
A separate window will open, allowing you to inspect or change settings. Click OK to apply settings and close
the window.
<br><br>
<img src="../../images/mmc2.gif" alt="Edit configuration dialog" /><br><br>
</ol>
<p>
<a name="webadmin"></a>
<h3>Web Application Administration Tool</h3>
One of the new features for web developers in Visual Studio 2005 is a graphical administration
tool for configuring common application and security settings for your web sites. 
The Web Application Administration tool allows you to perform the following configuration tasks:
<ul>
<li>Configure application security, including authentication and authorization settings
<li>Manage users and roles for your application
<li>Create or manage application settings
<li>Configure SMTP e-mail settings
<li>Take an application temporarily offline, to allow reliable updates of content and data
<li>Adjust debugging and tracing settings
<li>Define a default custom error page
<li>Select providers for use with site features such as membership
</ul>
<p>
The Web Application Administration tool is available with all versions of Visual
Studio 2005, and from Visual Studio 2005 Express Edition.
To open the administration tool from a web site project, select <b>ASP.NET Configuration</b>
from the <b>Website</b> menu.
<p>
<img src="../../images/admin.jpg" alt="Web administration tool" /><br />
<p>
<a name="regsql"></a>
<h3>The ASPNET_REGSQL Tool</h3>
ASP.NET 2.0 has a number of application services that can be configured to use
a SQL Server database, including session state, membership, role manager, profiles,
personalization, SQL web event provider, and SQL cache invalidation.
<p>
Each of these features require that ASP.NET and the database be configured to set up
permissions, and create and prepopulate databases as needed. To configure and install databases
on a SQL server to use these ASP.NET features, you can use the <b>aspnet_regsql</b> tool. This tool
can be found in the version-specific framework directory, under the <b>Microsoft.NET\Framework</b>
subdirectory of your Windows system folder.
<p>
The aspnet_regsql tool can be used either as a command line tool or a wizard. To run
the tool as a wizard, you can run it without any command line arguments. To see a list
of available options, run <b>aspnet_regsql -?</b>.
<p>
<a name="regiis"></a>
<h3>The ASPNET_REGIIS Tool</h3>

The .NET Framework redistributable includes a command line tool, called <b>aspnet_regiis</b>, 
for installing and uninstalling ASP.NET and features on sites. 
You can also use this tool to manage configuration encryption features.
<p>
Each version of the .NET Framework includes an ASPNET_REGIIS tool. To configure a
particular version of ASP.NET, you need to locate and use the corresponding 
version of ASPNET_REGIIS. The tool can be found in the version-specific framework directory,
under the <b>Microsoft.NET\Framework</b> subdirectory of your Windows system folder.
<p>
The following are some examples of ASPNET_REGIIS command line syntax. For a list of all
options, enter <b>aspnet_regiis -?</b>.
<dl>
<dt><b>Install ASP.NET</b>
<dd>To install a version ASP.NET on a machine, and map all applications to use it,
use <b>aspnet_regiis -i</b>.<br>
<dd>To install without updating all applications to use ASP.NET 2.0, use <b>aspnet_regiis -ir</b>.<br><br>
<dt><b>Enable ASP.NET in the IIS 6.0 Security Console</b>
<dd>To enable ASP.NET as a valid extension for IIS 6.0, use <b>aspnet_regiis -i -enable</b> or <b>aspnet_regiis -ir -enable</b>,
depending on whether you want to map all existing applications to ASP.NET 2.0.<br>
<dd>To disable it, use <b>aspnet_regiis -i -disable</b> or <b>aspnet_regiis -ir -disable</b>.<br><br>
<dt><b>Uninstall ASP.NET</b>
<dd>To uninstall a version of ASP.NET, run <b>aspnet_regiis -u</b>. All existing
applications using this version will be remapped to the highest remaining version
of ASP.NET.<br>
<dd>To uninstall all versions, use <b>aspnet_regiis -ua</b>.<br><br>
<dt><b>Map an IIS application to an ASP.NET version</b>
<dd>To configure an IIS application to run a specific version of ASP.NET,
call <b>aspnet_regiis -s</b> <i>path</i> or <b>aspnet_regiis -sn</b> <i>path</i>.
<i>path</i> should be the IIS metabase path of the application, and is usually in the form
<b>w3svc/</b><i>site id</i><b>/root/</b><i>path from root to application</i></b>. For example,
the directory MyDir on the default web site has an IIS path of w3svc/1/root/MyDir.
<b>Note:</b> Using <b>-s</b> will recursively
map all child applications to the same version.
<br><br>
</dl>
<dt><b>List versions of ASP.NET</b>
<dd>To list all installed versions of ASP.NET on a computer, use <b>aspnet_regiis -lv</b>.<br>
<dd>To install specific mappings for individual directories, use <b>aspnet_regiis -lk</b>.<br><br>
<dt><b>Give a user permissions to access ASP.NET resources</b>
<dd>To give a specific Windows user account permissions to the IIS metabase, and to
special directories used by ASP.NET, use <b>aspnet_regiis -ga</b> <i>user</i>, where
<i>user</i> the user name. This option is helpful when configuring ASP.NET to run 
under a different user identity.<br><br>
</dl>
<br /><br />

</asp:Content>

