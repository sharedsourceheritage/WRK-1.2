<%@ Page Language="VB" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<script runat="server">

  Protected Sub SqlDataSource1_Updated(sender As Object, e As SqlDataSourceStatusEventArgs)
  
    If e.AffectedRows = 0 Then
      Response.Write("Row changed, update aborted<br />")
    End If
  End Sub

  Protected Sub SqlDataSource1_Deleted(sender As Object, e As SqlDataSourceStatusEventArgs)

    If e.AffectedRows = 0 Then
      Response.Write("Row changed, delete aborted<br />")
    End If
  End Sub
  
</script>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
  <title>Optimistic Concurrency</title>
</head>
<body>
  <form id="form1" runat="server">
    <div>
      <asp:GridView AutoGenerateColumns="False" DataKeyNames="ContactID" DataSourceID="SqlDataSource1"
        ID="GridView1" runat="server">
        <Columns>
          <asp:CommandField ShowDeleteButton="True" ShowEditButton="True" />
          <asp:BoundField DataField="ContactID" HeaderText="ContactID" InsertVisible="False"
            ReadOnly="True" SortExpression="ContactID" />
          <asp:BoundField DataField="ContactName" HeaderText="ContactName" SortExpression="ContactName" />
        </Columns>
      </asp:GridView>
      <asp:SqlDataSource ConnectionString="<%$ ConnectionStrings:Contacts %>" ID="SqlDataSource1"
        ConflictDetection="CompareAllValues" OldValuesParameterFormatString="original_{0}" runat="server" SelectCommand="GetContactsRetValAndOutParams"
        SelectCommandType="StoredProcedure" InsertCommand="InsertContact" InsertCommandType="StoredProcedure"
        DeleteCommand="DeleteContact" DeleteCommandType="StoredProcedure" UpdateCommand="UpdateContact"
        UpdateCommandType="StoredProcedure" OnUpdated="SqlDataSource1_Updated" OnDeleted="SqlDataSource1_Deleted">
        <SelectParameters>
          <asp:Parameter Direction="ReturnValue" Name="ReturnValue" Type="Int32" />
          <asp:Parameter Direction="Output" Name="TimeStamp" Type="DateTime" />
        </SelectParameters>
        <InsertParameters>
          <asp:Parameter Name="contactName" Type="String" />
          <asp:Parameter Direction="Output" Name="contactID" Type="Int32" />
        </InsertParameters>
        <DeleteParameters>
          <asp:Parameter Name="original_ContactID" Type="Int32" />
          <asp:Parameter Name="original_contactName" Type="String" />
        </DeleteParameters>
        <UpdateParameters>
          <asp:Parameter Name="contactName" Type="String" />
          <asp:Parameter Name="original_contactID" Type="Int32" />
          <asp:Parameter Name="original_contactName" Type="String" />
        </UpdateParameters>
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
