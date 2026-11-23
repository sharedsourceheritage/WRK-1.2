<%@ Page Language="C#" %>
<%@ Register TagPrefix="Acme" TagName="BookList" Src="userctrl6_cs.ascx" %>

<html>
<body style="font: 10pt verdana">

  <h3>A User Control w/ an Event</h3>

  <form runat="server">

    <Acme:BookList runat="server" id="BookList1" />

  </form>

</body>
</html>
