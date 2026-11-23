<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2>How Do I...Change the search path for private assemblies?</h2>

<br /><br />Private assemblies are assemblies that are visible to only one application. The .NET Framework enables
developers to build applications that are isolated from changes made to the system by other applications.
Private assemblies must be deployed in the directory structure of the containing application and are found
during runtime through a process called probing, which is simply a mapping from an assembly's identity to
a file on disk that contains the manifest.


<br /><br />
By default, probing for private assemblies is done in the application base (the root directory of the
application) and the subdirectories that follow naming conventions based on assembly name and culture. You can customize this behavior by specifying a privatePath in your application's configuration file.
The privatePath is a semi-colon delimited list of directories in which the common language runtime will search for private assemblies.
These directory names are relative to the application base - they cannot point outside the
application base.  The directories on privatePath will be searched after the application base itself.

The following configuration file adds a bin directory to the assembly search path:


<pre class="code">
&lt;configuration&gt;   
    &lt;runtime&gt;
        &lt;assemblyBinding xmlns="urn:schemas-microsoft-com:asm.v1"&gt;
        
            &lt;probing privatePath="bin"/&gt;

        &lt;/assemblyBinding&gt;
    &lt;/runtime&gt;
&lt;/configuration&gt;
</pre>

<h>Example</h>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/assemblies/searchpath/searchpath.src"
        Icon="../../images/console.gif"
        Caption="C# Config Example"
	SamplePath="howto\samples\assemblies\searchpath\"
        runat="server" />
  </CsTemplate>
  <CpTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/assemblies/searchpath/searchpath.src"
        Icon="../../images/console.gif"
        Caption="C++ Config Example"
	SamplePath="howto\samples\assemblies\searchpath\"
        runat="server" />
  </CpTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/assemblies/searchpath/searchpath.src"
        Icon="../../images/console.gif"
        Caption="VB Config Example"
	SamplePath="howto\samples\assemblies\searchpath\"
        runat="server" />
  </VbTemplate>
  <VjsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource=""
        Icon = ""
        Caption=""
        runat="server" />	
  </VjsTemplate>
</Acme:LangSwitch>

</asp:Content>