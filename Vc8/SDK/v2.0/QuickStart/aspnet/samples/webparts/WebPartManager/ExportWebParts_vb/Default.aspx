<%@ Page Language="VB" %>
<%@ Register Src="WebPartPageMenu.ascx" TagName="WebPartPageMenu" TagPrefix="uc2" %>
<%@ Register TagPrefix="sample" Namespace="Microsoft.Sample.WebParts" %>
<%@ Register TagPrefix="uc1" TagName="TextInputControl" Src="TextInputControl.ascx" %>
<script runat="server">

Protected Sub WebPartManager1_AuthorizeWebPart(ByVal sender As Object, ByVal e As System.Web.UI.WebControls.WebParts.WebPartAuthorizationEventArgs)
        If e.Type Is GetType(Calendar) Then
            e.IsAuthorized = False
        End If
End Sub
</script>
<html>
  <head runat="server">
    <title>Web Part Page</title>
  </head>
  <body>
    <form id="form1" runat="server">
      <div>
        <asp:WebPartManager ID="WebPartManager1" Runat="server" OnAuthorizeWebPart="WebPartManager1_AuthorizeWebPart"/>
          <uc2:WebPartPageMenu id="WebPartPageMenu1" runat="server">
          </uc2:WebPartPageMenu>
      </div>
      <div>
        <table style="width: 100%">
          <tr>
            <td style="width: 100px; height: 100px" valign="top" align="left">
              <asp:WebPartZone ID="WebPartZone1" Runat="server">
                <ZoneTemplate>
                  <sample:textdisplaywebpart runat="server" id="UserControl1" ExportMode=All />
                  <asp:Calendar Runat="server" ID="Calendar1"/>
                </ZoneTemplate>
              </asp:WebPartZone>
            </td>
            <td style="width: 100px; height: 100px" valign="top" align="left">
              <asp:WebPartZone ID="WebPartZone2" Runat="server">
                <ZoneTemplate>
                  <uc1:textinputcontrol runat="server" id="TextInputControl1" ExportMode=NonSensitiveData />
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
            </td>
          </tr>
        </table>
        <br />
        <asp:LoginStatus ID="LoginStatus1" Runat="server" />
      </div>
    </form>
  </body>
</html>
