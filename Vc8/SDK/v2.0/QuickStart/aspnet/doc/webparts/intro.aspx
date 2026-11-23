<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>


<h2>Introducing Web Part Controls</h2>

    The Web Part Control Set includes the following controls:

<ul>
<li>
<b>Web Parts</b> are ASP.NET server controls that can be used and personalized with
the Web Part Control Set. Any ASP.NET server control or user control can behave
as a web part.&nbsp;</li>
<br />
<li>
<b>Web Part Zones</b> provide a way to organize parts into regions 
on the page. Zones are container controls that provide layout for parts, and add common, consistent UI elements
such as a Verb Menu and border to each part.
</li>
<br />
<li>
The <b>WebPartManager</b> control manages the pages personalization state, 
and co-ordinates communication between parts and zones. Every page that uses the
Web Part Control Set must have a WebPartManager control on it.
</li>
<br />
</ul>

The following code shows a web part zone with a single part. The parts in a zone
are contained in the zone's ZoneTemplate.&nbsp;

<br /><br />
<pre class="code">&lt;asp:WebPartZone ID="WebPartZone1" Runat="server"&gt;
  &lt;ZoneTemplate&gt;
    &lt;asp:Calendar Runat="server" ID="Calendar1"/&gt;
  &lt;/ZoneTemplate&gt;
&lt;/asp:WebPartZone&gt;  
</pre>
This example shows a simple page that uses web parts. It includes
a WebPartManager control, a WebPartPageMenu control, and two web part zones.
One of the zones contains an ASP.NET Calendar control.
<ol>
<li>Log in to the page.</li>
<li>Select "Design" from the menu's DropDownList.</li>
<li>Move Web Parts to different WebPartZones.</li>
<li>Close the browser, and run the sample again. You will see your personalized changes have been applied.</li>
</ol>

<Acme:LangSwitch runat=server>
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/intro/intro_cs/webparts.aspx"
        ViewSource="~/aspnet/samples/webparts/intro/webparts.src"
        Caption="C# Web Parts and Zones"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/intro/intro_vb/webparts.aspx"
        ViewSource="~/aspnet/samples/webparts/intro/webparts.src"
        Caption="VB Web Parts and Zones"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />
Web parts pages can also contain web parts that are not visible by default.
The user can add these parts to the page through a web part catalog.
A web part catalog allows you to define optional content not visible by default
on the page. 
<br /><br />
To provide a catalog on the page, you need to add a special zone control, called the <b>CatalogZone</b>,
to your page. In this zone, you can add catalog parts that provide different kinds
of controls. 
This example shows a page with a CatalogZone containing a PageCatalogPart, which
provides a catalog of all closed web parts defined on the page.
<br />
<ol>
<li>Log in to the page.</li>
<li>Click the dropdown arrow on the control's verbs Menu then click the Close verb on the calendar to close the Web Part.</li>
<li>Select "Catalog" from the menu's DropDownList.</li>
<li>Check the checkbox next to the part named "Untitled", and click the Add button. The calendar will be added back to the first zone.</li>
</ol>
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/intro/intro_cs/webpartcatalog.aspx"
        ViewSource="~/aspnet/samples/webparts/intro/webpartcatalog.src"
        Caption="C# Web Part Catalogs"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/intro/intro_vb/webpartcatalog.aspx"
        ViewSource="~/aspnet/samples/webparts/intro/webpartcatalog.src"
        Caption="VB Web Part Catalogs"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />
In addition to allowing users to personalize the layout and visibility of web parts on a page,
you can also let users edit properties of each web part. Every part has a set of default properties
that can be personalized. Each control can also provide additional properties to be
personalized.
<br /><br />
To allow editing of control properties, you need to add a special zone control,
called the <b>EditorZone</b>, to the page. To this zone, you can add one or more
editor parts. The following editor parts are provided:
<ul>
<li>The <b>AppearanceEditorPart</b> control allows users to edit the visual appearance
of a web part.
<br />
</li>
<li>The <b>BehaviorEditorPart</b> control allows users to edit behavior properties of
a web part.
<br />
</li>
<li>The <b>LayoutEditorPart</b> control allows users to edit the layout of a web part.
<br />
</li>
<li>The <b>PropertyGridEditorPart</b> control displays a property grid that allows users to edit 
custom personalizable properties for a web part.</li></ul>
You can also create your own custom editor parts by inheriting from the 
<b>EditorPart</b> base class.
<br /><br />
This example shows a page with an EditorZone containing an AppearanceEditorPart.

<ol>
<li>Log in to the page.</li>
<li>Select "Edit" from the menu's DropDownList.The editor will now be visible. </li>
<li>Click the Edit Verb on the calendar's Verbs Menu to edit the Web Part. </li>
<li>Edit the title in the editor, and click OK. The title of the calendar will now be updated. </li>
</ol>
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/intro/intro_cs/webparteditor.aspx"
        ViewSource="~/aspnet/samples/webparts/intro/webparteditor.src"
        Caption="C# Web Part Editors"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/webparts/intro/intro_vb/webparteditor.aspx"
        ViewSource="~/aspnet/samples/webparts/intro/webparteditor.src"
        Caption="VB Web Part Editors"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>

