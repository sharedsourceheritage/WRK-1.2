<%@ Page Language="VB" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">

Protected Sub SqlDataSource1_Selected(ByVal sender As Object, ByVal e As System.Web.UI.WebControls.SqlDataSourceStatusEventArgs)
    If Not e.Exception Is Nothing Then
    
      Response.Write("In order to run this sample, the ASP.NET process account (either the local ASPNET or Network Service account, by default) ")
      Response.Write("needs read/write permission to the ~/App_Data/Database.mdf and ~/App_Data/Database_log.ldf files in the sample directory")
      e.ExceptionHandled = True
    End If
  End Sub
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>SQL Server Express Local Databases</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
      <asp:GridView AllowSorting="True" AutoGenerateColumns="False" DataKeyNames="ContactID" DataSourceID="SqlDataSource1"
        ID="GridView1" runat="server">
        <Columns>
          <asp:BoundField DataField="ContactID" HeaderText="ID" ReadOnly="True" SortExpression="ID" />
          <asp:BoundField DataField="ContactName" HeaderText="Name" SortExpression="Name" />
        </Columns>
      </asp:GridView>
      <asp:SqlDataSource ConnectionString="<%$ ConnectionStrings:ContactsDatabase %>" ID="SqlDataSource1"
        runat="server" SelectCommand="SELECT [ContactID], [ContactName] FROM [Contacts]" OnSelected="SqlDataSource1_Selected"></asp:SqlDataSource>
    </div>
    </form>
</body>
</html>
