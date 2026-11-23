<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.PasswordRecovery" runat="server">
  PasswordRecovery
</Acme:TypeRef>
</h2>

The PasswordRecovery control provides the functionality to retrieve or reset a user's password based on their username. The information is then emailed to the user. The control does <b>not</b> support displaying the password to the user in their web browser.  <B>Security Note:</B> It may be possible for the email containing the user's password to be intercepted by hackers and thus compromise the user's account. 

The PasswordRecovery control uses the <asp:hyperlink navigateurl ="~/aspnet/doc/security/default.aspx"    runat="server"> Membership service </asp:hyperlink>  to retrieve or reset the user's password. The default Membership provider from your configuration file will be used automatically, however you can also set the Membership provider as a property on the control. The PasswordRecovery control honors the following Membership configuration settings:  
<ul>
<li> <code>requiresQuestionAndAnswer </code>When set to true the Question view will be required for the user's password to be retrieved or reset. When set to false the Question view is not displayed to the user. </li> 
<li> <code>passwordFormat </code>If the passwordFormat is set to hashed, the control will be unable to retrieve the password and will only attempt to reset the password. </li>
<li> <code>enablePasswordRetrieval </code>When set to false the control will attempt to reset the password. </li> 
<li> <code>enablePasswordReset </code>When set to true the password will be reset, if set to false and all retrieval options are also disallowed the control will be unable to recover the password for the user. </li> 
 </ul>

The PasswordRecovery control consists of three discrete views which are displayed to the user sequentially.  The Username view is the first view shown to the user and it collects and submits the user's name. The Question view is an optional view that is only displayed if the security question (e.g. pet's name) is required to retrieve or reset the password. The Success view is an optional view that is displayed when the password has been successfully retrieved or reset for the user. In addition to the success view the control supports redirecting the user to new page if they are successful.  Key elements of the  PasswordRecovery Control are:
<ul>
<li> <b>Username Label and Textbox: </b>Collects the string used to identify the user in the membership system.  </li> 
<li> <b>Question Label and Answer Textbox: </b>Displays the security confirmation question and collects the answer.</li>
<li> <b>SubmitButton: </b> The button that fires the user and question views. </li>
<li> <b>SuccessText : </b> Text displayed when the password has been successfully reset. </li>
<li> <b>Title and Instruction (Username and Success views): </b> Text to orient and guide the user through the process. </li>
<li> <b>Link: </b> Configurable link to help information. </li>
<li> <b>Validators: </b> Required field validators for the username and security answer textboxes. </li>
</ul>
In addition to the visual elements displayed to the user on the web site, the PasswordRecovery control also contains a <code>MailDefintion</code> that determines the content of the email that is sent to the user.  The PasswordRecovery control contains a default email message that is sent to the user, however you can customize this behavior and add your own text or html file to be used as the body of the message. If you are creating your own email file the control will automatically insert the user's username and password for the following strings: <code> &lt&#37UserName&#37&gt  &lt&#37Password&#37&gt </code> in the designated email file.
<br/><br/>

<b>Sample Notes:</b> 
<ul>
<li>For sample purposes the PasswordRecovery email is <b>not</b> sent in these samples.</li>
<li>The samples for this control use Master Pages to provide the information that is used to logon a user. For more information on <asp:hyperlink navigateurl ="~/aspnet/doc/masterpages/default.aspx"    runat="server"> Master Pages </asp:hyperlink>. </li>
<li><b>SECURITY NOTE:</b> The most secure passwordFormat is hashed. The hashed option only supports enablePasswordReset. If you need to enablePasswordRetrieval the most secure format is encrypted. Encrypting your password requires a pre-defined machinekey. To enable these samples to run on all machines without machine key configuration and with a consistent password we are using the clear password format. In production you should change this setting in the Membership provider in web.config.</li>
</ul>

<h3>Simple PasswordRecovery Sample </h3>
This sample demonstrates the basic PasswordRecovery control behavior when a security question is required by the Membership provider.
<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/Login_cs/PasswordRecoveryBasic.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/PasswordRecoveryBasic.src"
        Caption="C# PasswordRecovery"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/Login_vb/PasswordRecoveryBasic.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/PasswordRecoveryBasic.src"
        Caption="VB PasswordRecovery"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

<h3>PasswordRecovery Behaviors </h3>
There are a variety of ways to customize the PasswordRecovery control to meet your needs. Some of the means of customization are: 
<ul>
<li> <b>MailDefinition: </b>Change the mail message that is sent to your users with their retrieved or reset password. </li> 
<li> <b>TextLayout: </b>Determines if the text will be displayed on top of the textboxes or on the side. </li>
<li> <b>SuccessPageUrl: </b>Determines what web page a user will be redirected to when their password recovery is successful. If there is a SuccessPasswordUrl, the user will not be shown the Success view of the control. </li> 
<li> <b>HelpLink: </b>Displaying a help link and associated icon.</li> 
</ul>

<h3>PasswordRecovery Behaviors Sample</h3>
This sample demonstrates the SuccessPageUrl, setting some MailDefinition properties and displaying the HelpLink. 
<br/><br/>


<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/Login_cs/PasswordRecoveryBehaviors.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/PasswordRecoveryBehaviors.src"
        Caption="C# PasswordRecovery Behaviors"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/Login_vb/PasswordRecoveryBehaviors.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/PasswordRecoveryBehaviors.src"
        Caption="VB PasswordRecovery Behaviors"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />


<h3>PasswordRecovery Styles </h3>
The PasswordRecovery control supports customizing the look of the control through a series of style properties that control different parts of the control. 

<ul>
<li><b><i>Control</i> Style:</b> Applies to all sections of the PasswordRecovery control and is merged with other styles set on the control.</li>
<li><b>Label Style:</b> Applies to the username, question and answer labels.</li>
<li><b>TextboxStyle:</b> Applies to the username and question textboxes.</li>
<li><b>TitleTextStyle:</b> Applies to the title text on the different views.</li>
<li><b>SuccessTextStyle:</b> Applies to the text on the success views.</li>
<li><b>InstructionTextStyle:</b> Applies to the instruction text.</li>
<li><b>HyperlinkStyle:</b> Applies to the help link. </li>
<li><b>SubmitButtonStyle:</b> Applies to the buttons on username and question views. </li>
<li><b>FailureTextStyle:</b> Applies to the text returned if the membership system fails to reset or retrieve the password. </li>
<li><b>ValidatorTextStyle:</b> Applies to the text displayed if the required field valuators fail. </li>
</ul>

<h3>PasswordRecovery Styles Sample</h3>
This sample demonstrates a variety of the style properties. 
<br/> <br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/Login_cs/PasswordRecoveryStyles.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/PasswordRecoveryStyles.src"
        Caption="C# PasswordRecovery Styles"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/Login_vb/PasswordRecoveryStyles.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/PasswordRecoveryStyles.src"
        Caption="VB PasswordRecovery Styles"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />
<h3>PasswordRecovery Templates </h3>
The PasswordRecovery control is a composite control which unites child controls (e.g. textboxes, buttons) and additional logic (calling Membership, handling errors) to implement the PasswordRecovery functionality.  For even more control over the display of the PasswordRecovery control you can template the control.  To ensure that the PasswordRecovery control continues to function when it is templated, your control must use well known control IDs or command names for some of the child controls. In addition to the key controls required for functionality (e.g. textboxes) additional controls with well known IDs are supported and will be automatically hooked up to the PasswordRecovery functionality. Here is a list of control IDs and command names that are used in template editing mode: 
<ul>
<li><b>ID=UserName</b></li>
<li><b>ID=Password</b></li>
<li><b>ID=Question</b></li>
<li><b>ID=Answer</b></li>
<li><b>ID=FailureText</b> </li>
<li><b>CommandName=Submit</b> This control can have any control ID but must support command bubbling.</li>
</ul>

You can add additional functionality to the PasswordRecovery control through templating. For example, you can collect additional information from the user by adding additional controls to the template.

<h3>PasswordRecovery FindControl Template Sample </h3>
This sample contains a basic templated PasswordRecovery (no fancy styles) which collects an additional piece of information in the Question template. The sample shows how to find and retrieve the information from the DropDownList and write it to a label.
<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/Login_cs/PasswordRecoveryTemplates.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/PasswordRecoveryTemplates.src"
        Caption="C# PasswordRecovery Templates"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/Login_vb/PasswordRecoveryTemplates.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/PasswordRecoveryTemplates.src"
        Caption="VB PasswordRecovery Templates"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
