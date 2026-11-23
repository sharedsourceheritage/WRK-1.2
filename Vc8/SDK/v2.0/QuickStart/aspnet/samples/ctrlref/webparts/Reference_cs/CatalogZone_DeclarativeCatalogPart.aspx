<%@ Page Language="C#" %>
<%@ Register Src="WebPartPageMenu.ascx" TagName="WebPartPageMenu" TagPrefix="uc2" %>
<%@ Register TagPrefix="sample" Namespace="Microsoft.Sample.WebParts" %>
<%@ Register TagPrefix="uc1" TagName="TextInputControl" Src="TextInputControl.ascx" %>
<html>
  <head id="Head1" runat="server">
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
                  <sample:textdisplaywebpart runat="server" id="UserControl1" AllowClose="False" AllowMinimize="False" ContentText="This Web Part displays text in this area." MaxTextDisplayLength="-1" Title="Text Display Web Part"/>
                </ZoneTemplate>
              </asp:WebPartZone>
            </td>
            <td style="width: 100px; height: 100px" valign="top" align="left">
              <asp:WebPartZone ID="WebPartZone2" Runat="server">
              </asp:WebPartZone>
            </td>
            <td style="width: 100px; height: 100px" valign="top" align="left">
                &nbsp; &nbsp;&nbsp; &nbsp;
                <asp:CatalogZone ID="CatalogZone1" runat="server">
                    <ZoneTemplate>
                        <asp:DeclarativeCatalogPart ID="DeclarativeCatalogPart1" runat="server">
                            <WebPartsTemplate>
                                <uc1:TextInputControl ID="TextInputControl1" runat="server" />
                                <sample:textdisplaywebpart runat="server" id="UserControl1" AllowClose="False" AllowMinimize="False" ContentText="This Web Part displays text in this area." MaxTextDisplayLength="-1" Title="Text Display Web Part"/>
                            </WebPartsTemplate>
                        </asp:DeclarativeCatalogPart>
                    </ZoneTemplate>
                </asp:CatalogZone>
            </td>
          </tr>
        </table>
      </div>
    </form>
  </body>
</html>
