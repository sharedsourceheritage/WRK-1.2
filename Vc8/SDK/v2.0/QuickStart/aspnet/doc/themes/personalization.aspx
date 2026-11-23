<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>

<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>


<h2>Themes and Profiles</h2>

You may want the end-users of your application to be able to choose and apply Themes dynamically.
By storing the active Theme in a 
<asp:HyperLink NavigateUrl="~/aspnet/doc/profile/default.aspx" runat="server">User Profile</asp:HyperLink>, 
you can dynamically apply a theme based on user
preferences.  To do this, you apply the Theme programmatically in code instead of setting the 
Theme declaratively using the <code>@Page</code> directive or Web.config.

<a name="code"></a>
<h3>Assigning a Theme in Code</h3>

To apply a Theme from code, you set the <b>Theme</b> property of the <b>Page</b> object at runtime.
A Theme must be applied to a page very early in the request lifecycle, in the <code>PreInit</code>
event.  The example below shows a Theme dynamically applied in this event when the user selects
a Theme name from a DropDownList control.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/themes/Programmatic_cs.aspx"
        ViewSource="~/aspnet/samples/themes/Programmatic.src"
        Caption="C# Assigning a Theme in Code"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/themes/Programmatic_vb.aspx"
        ViewSource="~/aspnet/samples/themes/Programmatic.src"
        Caption="VB Assigning a Theme in Code"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

Using the Profile feature in ASP.NET 2.0, you can store a user's preference for a Theme and restore
it when the user logs in to your site.  The example below demonstrates this technique.  The user 
can select their favorite color preference and save it to their profile, and then the page sets
the Theme based on this color preference by retrieving the Theme name from the <b>Profile</b> object.
Notice that if you log out of the site, the Theme is restored to the default (no theme), but if you
log back into the site, the user preference is retained.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/themes/ProfileTheme_cs.aspx"
        ViewSource="~/aspnet/samples/themes/ProfileTheme.src"
        Caption="C# Assigning a Theme Based on User Profile"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/themes/ProfileTheme_vb.aspx"
        ViewSource="~/aspnet/samples/themes/ProfileTheme.src"
        Caption="VB Assigning a Theme Based on User Profile"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

</asp:Content>

