<%@ Page Language="C#" MasterPageFile="~/webservices/webservices.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2><b>Web Service That Validates Incoming Messages According to a Schema</b></h2>

<p>To validate messages at the service use the XmlValidatingReader.  The best place
to validate messages is in a SOAP Extension.  This gives you complete control over
the contents of the SOAP message and allows you to reject messages that are not
schema-compliant before the relatively expensive deserialization step.
<p>Note that this sample validates messages in the body of the WebMethod instead.
This is done for simplicity.  The steps to validate the message are the same 
regardless of location.  For more information about validation in SOAP 
extensions, refer to this <a href="http://msdn.microsoft.com/msdnmag/issues/03/07/XMLSchemaValidation/">MSDN article</a>.
</p>
<p>
<Acme:TabControl runat="server">

<Tab Name="C#">
//create the validating reader
XmlTextReader tr = new XmlTextReader(input, XmlNodeType.Document, null);
XmlValidatingReader vr = new XmlValidatingReader(tr);

//add the schema and set the validation type to schema
XmlSchemaCollection schemas = new XmlSchemaCollection();
schemas.Add("Microsoft.Samples.Web.Services", "insert location here...");
vr.Schemas.Add(schemas); 
vr.ValidationType = ValidationType.Schema;

//add our event callback function to the event handler in case there is a validation error
vr.ValidationEventHandler += new ValidationEventHandler (ValidationHandler);

try
{
    //if there is an error we will fall out of this while loop and our callback function will be called
    while (vr.Read())
    {
        //do nothing  
    }
}
catch (Exception exception)
{
    //an exception will be thrown if there are non-validation errors, e.g. in the case of malformed XML
}
</Tab>

<Tab Name="VB">
'create the validating reader
Dim tr As New XmlTextReader(input, XmlNodeType.Document, Nothing)
Dim vr As New XmlValidatingReader(tr)

'add the schema and set the validation type to schema      
Dim schemas As New XmlSchemaCollection()
schemas.Add("Microsoft.Samples.Web.Services", "insert location here...")
vr.Schemas.Add(schemas)
vr.ValidationType = ValidationType.Schema

'add our event callback function to the event handler in case there is a validation error
AddHandler vr.ValidationEventHandler, AddressOf ValidationHandler
      
Try
    'if there is an error we will fall out of this while loop and our callback function will be called
    While vr.Read()
        'do nothing
    End While
Catch exception As Exception
    'an exception will be thrown if there are non-validation errors, e.g. in the case of malformed XML
End Try
</Tab>

<Tab Name="J#">
//create the validating reader
XmlTextReader tr = new XmlTextReader(input, XmlNodeType.Document, null);
XmlValidatingReader vr = new XmlValidatingReader(tr);

//add the schema and set the validation type to schema
XmlSchemaCollection schemas = new XmlSchemaCollection();
schemas.Add("Microsoft.Samples.Web.Services", "insert location here...");
vr.get_Schemas().Add(schemas); 
vr.set_ValidationType(ValidationType.Schema);

//add our event callback function to the event handler in case there is a validation error
vr.add_ValidationEventHandler(new ValidationEventHandler(ValidationHandler));

try
{
    //if there is an error we will fall out of this while loop and our callback function will be called
    while (vr.Read())
    {
        //do nothing  
    }
}
catch (Exception exception)
{
    //an exception will be thrown if there are non-validation errors, e.g. in the case of malformed XML
}
</Tab>

</Acme:TabControl>
</p>
<p>
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../samples/MessageValidation/cs/Client/MessageValidationClient.aspx"
        ViewSource="~/webservices/samples/MessageValidation/MessageValidation.src"
        Icon = "../../images/genicon.gif"
        Caption="Run C# Sample"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../samples/MessageValidation/vb/Client/MessageValidationClient.aspx"
        ViewSource="~/webservices/samples/MessageValidation/MessageValidation.src"
        Icon = "../../images/genicon.gif"
        Caption="Run VB Sample"
        runat="server" />
  </VbTemplate>
  <VJSTemplate>
        <Acme:SourceRef
        RunSample="../samples/MessageValidation/jsl/Client/MessageValidationClient.aspx"
        ViewSource="~/webservices/samples/MessageValidation/MessageValidation.src"
        Icon = "../../images/genicon.gif"
        Caption="Run VJ# Sample"
        runat="server" />
  </VJSTemplate>
</Acme:LangSwitch>
</p>
</asp:Content>

