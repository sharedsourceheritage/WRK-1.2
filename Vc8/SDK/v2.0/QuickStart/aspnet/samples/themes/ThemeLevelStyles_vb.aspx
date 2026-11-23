<%@ Page Language="VB" Theme="MyTheme" %>

<head runat="server"/>

<h2>Level Styles Collection in a Theme</h2>

  <form runat="server">

      <asp:TreeView ID="TreeView1" runat="server">
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



