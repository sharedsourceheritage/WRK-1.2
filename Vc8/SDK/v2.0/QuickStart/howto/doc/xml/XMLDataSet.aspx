<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4>How Do I...Use XML and the DataSet?</h4>

<p>These topics provide an introduction to the interaction between the DataSet and XMLDataDocument objects.
</p>

<span class="subhead">XML and Relational Data. Same Data, Two Views.</span>
<p>
XML often has a relational structure, such as the fictional books in a bookstore, as well as being unstructured. This set of topics covers the concept of storing this data centrally and providing different views of this data, either as XML or relationally as tables, columns, and rows with relationships. This disconnected store of data which, for example, could represent a business object in the middle tier that enforces business rules, could provide its data as XML to a browser via Extensible Stylesheet Language Transformations (XSLT), across the Internet to another Web site, or to a local application via the relational tables. However the data gets amended, you can update that data to a database on a transaction basis.
<p>
A DataSet represents an in-memory cache of data as a collection of tables and relationships between those tables. It is a locally cached database. This provides a disconnected cache of data, like a message, that enables dealing with chunks of data. The DataSet has no knowledge of where the data came from. It may have come from a file, a database connection, or from a stream. A DataSet provides a relational view onto this stored data.
<p>
The XmlDataDocument provides XML APIs for accessing this in-memory cache of data, as well as supporting reading and writing XML. The XmlDataDocument is a DataSet-aware object. Creation of an XmlDataDocument implicitly creates a DataSet, accessed as a property, that provides a relational view onto the data XML data. This symbiotic relationship between these two objects provides a powerful technique for accessing data either relationally or as XML, irrespective of the mechanism by which the data was sourced.

<p>
<span class="subhead">XmlDataDocument and DataSet Differences</span>

<p>
There are differences between these two objects and their views. XML that is loaded via the Load method on the XmlDataDocument maintains full fidelity; all the XML structure is maintained and can be accessed via the XML API. The ReadXml method on the DataSet, however, loads only the XML that conforms to the internally created mappings (schema). You lose white space and element ordering, as well as data that does not conform to the relational mapping. Therefore, the DataSet does not retain XML fidelity. Also, data that has been loaded through an XmlDataDocument and that does not conform to the internal mappings on the DataSet cannot be viewed by using the relational API. Relational data can always be viewed via the XML API.
<p>
Both the DataSet and XmlDataDocument can save data. However, they do not save the data identically. By using the WriteXml method, the DataSet can save a normalized view of the relationally mapped data (the XML data that conforms to the internal schema, with elements ordered according to the relational schema). This contrasts to the Save method of the XmlDataDocument that saves the XML data with full fidelity; this includes all the XML that has been loaded into the XmlDataDocument, including the preservation of white space and element ordering.
<p>

<span class="subhead">Related Topics</span>
<p>
The following topics cover many of the features of the XmlDataDocument object that utilize the XML API. Refer to these topics for information about those scenarios in which you want to access data as XML.
<p>

<p>
For coverage of the interaction between the DataSet and databases using the .NET data providers, see <A target=content href="../adoplus/adoplusoverview.aspx">How do I...Get an Overview of ADO.NET?</A>
<p>







</asp:Content>



