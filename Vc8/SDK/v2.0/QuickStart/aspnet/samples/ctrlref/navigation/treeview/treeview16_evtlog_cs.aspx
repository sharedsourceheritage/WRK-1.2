<%@ Page Language="C#" Theme="Default" %>

<html xmlns="http://www.w3.org/1999/xhtml">
  <head runat="server">
    <title>TreeView Event Viewer</title>
  </head>
  <body>
    <div>
      <h2>TreeView Event Viewer</h2>
      <form action="treeview16_evtlog_cs.aspx" runat="server">

        <asp:XmlDataSource ID="MyXmlDataSource" DataFile="~/App_Data/Events.xml" runat="server"/>
        <asp:TreeView ID="MyTreeView" DataSourceId="MyXmlDataSource" runat="server" />
    
      </form>
    </div>
  </body>
</html>