<%@ Page Language="VB" Theme="Default" %>
<%@ Import Namespace="System.Xml" %>

<html xmlns="http://www.w3.org/1999/xhtml">
  <head runat="server">
    <title></title>
  </head>
  <script language="VB" runat="server">

      Sub MyTreeView_SelectedNodeChanged(sender As Object, e As EventArgs)

          Dim path As String = MyTreeView.SelectedNode.DataPath
          MyDetailsSource.XPath = path
          MyDataList.DataSource = MyDetailsSource
          MyDataList.DataBind()

      End Sub

  </script>
  <body>
    <div>
      <h2>TreeView Event Viewer</h2>

      <form action="treeview19_evtlog4_vb.aspx" runat="server">

        <table width="600px">
          <tr>
            <td valign="top">

              <asp:XmlDataSource ID="MySource" DataFile="~/App_Data/Events.xml" XPath="Events/EventLog" runat="server"/>

              <asp:TreeView ID="MyTreeView" 
                SkinId="Events"
                DataSourceId="MySource" 
                MaxDataBindDepth="1" 
                OnSelectedNodeChanged="MyTreeView_SelectedNodeChanged"
                runat="server">
                <Databindings>
                  <asp:TreeNodeBinding DataMember="EventLog" TextField="Name" ImageUrl="~/images/events/log.gif" SelectAction="Expand" />
                  <asp:TreeNodeBinding DataMember="Information" ImageUrl="~/images/events/info.gif" TextField="DateTime"/>
                  <asp:TreeNodeBinding DataMember="Error" ImageUrl="~/images/events/error.gif" TextField="DateTime"/>
                  <asp:TreeNodeBinding DataMember="Warning" ImageUrl="~/images/events/warning.gif" TextField="DateTime"/>
                </Databindings>
              </asp:TreeView>

            </td>
            <td valign="top">

              <asp:XmlDataSource Id="MyDetailsSource" DataFile="~/App_Data/Events.xml" runat="server"/>

              <asp:DataList Id="MyDataList" runat="server">
                <ItemTemplate>
                  <span style="font: 10pt verdana;"><u><b>Event Details</b></u></span>
                  <table width="350px" style="font: 8pt verdana">
                    <tr><td><b>Date:</b></td><td><%# DateTime.Parse(XPath("@DateTime")).ToString("d") %></td></tr>
                    <tr><td><b>Time:</b></td><td><%# DateTime.Parse(XPath("@DateTime")).ToString("t") %></td></tr>
                    <tr><td><b>Source:</b></td><td><%# XPath("@Source") %></td></tr>
                    <tr><td><b>Message:</b></td><td><%# XPath("text()") %></td></tr>
                    <tr><td><b>Type:</b></td><td><%# XPath("name()") %></td></tr>
                  </table>            
                </ItemTemplate>
              </asp:DataList>

            </td>
          </tr>
        </table>

      </form>
    </div>
  </body>
</html>
