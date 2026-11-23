<%@ Page Language="VB" MasterPageFile="~/UserInfo.master"%>


<script runat="server">
  'Remove this code in production.
  'For sample purposes only we have canceled the email
  'that the PasswordRecovery control is attempting to send to the end user.
  Sub CancelEmail(ByVal sender As Object, ByVal e As MailMessageEventArgs)
    e.Cancel = True
  End Sub
        
</script>

<asp:Content ID="Content1" ContentPlaceHolderID="ContentPlaceHolder1" runat="server">
<h2>PasswordRecovery Behaviors Sample</h2>
        This sample demonstrates displaying the link to the help page, redirecting to 
        different page when the password retrieval has been successful and changing the
        email priority, and subject.
        <br />
        <br />
        <asp:PasswordRecovery ID="PasswordRecovery1" runat="server" HelpPageText="Help" 
          HelpPageUrl="~/PasswordRecoveryBehaviors.aspx" 
          SuccessPageUrl="~/SuccessPage.aspx" 
          OnSendingMail=CancelEmail BackColor="SeaShell" BorderColor="Sienna" 
          BorderPadding="4" BorderStyle="Solid" BorderWidth="1px" 
          Font-Names="Verdana">
            <MailDefinition Priority="High" Subject="Sending Per Your Request " 
              From="someone@example.com">
            </MailDefinition>
          <InstructionTextStyle Font-Italic="False" ForeColor="Black" />
          <SuccessTextStyle Font-Bold="True" ForeColor="#1C5E55" />
          <TitleTextStyle BackColor="Sienna" Font-Bold="True" ForeColor="White" />
          <SubmitButtonStyle BackColor="White" BorderColor="Sienna" 
            BorderStyle="Solid" BorderWidth="1px" Font-Names="Verdana" ForeColor="Sienna" />
        </asp:PasswordRecovery>
        <br /><br />
        <b>Sample Notes:</b>
  <ul>
    <li>The PasswordRecovery email is being cancelled for demonostration purposes.</li>
    <li>Close and reopen your browser or add a ? in the URL of your browser and press 
       enter to start the sample over again.</li>
    <li>The help link is pointing to the current page.</li>
    <li><b>SECURITY NOTE:</b> The most secure passwordFormat is hashed. The hashed option
        only supports enablePasswordReset. If you need to enablePasswordRetrieval the 
        most secure format is encrypted. Encrypting your password requires a pre-defined
        machinekey. To enable these samples to run on all machines without machine key 
        configuration and with a consistent password we are using the clear password 
        format. In production you should change this setting in the Membership provider
        in web.config.</li></ul>
   </asp:Content>