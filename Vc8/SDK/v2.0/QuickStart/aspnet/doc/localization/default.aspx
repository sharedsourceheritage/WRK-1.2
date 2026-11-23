<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>

<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>


<h2>Internationalizing Your Application</h2>

<div class="new">

<h3>What's New in 2.0</h3>

<ul>
  <li><b>Auto Detection of Browser Language - </b> You can easily adapt your application's behavior to the user's culture by determining the language of the requesting browser.</li><br /><br />
  <li><b>Declarative Localization Expressions - </b> Declarative resource expressions allow you to make your application multilingual without manually writing code to retrieve and substitute resources into your pages.  You simply define a resource substitution using the new expression syntax in ASP.NET 2.0.</li><br /><br />
  <li><b>Generating Local Resources - </b> ASP.NET 2.0 supports the standard resx file format to automatically retrieve resources at runtime. Developers can also provide alternative sources for localization resources through extensibility.  Visual Web Developer includes support to easily generate application resources as well.</li></ul>
This section discusses these and other internationalization features in ASP.NET 2.0.
</div>

<br/>

The Web has had worldwide reach since its inception. Users have different cultural expectations and speak different languages. In this Quickstart you will learn how powerful new ASP.NET v2.0 features make it easier to adapt your Web application to different countries, regions, and markets.
<br /><br />

In the <a href="culture.aspx">Culture-sensitive Formatting</a> section, learn how browsers communicate their language preferences to the server. Learn how you can use auto-detect
    functionality in ASP.NET v2.0 to determine date and number formatting that is appropriate for the user.
<br /><br />

The <a href="localization.aspx">Localization</a> section shows how new declarative expressions in markup allow you to use .NET Framework resources both for resources that are defined for a local page as well as resources shared by the whole application, without
    coding. The section also explains how to use resources in code, if necessary, as well as how to use the auto-detect functionality to determine the language of the content that is presented to the user. Lastly, a sample in the section shows how to let the user choose a language and persist this choice in the user preferences using the Profile feature.
<br /><br />

Users may not always be using browsers that support Unicode. The <a href="encoding.aspx">Encoding</a> section explains how your applications can be configured for this case.
<br /><br />

The sample used to demonstrate these different internationalization features is a currency calculator. It is gradually improved from an application that only supports culture-sensitive formatting to a fully multilingual, personalized site available in English, French, German, Japanese, Spanish, and Arabic.</asp:Content>

