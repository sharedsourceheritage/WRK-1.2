<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.WebParts.AppearanceEditorPart" runat="server">
  AppearanceEditorPart
</Acme:TypeRef>
</h2>

<p>
The AppearanceEditorPart class is an editor control that derives from the EditorPart class, and is used to edit properties that affect the appearance of an associated WebPart or GenericWebPart control. 
</p>
<p>The most common and convenient way to add a AppearanceEditorPart control to a page is by declaring it in page persistence format inside an <a href=editorzone.aspx>EditorZone</a></p>
<p>
The AppearanceEditorPart control is a tool part that becomes visible only when a Web Parts page is in edit mode, and when a specific WebPart control has been selected for editing.
</p>
<br /><br />

<Acme:LangSwitch ID="LangSwitch1" runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/webparts/Reference_cs/EditorZone_AppearanceEditorPart.aspx"
        ViewSource="~/aspnet/samples/ctrlref/webparts/EditorZone_AppearanceEditorPart.src"
        Caption="C# AppearanceEditorPart Sample"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/webparts/Reference_vb/EditorZone_AppearanceEditorPart.aspx"
        ViewSource="~/aspnet/samples/ctrlref/webparts/EditorZone_AppearanceEditorPart.src"
        Caption="VB AppearanceEditorPart Sample"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
