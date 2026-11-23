<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix="Acme" Namespace="Acme" %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.MultiView" runat="server">
  MultiView
</Acme:TypeRef>
and
<Acme:TypeRef TypeName="System.Web.UI.WebControls.View" runat="server">
  View
</Acme:TypeRef>
</h2>

<p>
The MultiView control represents a control that acts as a container for groups of View controls. 
It allows you to define a group of View controls, where each View control contains child controls, 
for example, in an online survey application. Your application can then render a specific View control 
to the client based on criteria such as user identity, user preferences, or information passed in a 
query string parameter.
</p>
<p>
The following sample illustrates a MultiView control hosting 3 View controls.
</p>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/MultiView/MultiView1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/MultiView/MultiView1.src"
        Caption="C# MultiView1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/MultiView/MultiView1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/MultiView/MultiView1.src"
        Caption="VB MultiView1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
