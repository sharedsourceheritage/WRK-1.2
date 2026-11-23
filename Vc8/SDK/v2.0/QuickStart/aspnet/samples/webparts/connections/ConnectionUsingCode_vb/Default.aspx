<%@ Page Language="VB" %>
<%@ Register Src="WebPartPageMenu.ascx" TagName="WebPartPageMenu" TagPrefix="uc2" %>
<%@ Register TagPrefix="sample" Namespace="Microsoft.Sample.WebParts" %>
<%@ Register TagPrefix="uc1" TagName="TextInputControl" Src="TextInputControl.ascx" %>
<script runat="server">

    Protected Sub connectWebParts_Click(ByVal sender As Object, ByVal e As System.EventArgs)
        Dim wpmgr As WebPartManager
        wpmgr = WebPartManager.GetCurrentWebPartManager(Me.Page)
        Dim genericWebPart As GenericWebPart
        genericWebPart = wpmgr.GetGenericWebPart(Me.TextInputControl1)

        Dim canBeConnected As Boolean = wpmgr.CanConnectWebParts(genericWebPart, wpmgr.GetProviderConnectionPoints(genericWebPart).Default, Me.textdisplaywebpart1, wpmgr.GetConsumerConnectionPoints(Me.textdisplaywebpart1).Default)
        If Not canBeConnected Then
            Throw New Exception("Can not connect the two web part")
        End If
        Dim newConnection As WebPartConnection = wpmgr.ConnectWebParts(genericWebPart, wpmgr.GetProviderConnectionPoints(genericWebPart).Default, Me.textdisplaywebpart1, wpmgr.GetConsumerConnectionPoints(Me.textdisplaywebpart1).Default)
        
    End Sub

    Protected Sub disconnectWebParts_Click(ByVal sender As Object, ByVal e As System.EventArgs)
        Dim wpmgr As WebPartManager
        wpmgr = WebPartManager.GetCurrentWebPartManager(Page)
        Dim genericWebPart As GenericWebPart
        genericWebPart = wpmgr.GetGenericWebPart(Me.TextInputControl1)

        Dim coll As WebPartConnectionCollection = wpmgr.Connections
        Dim connection As WebPartConnection
        For Each connection In coll
            If connection.Provider Is genericWebPart AndAlso connection.Consumer Is Me.textdisplaywebpart1 Then
                wpmgr.DisconnectWebParts(connection)
                Exit For
            End If
        Next connection
    End Sub
    
    
    Protected Sub Page_PreRender(ByVal sender As Object, ByVal e As System.EventArgs)
        Dim wpmgr As WebPartManager
        wpmgr = WebPartManager.GetCurrentWebPartManager(Page)
        Dim genericWebPart As GenericWebPart
        genericWebPart = wpmgr.GetGenericWebPart(Me.TextInputControl1)

        Me.disconnectWebParts.Visible = False
        Me.connectWebParts.Visible = True

        Dim coll As WebPartConnectionCollection = wpmgr.Connections
        Dim connection As WebPartConnection
        For Each connection In coll
            If connection.Provider Is genericWebPart AndAlso connection.Consumer Is Me.textdisplaywebpart1 Then
                Me.disconnectWebParts.Visible = True
                Me.connectWebParts.Visible = False
                Exit For
            End If
        Next connection
    End Sub
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
  
        
          <uc2:webpartpagemenu id="WebPartPageMenu1" runat="server"></uc2:webpartpagemenu>
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

            </td>
          </tr>
        </table><asp:Button ID="connectWebParts" Runat="server" OnClick="connectWebParts_Click" Text="Connect Web Parts" />
            <br />
          <asp:Button ID="disconnectWebParts" OnClick="disconnectWebParts_Click" runat="server"
              Text="Diconnect Web Parts"  />&nbsp;<br />
          &nbsp;</div>
    </form>
  </body>
</html>
