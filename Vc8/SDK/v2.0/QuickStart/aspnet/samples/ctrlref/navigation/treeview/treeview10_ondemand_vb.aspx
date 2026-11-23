<%@ Page Language="VB" Theme="Default" %>
<%@ Import Namespace="System.IO" %>

<html xmlns="http://www.w3.org/1999/xhtml">
  <head runat="server">
    <title>Populating TreeView Nodes On-Demand</title>
  </head>
  <script language="VB" runat="server">

    Shared ReadOnly _slashArray() As Char = {"/"}
    
    Sub PopulateNode(ByVal source As Object, ByVal e As TreeNodeEventArgs)

      Dim node As TreeNode = e.Node
      If (node.Value = "Demos") Then
        node.Value = "~/"
      End If
      
      Dim rootDirectory As String = Request.MapPath("~/", Request.ApplicationPath, False)
      Dim fullPath As String = Request.MapPath(node.Value, Request.ApplicationPath, False)
      
      If (fullPath.StartsWith(rootDirectory) = False) Then
      
        ' Mitigate against spoofed callback arguments
        ' Requested directory is not under root directory
        Return
      End If

      Dim dirs() As String = Directory.GetDirectories(fullPath)

      ' Enumerate directories
      Dim dir As String
      For Each dir In dirs
        Dim virtualDir As String = node.Value.TrimEnd(_slashArray) & "/" & Path.GetFileName(dir)
        
        Dim newNode As TreeNode = New TreeNode(Path.GetFileName(dir), virtualDir)
        If (Directory.GetFiles(dir).Length > 0 _
            Or Directory.GetDirectories(dir).Length > 0) Then
          newNode.PopulateOnDemand = True
        End If
        node.ChildNodes.Add(newNode)
      Next
      
      ' Enumerate files
      Dim files() As String = Directory.GetFiles(fullPath)
      Dim file As String
      For Each file In files
        Dim newNode As TreeNode = New TreeNode(Path.GetFileName(file), Path.GetFileName(file))
        node.ChildNodes.Add(newNode)
      Next
      
    End Sub

  </script>
  <body>
    <div>
      <h2>Populating TreeView Nodes On-Demand</h2>
      
      <form action="treeview10_ondemand_vb.aspx" runat="server">

        <asp:TreeView Id="MyTree" SkinId="Explorer"
          PathSeparator = "|"
          OnTreeNodePopulate="PopulateNode"
          ExpandDepth="1"
          runat="server">
          <Nodes>
            <asp:TreeNode Text="Demos" PopulateOnDemand="true" />
          </Nodes>
        </asp:TreeView>

      </form>
    </div>
  </body>
</html>
