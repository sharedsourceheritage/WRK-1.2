<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.BulletedList" runat="server">
  BulletedList
</Acme:TypeRef>
</h2>

The <b>BulletedList</b> control is used to create a list of items formatted with bullets. To specify the individual list items that you want to appear in a <b>BulletedList</b> control, place a <b>ListItem</b> object for each entry between the opening and closing tags of the <b>BulletedList</b> control.

<p>

<h3>List Bullet Styles</h3>
<p>
BulletedList controls can display list of items with a variety of bullet styles. To control the style of bullet used, use the <b>BulletedList.BulletSyle</b> property.
The following example shows how to render a list of items with circular bullets.
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/BulletedList/BulletedList1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/BulletedList/BulletedList1.src"
        Icon = "../../../images/genicon.gif"
        Caption="C# BulletedList1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/BulletedList/BulletedList1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/BulletedList/BulletedList1.src"
        Icon = "../../../images/genicon.gif"
        Caption="VB BulletedList1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<h3>List of Hyperlinks</h3>
<p>
The BulletedList control can also render a list of hyperlinks. 
The BulletedList control also provides a convenient way to render a list of hyperlinks,
as an alternative to creating multiple individual <b>HyperLink</b> controls.
<br /><br />
To render each item in the list as a hyperlink, set the <b>BulletedList.DisplayMode</b>
property to <b>BulletedListDisplayMode.HyperLink</b>, and set the <b>Value</b> property
of each list item to the navigation URL for the item. Lists of hyperlinks can
also be displayed with a variety of bullet styles, as above.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/BulletedList/BulletedList2_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/BulletedList/BulletedList2.src"
        Icon = "../../../images/genicon.gif"
        Caption="C# BulletedList2.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/BulletedList/BulletedList2_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/BulletedList/BulletedList2.src"
        Icon = "../../../images/genicon.gif"
        Caption="VB BulletedList2.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
