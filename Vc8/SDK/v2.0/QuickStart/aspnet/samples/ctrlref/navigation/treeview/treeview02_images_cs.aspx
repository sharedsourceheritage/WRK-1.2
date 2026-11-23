<%@ Page Language="C#" %>

<html xmlns="http://www.w3.org/1999/xhtml">
  <head runat="server">
    <title>Customizing TreeView Images</title>
  </head>
  <body>
    <div>
      <h2>Customizing TreeView Images</h2>
      
      <form action="treeview02_images_cs.aspx" runat="server">

        <asp:TreeView ID="TreeView1"
          RootNodeStyle-ImageUrl="~/images/xp/computer.gif"
          ParentNodeStyle-ImageUrl="~/images/xp/folder.gif"
          LeafNodeStyle-ImageUrl="~/images/xp/ie.gif"
          CollapseImageUrl="~/images/xp/minus.gif"
          ExpandImageUrl="~/images/xp/plus.gif"
          NoExpandImageUrl="~/images/xp/blank.gif"
          runat="server">
          <Nodes>
            <asp:TreeNode Text="My Computer">
              <asp:TreeNode Text="Favorites" ImageUrl="~/images/xp/star.gif">
                <asp:TreeNode Text="News">  
                  <asp:TreeNode Text="MSN" NavigateUrl="http://www.msn.com"/>
                  <asp:TreeNode Text="MSNBC News" NavigateUrl="http://www.msnbc.msn.com"/>
                </asp:TreeNode>
                <asp:TreeNode Text="Technology">  
                  <asp:TreeNode Text="Microsoft" NavigateUrl="http://www.microsoft.com"/>
                  <asp:TreeNode Text="ASP.NET" NavigateUrl="http://www.asp.net"/>
                  <asp:TreeNode Text="GotDotNet" NavigateUrl="http://www.gotdotnet.com"/>
                  <asp:TreeNode Text="MSDN" NavigateUrl="http://msdn.microsoft.com"/>
                </asp:TreeNode>
                <asp:TreeNode Text="Shopping">  
                  <asp:TreeNode Text="MSN Shopping" NavigateUrl="http://shopping.msn.com"/>
                  <asp:TreeNode Text="MSN Autos" NavigateUrl="http://autos.msn.com"/>
                </asp:TreeNode>
              </asp:TreeNode>
              <asp:TreeNode Text="City Links">
                <asp:TreeNode Text="MapPoint" NavigateUrl="http://www.mappoint.com"/>
                <asp:TreeNode Text="MSN City Guides" NavigateUrl="http://local.msn.com"/>
              </asp:TreeNode>
              <asp:TreeNode Text="Music Links">
                <asp:TreeNode Text="MSN Music" NavigateUrl="http://music.msn.com"/>
              </asp:TreeNode>
            </asp:TreeNode>
          </Nodes>
        </asp:TreeView>

      </form>
    </div>
  </body>
</html>


