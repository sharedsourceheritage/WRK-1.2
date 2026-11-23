<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.AdRotator" runat="server">
  AdRotator
</Acme:TypeRef>
</h2>

The <b>AdRotator</b> control presents ad images that, when clicked, navigate to a new Web location.  Each time the page
is loaded into the browser, an ad is randomly selected from a predefined list.  The following sample illustrates using the
<b>AdRotator</b> control.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/adrotator/AdRotator1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/adrotator/AdRotator1.src"
        Caption="C# AdRotator1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/adrotator/AdRotator1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/adrotator/AdRotator1.src"
        Caption="VB AdRotator1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

The rotation schedule for ads is defined in an XML file. The following example demonstrates a rotation schedule in the file <code>ads.xml</code>.
<pre class="code">
&lt;Advertisements&gt;
   &lt;Ad&gt;
      &lt;ImageUrl&gt;images/banner1.gif&lt;/ImageUrl&gt;
      &lt;NavigateUrl&gt;http://www.microsoft.com&lt;/NavigateUrl&gt;
      &lt;AlternateText&gt;Microsoft.com&lt;/AlternateText&gt;
      &lt;Keyword&gt;Computers&lt;/Keyword&gt;
      &lt;Impressions&gt;80&lt;/Impressions&gt;
   &lt;/Ad&gt;
&lt;/Advertisements&gt;
</pre>


The rotation file defines the following attributes of each ad.  Except for <b>ImageUrl</b>, these attributes are optional.

<br /><br />

<table class="table">
    <tr>
    <th style="width:25%"><b>Attribute</b></th>
    <th>Description</th>
    </tr>
    <tr>
    <td style="width:25%"><b>ImageUrl</b></td>
    <td>An absolute or relative URL to the ad image file.</td>
    </tr>
    <tr>
    <td style="width:25%"><b>NavigateUrl</b></td>
    <td>The Web location to navigate to when the image is clicked.  If <b>NavigateUrl</b> is not set, the image is not clickable.</td>
    </tr>
    <tr>
    <td style="width:25%"><b>AlternateText</b></td>
    <td>The text to render as the <b>ALT</b> attribute of the image.  When the page is viewed with Microsoft Internet Explorer, this acts as a ToolTip for the ad.</td>
    </tr>
    <tr>
    <td style="width:25%"><b>Keyword</b></td>
    <td>Specifies a category for the ad that the page can filter on.</td>
    </tr>
    <tr>
    <td style="width:25%"><b>Impressions</b></td>
    <td>A number that indicates the "weight" of the ad in the schedule of rotation relative to the other ads in
    the file.  The larger the number, the more often the ad will be displayed.</td>
    </tr>
</table>

<br />
<b>See Also: &nbsp;&nbsp;</b><asp:HyperLink Text="AdRotator Object Model" NavigateUrl="~/util/classbrowser.aspx?assembly=System.Web,%20Version=2.0.3600.0,%20Culture=neutral,%20PublicKeyToken=b03f5f7f11d50a3a&namespace=System.Web.UI.WebControls&class=AdRotator" runat="server"/>

</asp:Content>
