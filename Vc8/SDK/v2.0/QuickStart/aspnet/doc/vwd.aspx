<%@ Page Language="C#" MasterPageFile="~/aspnet/aspnet.master" %>

<asp:Content ID="Content1" ContentPlaceHolderID="MainBody" Runat=Server>

<h2>Introduction to Visual Web Developer 2005 Express Edition</h2>

<p>
Visual Web Developer 2005 Express Edition is part of the Microsoft Visual Studio 2005 family, and is the
best development tool for building data driven web applications with ASP.NET 2.0.  As part of the Express family, Visual Web Developer provides a seamless upgrade path to Visual Studio Standard, Professional, and Team System.
</p>
<p>
    Visual Web Developer is tuned to the specific needs of the Web developer through
    a new Web profile that exposes a menu and window layout optimized for Web development.
    The environment includes a best-of-breed HTML source editor, an improved visual page
    designer, a new project system, better support for working with data, and full XHTML
    standards support.&nbsp; Collectively, these features enable you to develop data-driven
    Web applications faster and easier than ever before. Below we'll dive in and explore a few of the 
    many Web development improvements coming with Visual Web Developer.

<p>
    <h1>Better Source Code Editing</h1><br/><br/>

    Visual Web Developer has an improved HTML source editor which enables you to write
    and modify your pages faster. The source editor provides full Intellisense throughout
    your files and has new features for navigating and validating your markup.
</p>
<p>
    <h3>Intellisense Everywhere</h3>

    Intellisense -- the popup code hints which appear while you type -- has a dramatic
    impact on your productivity as a developer. While support for Intellisense in Visual
    Studio .NET 2003 is excellent today, support for Intellisense in Visual Web Developer
    gets even better.
</p>
<p>
    In Visual Web Developer, Intellisense pops up everywhere. For example, you can
    take full advantage of Intellisense within the script blocks in single file ASP.NET
    pages. In addition, Visual Web Developer also supports Intellisense for ASP.NET
    Page Directives and for inline CSS style attributes within a page.
</p>
<p>
    Visual Web Developer also provides Intellisense for all sections within a Web.Config
    configuration file, as well as any generic XML file that contains a DTD or XML Schema
    reference.
</p>
<p>
    <img id="Img1" alt="Intellisense" src="~/aspnet/images/vwd1.gif" runat="server" /><br />
    <span class="caption">Using Intellisense in a single file ASP.NET page</span>
</p>
<p>
    <h3>HTML Source Preservation</h3>
    Visual Web Developer respects your HTML. The formatting of your HTML
    markup -- including all white space, casing, indention, carriage returns, and word
    wrapping -- is now preserved exactly as originally written, even when switching back
    and forth between the design view and source view of the page. You can completely
    trust Visual Web Developer to never modify your markup.&nbsp;
</p>
<p>
    <h3>HTML Formatting Options </h3>

    Visual Web Developer enables you to precisely control the format of all HTML and
    ASP.NET Server Control markup generated using the WYSIWYG designer.&nbsp; You can
    now configure the tag casing, attribute quotation, indention style and word wrap characteristics
    of every html or server control tag in a page.&nbsp; You can set these formatting
    options as defaults for all markup, as well as optionally override
    each formatting option on a per tag/control basis.&nbsp; This provides you with the
    flexibility to fully control exactly how you want your markup to be generated.&nbsp;
</p>
<p>
    HTML format settings can be exported and imported from Visual Web Developer to
    enable markup style standardization across multiple developers on a team.&nbsp; Visual Web Developer
    also enables developers to easily apply HTML formatting rules to
    existing markup source (to handle those cases when you need to update existing HTML
    source with new formatting rules).
</p>
<p>
    <h3>Tag Navigator</h3>

    The HTML source editor within Visual Web Developer ships with a new
    “Tag Navigator” feature that enables developers to easily track their location and
    navigate within a complicated HTML document. The Tag Navigator displays the current
    "path" within the source of an HTML page by displaying a list of all the HTML tags
    which contain the tag where your cursor is currently located. Clicking on any of the
    nodes enables developers to optionally change the source level selection, and quickly
    move up and down a deep HTML hierarchy.
</p>
<p>
    Imagine, for example, that you are editing the source of an HTML page with multiple
    nested HTML tables. Editing nested tables can be challenging since it is easy to get
    lost within the jumble of nested table rows and cells. However, by taking advantage
    of the Tag Navigator, you can avoid getting lost since the Tag Navigator continuously
    displays your current path within the hierarchy of table elements.
</p>
<p>
    <h3>Tag Outlining</h3>

    Tag Outlining enables you to work more effectively with large HTML documents.
    With Tag Outlining, you can right-click any HTML tag in the source editor and select
    Collapse Tag to hide the entire contents of the tag. Collapsing different regions
    of the HTML source code contained in a page makes it easier to focus on the particular
    region of the page which you need to edit.
</p>
<p>
    <h3>Flexible Browser Targeting and Validation</h3>

    Visual Web Developer enables you to easily target a specific HTML standard or browser
    when writing your HTML pages. For example, you can target your HTML pages to work
    with a particular browser such as Netscape Navigator 4.0 or Internet Explorer 6.0.
    Alternatively, you can target a particular HTML standard such as XHTML 1.0 Strict
    or XHTML 1.0 Transitional.
</p>
<p>
    Your HTML will then be validated in real-time as you type in the source editor. Invalid
    HTML will automatically be underlined with a red squiggly (with a tooltip displaying
    an explanation of precisely how you violated the target). These validation errors
    are also summarized in real-time within the “Task List” window.
</p>
<p>
    All browser/standard validation rules are pluggable within Visual Web Developer,
    and can be easily extended and customized by developers.&nbsp; Visual Web Developer
    will include a number of automatic validation targets out of the box – including built-in
    validation support for XHTML, XHTML Transitional, and all major desktop and mobile
    browsers.
</p>
<p>
    <img id="Img2" alt="Validation support" src="~/aspnet/images/vwd2.gif" runat="server" /><br />
    <span class="caption">Selecting a validation target</span>
</p>

<p>
    <h3>Code Refactoring</h3>

    Code Refactoring enables you to easily and systematically make changes
    to your code. Code Refactoring is supported everywhere that you can write code including
    both code-behind and single-file ASP.NET pages. For example, you can use Code Refactoring
    to automatically promote a public field to a full property.
</p>
<p>
    <h3>Intellitask</h3>

    Intellitask is like a super smart clipboard designed for working with
    code. Intellitask improves your productivity by enabling you to easily apply standard
    code snippets anywhere within the source editor. Simply by right-clicking, you can
    inject common code into your pages. Visual Web Developer will ship with more than
    200 web specific Intellitask code snippets out of the box.&nbsp; Better yet, you can
    add your own code templates to Intellitask so that you can quickly modify your code
    in the future.
</p>
<p>
    <h1>Richer Visual Designer</h1><br /><br />

    Visual Web Developer has an improved designer which makes it easier to visually
    build ASP.NET Web applications. By taking advantage of the new designer tools, you
    can build a feature rich, database-driven Web application without writing a single
    line of code.
</p>
<p>
    <h3>ASP.NET Master Page Designer</h3>

    Master Pages enable you to create a common look and feel for the pages in an ASP.NET
    Web application. You can take advantage of Master Pages to create a single page layout
    and apply the page layout to multiple Content Pages.&nbsp; For example, you can use
    a Master Page to ensure that every page in an application contains the same standard
    header, footer, and navigation bar.
</p>
<p>
    Visual Web Developer provides full WYSWIYG authoring support for ASP.NET Master
    Pages. After you create a Master Page, you can apply the Master to new ASP.NET Pages
    within your Web site. Visual Web Developer provides great editing support when
    authoring an ASP.NET page based on a Master – enabling the designer to see what the
    combined page will look like, while simultaneously ghosting out all content from the
    Master that cannot be edited on the Content Page.
</p>
<p>
    <span class="caption"><img id="Img3" alt="Master Pages" src="~/aspnet/images/vwd.gif" runat="server" />
    <br />
    Master Pages in the designer</span>
</p>
<p>
    <h3>Smart Tasks</h3>

    Visual Web Developer enables you to perform many of the most common programming
    tasks directly from the designer surface. By taking advantage of Smart Tasks, You
    can create an entire, feature rich, database-driven Web application without writing
    a single line of code.
</p>
<p>
    When you drag new controls onto the designer surface, a popup list of common tasks
    automatically appears. You can use the common tasks list to quickly configure a control's
    properties, as well as walk through common operations you might perform with it. For
    example, when you add a GridView control to a page, a common task list appears which
    enables you to quickly enable sorting, paging, or editing for the GridView.&nbsp;
    When you add a TextBox control to a page, a common task list appears which enables
    you to quickly associate a validation control with the control.
</p>
<p>
    <span class="caption"><img id="Img4" alt="Smart tag panel" src="~/aspnet/images/vwd3.gif" runat="server" />
    <br />
    Enabling GridView options with Smart Tasks</span>
</p>
<p>
    <h3>Improved ASP.NET Template Editing</h3>

    Visual Web Developer has better designer support for editing templates. You can
    take advantage of the new template editing features when working with data controls
    such as the DataList and GridView controls.
</p>
<p>
    When adding a control to a template in the designer, you can easily specify the databound
    expressions to associate with the control properties. For example, if you drag a TextBox
    control onto a template, you can bind the TextBox control's Text property to a particular
    field from the data control's data source. The Edit Databindings dialog box provided
    by the Visual Web Developer template editing designer enables you to easily bind
    particular fields by name.
</p>
<p>
    <h3>Improved Table Editing</h3>

    Visual Web Developer has better HTML table editing features. The improved Insert
    Table dialog box enables you to quickly control the look and feel of the new table
    when it is added to the designer surface. In addition, Visual Web Developer provides
    the ability to resize tables, table columns and table rows graphically within the
    designer surface (just click and hold down the appropriate element to size it).
</p>
<p>
    <h1>Better Web Projects</h1><br /><br />

    Visual Web Developer provides you with more flexibility and features
    for managing the files in your web projects. The new web project system includes new
    tools for accessing, compiling, and publishing your Web application projects. &nbsp;
</p>
<p>
    <h3>File System Support</h3>

    Visual Web Developer provides you with the option of creating a new Web application
    within any folder on your computer. When you create a file system project, you do
    not need to have IIS or Front Page Server Extensions installed on your computer. You
    can simply point at a folder and start building Web pages.<br />
    &nbsp;<br />
    <span class="caption"><img id="Img5" alt="File system Web sites" src="~/aspnet/images/vwd4.gif" runat="server" />
    <br />
    Creating a File System Web site</span>
</p>
<p>
    Visual Web Developer includes its own built-in ASP.NET enabled Web server. This
    enables you to develop and debug Web applications on a computer without IIS installed.&nbsp;
    It also enables developers to build and debug web applications without requiring Administrator
    access.&nbsp;
</p>
<p>
    The built-in Web server provides you with a more secure way of building applications
    on a development machine. The built-in Web server cannot be accessed remotely (it
    can only be used by a local web browser) and it automatically shuts down when you
    close the Visual Web Developer development environment.
    <br />
    <br />

    <h3>Local IIS Support (No FrontPage Server Extensions Required)</h3>

    In addition to file system projects, Visual Web Developer now enables you to more
    easily manage projects which work with an IIS Web server. When you create a new IIS
    project, you can now view all of the Web sites and applications configured on your
    machine. You can even create new IIS Web applications or virtual directories directly
    from the New Web Site dialog box.&nbsp;
</p>
<p>
    Frontpage Server Extensions (FPSE) are no longer required for locally developed IIS
    web applications. You can create and fully manage your websites without having to
    install or configure them.
</p>
<p>
    <h3>FTP Support</h3>

    Visual Web Developer now has built-in support for editing and updating remote web
    projects using the standard File Transfer Protocol (FTP). You can quickly connect
    to a remote Web site using FTP within the New Web Site and Open Web Site dialog box.
</p>
<p>
    <h3>Better Web Publishing</h3>

    With Visual Web Developer, you can now publish a Web site to a remote server easier
    than ever before. Built-in publishing features enable developers to easily keep files
    in a local project synchronized with files located on a remote Web server. Visual Web Developer
    provides automatic logging support for all files copied, and enables
    developers to quickly identify whether the latest files have been updated.<br />
    &nbsp;<br />
    <span class="caption"><img id="Img6" alt="CopyWeb publishing support" src="~/aspnet/images/vwd5.gif" runat="server" />
    <br />
    Publishing a Web site to a remote Web server</span>
</p>
<p>
    <h3>Pre-Compiled ASP.NET Web Sites</h3>

    </span>Visual Web Developer now includes built-in IDE support for pre-compiling
    ASP.NET 2.0 applications.&nbsp; By taking advantage of pre-compilation, you can
    automatically validate and compile all code in a site (including code-behind, inline
    code and business classes) and emit an output directory with only compiled .dll assemblies
    and the application's web.config file (all HTML markup and .aspx files will optionally be removed).&nbsp;
    In addition, you can choose to obfuscate the resulting code as part of the pre-compilation
    process for greater intellectual property protection.
</p>
<p>
    The pre-compilation feature enables developers to easily build and re-sell ASP.NET
    web applications without having to ship their source.&nbsp; It can also improve the
    site's performance and startup time on a production server.
</p>
<p>
    <h1>Better Data Support</h1><br /><br />

    Visual Web Developer makes it much easier to work with data in
    your Web applications.
</p>
<p>
    <h3>Drag and Drop Data Access</h3>

    You can easily create a database-driven Web page by dragging and dropping data controls
    onto a page. By taking advantage of the new ASP.NET 2.0 data source controls,
    you can easily connect to a database, retrieve database records, and update database
    records without writing any code (or having Visual Studio write any code for you!).
</p>
<p>
    Imagine, for example, that you want to display all the records from a Microsoft SQL
    Server database table named Products in a Web page. To do this, you simply need to
    drag two controls onto the page: a SqlDataSource control and a GridView control. By
    setting a few properties of these controls, you can automatically retrieve and display
    the records in a Web page.
</p>
<p>
    <h3>Data Access Layer Designer</h3>

    Visual Web Developer provides built-in designer support for building and maintaining
    a Data Access Layer within your web application.&nbsp; The data designer enables developers
    to model database tables and stored procedures as components that encapsulate procedural
    ADO.NET data access logic.&nbsp; You can then easily access and update your data from
    both web pages and business objects through these data components.
</p>
<p>
    <h3>Powerful Object Data Binding</h3>

    Visual Web Developer enables you to quickly create 3-tier applications with distinct
    presentation, business, and data layers. By taking advantage of the new ASP.NET ObjectDataSource
    control, you can declaratively bind data controls -- like the GridView, DataList,
    and DropDownList controls -- to a business or data component instead of binding the
    controls directly to a database.&nbsp; This enables clean encapsulation and abstraction
    of functionality within your application – and eliminates the need to write any data
    access code in your presentation layer.
</p>
<p>
    The development environment automatically guides developers through the process of
    binding a data control to a business object. Developers are prompted to select the
    particular methods from the business object to use for selecting, inserting, updating,
    and deleting data.&nbsp; No code is required from the page developer.
</p>
<p>
    <h3>Connection String Management</h3>

    Visual Web Developer helps you avoid hard-coding database connection strings into
    your ASP.NET pages. All data connection dialogs and wizards provide you with the option
    of storing database connection strings in an application's Web.Config file.
</p>
<p>
    Storing database connection strings in the Web.Config file makes your connection strings
    more manageable and more secure. If you need to change your database password, you
    need to change it at only one location.&nbsp; The ASP.NET 2.0 MMC Admin tool
    automatically provides administrators with an easy to use interface for changing connection
    strings on servers. In addition, the tool can be used to encrypt connection strings
    on production servers.
</p>
<p>
    <h1>Better Standards Support</h1><br /><br />

    Visual Web Developer enables you to easily build applications that conform to industry
    and government standards. The development environment includes new tools for supporting
    W3C standards such as XHTML and government standards such as accessibility standards.
</p>
<p>
    <h3>XHTML Compliant Designer</h3>

    All HTML code generated by Visual Web Developer is XHTML compliant. For example,
    all the formatting options available from the toolbar generate HTML which is fully
    XHTML compliant. All tags generated by the designer are well-formed and properly cased
    for XHTML.
</p>
<p>
    In addition to XHTML designer support, Visual Web Developer also includes tools
    for helping you write XHTML compliant code in the source editor. While working in
    the source editor, you can validate your HTML source code against either the XHTML
    1.0 Transitional or XHTML 1.0 Strict standards. When your code doesn't successfully
    validate, you are provided with an explanation for the validation failure.&nbsp;
</p>
<p>
    <h3>Accessibility Checker</h3>

    Creating accessible Web pages -- Web pages which can be used by persons with disabilities
    -- is a requirement for many government agencies and large corporations. Visual Web Developer now enables
    you to easily validate and enforce accessibility standards.
</p>
<p>
    You can use the integrated Visual Web Developer Accessibility Checker <i>(available in Visual Studio Standard Edition and above only)</i> to quickly
    identify accessibility problems in your application. The Accessibility Checker validates
    your ASP.NET pages against both the Section 508 and W3C Web Content Accessibility
    Guidelines (WCAG) standards, and will automatically output warnings and errors to
    the IDE Task List.
</p>
<p>
    <h1>Summary</h1><br /><br />

    Visual Web Developer is the best development tool for building dynamic, data driven web
    applications with ASP.NET 2.0. As detailed above, and demonstrated in the Quickstarts, it provides it provides major enhancements for the Web application developer.&nbsp;With Visual Web Developer and the ASP.NET enhancements you will be able to build feature rich, database-driven Web applications faster and easier than ever before.
    
    <br />
</p>




</asp:Content>
