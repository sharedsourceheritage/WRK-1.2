<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.WebParts.WebPartZone" runat="server">
  WebPartZone
</Acme:TypeRef>
</h2>
<p>
The <b>WebPartZone</b> control serves as the primary control in the Web Parts control set for hosting ASP.NET server side controls on a Web page.
</p>
In addition to web parts that inherit from the <b>WebPart</b> class, a WebPartZone control can host controls that do not derive from the WebPart class, by wrapping them with a GenericWebPart control at run time. 
Consequently, virtually any ASP.NET server control or user control can function as a web part when used inside a WebPartZone control.
<p>
The following example shows how to use a WebPartZone control in an ASP.NET page, and how
to place web parts inside it.
</p>
<br /><br />

<Acme:LangSwitch ID="LangSwitch1" runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/webparts/Reference_cs/WebPartZone_Simple.aspx"
        ViewSource="~/aspnet/samples/ctrlref/webparts/WebPartZone_Simple.src"
        Caption="C# WebPartManager1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/webparts/Reference_vb/WebPartZone_Simple.aspx"
        ViewSource="~/aspnet/samples/ctrlref/webparts/WebPartZone_Simple.src"
        Caption="VB WebPartManager1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
