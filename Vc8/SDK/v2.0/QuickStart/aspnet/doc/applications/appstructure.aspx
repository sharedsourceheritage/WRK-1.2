<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>

<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>


<h2>Application Structure</h2>

A single web server can host multiple ASP.NET web applications. Web applications are
organized into web sites, with each web site identified by a unique <b>HostName</b> and
<b>Port</b> combination. 
Each web site can contain multiple ASP.NET web applications, with each application identified
by a unique <b>URL prefix</b> that determines the root directory of the application.
<br /><br />
For example, a single Microsoft Internet Information
Services (IIS) Web server with two mapped IP addresses (one aliased to "www.msn.com" and
the other to "intranet") and three logical sites (http://intranet, http://www.msn.com,
http://www.msn.com port 81) could expose the following six ASP.NET applications.

<br /><br />

<table class="table">
<tr>  <th>Application URL</th>
        <th>Description</th></tr>
<tr>  <td>http://intranet</td>
        <td>"Root" application on intranet site.</td></tr>
<tr>  <td>http://www.msn.com</td>
        <td>"Root" application on www.msn.com site.</td></tr>
<tr>  <td>http://www.msn.com:81</td>
        <td>"Root" application on www.msn.com port 81 site.</td></tr>
<tr>  <td>http://intranet/training</td>
        <td>"Training" application on intranet site.</td></tr>
<tr>  <td>http://intranet/hr</td>
        <td>"HR" application on intranet site.</td></tr>
<tr>  <td>http://intranet/hr/compensation/</td>
        <td>"Compensation" application on intranet site.</td></tr>
</table>

<br />

<b>Note:</b> The URL for the compensation application mentioned in the table is rooted within 
the HR application URL namespace. However, this URL hierarchy notation does not 
imply that the
compensation application is contained or nested within the HR 
application.  Rather, each application maintains an independent set of configuration and 
class resolution properties; both are logical peer child sites of the 
intranet site.

<br /><br />

Each ASP.NET Framework application exposed within a URL namespace is backed using a file system
directory located on either a local or remote file share. Application directories are not required to be centrally located within a contiguous part of the
file system; they can be scattered throughout a disk. For example, the 
ASP.NET applications
mentioned previously could be located in the different directories listed in the following table.

<br /><br />

<table class="table">
<tr>  <th>Application URL</th>
      <th>Physical path</th></tr>
<tr>  <td>http://intranet</td>
      <td>c:\inetpub\wwwroot</td></tr>
<tr>  <td>http://www.msn.com</td>
      <td>c:\inetpub\msnroot</td></tr>
<tr>  <td>http://www.msn.com:81</td>
      <td>d:\msnroot81</td></tr>
<tr>  <td>http://intranet/training</td>
      <td>d:\serverapps\trainingapp</td></tr>
<tr>  <td>http://intranet/hr</td>
      <td>\\hrweb\sillystuff\reviews</td></tr>
<tr>  <td>http://intranet/hr/compensation/</td>
      <td>c:\inetpub\wwwroot\compensation</td></tr>
</table>

<!--BEGIN SUB SECTION-->
<a name="resolvingassemblies"></a>
<h3>Resolving Class References to Assemblies</h3>

Assemblies are the unit of class deployment in the common language runtime. Developers writing
.NET Framework classes using Visual Studio .NET version 7.0 will produce a new assembly with each
Visual Studio project that they compile.  Although it is possible to have an assembly
span multiple portable executable (PE) files (several module DLLs),
Visual Studio .NET will, by default,
compile all assembly code into a single DLL (1 Visual Studio .NET project = 1 .NET 
Framework assembly = 1 physical DLL).

<br /><br />

You can use an assembly on a computer by deploying it into an assembly cache.
The assembly cache can be either global to a computer or local to a particular
application. Only code intended to be shared across multiple
applications should be placed in the global system assembly cache. Code specific
to a particular application, such as most Web application logic, 
should be deployed in the application's local assembly cache. One advantage
of deploying an assembly within an application's local assembly cache is that only
code within that application can access it. (This is a nice feature 
for scenarios involving
ISPs.) It also facilitates side-by-side versioning of the same 
application because
classes are private to each application version instance.

<br /><br />

An assembly can be deployed into an  application's local assembly cache by simply copying,
XCOPYing, or FTPing the appropriate files into a directory that has been marked as an
"assembly cache location" for that particular application. No additional registration
tool must be run once the appropriate files are copied, and no reboot is necessary.
This eliminates some of the difficulties currently associated with deploying COM components within ASP applications
(currently, an administrator must log on to the Web server locally and run Regsvr32.exe).

<br /><br />

By default, an ASP.NET Framework application is automatically configured to use the \bin subdirectory,
located immediately under the application root, as its local assembly cache. The \bin directory
is also configured to deny any browser access so that a remote client cannot download
and steal the code.  The following example shows a possible directory layout for an ASP.NET application, where the \bin directory is immediately under the application root.

<pre class="code">
C:\inetpub\wwwroot
   Web.cfg
   Default.aspx

   \bin                  &lt;= Application assembly cache directory
      MyPages.dll
      MyBizLogic.dll

   \order
      SubmitOrder.aspx
      OrderFailed.aspx

      \img
         HappyFace.gif
</pre>

<!--BEGIN SUB SECTION-->
<a name="startup"></a>
<h3>ASP.NET Framework application Startup and Class Resolution</h3>

ASP.NET Framework applications are lazily constructed the first time a client requests a URL
resource from them. Each ASP.NET Framework application is launched within a unique application
domain (<b>AppDomain</b>)--a new common language runtime construct that enables process hosts to provide extensive
code, security, and configuration isolation at run time.

<br /><br />

ASP.NET is responsible for manually creating an application domain when a new application
is started. As part of this process, ASP.NET provides configuration settings for the common language runtime
to use. These settings include:

<ul>
<li>The directory paths that make up the local assembly cache. (Note: It is the .NET Framework
application domain isolation architecture that allows each application to maintain its
own local assembly cache.)
<li>The application's security restrictions (what the application can access on the system).
</ul>

Because ASP.NET does not have compile-time knowledge of any applications you 
write on top of it, it cannot use static references to resolve and reference application code.
Instead, ASP.NET must use a dynamic class/assembly resolution approach to make the transition
from the ASP.NET runtime into application code.

<br /><br />

ASP.NET configuration and page activation files will enable you to dynamically reference
a target-compiled .NET Framework class by specifying an assembly and class name combination.
The string format for this union follows the pattern <code>classname, assemblyname</code>. The common language runtime can then use this simple string reference to resolve and load the appropriate class.

<!--BEGIN SUB SECTION-->
<a name="codereplacement"></a>
<h3>Code Replacement</h3>

.NET Framework assemblies are typically compiled and deployed into a Windows DLL-based
PE format. When the common language runtime's loader resolves a class implemented within this type
of assembly, it calls the Windows LoadLibrary routine on the file (which locks
its access on disk), and then maps the appropriate code data into memory for
run-time execution. Once loaded, the DLL file will remain locked on disk until
the application domain referencing it is either torn down or manually recycled.

<br /><br />

Although ASP.NET cannot prevent the common language runtime from locking a loaded assembly DLL on disk,
it can support you by ensuring that the physical DLLs in a Web application's private assembly cache are never actually
loaded by the runtime. Instead, shadow copies of the assembly DLLs are made immediately
prior to their use. These shadow assemblies--not the original files--are then
locked and loaded by the runtime.

<br /><br />

Because the original assembly files always remain unlocked, you are free to delete, replace, or rename them without cycling the Web server
or having to use a registration utility. FTP and similar methods work just fine. ASP.NET maintains an
active list of all assemblies loaded within a particular application's application domain
and uses file-change monitoring code to watch for any updates to the original files.

</asp:Content>

