<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>

<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>


<h2>Applying Styles, Themes, and Skins</h2>

<div class="new">

<h3>What's New in 2.0</h3>

<ul>
  <li><b>Themes and Skins - </b> The Themes and Skins feature of ASP.NET 2.0 allows you to factor style and layout information into a separate group of files, 
collectively called a Theme.  A Theme can then be applied to any site to affect the look and feel of pages and controls within the site.  Style changes to a site can then be
easily maintained by making changes to the Theme, without having to edit the individual pages in your site.  Themes can also be shared with other developers.</li>
</ul>

This section discusses these and other style-related features in ASP.NET 2.0. 

</div>

<br /><br />

ASP.NET includes a number of features for customizing the look-and-feel or style of pages and controls in your 
application.  Controls support a <b>Style</b> object model for setting stylistic properties such as fonts, borders, background and 
foreground colors, width, height, and more.  Controls also fully support Cascading Style Sheets (CSS) for factoring style settings
separately from control properties.  You can define style information as control properties or CSS, or you can also define this 
information in a separate group of files called a <b>Theme</b>, to be applied to all or a portion of the pages in your application.  Individual
control styles are specified as a <b>Skin</b> within a Theme.  
<br /><br />

This section demonstrates a variety of uses for the Styles, Themes, and Skins features in ASP.NET 2.0.
<br /><br />


</asp:Content>

