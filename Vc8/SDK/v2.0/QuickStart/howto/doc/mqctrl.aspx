<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2>How Do I...Control a message queue?</h2>

<br /><br />Message queuing makes it easy for application developers to
communicate with application programs quickly and reliably by
sending and receiving messages. Messaging provides you with
guaranteed message delivery and a robust, fail-safe way to
carry out many of your business processes.

<br /><br />The <b>MessageQueue</b> component allows you to easily incorporate message-based
communication into your applications. Using this component and its associated
language features, you can send and receive messages, explore existing queues,
create and delete queues, and perform a variety of other operations using a
simple programming model.

<br /><br />This sample illustrates how to change some properties of a message queue. It is a
small console application that can be run from a command prompt. Run the sample
without any command-line arguments and it will print its full usage
instructions.

<br /><br />For example, if you want change a queue's label, run:

<pre class="code">
&gt; MQCtrl.exe MyQueue l &quot;New Label&quot;
</pre>

<br /><br />In its simplest form, changing a property of a message queue involves:

<ol>
<li>Creating a new instance of a <b>MessageQueue</b> component and pointing it to an existing queue:

<br /><br />
<table cellpadding=0 cellspacing=0 width="95%">
<tr>
<td>

<Acme:TabControl runat="server">
<Tab Name="C#">
MessageQueue mq = new MessageQueue(mqPath);
</Tab>
<Tab Name="VB">
Dim mq As MessageQueue = New MessageQueue(mqPath)
</Tab>
<Tab Name="C++">
MessageQueue* mq = new MessageQueue(mqPath);
</Tab>
</Acme:TabControl>

</td>
</tr>
</table>
<br /><br />

<li>Setting the property to a new value:

<br /><br />
<table cellpadding=0 cellspacing=0 width="95%">
<tr>
<td>

<Acme:TabControl runat="server">
<Tab Name="C#">
mq.Label = &quot;New Label&quot;;
</Tab>
<Tab Name="VB">
mq.Label = &quot;New Label&quot;
</Tab>
<Tab Name="C++">
mq->Label = &quot;New Label&quot;;
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
        ViewSource="~/howto/samples/Services/MessageQueue/MQCtrl/MQCtrl.src"
        Icon="../../images/console.gif"
        Caption="C# MQCtrl.exe"
	SamplePath="howto\samples\Services\MessageQueue\MQCtrl\"
        CanBeHosted="false"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/MessageQueue/MQCtrl/MQCtrl.src"
        Icon="../../images/console.gif"
        Caption="VB MQCtrl.exe"
	SamplePath="howto\samples\Services\MessageQueue\MQCtrl\"
        CanBeHosted="false"
        runat="server" />
  </VbTemplate>
  <CPTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/MessageQueue/MQCtrl/MQCtrl.src"
        Icon="../../images/console.gif"
        Caption="C++ MQCtrl.exe"
	SamplePath="howto\samples\Services\MessageQueue\MQCtrl\"
        CanBeHosted="false"
        runat="server" />
  </CpTemplate>
 <VjsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/MessageQueue/MQCtrl/MQCtrl.src"
        Icon="../../images/console.gif"
        Caption="J# MQCtrl.exe"
	SamplePath="howto\samples\Services\MessageQueue\MQCtrl\"
        CanBeHosted="false"
        runat="server" />	
  </VjsTemplate>
</Acme:LangSwitch>
</asp:Content>

