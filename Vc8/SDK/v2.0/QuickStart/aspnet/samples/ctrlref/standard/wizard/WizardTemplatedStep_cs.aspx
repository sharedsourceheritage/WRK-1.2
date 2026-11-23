<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script language="C#" runat="server">
  void GetDropDownListValuesOnActiveStepIndex(Object Sender, EventArgs e)
  {
    //This example demonostrates finding a control in a regular wizard step
    Label1.Text = "Values from regular WizardSteps:<br/> Favorite Number=" + DropDownList1.SelectedItem.Text + "<br/>Favorite Color = " + DropDownList2.SelectedItem.Text;

    //This example demonostrates finding a control in a templated wizard step 
    Label2.Text = "Values from Templated WizardStep:<br/> Favorite Sport: " + ((DropDownList)(MyTemplatedWizardStep.ContentTemplateContainer.FindControl("DropDownList3"))).SelectedItem.Text;
  }

</script>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
  <title>Wizard Templated Step Sample </title>
</head>
<body>
  <form id="form1" runat="server">
    <h2>
      Templated Wizard Step Sample</h2>
    This example demonostrates how finding a control inside a templated WizardStep is
    different from finding a control inside a regular WizardStep.
    <div>
      &nbsp;&nbsp;<br />
      <br />
      <br />
      <asp:Wizard ID="Wizard1" runat="server" ActiveStepIndex="0" Width="445px" OnActiveStepChanged="GetDropDownListValuesOnActiveStepIndex"
        BackColor="#FFFBD6" BorderColor="#FFDFAD" BorderWidth="1px" CellPadding="5" Font-Names="Verdana"
        Font-Size="0.8em">
        <WizardSteps>
          <asp:WizardStep runat="server" Title="Step 1">
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
          <asp:WizardStep runat="server" Title="Step 2">
            Wizard Step 2<br />
            <br />
            Favorite Color:
            <asp:DropDownList ID="DropDownList2" runat="server">
              <asp:ListItem>Red</asp:ListItem>
              <asp:ListItem>Blue</asp:ListItem>
              <asp:ListItem>Green</asp:ListItem>
              <asp:ListItem>Yellow</asp:ListItem>
              <asp:ListItem>Purple</asp:ListItem>
              <asp:ListItem>Pink</asp:ListItem>
              <asp:ListItem>Black</asp:ListItem>
              <asp:ListItem>White</asp:ListItem>
              <asp:ListItem>Brown</asp:ListItem>
              <asp:ListItem>Hazel</asp:ListItem>
              <asp:ListItem>Orange</asp:ListItem>
            </asp:DropDownList>
            <br />
          </asp:WizardStep>
          <asp:TemplatedWizardStep runat="server" ID="MyTemplatedWizardStep">
            <ContentTemplate>
              My Templated Wizard Step<br />
              <br />
              Favorite Sport:
              <asp:DropDownList ID="DropDownList3" runat="server">
                <asp:ListItem>Baseball</asp:ListItem>
                <asp:ListItem>Football</asp:ListItem>
                <asp:ListItem>Tennis</asp:ListItem>
              </asp:DropDownList>
              <br />
            </ContentTemplate>
          </asp:TemplatedWizardStep>
          <asp:WizardStep runat="server" StepType="Complete">
            Complete Wizard Step
            <br />
            <br />
            <asp:Label ID="Label1" runat="server"></asp:Label><br />
            <br />
            <asp:Label ID="Label2" runat="server"></asp:Label>
          </asp:WizardStep>
        </WizardSteps>
        <SideBarStyle BackColor="#990000" Font-Size="0.9em" VerticalAlign="Top" />
        <NavigationButtonStyle BackColor="White" BorderColor="#CC9966" BorderStyle="Solid"
          BorderWidth="1px" Font-Names="Verdana" Font-Size="0.8em" ForeColor="#990000" />
        <SideBarButtonStyle ForeColor="White" />
        <HeaderStyle BackColor="#FFCC66" BorderColor="#FFFBD6" BorderStyle="Solid" BorderWidth="2px"
          Font-Bold="True" Font-Size="0.9em" ForeColor="#333333" HorizontalAlign="Center" />
      </asp:Wizard>
    </div>
  </form>
</body>
</html>
