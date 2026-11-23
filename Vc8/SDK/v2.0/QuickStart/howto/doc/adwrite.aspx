<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2>How Do I...Modify Active Directory?</h2>

<br />The Active Directory Service Interface (ADSI) accesses the capabilities of directory
services from different network providers in a distributed computing environment to present a single set of directory service interfaces for managing network resources.
Administrators and developers can use ADSI services to enumerate and manage the
resources in a directory service, regardless of which network environment contains
the resource. Use Active Directory to perform common administrative tasks, such
as adding new users and managing printers throughout the distributed computing
environment.
<br />
<br />
This sample illustrates how to change a value of a property of an Active
Directory entry. It is a small console application that can be run from a command
prompt. The application takes three command line arguments. The first argument
must be a valid path to an active directory entry. The second argument is a property
name of the entry. The third argument is the new value of the entry.
<br />

Try running the following command substituting the path and property name for a
valid Active Directory path for your particular network:

<pre class="code">
&gt; ADWrite.exe &quot;LDAP://DC=Microsoft,DC=COM&quot; &quot;name&quot; &quot;Microsoft&quot;
</pre>

<br />
In its simplest form, writing to the Active Directory involves:

<ol>
<li>Creating a new <b>DirectoryEntry</b>:

<br /><br />
<table cellpadding=0 cellspacing=0 width="95%">
<tr>
<td>

<Acme:TabControl runat="server">
<Tab Name="C#">
String adPath = ... ;
DirectoryEntry objDirEnt=new DirectoryEntry(adPath);
</Tab>
<Tab Name="VB">
Dim adPath As String = ...
Dim objDirEnt As DirectoryEntry = New DirectoryEntry(adPath)
</Tab>
<Tab Name="C++">
//adpath got from command line.
DirectoryEntry* objDirEnt = new DirectoryEntry(adPath);
</Tab>
</Acme:TabControl>

</td>
</tr>
</table>
<br />


<li>Setting the <b>DirectoryEntry</b> object's properties:

<br /><br />
<table cellpadding=0 cellspacing=0 width="95%">
<tr>
<td>

<Acme:TabControl runat="server">
<Tab Name="C#">
String propertyName = ... ;
String newValue = ... ;

objDirEnt.Properties[propertyName].Value = newValue;
</Tab>
<Tab Name="VB">
Dim propertyName As String = ...
Dim newValue As String = ...

objDirEnt.Properties(propertyName).Value = newValue
</Tab>
<Tab Name="C++">
//propertyName and newValue got from command line.
(objDirEnt->Properties->get_Item(propertyName))->Value = newValue;
</Tab>
</Acme:TabControl>

</td>
</tr>
</table>
<br />

<li>Committing the changes to the Active Directory:

<br /><br />
<table cellpadding=0 cellspacing=0 width="95%">
<tr>
<td>

<Acme:TabControl runat="server">
<Tab Name="C#">
objDirEnt.CommitChanges();
</Tab>
<Tab Name="VB">
objDirEnt.CommitChanges()
</Tab>
<Tab Name="C++">
objDirEnt->CommitChanges();
</Tab>
</Acme:TabControl>

</td>
</tr>
</table>

</ol>

<h4>Example</h4>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/DirectoryServices/ADWrite/ADWrite.src"
        Icon="../../images/console.gif"
        Caption="C# ADWrite.exe"
	SamplePath="howto\samples\Services\DirectoryServices\ADWrite\"
        CanBeHosted="false"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/DirectoryServices/ADWrite/ADWrite.src"
        Icon="../../images/console.gif"
        Caption="VB ADWrite.exe"
	SamplePath="howto\samples\Services\DirectoryServices\ADWrite\"
        CanBeHosted="false"
        runat="server" />
  </VbTemplate>
  <CpTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/DirectoryServices/ADWrite/ADWrite.src"
        Icon="../../images/console.gif"
        Caption="C++ ADWrite.exe"
	SamplePath="howto\samples\Services\DirectoryServices\ADWrite\"
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
