<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>

<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Building a Web Application</h2>

<div class="new">

<h3>What's New in 2.0</h3>

<ul>
  <li><b>Dynamically Compiled Classes - </b> In addition to placing pre-compiled classes in the Bin directory, ASP.NET 2.0 now allows you to place shared class file sources in the App_Code directory, where they will be dynamically compiled just like ASPX pages.</li>
  <br /><br />
  <li><b>Simplified Code Behind Pages - </b> Code-behind files in ASP.NET 2.0 use a new language feature called partial classes, which allow code-behind files to be dynamically compiled with their associated ASPX pages into a single class type.  This means you no longer need to declare member variables in the code-behind page for each control, which greatly simplifies maintenance of sites that use this code-separation technique.</li>
  <br /><br />
  <li><b>Several New Server Controls - </b> ASP.NET 2.0 include over 50 new controls, making it easier than ever to create common UI elements in your web pages.  For example, the Data controls simplify data access scenarios, the Login controls add security to your site, the Navigation controls enable site navigation, and WebPart controls allow you to easily create personalized web pages.
  <br /><br />
  <li><b>New Declarative Expression Syntax - </b> The declarative expression syntax in ASP.NET 2.0 allows you to substitute application settings, connection strings, and localization resources into your pages before they are parsed and executed.
</ul>

This section discusses these and other features of basic ASP.NET applications.

</div>

<br /><br />

A web application in ASP.NET is a collection of pages, controls, code modules, and services all running under a single web server application directory (usually IIS).  ASP.NET makes it really easy to build the types of dynamic web applications that exist everywhere on the Internet today.  It provides a simple programming model based on the .NET Framework and several built-in controls and services that enable many of the common scenarios found in most applications, with very little effort or code.  In this section we demonstrate the basic elements of a web application that we will use throughout the remainder of Quickstart tutorial, including:

<ul>
  <li> The ASP.NET Page Framework (Web Forms)
  <li> Web and HTML Server Controls
  <li> Shared Code Modules or Assemblies
</ul>

This section also discusses a few improvements made to these application building blocks in ASP.NET 2.0 over previous versions of ASP.NET.

</asp:Content>

