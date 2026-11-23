 '-----------------------------------------------------------------------
'  This file is part of the Microsoft .NET SDK Code Samples.
' 
'  Copyright (C) Microsoft Corporation.  All rights reserved.
' 
'This source code is intended only as a supplement to Microsoft
'Development Tools and/or on-line documentation.  See these other
'materials for detailed information regarding Microsoft code samples.
' 
'THIS CODE AND INFORMATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY
'KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
'IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
'PARTICULAR PURPOSE.
'-----------------------------------------------------------------------

Imports System
Imports System.Xml
Imports System.Xml.Schema

Public Class XmlSchemaObjectModelSample
    Shared writer As XmlWriter = Nothing
    Shared xmlSchema As XmlSchema = Nothing

    Public Shared Sub Main()
        Dim random As New Random()

        'Schemas to read
        Dim sampleSchema1 As String = "..\books.xsd"
        Dim sampleSchema2 As String = "..\poschema.xsd"

        Console.WriteLine("Creating Schema in the Schema Object Model...")

        'Set writer properties with XmlWriterSettings
        Dim settings As New XmlWriterSettings()
        settings.Indent = True
        settings.ConformanceLevel = ConformanceLevel.Fragment

        'Create XmlWriter
        writer = XmlWriter.Create(Console.Out, settings)
        Using writer
            'Create an XmlNameTable
            Dim xmlNameTable As NameTable = New NameTable()
            'Add the nametable to the XmlSchemaCollection
            Dim xmlSchemaSet As New XmlSchemaSet(xmlNameTable)
            'Add some schemas to the XmlSchemaCollection
            Console.WriteLine("Reading and adding {0} schema.", sampleSchema1)
            xmlSchemaSet.Add(Nothing, sampleSchema1)
            Console.WriteLine("Reading and adding {0} schema.", sampleSchema2)
            xmlSchemaSet.Add(Nothing, sampleSchema2)
            Console.WriteLine("Added schemas successfully ...")
            xmlSchemaSet.Compile()

            Console.WriteLine("Showing added schemas")

            Dim tempXmlSchema As XmlSchema
            For Each tempXmlSchema In xmlSchemaSet.Schemas()
                xmlSchema = tempXmlSchema
                Console.WriteLine()
                Console.WriteLine("Schema from: {0}", tempXmlSchema.SourceUri)
                Console.WriteLine()
                Console.WriteLine("=== Start of Schema ===")
                Console.WriteLine()

                ' Write out the various schema parts
                WriteXSDSchema()

                Console.WriteLine()
                Console.WriteLine()
                Console.WriteLine("=== End of Schema ===")
                Console.WriteLine()
            Next tempXmlSchema
        End Using
        
        Console.WriteLine()
        Console.WriteLine("Press Enter to Exit")
        Console.ReadLine()
    End Sub

    Shared Sub WriteXSDSchema()
        writer.WriteStartElement("schema", xmlSchema.Namespace)
        writer.WriteAttributeString("targetNamespace", xmlSchema.TargetNamespace)
        Dim include As XmlSchemaInclude
        For Each include In xmlSchema.Includes
            writer.WriteStartElement("include", xmlSchema.Namespace)
            writer.WriteAttributeString("schemaLocation", include.SchemaLocation)
            writer.WriteEndElement()
        Next include

        Dim item As Object
        For Each item In xmlSchema.Items
            If TypeOf item Is XmlSchemaAttribute Then
                WriteXmlSchemaAttribute(CType(item, XmlSchemaAttribute)) 'attribute
            ElseIf TypeOf item Is XmlSchemaComplexType Then
                WriteXmlSchemaComplexType(CType(item, XmlSchemaComplexType)) 'complexType
            ElseIf TypeOf item Is XmlSchemaSimpleType Then
                WriteXmlSchemaSimpleType(CType(item, XmlSchemaSimpleType)) 'simpleType
            ElseIf TypeOf item Is XmlSchemaElement Then
                WriteXmlSchemaElement(CType(item, XmlSchemaElement)) 'element
            ElseIf TypeOf item Is XmlSchemaAnnotation Then
                WriteXmlSchemaAnnotation(CType(item, XmlSchemaAnnotation)) 'annotation
            ElseIf TypeOf item Is XmlSchemaAttributeGroup Then
                WriteXmlSchemaAttributeGroup(CType(item, XmlSchemaAttributeGroup)) 'attributeGroup
            ElseIf TypeOf item Is XmlSchemaNotation Then
                WriteXmlSchemaNotation(CType(item, XmlSchemaNotation)) 'notation
            ElseIf TypeOf item Is XmlSchemaGroup Then
                WriteXmlSchemaGroup(CType(item, XmlSchemaGroup)) 'group
            Else
                Console.WriteLine("Not Implemented.")
            End If
        Next item
        writer.WriteEndElement()

        writer.Flush()

    End Sub

    Shared Sub WriteXmlSchemaAttribute(ByVal attribute As XmlSchemaAttribute)
        writer.WriteStartElement("attribute", xmlSchema.Namespace)
        If Not (attribute.Name Is Nothing) Then
            writer.WriteAttributeString("name", attribute.Name)
        End If
        If Not attribute.RefName.IsEmpty Then
            writer.WriteStartAttribute("ref", Nothing)
            writer.WriteQualifiedName(attribute.RefName.Name, attribute.RefName.Namespace)
            writer.WriteEndAttribute()
        End If

        If Not attribute.SchemaTypeName.IsEmpty Then
            writer.WriteStartAttribute("type", Nothing)
            writer.WriteQualifiedName(attribute.SchemaTypeName.Name, attribute.SchemaTypeName.Namespace)
            writer.WriteEndAttribute()
        End If

        If Not (attribute.SchemaType Is Nothing) Then
            WriteXmlSchemaSimpleType(attribute.SchemaType)
        End If
        writer.WriteEndElement()

    End Sub

    Shared Sub WriteXmlSchemaComplexType(ByVal complexType As XmlSchemaComplexType)
        writer.WriteStartElement("complexType", xmlSchema.Namespace)
        If Not (complexType.Name Is Nothing) Then
            writer.WriteAttributeString("name", complexType.Name)
        End If
        If Not (complexType.ContentModel Is Nothing) Then
            Console.WriteLine("Not Implemented for this ContentModel.")
        Else
            If Not (complexType.Particle Is Nothing) Then
                WriteXmlSchemaParticle(complexType.Particle)
            End If
            Dim o As Object
            For Each o In complexType.Attributes
                If TypeOf o Is XmlSchemaAttribute Then
                    WriteXmlSchemaAttribute(CType(o, XmlSchemaAttribute))
                End If
            Next o
        End If
        writer.WriteEndElement()

    End Sub

    Shared Sub WriteXmlSchemaSimpleType(ByVal simpleType As XmlSchemaSimpleType)
        writer.WriteStartElement("simpleType", xmlSchema.Namespace)
        If Not (simpleType.Name Is Nothing) Then
            writer.WriteAttributeString("name", simpleType.Name)
        End If
        If TypeOf simpleType.Content Is XmlSchemaSimpleTypeRestriction Then
            writer.WriteStartElement("restriction", xmlSchema.Namespace)
        ElseIf TypeOf simpleType.Content Is XmlSchemaSimpleTypeList Then
            writer.WriteStartElement("list", xmlSchema.Namespace)
        Else
            writer.WriteStartElement("union", xmlSchema.Namespace)
        End If
        writer.WriteEndElement()
        writer.WriteEndElement()

    End Sub

    Shared Sub WriteXmlSchemaParticle(ByVal particle As XmlSchemaParticle)
        If TypeOf particle Is XmlSchemaElement Then
            WriteXmlSchemaElement(CType(particle, XmlSchemaElement))
        ElseIf TypeOf particle Is XmlSchemaSequence Then
            writer.WriteStartElement("sequence", xmlSchema.Namespace)
            Dim particle1 As XmlSchemaParticle
            For Each particle1 In CType(particle, XmlSchemaSequence).Items
                WriteXmlSchemaParticle(particle1)
            Next particle1
            writer.WriteEndElement()
        Else
            Console.WriteLine("Not Implemented for this type: {0}", particle.ToString())
        End If

    End Sub

    Shared Sub WriteXmlSchemaElement(ByVal element As XmlSchemaElement)
        writer.WriteStartElement("element", xmlSchema.Namespace)
        If Not (element.Name Is Nothing) Then
            writer.WriteAttributeString("name", element.Name)
        End If
        If Not element.RefName.IsEmpty Then
            writer.WriteStartAttribute("ref", Nothing)
            writer.WriteQualifiedName(element.RefName.Name, element.RefName.Namespace)
            writer.WriteEndAttribute()
        End If

        If Not element.SchemaTypeName.IsEmpty Then
            writer.WriteStartAttribute("type", Nothing)
            writer.WriteQualifiedName(element.SchemaTypeName.Name, element.SchemaTypeName.Namespace)
            writer.WriteEndAttribute()
        End If

        If Not (element.SchemaType Is Nothing) Then
            If TypeOf element.SchemaType Is XmlSchemaComplexType Then
                WriteXmlSchemaComplexType(CType(element.SchemaType, XmlSchemaComplexType))
            Else
                WriteXmlSchemaSimpleType(CType(element.SchemaType, XmlSchemaSimpleType))
            End If
        End If
        writer.WriteEndElement()

    End Sub

    Shared Sub WriteXmlSchemaAnnotation(ByVal annotation As XmlSchemaAnnotation)
        ' Not a complete implementation
        writer.WriteStartElement("annotation", xmlSchema.Namespace)
        writer.WriteEndElement()

    End Sub

    Shared Sub WriteXmlSchemaAttributeGroup(ByVal attributeGroup As XmlSchemaAttributeGroup)
        ' Not a complete implementation
        writer.WriteStartElement("attributeGroup", xmlSchema.Namespace)
        writer.WriteEndElement()

    End Sub

    Shared Sub WriteXmlSchemaGroup(ByVal group As XmlSchemaGroup)
        ' Not a complete implementation
        writer.WriteStartElement("group", xmlSchema.Namespace)
        writer.WriteEndElement()

    End Sub

    Shared Sub WriteXmlSchemaNotation(ByVal notation As XmlSchemaNotation)
        ' Not a complete implementation
        writer.WriteStartElement("notation", xmlSchema.Namespace)
        writer.WriteEndElement()

    End Sub
End Class