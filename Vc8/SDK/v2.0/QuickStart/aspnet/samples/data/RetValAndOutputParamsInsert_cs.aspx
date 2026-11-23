<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script runat="server">

  void SqlDataSource1_Selected(Object sender, System.Web.UI.WebControls.SqlDataSourceStatusEventArgs e) {
    
    foreach (System.Data.SqlClient.SqlParameter param in e.Command.Parameters) {
      Response.Write(Server.HtmlEncode(param.ParameterName) + "=");
      Response.Write(Server.HtmlEncode(param.Value.ToString()) + " (");
      Response.Write(Server.HtmlEncode(param.Value.GetType().ToString()) + ")<br />");
    }
  }

  void SqlDataSource1_Inserted(Object sender, System.Web.UI.WebControls.SqlDataSourceStatusEventArgs e) {
    Response.Write("Record Inserted: " + Server.HtmlEncode(e.Command.Parameters["@ContactID"].Value.ToString()) + "<br/>");
  }
</script>

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>Return Values and Output Parameters</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
      <asp:GridView AutoGenerateColumns="False" DataKeyNames="ContactID" DataSourceID="SqlDataSource1"
        ID="GridView1" runat="server">
        <Columns>
          <asp:CommandField ShowDeleteButton="True" />
          <asp:BoundField DataField="ContactID" HeaderText="ContactID" InsertVisible="False"
            ReadOnly="True" SortExpression="ContactID" />
          <asp:BoundField DataField="ContactName" HeaderText="ContactName" SortExpression="ContactName" />
        </Columns>
      </asp:GridView>
      <asp:SqlDataSource ConnectionString="<%$ ConnectionStrings:Contacts %>" ID="SqlDataSource1"
        runat="server" SelectCommand="GetContactsRetValAndOutParams" SelectCommandType="StoredProcedure" OnSelected="SqlDataSource1_Selected" InsertCommand="InsertContact" InsertCommandType="StoredProcedure" OnInserted="SqlDataSource1_Inserted" DeleteCommand="DELETE FROM Contacts WHERE ContactID = @ContactID">
        <SelectParameters>
          <asp:Parameter Direction="ReturnValue" Name="ReturnValue" Type="Int32"/>
          <asp:Parameter Direction="Output" Name="TimeStamp" Type="DateTime" />
        </SelectParameters>
        <InsertParameters>
          <asp:Parameter Name="contactName" Type="String" />
          <asp:Parameter Direction="Output" Name="contactID" Type="Int32" />
        </InsertParameters>
        <DeleteParameters>
          <asp:Parameter Name="ContactID" />
        </DeleteParameters>
      </asp:SqlDataSource>
      <br />
      <asp:DetailsView AutoGenerateRows="False" DataKeyNames="ContactID" DataSourceID="SqlDataSource1"
        DefaultMode="Insert" HeaderText="Insert New Contact" Height="50px" ID="DetailsView1"
        runat="server" Width="125px">
        <Fields>
          <asp:BoundField DataField="ContactID" HeaderText="ContactID" InsertVisible="False"
            ReadOnly="True" SortExpression="ContactID" />
          <asp:BoundField DataField="ContactName" HeaderText="ContactName" SortExpression="ContactName" />
          <asp:CommandField ShowInsertButton="True" />
        </Fields>
      </asp:DetailsView>
    
    </div>
    </form>
</body>
</html>
