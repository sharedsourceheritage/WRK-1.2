<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2>How Do I...Use different text encodings?</h2>

<div class="indent" style="width:660"><br /><br />
This sample illustrates how to use multiple encoding formats available
from the <b>System.Text</b> namespace.  A <b>StreamWriter</b> object is created
and passed a <b>Stream</b> object along with an <b>Encoding</b> object
from the <b>System.Text</b> namespace.  Once created, any output method calls
on the <b>StreamWriter</b> object will be written in the specified encoding.

<br /><br />
<Acme:TabControl runat="server">
<Tab Name="C#">
FileStream fs = new FileStream("text.txt", FileMode.OpenOrCreate);
 ...
StreamWriter t = new StreamWriter (fs, Encoding.UTF8);
t.Write("This is in UTF8");
</Tab>
<Tab Name="VB">
Dim Fs As FileStream = New FileStream("text.txt", FileMode.OpenOrCreate)
 ...
Dim T As StreamWriter = New StreamWriter (Fs, Encoding.UTF8)
T.Write("This is in UTF8")
</Tab>
<Tab Name="C++">
FileStream* fs = new FileStream("text.txt", FileMode::OpenOrCreate);
 ...
StreamWriter* t = new StreamWriter (fs, Encoding::UTF8);
T.Write("This is in UTF8");
</Tab>
</Acme:TabControl>

<br /><br />
A <b>StreamReader</b> object is used to read text in a given encoding and is
constructed in the same manner as a <b>StreamWriter</b> object.

<br /><br />
<Acme:TabControl runat="server">
<Tab Name="C#">
FileStream fs = new FileStream("text.txt", FileMode.Open);
 ...
StreamReader t = new StreamReader(fs, Encoding.UTF8);
String s = t.ReadLine();
</Tab>
<Tab Name="VB">
Dim Fs As FileStream = New FileStream("text.txt", FileMode.Open)
 ...
Dim T As StreamReader = New StreamReader(Fs, Encoding.UTF8)
Dim S As String = T.ReadLine()
</Tab>
<Tab Name="C++">
FileStream* fs = new FileStream("text.txt", FileMode::OpenOrCreate);
 ...
StreamWriter* t = new StreamWriter (fs, Encoding::UTF8);
String* s = t->ReadLine();
</Tab>
</Acme:TabControl>

<br /><br />
The following example illustrates creating <b>StreamWriter</b> objects
of different encodings and using each object to write to a text file.
</div>

<h2>Example</h2>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/globalization/encoding/encoding.src"
        Icon="../../images/console.gif"
        Caption="C# Encoding.exe"
	SamplePath="howto\samples\globalization\encoding\"
        CanBeHosted="false"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/globalization/encoding/encoding.src"
        Icon="../../images/console.gif"
        Caption="VB Encoding.exe"
	SamplePath="howto\samples\globalization\encoding\"
        CanBeHosted="false"
        runat="server" />
  </VbTemplate>
  <CpTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/globalization/encoding/encoding.src"
        Icon="../../images/console.gif"
        Caption="C++ Encoding.exe"
	SamplePath="howto\samples\globalization\encoding\"
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
