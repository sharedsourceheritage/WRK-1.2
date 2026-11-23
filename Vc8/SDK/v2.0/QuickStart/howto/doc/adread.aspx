<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2>How Do I...Access Active Directory?</h2>

The Active Directory Service Interface (ADSI) accesses the capabilities of directory services from different network providers in a distributed computing environment to present a single
set of directory service interfaces for managing network resources.
Administrators and developers can use ADSI services to enumerate and manage the
resources in a directory service, regardless of which network environment contains
the resource. Use Active Directory to perform common administrative tasks, such
as locating resources throughout the distributed computing environment.

<br /><br />

This sample illustrates how to locate resources in the Active Directory. It is
a small console application that can be run from a command prompt. The
application takes one command line argument. The first argument has to be a
valid path to an Active Directory entry.

<br /><br />

Try running the following command, substituting the path for a valid Active Directory
path for your particular network:

<pre class="code">
&gt; ADRead.exe &quot;LDAP://CN=Clarify Operations Team,OU=Distribution Lists,DC=fabricom,DC=com&quot;
</pre>

In its simplest form, reading from the Active Directory involves:

<ol>
<li>Creating a new <b>DirectoryEntry</b>:

<br /><br />
<table cellpadding=0 cellspacing=0 width="95%">
<tr>
<td>

<Acme:TabControl runat="server">
<Tab Name="C#">
DirectoryEntry objDirEnt = new DirectoryEntry(path);
</Tab>
<Tab Name="VB">
Dim objDirEnt As DirectoryEntry = New DirectoryEntry(path)
</Tab>
<Tab Name="C++">
DirectoryEntry* objDirEnt = new DirectoryEntry(path);
</Tab>
</Acme:TabControl>

</td>
</tr>
</table>

<br /><br />

<li>Reading the information from the Active Directory and printing it to the screen:

<br /><br />

<table cellpadding=0 cellspacing=0 width="95%">
<tr>
<td>

<Acme:TabControl runat="server">
<Tab Name="C#">
string tab = "    ";
foreach(string key in objDirEnt.Properties.PropertyNames) {
    Console.WriteLine(tab + key + " = ");
    foreach(Object objCollection in objDirEnt.Properties[key])
        Console.WriteLine(tab + tab + objCollection);
}



</Tab>
<Tab Name="VB">
Dim tab As String = "    "
Dim key As String
Dim objCollection As Object

For Each Key In objDirEnt.Properties.PropertyNames
    Console.WriteLine(tab & key & " = ")
    For Each objCollection In objDirEnt.Properties(key)
            Console.WriteLine(tab & tab & CStr(objCollection))
    Next
Next
</Tab>
<Tab Name="C++">

ICollection* ValCol = objDirEnt->Properties->get_Item(Key);
if (ValCol->Count > 0)
{
	IEnumerator* Enum2 = ValCol->GetEnumerator();
	while (Enum2->MoveNext())
	{
		objValue = Enum2->Current;
		Console::WriteLine(S"\t\t{0}", objValue);
	}
}
</Tab>
</Acme:TabControl>

</td>
</tr>
</table>

</ol>

<h3>Example</h3>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/DirectoryServices/ADRead/ADRead.src"
        Icon="../../images/console.gif"
        Caption="C# ADRead.exe"
	SamplePath="howto\samples\Services\DirectoryServices\ADRead\"
        CanBeHosted="false"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/DirectoryServices/ADRead/ADRead.src"
        Icon="../../images/console.gif"
        Caption="VB ADRead.exe"
	SamplePath="howto\samples\Services\DirectoryServices\ADRead\"
        CanBeHosted="false"
        runat="server" />
  </VbTemplate>
  <CpTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/DirectoryServices/ADRead/ADRead.src"
        Icon="../../images/console.gif"
        Caption="C++ ADRead.exe"
	SamplePath="howto\samples\Services\DirectoryServices\ADRead\"
        CanBeHosted="false"
        runat="server" />
  </CpTemplate>
 <VjsTemplate>
       <Acme:SourceRef
        RunSample=""
        ViewSource=""
        Icon = ""
        Caption=""
	SamplePath=""
        CanBeHosted="false"
        runat="server" />
  </VjsTemplate>
</Acme:LangSwitch>

</asp:Content>
