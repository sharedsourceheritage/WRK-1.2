Imports System
Imports System.Data
Imports System.Data.Sql
Imports System.Data.SqlClient
Imports System.Data.SqlTypes
Imports Microsoft.SqlServer.Server

'=====================================================================
'
'  File:    AWUtilsContactParseException.vb for Adventure Works Cycles SQLCLR Layer Sample
'  Summary: Contains the definition of the parse error exceptions
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
'''		Used to indicate when parsing the xml document for creating a contact is 
'''		not in the proper form.
''' </summary>
<System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1032:ImplementStandardExceptionConstructors")> _
<System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2240:ImplementISerializableCorrectly")> _
<System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1058:TypesShouldNotExtendCertainBaseTypes")> _
<Serializable()> _
Public Class AWUtilsContactParseException
    Inherits ApplicationException
    Private _expected As String = "unknown"

    Private _actual As String = "unknown"

    Public Property Expected() As String
        Get
            Return _expected
        End Get
        Set(ByVal Value As String)
            _expected = Value
        End Set
    End Property

    Public Property Actual() As String
        Get
            Return _actual
        End Get
        Set(ByVal Value As String)
            _actual = Value
        End Set
    End Property

    Public Sub New()
    End Sub

    Public Sub New(ByVal expected As String, ByVal actual As String)
        Me.Expected = expected
        Me.Actual = actual
    End Sub

    Public Overrides Function ToString() As String
        Return String.Format(System.Globalization.CultureInfo.InvariantCulture, _
            "Parsing error during contact creation, expected element {0}, found element {1}.", _
            Me.Expected, Me.Actual)
    End Function
End Class
