<%@ Page Language="VB" %>
<%@ Import namespace="System.Web.Management" %>
<%@ Import namespace="Microsoft.Samples.WebEvents" %>

<script runat="server">

  Sub Page_Load(sender As Object, e As EventArgs)

    ' Raise a custom event
    Dim myEvent As MyEvent = new MyEvent("loading webevent sample page", Me)
    myEvent.Raise()
  End Sub

  Sub Page_Unload(sender As Object, e As EventArgs)

      ' Clean up old events in the database
      WebEventsDataSource.Delete()
  End Sub

</script>

<html>
  <head>
    <title>Working With Web Events</title>
  </head>
  <body>
    <form id="form1" runat="server">
      <div>
        <b>This page displays web events emitted by the application.</b>
        <br />
        <br />
        <asp:GridView ID="GridView1" AllowSorting="true" AllowPaging="true" Runat="server"
          DataSourceID="WebEventsDataSource" AutoGenerateColumns="True">
        </asp:GridView>
        <asp:SqlDataSource ID="WebEventsDataSource" Runat="server"
          SelectCommand="SELECT TOP 10 [EventTime], [EventType], [EventSequence], [EventCode], [EventDetailCode], [Message], [ApplicationVirtualPath], [RequestUrl] FROM [dbo].[aspnet_WebEvent_Events] ORDER BY [EventTime] DESC"
          DeleteCommand="DELETE FROM [dbo].[aspnet_WebEvent_Events]"          
          ConnectionString="<%$ ConnectionStrings:ASPNETDB %>" />
      </div>
    </form>
  </body>
</html>
