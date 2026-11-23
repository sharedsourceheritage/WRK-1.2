<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2>How Do I...Use the CodeDOM to emit source code?</h2>

<div class="indent" style="width:660">
<h5>What is the CodeDOM</h5>
<br /><br />The CodeDOM is an API that gives you the ability to create a programming structure of
namespaces, objects, and programming constructs by adding items to different collections.
All CodeDOM programs start out with the creation of a <b>ICodeGenerator</b> for the target
language.  The following code shows the creation of the <b>ICodeGenerator</b> for C#.

<br /><br />
<Acme:TabControl runat="server">
<Tab Name="C#">
ICodeGenerator cg =new CSharpCodeProvider().CreateGenerator();
 ...
CSharpCodeProvider cdp = new CSharpCodeProvider();
cg = cdp.CreateGenerator();
</Tab>
<Tab Name="VB">
Dim cg As ICodeGenerator = New CSharpCodeProvider().CreateGenerator()
 ...
Dim cdp As New CSharpCodeProvider()
cg = cdp.CreateGenerator()
</Tab>
</Acme:TabControl>

<br /><br />
The <b>ICodeGenerator</b> is used to generate the actual code once a CodeDOM tree is built. To begin building your tree, you need to start with a <b>CodeNamespace</b> object.  This object
will contain any types and import directives.  With the <b>CodeNamespace</b> object you can
begin the tree.  For the following sample, several <b>CodeNamespaceImport</b> objects
are used to generate import directives for commonly used namespaces. The sample also
needs to generate a class construct so by using a <b>CodeTypeDeclaration</b> and setting the
<b>IsClass</b> property to true. The following code demonstrates these concepts.

<br /><br />
<Acme:TabControl runat="server">
<Tab Name="C#">
CodeNamespace cnamespace = new CodeNamespace("Microsoft.Samples");
cnamespace.Imports.Add (new CodeNamespaceImport ("System") );
 ...
CodeTypeDeclaration co = new CodeTypeDeclaration (typeName +"List");
co.IsClass = true;
cnamespace.Types.Add (co);
</Tab>
<Tab Name="VB">
Dim cnamespace As New CodeNamespace("Microsoft.Samples")
cnamespace.Imports.Add(New CodeNamespaceImport("System"))
 ...
Dim co As New CodeTypeDeclaration(typeName + "List")
co.IsClass = true
cnamespace.Types.Add (co)
</Tab>
</Acme:TabControl>

<br /><br />
At the end of the previous example, the class type definition is added
to the <b>Types</b> collection of the <b>CodeNamespace</b> object. This is how a CodeDOM
tree is built.  Starting with a <b>CodeNamespace</b> object and working down through classes
to class members. Class members in turn contain different types of code statements
and expressions. Once the entire tree is built, the entire source tree can be written
with a call to <b>GenerateCodeFromNamespace</b>, a method on <b>ICodeGenerator</b>.
The method is being passed the <b>CodeNamespace</b> object and a <b>TextWriter</b>.

<br /><br />
<Acme:TabControl runat="server">
<Tab Name="C#">
baseCompiler.GenerateCodeFromNamespace (cnamespace, w, null);
</Tab>
<Tab Name="VB">
baseCompiler.GenerateCodeFromNamespace (cnamespace, w, Nothing)
</Tab>
</Acme:TabControl>

<br /><br />
The following sample demonstrates the techniques described above by generating
the code for a strongly typed List. It also contains additional information and code
for generating code statements and expressions that were left out of the above documentation
for brevity.
</div>

<h2>Example</h2>


<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/CompMod/CodeDom/ListBuilder/listbuilder.src"
        Icon="../../images/console.gif"
        Caption="C# ListBuilder.exe"
	SamplePath="howto\samples\CompMod\CodeDom\ListBuilder\"
        CanBeHosted="false"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource="~/howto/samples/CompMod/CodeDom/ListBuilder/listbuilder.src"
        Icon="../../images/console.gif"
        Caption="VB ListBuilder.exe"
	SamplePath="howto\samples\CompMod\CodeDom\ListBuilder\"
        CanBeHosted="false"
        runat="server" />
  </VbTemplate>
 <VjsTemplate>
        <Acme:SourceRef
        RunSample=""
        ViewSource=""
        Icon = ""
        Caption=""
        CanBeHosted="false"
        runat="server" />	
  </VjsTemplate>
</Acme:LangSwitch>
</asp:Content>

