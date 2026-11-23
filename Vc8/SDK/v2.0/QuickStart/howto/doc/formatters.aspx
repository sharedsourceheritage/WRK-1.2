<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2>How Do I...Use message formatters?</h2>

<br /><br />Message queuing makes it easy for application developers to communicate with application
programs quickly and reliably by sending and receiving messages. Messaging
provides you with guaranteed message delivery and a robust, fail-safe way to
carry out many of your business processes.
<br /><br />
The <b>MessageQueue</b> component allows you to easily incorporate message-based
communication into your applications. Using this component and its associated
language features, you can send and receive messages, explore existing queues,
create and delete queues, and perform a variety of other operations using a
simple programming model.
<br /><br />
The sample illustrates how to use the <b>MessageQueue</b> component to use different
serialization mechanisms to send objects through a message queue. To run the
sample you have to have Message Queuing installed on your system.
<br /><br />
Selecting a serialization mechanism is as simple as changing the value of one
property. Here are some examples:

<ol>
<li> Send a message using an XML based serialization mechanism:

<br /><br />
<table cellpadding=0 cellspacing=0 width="95%">
<tr>
<td>

<Acme:TabControl runat="server">
<Tab Name="C#">
mq.Formatter = new XmlMessageFormatter();
mq.Send(order);
</Tab>
<Tab Name="VB">
mq.Formatter = New XmlMessageFormatter()
mq.Send(order)
</Tab>
<Tab Name="C++">
mq->Formatter = new XmlMessageFormatter;
mq->Send(order);
</Tab>
</Acme:TabControl>

</td>
</tr>
</table>
<br /><br />

<li>Send a message using a binary serialization mechanism:

<br /><br />
<table cellpadding=0 cellspacing=0 width="95%">
<tr>
<td>

<Acme:TabControl runat="server">
<Tab Name="C#">
mq.Formatter = new BinaryMessageFormatter();
mq.Send(order);
</Tab>
<Tab Name="VB">
mq.Formatter = New BinaryMessageFormatter()
mq.Send(order)
</Tab>
<Tab Name="C++">
mq->Formatter = new BinaryMessageFormatter;        
mq->Send(order);
</Tab>
</Acme:TabControl>

</td>
</tr>
</table>
<br /><br />

<li>
Send a message using a serialization mechanism which is compatible with the
MSMQ ActiveX Formatter:

<br /><br />
<table cellpadding=0 cellspacing=0 width="95%">
<tr>
<td>

<Acme:TabControl runat="server">
<Tab Name="C#">
mq.Formatter = new ActiveXMessageFormatter();
mq.Send(order);
</Tab>
<Tab Name="VB">
mq.Formatter = New ActiveXMessageFormatter()
mq.Send(order)
</Tab>
<Tab Name="C++">
mq->Formatter = new ActiveXMessageFormatter;     
mq->Send(order);
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
        ViewSource="~/howto/samples/Services/MessageQueue/Formatters/Formatters.src"
        Icon="../../images/console.gif"
        Caption="C# Formatters.exe"
	SamplePath="howto\samples\Services\MessageQueue\Formatters\"
        CanBeHosted="false"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/MessageQueue/Formatters/Formatters.src"
        Icon="../../images/console.gif"
        Caption="VB Formatters.exe"
	SamplePath="howto\samples\Services\MessageQueue\Formatters\"
        CanBeHosted="false"
        runat="server" />
  </VbTemplate>
  <CpTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/MessageQueue/Formatters/Formatters.src"
        Icon="../../images/console.gif"
        Caption="C++ Formatters.exe"
	SamplePath="howto\samples\Services\MessageQueue\Formatters\"
        CanBeHosted="false"
        runat="server" />
  </CpTemplate>
 <VjsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/MessageQueue/Formatters/Formatters.src"
        Icon="../../images/console.gif"
        Caption="J# Formatters.exe"
	SamplePath="howto\samples\Services\MessageQueue\Formatters\"
        CanBeHosted="false"
        runat="server" />	
  </VjsTemplate>
</Acme:LangSwitch>
</asp:Content>

