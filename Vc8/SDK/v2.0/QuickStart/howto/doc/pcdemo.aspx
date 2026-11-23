<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2>How Do I...Count rate of change?</h2>

<br /><br />Windows performance counters enable
your applications and components to publish, capture, and analyze the
performance data that applications, services, and drivers provide. You can use
this information to determine system bottlenecks and fine-tune system and
application performance. For example, you can use a performance counter to
track the number of orders processes per second or the number of users currently
connected to the system. Using the common language runtime's <b>PerformanceCounter</b>
component, you can easily create your own custom counters and publish
performance data relevant to your application, such as those mentioned above.

<br /><br />
This sample illustrates how to publish the number of orders processed per second using a
custom performance counter. It's a small console application you can run
from the command prompt.

You have to run the app first to install the counter as follows:

<pre class="code">
&gt; PCDemo.exe /inst
</pre>

Then you have to run the app again without any arguments to see it work as follows:

<pre class="code">
&gt; PCDemo.exe
</pre>


<br /><br />
Now, wait for the application to display "Started" and run the PerfMon.exe.
In PerfMon, choose the Add toolbar button. A dialog will open.
Select the ACounterDemo performance object, CountPerSecond
counter, and _Total instance. Choose Add, close the
dialog, and notice that you can use the PCDemo sample to change the published
value by pressing + or -. When the application starts,
it simulates the processing of two new orders per
second. The + and - keys can be used to double the number or divide it in two.

<br /><br />
To delete the counter you could run the app with the delete switch as follows:

<pre class="code">
&gt; PCDemo.exe /del
</pre>

<br /><br />
In its simplest form, writing to a custom performance counter that counts number of
items per second involves:

<ol>

<li>Creating a counter of the <b>RateOfCountsPerSecond32</b> type:

<br /><br />
<table cellpadding=0 cellspacing=0 width="95%">
<tr>
<td>

<Acme:TabControl runat="server">
<Tab Name="C#">
if(!PerformanceCounterCategory.Exists(objectName)) {
    CounterCreationData ccd = new CounterCreationData();
    ccd.CounterName = counterName;
    ccd.CounterType = PerformanceCounterType.RateOfCountsPerSecond32;
    CounterCreationDataCollection ccds = new CounterCreationDataCollection();
    ccds.Add(ccd);

    PerformanceCounterCategory.Create(objectName,"Sample Object",ccds);
}
</Tab>
<Tab Name="VB">
If Not PerformanceCounterCategory.Exists(objectName) Then
    Dim ccd As CounterCreationData = new CounterCreationData()
    ccd.CounterName = counterName
    ccd.CounterType = PerformanceCounterType.RateOfCountsPerSecond32
    Dim ccds As New CounterCreationDataCollection
    ccds.Add(ccd)

    PerformanceCounterCategory.Create(objectName,"Sample Object",ccds)
End If
</Tab>
<Tab Name="C++">
if(!PerformanceCounterCategory::Exists(objectName)) {
    CounterCreationData* ccd = new CounterCreationData();
    ccd->CounterName = counterName;
    ccd->CounterType = PerformanceCounterType::RateOfCountsPerSecond32;
    CounterCreationDataCollection* ccds = new CounterCreationDataCollection();
    ccds->Add(ccd);
}
</Tab>
</Acme:TabControl>

</td>
</tr>
</table>
<br /><br />

<li>Creating a new instance of a <b>PerformanceCounter</b> component and pointing it to an appropriate performance
counter:

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
counter = new PerformanceCounter(objectName, counterName, instanceName, false);
</Tab>
</Acme:TabControl>

</td>
</tr>
</table>
<br /><br />


<li>Setting the <b>RawValue</b> property of the counter:


<br /><br />
<table cellpadding=0 cellspacing=0 width="95%">
<tr>
<td>

<Acme:TabControl runat="server">
<Tab Name="C#">
counter.IncrementBy(1);
</Tab>
<Tab Name="VB">
counter.IncrementBy(1)
</Tab>
<Tab Name="C++">
Counter->Increment();
</Tab>
</Acme:TabControl>

</td>
</tr>
</table>

</ol>

<h2>Example</h2>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/PerformanceCounters/PCDemo/PCDemo.src"
        Icon="../../images/console.gif"
        Caption="C# PCDemo.exe"
	SamplePath="howto\samples\Services\PerformanceCounters\PCDemo\"
        CanBeHosted="false"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/PerformanceCounters/PCDemo/PCDemo.src"
        Icon="../../images/console.gif"
        Caption="VB PCDemo.exe"
	SamplePath="howto\samples\Services\PerformanceCounters\PCDemo\"
        CanBeHosted="false"
        runat="server" />
  </VbTemplate>
  <CpTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/PerformanceCounters/PCDemo/PCDemo.src"
        Icon="../../images/console.gif"
        Caption="C++ PCDemo.exe"
	SamplePath="howto\samples\Services\PerformanceCounters\PCDemo\"
        CanBeHosted="false"
        runat="server" />
  </CpTemplate>
  <VjsTemplate>
        <Acme:SourceRef
       RunSample=""
        ViewSource="~/howto/samples/Services/PerformanceCounters/PCDemo/PCDemo.src"
        Icon="../../images/console.gif"
        Caption="J# PCDemo.exe"
	SamplePath="howto\samples\Services\PerformanceCounters\PCDemo\"
        CanBeHosted="false"
        runat="server" />	
  </VjsTemplate>
</Acme:LangSwitch>

</asp:Content>

