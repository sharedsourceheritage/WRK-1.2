<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script language="C#" runat="server">
  void GetFavoriteNumberOnActiveStepIndex(Object Sender, EventArgs e)
  {
    Label1.Text = "Thank you for telling that your favorite number is:" + DropDownList1.SelectedItem.Text;
  }
</script>

<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
  <title>Simple Single-Step Wizard Control</title>
</head>
<body>
  <form id="form1" runat="server">
    <div>
      <h2>Simple Single-Step Wizard Control</h2>
      <asp:Wizard ID="Wizard1" runat="server" ActiveStepIndex="0" OnActiveStepChanged="GetFavoriteNumberOnActiveStepIndex"
        BackColor="#FFFBD6" BorderColor="#FFDFAD" BorderWidth="1px" CellPadding="5" Font-Names="Verdana"
        Font-Size="0.8em" Width="322px">
        <WizardSteps>
          <asp:WizardStep ID="WizardStep1" runat="server" Title="Step 1">
            <strong>Wizard Step 1</strong>
            <br /><br />
            Favorite Number:
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
          <asp:WizardStep ID="WizardStep2" runat="server" Title="Step 2" StepType="Complete">
            <strong>Wizard Step 2</strong><br />
            <br />
            <asp:Label ID="Label1" runat="server"/>
          </asp:WizardStep>
        </WizardSteps>
        <SideBarStyle Width="75px" VerticalAlign="Top"/>
      </asp:Wizard>
    </div>
  </form>
</body>
</html>
