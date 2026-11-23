<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>


<h2>Editing Web Part Properties</h2>

key feature of Web Parts is the ability of end users to modify (or personalize) Web pages according to their preferences, and save their personalized settings for future browser sessions. One aspect of modifying Web Parts pages includes editing; users can edit the appearance, layout, behavior, and other properties of the visible WebPart controls.
<br />
<br />
This example show how to edit web part properties
<ol>
<li>Log in to the page.</li>
<li>Select "Edit" from the dropdown.</li>
<li>Click the dropdown arrow on the Calendar's Verb Menu, and select "Edit" from the menu. The editor will now be visible, with a property grid showing the Text property.</li>
<li>Change the title property and click on. the new title should be set in the calendar control</li>

</ol>


<Acme:LangSwitch ID="LangSwitch1" runat=server>
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/intro/intro_cs/WebPartEditor.aspx"
        ViewSource="~/aspnet/samples/webparts/intro/WebPartEditor.src"
        Caption="C# Editing Web Part Properties"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/intro/intro_vb/WebPartEditor.aspx"
        ViewSource="~/aspnet/samples/webparts/intro/WebPartEditor.src"
        Caption="VB Editing Web Part Properties"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />
Developer can take advantage of the Multiview control to have a full page editing.
<br />
<br />
This example show how to implement a full page editing scenario using multiview
<ol>
<li>Log in to the page.</li>
<li>Select "Edit" from the dropdown.</li>
<li>Click the dropdown arrow on the Calendar's Verb Menu, and select "Edit" from the menu. The editor will now be visible, with a property grid showing the Text property.</li>
<li>Change the title property and click on. the new title should be set in the calendar control</li>

</ol>
<Acme:LangSwitch ID="LangSwitch5" runat=server>
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/controls/FullPageEditing_cs"
        ViewSource="~/aspnet/samples/webparts/controls/FullPageEditing.src"
        Caption="C# Full page editing"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/controls/FullPageEditing_vb"
        ViewSource="~/aspnet/samples/webparts/controls/FullPageEditing.src"
        Caption="VB Full page editing"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />
A web part can also specify properties that can be edited by the user.
To provide editable properties, you can mark the property declaration with the 
<b>WebBrowsable</b> attribute. The page's EditorZone must also include an editor part capable
of editing custom properties. You can use the PropertyGridEditorPart to provide editing for 
custom properties in a property grid.
<br /><br />
This example makes the Text property of the web part editable, and uses a PropertyGridEditorPart 
to allow users to edit it.
<ol>
<li>Log in to the page.</li>
<li>Select "Edit" from the dropdown.</li>
<li>Click the dropdown arrow on the Text Display Web Part's Verb Menu, and select "Edit" from the menu. The editor will now be visible, with a property grid showing the Text property.</li>
</ol>

<Acme:LangSwitch ID="LangSwitch2" runat=server>
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/controls/propertyedit_cs"
        ViewSource="~/aspnet/samples/webparts/controls/PropertyEdit.src"
        Caption="C# Marking Web Properties as WebBrowsable"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/controls/propertyedit_vb"
        ViewSource="~/aspnet/samples/webparts/controls/PropertyEdit.src"
        Caption="VB Marking Web Properties as WebBrowsable"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />
Developers can specify a friendly name for properties marked as WebBrowsable by declaring the 
<b>WebDisplayName</b> attribute.
<br /><br />
This example marks the Text property as WebDisplayName to show a friendly name in the PropertyGridEditorPart.
<ol>
<li>Log in to the page.</li>
<li>Select "Edit" from the dropdown.</li>
<li>Click the dropdown arrow on the Text Display Web Part's Verb Menu, and select "Edit" from the menu. The editor will now be visible, with a property grid showing the Friendly name.</li>
</ol>



<Acme:LangSwitch ID="LangSwitch3" runat=server>
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/controls/propertyeditwithWebDisplayName_cs"
        ViewSource="~/aspnet/samples/webparts/controls/propertyeditwithWebDisplayName.src"
        Caption="C# Defining friendly name"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/controls/propertyeditwithWebDisplayName_vb"
        ViewSource="~/aspnet/samples/webparts/controls/propertyeditwithWebDisplayName.src"
        Caption="VB Defining friendly name"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />
Developers can also specify a tooltip for properties marked as WebBrowsable by declaring the 
<b>WebDescription</b> attribute.
<br /><br />
This example marks the Text property as WebDescription to show a tooltip in the PropertyGridEditorPart.
<ol>
<li>Log in to the page.</li>
<li>Select "Edit" from the dropdown.</li>
<li>Click the dropdown arrow on the Text Display Web Part's Verb Menu, and select "Edit" from the menu. The editor will now be visible, with a property grid showing the Friendly name.</li>
</ol>


<Acme:LangSwitch ID="LangSwitch4" runat=server>
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/controls/propertyeditwithWebDescription_cs"
        ViewSource="~/aspnet/samples/webparts/controls/propertyeditwithWebDescription.src"
        Caption="C# adding property Description"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/controls/propertyeditwithWebDescription_vb"
        ViewSource="~/aspnet/samples/webparts/controls/propertyeditwithWebDescription.src"
        Caption="VB adding property Description"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />
You can also provide your own custom editor parts for editing part properties. These parts
are displayed in the editor zone when the user edits the web part. 
<br /><br />
To create a custom editor part, inherit from the <b>EditorWebPart</b> control. The EditorWebPart
control is a composite control, so you can override the CreateChildControls method, and create controls 
for the part. You also need to override the ApplyChanges and SyncChanges methods to 
apply changes made in the editor part to the control.
<br /><br />
To provide custom editor parts, you can implement the <b>IWebEditable</b> interface
on the part, and implement the CreateEditorParts method and the WebBrowsableObject property.
The CreateEditorParts method should return a collection of editor parts.
<br /><br />
This example shows a custom editor part.
<ol>
<li>Log in to the page. </li>
<li>Select "Edit" from the dropdown. </li>
<li>Click the dropdown arrow on the Text Display Web Part's Verb Menu, and select "Edit" from the menu. The editor will now be visible, with the custom editor part </li>
</ol>


<Acme:LangSwitch ID="LangSwitch6" runat=server>
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/controls/customedit_cs"
        ViewSource="~/aspnet/samples/webparts/controls/CustomEdit.src"
        Caption="C# creating custom editor part"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/controls/customedit_vb"
        ViewSource="~/aspnet/samples/webparts/controls/CustomEdit.src"
        Caption="VB creating custom editor part"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />
</asp:Content>

