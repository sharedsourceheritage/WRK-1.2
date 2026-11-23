<%@ Page Language="C#"  %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<script runat="server">
</script>
<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>Url Remapping Demo</title>
</head>
<body>
    <asp:SiteMapDataSource Runat=server ID="SiteMapDataSource1" />
    <form id="form1" runat="server">
    <div>
        <table>
            <tr>
                <td valign="top" align="right">
                    <asp:Label Runat=server Text="SiteMapPath" id="Label1" ForeColor="#ff3366" /> 
                    <asp:SiteMapPath id="SiteMapPath1" Runat=Server />
                </td>
            </tr>
           <tr>
                <td><br /></td> 
           </tr> 
            <tr>
                <td>
                    <asp:Label Runat=server Text="Menu" id="Label2" ForeColor="#ff3366" />
                    <asp:Menu id="Menu1" DataSourceID="SiteMapDataSource1" Runat=Server />                
                </td>
             </tr>
           <tr>
                <td><br /></td> 
           </tr>              
             <tr>
                <td>
                    <asp:Label Runat=server Text="TreeView" id="Label3" ForeColor="#ff3366" />                
                    <asp:TreeView ID="TreeView1" DataSourceID="SiteMapDataSource1" Runat=Server />
                </td>
            </tr>
            <tr>
                <td><br /></td> 
           </tr>              
             <tr>
                <td>
                    The current virtual path for the request is:<b> <% Response.Write(Request.Path); %></b>.
                    <br />
                    The value of the category querystring variable is:<b> <% Response.Write(Server.HtmlEncode(Request.QueryString["category"])); %></b>.
                    <br />                    
                    However, the original path that was requested before it was remapped is:<b> <% Response.Write(Request.RawUrl); %></b>.
                </td>
            </tr>            
        </table>
    </div>
    </form>
</body>
</html>
