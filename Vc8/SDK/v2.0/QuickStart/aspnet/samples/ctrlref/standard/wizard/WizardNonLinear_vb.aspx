<%@ Page Language="VB" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<script language="VB" runat="server">
  Sub SkipStep(ByVal sender As Object, ByVal e As WizardNavigationEventArgs)
    
    If e.CurrentStepIndex = 0 AndAlso Int32.Parse(DropDownList1.SelectedItem.Value) > 5 Then
      Wizard1.ActiveStepIndex = 2
    End If
  End Sub
    
    
  Sub GetFavoriteNumerOnActiveStepIndex(ByVal sender As Object, ByVal e As EventArgs)
    
    If Wizard1.ActiveStepIndex >= 1 Then
      Label1.Text = "The value selected on Step 1 is: " & DropDownList1.SelectedItem.Text
    End If
    If Wizard1.ActiveStepIndex >= 2 Then
      Label2.Text = "The value selected on Step 2 is: " & DropDownList2.SelectedItem.Text
    End If
    If Wizard1.ActiveStepIndex >= 3 Then
      Label3.Text = "The value selected on Step 3 is: " & DropDownList3.SelectedItem.Text
    End If
  End Sub
     
</script>

<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
  <title>Wizard NonLinear Navigation</title>
</head>
<body>
  <form id="form1" runat="server">
    <h2>
      Wizard Non-Linear Navigation Sample</h2>
    <div>
      In this sample, if the number that you select on the first step is greater then
      5 you will skip WizardStep 2 and go directly to WizardStep 3. Try selecting different
      numbers on the WizardStep 1 to see the different behaviors.&nbsp;<br />
      <br />
      Note: That when if you skip WizardStep 2 and click the previous button on WizardStep
      3 you will be returned to WizardStep 1 the previous step that you visited.<br />
      <br />
      <br />
      <asp:Wizard ID="Wizard1" runat="server" ActiveStepIndex="0" Width="322px" OnNextButtonClick="SkipStep"
        OnActiveStepChanged="GetFavoriteNumerOnActiveStepIndex" BackColor="#FFFBD6" BorderColor="#FFDFAD"
        BorderWidth="1px" CellPadding="5" Font-Names="Verdana" Font-Size="0.8em" DisplaySideBar="False">
        <WizardSteps>
          <asp:WizardStep ID="WizardStep1" runat="server" Title="Step 1">
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
          <asp:WizardStep ID="WizardStep2" runat="server" Title="Step 2">
            WizardStep 2<br />
            <br />
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
          <asp:WizardStep ID="Step3" runat="server" Title="Step 3">
            WizardStep 3<br />
            <br />
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
          <asp:WizardStep ID="Complete" runat="server" StepType="Complete" Title="Complete ">
            <br />
            Thank you for completing this survey.<br />
          </asp:WizardStep>
        </WizardSteps>
      </asp:Wizard>
      &nbsp; &nbsp;<br />
      <br />
      <asp:Label ID="Label1" runat="server"></asp:Label>
      <br />
      <br />
      <asp:Label ID="Label2" runat="server"></asp:Label>
      <br />
      <br />
      <asp:Label ID="Label3" runat="server"></asp:Label>
      <br />
    </div>
  </form>
</body>
</html>
