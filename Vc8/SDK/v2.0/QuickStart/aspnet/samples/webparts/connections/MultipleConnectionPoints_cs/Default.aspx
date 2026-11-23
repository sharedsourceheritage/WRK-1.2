<%@ Page Language="C#" %>
<%@ Register Src="WordCountControl.ascx" TagName="WordCountControl" TagPrefix="uc3" %>
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
        <asp:WebPartManager ID="WebPartManager1" Runat="server">
        </asp:WebPartManager>
          <uc2:webpartpagemenu id="WebPartPageMenu1" runat="server">
          
          </uc2:webpartpagemenu>
      </div>
      <div>
        <table style="width: 100%">
          <tr>
            <td style="width: 100px; height: 100px" valign="top" align="left">
              <asp:WebPartZone ID="WebPartZone1" Runat="server">
                <ZoneTemplate>
                  <sample:textdisplaywebpart runat="server" id="UserControl1"/>
                  <asp:Calendar Runat="server" ID="Calendar1"/>
                </ZoneTemplate>
              </asp:WebPartZone>
            </td>
            <td style="width: 100px; height: 100px" valign="top" align="left">
              <asp:WebPartZone ID="WebPartZone2" Runat="server">
                <ZoneTemplate>
                  <uc1:textinputcontrol runat="server" id="TextInputControl1" />
                    <uc3:wordcountcontrol id="WordCountControl1" runat="server"></uc3:wordcountcontrol>
                </ZoneTemplate>
              </asp:WebPartZone>
            </td>
            <td style="width: 100px; height: 100px" valign="top" align="left">
              <asp:CatalogZone ID="CatalogZone1" Runat="server">
                <ZoneTemplate>
                  <asp:PageCatalogPart Runat="server" ID="PageCatalogPart1" />
                </ZoneTemplate>
              </asp:CatalogZone>
              <asp:EditorZone ID="EditorZone1" Runat="server">
                <ZoneTemplate>
                  <asp:AppearanceEditorPart Runat="server" ID="AppearanceEditorPart1" />
                  <asp:BehaviorEditorPart Runat="server" ID="BehaviorEditorPart1" />
                  <asp:PropertyGridEditorPart Runat="server" ID="PropertyGridEditorPart1" />
                </ZoneTemplate>
              </asp:EditorZone>
                &nbsp;&nbsp;
                <asp:ConnectionsZone ID="ConnectionsZone1" runat="server">
                </asp:ConnectionsZone>
            </td>
          </tr>
        </table>
      </div>
    </form>
  </body>
</html>
