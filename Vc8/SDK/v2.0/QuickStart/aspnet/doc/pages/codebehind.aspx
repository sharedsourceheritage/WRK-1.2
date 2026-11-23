<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>

<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>


<h2>Code Behind vs. Code Inline</h2>

ASP.NET provides two ways that you can organize code within your pages.

<a name="inline"></a>
<h3>Inline Code Separation</h3>

The example below demonstrates a simple ASP.NET page with three server controls, a TextBox, Button, and a Label.  Initially these controls just render their HTML form equivalents.  However, when a value is typed in the TextBox and the Button is clicked on the client, the page posts back to the server and the page handles this click event in the code of the page, dynamically updating the Text property of the Label control.  The page then re-renders to reflect the updated text.  This simple example demonstrates the basic mechanics behind the server control model that has made ASP.NET one of the easiest Web programming models to learn and master.

<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/simple/Inline_cs.aspx"
        ViewSource="~/aspnet/samples/simple/Inline.src"
        Caption="C# Inline Code Separation"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/simple/Inline_vb.aspx"
        ViewSource="~/aspnet/samples/simple/Inline.src"
        Caption="VB Inline Code Separation"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br/>

Note that in the preceding example the event handler for the Button was located between <code>&lt;script&gt;&lt;/script&gt;</code> tags in the same page containing the server controls.  ASP.NET calls this type of page programming <b>code-inline</b>, and it is very useful when you want to maintain your code and presentation logic in a single file.  However, ASP.NET also supports another way to factor your code and presentation content, called the <b>code-behind</b> model.  When using code-behind, the code for handling events is located in a physically separate file from the page that contains server controls and markup.  This clear delineation between code and content is useful when you need to maintain these separately, such as when more than one person is involved in creating the application.  It is often common in group projects to have designers working on the UI portions of an application while developers work on the behavior or code.  The code-behind model is well-suited to that environment.

<a name="codebehind"></a>
<h3>Simplified Code Behind Model <span class="newinline">New in 2.0</span></h3>

ASP.NET 2.0 introduces an improved runtime for code-behind pages that simplifies the connections between the page and code.  In this new code-behind model, the page is declared as a partial class, which enables both the page and code files to be compiled into a single class at runtime.  The page code refers to the code-behind file in the <code>CodeFile</code> attribute of the <code>&lt;%@ Page %&gt;</code> directive, specifying the class name in the <code>Inherits</code> attribute.  Note that members of the code behind class must be either public or protected (they cannot be private).

<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/simple/CodeBehind_cs.aspx"
        ViewSource="~/aspnet/samples/simple/CodeBehind.src"
        Caption="C# CodeBehind Code Separation"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/simple/CodeBehind_vb.aspx"
        ViewSource="~/aspnet/samples/simple/CodeBehind.src"
        Caption="VB CodeBehind Code Separation"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<br />

The advantage of the simplified code-behind model over previous versions is that you do not need to maintain separate declarations of server control variables in the code-behind class.  Using partial classes (new in 2.0) allows the server control IDs of the ASPX page to be accessed directly in the code-behind file.  This greatly simplifies the maintenance of code-behind pages.

</asp:Content>

