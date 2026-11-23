<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2>How Do I...Receive a message from a message queue?</h2>

<br /><br />Message queuing makes it easy for application developers to communicate with application
programs quickly and reliably by sending and receiving messages. Messaging provides you
with guaranteed message delivery and a robust, fail-safe way to carry out many of your
business processes.
<br /><br />
The <b>MessageQueue</b> component allows you to easily incorporate message-based communication into your applications.
Using this component and its associated language features, you can send and receive messages, explore existing
queues, create and delete queues, and perform a variety of other operations using a simple programming model.
<br /><br />
The sample illustrates how to use the <b>MessageQueue</b> component to receive a message from a message queue. To run
the sample you have to have Message Queuing installed on your system. The sample is a command-line application
that takes one command-line argument. The argument is the name of a public message queue on your local machine.
For example, you can run it as follows (first send a message to the queue using the MQSend sample):

<pre class="code">
&gt; MQReceive.exe MyQueue
</pre>

The sample application will receive and output to the console the first message from the queue.
In its simplest form, receiving a message from a message queue involves:

<ol>
<li> Creating an instance of the <b>MessageQueue</b> component, setting its <b>Path</b>, and initializing the Formatter's
<b>TargetTypeNames</b> property:
<br /><br />
<table cellpadding=0 cellspacing=0 width="95%">
<tr>
<td>

<Acme:TabControl runat="server">
<Tab Name="C#">
MessageQueue mq = new MessageQueue(&quot;.\\MyQueue&quot;);
string[] types = { &quot;System.String&quot; };
((XmlMessageFormatter)mq.Formatter).TargetTypeNames = types;
</Tab>
<Tab Name="VB">
Dim mq As MessageQueue = new MessageQueue(mqPath)
Dim formatter As XmlMessageFormatter = CType(mq.Formatter,XmlMessageFormatter)
formatter.TargetTypeNames = new String(){"System.String"}
</Tab>
<Tab Name="C++">
MessageQueue* mq = new MessageQueue(mqPath);
String* strTypeNames[] = { S"System.String,mscorlib" };
__try_cast<XmlMessageFormatter*>( mq->Formatter )->TargetTypeNames = strTypeNames;
</Tab>
</Acme:TabControl>

</td>
</tr>
</table>
<br /><br />

<li> Calling <b>Receive</b> to receive the message:
<br /><br />
<table cellpadding=0 cellspacing=0 width="95%">
<tr>
<td>

<Acme:TabControl runat="server">
<Tab Name="C#">
Message m = mq.Receive(new TimeSpan(0,0,3));
Console.WriteLine((string)m.Body);
</Tab>
<Tab Name="VB">
Dim m As Message = mq.Receive(New TimeSpan(0,0,3))
Console.WriteLine(CStr(m.Body))
</Tab>
<Tab Name="C++">
Message* m = mq->Receive( TimeSpan(0,0,3) );
Console::WriteLine( String::Concat( S"Message: ", __try_cast<String*>(m->Body) ) );
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
        ViewSource="~/howto/samples/Services/MessageQueue/MQReceive/MQReceive.src"
        Icon="../../images/console.gif"
        Caption="C# MQReceive.exe"
	SamplePath="howto\samples\Services\MessageQueue\MQReceive\"
        CanBeHosted="false"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/MessageQueue/MQReceive/MQReceive.src"
        Icon="../../images/console.gif"
        Caption="VB MQReceive.exe"
	SamplePath="howto\samples\Services\MessageQueue\MQReceive\"
        CanBeHosted="false"
        runat="server" />
  </VbTemplate>
  <CpTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/MessageQueue/MQReceive/MQReceive.src"
        Icon="../../images/console.gif"
        Caption="C++ MQReceive.exe"
	SamplePath="howto\samples\Services\MessageQueue\MQReceive\"
        CanBeHosted="false"
        runat="server" />
  </CPTemplate>
 <VjsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/Services/MessageQueue/MQReceive/MQReceive.src"
        Icon="../../images/console.gif"
        Caption="J# MQReceive.exe"
	SamplePath="howto\samples\Services\MessageQueue\MQReceive\"
        CanBeHosted="false"
        runat="server" />	
  </VjsTemplate>
</Acme:LangSwitch>
</asp:Content>

