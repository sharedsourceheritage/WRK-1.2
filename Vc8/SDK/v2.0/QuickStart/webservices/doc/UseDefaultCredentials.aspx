<%@ Page Language="C#" MasterPageFile="~/webservices/webservices.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2><b>Simple Web Service That Demonstrates the UseDefaultCredentials Feature</b></h2>
<p>When the UseDefaultCredentials property on an instance of a client proxy class is set to true 
the client will use the default credentials to authenticate to the Web service.  For example:
</p>
<p>
<Acme:TabControl runat="server">

<Tab Name="C#">
UseDefaultCredentialsService service = new UseDefaultCredentialsService();
service.UseDefaultCredentials = true;
</Tab>

<Tab Name="VB">
Dim service As New UseDefaultCredentialsService()
service.UseDefaultCredentials = True
</Tab>

<Tab Name="VJ#">
UseDefaultCredentialsService service = new UseDefaultCredentialsService();
service.set_UseDefaultCredentials(true);
</Tab>

</Acme:TabControl>

<p>Setting the UseDefaultCredentials property to true is equivalent to the following lines of code:</p>

<p>
<Acme:TabControl runat="server">

<Tab Name="C#">
service.Credentials = System.Net.CredentialCache.DefaultCredentials;
</Tab>

<Tab Name="VB">
service.Credentials = System.Net.CredentialCache.DefaultCredentials
</Tab>

<Tab Name="VJ#">
service.set_Credentials(System.Net.CredentialCache.get_DefaultCredentials());
</Tab>

</Acme:TabControl>
</p>
<p>NOTE: The Web service in this sample must be configured to support integrated Windows authentication
to properly demonstrate passing default credentials.</p> 
</font>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../samples/UseDefaultCredentials/cs/Client/UseDefaultCredentialsClient.aspx"
        ViewSource="~/webservices/samples/UseDefaultCredentials/UseDefaultCredentials.src"
        Icon = "~/images/genicon.gif"
        Caption="Run C# Sample"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../samples/UseDefaultCredentials/vb/Client/UseDefaultCredentialsClient.aspx"
        ViewSource="~/webservices/samples/UseDefaultCredentials/UseDefaultCredentials.src"
        Icon = "~/images/genicon.gif"
        Caption="Run VB Sample"
        runat="server" />
  </VbTemplate>
  <VjsTemplate>
	<Acme:SourceRef
	RunSample="../samples/UseDefaultCredentials/jsl/Client/UseDefaultCredentialsClient.aspx"
	ViewSource="~/webservices/samples/UseDefaultCredentials/UseDefaultCredentials.src"
	Icon="~/images/genicon.gif"
	Caption="Run VJ# Sample"
	runat="server" />
  </VjsTemplate>
</Acme:LangSwitch>

</asp:Content>

