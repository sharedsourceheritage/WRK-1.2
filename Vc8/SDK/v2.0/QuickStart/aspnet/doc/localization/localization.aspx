<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>

<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Localization</h2>

To create a Web application that can be multilingual was a complex task prior to ASP.NET v2.0. If you used resource files (RESX) and the ResourceManager, you needed to separate out localizable elements manually and perform your own resource loading, which required some effort and code. ASP.NET v2.0, simplifies this process greatly and brings a wealth of features such as:

<ul>
  <li>Auto detection of the Accept-Language HTTP request header field sent by the client browser</li>
  <li>Declarative resource expressions to tie controls or their properties to resources</li>
  <li>Programmatic access to resources and strongly-typed resources</li>
  <li>Automatic compilation and linking of RESX or RESOURCE files into runtime satellite assemblies</li>
  <li>Further design-time support for creation of resources</li>
  <li>A full extensibility model so that the RESX model can be swapped out</li>
</ul>

When building a multilingual Web application, you benefit from a single page source that requires much less maintenance compared to the language-separated site or page structure. ASP.NET v2.0 accomplishes this by providing a declarative model for resource handling through <a href="#expressions">resource expressions</a>. Resource expressions are a sub-feature of the overall expressions feature, which can be thought of much like databinding expressions from ASP.NET v1.0. Expressions, however, are parse-time property setters that do not require the user to explicitly call a method like <code>DataBind()</code>.
<br /><br/>

ASP.NET v2.0 provides automatic support for resource (RESX or RESOURCE) files that follow a specific naming convention and that reside in specialized folders within the application. This allows you to add resource files without any compilation step or satellite assemblies and allows you to provide resources that can be scoped to a page or an application. The ASP.NET runtime uses the .NET Framework <code>ResourceManager</code> to perform resources lookup. This model has many advantages such as the automatic fall-back mechanisms and custom culture support.
<br/><br/>

If RESX resource files are not your preferred source format for storing translations, you'll find the entire model extensible.
<br/><br/>

The samples described here can be executed for English-US(en-US), French(fr), German(de), Spanish(es), Japanese(ja), and Arabic(ar) (Arabic only for the last two samples in the page). Other languages will defer to their fallback culture, or ultimately to English-US. Refer to <a href="culture.aspx#ielanguage">Setting a Preferred Language in Internet Explorer</a> in the previous topic so that you can see the use of resources in action.
<br/><br/>

<a name="simpleexample"></a>
<h3>A Simple Example <span class="newinline">New in 2.0</span></h3>

The following example demonstrates the localization of a Label control in a page called LabelLocalization.aspx.

<pre class="code">
&lt;%@ Page UICulture="auto" Culture="auto" %&gt;
&lt;form runat="server"&gt;
  &lt;asp:Label ID="Label1" runat="server" Text="&lt;%$ Resources:Label1TextKey %&gt;"
	Font-Name="&lt;%$ Resources:Label1FontNameKey %&gt;"/&gt;
&lt;/form&gt;
</pre>

The page defines a <code>Page</code> directive with specific <code>UICulture</code> and <code>Culture</code> attributes. The attribute values are automatic. This instructs ASP.NET to detect and set the current thread culture and UI culture for the page execution based on the preferred culture of the client browser. For a detailed explanation of how this works, see <a href="culture.aspx#autoculture">Auto-detecting the browser language for culture-sensitive formatting</a>. As mentioned in the previous topic <code>Culture</code> controls formatting of dates and numbers, whereas <code>UICulture</code> controls resource loading - that is translated text and localized control properties like color or font.
<br /><br />

The <code>Text</code> and <code>Font-Name</code> properties of the Label are bound to resource expressions that resolve to a resource key, which is used to perform assignment of the property to a value from, in this case, a local resource. 
<br/><br/>

Alongside the LabelLocalization.aspx page is a peer folder called App_LocalResources. This is where the local resource(s) reside and are named appropriately for the page, for example:

<ul>
  <li> LabelLocalization.aspx.resx. The culture-neutral resource file
  <li> LabelLocalization.aspx.fr.resx. The culture-specific resource file, (French)
  <li> LabelLocalization.aspx.de.resx. The culture-specific resource file, (German)
  <li> LabelLocalization.aspx.ja.resx. The culture-specific resource file, (Japanese)
  <li> LabelLocalization.aspx.ar.resx. The culture-specific resource file, (Arabic)
</ul>

These RESX files contain a keyname-value mapping. For example in LabelLocalization.aspx.resx

<pre class="code">
&lt;data name="Label1TextKey"&gt;
  &lt;value xml:space="preserve"&gt;Welcome to ASP.NET Localization&lt;/value&gt;
&lt;/data&gt;
</pre>

Executing this page yields the rendering for the Label using a <code>Text</code> property from the resource for German, French, Japanese, or other languages.

<a name="expressions"></a>
<h3>Resource Expressions <span class="newinline">New in 2.0</span></h3>

There are two forms of resource expressions, explicit and implicit. 
<br/><br/>
<table class="table">
  <tr>	<th>Resource Expression form</th><th>Description</th></tr>
  <tr>	<td><u>Explicit</u></td>
	<td>
<code>&lt;%$ Resources:[filename prefix,]resource-key %&gt;</code><br/><br/>
The Explicit expression is used to define the value of a control property in declarative syntax, and the <i>resource-key</i>, which is required, is used to map to the value from the resource. The <i>filename prefix</i> parameter is optional, but the <i>filename</i> specifies the name of a resource file(s) that resides in the <a href="#resources">global resources</a> folder.		
	</td></tr>
  <tr>	<td><u>Implicit</u></td>
	<td>
<code>&lt;asp:Label ID="Label1" runat="server" meta:resourcekey="resource-key-prefix" /&gt;</code>
<br/><br/>
The Implicit expression is used as an attribute on a control or object in declarative syntax and defines a <i>resource-key-prefix</i>, which is used to perform many property assignments for the control. The resource file contains many potential resource-keys of the general form <i>resource-key-prefix.Property</i> - for example, Label1KeyPrefix.Text and Label1KeyPrefix.Font-name. All resources are obtained from <a href="#LocalRes">local resources</a> only. You can think of the expressions as a short-hand notation for mapping one to many control properties without explicitly defining the properties in the page.</td></tr>
</table>

<br/>

<a name="resources"></a>
<h3>Global and Local Resources <span class="newinline">New in 2.0</span></h3>

Global resources reside in a specialized folder called <code>/App_GlobalResources</code>, located at the root of the application. All pages, user-controls, etc. can access these resources, so they typically are used as shared resources. The name of the resource file is used in explicit expressions, but also forms the namespace.classname for strongly-typed access under the <code>Resources</code> namespace in your application.
<br/><br/>

<a name="LocalRes">Local resources</a> are defined in a peer-level <code>/App_LocalResources</code> folder. RESX files follow the naming convention of the associated page, user-control, or master-page, along with the culture definition. For example, <code>foo.aspx</code> will refer to the <code>/App_LocalResources/foo.aspx.resx</code> culture-neutral file and <code>/App_LocalResources/foo.aspx.fr.resx</code> and
<code>/App_LocalResources/foo.aspx.ja.resx</code> culture-specific files. Only the associated page can access these resources using the explicit or implicit resource expression. There is a programmatic method available to access these resources in code.	

<a name="implicit"></a>
<h3>Implicit Expressions to Local Resources <span class="newinline">New in 2.0</span></h3>

This sample was created from the sample showing culture-correct formatting by using Visual Web Developer to create the local resources. All text on the page was converted into ASP.NET Label controls, and after this the "Generate Local Resource" command from the Tools menu in design view generated the resource file for the default language (English-US in this case). This resource file was then translated to Japanese, German, French, and Spanish. No additional coding was necessary to enable the page for localization.
<br /><br />
The designer added the <code>UICulture</code> attribute to the <code>Page</code> directive and implicit resource expressions like 
<pre class="code">
&lt;asp:Label ID="LabelTitle" runat="server" Text="Currency Exchange Calculator" meta:resourcekey="LabelResource1"&gt;
&lt;/asp:Label&gt;</pre>
to enable the loading of resources during runtime. 
<br /><br />
The designer analyzes controls on the page for localizable resources. As the currency names on the page get filled in programmatically it cannot detect that they should be added to the localizable resources too - how this can be done manually is shown in a sample further down.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/localization/LocalizeImp_cs/LocalizeImp_cs.aspx"
        ViewSource="~/aspnet/samples/localization/LocalizeImp.src"
        Caption="Localization using implicit expressions (C#)"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/localization/LocalizeImp_vb/LocalizeImp_vb.aspx"
        ViewSource="~/aspnet/samples/localization/LocalizeImp.src"
        Caption="Localization using implicit expressions (VB)"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="explicit"></a>
<h3>Explicit Expressions to Local Resources <span class="newinline">New in 2.0</span></h3>
The page above using implicit expressions is still not completely translated - the currency names in the drop down and the exchange value list are still in English. Also the page is not yet translated to Arabic, and the German version should get a different background color for the title and date labels.
<br /><br />
Arabic is a language that is written from right to left. To instruct the browser to display the page in the correct directionality, an additional resource called <code>HTMLDirectionality</code> was added. Using an explicit expression to this local resource, the <code>dir</code> attribute of the <code>html</code> element of the page is set.
<br /><br />
The following sample also uses explicit expressions to modify both <code>Text</code> and <code>BackColor</code> of the title and date labels. Note that the resources for languages that don't need to modify these values don't need to contain the resources - the fallback mechanism of .NET Framework resources will always pick up the default value contained in the default resources.

<a name="programmatic"></a>
<h3>Programmatic Access to Global and Local Resources <span class="newinline">New in 2.0</span></h3>
Text that gets generated programmatically cannot be loaded by using resource expressions, nor can the Visual Web Developer designer automatically generate resources for it. ASP.NET offers the functions <code>GetGlobalResourceObject()</code> and <code>GetLocalResourceObject()</code> to deal programmatically with these cases. This is how the sample below loads the currency names from the added <code>CurrencyNames</code> resources that are available application-wide.

<a name="static"></a>
<h3>Localizing Static Content <span class="newinline">New in 2.0</span></h3>
Typically developers create a Web application that contains static text as, for example the disclaimer on the page. It is not necessary to declare this as a <code>Label</code> control, because a special <code>Localize</code> control is available for this purpose. This control allows the editing of text not only in the property grid, but also directly in design view.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/localization/LocalizeImpExp_cs/LocalizeImpExp_cs.aspx"
        ViewSource="~/aspnet/samples/localization/LocalizeImpExp.src"
        Caption="Localization using implicit and explicit expressions as well as programmatic access (C#)"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/localization/LocalizeImpExp_vb/LocalizeImpExp_vb.aspx"
        ViewSource="~/aspnet/samples/localization/LocalizeImpExp.src"
        Caption="Localization using implicit and explicit expressions as well as programmatic access (VB)"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="langprefs"></a>
<h3>Storing Language Preferences <span class="newinline">New in 2.0</span></h3>

In some cases the <code>Culture</code> and <code>UICulture</code> selection defaults chosen by auto-detection might not be convenient for the user (e.g. a Spanish-speaking user using a computer in a Chinese Internet café). In these cases Web applications need to give users the option to change the displayed language and/or cultural preferences. The following sample shows how to build a <code>DropDownList</code> control that lists all the available languages. It changes the language according to the selection in the drop-down and stores the selection using the new ASP.NET v2.0 Profiles feature.
<br /><br />

It is important to note that changes to <code>Thread.CurrentThread.CurrentCulture</code> and <code>Thread.CurrentThread.CurrentUICulture</code> need to be made in the <code>InitializeCulture()</code> method, because the auto-detection of the preferred browser language happens early during the page life cycle.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/localization/LocalizePers_cs/LocalizePers_cs.aspx"
        ViewSource="~/aspnet/samples/localization/LocalizePers.src"
        Caption="Selecting and storing language preferences using personalization (C#)"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/localization/LocalizePers_vb/LocalizePers_vb.aspx"
        ViewSource="~/aspnet/samples/localization/LocalizePers.src"
        Caption="Selecting and storing language preferences using personalization (VB)"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>

