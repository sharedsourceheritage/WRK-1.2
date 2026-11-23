<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Windows-based Authentication</h2>

When you use ASP.NET Windows authentication, ASP.NET attaches a <b>WindowsPrincipal</b> object to the current request.  This object is used by URL authorization. The application can also use it programmatically to determine whether a requesting identity is in a given role.

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
if(User.IsInRole("Administrators")) {
    DisplayPrivilegedContent();
}
</Tab>

<Tab Name="VB">
If User.IsInRole("Administrators") Then
    DisplayPrivilegedContent()
End If
</Tab>

</Acme:TabControl>

<br />

The <b>WindowsPrincipal</b> class determines roles by NT group membership.  Applications that want to determine their own roles can do so by handling the 
<b>WindowsAuthentication_OnAuthenticate</b> event in their Global.asax file and attaching their own class that implements <b>System.Security.Principal.IPrincipal</b> to the request, as shown in the following example:

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
// Create a class that implements IPrincipal
public class MyPrincipal : IPrincipal {
  // implement application-defined role mappings
}

// In a Global.asax file:
public void WindowsAuthentication_OnAuthenticate(Object Source, WindowsAuthenticationEventArgs e) {
  // Attach a new application-defined class that implements IPrincipal to
  // the request.
  // Note that since IIS has already performed authentication, the provided
  // identity is used.
  e.User = new MyPrincipal(e.Identity);
}
</Tab>

<Tab Name="VB">
' Create a class that implements IPrincipal
Public Class MyPrincipal : Inherits IPrincipal
  ' Implement application-defined role mappings
End Class

' In a Global.asax file
Public Sub WindowsAuthentication_OnAuthenticate(Source As Object, e As WindowsAuthenticationEventArgs)
  ' Attach a new application-defined class that implements IPrincipal to
  ' the request.
  ' Note that since IIS has already performed authentication, the provided
  ' identity is used.
  e.User = New MyPrincipal(e.Identity)
End Sub
</Tab>

</Acme:TabControl>

<br />

The following sample shows how to access the name of an authenticated user, which is available as <b>User.Identity.Name</b>.  Programmers familiar with ASP should note 
that this value is also still available as the <i>AUTH_USER</i> server variable.  Prior to running this application, make sure the settings in IIS are set to require only Integrated Windows authentication for the sample application.  This will force a security handshake between the browser and the sample application.  

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
    <Acme:SourceRef
      RunSample="../../samples/security/WindowsAuth_cs/windowsauth.aspx"
      ViewSource="~/aspnet/samples/security/windowsauth.src"
      Caption="C# Windows Authentication"
      runat="server" />
  </CsTemplate>
  <VbTemplate>
    <Acme:SourceRef
      RunSample="../../samples/security/WindowsAuth_vb/windowsauth.aspx"
      ViewSource="~/aspnet/samples/security/windowsauth.src"
      Caption="VB Windows Authentication"
      runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>


