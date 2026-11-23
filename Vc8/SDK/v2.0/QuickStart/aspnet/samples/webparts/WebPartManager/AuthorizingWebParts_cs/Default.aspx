<%@ Page Language="C#" %>
<%@ Register Src="WebPartPageMenu.ascx" TagName="WebPartPageMenu" TagPrefix="uc2" %>
<%@ Register TagPrefix="sample" Namespace="Microsoft.Sample.WebParts" %>
<%@ Register TagPrefix="uc1" TagName="TextInputControl" Src="TextInputControl.ascx" %>
<script runat="server">

    protected void WebPartManager1_AuthorizeWebPart(object sender, WebPartAuthorizationEventArgs e)
    {
        Type calendarType = typeof(Calendar);
        if (e.Type.IsAssignableFrom(calendarType))
            e.IsAuthorized = true;
        else
            e.IsAuthorized = false;
    }
</script>
<html>
  <head runat="server">
    <title>Web Part Page</title>
  </head>
  <body>
    <form id="form1" runat="server">
      <div>
        <asp:WebPartManager ID="WebPartManager1" Runat="server" OnAuthorizeWebPart="WebPartManager1_AuthorizeWebPart"/>
          <uc2:webpartpagemenu id="WebPartPageMenu1" runat="server"></uc2:webpartpagemenu>

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
                </ZoneTemplate>
              </asp:WebPartZone>
            </td>
            <td style="width: 100px; height: 100px" valign="top" align="left">
              <asp:CatalogZone ID="CatalogZone1" Runat="server">
                <ZoneTemplate>
                  <asp:PageCatalogPart Runat="server" ID="PageCatalogPart1" />
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
        <asp:LoginStatus ID="LoginStatus1" Runat="server" />
      </div>
    </form>
  </body>
</html>
