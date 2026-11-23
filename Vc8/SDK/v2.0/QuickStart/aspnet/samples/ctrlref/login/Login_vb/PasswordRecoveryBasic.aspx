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
 <h2>
    Basic PasswordRecovery Sample</h2>
  <asp:PasswordRecovery ID="PasswordRecovery1" runat="server" OnSendingMail="CancelEmail"
    BackColor="#E3EAEB" BorderColor="#E6E2D8" BorderPadding="4" BorderStyle="Solid"
    BorderWidth="1px" Font-Names="Verdana">
    <MailDefinition From="someone@example.com">
    </MailDefinition>
    <SuccessTextStyle Font-Bold="True" ForeColor="#1C5E55" />
    <TitleTextStyle BackColor="#1C5E55" Font-Bold="True" ForeColor="White" />
    <SubmitButtonStyle BackColor="White" BorderColor="#C5BBAF" BorderStyle="Solid" 
      BorderWidth="1px" Font-Names="Verdana" ForeColor="#1C5E55" />
  </asp:PasswordRecovery>
  <br />
  <br />
  <b>Sample Notes:</b>
  <ul>
    <li>The PasswordRecovery email is being cancelled for demonostration purposes.</li>
    <li>Close and reopen your browser or add a ? in the URL of your browser and press 
       enter to start the sample over again.</li>
    <li><b>SECURITY NOTE:</b> The most secure passwordFormat is hashed. The hashed option
        only supports enablePasswordReset. If you need to enablePasswordRetrieval the 
        most secure format is encrypted. Encrypting your password requires a pre-defined
        machinekey. To enable these samples to run on all machines without machine key 
        configuration and with a consistent password we are using the clear password 
        format. In production you should change this setting in the Membership provider
        in web.config.</li>
  </ul>
   </asp:Content>