Imports System
Imports System.Data
Imports System.Data.Sql
Imports System.Data.SqlClient
Imports System.Data.SqlTypes
Imports System.IO
Imports System.Xml
Imports System.Collections
Imports System.Collections.Generic
Imports System.Globalization
Imports Microsoft.SqlServer.Server

'=====================================================================
'
'  File:    ContactCreator.vb for Adventure Works Cycles SQLCLR Layer Sample
'  Summary: The base class implementation for all contact creation classes
'  Date:    May 25, 2004
'
'---------------------------------------------------------------------
'
'  This file is part of the Microsoft SQL Server Code Samples.
'  Copyright (C) Microsoft Corporation.  All rights reserved.
'
' This source code is intended only as a supplement to Microsoft
' Development Tools and/or on-line documentation.  See these other
' materials for detailed information regarding Microsoft code samples.
'
' THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
' KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
' IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
' PARTICULAR PURPOSE.
'
'======================================================= 

''' <summary>
'''		Base class for all the contact creation classes.  Responsible for parsing the XML,
'''		providing the public API for all types of contacts, and for inserting the row 
'''		in the Person.Contact table.
''' </summary>

Public MustInherit Class ContactCreator

    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1051:DoNotDeclareVisibleInstanceFields")> _
    Protected parameterCount As Integer
    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1051:DoNotDeclareVisibleInstanceFields")> _
    Protected valueCount As Integer
    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1051:DoNotDeclareVisibleInstanceFields")> _
    Protected contactDictionary As New Dictionary(Of String, String)()

    Private Shared ReadOnly xmlColumns() As String = {"AdditionalContactInfo", "Demographics"}
    Private Shared ReadOnly nestedColumns() As String = {"Address"}

    Protected Sub New()
    End Sub

    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1706:ShortAcronymsShouldBeUppercase")> _
    Public Property ContactID() As Integer
        Get
            Dim val As String = String.Empty

            If contactDictionary.TryGetValue("ContactID", val) Then
                Return Integer.Parse(val, CultureInfo.InvariantCulture)
            Else
                Return -1
            End If
        End Get
        Set(ByVal Value As Integer)
            contactDictionary("ContactID") = Value.ToString(CultureInfo.InvariantCulture)
        End Set
    End Property

    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1706:ShortAcronymsShouldBeUppercase")> _
    Public Property CustomerID() As Integer
        Get
            Dim val As String = String.Empty

            If contactDictionary.TryGetValue("CustomerID", val) Then
                Return Integer.Parse(val, CultureInfo.InvariantCulture)
            Else
                ' Not every contact is for a customer.  Return -1 in that case.
                Return -1
            End If
        End Get
        Set(ByVal Value As Integer)
            contactDictionary("CustomerID") _
                = Value.ToString(CultureInfo.InvariantCulture)
        End Set
    End Property

    Public Sub LoadDictionary(ByVal reader As XmlReader)
        While reader.IsStartElement()
            Dim key As String = reader.LocalName
            Dim val As String

            If Array.IndexOf(xmlColumns, key) > -1 Then
                val = reader.ReadInnerXml()
            ElseIf Array.IndexOf(nestedColumns, key) > -1 Then
                reader.ReadStartElement()
                LoadDictionary(reader)
                reader.ReadEndElement()
                GoTo ContinueWhile1
            Else
                val = reader.ReadElementString()
            End If

            contactDictionary.Add(key, val)

ContinueWhile1:
        End While
    End Sub

    Protected Sub ResetCounters(ByVal valueForReset As Integer)
        parameterCount = valueForReset
        valueCount = valueForReset
    End Sub

    Public Function MaybeParameter(ByVal name As String) As String
        If contactDictionary.ContainsKey(name) Then
            parameterCount = parameterCount + 1
            If parameterCount = 1 Then
                Return name
            Else
                Return ", " & name
            End If
        Else
            Return String.Empty
        End If
    End Function

    Public Function MaybeValue(ByVal name As String) As String
        If contactDictionary.ContainsKey(name) Then
            valueCount = valueCount + 1
            If valueCount = 1 Then
                Return "@" & name
            Else
                Return ", @" & name
            End If
        Else
            Return String.Empty
        End If
    End Function

    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Maintainability", "CA1502:AvoidExcessiveComplexity")> _
    Public Shared Function TypeConvert(ByVal valueToConvert As String, ByVal parameterType As SqlDbType) As Object
        Select Case parameterType
            Case SqlDbType.BigInt
                Return Int64.Parse(valueToConvert, CultureInfo.InvariantCulture)

            Case SqlDbType.Int
                Return Integer.Parse(valueToConvert, CultureInfo.InvariantCulture)

            Case SqlDbType.SmallInt
                Return Int16.Parse(valueToConvert, CultureInfo.InvariantCulture)

            Case SqlDbType.TinyInt
                Return Byte.Parse(valueToConvert, CultureInfo.InvariantCulture)

            Case SqlDbType.Bit
                If valueToConvert.Equals("1") OrElse valueToConvert.Equals("true") Then
                    Return 1
                Else
                    Return 0
                End If

            Case SqlDbType.NVarChar, SqlDbType.VarChar, SqlDbType.NChar, SqlDbType.NText, SqlDbType.Text, SqlDbType.Char, SqlDbType.Xml
                Return valueToConvert

            Case SqlDbType.DateTime
                Return DateTime.Parse(valueToConvert, CultureInfo.InvariantCulture)

            Case SqlDbType.Money
                Return Decimal.Parse(valueToConvert, CultureInfo.InvariantCulture)

            Case Else
                Return "unknown conversion"
        End Select
    End Function

    Public Overloads Sub MaybeAddCommandParameter(ByVal keyName As String, ByVal paramName As String, ByVal command As SqlCommand, ByVal parameterType As SqlDbType, ByVal isRequired As Boolean, ByVal defaultValue As String)
        If isRequired OrElse contactDictionary.ContainsKey(keyName) Then
            Dim param As New SqlParameter("@" & paramName, parameterType)
            Dim val As String

            If (contactDictionary.ContainsKey(keyName)) Then
                val = contactDictionary(keyName)
            Else
                val = defaultValue
            End If

            param.Value = TypeConvert(val, parameterType)
            command.Parameters.Add(param)
        End If
    End Sub

    Public Overloads Sub MaybeAddCommandParameter(ByVal name As String, ByVal command As SqlCommand, ByVal parameterType As SqlDbType, ByVal isRequired As Boolean, ByVal defaultValue As String)
        MaybeAddCommandParameter(name, name, command, parameterType, isRequired, defaultValue)
    End Sub

    Public Overloads Sub MaybeAddCommandParameter(ByVal name As String, ByVal command As SqlCommand, ByVal parameterType As SqlDbType, ByVal size As Integer, ByVal isRequired As Boolean, ByVal defaultValue As String)
        If isRequired OrElse contactDictionary.ContainsKey(name) Then
            MaybeAddCommandParameter(name, command, parameterType, isRequired, defaultValue)
            command.Parameters(command.Parameters.Count - 1).Size = size
        End If
    End Sub

    Public Overloads Sub MaybeAddCommandParameter(ByVal keyName As String, ByVal paramName As String, ByVal command As SqlCommand, ByVal parameterType As SqlDbType, ByVal size As Integer, ByVal isRequired As Boolean, ByVal defaultValue As String)
        If isRequired OrElse contactDictionary.ContainsKey(keyName) Then
            MaybeAddCommandParameter(keyName, paramName, command, parameterType, isRequired, defaultValue)
            command.Parameters(command.Parameters.Count - 1).Size = size
        End If
    End Sub

    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Performance", "CA1804:RemoveUnusedLocals")> _
    Public Overridable Sub Create()
        Using conn As New SqlConnection("context connection=true")

            Dim command As SqlCommand = conn.CreateCommand()

            ResetCounters(1)

            Dim parameters As String = String.Format( _
                System.Globalization.CultureInfo.InvariantCulture, _
                "NameStyle{0}, FirstName{1}, LastName{2}{3}{4}{5}, PasswordHash, PasswordSalt{6}", _
                MaybeParameter("Title"), MaybeParameter("MiddleName"), _
                MaybeParameter("Suffix"), MaybeParameter("EmailAddress"), _
                MaybeParameter("EmailPromotion"), MaybeParameter("Phone"), _
                MaybeParameter("AdditionalContactInfo"))
            Dim values As String = String.Format( _
                System.Globalization.CultureInfo.InvariantCulture, _
                "@NameStyle{0}, @FirstName{1}, @LastName{2}{3}{4}{5}, @PasswordHash, @PasswordSalt{6}", _
                MaybeValue("Title"), MaybeValue("MiddleName"), MaybeValue("Suffix"), _
                MaybeValue("EmailAddress"), MaybeValue("EmailPromotion"), _
                MaybeValue("Phone"), MaybeValue("AdditionalContactInfo"))

            Dim formatText As String = String.Format( _
                System.Globalization.CultureInfo.InvariantCulture, _
                "INSERT INTO Person.Contact ({0}) VALUES ({1}); SELECT CAST(SCOPE_IDENTITY() AS Int);", _
                parameters, values)

            command.CommandText = String.Format( _
                System.Globalization.CultureInfo.InvariantCulture, _
                formatText)
            MaybeAddCommandParameter("NameStyle", command, SqlDbType.Bit, True, "0")
            MaybeAddCommandParameter("Title", command, SqlDbType.NVarChar, 8, False, Nothing)
            MaybeAddCommandParameter("FirstName", command, SqlDbType.NVarChar, 50, True, String.Empty)
            MaybeAddCommandParameter("MiddleName", command, SqlDbType.NVarChar, 50, False, Nothing)
            MaybeAddCommandParameter("LastName", command, SqlDbType.NVarChar, 50, True, String.Empty)
            MaybeAddCommandParameter("Suffix", command, SqlDbType.NVarChar, 10, False, Nothing)
            MaybeAddCommandParameter("EmailAddress", command, SqlDbType.NVarChar, 50, True, String.Empty)
            MaybeAddCommandParameter("EmailPromotion", command, SqlDbType.Int, False, Nothing)
            MaybeAddCommandParameter("Phone", command, SqlDbType.NVarChar, 25, False, Nothing)
            MaybeAddCommandParameter("PasswordHash", command, SqlDbType.VarChar, 40, True, String.Empty)
            MaybeAddCommandParameter("PasswordSalt", command, SqlDbType.VarChar, 10, True, String.Empty)
            MaybeAddCommandParameter("AdditionalContactInfo", command, SqlDbType.Xml, False, Nothing)
            conn.Open()
            Me.ContactID = CType(command.ExecuteScalar(), Integer)
            Dim st As New StackTrace(True)
        End Using
    End Sub
End Class
