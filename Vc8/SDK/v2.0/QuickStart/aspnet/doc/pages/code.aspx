<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>

<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Sharing Code Between Pages</h2>

Although you can place code inside each page within your site (using the inline or code-behind separation models described in the previous section), there are times when you will want to share code across several pages in your site.  It would be inefficient and difficult to maintain this code by copying it to every page that needs it.  Fortunately, ASP.NET provides several convenient ways to make code accessible to all pages in an application.

<a name="code"></a>
<h3>The Code Directory <span class="newinline">New in 2.0</span></h3>

Just as pages can be compiled dynamically at runtime, so can arbitrary code files (for example .cs or .vb files).  ASP.NET 2.0 introduces the <b>App_Code directory</b>, which can contain standalone files that contain code to be shared across several pages in your application.  Unlike ASP.NET 1.x, which required these files to be precompiled to the Bin directory, any code files in the App_Code directory will be dynamically compiled at runtime and made available to the application.  It is possible to place files of more than one language under the App_Code directory, provided they are partitioned in subdirectories (registered with a particular language in Web.config).  The example below demonstrates using the App_Code directory to contain a single class file called from the page.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/simple/CodeFolder_cs/CodeFolder_cs.aspx"
        ViewSource="~/aspnet/samples/simple/CodeFolder.src"
        Caption="C# App_Code Folder Example"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/simple/CodeFolder_vb/CodeFolder_vb.aspx"
        ViewSource="~/aspnet/samples/simple/CodeFolder.src"
        Caption="VB App_Code Folder Example"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

By default, the App_Code directory can only contain files of the same language.  However, you may partition the App_Code directory into subdirectories (each containing files of the same language) in order to contain multiple languages under the App_Code directory.  To do this, you need to register each subdirectory in the Web.config file for the application.

<pre class="code">
&lt;configuration&gt;
  &lt;system.web&gt;
    &lt;compilation&gt;
      &lt;codeSubDirectories&gt;
        &lt;add directoryName="Subdirectory"/&gt;
      &lt;/codeSubDirectories&gt;
    &lt;/compilation&gt;
  &lt;/system.web&gt;
&lt;/configuration&gt;
</pre>


The following example demonstrates an App_Code directory partitioned to contain files in both the VB and C# languages.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/simple/CodeFolder_cs/CodeFolder2_cs.aspx"
        ViewSource="~/aspnet/samples/simple/CodeFolder2.src"
        Caption="C# Partitioned App_Code Folder Example"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/simple/CodeFolder_vb/CodeFolder2_vb.aspx"
        ViewSource="~/aspnet/samples/simple/CodeFolder2.src"
        Caption="VB Partitioned App_Code Folder Example"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="bin"></a>
<h3>The Bin Directory</h3>

Supported in ASP.NET version 1, the Bin directory is like the Code directory, except it can contain precompiled assemblies.  This is useful when you need to use code that is possibly written by someone other than yourself, where you don't have access to the source code (VB or C# file) but you have a compiled DLL instead.  Simply place the assembly in the Bin directory to make it available to your site.  By default, all assemblies in the Bin directory are automatically loaded in the app and made accessible to pages.  You may need to Import specific namespaces from assemblies in the Bin directory using the <b>@Import</b> directive at the top of the page.

<pre class="code">
  &lt;@ Import Namespace="MyCustomNamespace" &gt;
</pre>

<a name="gac"></a>
<h3>The Global Assembly Cache</h3> 

The .NET Framework 2.0 includes a number of assemblies that represent the various parts of the Framework.  These assemblies are stored in the global assembly cache, which is a versioned repository of assemblies made available to all applications on the machine (not just a specific application, as is the case with Bin and App_Code).  Several assemblies in the Framework are automatically made available to ASP.NET applications.
You can register additional assemblies by registration in a Web.config file in your application.

<pre class="code">
&lt;configuration&gt;
   &lt;compilation&gt;
      &lt;assemblies&gt;
         &lt;add assembly="System.Data, Version=1.0.2411.0, 
                        Culture=neutral, 
                        PublicKeyToken=b77a5c561934e089"/&gt;
      &lt;/assemblies&gt;
   &lt;/compilation&gt;
&lt;/configuration>
</pre>

Note that you still need to use an <b>@Import</b> directive to make the namespaces in these assemblies available to individual pages.


</asp:Content>

