<%@ Page Language="C#" %>

<html xmlns="http://www.w3.org/1999/xhtml">
  <head runat="server">
    <title>TreeView Level Styles</title>
  </head>
  <body>
    <div>
      <h2>TreeView Level Styles</h2>

      <form action="treeview06_levels_cs.aspx" runat="server">

        <asp:TreeView ID="TreeView1" runat="server"
            Font-Names="Verdana" 
            ForeColor="Black"
            HoverNodeStyle-Font-Underline="true"
            ShowExpandCollapse="false"
            ExpandDepth="3"
            NodeIndent="0">
            <LevelStyles>
                <asp:TreeNodeStyle ChildNodesPadding="10" Font-Bold="True" Font-Size="12pt" ForeColor="DarkGreen"/>
                <asp:TreeNodeStyle ChildNodesPadding="5" Font-Bold="True" Font-Size="10pt" />
                <asp:TreeNodeStyle ChildNodesPadding="5" Font-Underline="True" Font-Size="10pt" />
                <asp:TreeNodeStyle Font-Size="8pt" />
            </LevelStyles>
            <Nodes>
                <asp:TreeNode Text="Table of Contents">
                    <asp:TreeNode Text="Chapter One">
                        <asp:TreeNode Text="Section 1.0">
                            <asp:TreeNode Text="Topic 1.0.1"/>
                            <asp:TreeNode Text="Topic 1.0.2"/>
                            <asp:TreeNode Text="Topic 1.0.3"/>
                        </asp:TreeNode>
                        <asp:TreeNode Text="Section 1.1">
                            <asp:TreeNode Text="Topic 1.1.1" />
                            <asp:TreeNode Text="Topic 1.1.2" />
                            <asp:TreeNode Text="Topic 1.1.3" />
                            <asp:TreeNode Text="Topic 1.1.4" />
                        </asp:TreeNode>
                    </asp:TreeNode>
                    <asp:TreeNode Text="Chapter Two">
                        <asp:TreeNode Text="Section 2.0">
                            <asp:TreeNode Text="Topic 2.0.1" />
                            <asp:TreeNode Text="Topic 2.0.2" />
                        </asp:TreeNode>
                    </asp:TreeNode>
                    <asp:TreeNode Text="Appendix A" />
                    <asp:TreeNode Text="Appendix B" />
                    <asp:TreeNode Text="Appendix C" />
                </asp:TreeNode>
            </Nodes>
        </asp:TreeView>
  
      </form>
    </div>
  </body>
</html>



