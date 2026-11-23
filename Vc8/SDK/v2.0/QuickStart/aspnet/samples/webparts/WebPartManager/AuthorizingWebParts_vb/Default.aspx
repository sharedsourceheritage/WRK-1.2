<%@ Page Language="VB" %>

<%@ Register Src="WebPartPageMenu.ascx" TagName="WebPartPageMenu" TagPrefix="uc2" %>
<%@ Register TagPrefix="sample" Namespace="Microsoft.Sample.WebParts" %>
<%@ Register TagPrefix="uc1" TagName="TextInputControl" Src="TextInputControl.ascx" %>

<script runat="server">

    Protected Sub WebPartManager1_AuthorizeWebPart(ByVal sender As Object, ByVal e As System.Web.UI.WebControls.WebParts.WebPartAuthorizationEventArgs)
        Dim calendarType As Type
        calendarType = GetType(Calendar)
        If e.Type.IsAssignableFrom(calendarType) Then
            e.IsAuthorized = True
        Else
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
      <asp:WebPartManager ID="WebPartManager1" runat="server" OnAuthorizeWebPart="WebPartManager1_AuthorizeWebPart" />
      <uc2:WebPartPageMenu id="WebPartPageMenu1" runat="server">
      </uc2:WebPartPageMenu>
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
                <asp:DeclarativeCatalogPart ID="DeclarativeCatalogPart1" runat="server">
                  <WebPartsTemplate>
                    <uc1:TextInputControl ID="TextInputControl2" runat="server" />
                    <asp:Calendar ID="Calendar2" runat="server"></asp:Calendar>
                  </WebPartsTemplate>
                </asp:DeclarativeCatalogPart>
              </ZoneTemplate>
            </asp:CatalogZone>
            &nbsp;
          </td>
        </tr>
      </table>
      <br />
      <asp:LoginStatus ID="LoginStatus1" runat="server" />
    </div>
  </form>
</body>
</html>
