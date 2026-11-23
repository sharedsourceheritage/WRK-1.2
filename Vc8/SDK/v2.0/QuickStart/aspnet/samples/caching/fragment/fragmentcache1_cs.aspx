<%@ Page Language="C#" %>
<%@ Register TagPrefix="Acme" TagName="DataControl" Src="datactrl_cs.ascx" %>

<html>

<script runat="server">
    void Page_Load(Object Src, EventArgs E)
    {
        TimeMsg.Text = DateTime.Now.ToString("G");
    }
  </script>

<body>
<form runat=server>
    <h3>
        <font face="Verdana">Fragment Caching</font></h3>
    <Acme:DataControl runat="server" />
    <br>
    <i>Page last generated on:</i>
    <asp:Label ID="TimeMsg" runat="server" />
    </form>
</body>
</html>

