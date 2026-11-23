<%@ Page Language="C#" MasterPageFile="~/webservices/webservices.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2><b>ASP.NET Web Service That Throws a Soap Exception with Custom Information</b></h2>

<p>
The server can send custom fault information to the client using a SoapException.  When a SoapException
is thrown (and not caught) the server sends the error information on the wire in the form of a
SOAP fault.  The SOAP fault is deserialized back into a SoapException at the client.  
Custom (machine-readable) error information is sent in the Detail element of a SOAP fault.  
A SOAP fault also includes a human-readable error message, a fault code and optionally
a SOAP actor. 
</p>
<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
//assume that there was an error validating the SOAP Message
if(true)
{
    XmlDocument doc = new XmlDocument();
    //insert your own XML into the XmlDocument, 
    //this will go into the Detail element of the SOAP fault
    string errorMsg = "An error was received...";
    //the SOAP fault will contain a human-readable error message, 
    //the fault code, the SOAP actor, and the detail element    
    SoapException exc = new SoapException(errorMsg, SoapException.ClientFaultCode, "", detail);
    throw exc; 
}
</Tab>

<Tab Name="VB">
'assume that there was an error validating the SOAP Message
If True Then
    Dim doc As New XmlDocument()
    'insert your own XML into the XmlDocument, 
    'this will go into the Detail element of the SOAP fault
    Dim errorMsg As String = "An error was received..."
    'the SOAP fault will contain a human-readable error message, 
    'the fault code, the SOAP actor, and the detail element  
    Dim exc As New SoapException(errorMsg, SoapException.ClientFaultCode, "", detail)
    Throw exc
End If
</Tab>

<Tab Name="VJ#">
//assume that there was an error validating the SOAP Message
if(true)
{
    XmlDocument doc = new XmlDocument();
    //insert your own XML into the XmlDocument, 
    //this will go into the Detail element of the SOAP fault
    String errorMsg = "An error was received...";
    //the SOAP fault will contain a human-readable error message, 
    //the fault code, the SOAP actor, and the detail element    
    SoapException exc = new SoapException(errorMsg, SoapException.ClientFaultCode, "", detail);
    throw exc; 
}
</Tab>
</Acme:TabControl>
</p>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../samples/SoapException/cs/Client/SoapExceptionClient.aspx"
        ViewSource="~/webservices/samples/SoapException/SoapException.src"
        Icon = "../../images/genicon.gif"
        Caption="Run C# Sample"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../samples/SoapException/vb/Client/SoapExceptionClient.aspx"
        ViewSource="~/webservices/samples/SoapException/SoapException.src"
        Icon = "../../images/genicon.gif"
        Caption="Run VB Sample"
        runat="server" />
  </VbTemplate>
  <VjsTemplate>
        <Acme:SourceRef
        RunSample="../samples/SoapException/jsl/Client/SoapExceptionClient.aspx"
        ViewSource="~/webservices/samples/SoapException/SoapException.src"
        Icon = "../../images/genicon.gif"
        Caption="Run VJ# Sample"
        runat="server" />
  </VjsTemplate>
</Acme:LangSwitch>

</asp:Content>

