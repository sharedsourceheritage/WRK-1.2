<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Personalizing Using Web Parts</h2>

<div class="new">

<h3>What's New in 2.0</h3>

<ul>
  <li><b>Web Part Controls - </b> Web parts are an exciting new family of controls that enable you to add rich, personalized content and layout to your site, and well as the ability to edit that content and layout directly from your application pages. These controls rely on the personalization services in ASP.NET 2.0 to provide a unique experience for each user in your application. Any control can easily be made into a web part to participate in these personalization services.</li>
</ul>
This section discusses the new Web Part controls in ASP.NET 2.0.
</div>

<br />

Modern web sites often require UIs that are dynamic and personalizable. Users of these sites
are able to customize the layout and appearance of content of pages according to their 
individual preferences, and personalize page content to display most relevant information.
Traditionally, building these sites has required lots of complex code, from creating a 
secure, comprehensive personalization infrastructure on the server to writing elaborate
client side script to deliver a rich browser experience.
<br /><br />
ASP.NET 2.0 includes a new Web Part Control Set that makes it dramatically simple 
to create pages with dynamic, modular layout and personalized content.
<br /><br />
<div class="new">
  <span style="color:red"><b>NOTE: In order to use the samples in this section, you need to create a user and password to login.  The password must satisfy the following strength requirements or it will be considered invalid:
  <ul>
    <li>Must contain at least 7 characters
    <li>Must contain at least 1 non-alphanumeric character (punctuation)
  </ul>
Examples: test@123, out(in), far$ide
</b></span>
</div>

</asp:Content>

