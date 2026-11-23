<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.ImageButton" runat="server">
  ImageButton
</Acme:TypeRef>
</h2>

Like the <b>Button</b> control, <b>ImageButton</b> is used to post back to the server. For additional button
examples, see <asp:HyperLink NavigateUrl="~/aspnet/doc/ctrlref/standard/button.aspx" runat="server">
Button</asp:HyperLink> and <asp:HyperLink NavigateUrl="~/aspnet/doc/ctrlref/standard/linkbutton.aspx" runat="server">
LinkButton</asp:HyperLink>.

<br /><br />

The following sample illustrates using the <b>ImageButton</b> control.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/ImageButton/ImageButton1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/ImageButton/ImageButton1.src"
        Caption="C# ImageButton1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/ImageButton/ImageButton1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/ImageButton/ImageButton1.src"
        Caption="VB ImageButton1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<!--image map-->
<a name="imagemap"></a>
<h3>Using ImageButton as an Image Map</h3>

The <b>ImageButton</b> click event also supplies the x/y coordinates of where the user clicked the image.
This provides a means to respond differently depending on what part of the image is clicked.

<br /><br />

The following sample illustrates using the <b>ImageButton</b> control as an image map.

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/ImageButton/ImageButton2_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/ImageButton/ImageButton2.src"
        Caption="C# ImageButton2.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/ImageButton/ImageButton2_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/ImageButton/ImageButton2.src"
        Caption="VB ImageButton2.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="mouseover"></a>
<h3>Mouse-Over Effects on ImageButton</h3>

You can hook the client script events <b>onmouseover</b> and <b>onmouseout</b> on an <b>ImageButton</b> control to provide mouse-over
effects such as changing the image source of the button.  Client attributes such as <b>onmouseover</b> are disregarded by ASP.NET
on the server and passed unchanged to the browser.  If your application targets newer browsers that support DHTML, these
events will occur in the browser as the cursor passes over the button.

<br />

<!--rollover-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/ImageButton/ImageButton3_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/ImageButton/ImageButton3.src"
        Caption="C# ImageButton3.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/ImageButton/ImageButton3_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/ImageButton/ImageButton3.src"
        Caption="VB ImageButton3.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
