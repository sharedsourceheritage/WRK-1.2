<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.WebParts.EditorZone" runat="server">
  EditorZone
</Acme:TypeRef>
</h2>

<p>
The EditorZone control is one of the fundamental controls in the Web Parts control set. A key feature of Web Parts is the ability of end users to modify (or personalize) Web pages according to their preferences, and save their personalized settings for future browser sessions. One aspect of modifying Web Parts pages includes editing; users can edit the appearance, layout, behavior, and other properties of the visible WebPart controls. Several controls in the Web Parts control set provide the editing features, including the EditorZone control.
</p>
<p>
An EditorZone control becomes visible when a Web Parts page enters edit mode, and it makes available various EditorPart controls that can be used to personalize WebPart controls.
</p>
A catalog can contain several types of CatalogPart controls. The following list summarizes the CatalogPart controls provided with the Web Parts control set
<ul>
<li><a href=appearanceeditorpart.aspx>AppearanceEditorPart</a></li>
<li><a href=behavioreditorpart.aspx>BehaviorEditorPart</a></li>
<li><a href=layouteditorpart.aspx>LayoutEditorPart</a></li>
<li><a href=propertygrideditorpart.aspx>PropertyGridEditorPart</a> </li>

</ul>
<br /><br />

<Acme:LangSwitch ID="LangSwitch1" runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/webparts/Reference_cs/EditorZone_AppearanceEditorPart.aspx"
        ViewSource="~/aspnet/samples/ctrlref/webparts/EditorZone_AppearanceEditorPart.src"
        Caption="C# DeclarativeCatalogPart Sample"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/webparts/Reference_vb/EditorZone_AppearanceEditorPart.aspx"
        ViewSource="~/aspnet/samples/ctrlref/webparts/EditorZone_AppearanceEditorPart.src"
        Caption="VB DeclarativeCatalogPart Sample"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
