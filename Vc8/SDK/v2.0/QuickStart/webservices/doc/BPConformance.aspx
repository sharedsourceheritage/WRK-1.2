<%@ Page Language="C#" MasterPageFile="~/webservices/webservices.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2>WS-I Basic Profile 1.1 Conformance</h2>
<br /><br />
ASP.NET Web Services now supports the <a href="http://www.ws-i.org/deliverables/workinggroup.aspx?wg=basicprofile" target="new">WS-I Basic Profile</a>.
<br /><br />
To build a WS-I Basic Profile conformant Web service, use the WebServiceBinding attribute on your Web service class. 
Setting WebServiceBinding.ConformanceClaims to WsiProfiles.BasicProfile1_1 makes the SOAP 1.1 port exposed by this service 
conform to the WS-I Basic Profile 1.1. (Note that SOAP 1.2 bindings are not Basic Profile 1.1 conformant by definition.)  
Setting WebServiceBinding.EmitConformanceClaims = true emits documentation elements
in the service's WSDL that indicate it is conformant to the WS-I Basic Profile 1.1. These claims are not required; you can 
turn off conformance claims (while retaining port conformance) by setting EmitConformanceClaims = false. 
<br /><br />
NOTE: By default, new Web services created by Visual Studio are BP-conformant with WebServiceBinding.EmitConformanceClaims set to true. 

<br /><br /><Acme:TabControl runat="server">

<Tab Name="C#">
[WebServiceBinding(ConformsTo=WsiProfiles.BasicProfile1_1, EmitConformanceClaims=true)]
[WebService(Namespace="Microsoft.Samples.XmlMessaging.WebServices")]
public class BPConformance_asmx 
{
   [WebMethod]
   public string HelloWorldBP() 
   {
      //implement method here
   }  
}
</Tab>

<Tab Name="VB">
&lt;WebServiceBinding(ConformsTo:=WsiProfiles.BasicProfile1_1, EmitConformanceClaims:=True)> _
&lt;WebService(Namespace:="Microsoft.Samples.XmlMessaging.WebServices")> _
Public Class BPConformance_asmx
      
   &lt;WebMethod> _
   Public Function HelloWorldBP() As String
      'implement method here
   End Function 'HelloWorld

End Class 'BPConformance_asmx
</Tab>

<Tab Name="VJ#">
/** @attribute WebServiceBinding(ConformsTo=WsiProfiles.BasicProfile1_1, EmitConformanceClaims=true) */
/** @attribute WebService(Namespace="Microsoft.Samples.XmlMessaging.WebServices") */
public class BPConformance_asmx 
{
    /** @attribute WebMethod() */
    public String HelloWorldBP() 
    {
        //implement method here
    }  
}
</Tab>

</Acme:TabControl><br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../samples/BPConformance/cs/Client/BPConformanceClient.aspx"
        ViewSource="~/webservices/samples/BPConformance/BPConformance.src"
        Icon = "../../images/genicon.gif"
        Caption="C# Sample Caption"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../samples/BPConformance/vb/Client/BPConformanceClient.aspx"
        ViewSource="~/webservices/samples/BPConformance/BPConformance.src"
        Icon = "../../images/genicon.gif"
        Caption="VB Sample Caption"
        runat="server" />
  </VbTemplate>
  <VjsTemplate>
        <Acme:SourceRef
        RunSample="../samples/BPConformance/jsl/Client/BPConformanceClient.aspx"
        ViewSource="~/webservices/samples/BPConformance/BPConformance.src"
        Icon = "../../images/genicon.gif"
        Caption="VJ# Sample Caption"
        runat="server" />
  </VjsTemplate>
</Acme:LangSwitch>

</asp:Content>

