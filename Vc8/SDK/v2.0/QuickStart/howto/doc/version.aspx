<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2>How Do I...Use Assembly Version Policy?</h2>

<br /><br />
A primary goal of the deployment system in the .NET Framework is to eliminate conflicts between applications caused by
shared components and shared states (or DLL conflicts).  A key solution to this problem is a robust
versioning system.  The .NET Framework records information about an application's dependencies
in the assembly manifest.  This dependency information includes a version number that is used at runtime to load the proper
version of a dependency.


<br /><br />By default, the common language runtime will load the version of a dependency that is specified in the manifest.  This is
preferred in the majority of scenarios. However, there are cases where running an application with
a different version of a dependency can be useful.  In order to accomplish this, version policies can be included
in an application's configuration file.  For example, the following XML code fragment redirects references to version 5.0.0.0 of a shared
assembly called "CalcR" up to version 6.0.0.0 of that assembly:


<pre class="code">
<pre class="code">
&lt;configuration&gt;   
    &lt;runtime&gt;
        &lt;assemblyBinding xmlns="urn:schemas-microsoft-com:asm.v1"&gt;


            &lt;dependentAssembly&gt;
                &lt;assemblyIdentity name="calcR" 
                                  publicKeyToken="a1690a5ea44bab32" 
                                  culture=""/&gt;
              
                
                &lt;bindingRedirect oldVersion="5.0.0.0"
                                 newVersion="6.0.0.0"/&gt;


            &lt;/dependentAssembly&gt;
        &lt;/assemblyBinding&gt;
    &lt;/runtime&gt;
&lt;/configuration&gt; 
</pre>
</pre>

<br /><br />In addition to policies specified at the application level, the .NET Framework also provides two other policy levels: publisher and administrator.
A Publisher policy statement describes the compatibility of an assembly issued by the publisher of that shared assembly.  Administrator level policy is a machine version
policy that affects all applications.  Administrator policy is created using the same XML syntax as application level policy.  The
administrator policy file is called machine.config, and resides in the common language runtime install directory.  The three policy levels are evaluated
in the following order:

<ul>
  <li>Application Policy
  <li>Publisher Policy
  <li>Administrator Policy
</ul>


<h4>Example</h4>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/assemblies/version/version.src"
        Icon="../../images/console.gif"
        Caption="C# Math.exe"
	SamplePath="howto\samples\assemblies\version\"
        CanBeHosted="false"
        runat="server" />
  </CsTemplate>
  <CpTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/assemblies/version/version.src"
        Icon="../../images/console.gif"
        Caption="C++ Math.exe"
	SamplePath="howto\samples\assemblies\version\"
        CanBeHosted="false"
        runat="server" />
  </CpTemplate>
 <VjsTemplate>
       <Acme:SourceRef
        RunSample=""
        ViewSource=""
        Icon = ""
        Caption=""
        CanBeHosted="false"
        runat="server" />
  </VjsTemplate>
</Acme:LangSwitch>
</asp:Content>

