<%@ Page Language="VB" MasterPageFile="~/ProxyWebPart_Master.master" Title="Untitled Page" %>
<%@ Register TagPrefix="uc1" TagName="TextInputControl" Src="TextInputControl.ascx" %>

<asp:Content runat="server" ContentPlaceHolderID="WebPartZoneContentPlaceHolder">
    <uc1:TextInputControl ID="TextInputControl1" runat="server" />
</asp:Content>

<asp:Content ContentPlaceHolderID="ProxyWebPartContentPlaceHolder" runat="server">
    <asp:ProxyWebPartManager ID="ProxyWebPartManager1" runat="server">
        <StaticConnections>
            <asp:WebPartConnection ConsumerID="UserControl1" ID="MyFirstConnection" ProviderID="TextInputControl1">
            </asp:WebPartConnection>
        </StaticConnections>
    </asp:ProxyWebPartManager>
</asp:Content>
