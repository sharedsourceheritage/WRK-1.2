<%@ Page Language="C#" MasterPageFile="~/UserInfo.master"%>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
       <h2>LoginName and LoginStatus Sample</h2>
       
       <asp:LoginName ID="LoginName1" runat="server" FormatString="Welcome {0}!" />
        <br />
        <br />
        <asp:LoginStatus ID="LoginStatus1" runat="server"/>
           
</asp:Content>