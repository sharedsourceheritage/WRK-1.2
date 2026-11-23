<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>

<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>


<h2>Named Skins within a Theme</h2>

By default, a control definition in a skin file applies to all controls of the same type in pages of the themed application.  However, 
you may want controls of the same type to appear different in different parts of the application.  For example, you might want the
Text of a Label control to appear bold in one place and italic in another.  You can do this using named skins within a Theme.

<a name="named"></a>
<h3>Default and Named Skins</h3>

You can define different styles for controls of the same
type in a skin file by creating separate definitions of the control.  You can set a separate <b>SkinID</b> property on these control
definitions to a name of your choosing, and then set this same SkinID value on controls in pages that should have this specific 
skin applied.  In the absence of a SkinID property, the default skin (one without a SkinID property set) applies.
The following example demonstrates separate skins for the Label and Calendar controls.  Notice that the controls in the page with a
named SkinID get a different set of styles from the default skin.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/themes/NamedSkin_cs.aspx"
        ViewSource="~/aspnet/samples/themes/NamedSkin.src"
        Caption="C# Named Skins in a Theme"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/themes/NamedSkin_vb.aspx"
        ViewSource="~/aspnet/samples/themes/NamedSkin.src"
        Caption="VB Named Skins in a Theme"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

Named skins can be organized in a variety of ways inside a Theme's skin files.  Because a Theme can contain
multiple skin files, you might divide up named skins into separate files, where each skin file contained multiple
control definitions with the same SkinID.  For example, you could have three skin files in a Theme each named 
according to a particular SkinID value:

<pre class="code">
/WebSite1
  /App_Themes
    /MyTheme
      Default.skin
      Red.skin
      Blue.skin
</pre>

Alternatively, you might group skin files by control type, where each skin contains a set of skin definitions for
a particular control:

<pre class="code">
/WebSite1
  /App_Themes
    /MyTheme
      GridView.skin
      Calendar.skin
      Label.skin
</pre>
  
You might even divide up skin files according to the areas in your site, for example:

<pre class="code">
/WebSite1
  /App_Themes
    /MyTheme
      HomePage.skin
      DataReports.skin
      Forums.skin
</pre> 
The ability to have multiple skin files under a single Theme directory gives you this organizational
flexibility.  It also allows you to easily share skin definitions with others or copy skin definitions 
from one Theme to another without having to edit the other skin files in the Theme.

</asp:Content>

