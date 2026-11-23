<%@ Page Language="VB" %>
<%@ Register TagPrefix="Acme" TagName="BookList" Src="userctrl6_vb.ascx" %>

<html>
<body style="font: 10pt verdana">

  <h3>A User Control w/ an Event</h3>

  <form runat="server">

    <Acme:BookList runat="server" id="BookList1" />

  </form>

</body>
</html>
