<%@ Page Language="C#" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script language="C#" runat="server">
  void GetFavoriteNumerOnActiveStepIndex(Object Sender, EventArgs e)
  {
    Label1.Text = "Thank you for telling me that your favorite number is: " + DropDownList1.SelectedItem.Text;
  }

</script>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
  <title>Wizard Templates Sample</title>
</head>
<body>
  <form id="form1" runat="server">
    <h2>
      Wizard Templates Sample</h2>
    Navigate through all of the WizardSteps to see the different templates.<br />
    <br />
    <div>
      <asp:Wizard ID="Wizard1" runat="server" HeaderText=" My Title" ActiveStepIndex="0"
        Width="322px" OnActiveStepChanged="GetFavoriteNumerOnActiveStepIndex" CellSpacing="5">
        <WizardSteps>
          <asp:WizardStep runat="server" Title="Step 1">
            Wizard Step Area<br />
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
            <br />
          </asp:WizardStep>
          <asp:WizardStep runat="server" Title="Step 2">
            Wizard Step Area<br />
            <br />
            <asp:Label ID="Label1" runat="server"></asp:Label><br />
            <br />
          </asp:WizardStep>
          <asp:WizardStep runat="server" Title="Step 3">
            Wizard Step Area<br />
            <br />
            Thank you for completing this survey.<br />
            <br />
          </asp:WizardStep>
        </WizardSteps>
        <HeaderTemplate>
          <i>Header Template<br />
            <b>
              <%= Wizard1.ActiveStep.Title %>
              of 3</b></i><br />
          <br />
        </HeaderTemplate>
        <SideBarTemplate>
          <i>SideBar Template</i>
          <br />
          <br />
          <asp:DataList ID="SideBarList" runat="server">
            <SelectedItemStyle Font-Bold="True" />
            <ItemTemplate>
              <asp:Button ID="SideBarButton" runat="server"></asp:Button>
            </ItemTemplate>
          </asp:DataList><br />
        </SideBarTemplate>
        <StartNavigationTemplate>
          <asp:LinkButton CommandName="MoveNext" ID="StartNextButton" runat="server" Text="Next" />
          <br />
          <i>Start Navigation Template</i>
        </StartNavigationTemplate>
        <StepNavigationTemplate>
          <asp:LinkButton CausesValidation="False" CommandName="MovePrevious" ID="StepPreviousButton"
            runat="server" Text="Previous" />
          <asp:LinkButton CommandName="MoveNext" ID="StepNextButton" runat="server" Text="Next" />
          <br />
          <i>Step Navigation Template</i>
        </StepNavigationTemplate>
        <FinishNavigationTemplate>
          <i>
            <br />
            Note: Removed all buttons from the Finish Navigation Template.</i>
        </FinishNavigationTemplate>
        <StepStyle Font-Names="Verdana" Font-Size="0.8em" />
        <SideBarStyle BackColor="OldLace" VerticalAlign="Top" />
        <HeaderStyle BackColor="Moccasin" />
        <NavigationStyle BackColor="PaleGoldenrod" />
      </asp:Wizard>
      &nbsp;&nbsp;<br />
      <b>Items to Note:</b><br />
      <ul>
        <li>The <b>Header Template</b> dynamically writes the active step to the text.<br />
        </li>
        <li>The <b>SideBar Template</b> uses Buttons instead of LinkButtons.<br />
        </li>
        <li>The <b>Start Navigation Template</b> uses LinkButtons instead of Buttons.<br />
        </li>
        <li>The <b>Step Navigation Template</b> uses LinkButtons instead of Buttons.<br />
        </li>
        <li>The <b>Finish Navigation Template</b> has removed all of the navigation buttons.<br />
        </li>
      </ul>
      <br />
      <br />
      <br />
    </div>
  </form>
</body>
</html>
