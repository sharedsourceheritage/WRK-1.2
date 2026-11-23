<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>

<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Advanced Data Scenarios</h2>

This topic describes how you can use some of the less obvious features of data controls to implement
advanced scenarios.

<a name="nulls"></a>
<h3>Handling Null Values</h3>

Data controls support a variety of ways to handle null or missing data.  To begin with, the GridView, FormView,
and DetailsView all support an <b>EmptyDataText</b> or <b>EmptyDataTemplate</b> property that you can use to specify a rendering 
for the control when the data source returns no rows of data.  Only one of EmptyDataText and EmptyDataTemplate needs to be
set (EmptyDataTemplate overrides when both are set).  You can also specify a <b>ConvertEmptyStringToNull</b> property on 
BoundField (and derived field types), TemplateField or data source parameter objects to specify that String.Empty values posted from the client should
be converted to null before invoking the associated data source operation.  ObjectDataSource also supports a <b>ConvertNullToDbNull</b> property
that can be set to true when the associated method expects DbNull parameters instead of null (the TableAdapter classes in a Visual Studio
DataSet have this requirement).  You can also specify a <b>NullDisplayText</b> property on BoundField (and derived field types) to specify a value for the field to display when the field value from
the data source is returned as null.  If this value is not changed during edit mode, the value will roundtrip as null back to the data 
source during an Update operation.  Lastly, you can also specify a <b>DefaultValue</b> property on data source parameters to specify a default value for the 
parameter when the parameter value passed is null. These properties can a chaining effect, for example if both ConvertEmptyStringToNull and
DefaultValue are set, a String.Empty value will first be converted to null and subsequently to the default value.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/HandlingNull_cs.aspx"
        ViewSource="~/aspnet/samples/data/HandlingNull.src"
        Caption="C# Handling Null Values"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/HandlingNull_vb.aspx"
        ViewSource="~/aspnet/samples/data/HandlingNull.src"
        Caption="VB Handling Null Values"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

You can use these null-handling properties to implement a DropDownList filter that displays all values from the data source initially
until a filter value is selected.  This is achieved by adding an item to the DropDownList with an empty string value and setting the
ConvertEmptyStringToNull property on the associated ControlParameter for the DropDownList in the data source.  Then in the data source
SelectCommand, you can check for a null value in order to return all (unfiltered) values.  The following example demonstrates this 
technique using a simple SQL command, although you could also perform the null check in the implementation of a stored procedure.
Note the use of the <b>AppendDataBoundItems</b> property of the DropDownList, which allows values obtained from the DropDownList
data source to be appended to the statically added "ALL" item in the Items collection.  Also note that by default the SqlDataSource
does not perform a Select operation if any of the associated parameters to the SelectCommand are null.  To allow the select operation 
to execute even when a null parameter is passed, you can set the <b>CancelSelectOnNullParameter</b> property to false.
<br /><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/DropDownListAll_cs.aspx"
        ViewSource="~/aspnet/samples/data/DropDownListAll.src"
        Caption="C# Show All Values on Null Selection"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/DropDownListAll_vb.aspx"
        ViewSource="~/aspnet/samples/data/DropDownListAll.src"
        Caption="VB Show All Values on Null Selection"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>


<%--
<a name="templates"></a>
<h3>Finding Controls In Templates</h3>
--%>

<a name="masterdetails"></a>
<h3>Advanced Master Details</h3>

In the preceding topics of this tutorial, you've seen how a master-details scenario can be implemented 
by associating a ControlParameter to the SelectedValue property of GridView.  The SelectedValue property
returns the value of the first field specified by the DataKeyNames property.  You can also specify 
multiple comma-separated field values for the DataKeyNames property, for example if you need more than
one value to be passed to the details data source in a master-details scenario.  The values
of these additional key fields are exposed through the <b>SelectedDataKey</b> property, which returns a <b>DataKey</b>
object of name/value pairs for key fields.  A ControlParameter can even refer to these keys by setting the 
PropertyName property to an expression, like <code>SelectedDataKey.Values("title_id"))</code>.  

<pre class="code">
  &lt;asp:ControlParameter Name="FirstKey" ControlID="MasterGrid" PropertyName="SelectedDataKey.Values[0]"/&gt;
  &lt;asp:ControlParameter Name="SecondKey" ControlID="MasterGrid" PropertyName="SelectedDataKey.Values[1]"/&gt;
</pre>

The following example demonstrates code to enumerate the DataKeys collection and for obtaining key field values from the 
GridView SelectedDataKey.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/DataKeys_cs.aspx"
        ViewSource="~/aspnet/samples/data/DataKeys.src"
        Caption="C# DataKeys"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/DataKeys_vb.aspx"
        ViewSource="~/aspnet/samples/data/DataKeys.src"
        Caption="VB DataKeys"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

The previous master-details samples in this tutorial showed the details control as a separate control on the 
form, but another common way to implement master-details is to show the details control as a nested control that 
is part of the rendering of the master control.  To do this, you need both the details control and its associated
data source to be contained in a template of the master control, with a data source parameter that obtains its
value from a field of the master data source.  Because there is not a declarative parameter object that can be 
associated in this way, you will have to set the parameter value programmatically in code.  You can do this by 
handling an event on the master control to set the parameter value when an item of the master control is data-bound, 
for example in the FormView <b>DataBound</b> event.  The following example demonstrates this technique.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/NestedMasterDetails_cs.aspx"
        ViewSource="~/aspnet/samples/data/NestedMasterDetails.src"
        Caption="C# Nested Master-Details"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/NestedMasterDetails_vb.aspx"
        ViewSource="~/aspnet/samples/data/NestedMasterDetails.src"
        Caption="VB Nested Master-Details"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

This next example shows a similar technique using DataList, handling the DataList <b>ItemDataBound</b> event
to set the details data source parameter value.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/NestedMasterDetailsList_cs.aspx"
        ViewSource="~/aspnet/samples/data/NestedMasterDetailsList.src"
        Caption="C# Nested Master-Details (DataList)"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/NestedMasterDetailsList_vb.aspx"
        ViewSource="~/aspnet/samples/data/NestedMasterDetailsList.src"
        Caption="VB Nested Master-Details (DataList)"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="events"></a>
<h3>Handling Data Control Events </h3>

You already seen several examples of data control events in preceding sections of this tutorial.  The data 
control events are meant to provide you with appropriate places in the page execution lifecycle where you can 
plug in your own custom code.  Data controls generally expose events both before and after a particular operation
occurs.  The events that fire before an operation are typically named with an -ing suffix, while events that fire
after an operation are named with a -ed suffix.  The events supported by the GridView for example, include:

<ul>
  <li><b>PageIndexChanging</b> and <b>PageIndexChanged</b> - Raised before and after a paging operation
  <li><b>SelectedIndexChanging</b> and <b>SelectedIndexChanged</b> - Raised before and after a selection occurs
  <li><b>Sorting</b> and <b>Sorted</b> - Raised before and after a sorting operation
  <li><b>RowEditing</b> and <b>RowCancelingEdit</b> - Raised before the row goes into edit mode, or before an edit mode is canceled
  <li><b>RowUpdating</b> and <b>RowUpdated</b> - Raised before and after an update operation
  <li><b>RowDeleting</b> and <b>RowDeleted</b> - Raised before and after a delete operation
  <li><b>RowDataBound</b> - Raised when a row is data-bound
  <li><b>RowCreated</b> - Raised when a row is created for rendering (as a TableRow)
  <li><b>RowCommand</b> - Raised when a button command is fired from within the control
</ul>

Data source controls also expose events, similar to data-bound control events.  Both the SqlDataSource and 
ObjectDataSource controls support the following events:

<ul>
  <li><b>Selecting</b> and <b>Selected</b> - Raised before and after a select operation
  <li><b>Updating</b> and <b>Updated</b> - Raised before and after an update operation
  <li><b>Deleting</b> and <b>Deleted</b> - Raised before and after a delete operation
  <li><b>Inserting</b> and <b>Inserted</b> - Raised before and after an insert operation
  <li><b>Filtering</b> - Raised before a filter operation
</ul>

The ObjectDataSource control additionally exposes events when the object specified by TypeName property
is created or destroyed.  You can actually set a custom object in the ObjectCreating event by setting
the <b>ObjectInstance</b> property of the passed event args.

<ul>
  <li><b>ObjectCreating</b> and <b>ObjectCreated</b> - Raised before and after the object is created
  <li><b>ObjectDisposing</b> - Raised before the object is disposed
</ul>

Typically the events that fire before an operation occurs are used to cancel the operation, by setting <b>Cancel</b>
property of the events args to true, or to perform parameter validation or manipulation.  The events that are
raised after an operation are used to write custom code to respond to a given operation, or to check the 
success status of the operation.  For example, you can check the <b>RowsAffected</b> by an Update, Insert, or Delete
operation or check the <b>Exception</b> property to determine if an exception occurred during processing.
You can also set the <b>ExceptionHandled</b> property of the event args to prevent the exception from bubbling
up to the control or Page.  The following example shows the various GridView and SqlDataSource events that can
be handled and the relative order in which they are raised.  
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewUpdatingEvent_cs.aspx"
        ViewSource="~/aspnet/samples/data/GridViewUpdatingEvent.src"
        Caption="C# GridView RowUpdating Event"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewUpdatingEvent_vb.aspx"
        ViewSource="~/aspnet/samples/data/GridViewUpdatingEvent.src"
        Caption="VB GridView RowUpdating Event"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

This next example demonstrates a more practical handling of the DetailsView <b>Inserting</b> event to
obtain a posted photo file from a FileUpload control inside the DetailsView to save the contents to disk before 
the DetailsView completes the insert operation to insert a record in a database for the posted photo file.
For demonstration purposes, the actual file save code has been commented out, but you can still try out this
sample by specifying the name of an already existing "Winter.jpg" image.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/PhotoAlbum_cs/PhotosInsert.aspx"
        ViewSource="~/aspnet/samples/data/PhotosInsert.src"
        Caption="C# DetailsView ItemInserting Event"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/PhotoAlbum_vb/PhotosInsert.aspx"
        ViewSource="~/aspnet/samples/data/PhotosInsert.src"
        Caption="VB DetailsView ItemInserting Event"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

Similar to the example above, this sample shows handling the FormView <b>ItemDeleted</b> event
to remove the associated photo file from disk when the database record for the photo is deleted.
Again, the actual file delete code has been commented out for demonstration purposes.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/PhotoAlbum_cs/PhotoDelete.aspx?ID=10"
        ViewSource="~/aspnet/samples/data/PhotoDelete.src"
        Caption="C# FormView ItemDeleted Event"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/PhotoAlbum_vb/PhotoDelete.aspx?ID=10"
        ViewSource="~/aspnet/samples/data/PhotoDelete.src"
        Caption="VB FormView ItemDeleted Event"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="parameters"></a>
<h3>Working With Parameters</h3>

You can handle the events for Select, Update, Insert, Delete, and Filter operations to validation and 
manipulate the parameter values that are passed to these operations.  Both the data-bound controls and 
data source controls expose appropriate events for this purpose.  For example, in the GridView Updating
event you can see the names and values of parameters in the Keys, NewValues, and OldValues dictionaries
that will be handed off to the data source.  On the data source side, you can handle the SqlDataSource
Updating event to see these parameters as they are applied to the underlying command object that 
will be executed to complete the operation.  Similarly you can handle an ObjectDataSource Updating
event to view or change the parameter dictionaries that will be used to resolve the appropriate 
overload of the UpdateMethod.  You can use these events to add or remove parameters from
the dictionaries or commands, change their values, or simply validate that parameters have the correct
input format.  
<br /><br />

<b>Important:</b> You should especially validate parameter inputs for the Filtering event, which do not 
get SQL encoded before applied to the FilterExpression associated to the DataView object.
<br /><br />

The following example demonstrates handling various data control events to enumerate the parameters
collections passed via the event args.  Notice that this sample sets the <b>InsertVisible</b> property
of the BoundField associated to the <code>OrderID</code> primary key field to false, because the OrderID
field is an identity column in the underlying database and should not be passed to Insert operations (the
database increments this value automatically when an insert occurs).  Also note that the OrderID field
is marked as the primary key in <b>DataKeyNames</b>, so the original value of this field is retained in the <b>Keys</b> dictionary 
passed by the data-bound control.  Values entered by the user to input controls are passed in a 
<b>NewValues</b> dictionary, except those fields marked as <code>ReadOnly=false</code>.  The original values of 
non-key fields are also retained in an <b>OldValues</b> dictionary by the data-bound control for 
passing to the data source.  These parameter values are appended to the command by SqlDataSource in the 
order of NewValues, Keys, and OldValues, although by default the data source does not append OldValues when
<b>ConflictDetection</b> is set the <code>OverwriteChanges</code>.  For more information on how OldValues is used by data sources, refer to the 
<asp:HyperLink NavigateUrl="#conflicts" runat="server">Using Conflict Detection</asp:HyperLink> section below.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/EnumerateParameters_cs.aspx"
        ViewSource="~/aspnet/samples/data/EnumerateParameters.src"
        Caption="C# Data Parameters"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/EnumerateParameters_vb.aspx"
        ViewSource="~/aspnet/samples/data/EnumerateParameters.src"
        Caption="VB Data Parameters"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

You can change the order in which parameters are appended to the command by SqlDataSource by adding static
<b>Parameter</b> object to the parameters collection for a data source operation in the preferred order. 
The SqlDataSource automatically reorders parameters passed by the data-bound control according to the order of
these Parameter objects.  This is useful when the <b>ProviderName</b> property of the data source is set to 
<code>System.Data.OleDb</code>, which does not have support for named parameters so the order in which parameters
are appended to the command must match the order of anonymous parameter placeholders ('?') in the command.
When using named parameters, the order of parameters is insignificant.  
You can specify the <b>Type</b> property of a Parameter object to force the values passed by the data-bound 
control to be converted to an appropriate data type before executing the command or method.  Likewise, you can
set the <b>Size</b> property of a Parameter to dictate the Size of the DbParameter in a SqlDataSource command
(required for input/output, output, and return value parameters).  
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/ParameterOrderAndTypes_cs.aspx"
        ViewSource="~/aspnet/samples/data/ParameterOrderAndTypes.src"
        Caption="C# Parameter Order and Types"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/ParameterOrderAndTypes_vb.aspx"
        ViewSource="~/aspnet/samples/data/ParameterOrderAndTypes.src"
        Caption="VB Parameter Order and Types"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

The default convention for parameter names requires that new values are named according to 
the fields selected by the data source Select operation.  It is possible to rename parameters from 
Keys or OldValues to differentiate them from NewValues by specifying the 
<b>OldValuesParameterFormatString</b> property, for example to "original_{0}".
You can also customize the names of parameters by handling an appropriate event to change the 
value of a parameter before the data source operation is executed.  For example, if the update operation
of a SqlDataSource is associated to a stored procedure that takes different parameter names than those
that match the default naming convention, you can modify the parameter names in the SqlDataSource
<b>Updating</b> event before the stored procedure is called.  The example below demonstrates this 
technique.


<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/ParameterMapping_cs.aspx"
        ViewSource="~/aspnet/samples/data/ParameterMapping.src"
        Caption="C# Renaming Parameters"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/ParameterMapping_vb.aspx"
        ViewSource="~/aspnet/samples/data/ParameterMapping.src"
        Caption="VB Renaming Parameters"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

ObjectDataSource does not rely on a particular order of parameters, but instead simply looks for a 
method with matching parameter names.  Note that the Type or Size of a parameter is not used by 
ObjectDataSource for the sake of resolving method overloads. Only the names of the parameters are 
matched, so if you have two methods on your business object that have the same name and parameter names, 
but different parameter types, ObjectDataSource will not be able to distinguish between them.

You can change the names and values of ObjectDataSource parameters in events, similar to the SqlDataSource
example above.  However, if you are using <b>DataObjectTypeName</b> to specify a particular data object
type to be passed to Update, Insert, and Delete operations, you will not be able to modify the parameter
names -- only the values.  If you need to modify parameter names, do not use DataObjectTypeName and instead
just construct appropriate data objects in the data source events manually in code.
<br /><br />

All of the data source parameters we have used so far have been <code>Input</code> parameters, used for passing
values into a data source operation.  Parameters can also be bidirectional, such as <code>InputOutput</code>, <code>Output</code>,
and <code>ReturnValue</code> parameters.  You can specify the directionality of a parameter using the Parameter object's
<b>Direction</b> property.  To retrieve the values of these parameters after a data source operation completes,
handle the appropriate post-operation event, such as the Selected, Updated, Inserted, or Deleted event, to 
obtain the parameter value from the event arguments passed to these events.  The <b>SqlDataSourceStatusEventArgs</b>
has a <b>Command</b> property you can use to obtain return values and output parameters, shown in the example below.  Note that it is important to set the 
<b>Size</b> property of the Parameter object in SqlDataSource to an appropriate value for bidirectional parameters.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/RetValAndOutputParams_cs.aspx"
        ViewSource="~/aspnet/samples/data/RetValAndOutputParams.src"
        Caption="C# Return Values and Output Parameters"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/RetValAndOutputParams_vb.aspx"
        ViewSource="~/aspnet/samples/data/RetValAndOutputParams.src"
        Caption="VB Return Values and Output Parameters"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

The <b>ObjectDataSourceStatusEventArgs</b> type supports an <b>OutputParameters</b> collection and <b>ReturnValue</b> property for this purpose, 
demonstrated in this next sample.  Note that in this case, the return value of the Update operation is used to determine the number of affected rows
by that operation.  To pass this value back to the data-bound control (for example through the GridViewUpdatedEventArgs AffectedRows property, you 
can set the AffectedRows property of the ObjectDataSourceStatusEventArgs to this return value).
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewObject_cs/RetValAndOutputParamsObject.aspx"
        ViewSource="~/aspnet/samples/data/RetValAndOutputParamsObject.src"
        Caption="C# Return Values and Output Parameters (Object)"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewObject_vb/RetValAndOutputParamsObject.aspx"
        ViewSource="~/aspnet/samples/data/RetValAndOutputParamsObject.src"
        Caption="VB Return Values and Output Parameters (Object)"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

Another common use for output parameters is to retrieve the primary key value of a row inserted into a database
that is an Identity column (where the key value is not specified as a parameter of the insert, but is instead 
automatically generated by the database server when the insert occurs.  This next example demonstrates this 
technique.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/RetValAndOutputParamsInsert_cs.aspx"
        ViewSource="~/aspnet/samples/data/RetValAndOutputParamsInsert.src"
        Caption="C# Retrieving Identity After Insert"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/RetValAndOutputParamsInsert_vb.aspx"
        ViewSource="~/aspnet/samples/data/RetValAndOutputParamsInsert.src"
        Caption="VB Retrieving Identity After Insert"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

<a name="conflicts"></a>
<h3>Using Conflict Detection</h3>

As mentioned in previous topics, the data-bound control passes values to a data source in separate
Keys, Values (new values), and OldValues dictionaries.  By default the SqlDataSource and ObjectDataSource
ignore the OldValues dictionary and instead only apply Keys and Values.  This behavior is determined by
the <b>ConflictDetection</b> property of the data source, which is set to <code>OverwriteChanges</code>
by default.  The OverwriteChanges mode essentially means "only match primary key values for the sake
of updating or deleting a record".  This behavior means that the record is updated or deleted regardless
of whether the underlying values of the record have changed.  Often it is more desirable to only allow
Update or Delete operations to succeed when the values of the row match exactly what was selected 
initially.  This way, if another user updates a row between the time you select the row and update it, 
your update operation will fail.  Data sources support this approach by setting the ConflictDetection
property to <code>CompareAllValues</code>  In this mode, the data source applies to OldValues parameters 
to the command or method, which can use these values to ensure an update or delete operation matches
all of these values of the record before updating or deleting the record.  You must also set the
<b>OldValuesParameterFormatString</b> property to a valid .NET Framework format string, for example "original_{0}",
to indicate how parameters in the OldValues and Keys dictionaries should be renamed to differentiate them from NewValues.
<br /><br />
The code example below shows typical SQL commands for the OverwriteChanges and CompareAllValues mode
of the SqlDataSource control.  The ID field is assumed to be the primary key field.  Notice that the 
latter commands compare all the original values of the row in the WHERE clause, not just the primary
key.  In this case, OldValuesParameterFormatString would need to be set to "original_{0}" on the data source.
<br /><br />

<pre class="code">
SELECT [ID], [Name], [Address] from [Contacts]

<b>-- OverwriteChanges</b>
UPDATE [Contacts] SET [Name] = @Name, [Address] = @Address WHERE [ID] = @ID
DELETE FROM [Contacts] WHERE [ID] = @ID

<b>-- CompareAllValues</b>
UPDATE [Contacts] SET [Name] = @Name, [Address] = @Address WHERE [ID] = @original_ID 
  AND [Name] = @original_Name AND [Address] = @original_Address
DELETE FROM [Contacts] WHERE [ID] = @original_ID AND [Name] = @original_Name 
  AND [Address] = @original_Address
</pre>

The following example shows the enumerations of parameters at the data-bound control level and 
the data source level for the Keys, Values, and OldValues dictionaries, when ConflictDetection is
set to CompareAllValues.  For demonstration purposes, the actual Update, Delete, and Insert operations are
cancelled.  Notice also that OldValues is not required for an Insert operation. ConflictDetection is only 
meaningful for Updates and Deletes.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/OptimisticConcurrency_cs.aspx"
        ViewSource="~/aspnet/samples/data/OptimisticConcurrency.src"
        Caption="C# Conflict Detection Parameters"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/OptimisticConcurrency_vb.aspx"
        ViewSource="~/aspnet/samples/data/OptimisticConcurrency.src"
        Caption="VB Conflict Detection Parameters"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br>

The next example shows the behavior when a conflict occurs.  To run this sample, open two instances of
the sample in separate browser windows (click "Run Sample" twice).  Then click the Edit button for the 
same row in both windows, to place the row in edit mode.  In the first window, change a row value and 
click Update, and note that the update succeeds.  In the second window, you can enter new values for the
same row and click update, but the Update will not succeed because the underlying row values where changed
by the first update operation.  The sample checks that the <b>AffectedRows</b> property of the Updated or Deleted
event args is 0 to confirm that a conflict has occurred.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/OptimisticConcurrencyDelete_cs.aspx"
        ViewSource="~/aspnet/samples/data/OptimisticConcurrencyDelete.src"
        Caption="C# Conflict Detection (Update and Delete)"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/OptimisticConcurrencyDelete_vb.aspx"
        ViewSource="~/aspnet/samples/data/OptimisticConcurrencyDelete.src"
        Caption="C# Conflict Detection (Update and Delete)"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

When using templated UI for Updates or Deletes, the old values are retained for fields that are two-way
data-bound using <code>Bind</code> statements.  For Deletes, this means that you must use <code>Bind</code>
statements to data-bound values in the ItemTemplate in order to retain old values for delete operations.  The 
example below demonstrates this technique. 
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/OptimisticConcurrencyDeleteBind_cs.aspx"
        ViewSource="~/aspnet/samples/data/OptimisticConcurrencyDeleteBind.src"
        Caption="C# Conflict Detection Using Templates"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/OptimisticConcurrencyDeleteBind_vb.aspx"
        ViewSource="~/aspnet/samples/data/OptimisticConcurrencyDeleteBind.src"
        Caption="VB Conflict Detection Using Templates"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

You can handle conflict detection errors gracefully by giving the user an option to commit or abort the
operation when the underlying row has changed, by displaying the changed values to the user so they can 
compare to their own updates.  The following example demonstrates a possible approach for handling conflict
detection errors.  Note that the DetailsView RowUpdated event args passes dictionaries that you can use to
check the values entered by the user.  You can also set the <b>KeepInEditMode</b> property of this event args
to keep the DetailsView in edit mode while the user makes a decision about how to handle the conflict.  You can 
exercise this sample in the same way as the previous example, by opening two windows to create a conflicting update.  
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/OptimisticConcurrencyHandling_cs.aspx"
        ViewSource="~/aspnet/samples/data/OptimisticConcurrencyHandling.src"
        Caption="C# Handling Conflicting Updates"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/OptimisticConcurrencyHandling_vb.aspx"
        ViewSource="~/aspnet/samples/data/OptimisticConcurrencyHandling.src"
        Caption="VB Handling Conflicting Updates"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

This next example shows the same scenario as above using ObjectDataSource.  Note that because the data source
ConflictDetection property is set to CompareAllValues, the data source looks for an overload of <code>UpdateContact</code>
that accepts original values for each field of the <code>Contact</code> object.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewObject_cs/OptimisticConcurrencyObject.aspx"
        ViewSource="~/aspnet/samples/data/OptimisticConcurrencyObject.src"
        Caption="C# Conflict Detection w/ ObjectDataSource"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewObject_vb/OptimisticConcurrencyObject.aspx"
        ViewSource="~/aspnet/samples/data/OptimisticConcurrencyObject.src"
        Caption="VB Conflict Detection w/ ObjectDataSource"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

You can also use the <b>DataObjectTypeName</b> property in conjunction with CompareAllValues.  In this case, the ObjectDataSource
looks for an overload of <code>UpdateContact</code> that accepts exactly two parameters, both of type <code>Contact</code>.  The 
first parameter will be a Contact object populated with the new values for the update, while the second parameter will be an 
Contact object populated with the original values.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewObject_cs/OptimisticConcurrencyDataObject.aspx"
        ViewSource="~/aspnet/samples/data/OptimisticConcurrencyDataObject.src"
        Caption="C# Conflict Detection w/ ObjectDataSource (DataObjectTypeName)"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/GridViewObject_vb/OptimisticConcurrencyDataObject.aspx"
        ViewSource="~/aspnet/samples/data/OptimisticConcurrencyDataObject.src"
        Caption="VB Conflict Detection w/ ObjectDataSource (DataObjectTypeName)"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

<a name="pagesort"></a>
<h3>Advanced Paging/Sorting</h3>

Selection in the GridView control is purely a UI concept, where the <b>SelectedIndex</b> property 
correspond to the index of the currently selected row among the visible rows of the grid.  If you
have enabled paging and sorting in the grid, the SelectedIndex of the grid remains the same after a 
paging or sorting operation, so that a new row ends up selected after these operations.  In
some circumstances it is better to retain the selection of a given row even when that row is
not currently visible on the current page of the grid.  The example below shows a technique for
retaining the selected row across a sorting or paging operation.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/SortingAndSelection_cs.aspx"
        ViewSource="~/aspnet/samples/data/SortingAndSelection.src"
        Caption="C# Maintaining Selection After Sort"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/SortingAndSelection_vb.aspx"
        ViewSource="~/aspnet/samples/data/SortingAndSelection.src"
        Caption="VB Maintaining Selection After Sort"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

<%--
TODO: Describe SortParameterName (Object) - linked sample<br />
TODO: Describe Paging Parameters w/ GridView<br />
TODO: DataList paging example<br /><br />
--%>

GridView and DetailsView support a special mode for paging and sorting that takes advantage of client-side
callbacks to the server to obtain data for the new page or newly sorted data.  To enable this
feature, set the <b>EnableSortingAndPagingCallbacks</b> property to true.  Notice that when
a page or sort operation is performed, the page does not need to postback in order to 
retrieve new values (although a client script callback to the server is made).  This 
feature is not supported when the GridView or DetailsView contains templated fields.  
Showing a Select button in a CommandField is also not supported when this feature is enabled.
<br /><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/PagingSortingCallbacks_cs.aspx"
        ViewSource="~/aspnet/samples/data/PagingSortingCallbacks.src"
        Caption="C# Sorting and Paging Using Callbacks"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/PagingSortingCallbacks_vb.aspx"
        ViewSource="~/aspnet/samples/data/PagingSortingCallbacks.src"
        Caption="VB Sorting and Paging Using Callbacks"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

Although the GridView, DetailsView, and FormView provide a default rendering for the pager UI, 
you can also customize the rendering for the pager by setting the <b>PagerTemplate</b> property.
Inside this template you can place <b>Button</b> controls with the <b>CommandName</b> property set to 
<code>Page</code>, and the <b>CommandArgument</b> property set to <code>First</code>, <code>Prev</code>,
<code>Next</code>, <code>Last</code>, or <code>&lt;number&gt;</code>, where &lt;number&gt; is the 
value of a specific page index.  The example below shows a PagerTemplate defined for both 
the GridView and DetailsView controls.
<br /><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/PagerTemplate_cs.aspx"
        ViewSource="~/aspnet/samples/data/PagerTemplate.src"
        Caption="C# Pager Template"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/PagerTemplate_vb.aspx"
        ViewSource="~/aspnet/samples/data/PagerTemplate.src"
        Caption="VB Pager Template"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="databind"></a>
<h3>Databinding in Code</h3>

<%--
* Copy from Databinding v1 (DataBind*_vb.aspx)<br />
* Assigning DataSource Control to DataSource (DataSourceProgrammatic_vb.aspx)<br />
* Master-Details In-Sync Example (linked)<br />

- DataList Updates, Deletes (DataList/Customzation from v1)<br />
--%>

As discussed in the 
<asp:HyperLink NavigateUrl="~/aspnet/doc/data/templates.aspx" runat="server">Databinding in Templates</asp:HyperLink>
section, ASP.NET includes a declarative data binding syntax for associating data source fields with properties of
controls in a data-bound template.  You can also use the &lt%# ... &gt; syntax to data bind arbitrary values in 
code, such as Page and control properties, collections, expressions, and even results returned from
method calls.  To force the data binding to evaluate, you must call the <code>DataBind</code> method on the 
Page or control containing the data binding expression.  The following table shows some examples of the 
data binding syntax in ASP.NET.
<br /><br />

<table class="table">
<tr>
    <td><b>Simple property</b></td>
    <td>Customer: &lt;%# custID %&gt;</td>
</tr><tr>
    <td><b>Collection</b></td>
    <td>Orders: &lt;asp:ListBox id="List1" datasource='&lt;%# myArray %&gt;' runat="server"&gt;</td>
</tr><tr>
    <td><b>Expression</b></td>
    <td>Contact: &lt;%# ( customer.FirstName + " " + customer.LastName ) %&gt;</td>
</tr><tr>
    <td><b>Method result</b></td>
    <td>Outstanding Balance: &lt;%# GetBalance(custID) %&gt;</td>
</tr>
</table>
<br />

Although this syntax looks similar to the ASP shortcut for <b>Response.Write</b> -- <code>&lt;%= %&gt;</code> -- its
behavior is quite different.  Whereas the ASP <b>Response.Write</b> shortcut syntax was evaluated when the page
was processed, the ASP.NET data binding syntax is evaluated only when the <b>DataBind</b> method is invoked.
<br /><br />

<b>DataBind</b> is a method of the <b>Page</b> and all server controls.  When you call <b>DataBind</b> on a parent control, it
cascades to all of the children of the control.  So, for example, <code>DataList1.DataBind()</code>
invokes the <b>DataBind</b> method on each of the controls in the <b>DataList</b> templates.  Calling <b>DataBind</b> on the
<b>Page</b> -- <code>Page.DataBind()</code> or simply <code>DataBind()</code> -- causes all
data binding expressions on the page to be evaluated.  <b>DataBind</b> is commonly called from the <b>Page_Load</b> event, as shown in the following example.
<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
protected void Page_Load(Object Src, EventArgs E) {
    DataBind();
}
</Tab>

<Tab Name="VB">
Protected Sub Page_Load(Src As Object, E As EventArgs)
    DataBind()
End Sub
</Tab>

</Acme:TabControl>
<br />

You can use a binding expression almost anywhere in the declarative section of an .aspx page, provided it evaluates to
the expected data type at run time.  The simple property, expression, and method examples above display text to
the user when evaluated.  In these cases, the data binding expression must evaluate to a value of type <b>String</b>.
In the collection example, the data binding expression evaluates to a value of valid type for the <b>DataSource</b>
property of <b>ListBox</b>.  You might find it necessary to coerce the type of value in your binding expression to produce
the desired result.  For example, if <code>count</code> is an integer:
<br /><br />

<pre class="code">
Number of Records:  &lt;%# count.ToString() %&gt;
</pre>

The ASP.NET data binding syntax supports binding to public variables, properties of the <b>Page</b>, and
properties of other controls on the page.
The following example illustrates binding to a public variable and simple property on the page. Note that these values are initialized before <code>DataBind()</code> is called.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/DataBind1_cs.aspx"
        ViewSource="~/aspnet/samples/data/DataBind1.src"
        Caption="C# Data Binding to a Property on the Page"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/DataBind1_vb.aspx"
        ViewSource="~/aspnet/samples/data/DataBind1.src"
        Caption="VB Data Binding to a Property on the Page"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

The following example illustrates binding to a property of another control.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/DataBind2_cs.aspx"
        ViewSource="~/aspnet/samples/data/DataBind2.src"
        Caption="C# Data Binding to a Server Control Property"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/DataBind2_vb.aspx"
        ViewSource="~/aspnet/samples/data/DataBind2.src"
        Caption="VB Data Binding to a Server Control Property"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

List server controls like <b>DropDownList</b>, <b>ListBox</b> and <b>HTMLSelect</b> use a collection as a data source.  The following
examples illustrate binding to usual common language runtime collection types.  These controls can bind only to
collections that support the <b>IEnumerable</b>, <b>ICollection</b>, or <b>IListSource</b> interface.
Most commonly, you'll bind to <b>ArrayList</b>, <b>Hashtable</b>, <b>DataView</b> and <b>DataReader</b>.
The following example illustrates binding to an <b>ArrayList</b>.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/DataBind3_cs.aspx"
        ViewSource="~/aspnet/samples/data/DataBind3.src"
        Caption="C# Data Binding DropDownList"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/DataBind3_vb.aspx"
        ViewSource="~/aspnet/samples/data/DataBind3.src"
        Caption="VB Data Binding DropDownList"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

The following example illustrates binding to a <b>DataView</b>.  Note that the <b>DataView</b> class is defined in the <b>System.Data</b>
namespace.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/DataBind4_cs.aspx"
        ViewSource="~/aspnet/samples/data/DataBind4.src"
        Caption="C# Data Binding to a DataView"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/DataBind4_vb.aspx"
        ViewSource="~/aspnet/samples/data/DataBind4.src"
        Caption="VB Data Binding to a DataView"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

The following example illustrates binding to a <b>Hashtable</b>.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/DataBind5_cs.aspx"
        ViewSource="~/aspnet/samples/data/DataBind5.src"
        Caption="C# Data Binding to a Hashtable"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/DataBind5_vb.aspx"
        ViewSource="~/aspnet/samples/data/DataBind5.src"
        Caption="VB Data Binding to a Hashtable"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

Often, you'll want to manipulate data before binding to your page or a control.  The following example illustrates
binding to an expression and the return value of a method.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/DataBind6_cs.aspx"
        ViewSource="~/aspnet/samples/data/DataBind6.src"
        Caption="C# Databinding to Methods and Expressions"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/DataBind6_vb.aspx"
        ViewSource="~/aspnet/samples/data/DataBind6.src"
        Caption="VB Databinding to Methods and Expressions"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

The ASP.NET Page Framework supplies a static method that evaluates late-bound data binding expressions and optionally
formats the result as a string.  <b>DataBinder.Eval</b> is convenient in that it eliminates much of the explicit
casting the developer must do to coerce values to the desired data type.  It is particularly useful when
data binding controls within a templated list, because often both the data row and the data field
must be cast.  
<br /><br />

Consider the following example, where an integer will be displayed as a currency string.  With the
standard ASP.NET data binding syntax, you must first cast the type of the data row in order to retrieve the
data field, <code>IntegerValue</code>.  Next, this is passed as an argument to the <b>String.Format</b> method.
<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
&lt;%# String.Format("{0:c}", ((DataRowView)Container.DataItem)["IntegerValue"]) %&gt;
</Tab>

<Tab Name="VB">
&lt;%# String.Format("{0:c}", (CType(Container.DataItem, DataRowView)("IntegerValue"))) %&gt;
</Tab>

</Acme:TabControl>
<br />

This syntax can be complex and difficult to remember.  In contrast, <b>DataBinder.Eval</b> is simply a method with
three arguments: the naming container for the data item, the data field name, and a format string.
In a templated control like <b>FormView</b>, <b>GridView</b>, <b>DetailsView</b>, <b>DataList</b> or <b>Repeater</b>, the naming container is always <code>
Container.DataItem.</code>  <b>Page</b> is another naming container that can be used with
<b>DataBinder.Eval</b>.
As discussed in previous section, ASP.NET 2.0 also include a new simplified syntax for DataBinder.Eval, 
simply <code>Eval</code>, that can be used inside a data-bound control template to resolve to 
Container.DataItem automatically.  The simplified <code>Eval</code> syntax is discussed in the preceding
section, <asp:HyperLink NavigateUrl="~/aspnet/doc/data/templates.aspx" runat="server">Databinding in Templates</asp:HyperLink>.
<br /><br />

<p><Acme:TabControl runat="server">
<Tab Name="C#">
&lt;%# DataBinder.Eval(Container.DataItem, "IntegerValue", "{0:c}") %&gt;
&lt;%# Eval("IntegerValue", "{0:c}") %&gt;
</Tab>

<Tab Name="VB">
&lt;%# DataBinder.Eval(Container.DataItem, "IntegerValue", "{0:c}") %&gt;
&lt;%# Eval("IntegerValue", "{0:c}") %&gt;
</Tab>

</Acme:TabControl>
<br />

The format string argument is optional.  If it is omitted, <b>DataBinder.Eval</b> returns a value of type object, as shown in the following example.
<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
&lt;%# (bool)DataBinder.Eval(Container.DataItem, "BoolValue") %&gt;
</Tab>

<Tab Name="VB">
&lt;%# CType(DataBinder.Eval(Container.DataItem, "BoolValue"), Boolean) %&gt;
</Tab>

</Acme:TabControl>
<br />

It is important to note that <b>DataBinder.Eval</b> can carry a noticeable performance penalty over the
standard data binding syntax because it uses late-bound reflection.  Use <b>DataBinder.Eval</b> judiciously, especially when string
formatting is not required.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/DataBind7_cs.aspx"
        ViewSource="~/aspnet/samples/data/DataBind7.src"
        Caption="C# Data Binding Using DataBinder.Eval"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/data/DataBind7_vb.aspx"
        ViewSource="~/aspnet/samples/data/DataBind7.src"
        Caption="VB Data Binding Using DataBinder.Eval"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

</asp:Content>

