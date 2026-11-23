<%@ Page Language="VB" %>
<script runat="server">

  Protected Sub DetailsView1_DataBound(sender As Object, e As EventArgs)

    If DetailsView1.CurrentMode = DetailsViewMode.Edit Then
      DetailsView1.Focus()
    End If
  End Sub

</script>
<html>
<head id="Head1" runat="server">
  <title>Set Focus to DetailsView</title>
</head>
<body text="#00b">
  <form id="form1" runat="server">
    <h3>Focus to a Composite Control (DetailsView)</h3>
    Enter a state (CA, IN or UT):<br /><br />
    <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
    <asp:Button ID="Button1" runat="server" Text="Submit" /><br />
    <br />
    <asp:DetailsView DataSourceID="SqlDataSource1" AllowPaging="true" Height="50px" ID="DetailsView1" DataKeyNames="au_id" runat="server"
      Width="275px" Font-Size="0.8em" HeaderText="Details..." OnDataBound="DetailsView1_DataBound">
      <Fields>
        <asp:CommandField ShowEditButton="True" />
      </Fields>
      <HeaderStyle Font-Bold="True" />
      <PagerStyle Font-Size=".7em" />
      <FooterTemplate>
        <br />Click the Edit button and notice that the first input control in DetailsView gets focus<br /><br />
      </FooterTemplate>
    </asp:DetailsView>
    <asp:SqlDataSource ID="SqlDataSource1" runat="server" SelectCommand="SELECT [au_id], [au_lname], [au_fname], [phone], [address], [city], [state], [zip], [contract] FROM [authors] where state = @state"
      UpdateCommand="UPDATE [authors] SET [au_lname] = @au_lname, [au_fname] = @au_fname, [phone] = @phone, [address] = @address, [city] = @city, [state] = @state, [zip] = @zip, [contract] = @contract WHERE [au_id] = @au_id"
      ConnectionString="<%$ ConnectionStrings:Pubs %>">
      <SelectParameters>
        <asp:ControlParameter Name="state" ControlID="TextBox1" />
      </SelectParameters>
    </asp:SqlDataSource>
  </form>
</body>
</html>
