<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script language="C#" runat="server">

  void GetFavoriteNumberOnActiveStepIndex(Object Sender, EventArgs e)
  {
    Label1.Text = "Thank you for telling me that your favorite number is:" + DropDownList1.SelectedItem.Text;
  }

</script>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
  <title>Wizard Style Sample</title>
</head>
<body>
  <form id="form1" runat="server">
    <h2>
      Wizard Style Sample</h2>
    <div>
      <asp:Wizard ID="Wizard1" runat="server" ActiveStepIndex="0" Width="322px" OnActiveStepChanged="GetFavoriteNumberOnActiveStepIndex"
        BackColor="#EFF3FB" BorderColor="#B5C7DE" BorderWidth="1px" Font-Names="Verdana"
        HeaderText="This is a Header " CellPadding="5">
        <WizardSteps>
          <asp:WizardStep runat="server" Title="Step 1" StepType="Start">
            Wizard Step 1<br />
            <br />
            Favorite Numer:
            <asp:DropDownList ID="DropDownList1" runat="server">
              <asp:ListItem>1</asp:ListItem>
              <asp:ListItem>2</asp:ListItem>
              <asp:ListItem>3</asp:ListItem>
              <asp:ListItem>4</asp:ListItem>
              <asp:ListItem>5</asp:ListItem>
              <asp:ListItem>6</asp:ListItem>
              <asp:ListItem>7</asp:ListItem>
              <asp:ListItem>8</asp:ListItem>
              <asp:ListItem>9</asp:ListItem>
              <asp:ListItem>10</asp:ListItem>
            </asp:DropDownList>
            <br />
          </asp:WizardStep>
          <asp:WizardStep runat="server" Title="Step 2" StepType="Complete">
            <asp:Label ID="Label1" runat="server"></asp:Label>
          </asp:WizardStep>
        </WizardSteps>
        <StepStyle Font-Size="0.8em" ForeColor="#333333" />
        <SideBarStyle BackColor="#507CD1" Font-Size="0.9em" VerticalAlign="Top" />
        <NavigationButtonStyle BackColor="White" BorderColor="#507CD1" BorderStyle="Solid"
          BorderWidth="1px" Font-Names="Verdana" Font-Size="0.8em" ForeColor="#284E98" />
        <SideBarButtonStyle BackColor="#507CD1" Font-Names="Verdana" ForeColor="White" />
        <HeaderStyle BackColor="#284E98" BorderColor="#EFF3FB" BorderStyle="Solid" BorderWidth="2px"
          Font-Bold="True" Font-Size="0.9em" ForeColor="White" HorizontalAlign="Center" />
      </asp:Wizard>
      &nbsp;&nbsp;<br />
      <br />
      <br />
    </div>
  </form>
</body>
</html>
