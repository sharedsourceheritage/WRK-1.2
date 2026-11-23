<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.WebParts.PropertyGridEditorPart" runat="server">
  PropertyGridEditorPart
</Acme:TypeRef>
</h2>

<p>The PropertyGridEditorPart provides a generic user interface (UI) that enables users to edit custom properties on WebPart controls. In contrast, the other EditorPart controls, such as the AppearanceEditorPart and BehaviorEditorPart controls, edit only existing, UI-oriented properties from the WebPart class.
</p>

<p>The most common and convenient way to add a PropertyGridEditorPart control to a page is by declaring it in page persistence format inside an <a href=editorzone.aspx>EditorZone</a></p>
<p>
The PropertyGridEditorPart control is a tool part that becomes visible only when a Web Parts page is in edit mode, and when a specific WebPart control has been selected for editing.
</p>

<br /><br />

<Acme:LangSwitch ID="LangSwitch1" runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/webparts/Reference_cs/EditorZone_PropertyGridEditorPart.aspx"
        ViewSource="~/aspnet/samples/ctrlref/webparts/EditorZone_PropertyGridEditorPart.src"
        Caption="C# PropertyGridEditorPart Sample"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/webparts/Reference_vb/EditorZone_PropertyGridEditorPart.aspx"
        ViewSource="~/aspnet/samples/ctrlref/webparts/EditorZone_PropertyGridEditorPart.src"
        Caption="VB PropertyGridEditorPart Sample"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>


</asp:Content>
