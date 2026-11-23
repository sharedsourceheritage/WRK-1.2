<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Configuring the Process Model</h2>

One of the most important requirements for ASP.NET Framework applications is
reliability.
The architecture of applications running inside the server process (in IIS, Inetinfo.exe) does not produce a solid foundation for
building reliable applications that can continue to run over a
long period of time.  Too many resources are shared on the process
level, and it is too easy for an error to bring down the entire server process.

<br /><br />

To solve this problem, ASP.NET provides an out-of-process
execution model, which protects the server process from user code.
It also enables you to apply heuristics to the lifetime of the
process to improve the availability of your Web applications.
Using asynchronous interprocess communication enables you to
provide the best balance of performance, scalability, and reliability.

<!--BEGIN SUB SECTION-->
<a name="config"></a>
<h3>Process Model Configuration</h3>

Process model settings are exposed in the root configuration file for the computer,
Machine.config.  The configuration section is named <b>&lt;processModel&gt;</b> and is shown in the following example.
On Windows 2000 and Windows XP, the process model is enabled by default (enable="true").

<p>

If ASP.NET runs on IIS 6.0 (Windows Server 2003 family) in IIS6 native mode (Worker 
Process Isolation Mode), the &lt;processModel&gt; section is ignored,
and built-in IIS6 process model settings are used instead. The ASP.NET 2.0 &lt;processModel&gt; section applies if IIS 6.0 runs in IIS5 Isolation (compatibility) mode.

<pre class="code">&lt;processModel
    enable="true"
    timeout="Infinite"
    idleTimeout="Infinite"
    shutdownTimeout="0:00:05" 
    requestLimit="Infinite" 
    requestQueueLimit="5000" 
    restartQueueLimit="10"
    memoryLimit="60" 
    webGarden="false"
    cpuMask="0xffffffff"
    userName="machine"
    password="AutoGenerate"
    logLevel="Errors"
    clientConnectedCheck="0:00:05"
    comAuthenticationLevel="Connect"
    comImpersonationLevel="Impersonate"
    responseRestartDeadlockInterval="00:03:00"
    responseDeadlockInterval="00:03:00" 
    maxWorkerThreads="20"
    maxIoThreads="20"
/&gt;
</pre>

Most of these settings control when a new worker process is
started to serve requests (gracefully taking the place of an old
worker process).  The process model supports two types of recycling:
reactive and proactive. The 'userName' and 'password' attributes define the 
account under which the ASP.NET worker process runs.&nbsp; These default to 
'machine' and 'autogenerate' respectively.&nbsp; These values tell ASP.NET to 
use the built-in ASPNET account and to use a cryptographically strong random 
password stored in the Local Security Authority (LSA) for that account.&nbsp; As 
noted above, by default on the Windows Server 2003 family, ASP.NET runs as part of the w3wp 
process using the default identity &quot;NETWORK SERVICE&quot;.&nbsp; 

<br /><br />

If you want a more privileged process, you can set the
<b>userName</b> attribute to <b>System</b>, 
which causes the ASP.NET worker process to run with the same identity as the 
inetinfo.exe process. This process runs by default as the System identity. When 
so configured, the ASP.NET worker process will have the right to access nearly 
all resources on the local machine. In Windows 2000, Windows XP, and the Windows 
Server 2003 family systems, the System account also has network credentials and 
can access network resources as the machine account.
<br /><br />

To configure the process to run as System, change the
<b>userName</b> attribute in the <b>&lt;processModel&gt;</b> 
section of machine.config as follows:

<pre class="code">
&lt;processModel&nbsp; userName=&quot;system&quot; password=&quot;autogenerate&quot; …/&gt;
</pre>

<!--BEGIN SUB SECTION-->
<a name="reactive"></a>
<h3>Reactive Process Recycling</h3>

Reactive process recycling occurs when a process is misbehaving or
unable to serve requests.  The process typically displays detectable
symptoms, such as deadlocks, access violations,
memory leaks, and so on,
in order to trigger a process recycle.  You can control the conditions that
trigger a process restart by using the configuration settings described in the following table.

<br /><br />

<table class="table">
<tr>
<th width="*">Setting</th><th width="70%">Description</th>
</tr>
<tr>
  <td>
    <b>requestQueueLimit</b>
  </td>
  <td>
Handles deadlock conditions.  The DWORD value is set to the
maximum allowed number of requests
in the queue, after which the worker process is considered to be
misbehaving. When the number is exceeded, a new process
is
launched and the requests are reassigned.  The default is 5000 requests.
</td>
</tr>
<tr>
  <td>
    <b>memoryLimit</b>
  </td>
  <td>
Handles memory leak conditions.  The DWORD
 value is set to the percentage of physical memory
that the worker process can consume before it is considered to be
misbehaving. When that percentage is exceeded, a new process is
launched and the requests are reassigned.  The default is
60%.
  </td>
</tr>
<tr>
  <td>
    <b>shutdownTimeout</b>
  </td>
  <td>
Specifies the amount of time the worker process has
to shut itself down gracefully (string value in hr:min:sec format).
When the time out expires, the ASP.NET ISAPI shuts down the worker
process.  The default is "00:00:05".
  </td>
</tr>
</table>

<!--BEGIN SUB SECTION-->
<a name="proactive"></a>
<h3>Proactive Process Recycling</h3>

Proactive process recycling restarts the worker process periodically
even if the process is healthy.  This can be a useful way to prevent
denials of service due to conditions the process model is unable to
detect.  A process can be restarted after a specific number of
requests or after a time-out period has elapsed.

<br /><br />

<table class="table">
<tr>
<th width="20%">Setting</th><th width="100%">Description</th>
</tr>
<tr>
  <td>
    <b>timeout</b>
  </td>
  <td>
String value in hr:min:sec format that configures the time limit
after which a new worker process
will be launched to take the place of the current one. The default
is <b>Infinite</b>, a keyword indicating
that the process should not be restarted.
  </td>
</tr>
<tr>
  <td>
    <b>idleTimeout</b>
  </td>
  <td>
String value in hr:min:sec format that configures the amount of
inactivity, after which the
worker process is automatically shut down.  The default is <b>Infinite</b>,
a keyword indicating that
the process should not be restarted.
  </td>
</tr>
<tr>
  <td>
    <b>requestLimit</b>
  </td>
  <td>
DWORD value set to the number of requests after which a new worker
process will be launched to take the
place of the current one.  The default is <b>Infinite</b>, a keyword
indicating that the process
should not be restarted.
  </td>
</tr>
</table>

<!--BEGIN SUB SECTION-->
<a name="events"></a>
<h3>Logging Process Model Events</h3>

The process model can write events to the Windows event log when
process cycling occurs.  This is controlled by the <b>logLevel</b>
attribute in the <b>&lt;processModel&gt;</b> configuration section.

<br /><br />

<table class="table">
<tr>
<th width="20%">Setting</th><th width="100%">Description</th>
</tr>
<tr>
  <td>
    <b>logLevel</b>
  </td>
  <td>
Controls that process cycling events are logged to the event log.
The value can be:
<ul>
<li><b>All</b>: All
process cycling events are logged.</li>
<li><b>None</b>: No events are logged.</li>
<li><b>Errors</b>: Only unexpected
events are logged.</li>
</ul>
  </td>
</tr>
</table>

<br />

When a cycling event occurs, if logging is enabled for that event,
the following events are written to the application event log.

<br /><br />

<table class="table">
<tr>
<th width="200"><nobr>Shutdown Reason</nobr></th><th><nobr>Event Log Type</nobr></th><th width="*">Description</th>
</tr>
<tr>
  <td>
    <b>Unexpected</b>
  </td>
  <td>
    Error
  </td>
  <td>
The ASP.NET worker process has shut down unexpectedly.
  </td>
</tr>
<tr>
  <td>
    <b>RequestQueueLimit</b>
  </td>
  <td>
    Error
  </td>
  <td>
The ASP.NET worker process has been restarted because the request queue limit was exceeded.
  </td>
</tr>
<tr>
  <td>
    <b>RequestLimit</b>
  </td>
  <td>
    Information
  </td>
  <td>
The ASP.NET worker process has been  restarted because the request limit was exceeded.
  </td>
</tr>
<tr>
  <td>
    <b>Timeout</b>
  </td>
  <td>
    Information
  </td>
  <td>
The ASP.NET worker process has been restarted because the time-out interval was met.
  </td>
</tr>
<tr>
  <td>
    <b>IdleTimeout</b>
  </td>
  <td>
    Information
  </td>
  <td>
The ASP.NET worker process has been shut down because the idle time-out interval was met.
  </td>
</tr>
<tr>
  <td>
    <b>MemoryLimitExceeded</b>
  </td>
  <td>
    Error
  </td>
  <td>
The ASP.NET worker process was restarted because the process memory limit was exceeded.
  </td>
</tr>
</table>

</asp:Content>

