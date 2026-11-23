<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Personalization and Web Parts</h2>

The Web Part Control Set includes a page personalization system that can save
changes made by users until their next session. Personalized settings can include page layout,
visible or invisible parts, and part properties.
To mark a property as personalizable, you can mark the control property with the
<b>Personalizable</b> attribute. Typically, a property should have both the WebBrowsable
and Personalizable attributes, so it can be edited and saved.
<br /><br />
This example shows a page with a web part that has a personalizable property.
<ol>
<li>Log in to the page.</li>
<li>Select "Edit" from the dropdown.</li>
<li>Click on the down arrow to the right of the TextDisplayWebPart title and select "Edit".  The editor will now be visible, with a property grid showing the ContentText property.</li>
<li>Change the ContentText value, and click OK. </li>
<li>Close the browser, and then return to the page. The web part will continue to show the new text.</li>
</ol>
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/personalization/peruser_cs/default.aspx"
        ViewSource="~/aspnet/samples/webparts/personalization/peruser.src"
        Caption="C# Per-User Personalization"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/personalization/peruser_vb/default.aspx"
        ViewSource="~/aspnet/samples/webparts/personalization/peruser.src"
        Caption="VB Per-User Personalization"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />
The Web Part Control Set also provides a second level of personalization for pages, called
shared personalization. Using this mode, a user can create a customized view that is used
as the default for all users viewing a page. Shared personalization does not alter the contents
of the physical page; instead, it defines a set of customizations that are applied to the page before 
per-user personalization is applied.
<br /><br />
To specify that a setting be modifiable in shared personalization, you can add the 
Personalizable(PersonalizationScope.Shared) attribute to the property. In this example, the 
MaxTextDisplayLength property of the TextDisplayWebPart is marked as being personalizable in shared mode.
It also modifies the CreateEditorParts method to only return the custom editor part when in shared mode.
<br /><br />
<ol>
<li>Log in to the page.</li>
<li>Click on the Shared radio button.</li>
<li>Click on the down arrow to the right of the TextDisplayWebPart title and select "Edit". The Text Editor will now be visible. </li>
<li>Change the Text Length value, and click OK. </li>
<li>Close the browser, and then return to the page. The web part will continue to show the new text.</li>
</ol>
<br /><br />
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/personalization/shared_cs/default.aspx"
        ViewSource="~/aspnet/samples/webparts/personalization/shared.src"
        Caption="C# Shared Personalization"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/personalization/shared_vb/default.aspx"
        ViewSource="~/aspnet/samples/webparts/personalization/shared.src"
        Caption="VB Shared Personalization"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />
The personalized settings of a page are saved permanently, but it may be useful to reset these settings
back to their defaults. You can do this programmatically, using the <b>PersonalizationAdministration</b> class.
To reset the per-user personalization of a page, call PersonalizationAdministration.ResetUserState,
passing in the page path and the user name. To reset the shared personalization, call
PersonalizationAdministration.ResetSharedState, passing in the page path.
<br /><br />
<ol>
<li>Log in to the page.</li>
<li>Select "Design" from the dropdown.</li>
<li>Move Web Parts to different WebPartZones.</li>
<li>Click the "Reset User State". The personalized information will be reset.</li>
</ol>
<br /><br />
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/personalization/reset_cs/default.aspx"
        ViewSource="~/aspnet/samples/webparts/personalization/reset.src"
        Caption="C# Resetting Personalization"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/personalization/reset_vb/default.aspx"
        ViewSource="~/aspnet/samples/webparts/personalization/reset.src"
        Caption="VB Resetting Personalization"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>

