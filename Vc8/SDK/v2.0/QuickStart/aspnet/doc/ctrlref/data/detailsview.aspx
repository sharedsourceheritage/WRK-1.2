<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.DetailsView" runat="server">
  DetailsView
</Acme:TypeRef>
</h2>

<b>DetailsView</b> is a data-bound user interface control that renders a single record at a time from its associated data source, optionally providing paging buttons to navigate between records.  It is similar to the Form View of an Access database, and is typically used for updating and/or inserting new records.  It is often used in a master-details scenario where the selected record of the master control (GridView, for example) determines the DetailsView display record.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/GridViewMasterDetails_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewMasterDetails.src"
        Caption="C# Master-Details w/ GridView and DetailsView"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/GridViewMasterDetails_vb.aspx"
        ViewSource="~/aspnet/samples/data/GridViewMasterDetails.src"
        Caption="VB Master-Details w/ GridView and DetailsView"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br/>

DetailsView supports editing just like GridView, and you can enable the UI the same way 
using the AutoGenerateEditButton or CommandField.ShowEditButton properties.  Of course,
the data source associated to the DetailsView must also be configured to support the 
Update operation (in this case, by specifying an UpdateCommand on SqlDataSource).
The following example demonstrates a DetailsView configured to support editing records
in a master-details scenario.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/GridViewMasterDetailsEdit_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewMasterDetailsEdit.src"
        Caption="C# DetailsView Editing"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/GridViewMasterDetailsEdit_vb.aspx"
        ViewSource="~/aspnet/samples/data/GridViewMasterDetailsEdit.src"
        Caption="VB DetailsView Editing"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br/>

Normally data-bound controls automatically re-bind to their data source
whenever the data source changes (for example after an update).  However,
in the preceding example, the DetailsView is bound to a different data source than
the GridView, so when the Update operation is invoked, only the DetailsView
receives a change event from its data source.  To force the GridView to also
re-bind when the DetailsView performs an update, you can call <code>DataBind()</code>
explicitly on GridView in the DetailsView <code>ItemUpdated</code> event. This example
also handles events to disable editing when a GridView sorting or paging 
operation occurs or when a new filter value is selected in the 
DropDownList control.
<br /><br />

This next example demonstrates a master-details scenario using GridView and DetailsView
in separate pages.  Unlike the previous examples that showed the GridView and DetailsView
bound to the same type of record (an author), this example shows different types of
records for the master and details controls (authors and books), associated by a 
foreign key relationship in the underlying database.  Because an author record may 
have more than one associated book, the DetailsView has been configured to support 
paging over the book records in the details page.  The DetailsView also supports 
paging records using client-side callbacks through its <b>EnablePagingCallbacks</b> 
property (not shown in this example).
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/GridViewMasterDetailsPage_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewMasterDetailsPage.src"
        Caption="C# Master-Details (Separate Pages)"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/GridViewMasterDetailsPage_vb.aspx"
        ViewSource="~/aspnet/samples/data/GridViewMasterDetailsPage.src"
        Caption="VB Master-Details (Separate Pages)"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

Like the GridView control, the DetailsView control supports Updating and Deleting data through 
its data source.  However, DetailsView also supports Inserting data, whereas GridView does not.
You can easily pair a DetailsView with GridView to enable inserting records to be displayed 
in the GridView control.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/GridViewMasterDetailsInsert_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewMasterDetailsInsert.src"
        Caption="C# Master-Details Insert"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/GridViewMasterDetailsInsert_vb.aspx"
        ViewSource="~/aspnet/samples/data/GridViewMasterDetailsInsert.src"
        Caption="VB Master-Details Insert"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br/>

You can place the DetailsView on a separate page to perform an Insert or Update operation.  The 
following example shows a DetailsView configured on a separate page for Insert and Updates.  Notice
that the <b>DefaultMode</b> property is set in this example to <code>Insert</code> or <code>Edit</code>
so that the DetailsView renders in this mode initially instead of read-only mode.  After an Insert or
Update operation is performed, DetailsView always reverts to the DefaultMode (which is <code>ReadOnly</code>, by default).
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/GridViewMasterDetailsInsertPage_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewMasterDetailsInsertPage.src"
        Caption="C# Master-Details Insert (Separate Pages)"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/data/GridViewMasterDetailsInsertPage_vb.aspx"
        ViewSource="~/aspnet/samples/data/GridViewMasterDetailsInsertPage.src"
        Caption="VB Master-Details Insert (Separate Pages)"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

For more information and examples that demonstrate the use of the DetailsView control, refer to the 
<asp:HyperLink NavigateUrl="~/aspnet/doc/data/default.aspx" runat="server">Performing Data Access</asp:HyperLink> section.

</asp:Content>
