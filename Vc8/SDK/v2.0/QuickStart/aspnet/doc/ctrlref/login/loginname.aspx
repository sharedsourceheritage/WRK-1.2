<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.LoginName" runat="server">
  LoginName
</Acme:TypeRef>
</h2>

The LoginName controls displays the currently authenticated user's name on the page. It uses the value returned by calling page.user.identity. If the user is not currently logged in then the control does not render on the page and does not “hold” any visual space on the page.  The LoginName control supports the standard web control style properties to control its display.  The FormatString property enables you to insert the users name in a string of text. It will replace the {0} value with the user's identity at runtime. In this example, we have set the value to <code>Welcome {0}!</code>

<h3>LoginName Sample </h3>
To view the LoginName control in this sample you must first login to the website. Use one of the  user accounts as listed in the sample web page. 
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/Login_cs/LoginNameStatusBasic.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/LoginNameStatusBasic.src"
        Caption="C# LoginName1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/login/Login_vb/LoginNameStatusBasic.aspx"
        ViewSource="~/aspnet/samples/ctrlref/login/LoginNameStatusBasic.src"
        Caption="VB LoginName1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
