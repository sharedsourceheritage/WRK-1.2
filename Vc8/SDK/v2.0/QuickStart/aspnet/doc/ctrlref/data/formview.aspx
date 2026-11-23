<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.FormView" runat="server">
  FormView
</Acme:TypeRef>
</h2>

<b>FormView</b> is a data-bound user interface control that renders a single record at a time from its associated data source, optionally providing paging buttons to navigate between records.  It is similar to the DetailsView control, except that it requires the user to define the rendering of each item using templates, instead of using data control fields.
<br /><br />
The main difference between DetailsView and FormView is that DetailsView has a built-in tabular rendering, whereas FormView requires a user-defined template for its rendering. The FormView and DetailsView object model are very similar otherwise. The following example demonstrates a FormView control bound to an ObjectDataSource. The ItemTemplate property of FormView contains data-bound Image, Label and HyperLink controls.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/PhotoAlbum_cs/PhotoFormView.aspx"
        ViewSource="~/aspnet/samples/data/PhotoFormView.src"
        Caption="C# DataBinding in a FormView Template"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/PhotoAlbum_vb/PhotoFormView.aspx"
        ViewSource="~/aspnet/samples/data/PhotoFormView.src"
        Caption="VB DataBinding in a FormView Template"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

Like DetailsView, FormView keeps track of the current item being rendered, and can optionally support paging over multiple data items when the data source returns a list. The following example shows a FormView with paging enabled. 
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/FormView_cs.aspx"
        ViewSource="~/aspnet/samples/data/FormView.src"
        Caption="C# DataBinding in a FormView Template (Paged)"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/FormView_vb.aspx"
        ViewSource="~/aspnet/samples/data/FormView.src"
        Caption="VB DataBinding in a FormView Template (Paged)"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

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
        RunSample="../../../samples/data/PhotoAlbum_cs/PhotoFormViewEdit.aspx"
        ViewSource="~/aspnet/samples/data/PhotoFormViewEdit.src"
        Caption="C# Two-Way Databinding in a FormView Edit Template"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/PhotoAlbum_vb/PhotoFormViewEdit.aspx"
        ViewSource="~/aspnet/samples/data/PhotoFormViewEdit.src"
        Caption="VB Two-Way Databinding in a FormView Edit Template"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

For more information and examples that demonstrate the use of the FormView control, refer to the 
<asp:HyperLink NavigateUrl="~/aspnet/doc/data/default.aspx" runat="server">Performing Data Access</asp:HyperLink> section.

</asp:Content>
