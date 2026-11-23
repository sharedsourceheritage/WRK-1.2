<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.HtmlControls.HtmlInputFile" runat="server">
  HtmlInputFile
</Acme:TypeRef>
</h2>

An <b>HtmlInputFile</b> control handles uploading of binary or text files from a client browser to the server.
File-upload works with all HTML 3.2 and later Web clients.  Note that the <b>Enctype</b> attribute on the
<b>&lt;form&gt;</b> tag must be set to <b>"multipart/form-data"</b>.

<br /><br />

The following sample illustrates using the <b>HtmlInputFile</b> control.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlInputFile/HtmlInputFile1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlInputFile/HtmlInputFile1.src"
        Caption="C# HtmlInputFile1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/html/HtmlInputFile/HtmlInputFile1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/html/HtmlInputFile/HtmlInputFile1.src"
        Caption="VB HtmlInputFile1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>

