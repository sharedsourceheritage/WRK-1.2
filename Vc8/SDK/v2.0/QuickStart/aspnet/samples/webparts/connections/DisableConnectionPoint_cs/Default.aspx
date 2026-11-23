<%@ Page Language="C#" AutoEventWireup="true" %>
<%@ Register Src="WebPartPageMenu.ascx" TagName="WebPartPageMenu" TagPrefix="uc2" %>
<%@ Register TagPrefix="sample" Namespace="Microsoft.Sample.WebParts" %>
<%@ Register TagPrefix="uc1" TagName="TextInputControl" Src="TextInputControl.ascx" %>
<script runat="server">

    protected void Page_Load(object sender, EventArgs e)
    {
        if (!Page.IsPostBack)
        {
            if (textdisplaywebpart1.AllowTextConsumerConnection)
                RadioButtonList1.SelectedIndex = 0;
            else
                RadioButtonList1.SelectedIndex = 1;
        }
                
    }

    protected void RadioButtonList1_SelectedIndexChanged(object sender, EventArgs e)
    {
        
        if (Convert.ToInt32(RadioButtonList1.SelectedValue) == 0)
            textdisplaywebpart1.AllowTextConsumerConnection = true;
        else
            textdisplaywebpart1.AllowTextConsumerConnection = false;  
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
          <fieldset>
          <legend>Text Display Web Part Consumer Connection Point</legend>
          <asp:RadioButtonList ID="RadioButtonList1" runat="server" OnSelectedIndexChanged="RadioButtonList1_SelectedIndexChanged" AutoPostBack=true>
              <asp:ListItem Value="0">Enabled</asp:ListItem>
              <asp:ListItem Value="1">Disabled</asp:ListItem>
          </asp:RadioButtonList>
          </fieldset></div>
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
                &nbsp;&nbsp;
                <asp:ConnectionsZone ID="ConnectionsZone1" runat="server">
                </asp:ConnectionsZone>
            </td>
          </tr>
        </table>
      </div>
        &nbsp;
    </form>
  </body>
</html>
