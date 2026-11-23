<%@ Page Language="C#" %>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<script runat="server">

  protected void LinkButton1_Click(object sender, EventArgs e)
  {
    if (!Panel1.Visible)
    {
      Panel1.Visible = true;
      LinkButton1.Text = "Hide Panel";
      TextBox4.Focus();
    }
    else
    {
      Panel1.Visible = false;
      LinkButton1.Text = "Show Panel";
      Page.SetFocus(TextBox1);
    }
  }

  protected void Button2_Click(object sender, EventArgs e)
  {
    Label1.Text = "Hello " + TextBox4.Text;
  }
  
</script>
<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
  <title>Focus API, DefaultButton, DefaultFocus, and SetFocusOnError</title>
</head>
<body>
  <form id="form1" DefaultButton="Button1" DefaultFocus="TextBox2" runat="server">
    <div>
    <h3>Focus API, DefaultButton, DefaultFocus, and SetFocusOnError</h3>
      TextBox 1:
      <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
      <asp:RequiredFieldValidator SetFocusOnError="true" ErrorMessage="TextBox1 is empty"
        ID="RequiredFieldValidator1" ControlToValidate="TextBox1" Display="Dynamic" runat="server">*</asp:RequiredFieldValidator>
      <br />
      TextBox 2:
      <asp:TextBox ID="TextBox2" runat="server"></asp:TextBox>
      <asp:RequiredFieldValidator SetFocusOnError="true" ErrorMessage="TextBox2 is empty"
        ID="RequiredFieldValidator2" ControlToValidate="TextBox2" Display="Dynamic" runat="server">*</asp:RequiredFieldValidator>
      &lt;-- notice the cursor starts here
      <br />
      TextBox 3:
      <asp:TextBox ID="TextBox3" runat="server"></asp:TextBox>
      <asp:RequiredFieldValidator SetFocusOnError="true" ErrorMessage="TextBox3 is empty"
        ID="RequiredFieldValidator3" ControlToValidate="TextBox3" Display="Dynamic" runat="server">*</asp:RequiredFieldValidator>
      <br />
      <br />
      <asp:Button ID="Button1" runat="server" Text="Submit" />
      <br />
      <br />
      <asp:ValidationSummary ID="ValidationSummary1" runat="server" />
      <asp:LinkButton ID="LinkButton1" CausesValidation="false" OnClick="LinkButton1_Click" runat="server">Show Panel</asp:LinkButton><br />
      <br />
      <asp:Panel Visible="false" DefaultButton="Button2" ID="Panel1" runat="server" Width="125px">
        Enter Your Name:
        <asp:TextBox ID="TextBox4" runat="server"></asp:TextBox><br />
        <br />
        <asp:Button ID="Button2" CausesValidation="false"  runat="server" Text="Go" OnClick="Button2_Click" />
        <br />
        <br />
        <asp:Label ID="Label1" runat="server"></asp:Label><br />
      </asp:Panel>
      <br />
    </div>
  </form>
</body>
</html>
