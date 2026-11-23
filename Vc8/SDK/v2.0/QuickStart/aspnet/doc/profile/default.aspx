<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Storing User Profiles</h2>

<div class="new">

<h3>What's New in 2.0</h3>

<ul>
  <li><b>User Profiles - </b> The profile feature in ASP.NET 2.0 allows you to define and store per-user settings to be used throughout your application.  Settings can also be stored in an anonymous profile while users are not logged in, and then migrated to a logged-in user profile at a later time.</li>
</ul>
This section discusses the new profile feature in ASP.NET 2.0.
</div>

<br />

Web sites frequently need a convenient method to store user-specific data that is applicable site-wide.  The Profile feature delivers
an easy-to-use approach for defining user-specific data as well storing and retrieving this user data.  
<br /><br />
A user's profile is a collection of properties that define information you want to store for your web site's users.  The user's 
profile is defined using a simple XML syntax in a configuration file (machine.config and/or web.config).  Within your page, you
reference a user's profile information with the <b>Profile</b> property.  ASP.NET reads the schema defined in configuration, and 
automatically generates a class that is accessible from the <b>Profile</b> property on a page.  You access properties on the <b>Profile</b> just as you would 
access properties on any other class.
<br /><br />
Although the most common use of the Profile feature is storing data for authenticated users, the Profile feature also supports
storing information for anonymous users.  Storing profile information for anonymous users depends on the Anonymous Identification
feature.  The Profile and Anonymous Identification features work together to enable the use of the <b>Profile</b> property
for anonymous users.  The samples included in the QuickStart demonstrate using the Profile feature with both authenticated and
unauthenticated users. 
<br /><br />
Prior to the start of the page lifecycle, ASP.NET ensures that the <b>Profile</b> is available for use by the page.  Similarly,
at the end of the ASP.NET page lifecycle, ASP.NET automatically saves the <b>Profile</b> to the underlying data store(s). As with other
features such as Membership and Role Manager, the Profile feature has been designed with a provider-based model.  Providers
abstract the physical data storage for a feature from the classes and business logic exposed by a feature.  The Profile feature
ships with a provider for Microsoft&trade; SQL Server.  You can create your own custom providers and configure them to
work either the Profile feature.  Pages that use the Profile feature will continue to work unchanged with your custom providers.
<p>
In addition to the <b>Profile</b> property, the Profile feature provides support for administration of profiles (both for authenticated
users and anonymous users) with the <b>ProfileManager</b>. Common tasks that you perform with the <b>ProfileManager</b> include:
<ul>
  <li> Searching for statistical information about all profiles, profiles for authenticated users, and profiles for anonymous users
  <li> Determine the number of profiles that have not been modified in a given period of time
  <li> Deleting individual profiles as well as deleting multiple profiles based on a profile's last modification date
</ul>

<a name="schema"></a>
<h3>Defining the Profile Schema</h3>

The configuration file in the following sample defines a <b>Profile</b> using properties, as well as a property group.  Properties are
defined using <code>&lt;add&gt;</code> elements within a <code>&lt;properties&gt;</code> element.  A property group is a convenient
way of logically grouping multiple properties.  You define a property group with a <code>&lt;group&gt;</code> element.  In the
sample schema, a property group called "AutomobilePreferences" groups together two additional properties.  Note that 
<code>&lt;group&gt;</code> elements cannot be nested (that is:  there is only one level of group nesting supported beneath the
<code>&lt;properties&gt;</code> element).
<br /><br />
The sample schema demonstrates the flexibility you have in terms of defining data types for your profile properties.  By default,
properties are assumed to be of type <code>System.String</code>.  However, you can define a profile property using any type that is
resolvable by the ASP.NET application at runtime.  The sample schema includes definitions for <code>System.Collections.ArrayList</code>
as well as <code>System.Drawing.Color</code>.
<br /><br />
Note that the <code>&lt;add&gt;</code> element supports a variety of optional attributes beyond those shown in this sample.  Normally, the Profile feature serializes
properties using either type conversion to a string, or Xml serialization.  However, not all types are serializable as strings
or as Xml fragments.  This is why the "PreferredBackgroundColor" property has a <code>serializeAs</code> attribute that explicitly
indicates binary serialization.  The "PricePoint" property has a <code>defaultValue</code> attribute that defines the default value
for this property if one has not already been set.
<br /><br />
The "PreferredBackgroundColor" property also has an <code>allowAnonymous</code> attribute that is set to <code>true</code>.  By default, 
profile properties are restricted to authenticated users.  When the <code>allowAnonymous</code> attribute is set to <code>true</code>
this indicates that the property can also be used to load and store information for anonymous users.
<br><br>
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
	ViewSource="~/aspnet/samples/profiles/ProfileSchema.src"
	Caption="Profile schema in web.config"
	runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
	ViewSource="~/aspnet/samples/profiles/ProfileSchema.src"
	Caption="Profile schema in web.config"
	runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="anon"></a>
<h3>Anonymous Profiles</h3>

The profile schema shown in the last sample allows both authenticated and anonymous users to store their preferred background color.
  On the sample page an anonymous user can choose from a selection of colors.  When the page refreshes it will render using
the selected color.  Notice that if you shut down the browser, and then re-run the sample, the color selection is remembered.
The reason for this is that the Anonymous Identification feature is enabled for all of the samples (by default, Anonymous Identification
is disabled).  The Anonymous Identification feature automatically generates a random identifier for an anonymous user and stores it 
in a cookie.  On subsequent visits to a site, the identifier in the cookie is used as a surrogate "id" when retrieving profile 
information for an anonymous user.
<br /><br />
In the sample page, you get and set the background color using the syntax <code>Profile.PreferredBackgroundColor</code>.  The coding style
for using a <b>Profile</b> property is the same as accessing properties on any other class.  In this sample, the page uses some common
conversions available on the <code>System.Drawing.Color</code> structure to get and set <code>Profile.PreferredBackgroundColor</code>.
<br/><br/>
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/profiles/profiles_cs/Anonymous.aspx"
        ViewSource="~/aspnet/samples/profiles/Anonymous.src"
        Caption="C# Storing Profile data for anonymous users"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/profiles/profiles_vb/Anonymous.aspx"
        ViewSource="~/aspnet/samples/profiles/Anonymous.src"
        Caption="VB Storing Profile data for anonymous users"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="auth"></a>
<h3>Authenticated Profiles</h3>

In this sample, you log in as an authenticated user and set values for all of the profile properties.  When you first run the sample
you will be on a home page that is accessible to both anonymous and authenticated users.  Note that the background color is set to
the value you selected as an anonymous user in the previous sample.  Click on the link that allows you to create a new user (this
link is at the bottom of the login control). Enter a username and a password and then click the button to create a new user.  After
the new user is created, click on the button to continue to the page that displays the profile properties for the logged in user.
<br /><br />
When you first view the page with all of your profile properties, you will notice that the background color is set to the selection
you made earlier as an anonymous user.  The reason for this is covered in more detail in the next sample.  For now, notice that
you can set values for all of the profile properties. Also, notice that initially the automobile price point is set to the default
value defined in the profile schema.
<br/><br/>
After entering new values in the HTML form, press the "Update Preferences" button.  When the page refreshes the property
changes take immediate effect.  Click on the logout link to remove the Forms Authentication cookie from your machine.  Then close 
the browser.  Now, if you re-run the sample you will be prompted to log in again.  After entering your credentials and logging in,
notice that the profile properties page correctly displays the information you entered earlier.  If you click on the link that takes
you back to the home page, you will see that the home page uses both the name and the background color that you selected for the logged
in user. This demonstrates how profile properties can be used across secured and non-secure pages on a site.  On the home page
the background color and name are displayed using either the anonymous user's <b>Profile</b> (if you are not logged in yet), or the logged in
user's <b>Profile</b> (once you choose to log in).
<br /><br />
As with the anonymous example, this sample demonstrates how the <b>Profile</b> syntax follows the property accessor syntax for 
VB.NET and C#.  Notice that the syntax for accessing a property within a property group uses two levels of property accessors: 
<code>Profile.<b>AutomobilePreferences</b>.PricePoint</code>.  The property group simply acts as an intermediate property.  The code
for manipulating <code>Profile.AutomobilePreferences.CarModels</code> demonstrates using an <code>System.Collections.Arraylist</code>
 as a <b>Profile</b> property.  The string that is typed into the HTML form should be a comma-delimited set of names.
The page code parses this into an <code>System.Array</code> of strings prior to adding the array values to the 
<code>Profile.AutomobilePreferences.CarModels</code> property.  When retrieving the car models, 
<code>Profile.AutomobilePreferences.CarModels</code> is enumerated using standard for-each syntax.
<br /><br />
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/profiles/profiles_cs/secured/ProfileProperties.aspx"
        ViewSource="~/aspnet/samples/profiles/ProfileProperties.src"
        Caption="C# Storing Profile data for authenticated users"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/profiles/profiles_vb/secured/ProfileProperties.aspx"
        ViewSource="~/aspnet/samples/profiles/ProfileProperties.src"
        Caption="VB Storing Profile data for authenticated users"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="migrate"></a>
<h3>Migrating Anonymous Profiles to Authenticated Profiles</h3>

In earlier samples it was demonstrated that the background color for an anonymous user was carried over to the authenticated user.
You can verify this by running the sample below.  If you are already logged in, click the logout link at the bottom of the page. 
On the home page, select a different color from the dropdown in the upper left corner of the page.  The home page will refresh itself
and display using the selected background color.  Also, the page will have text stating "Hello Anonymous User" because the name property
on the <b>Profile</b> is only supported for authenticated users.  Log in to the site using the login control on the home page.  Notice
that once you log in, the background color on the profile properties page reflects the selection that was made earlier as an anonymous
user.  
<br /><br />
On the profile properties page, click the link that takes you back to the home page.  Notice that on the home page the name
that is displayed is based on the value set for the <code>Profile.Name</code> property.  Now that you are back on the home page as an
authenticated user, select a different color from the dropdown and click the update button.  The page refreshes and uses the updated
background color.  If you then click on the link that leads back to the profile properties page, you will see that the background 
color is retained.
<br /><br />
Once you are back on the profile properties page, click on the logout link.  This will redirect you back to the home page.  Notice
that when you are redirected to the home page, your previous selections for background color are no longer in effect.  The reason
for this is twofold.  First, once you are logged out, the site considers you to be an anonymous user - as a result any background
color that was set on the authenticated user's <b>Profile</b> is not available.  Secondly, any color selection that was previously
made when you were an anonymous user is no longer available.  The reason for this is that once an anonymous users logs in, the cookie 
containing the autogenerated anonymous identifier was removed from the browser.  As a result, when you log in, and then log out, the site
considers you to be a completely new anonymous user.  This interaction between anonymous users and logged in users leads to the need
for migrating data from anonymous profiles to authenticated profiles.
<br /><br />
The Profile feature exposes an event called the <b>MigrateAnonymous</b> event.  You can subscribe to this event by placing an event
handler in <code>global.asax</code> called <code>Profile_MigrateAnonymous</code>.  This event fires whenever an anonymous identifier is available (either as a cookie
or in the URL as a cookieless ticket), and the current user is authenticated.  Within the event handler, you can load the <b>Profile</b> for the anonymous user by
calling <code>Profile.GetProfile</code> and passing in the anonymous ID (the anonymous ID is one of the properties available off of the event arguments).  Once you 
have a reference to the anonymous <b>Profile</b>, you can transfer property settings from the anonymous <b>Profile</b> to the authenticated
<b>Profile</b>.  The sample <code>global.asax</code> file demonstrates transferring the background color from the anonymous <b>Profile</b>
 to the authenticated <b>Profile</b>.  The code also deletes the anonymous <b>Profile</b> data from the database.  Lastly, the code calls
a method in Anonymous Identification to clear the cookie that contains the anonymous identifier.  Note that developers must explicitly choose to clear
 the anonymous identifier from the request - otherwise ASP.NET will not automatically clear the identifier.  By the time the <b>MigrateAnonymous</b> event completes,
ASP.NET will have issued an Http header to clear the anonymous identifier from the browser, and on subsequent page requests the event will no longer fire.  
<br /><br />
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/profiles/profiles_cs/HomePage.aspx"
        ViewSource="~/aspnet/samples/profiles/Migration.src"
        Caption="C# Migrating Profile data from an anonymous user to an authenticated user"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/profiles/profiles_vb/HomePage.aspx"
        ViewSource="~/aspnet/samples/profiles/Migration.src"
        Caption="VB Migrating Profile data from an anonymous user to an authenticated user"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="inherit"></a>
<h3>Defining Profile Properties with a Custom Base Class</h3>

The web.config shown earlier included an attribute called <code>inherits</code> on the <code>&lt;profile&gt;</code> element.  This attribute instructs ASP.NET to autogenerate
a class for the <b>Profile</b> property by inheriting from a custom base class.  In this sample, the classname is <code>UserDefinedProfileClass</code>, and this class
is located in the <b>App_Code</b> directory.  The custom class inherits from <code>ProfileBase</code> because the autogenerated class for the <b>Profile</b> property
must always have <code>ProfileBase</code> in the inheritance hierarchy.  Any public properties defined on a custom base class are visible and useable from the 
<b>Profile</b> property.  
<br /><br />
Run the sample and log in again.  On the properties page, the data from the listbox containing junk food preferences is stored using the property defined on the custom
base class.  As with other properties on the <b>Profile</b>, the food preferences are accessed using standard property syntax:  <code>Profile.JunkFood</code>.
<br /><br />  
The advantage of defining a custom base class is that developers can "intercept" property sets and gets, and implement complex business
logic in the property getters and setters. In the sample code, the custom base class defines a property using Generics.  The property definition demonstrates the minimal
requirements:  the property implementations must call into the base class since it is the base class (<code>ProfileBase</code>) that contains the logic for serializing
data as well as communicating to the underlying provider(s).
<br /><br />
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
	ViewSource="~/aspnet/samples/profiles/ProfileSchema.src"
	Caption="Profile schema in web.config"
	runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
	ViewSource="~/aspnet/samples/profiles/ProfileSchema.src"
	Caption="Profile schema in web.config"
	runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/profiles/profiles_cs/secured/ProfileProperties.aspx"
        ViewSource="~/aspnet/samples/profiles/Inherits.src"
        Caption="C# Using a Custom Base Class"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/profiles/profiles_vb/secured/ProfileProperties.aspx"
        ViewSource="~/aspnet/samples/profiles/Inherits.src"
        Caption="VB Using a Custom Base Class"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="autosave"></a>
<h3>Controlling the Automatic Save Behavior of the Profile</h3>

The Profile feature will automatically determine whether or not a <b>Profile</b> is dirty.  If the <b>Profile</b> appears to be dirty, the <code>ProfileModule</code>
that runs at the end of each page request will call the <code>Save</code> method on the <b>Profile</b>, thus saving data using the configured provider(s).  However,
the Profile feature can only reliably detect changes to data when the data is typed as either a <code>System.String</code>, or as a primitive type like <code>System.Int16
</code>, <code>System.Int32</code>, etc...  If a <b>Profile</b> contains more complex data-types, the default behavior of the Profile feature assumes the <b>Profile</b>
is dirty, and will always attempt to save the data.  To optimize performance, a developer can implement logic in their pages to determine if the <b>Profile</b> really is 
dirty.  If a developer determines the <b>Profile</b> has not changed, they can hook the <code>ProfileAutoSaving</code> event by writing an event handler in <code>
global.asax</code>.  The event argument includes a property called <code>ContinueWithProfileAutoSave</code>.  If a developer sets this property to <code>false</code>,
then <code>ProfileModule</code> will not attempt to save the <b>Profile</b>.
<br /><br />
Run the sample and log in again if necessary. This page is the same as the profile properties page used earlier, with the minor addition of a second button.  If you edit
any of the profile data, and then click on the button that cancels the automatic save behavior, when the page refreshes, the old property values will be displayed.  The
code sample demonstrates subscribing to the <code>ProfileAutoSaving</code> event in <code>global.asax</code> and canceling the save if a property was set in the 
<code>HttpContext.Items</code> collection.  The button click event handler on the page sets this item to indicate that the automatic save behavior should be cancelled.
<br /><br />
Note that if a developer never wants the <code>ProfileModule</code> to attempt saves, the automatic save behavior for the feature can be turned off by setting the 
<code>automaticSaveEnabled</code> attribute on the <code>&lt;profile&gt;</code> element to <code>false</code>.
<br /><br />
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/profiles/profiles_cs/secured/AutoSave.aspx"
        ViewSource="~/aspnet/samples/profiles/AutoSave.src"
        Caption="C# Controlling Automatic Profile Saves"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/profiles/profiles_vb/secured/AutoSave.aspx"
        ViewSource="~/aspnet/samples/profiles/AutoSave.src"
        Caption="VB Controlling Automatic Profile Saves"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="delete"></a>
<h3>Deleting a Profile</h3>

Over time, the amount of profile data for a site will grow, especially for sites that use anonymous profiles.  The 
<code>ProfileManager</code> class provides a number of methods for deleting profile data.  This sample demonstrates using 
<code>ProfileManager.DeleteProfile</code> to delete the profile of the currently logged in user.  When you run the sample you will
first need to log in.  Once you are logged in, you can click on the delete button to clear the profile data for the current user.
  You will then be redirected to the profile properties page.  Notice that at this point all of your previous profile data has been
deleted and you need to re-enter new profile data on the HTML form.
<br /><br />
In production environments you would normally use <code>ProfileManager</code> in a scheduled maintenance task.  For example, you
could create a daily batch job that runs a console application using <code>ProfileManager</code> to delete profiles that have
been inactive for more than thirty days. Since the Profile feature is supported in non-ASP.NET environments (for example:  
console applications or NT service applications) you can create operations oriented applications using the <code>ProfileManager</code> 
class.
<br /><br />
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/profiles/profiles_cs/secured/DeleteProfile.aspx"
        ViewSource="~/aspnet/samples/profiles/DeleteProfile.src"
        Caption="C# Deleting a Profile"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/profiles/profiles_vb/secured/DeleteProfile.aspx"
        ViewSource="~/aspnet/samples/profiles/DeleteProfile.src"
        Caption="VB Deleting a Profile"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>

