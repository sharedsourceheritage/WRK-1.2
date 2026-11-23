<%@ Page Language="C#" MasterPageFile="~/webservices/webservices.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2><b>Return Various Data Types</b></h2>
<br /><br />
ASP.NET Web Services gives you a wide range of flexibility in how you structure the messages
passed to and from Web services. This sample shows examples of WebMethods that return the following data types:
<ul>
<li>Primitive (String)</li>
<li>Array of Primitives (Integers)</li>
<li>Enumeration (Enum)</li>
<li>Class/Struct</li>
<li>Array of Classes/Structs</li>
</ul>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../samples/DataTypes/cs/Client/DataTypesClient.aspx"
        ViewSource="~/webservices/samples/DataTypes/DataTypes.src"
        Icon = "../../images/genicon.gif"
        Caption="C# Sample Caption"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../samples/DataTypes/vb/Client/DataTypesClient.aspx"
        ViewSource="~/webservices/samples/DataTypes/DataTypes.src"
        Icon = "../../images/genicon.gif"
        Caption="VB Sample Caption"
        runat="server" />
  </VbTemplate>
  <VjsTemplate>
        <Acme:SourceRef
        RunSample="../samples/DataTypes/jsl/Client/DataTypesClient.aspx"
        ViewSource="~/webservices/samples/DataTypes/DataTypes.src"
        Icon = "../../images/genicon.gif"
        Caption="VJ# Sample Caption"
        runat="server" />
  </VjsTemplate>
</Acme:LangSwitch>

</asp:Content>

