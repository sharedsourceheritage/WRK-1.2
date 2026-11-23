<%@ Page Language="VB" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">

  Protected Sub ObjectDataSource1_Selected(ByVal sender As Object, ByVal e As ObjectDataSourceStatusEventArgs)
  
    Response.Write("Record Count: " & Server.HtmlEncode(e.OutputParameters("totalCount")))
  End Sub

  Protected Sub ObjectDataSource1_Updated(ByVal sender As Object, ByVal e As ObjectDataSourceStatusEventArgs)
  
    Response.Write("Rows Affected: " & Server.HtmlEncode(e.ReturnValue) & "<br/>")
  End Sub
  
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>Return Values and Output Parameters</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
      <asp:GridView DataSourceID="ObjectDataSource1" ID="GridView1" runat="server" AutoGenerateColumns="False" DataKeyNames="ContactID">
        <Columns>
          <asp:CommandField ShowEditButton="True" />
          <asp:BoundField DataField="ContactID" HeaderText="ContactID" ReadOnly="True" SortExpression="ContactID" />
          <asp:BoundField DataField="ContactName" HeaderText="ContactName" SortExpression="ContactName" />
        </Columns>
      </asp:GridView>
      <asp:ObjectDataSource ID="ObjectDataSource1" runat="server" SelectMethod="GetContacts"
        TypeName="ContactsList" UpdateMethod="UpdateContact" OnSelected="ObjectDataSource1_Selected" OnUpdated="ObjectDataSource1_Updated">
        <UpdateParameters>
          <asp:Parameter Name="ContactName" Type="String" />
        </UpdateParameters>
        <SelectParameters>
          <asp:Parameter Direction="Output" Name="totalCount" Type="Int32" />
        </SelectParameters>
      </asp:ObjectDataSource>
    
    </div>
    </form>
</body>
</html>
