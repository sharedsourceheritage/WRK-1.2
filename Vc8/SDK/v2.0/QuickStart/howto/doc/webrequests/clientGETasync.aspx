<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4>How Do I...Make a GET request asynchronously?</h4>

<div class="indent" style="width:660">
<P>
This sample illustrates how to use the <b>WebRequest</b> and <b>WebResponse</b> classes to make a GET request on
a URI asynchronously.
</P>
<P>
This sample is similar to the other <b>WebRequest</b> samples, with the difference found in the <I>Begin</I>
and <I>End</i> async-style function calls. Put simply, instead of calling <B>GetResponse</B>, a call
is made to the function <B>BeginGetResponse</B>, with the callback function and a state object specified as parameters.
</P>
<P>
This function <B>RespCallback</B>, takes an object of type <B>IASyncResult</B>. This object contains an
object <B>AsyncState</B> that is the same state object passed to the call to<B>BeginGetResponse</B>.  The state object
is casted to a custom type <B>RequestState</B> that can be used to get a handle to the original <B>HttpWebRequest</B>. 
Calling the original request's <B>EndGetResponse</B> method will return a WebResponse object (which is cast as an HttpWebResponse
in this case.)  Finally, the response is read asynchronously from the response by getting the value of the <B>ResponseStream</B>
property on the response object.
</P>
<P>
From here, this example is like the others. It pulls out the response from the stream and writes it
out to the console. 
</p>
</div>

<h4>Example</h4>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/net/WebRequests/clientGETasync.src"
        Icon="../../../images/console.gif"
        Caption="C# ClientGETasync.exe"
	SamplePath="howto\samples\net\WebRequests\"
        CanBeHosted="false"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/net/WebRequests/clientGETasync.src"
        Icon="../../../images/console.gif"
        Caption="VB ClientGETasync.exe"
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

