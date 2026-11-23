<%@ Page Language="C#" Theme="Default" %>

<html xmlns="http://www.w3.org/1999/xhtml">
  <head runat="server">
    <title>TreeView Event Viewer</title>
  </head>
  <body>
    <div>
      <h2>TreeView Event Viewer</h2>
      <form action="treeview17_evtlog2_cs.aspx" runat="server">

        <asp:XmlDataSource ID="MyXmlDataSource" DataFile="~/App_Data/Events.xml" XPath="Events/EventLog" runat="server"/>

        <asp:TreeView ID="MyTreeView"
          SkinId="Events" 
          DataSourceId="MyXmlDataSource" 
          MaxDataBindDepth="1" 
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

