<%@ Page Language="C#" %>

<%@ Register Src="WebPartPageMenu.ascx" TagName="WebPartPageMenu" TagPrefix="uc2" %>
<%@ Register TagPrefix="sample" Namespace="Microsoft.Sample.WebParts" %>
<%@ Register TagPrefix="uc1" TagName="TextInputControl" Src="TextInputControl.ascx" %>
<html>
<head runat="server">
  <title>Web Part Page</title>
</head>
<body>
  <form id="form1" runat="server">
    <div>
      <asp:WebPartManager ID="WebPartManager1" runat="server" />
      <uc2:WebPartPageMenu ID="WebPartPageMenu1" runat="server" />
    </div>
    <div>
      <table style="width: 100%">
        <tr>
          <td style="width: 100px; height: 100px" valign="top" align="left">
            <asp:WebPartZone ID="WebPartZone1" runat="server">
              <ZoneTemplate>
                <sample:textdisplaywebpart runat="server" id="UserControl1" />
                <asp:Calendar runat="server" ID="Calendar1" />
              </ZoneTemplate>
            </asp:WebPartZone>
          </td>
          <td style="width: 100px; height: 100px" valign="top" align="left">
            <asp:WebPartZone ID="WebPartZone2" runat="server">
              <ZoneTemplate>
                <uc1:textinputcontrol runat="server" id="TextInputControl1" />
              </ZoneTemplate>
            </asp:WebPartZone>
          </td>
          <td style="width: 100px; height: 100px" valign="top" align="left">
            <asp:CatalogZone ID="CatalogZone1" runat="server">
              <ZoneTemplate>
                <asp:PageCatalogPart runat="server" ID="PageCatalogPart1" />
              </ZoneTemplate>
            </asp:CatalogZone>
            <asp:EditorZone ID="EditorZone1" runat="server">
              <ZoneTemplate>
                <asp:AppearanceEditorPart runat="server" ID="AppearanceEditorPart1" />
                <asp:BehaviorEditorPart runat="server" ID="BehaviorEditorPart1" />
              </ZoneTemplate>
            </asp:EditorZone>
          </td>
        </tr>
      </table>
      <br />
      <asp:LoginStatus ID="LoginStatus1" runat="server" />
    </div>
  </form>
</body>
</html>
