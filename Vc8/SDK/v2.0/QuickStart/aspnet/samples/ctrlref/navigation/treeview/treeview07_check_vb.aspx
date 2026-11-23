<%@ Page Language="VB" Theme="Default" %>

<html xmlns="http://www.w3.org/1999/xhtml">
  <head runat="server">
    <title>TreeView Checkboxes</title>
  </head>
  <script language="VB" runat="server">

    Sub MyButton_Click(ByVal source As Object, ByVal e As EventArgs)
        
      Dim checkedNodes As TreeNodeCollection = MyTree.CheckedNodes
      MyDataList.DataSource = checkedNodes
      MyDataList.DataBind()
    End Sub

  </script>
  <body>
    <div>
      <h2>TreeView Checkboxes</h2>

      <form action="treeview07_check_vb.aspx" runat="server">

        <asp:TreeView Id="MyTree" SkinId="News" ShowCheckBoxes="All" runat="server">
            <Nodes>
              <asp:TreeNode Text="news.microsoft.com" ShowCheckBox="false" Expanded="true">
                  <asp:TreeNode Text=" microsoft.public.dotnet.framework.aspnet" Checked="true"/>
                  <asp:TreeNode Text=" microsoft.public.dotnet.framework.aspnet.mobile" />
                  <asp:TreeNode Text=" microsoft.public.dotnet.framework.aspnet.webservices" />
              </asp:TreeNode>
            </Nodes>
        </asp:TreeView>
        <br>
        <asp:Button ID="Button1" OnClick="MyButton_Click" Text="Subscribe!" runat="server"/>
        <br />
        <br />
        <asp:DataList ID="MyDataList" runat="server">
          <HeaderTemplate>
            The following nodes are checked:
          </HeaderTemplate>
          <ItemTemplate>
            <%# Eval("Text") %>
          </ItemTemplate>
        </asp:DataList>

      </form>
    </div>
  </body>
</html>