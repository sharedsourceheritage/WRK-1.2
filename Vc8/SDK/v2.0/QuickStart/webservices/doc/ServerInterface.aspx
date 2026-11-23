<%@ Page Language="C#" MasterPageFile="~/webservices/webservices.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2><b>Simple Web Service That Demonstrates the Server Interface Feature</b></h2>
<br /><br /> To use the ServerInterface feature, you have two options:
<ul>
<li>(1) Run wsdl.exe using the /serverInterface switch (or /si for short) with a wsdl file.  The output will 
be a code file that contains an interface for each wsdl binding.</li>
<li>(2) Write the interface(s) yourself and apply [WebServiceBindingAttribute] on the interface(s), 
and [WebMethodAttribute] on each Web method in the interface(s).  
</li>
</ul>
<br /><br />Here is an example of how to use option (1) from the command line:  
<pre>wsdl.exe /si ServerInterfaceSample.wsdl</pre>
<br /><br />The Web service in this sample was written using Option (2).  The interface looks like this:

<br /><br /><Acme:TabControl runat="server">

<Tab Name="C#">
[WebServiceBinding(Name="ReportDateTime", Namespace="Microsoft.Samples.XmlMessaging.WebServices")]
public interface IReportDateTime
{
	[WebMethod]
	DateTime getCurrentDateTime();
}
</Tab>

<Tab Name="VB">
&lt;WebServiceBinding(Name:="ReportDateTime", Namespace:="Microsoft.Samples.XmlMessaging.WebServices")&gt;  _
Public Interface IReportDateTime

	&lt;WebMethod()&gt;  _
	Function getCurrentDateTime() As DateTime

End Interface 'IReportDateTime
</Tab>

</Acme:TabControl>



<br /><br />The implementation looks like this:

<br /><br /><Acme:TabControl runat="server">

<Tab Name="C#">
[WebService(Namespace="Microsoft.Samples.XmlMessaging.WebServices")]
public class ServerInterfaceService : IReportDateTime
{
	public DateTime getCurrentDateTime()
	{
		//Web method implementation here
	}
}
</Tab>

<Tab Name="VB">
&lt;WebService(Namespace:="Microsoft.Samples.XmlMessaging.WebServices")&gt;  _
Public Class ServerInterfaceService
	Implements IReportDateTime

	Public Function getCurrentDateTime() As DateTime Implements IReportDateTime.getCurrentDateTime	
		'Web method implementation here
	End Function 'getCurrentDateTime

End Class 'ServerInterfaceService
</Tab>

</Acme:TabControl>

<br /><br />Regardless of which you option you use, you will need to implement the interface(s) in your service code.
The benefit of this feature is that implementation code is kept separate from the contract code (as defined by the interface).
If you change the wsdl and then regenerate your interface(s), you will not lose any of the implementation code.
To follow recommended design guidelines, you should not put any code in the implementation that changes the wsdl contract.
Likewise, you should not alter the interfaces with code that affects the run-time behavior. 
Contract and implementation details remain separate.
<br /><br />NOTE: This feature deprecates the use of /server with wsdl.exe.
</font>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../samples/ServerInterface/cs/Client/ServerInterfaceClient.aspx"
        ViewSource="~/webservices/samples/ServerInterface/ServerInterface.src"
        Icon = "../../images/genicon.gif"
        Caption="C# Sample Caption"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../samples/ServerInterface/vb/Client/ServerInterfaceClient.aspx"
        ViewSource="~/webservices/samples/ServerInterface/ServerInterface.src"
        Icon = "../../images/genicon.gif"
        Caption="VB Sample Caption"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>

