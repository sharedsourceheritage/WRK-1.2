<%@ Page Language="VB" AutoEventWireup="true" %>
<%@ Register Src="WebPartPageMenu.ascx" TagName="WebPartPageMenu" TagPrefix="uc2" %>
<%@ Register TagPrefix="sample" Namespace="Microsoft.Sample.WebParts" %>
<%@ Register TagPrefix="uc1" TagName="TextInputControl" Src="TextInputControl.ascx" %>
<script runat=server>
Protected Sub Page_PreRender(ByVal sender As Object, ByVal e As EventArgs) 
        If WebPartManager1.DisplayMode Is WebPartManager.EditDisplayMode AndAlso Not (WebPartManager1.SelectedWebPart Is Nothing) Then
            MultiView1.ActiveViewIndex = 1
        Else
            MultiView1.ActiveViewIndex = 0
        End If

End Sub 'Page_PreRender

</script>

<html>
  <head runat="server">
    <title>Web Part Page</title>
  </head>
  <body>
    <form id="form1" runat="server">
      <div>
        <asp:WebPartManager ID="WebPartManager1" Runat="server"/>
          <uc2:webpartpagemenu id="WebPartPageMenu1" runat="server"></uc2:webpartpagemenu>
          <br />
          <asp:MultiView ID="MultiView1" runat="server">
              <asp:View ID="View1" runat="server">
                  <table style="width: 100%">
                      <tr valign=top align=left>
            <td >
              <asp:WebPartZone ID="WebPartZone1" Runat="server">
                <ZoneTemplate>
                  <sample:textdisplaywebpart runat="server" id="UserControl1" AllowClose="False" AllowMinimize="False" ContentText="This Web Part displays text in this area." Title="Text Display Web Part"/>
                  <asp:Calendar Runat="server" ID="Calendar1"/>
                </ZoneTemplate>
              </asp:WebPartZone>
            </td>
            <td >
              <asp:WebPartZone ID="WebPartZone2" Runat="server">
                <ZoneTemplate>
                  <uc1:textinputcontrol runat="server" id="TextInputControl1" />
                </ZoneTemplate>
              </asp:WebPartZone>
            </td>
            <td>
             <asp:CatalogZone ID="CatalogZone1" Runat="server">
                <ZoneTemplate>
                  <asp:PageCatalogPart Runat="server" ID="PageCatalogPart1" />
                </ZoneTemplate>
              </asp:CatalogZone>
            </td>
                      </tr>
                  </table>
              </asp:View>
              <asp:View ID="View2" runat="server">
        <table style="width: 100%">
          <tr valign=top align=center>
            <td >
             
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
              </asp:View>
          </asp:MultiView></div>
      <div>
        <br />
        <asp:LoginStatus ID="LoginStatus1" Runat="server" />
      </div>
    </form>
  </body>
</html>
