<%@ Page Language="C#" MasterPageFile="~/webservices/webservices.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2><b>Simple Web Service That Demonstrates the EnableDecompression Feature</b></h2>
<br /><br /> When the EnableDecompression property on an instance of a client proxy class is set to true 
the client will support decompression.

<br /><br /><Acme:TabControl runat="server">

<Tab Name="C#">
EnableDecompressionService service = new EnableDecompressionService();
service.EnableDecompression = true;
</Tab>

<Tab Name="VB">
Dim service As New EnableDecompressionService()
service.EnableDecompression = true
</Tab>

<Tab Name="VJ#">
EnableDecompressionService service = new EnableDecompressionService();
service.set_EnableDecompression(true);
</Tab>

</Acme:TabControl>


<br /><br />This gives the ability to interoperate with services that support compression. 
<br /><br />To disable decompression, set EnableDecompression to false.  One likely scenario for this is when you want
to view SOAP traces of the responses being sent from the server in plain text.  Setting this property to false
lets the server know that decompression is not supported.
<br /><br />NOTE: The Web service in this sample does not support compression. 
</font>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../samples/EnableDecompression/cs/Client/EnableDecompressionClient.aspx"
        ViewSource="~/webservices/samples/EnableDecompression/EnableDecompression.src"
        Caption="Run C# Sample"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../samples/EnableDecompression/vb/Client/EnableDecompressionClient.aspx"
        ViewSource="~/webservices/samples/EnableDecompression/EnableDecompression.src"
        Caption="Run VB Sample"
        runat="server" />
  </VbTemplate>
  <VjsTemplate>
        <Acme:SourceRef
        RunSample="../samples/EnableDecompression/jsl/Client/EnableDecompressionClient.aspx"
        ViewSource="~/webservices/samples/EnableDecompression/EnableDecompression.src"
        Caption="Run VJ# Sample"
        runat="server" />
  </VjsTemplate>
</Acme:LangSwitch>

</asp:Content>

