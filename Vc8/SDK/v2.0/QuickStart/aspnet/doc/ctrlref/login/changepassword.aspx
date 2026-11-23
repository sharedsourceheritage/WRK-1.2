<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.ChangePassword" runat="server">
  ChangePassword
</Acme:TypeRef>
</h2>

The ChangePassword control provides the functionality to confirm a user's existing password prior to executing the password change.  In the case where the user is not already authenticated on the web site, their identity is confirmed and their password changed and they are automatically logged into the website. Since the user has entered the new password, there is no requirement to send that new password in email, however the control supports the option to send the user a confirmation email. 
<br/><br/>
<B>Security Note:</B> It may be possible for the email containing the user's password to be intercepted by hackers and thus compromise the user's account. 

The ChangePassword control uses the <asp:hyperlink navigateurl ="~/aspnet/doc/security/default.aspx"    runat="server"> Membership service </asp:hyperlink>  to retrieve or reset the user's password. The default Membership provider from your configuration file will be used automatically, however you can also set the Membership provider as a property on the control. 

The ChangePassword control consists of two discrete views which are displayed to the user sequentially.  The ChangePassword view is the first view shown to the user and it collects and processes the current password, new password, confirmation of new password and optionally the username (this is required if the user is not currently authenticated). The Success view is an optional view that is displayed when the password has been successfully changed. In addition to the success view the control supports redirecting the user to new page if they are successful instead of displaying the success view.  Key elements of the  ChangePassword Control are:
<ul>
<li> <b>Username Label and Textbox: </b>Collects the string used to identify the user in the membership system. If not displayed in the control the current user's identity will be used, if the user is not authenticated the attempt to change the password will always fail. </li> 
<li> <b>Password label and  Textbox: </b>Collects the user current password.</li>
<li> <b>New Password label and  Textbox: </b>Collects the new password the user would like to set.</li>
<li> <b>Confirm New Password label and  Textbox: </b>Uses a compare validator to confirm that this entry and the new password value are the same. <b>Note: </b> If the control is templated and the compare validator is removed, this comparison is not done and the value of the new password textbox is always sent to the membership service.</li>
<li> <b>ChangePasswordButton: </b> The button that initiates changing the password. </li>
<li> <b>SuccessText : </b> Text displayed when the password has been successfully reset. </li>
<li> <b>Title (ChangePassword and Success views) and Instruction (ChangePassword view): </b> Text to orient and guide the user through the process. </li>
<li> <b>Links: </b> Configurable link to Help, CreateUser, PasswordRecovery and Profile information. </li>
<li> <b>Validators: </b> Required field validators, and a compare validator for the new password and confirm new password textboxes. </li>
</ul>
In addition to the visual elements displayed to the user on the web site, the ChangePassword control also contains a <code>MailDefintion</code> that determines the content of the email that is sent to the user.  The ChangePassword control does not contains a default email message but you can add your own text or html file to be used as the body of the message. If you are creating your own email file the control will automatically insert the user's username and password for the following strings: <code> &lt&#37UserName&#37&gt  &lt&#37Password&#37&gt </code> in the designated email file.

<h3>Simple ChangePassword Sample </h3>
This sample demonstrates the basic ChangePassword functionality when a user is already authenticated on the website. 
<br/><br/>


<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/CreateUser_cs/ChangePasswordBasic_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/ChangePasswordBasic.src"
        Caption="C# ChangePassword"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/CreateUser_vb/ChangePasswordBasic_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/ChangePasswordBasic.src"
        Caption="VB ChangePassword"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

<h3>ChangePassword Behaviors </h3>
There are a variety of ways to customize the ChangePassword control to meet your needs. Some of the means of customization are: 
<ul>
<li> <b>UserName: </b>The textbox where the user will enter their account name. </li> 
<li> <b>PasswordHint: </b>Provides text relative to the new password textbox to help users pick a secure and valid password. For example, must be 7 characters and contain 1 non-alphabetic character.</li> 
<li> <b>SuccessPageUrl: </b>Determines what web page a user will be redirected to when their password is successfully changed. If there is a SuccessPasswordUrl, the user will not be shown the Success view of the control. </li> 
<li> <b>CancelDestinationPageUrl: </b>Determines the web page that a user will be shown when they click on the Cancel button. </li> 
<li> <b>Links: </b>Displaying icons and links to other information and tasks.</li> 
</ul>

<h3>ChangePassword Behaviors Sample</h3>
This sample demonstrates how to set a CancelDestinationPageUrl and SuccessPageUrl. This sample also enables non-authenticated users to change their password after verifying their current password. You will also notice that the optional Help and Profile links are displayed within the control.
<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/CreateUser_cs/ChangePasswordBehaviors_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/ChangePasswordBehaviors.src"
        Caption="C# ChangePassword Behaviors"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/CreateUser_vb/ChangePasswordBehaviors_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/ChangePasswordBehaviors.src"
        Caption="VB ChangePassword Behaviors"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

<h3>ChangePassword Styles </h3>
The ChangePassword control supports customizing the look of the control through a series of style properties that control different parts of the control. 

<ul>
<li><b><i>Control</i> Style:</b> Applies to all sections of the ChangePassword control and is merged with other styles set on the control.</li>
<li><b>Label Style:</b> Applies to the username and different password labels.</li>
<li><b>TextboxStyle:</b> Applies to the textboxes.</li>
<li><b>TitleTextStyle:</b> Applies to the title text on both views.</li>
<li><b>SuccessTextStyle:</b> Applies to the text on the success views.</li>
<li><b>InstructionTextStyle:</b> Applies to the instruction text.</li>
<li><b>PasswordHintStyle:</b> Applies to the password hint text.</li>
<li><b>HyperlinkStyle:</b> Applies to all of the links.</li>
<li><b>ChangePasswordButtonStyle:</b> Applies to the ChangePassword button. </li>
<li><b>ContinueButtonStyle:</b> Applies to the Continue button. </li>
<li><b>CancelButtonStyle:</b> Applies to the Cancel button. </li>
<li><b>FailureTextStyle:</b> Applies to the text returned if the membership system fails to reset or retrieve the password. </li>
<li><b>ValidatorTextStyle:</b> Applies to the text displayed if the required field valuators fail. </li>
</ul>

<h3>ChangePassword Styles Sample</h3>
This sample demonstrates various style properties on the control. This sample also enables non-authenticated users to change their password after verifying their current password. This is particularly useful in systems that allow a user to have several screen accounts.
<br/> <br/>


<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/CreateUser_cs/ChangePasswordStyles_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/ChangePasswordStyles.src"
        Caption="C# ChangePassword Styles"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/CreateUser_vb/ChangePasswordStyles_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/ChangePasswordStyles.src"
        Caption="VB ChangePassword Styles"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

<h3>ChangePassword Templates </h3>
The ChangePassword control is a composite control which unites child controls (e.g. textboxes, buttons) and additional logic (calling Membership, handling errors) to implement the ChangePassword functionality.  For even more control over the display of the ChangePassword control you can template the control.  To ensure that the ChangePassword control continues to function when it is templated, your control must use well known control IDs or command names for some of the child controls. In addition to the key controls required for functionality (e.g. textboxes) additional controls with well known IDs are supported and will be automatically hooked up to the ChangePassword functionality. Here is a list of control IDs and command names that are used in template editing mode: 

<ul>
<li><b>ID=UserName</b></li>
<li><b>ID=CurrentPassword</b></li>
<li><b>ID=NewPassword</b></li>
<li><b>ID=ConfirmNewPassword</b></li>
<li><b>ID=FailureText</b> </li>
<li><b>CommandName=ChangePassword</b> This control can have any control ID but must support command bubbling.</li>
<li><b>CommandName=Continue</b> This control can have any control ID but must support command bubbling.</li>
<li><b>CommandName=Cancel</b> This control can have any control ID but must support command bubbling.</li>
</ul>

You can also add additional functionality to the ChangePassword control through templating. For example, you can collect additional information from the user by adding additional controls to the template or by adding additional client side validation of the textboxes.

<h3>ChangePassword FindControl Template Sample </h3>
This sample demonstrates a basic templated ChangePassword (no fancy styles) to show the correct control IDs and command names for key features of the ChangePassword control as well as how to programmatically find a control inside a template. Be sure to choose an account type when you are changing your password.
<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/CreateUser_cs/ChangePasswordTemplates_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/ChangePasswordTemplates.src"
        Caption="C# ChangePassword Templates"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/CreateUser_vb/ChangePasswordTemplates_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/ChangePasswordTemplates.src"
        Caption="VB ChangePassword Templates"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

</asp:Content>
