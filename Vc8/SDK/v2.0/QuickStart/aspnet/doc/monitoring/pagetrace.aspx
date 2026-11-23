<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>

<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>


<h2>Trace Logging to Page Output</h2>

Page-level tracing enables you to write debugging statements directly to a page's output, and conditionally run
debugging code when tracing is enabled.  To enable tracing for a page, include the following directive at the top of the page code:

<pre class="code">
&lt;%@ Page Trace="true"%&gt;
</pre>

Trace statements can also be organized by category, using the <b>TraceMode</b> attribute of the <b>Page</b> directive.
If no <b>TraceMode</b> attribute is defined, the default value is <b>SortByTime</b>.

<pre class="code">
&lt;%@ Page Trace="true" TraceMode="SortByCategory" %&gt;
</pre>

The following example shows the default output when page-level tracing is enabled.  Note that ASP.NET inserts timing information for
important places in the page's execution lifecycle:

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/monitoring/tracing/TraceEnabled_cs.aspx"
        ViewSource="~/aspnet/samples/monitoring/tracing/TraceEnabled.src"
        Caption="C# Trace Enabled"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/monitoring/tracing/TraceEnabled_vb.aspx"
        ViewSource="~/aspnet/samples/monitoring/tracing/TraceEnabled.src"
        Caption="VB Trace Enabled"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

The page exposes a <b>Trace</b> property (of type <b>TraceContext</b>), which can be used to
output debugging statements to the page output, provided tracing is enabled.  Using <b>TraceContext</b>, you can write debugging statements using the <b>Trace.Write</b> and
<b>Trace.Warn</b> methods, which each take a message string or a category and message
string.  <b>Trace.Warn</b> statements are identical to <b>Trace.Write</b>
statements, except they are output in <span style="color:red">red</span>.

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
// Trace(Message)
Trace.Write("Beginning User Code...");
...
Trace.Warn("Array count is null!");
// Trace(Category, Message)
Trace.Write("Custom Trace","Beginning User Code...");
...
Trace.Warn("Custom Trace","Array count is null!");
</Tab>

<Tab Name="VB">
' Trace(Message)
Trace.Write("Beginning User Code...")
...
Trace.Warn("Array count is Nothing!")
' Trace(Category, Message)
Trace.Write("Custom Trace","Beginning User Code...")
...
Trace.Warn("Custom Trace","Array count is null!")
</Tab>

</Acme:TabControl>

<br />

When tracing is disabled (that is, when <b>Trace="false"</b> on the <b>Page</b> directive, or is not present), these statements do not run and no Trace output
appears in the client browser.  This makes it possible to keep debugging statements in production code and enable them conditionally
at a later time.

<br /><br />

Often you might need to run additional code to construct the statements to pass to the <b>Trace.Write</b> or <b>Trace.Warn</b> methods, where this
code should only run if tracing is enabled for the page.  To support this, <b>Page</b> exposes a Boolean property,
<b>Trace.IsEnabled</b>, which returns true only if tracing is enabled for the page.  You should check this property first to guarantee that your
debugging code can only run when tracing is on.

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
if (Trace.IsEnabled) {
    for (int i=0; i&lt;ds.Tables["Categories"].Rows.Count; i++) {
        Trace.Write("ProductCategory",ds.Tables["Categories"].Rows[i][0].ToString());
    }
}
</Tab>

<Tab Name="VB">
If Trace.IsEnabled Then
    For i=0 To ds.Tables("Categories").Rows.Count-1
        Trace.Write("ProductCategory",ds.Tables("Categories").Rows(i)(0).ToString())
    Next
End if
</Tab>

</Acme:TabControl>

<br />

The following example shows the use of <b>Trace.Write</b> and <b>Trace.Warn</b> to output debugging statements.  Also note the use of the <b>Trace.IsEnabled</b>
property to conditionally run extra debugging code.  In this example, the trace information has been sorted by category.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/monitoring/tracing/TraceWrite_cs.aspx"
        ViewSource="~/aspnet/samples/monitoring/tracing/TraceWrite.src"
        Caption="C# Trace Write"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/monitoring/tracing/TraceWrite_vb.aspx"
        ViewSource="~/aspnet/samples/monitoring/tracing/TraceWrite.src"
        Caption="VB Trace Write"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<h3>Integration of ASP.NET Trace and System.Diagnostics.Trace <span class="newinline">New in 2.0</span></h3>

ASP.NET Trace messages can be now forwarded to <b>System.Diagnostics.Trace</b> in order to make them available to generic processing infrastructure and tools consuming System.Diagnostics.Trace messages.  This feature can be enabled in the <trace> configuration section by setting <code>writeToDiagnosticsTrace</code> to true.
<br/><br/>
Likewise, System.Diagnostics.Trace messages can be consumed by ASP.NET Trace and displayed with the page trace messages in the page trace output or the application trace viewer.  This is incredibly useful to trace the execution of generic .NET components within ASP.NET pages.  This is accomplished by wiring up the <b>WebPageTraceListener</b> in the <listeners> element of the <trace> configuration section, as shown in the sample below:
<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/monitoring/tracing/DisplayingDiagnosticsTrace_cs.aspx"
        ViewSource="~/aspnet/samples/monitoring/tracing/DisplayingDiagnosticsTrace.src"
        Caption="C# Diagnostics Trace Integration"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/monitoring/tracing/DisplayingDiagnosticsTrace_vb.aspx"
        ViewSource="~/aspnet/samples/monitoring/tracing/DisplayingDiagnosticsTrace.src"
        Caption="VB Diagnostics Trace Integration"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br/>

Note that <code>trace</code> option must be enabled during compilation of code containing System.Diagnostics.Trace statements for them to generate messages.

<br /><br />

ASP.NET also provides a way to enable tracing for the entire application, not just a single page.  For more about application-level
tracing, click <a href="apptrace.aspx">here</a>.

</asp:Content>

