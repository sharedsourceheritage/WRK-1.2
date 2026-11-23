<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.Login" runat="server">
  Login
</Acme:TypeRef>
</h2>

The Login control provides the user interface to log a user into a web site. The Login control uses the <asp:hyperlink navigateurl ="~/aspnet/doc/security/default.aspx"    runat="server"> Membership service</asp:hyperlink>  to authenticate the user in your membership system. The default Membership service from your configuration file will be used automatically, however you can also set the Membership provider that you would like used as a property on the control. 

The Login Control consists of:
<ul>
<li> <b>Username Label and Textbox: </b>Collects the string used to identify the user in the membership system.  </li> 
<li> <b>Password Label and Textbox: </b>Collects the password for the specified user. The textbox text is always obscured.</li>
<li> <b>LoginButton: </b> The button to submit the user's request for authentication. </li>
<li> <b>RememberMe: </b> Configurable to display a checkbox giving the user the option to store a persistent cookie on the user's machine. </li>
<li> <b>Title and Instruction: </b> Text to orient and guide the user through the process. </li>
<li> <b>Links: </b> Configurable links to help, password recovery and user registration information. </li>
<li> <b>Validators: </b> Required field validators for the username and password textboxes. </li>
</ul>

<b>Note:</b> The samples for this control use Master Pages to provide the information that is used to logon a user. For more information on <asp:hyperlink navigateurl ="~/aspnet/doc/masterpages/default.aspx"    runat="server"> Master Pages</asp:hyperlink>. 

<br/><br/>

<h3>Simple Login Sample </h3>
This sample demonstrates the default Login control behavior on a dedicated login page as defined in the forms authentication section of web.config.

<br/><br/>


<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/Login_cs/Login.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/Login.src"
        Caption="C# Login"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/Login_vb/Login.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/Login.src"
        Caption="VB Login"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />


<h3>Login Behaviors </h3>
The Login control supports a variety of options to customize the display behaviors. Some of the behaviors that will impact the display are: 

<ul>
<li> <b>Orientation: </b>Determines if the control will be oriented horizontally or vertically.  Horizontal is a useful option when you want the login functionality to always be present in the top or bottom of a page.   </li> 
<li> <b>TextLayout: </b>Determines if the text will be displayed on top of the textboxes or on the side. </li>
<li> <b>VisibleWhenLoggedIn: </b>When set to true, the control will be hidden on the page if the user is already authenticated. This option works well on home pages that provide personalized data when the user is logged in to the website. Note: If the Login control is on the default login page set in the configuration file this property will be ignored and the control will always be rendered.</li> 
</ul>

<h3>Login Behaviors Sample</h3>
This sample demonstrates a horizontal Login control with the text displayed above the textboxes.
<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/Login_cs/LoginBehaviors.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/LoginBehaviors.src"
        Caption="C# Login Behaviors"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/Login_vb/LoginBehaviors.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/LoginBehaviors.src"
        Caption="VB Login Behaviors"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

<h3>Login Styles </h3>
The Login control supports customizing the look of the control through a series of style properties that control different areas of the control. 

<ul>
<li><b><i>Control</i> Style:</b> Applies to all sections of the Login control and is merged with other styles set on the control.</li>
<li><b>Label Style:</b> Applies to the username and password labels.</li>
<li><b>TextboxStyle:</b> Applies to the username and password textboxes.</li>
<li><b>TitleTextStyle:</b> Applies to the title text.</li>
<li><b>InstructionTextStyle:</b> Applies to the instruction text.</li>
<li><b>HyperlinkStyle:</b> Applies to the help, password recovery and create new user links. </li>
<li><b>LoginButtonStyle:</b> Applies to the login button. </li>
<li><b>CheckBoxStyle:</b> Applies to the remember me checkbox.</li>
<li><b>FailureTextStyle:</b> Applies to the text returned if the membership system fails to authenticate the user. </li>
<li><b>ValidatorTextStyle:</b> Applies to the text displayed if the required field valuators fail. </li>
</ul>

<h3>Login Styles Sample</h3>
This sample demonstrates a variety of the style properties. 
<br/> <br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/Login_cs/LoginStyles.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/LoginStyles.src"
        Caption="C# Login Styles"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/Login_vb/LoginStyles.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/LoginStyles.src"
        Caption="VB Login Styles"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

<h3>Login Templates </h3>
The Login control is a composite control which unites child controls (e.g. textboxes, buttons) and additional logic (calling Membership, handling errors) to implement the login functionality.  For even more control over the display of the Login control you can template the control.  To ensure that the Login control continues to function when it is templated, your control must use well known control IDs or command names for its child controls. In addition to the key controls required for functionality (e.g. textboxes) additional controls with well known IDs are supported and will be automatically hooked up to the Login functionality. Here is a list of control IDs and command names that are used in template editing mode: 
<ul>
<li><b>ID=UserName</b></li>
<li><b>ID=Password</b></li>
<li><b>ID=RememberMe</b></li>
<li><b>ID=FailureText</b> </li>
<li><b>CommandName=Login</b> This control can have any control ID but must support command bubbling.</li>
</ul>

You can add additional functionality to the Login control through templating. For example, you can add additional validators to the password textbox to ensure that your web sites minimum password requirement has been met or you could collect additional information from the user by adding additional controls to the template.

<h3>Login Templates Sample </h3>
This sample demonstrates a templated login control.
<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/Login_cs/LoginTemplate.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/LoginTemplate.src"
        Caption="C# Login Template"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/Login_vb/LoginTemplate.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/LoginTemplate.src"
        Caption="VB Login Template"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>


</asp:Content>
