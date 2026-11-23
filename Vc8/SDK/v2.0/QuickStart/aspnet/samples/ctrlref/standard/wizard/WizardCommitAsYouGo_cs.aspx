<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script language="C#" runat="server">
  void GetFavoriteNumerOnActiveStepIndex(Object Sender, EventArgs e)
  {
    if (Wizard1.ActiveStepIndex >= 1)
      Label1.Text = "The value selected on Step 1 is: " + DropDownList1.SelectedItem.Text;
    if (Wizard1.ActiveStepIndex >= 2)
      Label2.Text = "The value selected on Step 2 is: " + DropDownList2.SelectedItem.Text;
    if (Wizard1.ActiveStepIndex >= 3)
      Label3.Text = "The value selected on Step 3 is: " + DropDownList3.SelectedItem.Text;
  }
  void GetAllValues(object sender, WizardNavigationEventArgs e)
  {
    Label4.Text = "The value selected on Step 1 is: " + DropDownList4.SelectedItem.Text;
    Label5.Text = "The value selected on Step 2 is: " + DropDownList5.SelectedItem.Text;
    Label6.Text = "The value selected on Step 3 is: " + DropDownList6.SelectedItem.Text;
  }
 
</script>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
  <title>Wizard Commit Model Samples</title>
</head>
<body>
  <form id="form1" runat="server">
    <div>
      <br />
      <h2>
        Wizard Commitment Model Samples</h2>
      <table id="TABLE1" language="javascript">
        <tr>
          <td bgcolor="#eff3fb" valign="top">
            <b>Wizard Commit As You Go Sample</b><br />
            Select items on each step and click the next button. Notice that your selection
            is written out to a label each time you click a next button and that no previous
            button is displayed because the AllowReturn=False is set for each step.</td>
          <td>
          </td>
          <td bgcolor="#fffbd6" valign="top">
            <b>Wizard Commit At the End Sample</b><br />
            Select an item on each step and click the next or finish button. Notice that all
            of your selections are written out to labels after you click the finish button on
            the final wizard step. You can also click the previous button and change your selection.</td>
        </tr>
        <tr>
          <td bgcolor="#eff3fb">
            <asp:Wizard ID="Wizard1" runat="server" ActiveStepIndex="0" Width="322px" OnActiveStepChanged="GetFavoriteNumerOnActiveStepIndex"
              BackColor="#EFF3FB" BorderColor="#B5C7DE" BorderWidth="1px" Font-Names="Verdana"
              CellPadding="5">
              <WizardSteps>
                <asp:WizardStep runat="server" Title="Step 1" AllowReturn="False">
                  Wizard Step 1<br />
                  <br />
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
                <asp:WizardStep runat="server" Title="Step 2" AllowReturn="False">
                  Favorite Color: &nbsp;<asp:DropDownList ID="DropDownList2" runat="server">
                    <asp:ListItem>Red</asp:ListItem>
                    <asp:ListItem>Blue</asp:ListItem>
                    <asp:ListItem>Green</asp:ListItem>
                    <asp:ListItem>Purple</asp:ListItem>
                    <asp:ListItem>Black</asp:ListItem>
                    <asp:ListItem>Brown</asp:ListItem>
                    <asp:ListItem>Pink</asp:ListItem>
                    <asp:ListItem>Orange</asp:ListItem>
                    <asp:ListItem>Yellow</asp:ListItem>
                  </asp:DropDownList>
                </asp:WizardStep>
                <asp:WizardStep AllowReturn="False" ID="Step3" runat="server" Title="Step 3" StepType="Step">
                  Favorite Sport:
                  <asp:DropDownList ID="DropDownList3" runat="server">
                    <asp:ListItem>Soccer</asp:ListItem>
                    <asp:ListItem>Baseball</asp:ListItem>
                    <asp:ListItem>Football</asp:ListItem>
                    <asp:ListItem>Hockey</asp:ListItem>
                    <asp:ListItem>Basketball</asp:ListItem>
                    <asp:ListItem>Tennis</asp:ListItem>
                    <asp:ListItem>Rugby</asp:ListItem>
                    <asp:ListItem>Cricket</asp:ListItem>
                  </asp:DropDownList>
                </asp:WizardStep>
                <asp:WizardStep ID="Complete" runat="server" Title="Complete " StepType="Complete">
                  <br />
                  Thank you for completing this survey.<br />
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
          </td>
          <td>
          </td>
          <td bgcolor="#fffbd6">
            <asp:Wizard ID="Wizard2" runat="server" ActiveStepIndex="0" Width="322px" OnFinishButtonClick="GetAllValues"
              BackColor="#FFFBD6" BorderColor="#FFDFAD" BorderWidth="1px" Font-Names="Verdana"
              Font-Size="0.8em" CellPadding="5">
              <WizardSteps>
                <asp:WizardStep runat="server" Title="Step 1">
                  Wizard Step 1<br />
                  <br />
                  Favorite Number:
                  <asp:DropDownList ID="DropDownList4" runat="server">
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
                  Favorite Color: &nbsp;<asp:DropDownList ID="DropDownList5" runat="server">
                    <asp:ListItem>Red</asp:ListItem>
                    <asp:ListItem>Blue</asp:ListItem>
                    <asp:ListItem>Green</asp:ListItem>
                    <asp:ListItem>Purple</asp:ListItem>
                    <asp:ListItem>Black</asp:ListItem>
                    <asp:ListItem>Brown</asp:ListItem>
                    <asp:ListItem>Pink</asp:ListItem>
                    <asp:ListItem>Orange</asp:ListItem>
                    <asp:ListItem>Yellow</asp:ListItem>
                  </asp:DropDownList>
                </asp:WizardStep>
                <asp:WizardStep runat="server" Title="Step 3">
                  Favorite Sport:
                  <asp:DropDownList ID="DropDownList6" runat="server">
                    <asp:ListItem>Soccer</asp:ListItem>
                    <asp:ListItem>Baseball</asp:ListItem>
                    <asp:ListItem>Football</asp:ListItem>
                    <asp:ListItem>Hockey</asp:ListItem>
                    <asp:ListItem>Basketball</asp:ListItem>
                    <asp:ListItem>Tennis</asp:ListItem>
                    <asp:ListItem>Rugby</asp:ListItem>
                    <asp:ListItem>Cricket</asp:ListItem>
                  </asp:DropDownList>
                </asp:WizardStep>
                <asp:WizardStep runat="server" StepType="Complete" Title="Complete ">
                  <br />
                  Thank you for completing this survey.<br />
                </asp:WizardStep>
              </WizardSteps>
              <SideBarStyle BackColor="#990000" Font-Size="0.9em" VerticalAlign="Top" />
              <NavigationButtonStyle BackColor="White" BorderColor="#CC9966" BorderStyle="Solid"
                BorderWidth="1px" Font-Names="Verdana" Font-Size="0.8em" ForeColor="#990000" />
              <SideBarButtonStyle ForeColor="White" />
              <HeaderStyle BackColor="#FFCC66" BorderColor="#FFFBD6" BorderStyle="Solid" BorderWidth="2px"
                Font-Bold="True" Font-Size="0.9em" ForeColor="#333333" HorizontalAlign="Center" />
            </asp:Wizard>
          </td>
        </tr>
        <tr>
          <td bgcolor="#eff3fb">
            <asp:Label ID="Label1" runat="server"></asp:Label><br />
            <br />
            <asp:Label ID="Label2" runat="server"></asp:Label><br />
            <br />
            <asp:Label ID="Label3" runat="server"></asp:Label></td>
          <td>
          </td>
          <td bgcolor="#fffbd6">
            <asp:Label ID="Label4" runat="server"></asp:Label><br />
            <br />
            <asp:Label ID="Label5" runat="server"></asp:Label><br />
            <br />
            <asp:Label ID="Label6" runat="server"></asp:Label></td>
        </tr>
      </table>
      <br />
      <br />
      &nbsp;<br />
      <br />
      <br />
      <br />
      &nbsp; &nbsp;&nbsp;<br />
      <br />
      &nbsp;<br />
      <br />
      &nbsp;<br />
      <br />
      <br />
      <br />
    </div>
  </form>
</body>
</html>
