<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>

<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>


<h2>Encoding</h2>

Like other components in the .NET Framework, ASP.NET processes strings internally as Unicode, more specifically as its 16-bit encoding form, UTF-16. Most Web protocols are byte-based, though, which is why requests from and responses to browsers are converted to the byte-based form of Unicode UTF-8 by default. This conversion is algorithmic and generally has no performance impact. Most current browsers support UTF-8 encoded pages. However, for older browsers or browsers on mobile devices, it might be necessary to convert the communication with the browser to one of the legacy codepage-based encodings. The following sample shows how to configure the Japanese encoding Shift-JIS in the <code>globalization</code> section of a <code>web.config</code> file.
<br /><br />

In this case the Web developer might also want to save their files in the codepage encoding. This can be declared using the <code>fileEncoding</code> attribute.
<br /><br />

<pre class="code">
&lt;configuration&gt;
  &lt;system.web&gt;
    &lt;globalization
       requestEncoding="shift-jis"
       responseEncoding="shift-jis"
       fileEncoding="shift-jis"
       ...
    /&gt;
  &lt;/system.web&gt;
&lt;/configuration&gt;
</pre>

Both <code>requestEncoding</code> and <code>responseEncoding</code> should typically be set to the same value. These configuration settings except for <code>fileEncoding</code> can also be set in the <code>@ Page</code> declaration. The reason is that the directive is in the page file and the file encoding has to be known when the page is first read. 
<br /><br />

If no <code>fileEncoding</code> declaration is available, the ASP.NET runtime determines the file encoding by detecting any Unicode signatures at the beginning of the file and is uses these to distinguish between UTF-8 and UTF-16 encoded pages. Unicode signatures are added by Visual Studio and Notepad automatically when saving a file as UTF-16. Notepad also adds a signature for UTF-8, or it can be specified in Visual Studio. If no signature is present the runtime will interpret the source file in the current system ANSI codepage of the system the page is run on. The recommendation is to always save files in Unicode with a signature.


</asp:Content>

