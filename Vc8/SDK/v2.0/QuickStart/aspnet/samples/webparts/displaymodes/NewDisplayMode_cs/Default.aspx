<%@ Page Language="C#" %>
<%@ Register Src="TextDisplay.ascx" TagName="TextDisplay" TagPrefix="uc2" %>
<%@ Register Src="WebPartPageMenu.ascx" TagName="WebPartPageMenu" TagPrefix="uc1" %>
<%@ Register Namespace=Microsoft.Sample.WebParts TagPrefix=sample  %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    <sample:NewWebPartManager runat=server ID=wpgm1 />&nbsp;
        <uc1:webpartpagemenu id="WebPartPageMenu1" runat="server"></uc1:webpartpagemenu>
        <br />
        <table style="width: 100%">
            <tr valign=top align=center >
                <td style="width: 100px; height: 123px">
        <asp:WebPartZone ID="WebPartZone1" runat="server">
            <ZoneTemplate>
                <uc2:TextDisplay ID="TextDisplay1" runat="server">
                </uc2:TextDisplay>
            </ZoneTemplate>
        </asp:WebPartZone>
                </td>
                <td style="width: 100px; height: 123px">
                    <asp:WebPartZone ID="WebPartZone2" runat="server">
                    </asp:WebPartZone>
                </td>
            </tr>
        </table>
        <br />
        <br />
        <br />
        &nbsp;</div>
    </form>
</body>
</html>
