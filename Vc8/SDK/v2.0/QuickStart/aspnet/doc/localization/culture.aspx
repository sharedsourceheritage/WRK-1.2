<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>

<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>


<h2>Culture-sensitive Formatting</h2>

<a name="ielanguage"></a>
<h3>Setting a Preferred Language in Internet Explorer</h3>

HTTP allows browsers to send a list of preferred languages to the Web server using the Accept-Language HTTP request header field. In Internet Explorer the list can be configured like this: 
<ul>
    <li>Select the "Tools | Internet Options" command. </li>
    <li>Select the "Languages" button. </li>
    <li>In the dialog that is shown, click on the "Add" button to add a new language and select a new culture. Click "OK". </li>
    <li>Ensure your preferred language is at the top of the list. Select that language and click "Move Up". Click "OK" to exit the dialog. </li>
    <li>Refresh the page using F5. </li>
</ul>

Initially the list is preconfigured to the language of the Internet Explorer user interface, which makes sense as typically users want to see Web content in the language of the computer they are working on. Other browsers have similar features to configure this header field.

<a name="autoculture"></a>
<h3>Auto-detecting the browser language for culture-sensitive formatting <span class="newinline">New in 2.0</span></h3>
The language list can be used to determine which culture the user most likely prefers for formatting of numbers, dates and times. ASP.NET v2.0 now provides functionality to easily detect the first language in the list and use this for formatting:

<pre class="code">
&lt;%@ Page Culture="auto:en-US" %&gt;
</pre>

If the first language in the list matches the name of a specific culture supported by the .NET Framework, ASP.NET will set the CurrentCulture of the running thread to this culture. This happens early in the page life cycle so that all subsequent culture-sensitive formatting will be done with this culture.
<br /><br />
If the first language in the list matches the name of a neutral culture supported by the .NET Framework, ASP.NET will try to use the function <code>CultureInfo.CreateSpecificCulture()</code> to create a specific culture for the purpose of formatting. For example, this would map <code>fr</code> into the culture for French (France). However, this determination could be inappropriate for somebody in the French-speaking part of Canada, which is why an application should provide the means to configure both culture and language - more on this personalization in the localization section.
<br /><br />
If the first language in the list isn't a culture supported by the .NET Framework, ASP.NET will fall back to the culture specified after the colon in the Culture declaration. This would be <code>en-US</code> - English (United States) in the example above.
<br /><br />
This auto-detection functionality can be used in all places where Culture can be specified declaratively, such as in the <code>globalization</code> section of <code>web.config</code>. The auto-detection works the same for UICulture, which is used for localization and is explained later.
<br /><br />
The following sample demonstrates a Currency Exchange Calculator that reacts to different language settings in the browser (see above for information how to change this). It will display the date in the format appropriate for the first language in the list and also uses the correct decimal separator for the exchange values. Furthermore, this decimal separator can be used for the entry of the value to be converted.

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/localization/Global_cs/Global_cs.aspx"
        ViewSource="~/aspnet/samples/localization/Global.src"
        Caption="Culture-sensitive date and number formatting (C#)"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/localization/Global_vb/Global_vb.aspx"
        ViewSource="~/aspnet/samples/localization/Global.src"
        Caption="Culture-sensitive date and number formatting (VB)"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

In order to view text in some East Asian languages and some languages with complex scripts, you might need to install the appropriate font for Internet Explorer. Refer to Internet Explorer Help Topics for more information (see in the index under "foreign languages used in Web pages"). Alternatively you can install additional fonts from the Regional and Language Options of the Control Panel.

<br /><br />
This sample will not display dates in the correct reading order for right-to-left languages like Arabic or Hebrew. See the second and third sample in the <a href="localization.aspx">Localization</a> section for information on how to handle this case.

</asp:Content>

