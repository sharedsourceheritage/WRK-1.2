<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.DataList" runat="server">
  DataList
</Acme:TypeRef>
</h2>

The <b>DataList</b> control displays data items in a repeating list, and optionally supports selecting and
editing the items. The content and layout of list items in <b>DataList</b> is defined using templates. At a
minimum, every <b>DataList</b> must define an <b>ItemTemplate</b>; however, several optional templates can be used to
customize the appearance of the list. The following table describes those templates.

<br /><br />

<table class="table">
    <tr>
    <th width="200"><b>Template Name</b></th>
    <th width="*"><b>Description</b></th>
    </tr>
    <tr>
    <td><b>ItemTemplate</b></td>
    <td>Defines the content and layout of items within the list. Required.</td>
    </tr>
    <tr>
    <td><b>AlternatingItemTemplate</b></td>
    <td>If defined, determines the content and layout of alternating items.  If not defined, <b>ItemTemplate</b> is used.</td>
    </tr>
    <tr>
    <td><b>SeparatorTemplate</b></td>
    <td>If defined, is rendered between items (and alternating items).  If not defined, a separator is not rendered.</td>
    </tr>
    <tr>
    <td><b>SelectedItemTemplate</b></td>
    <td>If defined, determines the content and layout of the selected item.  If not defined, <b>ItemTemplate</b> (<b>AlternatingItemTemplate</b>) is used.</td>
    </tr>
    <tr>
    <td><b>EditItemTemplate</b></td>
    <td>If defined, determines the content and layout of the item being edited.  If not defined, <b>ItemTemplate</b> (<b>AlternatingItemTemplate</b>, <b>SelectedItemTemplate</b>) is used.</td>
    </tr>
    <tr>
    <td><b>HeaderTemplate</b></td>
    <td>If defined, determines the content and layout of the list header.  If not defined, the header is not rendered.</td>
    </tr>
    <tr>
    <td><b>FooterTemplate</b></td>
    <td>If defined, determines the content and layout of the list footer.  If not defined, the footer is not rendered.</td>
    </tr>
</table>

<br />

Templates define the HTML elements and controls that should be displayed for an item, as well as the layout of these
elements.  Style formatting -- font, color, and border attributes -- is set via styles.  Each template has its
own style property.  For example, styles for the <b>EditItemTemplate</b> are set through the <b>EditItemStyle</b> property.

<br /><br />

A third set of properties affect the overall rendering of <b>DataList</b>.  By default, <b>DataList</b> items render within a
table as a single vertical column.  Setting the <b>RepeatLayout</b> property to <b>Flow</b> removes the HTML table
structure from the rendering of the list.

<br /><br />

<b>DataList</b> supports directional rendering through the <b>RepeatDirection</b> property,
meaning it can render its items horizontally or vertically.  Since page width is the dimension that the developer
must control in Web user interface, <b>DataList</b> permits the developer to control the number of "columns" that are rendered
(<b>RepeatColumns</b>), regardless of whether the items are rendered horizontally or vertically.

<br /><br />

If <b>RepeatDirection</b> is <b>Horizontal</b> and <b>RepeatColumns</b> is <b>five</b>, the items are rendered in rows containing five columns.<p>

<table class="table" style="width:400px">
<tr>
    <td width="20%">1</td>
    <td width="20%">2</td>
    <td width="20%">3</td>
    <td width="20%">4</td>
    <td width="20%">5</td>
</tr><tr>
    <td>6</td>
    <td>7</td>
    <td>8</td>
    <td>9</td>
    <td>10</td>
</tr><tr>
    <td>11</td>
    <td>12</td>
    <td>13</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
</tr>
</table>

<br />

If <b>RepeatDirection</b> is <b>Vertical</b>, and <b>RepeatColumns</b> remains set to <b>five</b>, the items are rendered
in five columns, each equal in length to the total number of items divided by five.

<br /><br />

<table class="table" style="width:400px">
<tr>
    <td width="20%">1</td>
    <td width="20%">4</td>
    <td width="20%">7</td>
    <td width="20%">10</td>
    <td width="20%">12</td>
</tr><tr>
    <td>2</td>
    <td>5</td>
    <td>8</td>
    <td>11</td>
    <td>13</td>
</tr><tr>
    <td>3</td>
    <td>6</td>
    <td>9</td>
    <td>&nbsp;</td>
    <td>&nbsp;</td>
</tr>
</table>

<br />

The following sample illustrates using a simple <b>DataList</b> control.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/data/DataList/DataList1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/data/DataList/DataList1.src"
        Caption="C# Simple DataList"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/data/DataList/DataList1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/data/DataList/DataList1.src"
        Caption="VB Simple DataList"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>


<!--BEGIN SECTION-->
<a name="selecting"></a>
<h3>Selecting Items in DataList</h3>

You can customize the content and appearance of the selected item through the <b>SelectedItemTemplate</b>
property.  The <b>SelectedItemTemplate</b> is controlled by the <b>SelectedIndex</b> property.  By default the value of
<b>SelectedIndex</b> is -1, meaning none of the items in the list is selected.  When <b>SelectedIndex</b> is set to a
particular item, that item is displayed using the <b>SelectedItemTemplate</b>.

<br /><br />

The following sample illustrates using a <b>SelectedItemTemplate</b> in <b>DataList</b>.

<br /><br />
<!--selected item-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/data/DataList/DataList2_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/data/DataList/DataList2.src"
        Caption="C# DataList SelectedItemTemplate"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/data/DataList/DataList2_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/data/DataList/DataList2.src"
        Caption="VB DataList SelectedItemTemplate"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<!--BEGIN SECTION-->
<a name="editing"></a>
<h3>Editing DataList Items</h3>

The <b>DataList</b> control supports in-place editing of the data in an item through its <b>EditItemTemplate</b>
property.  The <b>EditItemTemplate</b> defines the content and appearance of the item when it is being edited.  For
example, the following template includes a text box, an &quot;Update&quot; button and a &quot;Cancel&quot; button.

<pre class="code">
&lt;EditItemTemplate&gt;
&nbsp;&nbsp;&nbsp;&nbsp;Item: &lt;asp:TextBox id=&quot;Text1&quot; runat=&quot;server&quot;
&nbsp;&nbsp;&nbsp;&nbsp;Text='&lt;%# ((DataRowView)Container.DataItem)[&quot;Item&quot;]  %&gt;'
&nbsp;&nbsp;&nbsp;&nbsp;/>&lt;br&gt;
&lt;asp:LinkButton id=&quot;button1&quot; runat=&quot;server&quot;
&nbsp;&nbsp;&nbsp;&nbsp;Text=&quot;Update&quot;
&nbsp;&nbsp;&nbsp;&nbsp;CommandName=&quot;update&quot;
&nbsp;&nbsp;&nbsp;&nbsp;/&gt;
&lt;asp:LinkButton id=&quot;button2&quot; runat=&quot;server&quot;
&nbsp;&nbsp;&nbsp;&nbsp;Text=&quot;Cancel&quot;
&nbsp;&nbsp;&nbsp;&nbsp;CommandName=&quot;cancel&quot;
&nbsp;&nbsp;&nbsp;&nbsp;/&gt;
&lt;/EditItemTemplate&gt;
</pre>

The <b>EditItemTemplate</b> interacts with another property: <b>EditItemIndex</b>.  By default, the value of
<b>EditItemIndex</b> is -1, meaning none of the items in the list is being edited.  When <b>EditItemIndex</b> is set to a
particular item, that item is displayed using the <b>EditItemTemplate</b>.

<br /><br />

The <b>DataList</b> also supplies three events that can be used to support editing.  <b>EditCommand</b> is thrown
when an &quot;edit&quot; command button control is clicked within the list's <b>ItemTemplate</b>.  It's up to you to handle this event
in your code.  The typical logic sets <b>EditItemIndex</b> to the selected item, and then rebinds the data to the <b>DataList</b> as shown in the following example.

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
protected void DataList_EditCommand(object Source, DataListCommandEventArgs e) {
    DataList1.EditItemIndex = (int)e.Item.ItemIndex;
    BindList();
}
</Tab>

<Tab Name="VB">
Protected Sub DataList_EditCommand(Source As Object, e As DataListCommandEventArgs)
    DataList1.EditItemIndex = CType(e.Item.ItemIndex, Integer)
    BindList()
End Sub
</Tab>

</Acme:TabControl><p>

The <b>EditItemTemplate</b> typically contains &quot;update&quot; and &quot;cancel&quot; command buttons.  These buttons cause the
<b>UpdateCommand</b> and <b>CancelCommand</b> events to be thrown, respectively.  It's up to you to handle these events
in your code.  The typical logic for &quot;cancel&quot; sets <b>EditItemIndex</b> to -1, and then rebinds the data to the <b>DataList</b> as shown in the following example.<p>

<p><Acme:TabControl runat="server">
<Tab Name="C#">
protected void DataList_CancelCommand(object Source, DataListCommandEventArgs e) {
    DataList1.EditItemIndex = -1;
    BindList();
}
</Tab>

<Tab Name="VB">
Protected Sub DataList_CancelCommand(Source As Object, e As DataListCommandEventArgs)
    DataList1.EditItemIndex = -1
    BindList()
End Sub
</Tab>

</Acme:TabControl>

<br />

The typical logic for &quot;update&quot; updates the data source, sets <b>EditItemIndex</b> to -1, and then rebinds the data to the
<b>DataList</b>.  The following sample illustrates editing items in <b>DataList</b>.

<br /><br />

<!--edit item-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/data/DataList/DataList3_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/data/DataList/DataList3.src"
        Caption="C# DataList Editing"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/data/DataList/DataList3_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/data/DataList/DataList3.src"
        Caption="VB DataList Editing"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

<b>DataList</b> renders additional elements, like table rows and cells and spans containing style attributes, outside of the template definition to enable 
layout formatting.  For example, <b>DataList</b> supports <b>RepeatColumns</b> and <b>RepeatDirection</b> properties that specify whether
data should be rendered in multiple columns, and in which direction (vertical or horizontal) the data items should be rendered.  <b>DataList</b> also
supports style attributes, as shown in the following example.

<pre class="code">
&lt;ASP:DataList runat="server" DataSource="&lt;%#MyData%&gt;"
    RepeatColumns="2"
    RepeatDirection="Horizontal"
    ItemStyle-Font-Size="10pt"
    ItemStyle-Font-Name="Verdana"
&gt;
    ...
&lt;/ASP:DataList&gt;
</pre>

The following sample demonstrates the <b>DataList</b> control with the <b>RepeatDirection</b> and <b>RepeatColumns</b>
properties set to determine how the <b>ItemTemplates</b> are laid out.

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/data/DataList/DataList4_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/data/DataList/DataList4.src"
        Caption="C# DataList RepeatDirection and RepeatColumns"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/data/DataList/DataList4_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/data/DataList/DataList4.src"
        Caption="VB DataList RepeatDirection and RepeatColumns"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

The following example further demonstrates the flexibility of templates by changing the <b>ItemTemplate</b> yet again.
This time, one of the <b>DataItem</b> values has been substituted for the "src" attribute of an <b>&lt;img&gt;</b> tag. The <i>format</i> 
<b>String</b> parameter of <b>DataBinder.Eval</b> has also been used to substitute a <b>DataItem</b> value in the query string for a URL.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/data/DataList/DataList5_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/data/DataList/DataList5.src"
        Caption="C# DataList ItemTemplate Customization"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/data/DataList/DataList5_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/data/DataList/DataList5.src"
        Caption="VB DataList ItemTemplate Customization"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

You can fire a command from inside a <b>DataList</b> template that is passed to an event handler wired to the
<b>DataList</b> itself.  For example, a <b>LinkButton</b> inside the <b>ItemTemplate</b> might fire a <b>Select</b> command.  By setting the
<b>OnSelectedIndexChanged</b> property of the <b>DataList</b>, you can call an event handler in response to this command. The following example demonstrates this process.
The following sample demonstrates this code in action.  In the <code>MyDataList_Select</code> event handler, you populate several other server controls
with the details about the particular selected item.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/data/DataList/DataList6_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/data/DataList/DataList6.src"
        Caption="C# DataList Selection"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/data/DataList/DataList6_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/data/DataList/DataList6.src"
        Caption="VB DataList Selection"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

Note that while the <b>DataList</b> recognizes a few special commands such as <b>Select</b> and <b>Edit/Update/Cancel</b>, the command string fired inside a template
can be any arbitrary string.  For all commands, the <b>DataList</b>'s <b>OnItemCommand</b> is fired.  You can wire this event to a handler
as in the previous example; the following example shows how to do this.
<br /><br />

Note that because more than one command can fire this event handler, you must employ a switch statement to determine the
particular command that was fired.  The following sample demonstrates this code in action.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/data/DataList/DataList7_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/data/DataList/DataList7.src"
        Caption="C# DataList ItemCommand Event"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/data/DataList/DataList7_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/data/DataList/DataList7.src"
        Caption="VB DataList ItemCommand Event"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

In addition to handling the <b>Select</b> command using a page-level event handler, the <b>DataList</b> can respond to this event internally.  If a
<b>SelectedItemTemplate</b> is defined for the <b>DataList</b>, the <b>DataList</b> renders this template for the item that fired the <b>Select</b>
command.  The following example uses the <b>SelectedItemTemplate</b> to make the title of the selected book bold.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/data/DataList/DataList8_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/data/DataList/DataList8.src"
        Caption="C# DataList SelectedItemTemplate (2)"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/data/DataList/DataList8_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/data/DataList/DataList8.src"
        Caption="VB DataList SelectedItemTemplate (2)"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

<b>DataList</b> also supports an <b>EditItemTemplate</b> for rendering an item whose index is equal to the <b>DataList</b>'s <b>EditItemIndex</b>
property.  Note that DataList does not support automatically updating and deleting using a data source control, so you need to write code to handle the
edit, update, and delete commands yourself (using the same model as was supported in ASP.NET v1.x).
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/data/DataList/DataList9_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/data/DataList/DataList9.src"
        Caption="C# DataList Editing (2)"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/data/DataList/DataList9_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/data/DataList/DataList9.src"
        Caption="VB DataList Editing (2)"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

Sometimes it is necessary to locate a control contained inside a template.  If a control is given an ID in a template, that control can be
retrieved from its container (the first control in the parent hierarchy that supports <b>INamingContainer</b>).  In this case, the
container is the <b>DataListItem</b> control.  Note that even though there are several controls with the same ID (by virtue of the <b>DataList</b>'s
repetition), each is contained logically in the namespace of the <b>DataListItem</b> container control.
<br /><br />

You can go through the <b>DataList</b>'s <b>Items</b> collection to retrieve the <b>DataListItem</b> for a given index, and then call
the <b>DataListItem</b>'s <b>FindControl</b> method (inherited from the base <b>Control</b> class) to retrieve a control with a particular ID.
<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
&lt;script runat="server"&gt;

    public void Page_Load(Object sender, EventArgs E)) {
        // set datasource and call databind here

        for (int i=0; i&lt;MyDataList.Items.Count; i++) {
           String isChecked = ((CheckBox) MyDataList.Items[i].FindControl("Save")).Checked.ToString();
           If (isChecked == "True") {
             ...
           }
        }
    }
&lt;/script&gt;

&lt;ASP:DataList id="MyDataList" runat="server"&gt;

    &lt;ItemTemplate&gt;
         &lt;asp:CheckBox id="Save" runat="server"/&gt; &lt;b&gt;Save to Favorites&lt;/b&gt;
    &lt;/ItemTemplate&gt;

&lt;/ASP:DataList&gt;
</Tab>

<Tab Name="VB">
&lt;script runat="server"&gt;

    Public Sub Page_Load(sender As Object, E As EventArgs))
        ' set datasource and call databind here

        For I=0 To MyDataList.Items.Count-1
           Dim IsChecked As String =  MyDataList.Items(i).FindControl("Save").Checked.ToString()
           If IsChecked = "True" Then
             ...
           End If
        Next
    End Sub
&lt;/script&gt;

&lt;ASP:DataList id="MyDataList" runat="server"&gt;

    &lt;ItemTemplate&gt;
         &lt;asp:CheckBox id="Save" runat="server"/&gt; &lt;b&gt;Save to Favorites&lt;/b&gt;
    &lt;/ItemTemplate&gt;

&lt;/ASP:DataList&gt;
</Tab>

</Acme:TabControl>
<br />

The following sample demonstrates this code in action.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/data/DataList/DataList10_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/data/DataList/DataList10.src"
        Caption="C# Finding a Control in a DataList Template"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/data/DataList/DataList10_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/data/DataList/DataList10.src"
        Caption="VB Finding a Control in a DataList Template"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

</asp:Content>


