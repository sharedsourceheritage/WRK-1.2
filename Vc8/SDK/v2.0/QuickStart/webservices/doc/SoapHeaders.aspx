<%@ Page Language="C#" MasterPageFile="~/webservices/webservices.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2><b>SOAP Headers</b></h2>
<p>
This sample demonstrates the use of ASP.NET Web Services's support for SOAP headers.
The sample employs an authorization header sent with the request that has username/password information.
The first call to the WebMethod does not include the SOAP header and thus fails.  The second
call to the WebMethod includes the SOAP header and thus returns successfully.
<br /><br />
<font color='red'>WARNING:</font> This sample is for demonstration purposes only.  Username/password information is sent in plain text,
which should never be done in a real application. It is not secure without modification.   
</p>
<p><Acme:TabControl runat="server">

<Tab Name="C#">
// On the server, create the AuthHeader class which extends from SoapHeader
public class AuthHeader : SoapHeader {
    public string Username;
    public string Password;
}
   
// On the client, create a new instance of the AuthHeader class
AuthHeader myHeader = new AuthHeader();

//WARNING: This sample is for demonstration purposes only.  Username/password information is sent in plain text,
//which should never be done in a real application. It is not secure without modification.  
myHeader.Username = "JaneDoe";
myHeader.Password = "password";

// Set the AuthHeader public member of the Web service instance to myHeader
service.AuthHeaderValue = myHeader;
    
// Call the Web service, which automatically sends the header with the request
string answer = service.HelloWorld();
</Tab>

<Tab Name="VB">
' On the server, create the AuthHeader class which extends from SoapHeader	
Public Class AuthHeader : Inherits SoapHeader
    Public Username As String
    Public Password As String
End Class
    
'On the client, create a new instance of the AuthHeader class
Dim myHeader As New AuthHeader

'WARNING: This sample is for demonstration purposes only.  Username/password information is sent in plain text,
'which should never be done in a real application. It is not secure without modification.  
myHeader.Username = "JaneDoe"
myHeader.Password = "password"

' Set the AuthHeader public member of the Web service instance to myHeader
service.AuthHeaderValue = myHeader
	
' Call the Web service, which automatically sends the header with the request
Dim answer As String = service.HelloWorld()
</Tab>

<Tab Name="VJ#">
// On the server, create the AuthHeader class which extends from SoapHeader
public class AuthHeader extends SoapHeader 
{
    public String Username;
    public String Password;
}
   
// On the client, create a new instance of the AuthHeader class
AuthHeader myHeader = new AuthHeader();

//WARNING: This sample is for demonstration purposes only.  Username/password information is sent in plain text,
//which should never be done in a real application. It is not secure without modification.  
myHeader.set_Username("JaneDoe");
myHeader.set_Password("password");

// Set the AuthHeader public member of the Web service instance to myHeader
service.set_AuthHeaderValue(myHeader);
    
// Call the Web service, which automatically sends the header with the request
String answer = service.HelloWorld();
</Tab>

</Acme:TabControl>
</p>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../Samples/SoapHeaders/cs/Client/SoapHeadersClient.aspx"
        ViewSource="~/webservices/Samples/SoapHeaders/SoapHeaders.src"
        Icon = "../../images/genicon.gif"
        Caption="Run C# Sample"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../Samples/SoapHeaders/vb/Client/SoapHeadersClient.aspx"
        ViewSource="~/webservices/Samples/SoapHeaders/SoapHeaders.src"
        Icon = "../../images/genicon.gif"
        Caption="Run VB Sample"
        runat="server" />
  </VbTemplate>
  <VjsTemplate>
        <Acme:SourceRef
        RunSample="../Samples/SoapHeaders/jsl/Client/SoapHeadersClient.aspx"
        ViewSource="~/webservices/Samples/SoapHeaders/SoapHeaders.src"
        Icon = "../../images/genicon.gif"
        Caption="Run VJ# Sample"
        runat="server" />
  </VjsTemplate>
</Acme:LangSwitch>

</asp:Content>

