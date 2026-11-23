<%@ Page Language="C#" MasterPageFile="~/webservices/webservices.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2><b>Choose Protocol</b></h2>
<br /><br />
ASP.NET Web Services now supports both the SOAP 1.1 and SOAP 1.2 protocols.  By default, 
each protocol will have a binding in the wsdl produced for your service.  To turn on or off SOAP 1.1
and SOAP 1.2, modify your config settings in either machine.config or web.config.  Un-commenting
the lines in the example below will turn off support for SOAP 1.1 or SOAP 1.2, respectively. 

<br /><br />

<div class="code"><pre>
    &lt;system.web>
		&lt;webServices>
			&lt;protocols>
				&lt;!-- &lt;remove name="HttpSoap"/> -->
				&lt;!-- &lt;remove name="HttpSoap1.2"/> -->
			&lt;/protocols>
		&lt;/webServices>
    &lt;/system.web>
</pre></div>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../samples/ChooseProtocol/cs/Client/ChooseProtocolClient.aspx"
        ViewSource="~/webservices/samples/ChooseProtocol/ChooseProtocol.src"
        Icon = "../../images/genicon.gif"
        Caption="C# Sample Caption"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../samples/ChooseProtocol/vb/Client/ChooseProtocolClient.aspx"
        ViewSource="~/webservices/samples/ChooseProtocol/ChooseProtocol.src"
        Icon = "../../images/genicon.gif"
        Caption="VB Sample Caption"
        runat="server" />
  </VbTemplate>
  <VjsTemplate>
        <Acme:SourceRef
        RunSample="../samples/ChooseProtocol/jsl/Client/ChooseProtocolClient.aspx"
        ViewSource="~/webservices/samples/ChooseProtocol/ChooseProtocol.src"
        Icon = "../../images/genicon.gif"
        Caption="VJ# Sample Caption"
        runat="server" />
  </VjsTemplate>
</Acme:LangSwitch>

</asp:Content>

