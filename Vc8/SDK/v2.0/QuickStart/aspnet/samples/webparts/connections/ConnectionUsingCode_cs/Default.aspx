<%@ Page Language="C#" AutoEventWireup="true" %>
<%@ Register Src="WebPartPageMenu.ascx" TagName="WebPartPageMenu" TagPrefix="uc2" %>
<%@ Register TagPrefix="sample" Namespace="Microsoft.Sample.WebParts" %>
<%@ Register TagPrefix="uc1" TagName="TextInputControl" Src="TextInputControl.ascx" %>
<script runat="server">

    protected void connectWebParts_Click(object sender, EventArgs e)
    {
        WebPartManager wpmgr = WebPartManager.GetCurrentWebPartManager(Page);
        GenericWebPart genericWebPart = wpmgr.GetGenericWebPart(this.TextInputControl1);

        bool canBeConnected = wpmgr.CanConnectWebParts(genericWebPart,
                                    wpmgr.GetProviderConnectionPoints(genericWebPart).Default,
                                    this.textdisplaywebpart1,
                                    wpmgr.GetConsumerConnectionPoints(this.textdisplaywebpart1).Default);
                                    ;
        if (!canBeConnected)
            throw (new Exception("Can not connect the two web part"));

        WebPartConnection newConnection = wpmgr.ConnectWebParts(genericWebPart,
                                    wpmgr.GetProviderConnectionPoints(genericWebPart).Default,
                                    this.textdisplaywebpart1,
                                    wpmgr.GetConsumerConnectionPoints(this.textdisplaywebpart1).Default);
                                           
    }

    protected void disconnectWebParts_Click(object sender, EventArgs e)
    {
        WebPartManager wpmgr = WebPartManager.GetCurrentWebPartManager(Page);
        GenericWebPart genericWebPart = wpmgr.GetGenericWebPart(this.TextInputControl1);

        WebPartConnectionCollection coll = wpmgr.Connections;
        foreach (WebPartConnection connection in coll)
        {
            if (connection.Provider == genericWebPart && connection.Consumer == this.textdisplaywebpart1)
            {
                wpmgr.DisconnectWebParts(connection);
                break;
            }
        }
    }



    protected void Page_PreRender(object sender, EventArgs e)
    {
        WebPartManager wpmgr = WebPartManager.GetCurrentWebPartManager(Page);
        GenericWebPart genericWebPart = wpmgr.GetGenericWebPart(this.TextInputControl1);
        
        this.disconnectWebParts.Visible = false;
        this.connectWebParts.Visible = true;

        WebPartConnectionCollection coll = wpmgr.Connections;
        foreach (WebPartConnection connection in coll)
        {
            if (connection.Provider == genericWebPart && connection.Consumer == this.textdisplaywebpart1)
            {
                this.disconnectWebParts.Visible = true;
                this.connectWebParts.Visible = false;
                break;
            }
        }
    }

</script>
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
                  <sample:textdisplaywebpart runat="server" id="textdisplaywebpart1"/>
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
                </ZoneTemplate>
              </asp:CatalogZone>
              <asp:EditorZone ID="EditorZone1" Runat="server">
                <ZoneTemplate>
                  <asp:AppearanceEditorPart Runat="server" ID="AppearanceEditorPart1" />
                  <asp:BehaviorEditorPart Runat="server" ID="BehaviorEditorPart1" />
                  <asp:PropertyGridEditorPart Runat="server" ID="PropertyGridEditorPart1" />
                </ZoneTemplate>
              </asp:EditorZone>
                &nbsp;&nbsp; &nbsp;
            </td>
          </tr>
        </table>
      </div>
        <asp:Button ID="connectWebParts" OnClick="connectWebParts_Click" runat="server" Text="Connect Web Parts" />
        <br />
        <asp:Button ID="disconnectWebParts" runat="server" Text="Diconnect Web Parts" OnClick="disconnectWebParts_Click" />
    </form>
  </body>
</html>
