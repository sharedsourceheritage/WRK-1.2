<%@ Page Language="C#" MasterPageFile="~/webservices/webservices.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2><b>Simple Web Service That Performs Basic Arithmetic</b></h2>
<br /><br />
This web service has four WebMethods that perform the following operations:
<ul>
<li>Addition</li>
<li>Subtraction</li>
<li>Multiplication</li>
<li>Division</li>
</ul>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../samples/MathService/cs/Client/MathServiceClient.aspx"
        ViewSource="~/webservices/samples/MathService/MathService.src"
        Icon = "../../images/genicon.gif"
        Caption="Run C# Sample"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../samples/MathService/vb/Client/MathServiceClient.aspx"
        ViewSource="~/webservices/samples/MathService/MathService.src"
        Icon = "../../images/genicon.gif"
        Caption="Run VB Sample"
        runat="server" />
  </VbTemplate>
  <VjsTemplate>
        <Acme:SourceRef
        RunSample="../samples/MathService/jsl/Client/MathServiceClient.aspx"
        ViewSource="~/webservices/samples/MathService/MathService.src"
        Icon = "../../images/genicon.gif"
        Caption="Run VJ# Sample"
        runat="server" />
  </VjsTemplate>
</Acme:LangSwitch>

</asp:Content>

