<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2>How Do I...Get all matches for a pattern</h2>

<br /><br />Regular Expressions are often useful when trying to retrieve small portions of
text from a large document, result set, or when filtering a stream.  The <b>MatchCollection</b>
object contains all valid <b>Match</b> objects for a given regular expression after a
successful match occurs.

<br /><br />
<Acme:TabControl runat="server">
<Tab Name="C#">
Regex digitregex = new Regex("(?&lt;number&gt;\\d+)");
String s = "abc 123 def 456 ghi 789";
  ...
MatchCollection ms = digitregex.Matches(s);
</Tab>
<Tab Name="VB">
Dim DigitRegex As Regex = New Regex("(?&lt;number&gt;\d+)")
Dim S As String = "abc 123 def 456 ghi 789"
  ...
Dim Mc As MatchCollection = DigitRegex.Matches(S)
</Tab>
<Tab Name="C++">
Regex * digitregex = new Regex(S"(?<number>\\d+)");
String * s = S"abc 123 def 456 ghi 789";
  ...
MatchCollection * mc = digitregex->Matches(s);
</Tab>
</Acme:TabControl>

<br /><br />
The following example illustrates how to create a <b>Regex</b> that matches numbers in a string.
The <b>Matches</b> method is callled to return a <b>MatchCollection</b>.  If the <b>Count</b>
property equals 0, no successful matches have occured.  If there are matches, the results
of each are displayed.

<h2>Example</h2>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/RegularExpressions/RegexMatches/RegexMatches.src"
        Icon="../../images/console.gif"
        Caption="C# RegexMatches.exe"
	SamplePath="howto\samples\RegularExpressions\RegexMatches\"
        CanBeHosted="false"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/RegularExpressions/RegexMatches/RegexMatches.src"
        Icon="../../images/console.gif"
        Caption="VB RegexMatches.exe"
	SamplePath="howto\samples\RegularExpressions\RegexMatches\"
        CanBeHosted="false"
        runat="server" />
  </VbTemplate>
  <CpTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/RegularExpressions/RegexMatches/RegexMatches.src"
        Icon="../../images/console.gif"
        Caption="C++ RegexMatches.exe"
	SamplePath="howto\samples\RegularExpressions\RegexMatches\"
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

