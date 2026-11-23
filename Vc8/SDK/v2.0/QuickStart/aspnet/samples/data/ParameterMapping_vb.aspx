<%@ Page Language="VB" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">

  Protected Sub SqlDataSource1_Updating(ByVal sender As Object, ByVal e As System.Web.UI.WebControls.SqlDataSourceCommandEventArgs)

    e.Command.Parameters("@id").Value = e.Command.Parameters("@ContactID").Value
    e.Command.Parameters("@name").Value = e.Command.Parameters("@ContactName").Value
    e.Command.Parameters.Remove(e.Command.Parameters("@ContactID"))
    e.Command.Parameters.Remove(e.Command.Parameters("@ContactName"))
  End Sub
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>Parameter Name Mapping</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
      <asp:GridView AutoGenerateColumns="False" DataKeyNames="ContactID" DataSourceID="SqlDataSource1"
        ID="GridView1" runat="server">
        <Columns>
          <asp:CommandField ShowEditButton="True" />
          <asp:BoundField DataField="ContactID" HeaderText="ContactID" InsertVisible="False"
            ReadOnly="True" SortExpression="ContactID" />
          <asp:BoundField DataField="ContactName" HeaderText="ContactName" SortExpression="ContactName" />
        </Columns>
      </asp:GridView>
      <asp:SqlDataSource ConnectionString="<%$ ConnectionStrings:Contacts %>" ID="SqlDataSource1"
        runat="server" SelectCommand="SELECT [ContactID], [ContactName] FROM [Contacts]"
        UpdateCommand="UpdateContactName" UpdateCommandType="StoredProcedure" OnUpdating="SqlDataSource1_Updating">
        <UpdateParameters>
          <asp:Parameter Name="id" Type="Int32" />
          <asp:Parameter Name="name" Type="String" />
        </UpdateParameters>
      </asp:SqlDataSource>
    
    </div>
    </form>
</body>
</html>
