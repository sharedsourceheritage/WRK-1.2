<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4>How Do I...Handle WebException?</h4>

<div class="indent" style="width:660">
This sample illustrates how to use the <b>WebException</b> and 
<b>UriFormatException</b> classes when dealing with exceptions 
when accessing URIs.
<BR>
<P>
This sample is like the simple clientGET sample.
The most important sections of code here (other than adding a try and 
catch to make sure we catch exceptions) are the catch sections.
</P>
<P>
In this catch section, the object that is caught is of type
<B>WebException</B> or <B>UriFormatException</B>. Both exception 
objects have an exception message that can be
written out with the <B>ToString()</B> method. In addition, 
you can examine the
error code of the <B>WebException</B> with the call to its 
<B>Status</B> property. If this status is 
<B>WebExceptionStatus.ProtocolError</B>,
then you can get the <b>WebResponse</b> and see its status code, 
which will map to an HTTP status code.
</p>

<p>
Run <b>ClientWebException.exe</b> and try these URLS:<br><br>
<code>htto://www.microsoft.com</code>
&nbsp;&nbsp;&nbsp;<i>(Bad URI, invalid protocol)</i><br>
<code>http://serverthatdoesntexist</code>
&nbsp;&nbsp;&nbsp;<i>(Name could not be resolved)</i><br>
<code>http://authserver/somauthtype</code>
&nbsp;&nbsp;&nbsp;<i>(server that requires authentication)</i><br>
<code>file://c:\</code>
&nbsp;&nbsp;&nbsp;<i>(Access is denied)</i><br>
</p>

</div>

<h4>Example</h4>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/net/WebRequests/clientwebexception.src"
        Icon="../../../images/console.gif"
        Caption="C# ClientWebException.exe"
	SamplePath="howto\samples\net\WebRequests\"
        CanBeHosted="false"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/net/WebRequests/clientwebexception.src"
        Icon="../../../images/console.gif"
        Caption="VB ClientWebException.exe"
	SamplePath="howto\samples\net\WebRequests\"
        CanBeHosted="false"
        runat="server" />
  </VbTemplate>
 <VjsTemplate>
       <Acme:SourceRef
        RunSample=""
        ViewSource=""
        Icon = ""
        Caption=""
        CanBeHosted="false"
        runat="server" />
  </VjsTemplate>
  <CpTemplate>
       <Acme:SourceRef
        RunSample=""
        ViewSource=""
        Icon = ""
        Caption=""
        CanBeHosted="false"
        runat="server" />
  </CpTemplate>
</Acme:LangSwitch>
</asp:Content>

