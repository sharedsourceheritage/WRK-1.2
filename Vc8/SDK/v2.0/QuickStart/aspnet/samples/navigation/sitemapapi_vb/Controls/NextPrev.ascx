<%@ Control ClassName="NextPrev" %>

  <script language="VB" runat="server">

      Sub Page_Load()

          If (Not SiteMap.CurrentNode.NextSibling Is Nothing) Then
              NextTopic.NavigateUrl = SiteMap.CurrentNode.NextSibling.Url
          Else
              NextTopic.Visible = false
              Separator.Visible = false
          End If

          If (Not SiteMap.CurrentNode.PreviousSibling Is Nothing)
              PrevTopic.NavigateUrl = SiteMap.CurrentNode.PreviousSibling.Url
          Else
              PrevTopic.Visible = false
              Separator.Visible = false
          End If

          'Using FindSiteMapNode to find a node based on URL and extract some information
          Dim rootNode as SiteMapNode = SiteMap.Provider.FindSiteMapNode("~/Home.aspx")
          GoHome.NavigateUrl = rootNode.Url
          GoHome.ToolTip = rootNode.Description
          GoHome.Text = rootNode("customAttribute")

      End Sub

  </script>

  [<b> <asp:HyperLink id="PrevTopic" runat="server">Previous Topic</asp:HyperLink></b>
  <span id="Separator" runat="server">|</span>
  <b><asp:HyperLink id="NextTopic" runat="server">Next Topic</asp:HyperLink> </b>]
  <br /> 
  <br />
  <asp:HyperLink id="GoHome" runat="server"></asp:HyperLink> 