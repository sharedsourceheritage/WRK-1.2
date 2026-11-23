<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4>How Do I...Make a GET request with SSL?</h4>

<div class="indent" style="width:660">
<P>
This sample illustrates how to use the <b>WebRequest</b> and <b>WebResponse</b> classes to make a GET request on a URI with SSL.
</P>
<P>
There is no actual code difference between this example and the clientGET example. Basically, you can enter a URL with a http<B>s</B>:// instead of http:// and the <b>WebRequest</b> will work exactly the same.
</P>
<P>
The function <b>GetPage</b> is where the specific details of making the request can be found. The rest of the code in this sample is for taking command-line parameters as well as displaying help usage for the parameters. This sample program is a command-line utility that runs at the command prompt.
</P>
<P>
The <B>GetPage</B> function takes a string parameter, which is the URL (or URI) of the web page to request. This URI is then included as a parameter in a call to <B>WebRequest.Create</B> which creates a <B>WebRequest</B> object.
</P>
<P>
The <B>GetResponse</B> function of the <b>WebRequest</b> object is then used to get a <B>WebResponse</B> object. This object can be used to get the status code of the response, as well as the actual response stream (a web page, for instance).
</p>
<P>
Writing out the stream can take several different forms. This example uses a <B>StreamReader</B> 
instance to read 256 characters into a character array. It then creates a <B>String</B> from the
character array and writes out the <B>String</B> using <B>Console.WriteLine</B>.
</P>
</div>

<h4>Example</h4>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/net/WebRequests/clientGETwithSSL.src"
        Icon="../../../images/console.gif"
        Caption="C# ClientGETwithSSL.exe"
	SamplePath="howto\samples\net\WebRequests\"
        CanBeHosted="false"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/net/WebRequests/clientGETwithSSL.src"
        Icon="../../../images/console.gif"
        Caption="VB ClientGETwithSSL.exe"
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

