<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.Wizard" runat="server">
  Wizard
</Acme:TypeRef>
</h2>

The Wizard control provides navigation through a series of steps that collect information incrementally from a user. Many websites include functionality that collects information from the end user (e.g. checking out on an ecommerce website). The Wizard consists of:
<ul>
<li> <b>Collection of WizardSteps: </b>Each WizardStep contains a discrete piece of content to be displayed to the user. Only one WizardStep will be displayed at a time.  </li> 
<li> <b>Navigation Area: </b>The navigation area below each WizardStep that contains the navigation buttons to go the next and pervious steps in the wizard. </li>
<li> <b>SideBar: </b> An optional element that contains a list of all WizardSteps and provides a means to skip around the WizardSteps in a random order. </li>
<li> <b>Header: </b> An optional element to provide consistent information at the top of the WizardStep.  </li>
</ul>

The StepType associated with each WizardStep determines the type of navigation buttons that will be displayed for that step. The StepTypes are: 
<ul>
<li> <b> Start: </b> Displays a Next button.</li>
<li> <b> Step:</b>  Displays Next and Previous buttons.</li>
<li> <b> Finish:</b> Displays a Finish button.</li>
<li> <b> Complete:</b> Displays no navigation buttons and hides the SideBar if it is displayed. </li>
<li> <b> Auto:</b>One of the step types listed above is selected based on the order of the step in the collection (e.g. the first step will have a Next button). </li>
</ul>

<b>Note:</b> If you are using the WizardControl in a visual designer you can switch to view different WizardSteps on the design surface. To improve the development experience, when you run the page whatever WizardStep was displayed in the designer will be the step you start on. This makes it easier to debug new steps you might be adding to a complicated wizard where each WizardStep requires a lot of validated input. However, you MUST REMEMBER to change the WizardStep back to the first step when you are done making changes.

<br/><br/>

<h3>Simple Single-Step Wizard Control Sample </h3>
This sample demonstrates a basic Wizard control that collects a single piece of information on the first WizardStep and displays that information to the user on the Complete WizardStep for confirmation. Instead of displaying this information to the user, you could write the information to a database or other collection store. 
<br/>
<br/>
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/Wizard/WizardBasic_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/Wizard/WizardBasic.src"
        Caption="C# Wizard"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/Wizard/WizardBasic_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/Wizard/WizardBasic.src"
        Caption="VB Wizard"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

<h3>Wizard Commitment Models </h3>
Since wizards in web applications are used for a large variety of task the Wizard control supports two different models for using or writing the data collected to a data store. 


<b>Commit As Your Go Model </b>In the commit as you go model the developer handles writing the information collected on each WizardStep incrementally. For example, a developer implementing a check out system might do the following: 
<ul>
<li><b>First Step:</b> Login the user or redirect to a registration page</li>
<li><b>Second Step:</b> Confirm the shipping information for the order</li>
<li><b>Third Step:</b> Review the order including shipping charges</li>
<li><b>Fourth Step:</b> Collect and process the credit card information</li>
<li><b>Fifth Step:</b> Confirm that the order was successful and offer a link to return to shopping</li>
</ul>

Since each step in this process is a pre-requisite for the next step and each step is processed independently it makes sense to commit and process these steps individually. Since each of these steps have been processed independently you may want to prevent the user from revisiting past steps by setting the AllowReturn=False property on the WizardSteps and might also decide to hide the SideBar display. Your code should also be robust enough to handle abandoned sessions, changes to previously committed choices and canceling at any of the WizardSteps. 

<b>Commit At the End Model </b>In the commit at the end model the developer handles writing all of the information collected on each WizardStep incrementally. For example, a developer implementing a user registration system might do the following: 
<ul>
<li><b>First Step:</b> Collect UserID and Password</li>
<li><b>Second Step:</b> Collect address information</li>
<li><b>Third Step:</b> Collect billing information.</li>
<li><b>Fifth Step:</b> Success message</li>
</ul>
In this example, the developer does not want to create the user in their registration system or enable their account until all of the billing information is collected and processed. If they created the user during the first step, then the user might become active in their system without paying for the service. 

<h3>Wizard Commit Model Samples </h3>
This file shows two Wizard controls side by side. One Wizard control demonstrates the Commit As You Go model and the second Wizard control demonstrates the commit at the end model. 
<br/>
<br/>
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/Wizard/WizardCommitAsYouGo_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/Wizard/WizardCommitAsYouGo.src"
        Caption="C# Wizard CommitAsYouGo"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/Wizard/WizardCommitAsYouGo_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/Wizard/WizardCommitAsYouGo.src"
        Caption="VB Wizard CommitAsYouGo"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />
<h3>Wizard NonLinear Navigation </h3>
Often in web site wizards,  information collected in one step is used to determine if another step should be displayed (e.g. marking something as a gift might cause a gift wrapping step to be displayed).  You can set the Wizard control's activeStepIndex to the step that you want the user to go to even if it is not the next sequential step in your collection of steps. In the skipped step scenario, a user who clicks the previous button on a WizardStep will go to the previous step that they visited (not the step that they skipped). 

<h3>Wizard NonLinear Navigation Sample </h3>
In this example the value selected on the first WizardStep is used to determine if the user should skip the second WizardStep and go directly to the third WizardStep.  The DisplaySideBar property is set to false in this sample to prevent users who skip WizardStep 2 from clicking on the WizardStep 2 option in the SideBar.
<br/>
<br/>
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/Wizard/WizardNonLinear_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/Wizard/WizardNonLinear.src"
        Caption="C# Wizard NonLinear"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/Wizard/WizardNonLinear_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/Wizard/WizardNonLinear.src"
        Caption="VB Wizard NonLinear"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />
<h3>Wizard Styles </h3>
The Wizard control allows you to control the look and feel by setting a variety of style properties on the control.  The Wizard control supports the following styles: 

<ul>
<li><b><i>Control</i> Style:</b> Applies to all sections of the Wizard control and are merged with other styles set on the control.</li>
<li><b>Step Style:</b> Applies to the WizardStep section of the control.</li>
<li><b>HeaderStyle:</b> Applies to the header section of the control.</li>
<li><b>SideBarStyle:</b> Applies to the area where the SideBar is displayed.</li>
<li><b>SideBarButtonStyle:</b> Applies to the buttons contained within the SideBar.</li>
<li><b>NavigationStyle:</b> Applies to all area of the control where the Navigation buttons are displayed. </li>
<li><b>NavigationButtonStyle:</b> Applies to all navigation buttons in the navigation area. These styles are merged with specific styles set on individual navigation buttons. In the event of conflict the more specific style is applied. </li>
<li><b>StartNextButtonStyle:</b> The next button on steps of StepType=Start.</li>
<li><b>StepNextButtonStyle:</b> The next button on steps of StepType=Step. </li>
<li><b>StepPreviousButtonStyle:</b> The previous button on steps of StepType=Step. </li>
<li><b>FinishPreviousButtonStyle:</b> The previous button on steps of StepType=Finish.< li>
<li><b>CancelButtonStyle:</b> The cancel button. </li>
</ul>

<h3>Wizard Style Sample </h3>
This sample demonstrates various style properties on the Wizard control that can be used to customize the look and feel of the control. 
<br/>
<br/>
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/Wizard/WizardStyles_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/Wizard/WizardStyles.src"
        Caption="C# Wizard Styles"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/Wizard/WizardStyles_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/Wizard/WizardStyles.src"
        Caption="VB Wizard Styles"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />
<h3>Wizard Templates </h3>
The Wizard control allows you more complete control of the look and feel of the control through templating.  The Wizard control supports individual components of the Wizard to be templated separately. You may choose to template 1 or more of these templates for a given Wizard in your web application. 
The Wizard control supports the following templates: 
<ul>
<li>HeaderTemplate</li>
<li>SideBarTemplate</li>
<li>StartNavigationTemplate</li>
<li>StepNavigationTemplate</li>
<li>FinishNavigationTemplate</li>
</ul>

Note: If you template the SideBar, use the well known ID=SideBarButton for the button controls and the Wizard will automatically hook up the navigation logic. If you template the Navigation areas use the well known command name (e.g. MoveNext, MovePrevious) for your controls and the Wizard will automatically hook up the navigation logic. 

<h3>Wizard Templates Sample </h3>
This sample demonstrates various templates in the Wizard control that can be used to customize the look and feel of the control. 
<br/>
<br/>
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/Wizard/WizardTemplates_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/Wizard/WizardTemplates.src"
        Caption="C# Wizard Templates"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/Wizard/WizardTemplates_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/Wizard/WizardTemplates.src"
        Caption="VB Wizard Templates"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

<h3>Templated WizardSteps </h3>
The Wizard control also supports creating Templated WizardSteps.  This gives you the ability to create your own Wizard step that supports templates. This functionality may prove useful to control developers who are building specialized wizards (e.g. Shopping Carts, Registration) that will be used by developers in a variety of sites with visual displays. Programmatically locating a control inside of a templated WizardStep is slightly more difficult because you must find the control within its naming container. 

<h3>Templated WizardStep Sample </h3>
This sample demonstrates how to find a control in both a regular and templated WizardStep.  
<br/>
<br/>
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/Wizard/WizardTemplatedStep_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/Wizard/WizardTemplatedStep.src"
        Caption="C# Wizard TemplatedStep"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/Wizard/WizardTemplatedStep_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/Wizard/WizardTemplatedStep.src"
        Caption="VB Wizard TemplatedStep"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

</asp:Content>
