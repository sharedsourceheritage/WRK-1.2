<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4>How Do I...Sink Unmanaged Events from .NET?</h4>

<p>This example demonstrates how to sink unmanaged events from .NET code.</p>

<p>In order to use the types defined within a COM library from managed code, you have to obtain 
an assembly containing definitions of the COM types. Refer to the 
<A href="Building_Samples_NET2COM.aspx">How Do I...Build a .NET Client That Uses a COM Server?</A> 
for specific details.</p>

<p>With Visual Basic or with C#, you can reference the assembly using compiler /r switch or
you can add reference to your project directly from the Visual Studio development tool.</p>

<p>Once you have a reference, you can create new instances of the event handlers and add them 
to existing event handlers in unmanaged code. For specific syntax see
examples below.</p>

<br>
<Acme:TabControl runat="server">
<Tab Name="C#">
public static void Main(){
	SHDocVw.InternetExplorer explorer;
	IWebBrowserApp webBrowser;			
	
	explorer = new SHDocVw.InternetExplorer();
	webBrowser = (IWebBrowserApp) explorer;
	
	//Title Change event
	<b>DWebBrowserEvents2_TitleChangeEventHandler dTitleChangeE
		= new DWebBrowserEvents2_TitleChangeEventHandler(OnTitleChange);
	explorer.TitleChange += dTitleChangeE;</b>	
				
	webBrowser.Visible = true;
	webBrowser.GoHome();	
	...		
}

<b>static void OnTitleChange(String text){
	Console.WriteLine("Title changes to {0}", text);
}</b>
</Tab>
<Tab Name="VB">
Public Shared Sub Main()
	Dim explorer As SHDocVw.InternetExplorer
	Dim webBrowser As IWebBrowserApp
		
	explorer = New SHDocVw.InternetExplorer
	webBrowser = explorer
	
	'Title Change event
	<b>AddHandler explorer.TitleChange, AddressOf OnTitleChange</b>		
	
	
	
	webBrowser.Visible = True
	webBrowser.GoHome
	...		
End Sub

<b>Public Shared Sub OnTitleChange(txt As String)
	Console.WriteLine("Title changes to {0}", txt)
End Sub</b>
</Tab>
<Tab Name="C++">
int main()
{
   Interop::SHDocVw::InternetExplorer * explorer = new Interop::SHDocVw::InternetExplorerClass;
   Interop::SHDocVw::IWebBrowserApp * webBrowser = __try_cast<Interop::SHDocVw::IWebBrowserApp *>(explorer);
            
   
   webBrowser->Visible = true;
   webBrowser->GoHome();    
   ...     
}






</Tab>
</Acme:TabControl>

<p>The following example uses the Internet Explorer object methods and events to open an Internet Explorer
window, catch all TitleChange events and show them in console window. To do this, an assembly containing 
definitions of the Internet Explorer types and events is created from SHDocVw.dll and saved into ExplorerLib.dll,
which then can be referenced from the code.</p>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef 
        RunSample=""        
        ViewSource="~/howto/samples/Interop/TestClient_2/TestClient.src"
        Icon="../../../images/console.gif"
        Caption="TestClient.exe"
	SamplePath="howto\samples\Interop\TestClient_2\"
        CanBeHosted="false"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef 
        RunSample=""
        ViewSource="~/howto/samples/Interop/TestClient_2/TestClient.src"
        Icon="../../../images/console.gif"
        Caption="TestClient.exe"
	SamplePath="howto\samples\Interop\TestClient_2\"
        CanBeHosted="false"
        runat="server" />
  </VbTemplate>
  <CpTemplate>
        <Acme:SourceRef 
        RunSample=""
        ViewSource="~/howto/samples/Interop/TestClient_2/TestClient.src"
        Icon="../../../images/console.gif"
        Caption="TestClient.exe"
	SamplePath="howto\samples\Interop\TestClient_2\"
        CanBeHosted="false"
        runat="server" />
  </CpTemplate>
 <VjsTemplate>
       <Acme:SourceRef
        RunSample=""
        ViewSource=""
        Icon = ""
        Caption=""
        CanBeHosted="false"
        runat="server" />
  </VjsTemplate>
</Acme:LangSwitch>
</asp:Content>

