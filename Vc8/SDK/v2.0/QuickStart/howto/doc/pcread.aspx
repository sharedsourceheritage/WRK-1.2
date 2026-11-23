<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2>How Do I...Read from a performance counter?</h2>

<br /><br />Windows performance counters enable
your applications and components to publish, capture (read), and analyze the
performance data that applications, services, and drivers provide. You can use
this information to determine system bottlenecks and fine-tune system and
application performance. For example, you can use a performance counter to
track the number of orders processed per second or a system's processor
utilization. Using the common language runtime's <b>PerformanceCounter</b>
component, you can easily read performance data relevant to your
application, such as those mentioned above.

<br /><br />
This sample illustrates how to read simple performance information from a
performance counter. It is a small console application that can be run from a
command prompt. The application takes three command line arguments. The first is
a performance object name (category). The second argument is the counter name.
The third argument is the counter instance name.

<br /><br />
For example, in order to see the processor utilization on your machine run
the sample with the following command line arguments:

<pre class="code">
&gt; PCRead.exe &quot;Processor&quot; &quot;% Processor Time&quot; &quot;_Total&quot;
</pre>

<br /><br />
You will see the processor utilization data updated every half-second.

<br /><br />
In its simplest form, reading a performance counter involves:

<ol>

<li>Creating a new instance of a <b>PerformanceCounter</b> component and pointing it to an appropriate
performance counter:


<br /><br />
<table cellpadding=0 cellspacing=0 width="95%">
<tr>
<td>

<Acme:TabControl runat="server">
<Tab Name="C#">
String objectName = ... ;
String counterName = ... ;
String instanceName = ... ;

PerformanceCounter counter;
counter = new PerformanceCounter(objectName, counterName, instanceName);
</Tab>
<Tab Name="VB">
Dim objectName As String = ...
Dim counterName As String = ...
Dim instanceName As String = ...

Dim counter As PerformanceCounter
counter = New PerformanceCounter(objectName, counterName, instanceName)
</Tab>
<Tab Name="C++">
String* objectName = ... ;
String* counterName = ... ;
String* instanceName = ... ;

PerformanceCounter* counter;
counter = new PerformanceCounter(objectName, counterName, instanceName);

</Tab>
</Acme:TabControl>

</td>
</tr>
</table>
<br /><br />

<li>Reading the <b>NextValue</b> property of the counter:

<br /><br />
<table cellpadding=0 cellspacing=0 width="95%">
<tr>
<td>

<Acme:TabControl runat="server">
<Tab Name="C#">
counter.NextValue();
</Tab>
<Tab Name="VB">
counter.NextValue()
</Tab>
<Tab Name="C++">
Counter->NextValue()
</Tab>
</Acme:TabControl>

</td>
</tr>
</table>

</ol>

<br /><br />Remember that you have to read <b>NextValue</b> more than once to get a relevant data.

<h2>Example</h2>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/PerformanceCounters/PCRead/PCRead.src"
        Icon="../../images/console.gif"
        Caption="C# PCRead.exe"
	SamplePath="howto\samples\Services\PerformanceCounters\PCRead\"
        CanBeHosted="false"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/PerformanceCounters/PCRead/PCRead.src"
        Icon="../../images/console.gif"
        Caption="VB PCRead.exe"
	SamplePath="howto\samples\Services\PerformanceCounters\PCRead\"
        CanBeHosted="false"
        runat="server" />
  </VbTemplate>
  <CpTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/PerformanceCounters/PCRead/PCRead.src"
        Icon="../../images/console.gif"
        Caption="C++ PCRead.exe"
	SamplePath="howto\samples\Services\PerformanceCounters\PCRead\"
        CanBeHosted="false"
        runat="server" />
  </CpTemplate>
  <VjsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/PerformanceCounters/PCRead/PCRead.src"
        Icon="../../images/console.gif"
        Caption="J# PCRead.exe"
	SamplePath="howto\samples\Services\PerformanceCounters\PCRead\"
        CanBeHosted="false"
        runat="server" />	
  </VjsTemplate>
</Acme:LangSwitch>

</asp:Content>


