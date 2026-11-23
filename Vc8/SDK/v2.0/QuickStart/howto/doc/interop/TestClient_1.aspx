<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4>How Do I...Call COM Methods from .NET?</h4>

<p>This example demonstrates how to use COM object from a Visual Basic or C# application.</p>

<p>In order to use the types defined within a COM library from managed code, you must obtain 
an assembly containing definitions of the COM types. Refer to the 
<A href="Building_Samples_NET2COM.aspx">How Do I...Build a .NET Client That Uses a COM Server?</A> 
for specific details.</p>

<p>With Visual Basic or with C#, you can reference the assembly using compiler /r switch or
you can add reference to the project directly from Visual Studio development tool.</p>

<Acme:TabControl runat="server">
<Tab Name="C#">

namespace Microsoft.Samples.Interop.TestClient {
	public class Test {
		public static void Main(){
			<b>SHDocVw.InternetExplorer explorer;</b>
			SHDocVw.IWebBrowserApp webBrowser;			
			
			explorer = new SHDocVw.InternetExplorer();
			<b>webBrowser = (SHDocVw.IWebBrowserApp) explorer;</b>
			
			webBrowser.Visible = true;
			webBrowser.GoHome();
			...
		}
	}
}
</Tab>
<Tab Name="VB">

Namespace Microsoft.Samples.Interop.TestClient
	Public Class Test 	
		Public Shared Sub Main()
			<b>Dim explorer As SHDocVw.InternetExplorer</b>
			Dim webBrowser As SHDocVw.IWebBrowserApp
				
			explorer = New SHDocVw.InternetExplorer
			<b>webBrowser = explorer</b>
			
			webBrowser.Visible = True
			webBrowser.GoHome
			...
		End Sub
	End Class
End Namespace
</Tab>
<Tab Name="C++">

void main()
{
   <b>Interop::SHDocVw::InternetExplorer * explorer = new Interop::SHDocVw::InternetExplorerClass;</b>
   <b>Interop::SHDocVw::IWebBrowserApp * webBrowser = __try_cast<Interop::SHDocVw::IWebBrowserApp *>(explorer);</b>
            
   Interop::SHDocVw::DWebBrowserEvents2_TitleChangeEventHandler * dTitleChange
	   = new Interop::SHDocVw::DWebBrowserEvents2_TitleChangeEventHandler(0, &S::OnTitleChange);
   explorer->TitleChange += dTitleChange;    
                        
   webBrowser->Visible = true;
   webBrowser->GoHome();    
   
   ...
}
</Tab>
</Acme:TabControl>

<p>The following example uses the Internet Explorer object methods to display an Internet Explorer
window and to navigate to the home page. In order to do that, an assembly containing 
definitions of the Internet Explorer types is created from SHDocVw.dll and saved into Interop.SHDocVw.dll,
which then can be referenced from code.</p>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef 
        RunSample=""        
        ViewSource="~/howto/samples/Interop/TestClient_1/TestClient.src"
        Icon="../../../images/console.gif"
        Caption="TestClient.exe"
	SamplePath="howto\samples\Interop\TestClient_1\"
        CanBeHosted="false"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef 
        RunSample=""
        ViewSource="~/howto/samples/Interop/TestClient_1/TestClient.src"
        Icon="../../../images/console.gif"
	SamplePath="howto\samples\Interop\TestClient_1\"
        CanBeHosted="false"
        Caption="TestClient.exe"
        runat="server" />
  </VbTemplate>
  <CpTemplate>
        <Acme:SourceRef 
        RunSample=""
        ViewSource="~/howto/samples/Interop/TestClient_1/TestClient.src"
        Icon="../../../images/console.gif"
        Caption="TestClient.exe"
	SamplePath="howto\samples\Interop\TestClient_1\"
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

