<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.CreateUserWizard" runat="server">
  CreateUserWizard
</Acme:TypeRef>
</h2>

The CreateUserWizard control extends the <asp:hyperlink runat="server" navigateurl ="~/aspnet/doc/ctrlref/standard/wizard.aspx"> Wizard control </asp:hyperlink> with additional functionality that relies on the <asp:hyperlink navigateurl ="~/aspnet/doc/security/default.aspx"    runat="server"> Membership service </asp:hyperlink>  to create a new user in your membership data store. Since it extends the Wizard control you can customize the CreateUserWizard experience on your website by adding additional WizardSteps that collect additional information or by templating the CreateUseWizardStep. 

<ul>
<li> <b>CreateUserWizardStep: </b>Pre-defined wizard step with the create user display and logic added.  </li> 
<li> <b>CompleteWizardStep: </b>Pre-defined wizard step that shows the successful completion of the wizard.  </li> 
<li> <b>Collection of WizardSteps: </b>Each WizardStep contains a discrete piece of content to be displayed to the user. Only one WizardStep will be displayed at a time.  </li> 
<li> <b>Navigation Buttons: </b>The navigation area below each WizardStep that contains the navigation buttons to go the next and pervious steps in the CreateUserWizard. </li>
<li> <b>SideBar: </b> An optional element that contains a list of all WizardSteps and provides a means to skip around the WizardSteps in a random order. </li>
<li> <b>Header: </b> An optional element to provide consistent information at the top of the WizardStep.  </li>
</ul>

<b>Note:</b> If you are using the CreateUserWizard control in a visual designer you can switch to view different WizardSteps on the design surface. To improve the development experience, when you run the page whatever WizardStep was displayed in the designer will be the step you start on in a browser. This makes it easier to debug new steps you might be adding to a complicated CreateUserWizard where each WizardStep requires a lot of validated input. However, you MUST REMEMBER to change the WizardStep back to the first step in the designer when you are done making changes.

<br/><br/>

<h3>Simple Single-Step CreateUserWizard Control Sample </h3>
This sample demonstrates basic CreateUserWizard functionality. This sample uses a regular expression to validate the email address.

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/CreateUser_cs/CreateUserWizardBasic_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/CreateUserWizardBasic.src"
        Caption="C# CreateUserWizard"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/CreateUser_vb/CreateUserWizardBasic_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/CreateUserWizardBasic.src"
        Caption="VB CreateUserWizard"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

<h3>CreateUserWizard Behaviors </h3>
There are a variety of ways to customize the CreateUserWizard control to meet your needs. In addition to the visual elements displayed to the user on the web site, the CreateUserWizard control also contains a <code>MailDefinition</code> that determines the content of the email that is sent to the user.  The CreateUserWizard control does not contain a default email message but you can add your own text or html file to be used as the body of the message. If you are creating your own email file the control will automatically insert the user's username and password for the following strings: <code> &lt&#37UserName&#37&gt  &lt&#37Password&#37&gt </code> in the designated email file. <B>Security Note:</B> It may be possible for the email containing the user's password to be intercepted by hackers and thus compromise the user's account. 
Some additional customizations are: 
<ul>
<li> <b>Additional Wizard Steps: </b>Collect additional information about the user. </li> 
<li> <b>Links: </b>Displaying icons and links to other information and tasks.</li> 
</ul>

<h3>ChangePassword Behaviors Sample</h3>
This sample demonstrates how to add an additional WizardStep to the CreateUserWizard.
<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/CreateUser_cs/CreateUserWizardBehaviors_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/CreateUserWizardBehaviors.src"
        Caption="C# CreateUserWizard Behaviors"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/CreateUser_vb/CreateUserWizardBehaviors_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/CreateUserWizardBehaviors.src"
        Caption="VB CreateUserWizard Behaviors"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

<h3>CreateUserWizard Styles </h3>
The CreateUserWizard control allows you to control the look and feel by setting a variety of style properties on the control.  In addition to the standard Wizard style properties, the CreateUserWizard control supports the following styles: 

<ul>
<li><b>Label Style:</b> Applies to the labels associated with textboxes on the CreateUserWizard.</li>
<li><b>TextboxStyle:</b> Applies to the textboxes.</li>
<li><b>CompleteSuccessTextStyle:</b> Applies to the text on the complete step.</li>
<li><b>InstructionTextStyle:</b> Applies to the instruction text.</li>
<li><b>PasswordHintStyle:</b> Applies to the password hint text.</li>
<li><b>HyperlinkStyle:</b> Applies to all of the links. </li>
<li><b>ErrorMessageStyle:</b> Applies to the text returned if the membership system fails to create the user. </li>
<li><b>ValidatorTextStyle:</b> Applies to the text displayed if the required field valuators fail. </li>
</ul>

<h3>CreateUserWizard Style Sample </h3>
This sample demonstrates various CreateUserWizard styles.


<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/CreateUser_cs/CreateUserWizardStyles_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/CreateUserWizardStyles.src"
        Caption="C# CreateUserWizard Styles"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/CreateUser_vb/CreateUserWizardStyles_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/CreateUserWizardStyles.src"
        Caption="VB CreateUserWizard Styles"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

<h3>CreateUserWizard Templates </h3>
The CreateUserWizard control allows you more complete control of the look and feel of the control through templating.  The CreateUserWizard control supports individual components of the CreateUserWizard to be templated separately. You may choose to template 1 or more of these templates for a given CreateUserWizard control in your web application. In addition to the standard templates supported by the Wizard control, the CreateUserWizard also supports templating the CreateUserStep. 

The CreateUserWizard control supports the following templates: 
<ul>
<li>HeaderTemplate</li>
<li>SideBarTemplate</li>
<li>StartNavigationTemplate</li>
<li>StepNavigationTemplate</li>
<li>FinishNavigationTemplate</li>
<li>ContentTemplates</li> (used for the CreateUserStep and the CompleteStep).
</ul>

To ensure that the functionality of the CreateUser and Complete steps function appropriately use the following control IDs or command names:
<ul>
<li>ID=UserName</li>
<li>ID=Password</li>
<li>ID=Email</li>
<li>ID=ConfirmPassword</li>
<li>ID=Question</li>
<li>ID=Answer</li> 
<li>ID=ErrorMessage</li> 
<li>Command=CreateUser</li> (the control must support command bubbling) 
<li>Command=Cancel</li> (the control must support command bubbling) 
</ul>


<h3>CreateUserWizard Templates Sample </h3>
This sample demonstrates how to access controls inside the templated CreateUser Step as well as controls inside additional Wizard steps. No graphical elements have been added to the template in an attempt to simplify the sample. This sample contains the well known control IDs and command names required for a templated CreateUser Step.
<br/><br/>
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/CreateUser_cs/CreateUserWizardTemplates_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/CreateUserWizardTemplates.src"
        Caption="C# CreateUserWizard Templates"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/CreateUser_vb/CreateUserWizardTemplates_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/CreateUserWizardTemplates.src"
        Caption="VB CreateUserWizard Templates"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

</asp:Content>
