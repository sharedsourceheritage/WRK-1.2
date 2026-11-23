<%@ Page Language="C#" Theme="Default" %>
<%@ Import Namespace="System.IO" %>

<html xmlns="http://www.w3.org/1999/xhtml">
  <head runat="server">
    <title>Populating TreeView Nodes On-Demand</title>
  </head>
  <script language="C#" runat="server">

    static readonly char[] _slashArray = new char[] {'/'};
    
    void PopulateNode(Object source, TreeNodeEventArgs e)
    {   
      TreeNode node = e.Node;
      if (node.Value == "Demos")
        node.Value = "~/";

      String rootDirectory = Request.MapPath("~/", Request.ApplicationPath, false);
      String fullPath = Request.MapPath(node.Value, Request.ApplicationPath, false);
        
      if (fullPath.StartsWith(rootDirectory) == false)
      {
        // Mitigate against spoofed callback arguments
        // Requested directory is not under root directory
        return;
      }

      String[] dirs = Directory.GetDirectories(fullPath);

      // Enumerate directories
      foreach (String dir in dirs)
      {
        String virtualDir = node.Value.TrimEnd(_slashArray) + "/" + Path.GetFileName(dir);

        TreeNode newNode = new TreeNode(Path.GetFileName(dir), virtualDir);
        if (Directory.GetFiles(dir).Length > 0
            || Directory.GetDirectories(dir).Length > 0)
        {
          newNode.PopulateOnDemand = true;
        }
        node.ChildNodes.Add(newNode);
      }

      // Enumerate files
      String[] files = Directory.GetFiles(fullPath);
      foreach (String file in files)
      {
        TreeNode newNode = new TreeNode(Path.GetFileName(file), Path.GetFileName(file));
        node.ChildNodes.Add(newNode);
      }
    }

  </script>
  <body>
    <div>
      <h2>Populating TreeView Nodes On-Demand</h2>

      <form action="treeview10_ondemand_cs.aspx" runat="server">

        <asp:TreeView ID="MyTree" SkinID="Explorer" PathSeparator="|" OnTreeNodePopulate="PopulateNode"
          ExpandDepth="1" runat="server">
          <Nodes>
            <asp:TreeNode Text="Demos" PopulateOnDemand="true" />
          </Nodes>
        </asp:TreeView>

      </form>
    </div>
  </body>
</html>
