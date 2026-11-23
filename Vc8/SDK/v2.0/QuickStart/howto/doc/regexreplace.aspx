<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2>How Do I...Use Regular Expressions to make replacements?</h2>

<br /><br />The Regular Expressions library can often ease the time it takes to generate
string replacement functions.  By specifying a pattern of strings to be replaced,
you do not have to search for every possible variation of a string.  Once a
<b>Regex</b> object that matches every possible string to be replaced is created, 
the <b>Replace</b> method can be used to generate a result.  The <b>Replace</b>
method can be most easily used by passing in the source string and the
replacement string.  The <b>Replace</b> method will return the results as a String.

<br /><br />
<Acme:TabControl runat="server">
<Tab Name="C#">
Regex digitregex = new Regex("(?&lt;digit&gt;[0-9])");
String before = "Here is so4848me te88xt with emb4493edded numbers.";
 ...
String after = digitregex.Replace(before, "");
</Tab>
<Tab Name="VB">
Dim digitregex As Regex = new Regex("(?&lt;digit&gt;[0-9])")
Dim Before As String = "Here is so4848me te88xt with emb4493edded numbers."
 ...
Dim After As String = DigitRegex.Replace(Before, "")
</Tab>
<Tab Name="C++">
Regex * digitregex = new Regex(S"(?<digit>[0-9])");
String * before = S"Here is so4848me te88xt with emb4493edded numbers.";
 ...
String * after = digitregex -> Replace(before, "");
</Tab>
</Acme:TabControl>

<br /><br />
You can also reuse the matched string in the replacement.  In the previous snippet
we have a named capture of <span class="code">?&lt;digit&gt;</span>.  This named capture
can be reused in the replacement string as <span class="code">${digit}</span>.
Note that ordinal captures can be used as well, <span class="code">$123</span>,
which would evaluate to 123 captures in our pattern.

<br /><br />
This example illustrates how to use the <b>Replace</b> method of <b>Regex</b> to
remove all digits from the input string.

<h2>Example</h4>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/RegularExpressions/RegexReplace/RegexReplace.src"
        Icon="../../images/console.gif"
        Caption="C# RegexReplace.exe"
	SamplePath="howto\samples\RegularExpressions\RegexReplace\"
        CanBeHosted="false"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/RegularExpressions/RegexReplace/RegexReplace.src"
        Icon="../../images/console.gif"
        Caption="VB RegexReplace.exe"
	SamplePath="howto\samples\RegularExpressions\RegexReplace\"
        CanBeHosted="false"
        runat="server" />
  </VbTemplate>
  <CpTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/RegularExpressions/RegexReplace/RegexReplace.src"
        Icon="../../images/console.gif"
        Caption="C++ RegexReplace.exe"
	SamplePath="howto\samples\RegularExpressions\RegexReplace\"
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
