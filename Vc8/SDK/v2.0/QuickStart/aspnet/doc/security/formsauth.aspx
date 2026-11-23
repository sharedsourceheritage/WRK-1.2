<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Forms-based Authentication</h2>

Forms-based authentication is an ASP.NET authentication service 
that enables applications to
provide their own logon UI and do their own credential verification.  
ASP.NET authenticates users, redirects unauthenticated users to the 
logon page, and performs all the
necessary cookie management.  This sort of authentication is a popular 
technique used by many
Web sites.

<br /><br />

An application has to be configured to use forms-based 
authentication by setting <b>&lt;authentication&gt;</b> to <b>Forms</b>, and
denying access to anonymous users. The following example shows how 
this can be done in the Web.config
file for the desired application:

<pre class="code">
&lt;configuration&gt;
  &lt;system.web&gt;
    &lt;authentication mode="Forms"/&gt;
    &lt;authorization&gt;
        &lt;deny users="?" /&gt;
    &lt;/authorization&gt;
  &lt;/system.web&gt;
&lt;/configuration&gt;
</pre>

Administrators use forms-based authentication to configure the 
name of the cookie to use, the
protection type, the URL to use for the logon page, length of time the 
cookie is in effect, and the
path to use for the issued cookie. The following table shows the 
valid attributes for the <b>&lt;Forms&gt;</b>
element, which is a sub-element of the <b>&lt;authentication&gt;</b> 
element shown in the following example:

<br /><br />

<pre class="code">
&lt;authentication mode="Forms"&gt;
   &lt;forms name=".ASPXCOOKIEDEMO" loginUrl="login.aspx" defaultUrl="default.aspx" 
          protection="All" timeout="30" path="/" requireSSL="false" 
          slidingExpiration="true" enableCrossAppRedirects="false"
          cookieless="UseDeviceProfile" domain=""&gt;
          &lt;!-- protection="[All|None|Encryption|Validation]" --&gt;
          &lt;!-- cookieless="[UseUri | UseCookies | AutoDetect | UseDeviceProfile]" --&gt;
   &lt;/forms&gt;
&lt;/authentication&gt;
</pre>

<table class="table">
<tr>
  <th width="150"><b>Attribute</b></th>
  <th><b>Description</b></th>
</tr>
<tr>
  <td><b>cookieless</b></td>
  <td>ASP.NET 2.0 Forms Authentication can store the forms authentication ticket
      in either a cookie, or in a cookie-less representation on the URL.  The 
      default value of <code>UseDeviceProfile</code> means that ASP.NET determines
      where to store the ticket based on pre-computed browser profiles.  The
      <code>AutoDetect</code> option causes ASP.NET to dynamically determine
      if the browser supports cookies or not.  <code>UseUri</code> and
      <code>UseCookies</code> force cookieless and cookied tickets respectively.</td>
</tr>
<tr>
  <td><b>defaultUrl</b></td>
  <td>Specifies the default URL to which the request is redirected after a 
      successful login.  This value is used if a redirect URL is not available
      to Forms Authentication when redirecting after login.</td>
</tr>
<tr>
  <td><b>domain</b></td>
  <td>Specifies the value of the <code>Domain</code> property on the <code>
      HttpCookie</code> containing the forms authentication ticket.  Explicitly
      setting this attribute allows applications to share the same cookie as
      long as the applications share a common portion of a DNS namespace 
      (e.g. appA.contoso.com and appB.contoso.com could share a cookie if the
      <code>domain</code> attribute is set to "contoso.com").</td>
</tr>
<tr>
  <td><b>enableCrossAppRedirects</b></td>
  <td>In ASP.NET 2.0, Forms Authentication allows you to pass the forms authentication
      ticket across applications in either a query-string variable or in a forms POST
      variable.  Setting this attribute to true enables the 
      <code>FormsAuthenticationModule</code> to extract the ticket from either the 
      query-string or forms POST variables.</td>
</tr>
<tr>
  <td><b>loginUrl</b></td>
  <td>Specifies the URL to which the request is redirected for unauthenticated users.  This can be on the same
    computer or a remote one.  If it is on a remote computer, both 
computers need to be using
    the same value for the <b>decryptionkey</b> and <b>validationKey</b> attributes
    found in the <b>machineKey</b> configuration element.</td>
</tr>
<tr>
  <td><b>name</b></td>
  <td>Name of the HTTP cookie to use for authentication purposes.  Note that if more
    than one application wants to use forms-based authentication 
services on a single
    computer, and each application wants the forms authentication cookie to be isolated
    by application, then they should each configure a unique cookie value.  In order to avoid
    causing dependencies in URLs, ASP.NET also uses "/" as the Path value when setting
    authentication cookies, so that they are sent back to every 
application on the site.</td>
</tr>
<tr>
  <td><b>path</b></td>
  <td>Path to use for the issued cookie.  The default value is "/" to 
avoid difficulties with
    mismatched case in paths, since browsers are strictly 
case-sensitive when returning cookies.
    Applications in a shared-server environment should use this directive to maintain private
    cookies. (Alternatively, they can specify the path at runtime using the APIs to issue
    cookies.)</td>
</tr>
<tr>
  <td><b>protection</b></td>
  <td>Method used to protect cookie data.  Valid values are as follows:
    <ul>
     <li><b>All</b>: Use both data validation and encryption to 
protect the cookie.  The configured data validation algorithm is 
based on the <b>&lt;machinekey&gt;</b> element. AES is used by default for encryption, and if the key is long enough (48 characters).  <b>All</b> is the default (and suggested) value.
     <li><b>None</b>: Use for sites that are only using cookies for 
personalization and have weaker security requirements. Both encryption and 
validation can be disabled.  Although you should use caution if you 
use cookies in this way, this setting provides the best performance of any method 
of doing personalization using the .NET Framework.
     <li><b>Encryption</b>: Encrypts the cookie using AES, TripleDES or 
DES, but data validation is not done on the cookie.  This type of 
cookie can be subject to chosen plaintext attacks.
     <li><b>Validation</b>: Does not encrypt the contents of the 
cookie, but validates that the cookie data has not been altered in 
transit.  To create the cookie, the validation key is concatenated in a buffer with the cookie data and a MAC is computed and appended to the outgoing cookie.
    </ul>
  </td>
</tr>
<tr>
  <td><b>requireSSL</b></td>
  <td>If set to true, Forms Authentication sets the secure bit on the forms 
      authentication cookie.  Compliant browers will only send the cookie back
      to ASP.NET over an SSL connection.  Note that this setting has no effect
      when using cookieless forms authentication.</td>
</tr>
<tr>
  <td><b>slidingExpiration</b></td>
  <td>If set to true, Forms Authentication will periodically update the time
      to live for the forms authentication ticket.  This occurs regardless
      of whether or not the ticket is contained in a cookie, or in a cookieless
      format on the URL.</td>
</tr>
<tr>
  <td><b>timeout</b></td>
  <td>Amount of time in integer minutes, after which the cookie 
expires.  The default value is <i>30</i>.
    The timeout attribute is a sliding value, expiring <i>n</i> minutes from the time the last request was
    received.  In order to avoid adversely affecting performance and to 
avoid multiple browser warnings
    for those who have cookies warnings turned on, the cookie is updated if the time is more
    than half gone. (This means a loss of possible precision in some cases.)</td>
</tr>
</table>

<br />

After the application has been configured, you need to provide a logon page. The following
example shows a simple logon page.  When the sample is run, it requests the
Default.aspx page.  Unauthenticated requests are redirected to the logon page (Login.aspx), 
which presents a simple form that prompts for an e-mail address and a password. (Use
Username="someone@www.contoso.com" and Password="password" as credentials.)

<br /><br />

After validating the credentials, the application calls the following:

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
FormsAuthentication.RedirectFromLoginPage(UserEmail.Value, PersistCookie.Checked);
</Tab>
<Tab Name="VB">
FormsAuthentication.RedirectFromLoginPage(UserEmail.Value, PersistCookie.Checked)
</Tab>

</Acme:TabControl>

<br />

This redirects the user back to the originally requested URL.  Applications that do not
want to perform the redirection can call either <b>FormsAuthentication.GetAuthCookie</b> to
retrieve the cookie value or <b>FormsAuthentication.SetAuthCookie</b> to attach a properly
encrypted cookie to the outgoing response.  These techniques can be 
useful for applications
that provide a logon UI embedded in the containing page or that want 
to have more
control over where users are redirected.  
<br />
<br />
Authentication cookies 
can either be temporary or
permanent ("persistent").  Temporary cookies last only for the 
duration of the 
current browser session. When the
browser is closed, the cookie is lost.  Permanent cookies are saved 
by the browser and are
sent back across browser sessions unless explicitly deleted by the user or if the cookie
lifetime expires.
The cookie lifetime for both temporary and permanent cookies is determined by the
<code>timeout</code> configuration attribute. This is a slight change in behavior from
older versions of ASP.NET where the persistent cookies were given a lifetime of 50 years.
 In ASP.NET 2.0, both temporary and persistent cookies have their expiration date set to the current 
time plus the value of the <code>timeout</code> configuration attribute.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
<Acme:SourceRef
  RunSample="../../samples/security/CookieAuth_cs/default.aspx"
  ViewSource="~/aspnet/samples/security/cookieauth.src"
  Caption="C# Forms-Based/Cookie Authentication"
  runat="server" />
  </CsTemplate>
  <VbTemplate>
<Acme:SourceRef
  RunSample="../../samples/security/CookieAuth_vb/default.aspx"
  ViewSource="~/aspnet/samples/security/cookieauth.src"
  Caption="VB Forms-Based/Cookie Authentication"
  runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

The authentication cookie used by forms authentication consists 
of a serialized version of
the <b>System.Web.Security.FormsAuthenticationTicket </b> class.  The information includes the
user name (but not the password), the version of forms authentication used, the date the
cookie was issued, and a field for optional application-specific data.

<br /><br />

Application code can revoke or remove authentication cookies using the
<b>FormsAuthentication.SignOut</b> method.  This removes the 
authentication cookie
regardless of whether it is temporary or permanent.

<br /><br />

It is also possible to supply forms-based authentication services with a list of valid
credentials using configuration, as shown in the following example:

<br /><br />

<pre class="code">
&lt;authentication&gt;
    &lt;credentials passwordFormat="SHA1" &gt;
        &lt;user name="Mary" password="94F85995C7492EEC546C321821AA4BECA9A3E2B1"/&gt;
        &lt;user name="John" password="5753A498F025464D72E088A9D5D6E872592D5F91"/&gt;
    &lt;/credentials&gt;
&lt;/authentication&gt;
</pre>
You can generate the hashed representation of the password by using the <code>
FormsAuthentication.HashPasswordForStoringInConfigFile(String password, String passwordFormat)</code>API.
This method supports generating hashed values using either SHA1 or MD5.
The application can then call 
<b>FormsAuthentication.Authenticate</b>, supplying
the username and password, and ASP.NET will verify the credentials.  Credentials can
be stored in cleartext, or as SHA1 or MD5 hashes, according to the following values 
of the
<b>passwordFormat</b> attribute:

<br /><br />

<table class="table" cellpadding=3>
  <tr>
    <th width="150">Hash Type</th>
    <th>Description</th>
  </tr>
  <tr>
    <td>Clear</td>
    <td>Passwords are stored in cleartext</td>
  </tr>
  <tr>
    <td>SHA1</td>
    <td>Passwords are stored as SHA1 digests</td>
  </tr>
  <tr>
    <td>MD5</td>
    <td>Passwords are stored as MD5 digests</td>
  </tr>
</table>

</asp:Content>


