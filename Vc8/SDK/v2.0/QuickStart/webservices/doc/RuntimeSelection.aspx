<%@ Page Language="C#" MasterPageFile="~/webservices/webservices.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4><b>ASP.NET Web Service Client That Allows Runtime Selection of the Web Service</b></h4>

<p>
Rather than hardcoding the location of your web service or using the default location in the client proxy,
you can store the value in config.  This will allow your or an administrator to change the location in config
without changing code.
</p>
<p>
<div class="code">
<pre>
&lt;configuration>
   &lt;appSettings>
      &lt;add key="WSUrl" value="insert location here..." />
   &lt;/appSettings>
&lt;/configuration>
</pre>
</div>
</p>
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../samples/RuntimeSelection/cs/Client/ChooseProtocolClient.aspx"
        ViewSource="~/webservices/samples/RuntimeSelection/RuntimeSelection.src"
        Icon = "../../images/genicon.gif"
        Caption="Run C# Sample"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../samples/RuntimeSelection/vb/Client/ChooseProtocolClient.aspx"
        ViewSource="~/webservices/samples/RuntimeSelection/RuntimeSelection.src"
        Icon = "../../images/genicon.gif"
        Caption="Run VB Sample"
        runat="server" />
  </VbTemplate>
  <VjsTemplate>
        <Acme:SourceRef
        RunSample="../samples/RuntimeSelection/jsl/Client/ChooseProtocolClient.aspx"
        ViewSource="~/webservices/samples/RuntimeSelection/RuntimeSelection.src"
        Icon = "../../images/genicon.gif"
        Caption="Run VJ# Sample"
        runat="server" />
  </VjsTemplate>
</Acme:LangSwitch>

</asp:Content>

