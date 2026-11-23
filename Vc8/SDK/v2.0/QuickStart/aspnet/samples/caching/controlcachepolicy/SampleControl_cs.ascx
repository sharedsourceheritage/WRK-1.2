<%@ Control Language="c#" %>
<%@ OutputCache Duration="3600" VaryByParam="none" %>

<asp:Panel runat="Server" BackColor="Gold" BorderStyle="Dashed" HorizontalAlign="Center">
<br />
<br />
<br />
<div style="font-size:xx-large; font-weight:bold">
<%= DateTime.Now.ToString() %>
</div>
<br />
<br />
<br />
</asp:Panel>