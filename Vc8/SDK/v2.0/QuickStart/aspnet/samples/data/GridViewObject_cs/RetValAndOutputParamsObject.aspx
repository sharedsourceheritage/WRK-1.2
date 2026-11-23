<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">

  protected void ObjectDataSource1_Selected(object sender, ObjectDataSourceStatusEventArgs e)
  {
    Response.Write("Record Count: " + Server.HtmlEncode(e.OutputParameters["totalCount"].ToString()));
  }

  protected void ObjectDataSource1_Updated(object sender, ObjectDataSourceStatusEventArgs e)
  {
    Response.Write("Rows Affected: " + Server.HtmlEncode(e.ReturnValue.ToString()) + "<br/>");
  }
  
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
