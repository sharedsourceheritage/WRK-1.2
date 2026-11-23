<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<%@ Page Language="C#" MasterPageFile="~/aspnet/aspnet.master" %>

<asp:Content ContentPlaceHolderID=MainBody Runat=Server>

<h2>What's New in ASP.NET 2.0?</h2>

<p>ASP.NET is a programming framework built on the common language runtime that can be used on a server to build 
powerful Web applications. The first version of ASP.NET offered several important advantages over previous Web development 
models. ASP.NET 2.0 improves upon that foundation 
by adding support for several new and exciting features in the areas of developer productivity, administration and management, extensibility, and performance: </p>

<h3>Developer Productivity</h3>

ASP.NET 2.0 encapsulates common Web tasks into application services and controls that can be easily reused across web sites.  With these basic building blocks, many scenarios can now be implemented with far less custom code than was required in previous versions.  With ASP.NET 2.0 it is possible to significantly reduce the amount of code and concepts necessary to build common scenarios on the web.

<ul>
  <li><b>New Server Controls.</b> ASP.NET 2.0 introduces many new server controls that enable powerful declarative support for data access, login security, wizard navigation, menus, treeviews, portals, and more.  Many of these controls take advantage of core application services in ASP.NET for scenarios like data access, membership and roles, and personalization. Some of the new families of controls in ASP.NET 2.0 are described below. <br /><br />

  <ul>
    <li><b>Data Controls.</b> Data access in ASP.NET 2.0 can be accomplished completely declaratively (no code) using the new data-bound and data source controls.  There are new data source controls to represent different data backends such as SQL database, business objects, and XML, and there are new data-bound controls for rendering common UI for data, such as gridview, detailsview, and formview..<br /><br />
    </li>
    <li><b>Navigation Controls.</b> The navigation controls provide common UI for navigating between pages in your site, such as treeview, menu, and sitemappath.  These controls use the site navigation service in ASP.NET 2.0 to retrieve the custom structure you have defined for your site.<br /><br />
    </li>
    <li><b>Login Controls.</b> The new login controls provide the building blocks to add authentication and authorization-based UI to your site, such as login forms, create user forms, password retrieval, and custom UI for logged in users or roles.  These controls use the built-in membership and role services in ASP.NET 2.0 to interact with the user and role information defined for your site. <br /><br />
    </li>
    <li><b>Web Part Controls.</b> Web parts are an exciting new family of controls that enable you to add rich, personalized content and layout to your site, as well as the ability to edit that content and layout directly from your application pages.  These controls rely on the personalization services in ASP.NET 2.0 to provide a unique experience for each user in your application. <br /><br />
    </li>
  </ul>
  </li>

  <li><b>Master Pages.</b> This feature provides the ability to define common structure and interface elements for your site, such as a page header, footer, or navigation bar, in a common location called a "master page", to be shared by many pages in your site.  In one simple place you can control the look, feel, and much of functionality for an entire Web site.  This improves the maintainability of your site and avoids unnecessary duplication of code for shared site structure or behavior.<br /><br />	
  </li>

  <li><b>Themes and Skins.</b> The themes and skins features in ASP.NET 2.0 allow for easy customization of your site's look-and-feel.  You can define style information in a common location called a "theme", and apply that style information globally to pages or controls in your site.  Like Master Pages, this improves the maintainability of your site and avoid unnecessary duplication of code for shared styles.<br /><br />	
  </li>
  <li><b>Personalization.</b> Using the new personalization services in ASP.NET 2.0 you can easily create customized experiences within Web applications.  The Profile object enables developers to easily build strongly-typed, sticky data stores for user accounts and build highly customized, relationship based experiences.  At the same time, a developer can leverage Web Parts and the personalization service to enable Web site visitors to completely control the layout and behavior of the site, with the knowledge that the site is completely customized for them.  Personalizaton scenarios are now easier to build than ever before and require significantly less code and effort to implement.<br /><br />	
  </li>
  <li><b>Localization.</b> Enabling globalization and localization in Web sites today is difficult, requiring large amounts of custom code and resources.  ASP.NET 2.0 and Visual Studio 2005 provide tools and infrastructure to easily build Localizable sites including the ability to auto-detect incoming locale's and display the appropriate locale based UI.  Visual Studio 2005 includes built-in tools to dynamically generate resource files and localization references.  Together, building localized applications becomes a simple and integrated part of the development experience.<br /><br />	
  </li>

</ul>

<h3>Administration and Management</h3>

ASP.NET 2.0 is designed with administration and manageability in mind.  We recognize that while simplifying the development experience is important, deployment and maintenance in a production environment is also a key component of an application's lifetime.  ASP.NET 2.0 introduces several new features that further enhance the deployment, management, and operations of ASP.NET servers. 

<ul>
  <li><b>Configuration API.</b> ASP.NET 2.0 contains new configuration management APIs, enabling users to programmatically build programs or scripts that create, read, and update Web.config and machine.config configuration files.  <br /><br />
  </li>

  <li><b>ASP.NET MMC Admin Tool.</b> ASP.NET 2.0 provides a new comprehensive admin tool that plugs into the existing IIS Administration MMC, enabling an administrator to graphically read or change common settings within our XML configuration files.<br /><br />
  </li>

  <li><b>Pre-compilation Tool.</b>  ASP.NET 2.0 delivers a new application deployment utility that enables both developers and administrators to precompile a dynamic ASP.NET application prior to deployment. This precompilation automatically identifies any compilation issues anywhere within the site, as well as enables ASP.NET applications to be deployed without any source being stored on the server (one can optionally remove the content of .aspx files as part of the compile phase), further protecting your intellectual property. <br /><br />
  </li>

  <li><b>Health Monitoring and Tracing.</b> ASP.NET 2.0 also provides new health-monitoring support to enable administrators to be automatically notified when an application on a server starts to experience problems. New tracing features will enable administrators to capture run-time and request data from a production server to better diagnose issues. ASP.NET 2.0 is delivering features that will enable developers and administrators to simplify the day-to-day management and maintenance of their Web applications. </li>


</ul>


<h3>Flexible Extensibility</h3>

ASP.NET 2.0 is a well-factored and open system, where any component can be easily replaced with a custom implementation.  Whether it is server controls, page handlers, compilation, or core application services, you'll find that all are easily customizable and replaceable to tailor to your needs.  Developers can plug in custom code anywhere in the page lifecycle to further customize ASP.NET 2.0 to their needs.


<ul>
  <li><b>Provider-driven Application Services.</b> ASP.NET 2.0 now includes built-in support for membership (user name/password credential storage) and role management services out of the box. The new personalization service enables quick storage/retrieval of user settings and preferences, facilitating rich customization with minimal code. The new site navigation system enables developers to quickly build link structures consistently across a site.  As all of these services are provider-driven, they can be easily swapped out and replaced with your own custom implementation.  With this extensibility option, you have complete control over the data store and schema that drives these rich application services.<br /><br />
  </li>

  <li><b>Server Control Extensibility.</b> ASP.NET 2.0 includes improved support for control extensibility, such as more base classes that encapsulate common behaviors, improved designer support, more APIs for interacting with client-side script, metadata-driven support for new features like themes and accessibility verification, better state management, and more. <br /><br />
  </li>

  <li><b>Data Source Controls.</b> Data access in ASP.NET 2.0 is now performed declaratively using data source controls on a page.  In this model, support for new data backend storage providers can be easily added by implementing custom data source controls. Additionally, the SqlDataSource control that ships in the box has built-in support for any ADO.NET managed provider that implements the new provider factory model in ADO.NET.<br /><br />
  </li>

  <li><b>Compilation Build Providers.</b> Dynamic compilation in ASP.NET 2.0 is now handled by extensible compilation build providers, which associate a particular file extension with a handler that knows how to compile that extension dynamically at runtime.  For example, .resx files can be dynamically compiled to resources, .wsdl files to web service proxies, and .xsd files to typed DataSet objects.  In addition to the built-in support, it is easy to add support for additional extensions by implementing a custom build provider and registering it in Web.config.<br /><br />
  </li>

  <li><b>Expression Builders.</b> ASP.NET 2.0 introduces a declarative new syntax for referencing code to substitute values into the page, called Expression Builders.  ASP.NET 2.0 includes expression builders for referencing string resources for localization, connection strings, application settings, and profile values.  You can also write your own expression builders to create your own custom syntax to substitute values in a page rendering. </li>

</ul>


<h3>Performance and Scalability</h3>

ASP.NET is built to perform, using a compiled execution model for handling page requests and running on the world's fastest web server, Internet Information Services.  ASP.NET 2.0 also introduces key performance benefits over previous versions.

<ul>
  <li><b>64-Bit Support.</b> ASP.NET 2.0 is now 64-bit enabled, meaning it can take advantage of the full memory address space of new 64-bit processors and servers. Developers can simply copy existing 32-bit ASP.NET applications onto a 64-bit ASP.NET 2.0 server and have them automatically be JIT compiled and executed as native 64-bit applications (no source code changes or manual re-compile are required). <br /><br />
  </li>

  <li><b>Caching Improvements.</b> ASP.NET 2.0 also now includes automatic database server cache invalidation. This powerful and easy-to-use feature allows developers to aggressively output cache database-driven page and partial page content within a site and have ASP.NET automatically invalidate these cache entries and refresh the content whenever the back-end database changes. Developers can now safely cache time-critical content for long periods without worrying about serving visitors stale data.</li>
</ul>

The remainder of the QuickStart presents practical examples of these and other features in ASP.NET.

</asp:Content>