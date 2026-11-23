<%@ Page Language="VB" Theme="Default" %>
<%@ Import Namespace="System.Xml" %>

<html xmlns="http://www.w3.org/1999/xhtml">
  <head runat="server">
    <title>TreeView Event Viewer</title>
  </head>
  <script language="VB" runat="server">

    Sub MyTreeView_TreeNodeDataBound(ByVal sender As Object, ByVal e As TreeNodeEventArgs)

      Dim node As XmlNode = CType(e.Node.DataItem, XmlNode)
      If (e.Node.Depth = 1) Then
        Dim dt As DateTime = DateTime.Parse(node.Attributes("DateTime").Value)
        e.Node.Text = dt.ToString("G")
      End If
    End Sub

  </script>
  <body>
    <div>
      <h2>TreeView Event Viewer</h2>

      <form action="treeview18_evtlog3_vb.aspx" runat="server">

        <asp:XmlDataSource ID="MySource" DataFile="~/App_Data/Events.xml" XPath="Events/EventLog" runat="server"/>

        <asp:TreeView ID="MyTreeView" 
          SkinId="Events"
          DataSourceId="MySource"
          MaxDataBindDepth="1" 
          OnTreeNodeDataBound="MyTreeView_TreeNodeDataBound"
          runat="server">
          <Databindings>
            <asp:TreeNodeBinding DataMember="EventLog" TextField="Name" ImageUrl="~/images/events/log.gif" />
            <asp:TreeNodeBinding DataMember="Information" ImageUrl="~/images/events/info.gif" TextField="DateTime"/>
            <asp:TreeNodeBinding DataMember="Error" ImageUrl="~/images/events/warning.gif" TextField="DateTime"/>
            <asp:TreeNodeBinding DataMember="Warning" ImageUrl="~/images/events/error.gif" TextField="DateTime"/>
          </Databindings>
        </asp:TreeView>
    
      </form>
    </div>
  </body>
</html>