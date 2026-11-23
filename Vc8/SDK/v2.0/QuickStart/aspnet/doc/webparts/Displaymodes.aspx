<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>


<h2>Adding a New Display Mode </h2>

A Web Parts page can enter several different display modes. In each display mode, certain elements of the Web Parts user interface (UI) are either hidden or displayed, and certain kinds of user modifications to a page are either enabled or disabled. The WebPartManager control contains the implementation for the display modes that are available in the Web Parts control set, and manages the display modes for a page.
The Web Part Control set provides 4 build in modes: Catalog, Connect, Design, Edit and Normal. Developers can add new display mode or disable the built in display modes.

This sample adds a new display mode call InlineDisplayMode. this mode allows Web Part a way to edit properties in line.
<ol>
<li>Log in to the page.</li>
<li>Click the dropdown arrow on the control's title bar, and select "Design" from the menu. Move Web Parts to different WebPartZones.</li>
<li>Close the browser, and run the sample again. You will see your personalized changes have been applied.</li>
</ol>

<Acme:LangSwitch ID="LangSwitch1" runat=server>
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/displaymodes/NewDisplayMode_cs"
        ViewSource="~/aspnet/samples/webparts/displaymodes/NewDisplayMode.src"
        Caption="C# Adding a new Display Mode"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/displaymodes/NewDisplayMode_vb"
        ViewSource="~/aspnet/samples/webparts/displaymodes/NewDisplayMode.src"
        Caption="VB Adding a new Display Mode"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />
</asp:Content>
