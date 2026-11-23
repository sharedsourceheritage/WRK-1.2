<%@ Page Language="VB" %>
<%@ Register Src="FragCtrlwithAPI_vb.ascx" TagName="FragCtrl" TagPrefix="acme" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">

 
</script>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>Untitled Page</title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <acme:FragCtrl ID="FragCtrl1" runat="server" />
            Current time:
            <%=Now.ToString("G") %>
            <asp:Button ID="Button2" runat="server" Text="Refresh" />
        </div>
    </form>
</body>
</html>

