<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.Repeater" runat="server">
  Repeater
</Acme:TypeRef>
</h2>

The <b>Repeater</b> control displays data items in a repeating list.  Similar to
<asp:HyperLink NavigateUrl="~/aspnet/doc/ctrlref/data/datalist.aspx" runat="server">DataList</asp:HyperLink>,
the content and layout of list items in <b>Repeater</b> is defined using <b>templates</b>.
At a minimum, every <b>Repeater</b> must define an <b>ItemTemplate</b>; however, the following optional templates may be used to
customize the appearance of the list.

<br /><br />

<table class="table">
    <tr>
    <th width="200"><b>Template Name</b></th>
    <th><b>Description</b></th>
    </tr>
    <tr>
    <td><b>ItemTemplate</b></td>
    <td>Defines the content and layout of items within the list.  <b>Required</b>.</td>
    </tr>
    <tr>
    <td><b>AlternatingItemTemplate</b></td>
    <td>If defined, the <b>AlternatingItemTemplate</b> determines the content and layout of alternating items.  If not defined, <b>ItemTemplate</b> is used.</td>
    </tr>
    <tr>
    <td><b>SeparatorTemplate</b></td>
    <td>If defined, the <b>SeparatorTemplate</b> is rendered between items (and alternating items).  If not defined, a separator is not rendered.</td>
    </tr>
    <tr>
    <td><b>HeaderTemplate</b></td>
    <td>If defined, the <b>HeaderTemplate</b> determines the content and layout of the list header.  If not defined, header is not rendered.</td>
    </tr>
    <tr>
    <td><b>FooterTemplate</b></td>
    <td>If defined, the <b>FooterTemplate</b> determines the content and layout of the list footer.  If not defined, footer is not rendered.</td>
    </t>
</table>

<br />

Unlike <b>DataList</b>, <b>Repeater</b> has no built-in layout or styles. You must explicitly declare all
HTML layout, formatting, and style tags within the templates of the control.  For example, to create a list within an
HTML table, you might declare the &lt;table&gt; tag in the <b>HeaderTemplate</b>, a table row (&lt;tr&gt; tags, &lt;td&gt; tags,
and data-bound items) in the <b>ItemTemplate</b>, and the &lt;/table&gt; tag in the <b>FooterTemplate</b>.

<br /><br />

The following samples illustrate using a simple <b>Repeater</b> control.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
<Acme:SourceRef
  RunSample="../../../samples/ctrlref/data/repeater/Repeater1_cs.aspx"
  ViewSource="~/aspnet/samples/ctrlref/data/repeater/Repeater1.src"
  Caption="C# Repeater1.aspx"
  runat="server" />
  </CsTemplate>
  <VbTemplate>
<Acme:SourceRef
  RunSample="../../../samples/ctrlref/data/repeater/Repeater1_vb.aspx"
  ViewSource="~/aspnet/samples/ctrlref/data/repeater/Repeater1.src"
  Caption="VB Repeater1.aspx"
  runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
<Acme:SourceRef
  RunSample="../../../samples/ctrlref/data/repeater/Repeater2_cs.aspx"
  ViewSource="~/aspnet/samples/ctrlref/data/repeater/Repeater2.src"
  Caption="C# Repeater2.aspx"
  runat="server" />
  </CsTemplate>
  <VbTemplate>
<Acme:SourceRef
  RunSample="../../../samples/ctrlref/data/repeater/Repeater2_vb.aspx"
  ViewSource="~/aspnet/samples/ctrlref/data/repeater/Repeater2.src"
  Caption="VB Repeater2.aspx"
  runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<br />

</asp:Content>
