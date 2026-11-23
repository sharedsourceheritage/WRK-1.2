<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4>How Do I...Use the Xml Schema Object Model?</h4>

<p>
This sample illustrates how to read two XML Schema Definition language (XSD) schemas into a SchemaSet and navigate through the schemas that they represent.
<p>
This sample shows how to use the XmlSchemaSet to cache and retrieve multiple schemas, and demonstrates that the Schema Object Model (SOM) loads and saves valid XML Schemas. You can also use the SOM to create in-memory schemas by using strongly-typed classes.
<p>
To demonstrate how to navigate the SOM, this sample outputs a formatted version of the two XML Schemas that were loaded into the XmlSchemaSet.
<Acme:LangSwitch runat="server">
  <CsTemplate>
<Acme:SourceRef
RunSample=""
ViewSource="~/howto/samples/Xml/XmlSchemaObjectModel/XmlSchemaObjectModel.src"
Icon="../../../images/genicon.gif"
Caption="C# XmlSchemaObjectModel.exe"
SamplePath="howto\samples\Xml\XmlSchemaObjectModel\"
CanBeHosted="false"
runat="server" />
  </CsTemplate>
  <VbTemplate>
<Acme:SourceRef
ViewSource="~/howto/samples/Xml/XmlSchemaObjectModel/XmlSchemaObjectModel.src"
RunSample=""
Icon="../../../images/genicon.gif"
Caption="VB XmlSchemaObjectModel.exe"
SamplePath="howto\samples\Xml\XmlSchemaObjectModel\"
CanBeHosted="false"
runat="server" />
  </VbTemplate>
 <VjsTemplate>
<Acme:SourceRef
ViewSource="~/howto/samples/Xml/XmlSchemaObjectModel/XmlSchemaObjectModel.src"
RunSample=""
Icon="../../../images/genicon.gif"
Caption="J# XmlSchemaObjectModel.exe"
SamplePath="howto\samples\Xml\XmlSchemaObjectModel\"
CanBeHosted="false"
runat="server" />
 </VjsTemplate>
 <CpTemplate>
       <Acme:SourceRef
        RunSample=""
        ViewSource=""
        Icon = ""
        Caption=""
        runat="server" />
  </CpTemplate>
</Acme:LangSwitch>

<p>
This sample first creates an XmlWriter that eventually writes out to the screen. The sample does this to take advantage of the various methods of the XmlWriter that produce well-formed XML. Some examples of these methods are the WriteStartElement, WriteEndElement, and WriteAttributeString. Then, the sample creates an XmlNameTable and adds the name table to the XmlSchemaSet. The sample adds two unique XML Schemas into the XmlSchemaSet and compiles the schemas. Finally, the sample writes each schema in the XmlSchemaSet to the screen.
<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
XmlWriterSettings settings = new XmlWriterSettings();
settings.Indent = true;
settings.ConformanceLevel = ConformanceLevel.Fragment;
writer = XmlWriter.Create(Console.Out, settings);
...
XmlNameTable xmlNameTable = new NameTable();
XmlSchemaSet xmlSchemaSet = new XmlSchemaSet(xmlNameTable);
xmlSchemaSet.Add(null, sampleSchema1);
xmlSchemaSet.Add(null, sampleSchema2);
xmlSchemaSet.Compile(); 
...
foreach (XmlSchema tempXmlSchema in xmlSchemaSet.Schemas())
{
    // Write out the various schema parts
    WriteXSDSchema();
}
</Tab>
<Tab Name="VB">
Dim settings As New XmlWriterSettings()
settings.Indent = True
settings.ConformanceLevel = ConformanceLevel.Fragment
writer = XmlWriter.Create(Console.Out, settings)
...
Dim xmlNameTable As NameTable = New NameTable()
Dim xmlSchemaSet As New XmlSchemaSet(xmlNameTable)
xmlSchemaSet.Add(Nothing, sampleSchema1)
xmlSchemaSet.Add(Nothing, sampleSchema2)
xmlSchemaSet.Compile()
...
Dim tempXmlSchema As XmlSchema
For Each tempXmlSchema In xmlSchemaSet.Schemas()
    ' Write out the various schema parts
    WriteXSDSchema()
Next tempXmlSchema
</Tab>
<Tab Name="J#">
XmlWriterSettings settings = new XmlWriterSettings();
settings.set_Indent(true);
settings.set_ConformanceLevel(ConformanceLevel.Fragment);
//Create XmlWriter
xmlWriter = XmlWriter.Create(Console.get_Out(), settings);
...
XmlNameTable xmlNameTable = new NameTable();
//Add the nametable to the XmlSchemaSet
XmlSchemaSet xmlSchemaSet = new XmlSchemaSet(xmlNameTable);
//Add some schemas to the XmlSchemaSet
Console.WriteLine("Reading and adding {0} schema.", args[0]);
xmlSchemaSet.Add(null, args[0]);
Console.WriteLine("Reading and adding {0} schema.", args[1]);
xmlSchemaSet.Add(null, args[1]);
Console.WriteLine("Added schemas successfully ...");
xmlSchemaSet.Compile();
...
while (myEnumerator.MoveNext()) {
    WriteXSDSchema();
}
</Tab>
</Acme:TabControl>
<p>
The WriteXSDSchema function loops through each item in the XmlSchema and, after determining its type, formats the item for output to the screen.

<H4>Summary</H4>
<OL>
<LI>The Schema Object Model (SOM) loads and saves valid XML Schemas.
<LI>The SOM provides an easy way to create in-memory schemas using strongly typed classes.
<LI>You can use the XmlSchemaSet object to cache and retrieve multiple schemas.
</OL>

<p>

</asp:Content>