<%@ Register TagPrefix="Acme" TagName="SourceCtrl" Src="SrcCtrl.ascx" %>
<%@ Import Namespace="System.Text" %>
<%@ Import Namespace="System.IO" %>
<%@ Import Namespace="System.Net" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
  <title>QuickStarts Source Control Viewer</title>
  <link rel="stylesheet" href="~/include/qsstyle.css">
  <script language="C#" runat="server">

    public bool showtitle = true;

    public String width = "100%";
    public String path;
    public String lang;
    private String font;

    public void Page_Load(Object sender, EventArgs e)
    {
      if (!Page.IsPostBack)
      {
        font = Request.QueryString["font"];
        if (font != null)
        {
          FontSize.SelectedIndex = (Int32.Parse(font) - 1);
        }
        else
        {
          font = (String)Session["SrcViewer.FontSize"];
          if (font != null)
          {
            FontSize.SelectedIndex = (Int32.Parse(font.ToString()) - 1);
          }
          else
          {
            FontSize.SelectedIndex = 2;
          }
        }
      }

      if (font == null)
      {
        font = FontSize.SelectedItem.Value;
      }

      MySourceCtrl.FontSize = Int32.Parse(FontSize.SelectedItem.Value);
      Session["SrcViewer.FontSize"] = font;

      try
      {

        if (path == null)
          path = Request.QueryString["path"];
          lang = Request.QueryString["lang"];

        if (path == null)
        {
          ErrorMessage.InnerHtml = "Please specify a path variable in the querystring.";
          return;
        }

        String defaultFile = null;
        String defaultFilename = null;
        String file = Request.QueryString["file"];
//        String FileCheck = null;

        if (file != null)
        {
          String dir = new FileInfo(Server.MapPath(path)).DirectoryName;
          MySourceCtrl.filename = Path.Combine(dir, file);
//          FileCheck = MySourceCtrl.filename;
        }

        //Get The VDir Quickstart Root
//        String rootDir = (String) ((NameValueCollection) Context.GetConfig("system.web/sourceview"))["root"];
		
        //Check to see if the file is actually under the VDir Root
//        if(rootDir != null && FileCheck != null && FileCheck.IndexOf(rootDir) == -1) 
//        {
//            ErrorMessage.InnerHtml = "Please specify a valid Source File.";
//            return;
//        }

        FileStream fs = new FileStream(Server.MapPath(path), FileMode.Open, FileAccess.Read);
        StreamReader sr = new StreamReader(fs);
        String line;

        // Loop through each line of the .src file
        while ((line = sr.ReadLine()) != null)
        {

          String[] list = line.Split(new char[] { ':' });

          if (!(list.Length > 1))
          {
            break;
          }

          String sourcegroup = list[0];  // Grouping of files
          String[] sourcelist = list[1].Split(new char[] { ',' }); // Individual file paths
          String value = "VB";
          if (lang == null || lang == String.Empty)
          {
              HttpCookie codeCookie = Page.Request.Cookies["langpref"];

              
              if (codeCookie != null && codeCookie.Value.Length >0)
              {
                  value = codeCookie.Value;
              }
          }
          else
          {
              value = lang;
          }

          // Try to find a match for the langpref cookie
          if ((file == null) && (sourcelist.Length > 0) && (sourcegroup.StartsWith(value)))
          {
            String dir = new FileInfo(Server.MapPath(path)).DirectoryName;
            MySourceCtrl.filename = dir + "\\" + sourcelist[0];
            file = sourcelist[0];
          }

          // Just in case there is no match, store a pointer to the first file
          if ((defaultFile == null) && (sourcelist.Length > 0))
          {
            String dir = new FileInfo(Server.MapPath(path)).DirectoryName;
            defaultFilename = dir + "\\" + sourcelist[0];
            defaultFile = sourcelist[0];
          }

          if (!Page.IsPostBack)
          {

            // Create the list of file hyperlinks for this sourcegroup
            Trace.Write("SrcViewer", "Source Group = " + sourcegroup);

            TreeNode groupNode = new TreeNode(sourcegroup);
            groupNode.SelectAction = TreeNodeSelectAction.Expand;
            TreeView1.Nodes.Add(groupNode);

            // Try to find a match for the langpref cookie
            if (!sourcegroup.StartsWith(value))
            {
              groupNode.Expanded = false;
            }
            
            foreach (String sourcefile in sourcelist)
            {
              TreeNode currParent = groupNode;
              String[] files = sourcefile.Split(new char[] { '\\' });
              String navUrl = "srcview.aspx?path=" + path + "&file=" + sourcefile+"&lang="+HttpUtility.UrlEncode(sourcegroup);

              int i = 0;

              // while not at leaf file in path
              while (i != (files.Length - 1))
              {
                int j = 0;
                bool found = false;

                // if the current parent has no children, just add the folder
                if (currParent.ChildNodes.Count == 0)
                {
                  TreeNode node = new TreeNode(files[i]);
                  node.SelectAction = TreeNodeSelectAction.Expand;
                  node.ImageUrl = GetFolderImage(node.Text);
                  currParent.ChildNodes.Add(node);
                  currParent = node;
                }
                else
                {
                  // otherwise, enumerate the existing folders of the current parent node
                  // NOTE: Should add HasChildren property to TreeNode
                  while (j < currParent.ChildNodes.Count && currParent.ChildNodes[j].ChildNodes.Count > 0 && !found)
                  {
                    if (currParent.ChildNodes[j].Text == files[i])
                    {
                      // found matching folder in tree
                      currParent = currParent.ChildNodes[j];
                      found = true;
                    }
                    else
                    {
                      j = j + 1;
                    }
                  }

                  if (!found)
                  {
                    // no matching folder, add as new folder
                    TreeNode node = new TreeNode(files[i]);
                    node.SelectAction = TreeNodeSelectAction.Expand;
                    node.ImageUrl = GetFolderImage(node.Text);
                    currParent.ChildNodes.AddAt(j, node);
                    currParent = node;
                  }
                }
                i = i + 1;
              }
              // Add file as leaf node
              TreeNode leafNode = new TreeNode(files[i]);
              leafNode.NavigateUrl = navUrl;

              int index = leafNode.Text.LastIndexOf(".");
              String extension = leafNode.Text.Substring(index, leafNode.Text.Length - index);
              leafNode.ImageUrl = GetFileImage(extension);

              currParent.ChildNodes.Add(leafNode);
            }
          }
        }

        fs.Close();

        // If there was no match for the langpref cookie,
        // show the first file of the first sourcegroup

        if (file == null) {
          MySourceCtrl.filename = defaultFilename;
          TreeView1.Nodes[0].Expanded = true;
        }

        if (showtitle != false)
        {
          if (file != null)
            BannerTitle.Text = file;
          else if (defaultFile != null)
            BannerTitle.Text = defaultFile;
        }
        else
          BannerTitle.Text = "Quickstart Source Viewer";

      }
      catch (Exception exc)
      {
        Trace.Write("Exception", exc.ToString());
      }

    }

    public String GetFolderImage(String folderName)
    {
      switch (folderName.ToLower())
      {
        case "app_code":
          return "~/Images/app_code.gif";
        case "app_data":
          return "~/Images/app_data.gif";
        case "app_themes":
          return "~/Images/app_themes.gif";
        case "app_browsers":
          return "~/Images/app_browsers.gif";
        case "app_localresources":
          return "~/Images/app_resources.gif";
        case "app_globalresources":
          return "~/Images/app_resources.gif";
        case "app_webreferences":
          return "~/Images/app_webreferences.gif";
        case "bin":
          return "~/Images/app_bin.gif";
        default:
          return "~/Images/folder2.gif";
      }
    }

    public String GetFileImage(String fileExtension)
    {
      switch (fileExtension)
      {
        case ".aspx":
          return "~/Images/aspx.gif";
        case ".cs":
          return "~/Images/cs.gif";
        case ".vb":
          return "~/Images/vb.gif";
        case ".js":
          return "~/Images/js.gif";
        case ".config":
          return "~/Images/config.gif";
        case ".xml":
          return "~/Images/xml.gif";
        case ".xsd":
          return "~/Images/xsd.gif";          
        case ".ascx":
          return "~/Images/ascx.gif";
        case ".htm":
          return "~/Images/html.gif";
        case ".html":
          return "~/Images/html.gif";
        case ".master":
          return "~/Images/master.gif";
        case ".txt":
          return "~/Images/txt.gif";
        case ".css":
          return "~/Images/css.gif";
        default:
          return "~/Images/txt.gif";
      }
    }

    public void LinkButton_Click(Object sender, EventArgs e)
    {
      // do nothing
    }

    public void Size_Select(Object sender, EventArgs e)
    {
      MySourceCtrl.FontSize = Int32.Parse(FontSize.SelectedItem.Value);
      Session["SrcViewer.FontSize"] = FontSize.SelectedItem.Value.ToString();
      //Added to prevent the web page from shifting positions when the value changes.
      Page.SetFocus(MySourceCtrl);
    }

    </script>
</head>
<body bottommargin="0" topmargin="0" leftmargin="0" style="height: 100%" bgcolor="#FFFFFF"
  text="#000000">
  <div>
    <form id="Form" runat="server">
      <asp:Table ID="Table1" runat="server" Width="100%" CellPadding="0" CellSpacing="0"
        BorderStyle="None">
        <asp:TableRow ID="TableRow1" runat="server">
          <asp:TableCell ID="TableCell1" runat="server" VerticalAlign="Top" RowSpan="2">
                  <asp:Image ID="Image1" Runat="server" ImageUrl="~/images/dotnet.gif" />
          </asp:TableCell>
          <asp:TableCell ID="TableCell2" runat="server" VerticalAlign="Top">
                  <asp:Image ID="Image2" Runat="server" ImageUrl="~/images/banner_curve.gif" />
          </asp:TableCell>
          <asp:TableCell ID="TableCell3" BackColor="White" runat="server" />
        </asp:TableRow>
        <asp:TableRow ID="TableRow2" runat="server">
          <asp:TableCell ID="TableCell4" VerticalAlign="Top" runat="server">
                    <asp:Image ID="BannerFade" Runat="server" ImageUrl="~/images/banner_fade.gif" />
          </asp:TableCell>
          <asp:TableCell ID="TableCell5" VerticalAlign="Top" CssClass="bannerbg" ColumnSpan="5"
            runat="server" />
        </asp:TableRow>
        <asp:TableRow ID="TableRow3" runat="server">
          <asp:TableCell ID="TableCell6" CssClass="toolbar" Height="25px" VerticalAlign="Middle"
            Wrap="False" ColumnSpan="5" runat="server">
                 <asp:Table ID="Table3" RunAt=server Width=100% CellPadding=0 CellSpacing=0 BorderStyle=None>
                  <asp:TableRow ID="TableRow4" Runat="server">
                    <asp:TableCell ID="TableCell7" Wrap=False Runat="server">
                        &nbsp;&nbsp;
                        <asp:HyperLink ID="HyperLink1" Runat="server" CssClass="toolbar"  NavigateUrl="~/">Welcome</asp:HyperLink>
                        &nbsp;&nbsp;|&nbsp;&nbsp;
                        
                        <asp:HyperLink ID="HyperLink2" Runat="server" CssClass="toolbar"  NavigateUrl="~/aspnet/">ASP.NET</asp:HyperLink>
                        &nbsp;&nbsp;|&nbsp;&nbsp;

	                    <asp:HyperLink ID="HyperLink3" Runat="server" CssClass="toolbar"  NavigateUrl="~/webservices/">Web Services</asp:HyperLink>
                        &nbsp;&nbsp;|&nbsp;&nbsp;

                        <asp:HyperLink ID="HyperLink5" Runat="server" CssClass="toolbar" NavigateUrl="~/howto/">How Do I...?</asp:HyperLink>
                        &nbsp;&nbsp;|&nbsp;&nbsp;

                        <asp:HyperLink ID="HyperLink6" Runat="server" CssClass="toolbar" NavigateUrl="~/util/classbrowser.aspx">Class Browser</asp:HyperLink>
                        &nbsp;&nbsp;
                    </asp:TableCell>
                  </asp:TableRow>
                 </asp:Table>
          </asp:TableCell>
          <asp:TableCell ID="TableCell8" CssClass="toolbar" HorizontalAlign="Right" Wrap="False"
            runat="server" Width="100%" VerticalAlign="Middle">
                    &nbsp;&nbsp;|&nbsp;&nbsp;
                    Font Size...
                    &nbsp;&nbsp;
          </asp:TableCell>
          <asp:TableCell ID="TableCell9" CssClass="toolbar" Width="100%" HorizontalAlign="Right"
            VerticalAlign="Middle" Wrap="False" runat="server">         
                    <asp:DropDownList CssClass="Select" Width="50px" ID="FontSize" OnSelectedIndexChanged="Size_Select" Font-Size="x-small" Font-Names="verdana" Font-Bold=True
                AutoPostBack="true" runat="server">
                <asp:ListItem Value="1" runat="server">1</asp:ListItem>
                <asp:ListItem Value="2" runat="server">2</asp:ListItem>
                <asp:ListItem Value="3" runat="server">3</asp:ListItem>
                <asp:ListItem Value="4" runat="server">4</asp:ListItem>
                <asp:ListItem Value="5" runat="server">5</asp:ListItem>
                <asp:ListItem Value="6" runat="server">6</asp:ListItem>
                <asp:ListItem Value="7" runat="server">7</asp:ListItem>
              </asp:DropDownList>
                    &nbsp;&nbsp;
          </asp:TableCell>
        </asp:TableRow>
      </asp:Table>
      <div class="sectiontitle">
        <h1>
          <asp:Label ID="BannerTitle" Text="Welcome" runat="server" />
          <asp:Label ID="BannerSubTitle" runat="server" />
        </h1>
      </div>
      <asp:Table ID="Table2" Height="100%" runat="server" CellPadding="0" CellSpacing="0"
        BorderStyle="None">
        <asp:TableRow ID="TableRow5" runat="server" VerticalAlign="Top" HorizontalAlign="Left">
          <asp:TableCell ID="NavCell" Height="100%" CssClass="nav" runat="server" HorizontalAlign="Left"
            VerticalAlign="Top">
            <asp:TreeView Width="231px" ID="TreeView1" Runat="server" ShowExpandCollapse="True"
                NodeIndent="20">
                <ParentNodeStyle ImageUrl="~/Images/folder2.gif" Font-Bold="True" HorizontalPadding="5px" VerticalPadding="3px" /> 
                <LeafNodeStyle ImageUrl="~/Images/txt.gif" HorizontalPadding="5px" VerticalPadding="3px" />
                <LevelStyles>
                    <asp:TreeNodeStyle Font-Size="small" Font-Bold="True" VerticalPadding="5px" ImageUrl="~/Images/Web.gif" HorizontalPadding="5px" /> 
                </LevelStyles>
                <SelectedNodeStyle Font-Underline="False" />
                <NodeStyle ChildNodesPadding="5px" Font-Size="1em"  />
            </asp:TreeView>
          </asp:TableCell>
          <asp:TableCell ID="TableCell10" runat="server" CssClass="mainbody" VerticalAlign="Top"
            HorizontalAlign="Left" Height="100%">
            <Acme:SourceCtrl ID="MySourceCtrl" runat="server" />
            <span style="color: red" id="ErrorMessage" runat="server" />
          </asp:TableCell>
        </asp:TableRow>
      </asp:Table>
      </form>
  </div>
  
</body>
</html>
