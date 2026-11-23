<%@ Page Language="C#" MasterPageFile="~/webservices/webservices.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2><b>New Event-Based Model For Asynchronous WebMethod Calls</b></h2>
<br /><br />
ASP.NET Web Services supports a new model for asynchronous WebMethod calls.  Use the
event-based model to asynchronously call your Web services.  This sample shows how
to define your callback function and add it to your proxy class' event handler.  When
the method call returns, your callback function will be called.  

<br /><br /><Acme:TabControl runat="server">

<Tab Name="C#">
	//First implement the HelloWorldCompleted method using the following signature:
	//public void HelloWorldCompleted(object sender, HelloWorldCompletedEventArgs args)
	
	//Create the Web service
	HelloWorldWaitService service = new HelloWorldWaitService();
	//Add our callback function to the event handler
	service.HelloWorldCompleted += this.HelloWorldCompleted;
	//Call the Web service asynchronously
	service.HelloWorldAsync("first call");
	//when the Web service call returns the HelloWorldCompleted method will be called
</Tab>

<Tab Name="VB">
	'First implement the HelloWorldCompleted method using the following signature:
	'public void HelloWorldCompleted(object sender, HelloWorldCompletedEventArgs args)
	
	'Create the Web service
	Dim service As New HelloWorldWaitService()
	'Add our callback function to the event handler
	AddHandler service.HelloWorldCompleted, AddressOf HelloWorldCompleted
	'Call the Web service asynchronously
	service.HelloWorldAsync("first call")
	'when the Web service call returns the HelloWorldCompleted method will be called
</Tab>

</Acme:TabControl><br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../Samples/RADAsync/cs/Client/RadAsyncClient.aspx"
        ViewSource="~/webservices/Samples/RADAsync/RADAsync.src"
        Icon = "../../images/genicon.gif"
        Caption="C# Sample Caption"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../Samples/RADAsync/vb/Client/RadAsyncClient.aspx"
        ViewSource="~/webservices/Samples/RADAsync/RADAsync.src"
        Icon = "../../images/genicon.gif"
        Caption="VB Sample Caption"
        runat="server" />
  </VbTemplate>
  <VjsTemplate>
	<Acme:SourceRef
	RunSample=""
	ViewSource=""
	Icon=""
	Caption=""
	runat="server" />
  </VjsTemplate>
</Acme:LangSwitch>

</asp:Content>

