<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Managing Your ASP.NET Application</h2>

<div class="new">

<h3>What's New in 2.0</h3>

<ul>
  <li><b>Configuration API - </b>The configuration API allows you to write programs and tools to examine and 
modify application configuration, using a full strongly typed configuration API
that even works on remote computers.</li>
  <br /><br />
  <li><b>New Configuration Tools - </b>ASP.NET 2.0 includes rich management tools you can use to easily edit
application configuration settings in the IIS Administration Manager and
in Visual Studio 2005.</li>
  <br /><br />
  <li><b>Configuration Encryption - </b>ASP.NET 2.0 allows you to protect your sensitive settings using
built-in support for encrypting configuration sections.</li>
</ul>

This section describes these and other management features in ASP.NET 2.0.
</div>

<br /><br />

A central requirement of any Web application server is a rich and flexible configuration 
and management system -- one that enables you to easily associate settings 
with an installable application (without having to "bake" values into code) and 
enables administrators to easily manage and customize these values after deployment.  
ASP.NET includes a configuration system designed to meet the needs of both of
these audiences; it provides a hierarchical configuration infrastructure that enables extensible
configuration data to be defined and used throughout an application, site, and/or machine. 
And, ASP.NET includes a full suite of tools to configure web applications.
    
ASP.NET has the following features for configuration and management of web applications:
</p>
<ul>
<li>ASP.NET allows configuration settings to be stored together with static content, dynamic pages,
and business objects within a single application directory hierarchy.  A user or administrator
simply needs to copy a single directory tree to set up an ASP.NET Framework application on a machine.
Changes to ASP.NET configuration files are automatically detected by the system and are applied
without requiring any user intervention (in other words, an administrator does not need to restart
the Web server or reboot the machine for them to take effect).
<p>

<li>Configuration data is stored in plain text files that are both human-readable and
human-writable.  Administrators and developers can use any standard text editor, XML parser,
or scripting language to interpret and update configuration settings. However, ASP.NET 2.0 now also 
includes a set of configuration tools that can be used to visually configure a web application.
<p>

<li>ASP.NET 2.0 now includes a full configuration management API that enables you
to examine, read and modify configuration settings through a clean, strongly typed programming model.
The management API automatically handles merging and unmerging settings inherited through
the configuration hierarchy, allowing you to work with settings as simple objects.
The configuration management API can even be used to edit configuration files on a remote computer.
<p>

<li>ASP.NET provides an extensible configuration infrastructure that enables you
to create your own configuration sections, define the persistence format of your configuration
settings, intelligently participate in their processing, and control the resulting object
model through which those settings are ultimately exposed.
<p>

<li>Also new to ASP.NET 2.0 is the ability to encrypt individual configuration sections,
which allows you to protect sensitive configuration settings like
passwords and database connection strings.

</ul>

<p>
To learn more about the ASP.NET configuration system, see 
<a href="fileformat.aspx">Configuration File Format</a> and <a href="retrieve.aspx">Retrieving Configuration</a>.
To see how to use the new Configuration Management API to edit configuration, see
<a href="mgmtapi.aspx">Using the Management API</a>.
To look at tools available in ASP.NET for managing web applications, see
<a href="tools.aspx">Using Management Tools</a>.
<br /><br />

</asp:Content>

