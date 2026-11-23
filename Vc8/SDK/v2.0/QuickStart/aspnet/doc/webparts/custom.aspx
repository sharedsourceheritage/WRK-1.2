<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>


<h2>Creating Custom Web Parts</h2>

Since any ASP.NET server control can be used as a web part, you can write custom web parts using
ASP.NET user controls or custom server controls.
<br /><br />
This example shows a user control web part that accepts text input. The user control implements the <b>IWebPart</b>
interface to provide values for common display properties of the web part, such as its title and description.
<br /><br />
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/controls/usercontrol_cs/default.aspx"
        ViewSource="~/aspnet/samples/webparts/controls/usercontrol.src"
        Caption="C# User Control Web Part"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/controls/usercontrol_vb/default.aspx"
        ViewSource="~/aspnet/samples/webparts/controls/usercontrol.src"
        Caption="VB User Control Web Part"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />
You can also write web parts as custom server controls. Although you can inherit from any control,
ASP.NET provides the <b>WebPart</b> base control class, which makes it significantly easier to
customize the default behavior of the control.
<br /><br />
This example shows a WebPart control that displays some text. The control has a property called ControlText,
which specifies the text to display. It also overrides the AllowMinimize and AllowClose properties
to prevent the part from being minimized or closed by the user.
<br /><br />
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/controls/customcontrol_cs/default.aspx"
        ViewSource="~/aspnet/samples/webparts/controls/customcontrol.src"
        Caption="C# Custom Control Web Part"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/controls/customcontrol_vb/default.aspx"
        ViewSource="~/aspnet/samples/webparts/controls/customcontrol.src"
        Caption="VB Custom Control Web Part"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />
A web part can also provide custom verbs that allow users to take actions on it. 
The zone is responsible for showing verbs for a web part; in most cases, 
verbs are shown in the part's Verb Menu. In the earlier editing
example, the "Edit" dropdown item was a verb shown only in edit mode.
<br /><br />
To provide custom verbs for a control that inherits from WebPart, you can 
override the Verbs property, create a WebPartVerbCollection object with a collection
of WebPartVerb objects, and return it. This example shows how to combine the verbs
provided by the base class with a new verb called "Save". The verb will be shown on the
Verb Menu of the part.<br /><br />
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/controls/customverbs_cs/default.aspx"
        ViewSource="~/aspnet/samples/webparts/controls/customverbs.src"
        Caption="C# Adding Custom Verbs"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/controls/customverbs_vb/default.aspx"
        ViewSource="~/aspnet/samples/webparts/controls/customverbs.src"
        Caption="VB Adding Custom Verbs"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch><br />
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
<li>Click the dropdown arrow on the control's Verb Menu, and select "Edit" from the menu. The editor will now be visible, with a property grid showing the Text property.</li>
</ol>
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/controls/propertyedit_cs/default.aspx"
        ViewSource="~/aspnet/samples/webparts/controls/propertyedit.src"
        Caption="C# Editing Web Part Properties"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/controls/propertyedit_vb/default.aspx"
        ViewSource="~/aspnet/samples/webparts/controls/propertyedit.src"
        Caption="VB Editing Web Part Properties"
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
This example shows a custom editor part to edit a property of a web part.
<br /><br />
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/controls/customedit_cs/default.aspx"
        ViewSource="~/aspnet/samples/webparts/controls/customedit.src"
        Caption="C# Writing a Custom Editor Part"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/controls/customedit_vb/default.aspx"
        ViewSource="~/aspnet/samples/webparts/controls/customedit.src"
        Caption="VB Writing a Custom Editor Part"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>

