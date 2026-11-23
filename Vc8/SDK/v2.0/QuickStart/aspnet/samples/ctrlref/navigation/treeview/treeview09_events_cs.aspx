<%@ Page Language="C#" Theme="Default" %>

<html xmlns="http://www.w3.org/1999/xhtml">
  <head runat="server">
    <title>TreeView Events</title>
  </head>
  <script runat="server">

    void MyTree_Select (Object source, EventArgs e) {
        String value = MyTree.SelectedNode.Value; 
        String path = MyTree.SelectedNode.ValuePath;
        Response.Write ("The value selected was " + value + "<br>");
        Response.Write ("The value path is " + path + "<br>");
    }

    void MyTree_Expand (Object source, TreeNodeEventArgs e) {
        String value = e.Node.Value;
        Response.Write ("The value expanded was " + value + "<br>");
    }

    void MyTree_Collapse (Object source, TreeNodeEventArgs e) {
        String value = e.Node.Value;
        Response.Write ("The value collapsed was " + value + "<br>");
    }

  </script>
  <body bgcolor="#eeeeee">
    <div>
      <h2>TreeView Events</h2>

      <form action="treeview09_events_cs.aspx" runat="server">

        <asp:TreeView Id="MyTree" SkinId="MSDN" 
          OnSelectedNodeChanged="MyTree_Select" 
          OnTreeNodeCollapsed="MyTree_Collapse" 
          OnTreeNodeExpanded="MyTree_Expand" 
          ExpandDepth="0"
          runat="server">
            <Nodes>
              <asp:TreeNode Text="Welcome to Code Center" Value="1.0" />   
              <asp:TreeNode Text="Data Binding" Value="2.0" SelectAction="Expand">  
                <asp:TreeNode Text="ANCHOR Element" Value="2.1"/>
                <asp:TreeNode Text="APPLET Element" Value="2.2"/>   
                <asp:TreeNode Text="BUTTON Element" Value="2.3" SelectAction="Expand">
                  <asp:TreeNode Text="Text Attribute" Value="2.3.1"/>   
                  <asp:TreeNode Text="Value Attribute" Value="2.3.2"/>
                </asp:TreeNode>   
              </asp:TreeNode>
              <asp:TreeNode Text="Data Source Objects" Value="3.0" SelectAction="Expand">  
                <asp:TreeNode Text="Array (VB)" Value="3.1"/>  
                <asp:TreeNode Text="Calendar Applet (Java)" Value="3.2"/>  
                <asp:TreeNode Text="Dual DSO (HTML)" Value="3.3"/>  
                <asp:TreeNode Text="Loan Calculator (VB)" Value="3.4"/>  
              </asp:TreeNode>
              <asp:TreeNode Text="DirectX Transformations" Value="4.0" SelectAction="Expand">  
                <asp:TreeNode Text="Settings Reference" Value="4.1"/>  
              </asp:TreeNode>
              <asp:TreeNode Text="Content & Component Delivery" Value="5.0" SelectAction="Expand">  
                <asp:TreeNode Text="Channel" Value="5.1"/>  
                <asp:TreeNode Text="IISLog" Value="5.2"/>  
              </asp:TreeNode>
              <asp:TreeNode Text="Common Controls" Value="6.0" SelectAction="Expand">  
                <asp:TreeNode Text="Rebar Control" Value="6.1"/>  
                <asp:TreeNode Text="Virtual List View Control" Value="6.2"/>  
              </asp:TreeNode>
              <asp:TreeNode Text="Component Development" Value="7.0" SelectAction="Expand">  
                <asp:TreeNode Text="Band Object Implementation" Value="7.1"/>  
              </asp:TreeNode>
              <asp:TreeNode Text="Internet Explorer 5 Demos" Value="8.0" SelectAction="Expand">  
                <asp:TreeNode Text="Ad Banner" Value="8.1"/>  
              </asp:TreeNode>
              <asp:TreeNode Text="Internet Explorer 5.5 Demos" Value="9.0" SelectAction="Expand">  
                <asp:TreeNode Text="Binary Behavior" Value="9.1"/>  
              </asp:TreeNode>
              <asp:TreeNode Text="Internet Explorer 6 Demos" Value="10.0" SelectAction="Expand">  
                <asp:TreeNode Text="HTML+TIME Transitions" Value="10.1"/>  
                <asp:TreeNode Text="HTMLEditor" Value="10.2"/>  
              </asp:TreeNode>
              <asp:TreeNode Text="Messaging & Collaboration" Value="11.0" SelectAction="Expand">  
                <asp:TreeNode Text="WAB Property Inspector Tool" Value="11.1"/>  
              </asp:TreeNode>
              <asp:TreeNode Text="Windows Media" Value="12.0" SelectAction="Expand">  
                <asp:TreeNode Text="Simple ASX" Value="12.1"/>  
              </asp:TreeNode>
            </Nodes>
        </asp:TreeView>

      </form>
    </div>
  </body>
</html>

