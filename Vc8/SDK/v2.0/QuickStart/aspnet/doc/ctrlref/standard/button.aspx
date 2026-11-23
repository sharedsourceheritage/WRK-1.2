<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.Button" runat="server">
  Button
</Acme:TypeRef>
</h2>

The <b>Button</b> control provides a command button-style control that is used to post a Web Forms page back to the server.
The following sample illustrates using a simple <b>Button</b> control.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/button/Button1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/button/Button1.src"
        Caption="C# Button1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/button/Button1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/button/Button1.src"
        Caption="VB Button1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="command"></a>
<h3>Bubbling Button Clicks Within a List</h3>

When used in a templated list such as a <asp:HyperLink NavigateUrl="~/aspnet/doc/ctrlref/data/repeater.aspx" runat="server">Repeater</asp:HyperLink> or <asp:HyperLink NavigateUrl="~/aspnet/doc/ctrlref/data/datalist.aspx" runat="server">DataList</asp:HyperLink>, many <b>Button</b> controls might be
rendered as the list iterates over its data source. Because each of these <b>Button</b> controls shares the same ID, you cannot simply bind an event handler to each <b>Button</b> control's <b>OnClick</b> event to determine the particular <b>Button</b> that was clicked.  To solve this, you use event bubbling to  fire an event on the container control (in this case, the <b>Repeater</b>, <b>DataList</b>, or <b>DataGrid</b>), and let the container impart additional information to the event handler about the item that raised the event.

<br /><br />

These events can be raised from a <b>Button</b> by specifying a <b>CommandName</b> property with the name of the event.  When the <b>Button</b> is clicked, the command "bubbles" to the container control (such as <b>Repeater</b>), which fires its own event. The arguments for this event might contain additional information, such as a custom string or the index of the item that raised the event.

<br /><br />

The following sample illustrates how a <b>Button</b> control's commands can bubble to the <b>OnItemCommand</b> event of a list.  The <b>Button</b> control's <b>CommandName</b> and <b>CommandArgument</b> strings are passed to the <b>OnItemCommand</b> event, permitting the sample code to distinguish which button was clicked.

<br /><br />

<!--command button-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/button/Button2_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/button/Button2.src"
        Caption="C# Button2.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/button/Button2_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/button/Button2.src"
        Caption="VB Button2.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="mouseover"></a>
<h3>Mouse-Over Effects on Button</h3>

You can hook the client script events <b>onmouseover</b> and <b>onmouseout</b> on a <b>Button</b> control to provide mouse-over
effects such as changing the font or color of the button.  Client attributes such as <b>onmouseover</b> are disregarded by ASP.NET
on the server, and passed "as is" to the browser.  If your application targets newer browsers that support DHTML, these
events will fire in the browser as the cursor passes over the button. The following sample demonstrates buttons with mouse-over effects.

<br /><br />

<!--rollover-->

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/button/Button3_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/button/Button3.src"
        Caption="C# Button3.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/button/Button3_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/button/Button3.src"
        Caption="VB Button3.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
