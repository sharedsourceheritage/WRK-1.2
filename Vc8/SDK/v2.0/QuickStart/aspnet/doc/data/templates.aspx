<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>

<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Databinding in Templates</h2>

Templated data-bound controls give you ultimate flexibility over the rendering of data in your pages.
You may recall several templated controls from ASP.NET v1.x, such as the DataList and Repeater controls.
Those controls continue to be supported in ASP.NET 2.0, however the way that you data bind controls 
inside templates have been simplified and improved in this release.  This section discusses the various
ways to data bind inside a data-bound control template.

<a name="expressions"></a>
<h3>Databinding Expressions</h3>

ASP.NET 2.0 adds improvements to data binding in templates, simplifying the data binding 
syntax from the full v1.x syntax of <code>DataBinder.Eval(Container.DataItem, <i>fieldname</i>)</code> 
to simply <code>Eval(<i>fieldname</i>)</code>.  Like DataBinder.Eval, the Eval method also accepts an
optional formatString parameter.  
The shortened Eval syntax is different from DataBinder.Eval in that Eval automatically resolves the field against the
DataItem property of the nearest container object (DataListItem, in the examples above), whereas DataBinder.Eval takes an
argument for the container.  For this reason, Eval is only used inside a template of a data-bound control and cannot be
used at the Page level.  Of course, DataBinder.Eval continues to be supported in ASP.NET 2.0 pages, so you 
use that instead for scenarios where the simplified Eval syntax is not supported.

<pre class="code">
&lt;asp:DataList DataSourceID="ObjectDataSource1" runat="server"&gt;
  &lt;ItemTemplate&gt;
    &lt;asp:Image ImageUrl='&lt;%# Eval("FileName", "images/thumbs/{0}") %&gt;' runat="server"/&gt;
    &lt;asp:Label Text='&lt;%# Eval("Caption") %&gt;' runat="server"/&gt;
  &lt;/ItemTemplate&gt;
&lt;/asp:DataList&gt;
</pre>

The example below shows the new 
simplified <code>Eval</code> data binding syntax to bind an Image, Label and HyperLink control in a 
DataList ItemTemplate.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/PhotoAlbum_cs/PhotosDataListPlain.aspx"
        ViewSource="~/aspnet/samples/data/PhotosDataListPlain.src"
        Caption="C# DataBinding in a DataList Template"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/PhotoAlbum_vb/PhotosDataListPlain.aspx"
        ViewSource="~/aspnet/samples/data/PhotosDataListPlain.src"
        Caption="VB DataBinding in a DataList Template"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

Data bindings can also be included as part of a theme definition for a control, so that it is possible
to dramatically alter the layout and look-and-feel of a templated control simply by changing the applied Theme.
Only Eval (or Bind, as discussed later) can be used in a Theme template, however.  Binding to arbitrary
user code is disallowed.  The next example shows a Theme applied to the previous example to create 
a completely different look for the photos page.  For more information about Themes, refer to the 
<asp:HyperLink NavigateUrl="~/aspnet/doc/themes/default.aspx" runat="server">Applying Styles, Themes 
and Skins</asp:HyperLink> section of this tutorial.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/PhotoAlbum_cs/PhotosDataListTheme.aspx"
        ViewSource="~/aspnet/samples/data/PhotosDataListTheme.src"
        Caption="C# DataBinding in a DataList Template (Themed)"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/PhotoAlbum_vb/PhotosDataListTheme.aspx"
        ViewSource="~/aspnet/samples/data/PhotosDataListTheme.src"
        Caption="VB DataBinding in a DataList Template  (Themed)"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>



<a name="formview"></a>
<h3>The FormView Control</h3>

The DataList control iterates over each data item from the data source and outputs the ItemTemplate
once for each item.  This is useful for rendering a list of items, but often you want to data bind
against a single data item inside a form.  For this purpose, ASP.NET 2.0 introduces the <b>FormView</b>
control, which renders a single data item at a time in a freeform template.  
The main difference between DetailsView and FormView is
that DetailsView has a built-in tabular rendering, whereas FormView requires a user-defined template
for its rendering.  The FormView and DetailsView object model are very similar otherwise.
The following example demonstrates a FormView control bound to an ObjectDataSource.  The ItemTemplate
property of FormView contains a data-bound Image, Label and HyperLink like the previous DataList example.
<br /><br />


<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/PhotoAlbum_cs/PhotoFormView.aspx"
        ViewSource="~/aspnet/samples/data/PhotoFormView.src"
        Caption="C# DataBinding in a FormView Template"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/PhotoAlbum_vb/PhotoFormView.aspx"
        ViewSource="~/aspnet/samples/data/PhotoFormView.src"
        Caption="VB DataBinding in a FormView Template"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

Like DetailsView, FormView 
keeps track of the current item being rendered, and can optionally support paging over multiple data 
items when the data source returns a list.  The following example shows a FormView with paging enabled.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/FormView_cs.aspx"
        ViewSource="~/aspnet/samples/data/FormView.src"
        Caption="C# DataBinding in a FormView Template (Paged)"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/FormView_vb.aspx"
        ViewSource="~/aspnet/samples/data/FormView.src"
        Caption="VB DataBinding in a FormView Template (Paged)"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="twowaybind"></a>
<h3>Two-way Databinding</h3>

The FormView supports automatic Updates, Inserts, and Deletes through its associated
data source control just like the DetailsView control.  To define the input UI for editing
or inserting, you define an EditItemTemplate or InsertItemTemplate in addition to the
ItemTemplate.  In this template you will data bind input controls such as TextBox, 
CheckBox, or DropDownList to the fields of the data source.  Data bindings in these
templates use a "two-way" data binding syntax, however, to allow the FormView to extract the 
values of input controls from the template in order to pass to the data source.  These 
data bindings use the new <code>Bind(<i>fieldname</i>)</code> syntax instead of Eval.
<br /><br />

<b>Important:</b> A control that is data-bound using the <code>Bind</code> syntax must have an <code>ID</code> property set.
<br /><br />

<pre class="code">
&lt;asp:FormView DataSourceID="ObjectDataSource1" DataKeyNames="PhotoID" runat="server"&gt;
  &lt;EditItemTemplate&gt;
    &lt;asp:TextBox ID="CaptionTextBox" Text='&lt;%# Bind("Caption") %&gt;' runat="server"/&gt;
    &lt;asp:Button Text="Update" CommandName="Update" runat="server"/&gt;
    &lt;asp:Button Text="Cancel" CommandName="Cancel" runat="server"/&gt;
  &lt;/EditItemTemplate&gt;
  &lt;ItemTemplate&gt;
    &lt;asp:Label Text='&lt;%# Eval("Caption") %&gt;' runat="server" /&gt;
    &lt;asp:Button Text="Edit" CommandName="Edit" runat="server"/&gt;
  &lt;/ItemTemplate&gt;
&lt;/asp:FormView&gt;
</pre>

When performing updates or inserts with the GridView or DetailsView, where there are BoundFields defined 
for the Columns or Fields for the control, GridView or DetailsView is responsible for creating
the input UI in Edit or Insert mode, so it can automatically extract these input values
to pass back to the data source.  Because templates contain arbitrary user-defined UI controls, 
the two-way data binding syntax is necessary to allow templated controls like FormView
to know which control values should be extracted from the template for an update, insert, 
or delete operation.  You can still use the Eval syntax in an EditItemTemplate 
for data bindings that should not be passed back to the data source.  Note also that the 
FormView supports the <b>DataKeyNames</b> property just like DetailsView and GridView for
retaining the original values of primary key fields to pass back to updates/deletes, even
when these fields are not rendered.
<br /><br />

The FormView supports the DefaultMode property for specifying the default template to display, but
by default the FormView starts in ReadOnly mode and renders the ItemTemplate.  To enable UI for
transitioning from ReadOnly mode to Edit or Insert mode, you can add a <b>Button</b> control
to the template and set its <b>CommandName</b> property to <code>Edit</code> or <code>New</code>. From within the
EditItemTemplate, you can add Buttons with CommandName set to <code>Update</code> or <code>Cancel</code> to 
commit or abort the update operation.  Similarly, you can add Buttons with CommandName set
to <code>Insert</code> or <code>Cancel</code> to commit or abort the insert operation.
<br /><br />

The following example shows a FormView with both an ItemTemplate and EditItemTemplate defined.  The 
ItemTemplate contains controls bound using Eval (one-way), whereas the EditItemTemplate contains
a TextBox control two-way bound using a Bind statement.  The primary key field (<code>PhotoID</code>) is 
round-tripped in viewstate using the DataKeyNames property.  The FormView contains command
buttons for switching between its templates.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/PhotoAlbum_cs/PhotoFormViewEdit.aspx"
        ViewSource="~/aspnet/samples/data/PhotoFormViewEdit.src"
        Caption="C# Two-Way Databinding in a FormView Edit Template"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/PhotoAlbum_vb/PhotoFormViewEdit.aspx"
        ViewSource="~/aspnet/samples/data/PhotoFormViewEdit.src"
        Caption="VB Two-Way Databinding in a FormView Edit Template"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

The GridView and DetailsView also support templated UI, through the use of a TemplateField
added to the Columns or Fields collection.  TemplateField supports ItemTemplate, EditItemTemplate, 
and InsertItemTemplate (DetailsView only) for specifying the UI for the field in the different
rendering modes of these controls.  Just like the FormView example above, two-way databindings
in the EditItemTemplate or InsertItemTemplate will allow GridView or DetailsView to extract values 
from controls in these templates.  A common use for TemplateField is to add validator controls
to the EditItemTemplate for declarative validation of GridView or DetailsView operations.
The example below shows an example of this technique.  For more information about the validation
controls available in ASP.NET, refer to the <asp:HyperLink NavigateUrl="~/aspnet/doc/validation/default.aspx" runat="server">Validating Form Input Controls</asp:HyperLink> section of this tutorial.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/PhotoAlbum_cs/AlbumsDataSetValidate.aspx"
        ViewSource="~/aspnet/samples/data/PhotosAlbumValidate.src"
        Caption="C# Validation in a GridView Edit Template"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/PhotoAlbum_vb/AlbumsDataSetValidate.aspx"
        ViewSource="~/aspnet/samples/data/PhotosAlbumValidate.src"
        Caption="VB Validation in a GridView Edit Template"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

Another use for TemplateField is to customize the input controls used to enter values for 
GridView or DetailsView columns/fields.  For example, you can place a DropDownList control
inside the EditItemTemplate of TemplateField to allow selection from a pre-defined
list of values.  The example below demonstrates this technique.  Note that the DropDownList
in this example is data-bound to it's own data source control to obtain the values of the
list dynamically.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/PhotoAlbum_cs/AlbumsDataSetDropDown.aspx"
        ViewSource="~/aspnet/samples/data/PhotosAlbumDropDown.src"
        Caption="C# DropDownList in a GridView Edit Template"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/PhotoAlbum_vb/AlbumsDataSetDropDown.aspx"
        ViewSource="~/aspnet/samples/data/PhotosAlbumDropDown.src"
        Caption="VB DropDownList in a GridView Edit Template"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>

