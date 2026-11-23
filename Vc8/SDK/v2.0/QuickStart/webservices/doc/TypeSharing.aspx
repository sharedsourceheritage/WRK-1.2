<%@ Page Language="C#" MasterPageFile="~/webservices/webservices.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2><b>Proxy Type Sharing</b></h2>
<p>
ASP.NET Web Services now supports proxy type sharing.  This feature allows you to share identical types 
from different Web services within the client-side proxy class.  For example, you can take
a type instance returned from one web service and pass it to another, and vice versa.  
</p>
<p>In this sample, a product invoice is returned from the Ordering Center.  The user then wishes to update the
ship date on the order.  To do so, the user passes the same ProductInvoice instance to the Shipping
Center, which updates the order and returns the modified product invoice.
</p>
<p>How do you identify identical types?
Identical types have the same type name and namespace, and also share the same schema type definition. 
</p>
<p>
In this sample we indicate that types should be shared by putting the wsdl and discomap from each service in the
'App_WebReferences' directory.
If you wish to use wsdl.exe instead to create your client proxy here is the command to share types between TypeSharingService1 and TypeSharingService2:
</p>
<div class="code"><pre>
&lt;!-- To share types, use the /sharetypes flag with wsdl.exe.  For example (all in one line): -->
     
wsdl.exe /sharetypes 
http://localhost/QuickstartV20/webservices/Samples/TypeSharing/cs/Server/TypeSharingService1.asmx
http://localhost/QuickstartV20/webservices/Samples/TypeSharing/cs/Server/TypeSharingService2.asmx
</pre></div>

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../Samples/TypeSharing/cs/Client/TypeSharingService.aspx"
        ViewSource="~/webservices/Samples/TypeSharing/TypeSharing.src"
        Icon = "../../images/genicon.gif"
        Caption="Run C# Sample"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../Samples/TypeSharing/vb/Client/TypeSharingService.aspx"
        ViewSource="~/webservices/Samples/TypeSharing/TypeSharing.src"
        Icon = "../../images/genicon.gif"
        Caption="Run VB Sample"
        runat="server" />
  </VbTemplate>
  <VjsTemplate>
        <Acme:SourceRef
        RunSample="../Samples/TypeSharing/jsl/Client/TypeSharingService.aspx"
        ViewSource="~/webservices/Samples/TypeSharing/TypeSharing.src"
        Icon = "../../images/genicon.gif"
        Caption="Run VJ# Sample"
        runat="server" />
  </VjsTemplate>
</Acme:LangSwitch>

</asp:Content>

