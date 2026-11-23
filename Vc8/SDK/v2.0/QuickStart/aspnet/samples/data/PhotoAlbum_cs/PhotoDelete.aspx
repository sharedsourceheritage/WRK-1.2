<%@ Page Language="C#" %>
<%@ Import Namespace = "System.IO" %>
<%@ Import Namespace = "System.Data" %>
<%@ Import Namespace = "System.Data.SqlClient" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<script runat="server">

    String fileName = "";

    protected void FormView1_ItemDeleted(Object sender, System.Web.UI.WebControls.FormViewDeletedEventArgs e) 
    {
        if (e.Exception == null) {
            // To enable this sample, grant Write permission to the ASP.NET process account 
            // for the Images subdirectory and uncomment below lines of code.            
            // File.Delete(Server.MapPath("Images\\" + fileName));
            // File.Delete(Server.MapPath("Images\\Thumbs\\" + fileName));
            Response.Redirect(e.Values["AlbumID"].ToString());
        }
    }
    
    protected void FormView1_ItemDeleting(Object sender, System.Web.UI.WebControls.FormViewDeleteEventArgs e) 
    {
        SqlDataSource s = new SqlDataSource();
        s.ConnectionString = ConfigurationManager.ConnectionStrings["Photos"].ConnectionString;
        s.SelectCommand = "select [FileName] from [Photos] where [PhotoID] = @PhotoID";
        
        s.SelectParameters.Add(new Parameter("PhotoID", TypeCode.Int32, e.Keys["PhotoID"].ToString()));
        s.DataSourceMode = SqlDataSourceMode.DataReader;
        SqlDataReader rows = (SqlDataReader)s.Select(DataSourceSelectArguments.Empty);

        if (rows.Read()) {
            fileName = rows.GetString(0);
        }
    }
</script>
<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
    <title>View Photo</title>
</head>
<body>
    <form id="form1" runat="server">
        <div>
            <asp:FormView ID="FormView1" runat="server" DataSourceID="ObjectDataSource1" DataKeyNames="PhotoID" OnItemDeleted="FormView1_ItemDeleted" OnItemDeleting="FormView1_ItemDeleting">
                <EditItemTemplate>
                    <b>Enter a New Caption:</b>
                    <asp:TextBox Text='<%# Bind("Caption") %>' runat="server" ID="CaptionTextBox" />&nbsp;<asp:Button
                        ID="Button1" runat="server" Text="Update" CommandName="Update" />
                    <asp:Button ID="Button2" runat="server" Text="Cancel" CommandName="Cancel" />
                </EditItemTemplate>
                <ItemTemplate>
                    <asp:Label ID="CaptionLabel" runat="server" Text='<%# Eval("Caption") %>' Font-Size="32pt" /><br />
                    <br />
                    <asp:Image ID="Image1" runat="server" ImageUrl='<%# Eval("FileName", "images/{0}") %>' />
                    <br />
                    <br />
                    <asp:Button ID="Button3" runat="server" Text="Edit Caption..." CommandName="Edit" />
                    <asp:Button CommandName="Delete" ID="Button4" runat="server" Text="Delete Photo" /><br />
                    <br />
                    <asp:HyperLink ID="HyperLink1" Text="Back to Album" NavigateUrl='<%# Bind("AlbumID", "PhotosInsert.aspx?ID={0}") %>'
                        runat="server" />
                </ItemTemplate>
                <EmptyDataTemplate>
                    <% Response.Redirect(String.Format("PhotosInsert.aspx")); %>
                </EmptyDataTemplate>
            </asp:FormView>
            <br />
            <br />
            <asp:ObjectDataSource ID="ObjectDataSource1" runat="server" TypeName="DataComponentTableAdapters.PhotosTableAdapter"
                InsertMethod="Insert" SelectMethod="GetPhoto" UpdateMethod="UpdateCaption" DeleteMethod="Delete" OldValuesParameterFormatString="original_{0}">
                <UpdateParameters>
                    <asp:Parameter Name="Caption" />
                    <asp:Parameter Name="PhotoID" />
                </UpdateParameters>
                <SelectParameters>
                    <asp:QueryStringParameter Name="PhotoID" DefaultValue="1" QueryStringField="ID" />
                </SelectParameters>
                <InsertParameters>
                    <asp:Parameter Name="AlbumID" />
                    <asp:Parameter Name="Caption" />
                    <asp:Parameter Name="FileName" />
                </InsertParameters>
                <DeleteParameters>
                    <asp:Parameter Name="Original_PhotoID" />
                </DeleteParameters>
            </asp:ObjectDataSource>
        </div>
    </form>
</body>
</html>
