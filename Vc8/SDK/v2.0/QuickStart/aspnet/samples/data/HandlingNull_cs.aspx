<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>EmptyDataTemplate, NullDisplayText, DefaultValue, and ConvertEmptyStringToNull</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
      <strong>View contacts that begin with:</strong><br />
      <br />
      <asp:ListBox AutoPostBack="True" ID="ListBox1" runat="server" Width="114px">
        <asp:ListItem Selected="true">A</asp:ListItem>
        <asp:ListItem>B</asp:ListItem>
        <asp:ListItem>C</asp:ListItem>
        <asp:ListItem>D</asp:ListItem>
        <asp:ListItem>E</asp:ListItem>
        <asp:ListItem>F</asp:ListItem>
        <asp:ListItem>G</asp:ListItem>
        <asp:ListItem>H</asp:ListItem>
        <asp:ListItem>I</asp:ListItem>
        <asp:ListItem>J</asp:ListItem>
        <asp:ListItem>K</asp:ListItem>
        <asp:ListItem>L</asp:ListItem>
        <asp:ListItem>M</asp:ListItem>
        <asp:ListItem>N</asp:ListItem>
        <asp:ListItem>O</asp:ListItem>
        <asp:ListItem>P</asp:ListItem>
        <asp:ListItem>Q</asp:ListItem>
        <asp:ListItem>R</asp:ListItem>
        <asp:ListItem>S</asp:ListItem>
        <asp:ListItem>T</asp:ListItem>
        <asp:ListItem>U</asp:ListItem>
        <asp:ListItem>V</asp:ListItem>
        <asp:ListItem>W</asp:ListItem>
        <asp:ListItem>X</asp:ListItem>
        <asp:ListItem>Y</asp:ListItem>
        <asp:ListItem>Z</asp:ListItem>
      </asp:ListBox><br />
      <br />
      <asp:DetailsView AutoGenerateRows="False" DataKeyNames="CustomerID" DataSourceID="SqlDataSource1"
        Height="50px" ID="DetailsView1" runat="server" Width="315px" AllowPaging="True">
        <Fields>
          <asp:BoundField DataField="ContactName" HeaderText="ContactName" SortExpression="ContactName" ReadOnly="true" />
          <asp:BoundField DataField="ContactTitle" HeaderText="ContactTitle" SortExpression="ContactTitle" />
          <asp:BoundField DataField="Region" HeaderText="Region" NullDisplayText="(NA)" SortExpression="Region" />
          <asp:BoundField DataField="Phone" HeaderText="Phone" NullDisplayText="not listed"
            SortExpression="Phone" />
          <asp:BoundField DataField="Fax" HeaderText="Fax" NullDisplayText="not listed" SortExpression="Fax" />
          <asp:CommandField ShowEditButton="True" />
        </Fields>
        <EmptyDataTemplate>
          <asp:Image ID="Image1" runat="server" ImageUrl="~/Images/warning.gif" />There are no records to display
        </EmptyDataTemplate>
      </asp:DetailsView>
      <asp:SqlDataSource ConnectionString="<%$ ConnectionStrings:Northwind %>" ID="SqlDataSource1"
        runat="server" SelectCommand="SELECT [CustomerID], [ContactName], [ContactTitle], [Region], [Phone], [Fax] FROM [Customers] WHERE ([ContactName] LIKE + @ContactName + '%')" 
        UpdateCommand="UPDATE [Customers] SET [ContactTitle] = @ContactTitle, [Region] = @Region, [Phone] = @Phone, [Fax] = @Fax WHERE [CustomerID] = @CustomerID">
        <UpdateParameters>
          <asp:Parameter Name="ContactName" Type="String" />
          <asp:Parameter Name="ContactTitle" Type="String" DefaultValue="Owner" ConvertEmptyStringToNull="true" />
          <asp:Parameter Name="Region" Type="String" ConvertEmptyStringToNull="true" />
          <asp:Parameter Name="Phone" Type="String" ConvertEmptyStringToNull="true" />
          <asp:Parameter Name="Fax" Type="String" ConvertEmptyStringToNull="true" />
          <asp:Parameter Name="CustomerID" Type="String" />
        </UpdateParameters>
        <SelectParameters>
          <asp:ControlParameter ControlID="ListBox1" Name="ContactName" PropertyName="SelectedValue"
            Type="String" />
        </SelectParameters>
      </asp:SqlDataSource>    
    </div>
    </form>
</body>
</html>
