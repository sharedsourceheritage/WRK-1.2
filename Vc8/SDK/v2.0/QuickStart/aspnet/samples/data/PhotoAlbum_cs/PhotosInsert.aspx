<%@ Page Language="C#"  %>
<%@ Import Namespace="System.Drawing" %>
<%@ Import Namespace="System.IO" %>
<%@ Import Namespace="System.Drawing.Imaging" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<script runat="server">

    protected void DetailsView1_ItemInserting(Object sender, System.Web.UI.WebControls.DetailsViewInsertEventArgs e) {

        FileUpload f = (FileUpload)DetailsView1.FindControl("FileUpload1");
        
        if (f.HasFile) {
            String path = Server.MapPath("Images/" + f.FileName);

            // To enable this sample, grant Write permission to the ASP.NET process account 
            // for the Images subdirectory and uncomment below lines of code.
            // f.SaveAs(path);
            // CreateThumbnail(path, Server.MapPath("Images/Thumbs/" + f.FileName));
        }
    }        
        
    public void CreateThumbnail(String srcpath, String destpath) {

        System.Drawing.Image img = System.Drawing.Image.FromFile(srcpath);
        System.Drawing.Image imgthumb = img.GetThumbnailImage(100, 75, null, new System.IntPtr(0));
        imgthumb.Save(destpath, ImageFormat.Jpeg);
        img.Dispose();
        imgthumb.Dispose();
    }
    
</script>
<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
    <title>View Photos</title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <h1>
                Album: <%= Server.HtmlEncode(Request.QueryString["Name"]) %></h1>
                
            <asp:DetailsView AutoGenerateRows="False" DataKeyNames="PhotoID" DataSourceID="ObjectDataSource1"
                DefaultMode="Insert" HeaderText="Upload Photo" Height="50px" ID="DetailsView1"
                runat="server" OnItemInserting="DetailsView1_ItemInserting">
                <Fields>
                    <asp:BoundField DataField="Caption" HeaderText="Caption" SortExpression="Caption"></asp:BoundField>
                    <asp:TemplateField HeaderText="Image">
                        <ItemTemplate>
                            <asp:FileUpload ID="FileUpload1" FileName='<%# Bind("FileName") %>' runat="server" />
                            <asp:RequiredFieldValidator ID="FileUploadValidator" ControlToValidate="FileUpload1" runat="Server">*</asp:RequiredFieldValidator>
                        </ItemTemplate>
                    </asp:TemplateField>
                    <asp:CommandField ButtonType="Button" ShowInsertButton="True" ShowCancelButton="false" InsertText="Upload Now"></asp:CommandField>
                </Fields>
            </asp:DetailsView>
            
            <br />
            <br />
            The File Upload code has been disabled.  Type Caption="Winter" and Image="Winter.jpg" to test out the sample.  On Internet Explorer in Windows XP SP2 and above, you may need to browse for the full path to this file under the "My Pictures" directory.  <br /><br />
            <asp:DataList ID="DataList1" RepeatColumns="5" Width="600" runat="server" DataSourceID="ObjectDataSource1">
                <ItemTemplate>
                    <br />
                    <asp:HyperLink ID="HyperLink1" runat="server" NavigateUrl='<%# Eval("PhotoID", "PhotoDelete.aspx?ID={0}") %>'>
                    <asp:Image ID="Image1" Runat="server" ImageUrl='<%# Eval("FileName", "images/thumbs/{0}") %>' /></asp:HyperLink>
                    <br />
                    <asp:Label ID="CaptionLabel" runat="server" Text='<%# Eval("Caption") %>' />
                </ItemTemplate>
            </asp:DataList><br />
            <asp:ObjectDataSource ID="ObjectDataSource1" runat="server" TypeName="DataComponentTableAdapters.PhotosTableAdapter"
                InsertMethod="Insert" SelectMethod="GetPhotosForAlbum">
                <SelectParameters>
                    <asp:QueryStringParameter Name="AlbumID" QueryStringField="ID" DefaultValue="1" />
                </SelectParameters>
                <InsertParameters>
                    <asp:QueryStringParameter Name="AlbumID" QueryStringField="ID" DefaultValue="1"/>
                    <asp:Parameter Name="Caption" />
                    <asp:Parameter Name="FileName" />
                </InsertParameters>
            </asp:ObjectDataSource>
        </div>
    </form>
</body>
</html>
