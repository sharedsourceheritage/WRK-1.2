<%@ Page Language="VB" MasterPageFile="~/Site.master"%>
<%@ Register TagPrefix="Samples" TagName="NextPrev" Src="~/Controls/NextPrev.ascx" %>

<asp:Content ID="Content1" ContentPlaceHolderID="MainBody" runat="server">
  <h2>Section Two</h2>
  <h3>Page 3</h3>
  <Samples:NextPrev ID="NextPrev1" runat="server"/>  
</asp:Content>