<%@ Control ClassName="NextPrev" %>

  <script language="C#" runat="server">

      void Page_Load() {

          //Using NextSibling and PreviousSibling to find peer nodes
          if (SiteMap.CurrentNode.NextSibling != null )
              NextTopic.NavigateUrl = SiteMap.CurrentNode.NextSibling.Url;
          else {
              NextTopic.Visible = false;
              Separator.Visible = false;
          }

          if (SiteMap.CurrentNode.PreviousSibling != null )
              PrevTopic.NavigateUrl = SiteMap.CurrentNode.PreviousSibling.Url;
          else {
              PrevTopic.Visible = false;
              Separator.Visible = false;
          }
          
          //Using FindSiteMapNode to find a node based on URL and extract some information
          SiteMapNode rootNode = SiteMap.Provider.FindSiteMapNode("~/Home.aspx");
          GoHome.NavigateUrl = rootNode.Url;
          GoHome.ToolTip = rootNode.Description;
          GoHome.Text = rootNode["customAttribute"];
          
      }

  </script>

  [<b> <asp:HyperLink id="PrevTopic" runat="server">Previous Topic</asp:HyperLink></b>
  <span id="Separator" runat="server">|</span>
  <b><asp:HyperLink id="NextTopic" runat="server">Next Topic</asp:HyperLink> </b>]
  <br /> 
  <br />
  <asp:HyperLink id="GoHome" runat="server"></asp:HyperLink> 
  