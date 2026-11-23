<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master"  %>
<%@ Register TagPrefix="Acme" Namespace="Acme" %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>Validating Form Input Controls</h2>

<div class="new">
  <h3>What's New in 2.0</h3>
  <ul>
    <li><b>Validation Groups - </b> You can assign a group name to a set of validators to ensure that validation occurs only for controls in the specified group.  This enables you to have multiple control groups that are validated separately on the same page.</li>
    <br /><br />
    <li><b>Set Focus on Error - </b> Using the new Focus API feature in ASP.NET validators can be configured to set focus to their associated control to be validated when a validation error occurs.  The first control in the form that has a validation error will receive default focus when the form is submitted.</li>
    <br /><br />
    <li><b>Culture Invariant Values - </b> When doing conversion on a compare validator's non strongly-typed properties (CompareValidator.ValueToCompare, RangeValidator.MaximumValue, RangeValidator.MinimumValue) the validator will use a culture neutral format (Date: YYYY/MM/DD, Double & Currency: US culture format) to do the conversion when CultureInvariantValues is true.</li>
    <br /><br />
    <li><b>Validate Empty Text - </b> The ValidateEmptyText property fixes an issue with CustomValidator. In ASP.NET 1.0 custom validation would not fire if ValidationText was empty.  You can set this property to true to cause custom validation to occur for empty input values.
  </ul>
  This section discusses these and other features of validation in ASP.NET 2.0.
</div>

<br /><br />

The Web Forms framework includes a set of validation server controls that provide an easy-to-use but powerful way
to check input forms for errors and, if necessary, display messages to the user.
Validation controls are added to a Web Forms page like other server controls.  There are controls for specific types of
validation, such as range checking or pattern matching, plus a <b>RequiredFieldValidator</b> that ensures that a user does
not skip an entry field.  You can attach more than one validation control to an input control. For example, you
might specify both that an entry is required and that it must contain a specific range of values.

<br /><br />

Validation controls work with a limited subset of HTML and Web server controls.  For each control, a specific
property contains the value to be validated.  The following table lists the input controls that may be validated.

<br /><br />

<table class="table" width="400" cellpadding="3">
    <tr>
    <th>Control</th>
    <th>Validation Property</th>
    </tr>
    <tr>
    <td><b>HtmlInputText</b></td>
    <td>Value</td>
    </tr>
    <tr>
    <td><b>HtmlTextArea</b></td>
    <td>Value</td>
    </tr>
    <tr>
    <td><b>HtmlSelect</b></td>
    <td>Value</td>
    </tr>
    <tr>
    <td><b>HtmlInputFile</b></td>
    <td>Value</td>
    </tr>
    <tr>
    <td><b>TextBox</b></td>
    <td>Text</td>
    </tr>
    <tr>
    <td><b>ListBox</b></td>
    <td>SelectedItem.Value</td>
    </tr>
    <tr>
    <td><b>DropDownList</b></td>
    <td>SelectedItem.Value</td>
    </tr>
    <tr>
    <td><b>RadioButtonList</b></td>
    <td>SelectedItem.Value</td>
    </tr>
    <tr>
    <td><b>FileUpload</b></td>
    <td>FileName</td>
    </tr>
</table>

<!--BEGIN SECTION-->
<a name="types"></a>
<h3>Types of Validation Controls</h3>

The simplest form of validation is a required field. If the user enters any value in a field, it is valid.
If all of the fields in the page are valid, the page is valid.  The following example illustrates this using the <b>RequiredFieldValidator</b>.

<br /><br />

<!-- server-side required field -->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/validation/RequiredFieldValidator_cs.aspx"
        ViewSource="~/aspnet/samples/validation/RequiredFieldValidator.src"
        Caption="C# RequiredFieldValidator"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/validation/RequiredFieldValidator_vb.aspx"
        ViewSource="~/aspnet/samples/validation/RequiredFieldValidator.src"
        Caption="VB RequiredFieldValidator"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>


<br />

There are also validation controls for specific types of validation, such as range checking or pattern matching. The following table lists the validation controls.

<br /><br />

<table class="table" width="80%" cellpadding=3>
    <tr>
    <th>Control Name</th>
    <th>Description</th>
    </tr>
    <tr>
    <td style="width:25%"><b>RequiredFieldValidator</b></td>
    <td>Ensures that the user does not skip an entry.</td>
    </tr>
    <tr>
    <td style="width:25%"><b>CompareValidator</b></td>
    <td>Compares a user's entry with a constant value or a property value of another control using a comparison operator (less than, equal to, greater than, and so on).</td>
    </tr>
    <tr>
    <td style="width:25%"><b>RangeValidator</b></td>
    <td>Checks that a user's entry is between specified lower and upper boundaries. You can check ranges within pairs of numbers, alphabetic characters, or dates. Boundaries can be expressed as constants.</td>
    </tr>
    <tr>
    <td style="width:25%"><b>RegularExpressionValidator</b></td>
    <td>Checks that the entry matches a pattern defined by a regular expression. This type of validation allows you to check for predictable sequences of characters, such as those in social security numbers, e-mail addresses, telephone numbers, postal codes, and so on.</td>
    </tr>
    <tr>
    <td style="width:25%"><b>CustomValidator</b></td>
    <td>Checks the user's entry using validation logic that you code yourself. This type of validation allows you to check for values derived at run time.</td>
    </tr>
    <tr>
    <td style="width:25%"><b>ValidationSummary</b></td>
    <td>Displays the validation errors in summary form for all of the validators on a page.</td>
    </tr>
</table>



<!--BEGIN SECTION-->
<a name="client"></a>
<h3>Client-Side Validation</h3>

The validation controls always perform validation checking in server code. However, if the user is working
with a browser that supports DHTML, the validation controls can also perform validation using client script.
With client-side validation, any errors are detected on the client when the form is submitted to the server.
If any of the validators are found to be in error, the submission of the form to the server is cancelled and
the validator's <b>Text</b> property is displayed.  This permits the user to correct the input before
submitting the form to the server.  Field values are revalidated as soon as the field containing the error
loses focus, thus providing the user with a rich, interactive validation experience.

<br /><br />

Note that the Web Forms page framework always performs validation on the server, even if the validation has
already been performed on the client.  This helps prevent users from being able to bypass validation by
impersonating another user or a preapproved transaction.

<br /><br />

Client-side validation is enabled by default.  If the client is capable, uplevel validation will be performed automatically.
To disable client-side validation, set the page's <b>ClientTarget</b> property to "Downlevel" ("Uplevel" forces client-side validation).
Alternatively, you can set an individual validator control's <b>EnableClientScript</b> property to "false" to disable client-side
validation for that specific control.

<br /><br />

<!-- client-side required field -->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/validation/ClientSideValidation_cs.aspx"
        ViewSource="~/aspnet/samples/validation/ClientSideValidation.src"
        Caption="C# Client-side Validation"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/validation/ClientSideValidation_vb.aspx"
        ViewSource="~/aspnet/samples/validation/ClientSideValidation.src"
        Caption="VB Client-side Validation"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<!--BEGIN SECTION-->
<a name="errors"></a>
<h3>Displaying Validation Errors</h3>

When the user's input is processed (for example, when the form is submitted), the Web Forms page framework passes
the user's entry to the associated validation control or controls. The validation controls test the user's input
and set a property to indicate whether the entry passed the validation test. After all validation controls have
been processed, the <b>IsValid</b> property on the page is set; if any of the controls shows
that a validation check failed, the entire page is set to invalid.

<br /><br />

If a validation control is in error, an error message may be displayed in the page by that validation control or
in a <b>ValidationSummary</b> control elsewhere on the page.  The <b>ValidationSummary</b> control is displayed
when the <b>IsValid</b> property of the page is false.  It polls each of the validation controls on the page and
aggregates the text messages exposed by each.  The following example illustrates displaying errors with
a <b>ValidationSummary</b> control.

<br /><br />

<!--ValidationSummary-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/validation/ValidationSummary_cs.aspx"
        ViewSource="~/aspnet/samples/validation/ValidationSummary.src"
        Caption="C# Validation Summary"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/validation/ValidationSummary_vb.aspx"
        ViewSource="~/aspnet/samples/validation/ValidationSummary.src"
        Caption="VB Validation Summary"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>


<!--BEGIN SECTION-->
<a name="compare"></a>
<h3>Working with CompareValidator</h3>

The <b>CompareValidator</b> server control compares the values of two controls.  <b>CompareValidator</b> uses three key properties to perform its validation.  <b>ControlToValidate</b> and <b>ControlToCompare</b>
contain the values to compare.  <b>Operator</b> defines the type of comparison to perform--for example, Equal or Not
Equal.  <b>CompareValidator</b> performs the validation by evaluating these properties as an expression, as follows:
<pre class="code">   ( ControlToValidate <Operator> ControlToCompare ) </pre>

If the expression evaluates true, the validation result is valid.  You can optionally specify the <b>ValueToCompare</b> property to compare against a static value instead of ControlToCompare.

<br /><br />

The <b>CompareValidator</b> server control could also be used to do Datatype validation.For example, if birth date 
information has to be collected from a user registration page, <b>CompareValidator</b> control could be used to make 
sure that the date is in a recognized format before it is submitted to the database.

<br /><br />

The following sample shows how to use the <b>CompareValidator</b> control.

<br /><br />

<!--CompareVal-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/validation/CompareValidator_cs.aspx"
        ViewSource="~/aspnet/samples/validation/CompareValidator.src"
        Caption="C# CompareValidator"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/validation/CompareValidator_vb.aspx"
        ViewSource="~/aspnet/samples/validation/CompareValidator.src"
        Caption="VB CompareValidator"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>


<!--BEGIN SECTION-->
<a name="range"></a>
<h3>Working with RangeValidator</h3>

The <b>RangeValidator</b> server control tests whether an input value falls within a given range.
<b>RangeValidator</b> uses three key properties to perform its validation.  <b>ControlToValidate</b> contains the value
to validate.  <b>MinimumValue</b> and <b>MaximumValue</b> define the minimum and maximum values of the valid
range.

<br /><br />

This sample shows how to use the <b>RangeValidator</b> control.

<br /><br />

<!-- RangeVal -->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/validation/RangeValidator_cs.aspx"
        ViewSource="~/aspnet/samples/validation/RangeValidator.src"
        Caption="C# RangeValidator"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/validation/RangeValidator_vb.aspx"
        ViewSource="~/aspnet/samples/validation/RangeValidator.src"
        Caption="VB RangeValidator"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>


<!--BEGIN SECTION-->
<a name="regex"></a>
<h3>Working with Regular Expressions</h3>

The <b>RegularExpressionValidator</b> server control checks that the entry matches a pattern defined by a
regular expression. This type of validation allows you to check for predictable sequences of characters,
such as those in social security numbers, e-mail addresses, telephone numbers, postal codes, and so on.

<br /><br />

<b>RegularExpressionValidator</b> uses two key properties to perform its validation.  <b>ControlToValidate</b> contains
the value to validate.  <b>ValidationExpression</b> contains the regular expression to match.

<br /><br />

These samples illustrates using the RegularExpressionValidator control.

<br /><br />

<!-- regex -->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/validation/RegularExpressionValidator_cs.aspx"
        ViewSource="~/aspnet/samples/validation/RegularExpressionValidator.src"
        Caption="C# RegularExpressionValidator"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/validation/RegularExpressionValidator_vb.aspx"
        ViewSource="~/aspnet/samples/validation/RegularExpressionValidator.src"
        Caption="VB RegularExpressionValidator"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br /><br />

<!-- more regex-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/validation/RegularExpressionValidator2_cs.aspx"
        ViewSource="~/aspnet/samples/validation/RegularExpressionValidator2.src"
        Caption="C# RegularExpressionValidator 2"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/validation/RegularExpressionValidator2_vb.aspx"
        ViewSource="~/aspnet/samples/validation/RegularExpressionValidator2.src"
        Caption="VB RegularExpressionValidator 2"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>


<!--BEGIN SECTION-->
<a name="custom"></a>
<h3>Performing Custom Validation</h3>

The <b>CustomValidator</b> server control calls a user-defined function to perform validations that the standard
validators can't handle.  The custom function can execute on the server or in client-side script, such as JScript or VBScript.
For client-side custom validation, the name of the custom function must be identified in the <b>ClientValidationFunction</b>
property.  The custom function must have the form 

<code>   function myvalidator(source, arguments)</code>.


Note that <b>source</b> is the client-side <b>CustomValidator</b> object, and <b>arguments</b> is an object with two properties,
<b>Value</b> and <b>IsValid</b>.  The <b>Value</b> property is the value to be validated and the <b>IsValid</b> property is a
Boolean used to set the return result of the validation.

<br /><br />

For server-side custom validation, place your custom validation in the validator's <b>OnServerValidate</b>
delegate.

<br /><br />

The following sample shows how to use the <b>CustomValidator</b> control.

<br /><br />

<!-- custom -->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/validation/CustomValidator_cs.aspx"
        ViewSource="~/aspnet/samples/validation/CustomValidator.src"
        Caption="C# Custom Validator"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/validation/CustomValidator_vb.aspx"
        ViewSource="~/aspnet/samples/validation/CustomValidator.src"
        Caption="VB Custom Validator"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<!--BEGIN SECTION-->
<a name="validateemptytext"></a>
<h3>ValidateEmptyText <span class="newinline">New in 2.0</span></h3>

The <b>ValidateEmptyText</b> property, new in ASP.NET 2.0, fixes an issue with CustomValidator. In ASP.NET 1.0 custom validation would not fire if the text of the <b>ControlToValidate</b> was empty.
You can set this property to true to cause custom validation to occur for empty input values.

<h3>Validation Groups <span class="newinline">New in 2.0</span></h3>

The <b>ValidationGroup</b> property is used when the user wants to perform separate validation scenarios on the same page.
Set the group name on validator controls and on the button or other postback control that causes validation.
This is useful with <b>Wizard</b> control, <b>MultiView</b> or data controls (editing).
By default all validators are in the "" group (default group), for backward compatibility.
<b>Page</b> also exposes <b>GetValidators("group")</b> method and <b>Validate("group")</b> method.
<b>Page.IsValid</b> reflects validity of all controls (cumulative) that have had <b>Validate</b> called.
<br /><br />
The example below demonstrates the ValidationGroup property.  To view the behavior, click the first (Search) button in the 
page, then click the second button on the page.  Notice that a different set of validators fires for each click.
<br /><br />

<!--BEGIN SECTION-->
<a name="validationgroups"></a>
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../aspnet/samples/tipstricks/ValidationGroup_cs.aspx"
        ViewSource="~/aspnet/samples/tipstricks/ValidationGroup.src"
        Caption="C# Validation Groups"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../aspnet/samples/tipstricks/ValidationGroup_vb.aspx"
        ViewSource="~/aspnet/samples/tipstricks/ValidationGroup.src"
        Caption="VB Validation Groups"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<!--BEGIN SECTION-->
<a name="setfocusonerror"></a>
<h3>SetFocusOnError <span class="newinline">New in 2.0</span></h3>

Another new validation feature in ASP.NET 2.0 is <b>SetFocusOnError</b> which is set on validator controls which causes the first invalid control to receive focus.
For more information about SetFocusOnError, refer to the <asp:HyperLink NavigateUrl="~/aspnet/doc/tipstricks/default.aspx#focusapi" runat="server">Focus API</asp:HyperLink> topic in the <asp:HyperLink NavigateUrl="~/aspnet/doc/tipstricks/default.aspx" runat="server">Tips and Tricks</asp:HyperLink> section.


<!--BEGIN SECTION-->
<a name="together"></a>
<h3>A Typical Validation Form</h3>

This sample shows a typical registration form, using the variations of validation controls discussed in this topic.

<br /><br />

<!-- summary -->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/validation/ValidationForm_cs.aspx"
        ViewSource="~/aspnet/samples/validation/ValidationForm.src"
        Caption="C# Validation Form"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/validation/ValidationForm_vb.aspx"
        ViewSource="~/aspnet/samples/validation/ValidationForm.src"
        Caption="VB Validation Form"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>

