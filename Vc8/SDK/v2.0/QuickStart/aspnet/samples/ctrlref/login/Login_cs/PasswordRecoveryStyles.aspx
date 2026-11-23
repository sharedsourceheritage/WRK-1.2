<%@ Page Language="C#" MasterPageFile="~/UserInfo.master" %>

<script runat="server">
  //Remove this code in production.
  // For sample purposes only we have canceled the email
  // that the PasswordRecovery control is attempting to send to the end user.
  void CancelEmail(Object sender, MailMessageEventArgs e)
  {
    e.Cancel = true;

  }

</script>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
  <h2>
    PasswordRecovery Style Sample</h2>
    Use the pre-created sample accounts listed below to test this functionality.
  <br /><br />
  <asp:PasswordRecovery ID="PasswordRecovery1" runat="server" BackColor="Lavender"
    BorderColor="MidnightBlue" BorderPadding="4" BorderStyle="Double" BorderWidth="1px"
    Font-Names="Verdana" OnSendingMail="CancelEmail" ForeColor="MidnightBlue">
    <InstructionTextStyle Font-Italic="False" />
    <SuccessTextStyle Font-Bold="True" Font-Italic="False" />
    <TitleTextStyle BackColor="MidnightBlue" BorderColor="MidnightBlue" BorderStyle="Double"
      BorderWidth="1px" ForeColor="White" Font-Bold="True" />
    <SubmitButtonStyle BackColor="#FFFBFF" BorderColor="SteelBlue" BorderStyle="Solid"
      BorderWidth="1px" Font-Names="Verdana" ForeColor="MidnightBlue"></SubmitButtonStyle>
    <MailDefinition From="someone@example.com" />
  </asp:PasswordRecovery>
  <br />
  <br />
  <b>Sample Notes:</b>
  <ul>
    <li>The PasswordRecovery email is being cancelled for demonostration purposes.</li>
    <li>Close and reopen your browser or add a ? in the URL of your browser and press 
       enter to start the sample over again.</li>
    <li>The help link is pointing to the current page.</li>
    <li><b>SECURITY NOTE:</b> The most secure passwordFormat is hashed. The hashed option
        only supports enablePasswordReset. If you need to enablePasswordRetrieval the most
        secure format is encrypted. Encrypting your password requires a pre-defined machinekey.
        To enable these samples to run on all machines without machine key configuration
        and with a consistent password we are using the clear password format. In production
        you should change this setting in the Membership provider in web.config.</li></ul>
</asp:Content>
