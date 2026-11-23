'=====================================================================
'
'  File:    Currency.vb for Adventure Works Cycles SQLCLR Layer Sample
'  Summary: Defines a class for handing particular amounts of money in a 
'           particular culture's monetary system.  This class is exposed as 
'           a SQL Server UDT.
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

Imports System
Imports System.Data.SqlTypes
Imports System.Globalization

''' <summary>
'''		Defines a class for handing particular amounts of money in a 
'''		particular culture's monetary system.  This class is exposed as 
'''		a SQL Server UDT.
''' 
''' 	 
'''		Note that we are implementing IComparable to affect comparison behavior 
'''		only within the CLR.  This does not affect how SQL Server will compare the
'''     the types.  How SQL Server will compare the type is determined by the Write 
'''		method on IBinarySerialize.
''' </summary>
<System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1036:OverrideMethodsOnComparableTypes")> _
<System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Performance", "CA1815:OverrideEqualsAndOperatorEqualsOnValueTypes")> _
<Serializable(), Microsoft.SqlServer.Server.SqlUserDefinedType(Microsoft.SqlServer.Server.Format.UserDefined, IsByteOrdered:=True, MaxByteSize:=32), CLSCompliant(False)> _
               Public Structure Currency
    Implements INullable, IComparable, Microsoft.SqlServer.Server.IBinarySerialize
    Private Const nullMarker As String = vbNullChar & vbNullChar & vbNullChar & vbNullChar & vbNullChar & vbNullChar & vbNullChar & vbNullChar & vbNullChar & vbNullChar
    Private Const cultureNameMaxSize As Integer = 10
    Private cultureName As String ' Who issued the money (en-us, for example)
    Private privCulture As CultureInfo ' The object which represents cultureName
    Private currencyVal As Decimal ' The amount of money

    ' Public properties for private fields
    Public ReadOnly Property Culture() As CultureInfo
        Get
            ' A culture name is required.  If not present the entire object is considered null.
            If cultureName Is Nothing Then
                Return Nothing
            End If

            ' If we've got a cached copy of the culture return it.
            If Not (privCulture Is Nothing) Then
                Return privCulture
            End If

            ' Otherwise, set the cache and return the culture for the culture name specified.
            privCulture = CultureInfo.CreateSpecificCulture(cultureName)

            Return privCulture
        End Get
    End Property

    ' Public property for the private field.
    Public ReadOnly Property CurrencyValue() As Decimal
        Get
            Return currencyVal
        End Get
    End Property

    ' Constructors for when we have the culture or the name of the culture
    Public Sub New(ByVal culture As CultureInfo, ByVal currencyValue As Decimal)
        Me.cultureName = culture.Name
        Me.privCulture = culture
        Me.currencyVal = currencyValue
    End Sub

    Public Sub New(ByVal cultureName As String, ByVal currencyValue As Decimal)
        Me.cultureName = cultureName
        Me.privCulture = Nothing
        Me.currencyVal = currencyValue
    End Sub

    ' Return the string representation for the currency, including the currency symbol.
    <Microsoft.SqlServer.Server.SqlMethod(IsDeterministic:=True, IsPrecise:=True, DataAccess:=Microsoft.SqlServer.Server.DataAccessKind.None, SystemDataAccess:=Microsoft.SqlServer.Server.SystemDataAccessKind.None)> _
    Public Overrides Function ToString() As String
        If Me.Culture Is Nothing Then
            Return "null"
        End If

        Return String.Format(Me.Culture, "{0:c}", currencyVal)
    End Function

    ' The entire value of the currency is considered null if the culture name is null
    Public ReadOnly Property IsNull() As Boolean Implements INullable.IsNull
        Get
            Return cultureName Is Nothing
        End Get
    End Property

    ' The no-argument constructor makes a null currency.
    Public Shared ReadOnly Property Null() As Currency
        Get
            Return New Currency(CStr(Nothing), 0)
        End Get
    End Property

    ' Be sure to set the current UI culture before using this method! Even better, provide the culture
    ' specifically (for the method after this one).
    <Microsoft.SqlServer.Server.SqlMethod(IsDeterministic:=True, IsPrecise:=True, DataAccess:=Microsoft.SqlServer.Server.DataAccessKind.None, SystemDataAccess:=Microsoft.SqlServer.Server.SystemDataAccessKind.None)> _
    Public Shared Function Parse(ByVal sqlString As SqlString) As Currency
        Return ParseWithCulture(sqlString, CultureInfo.CurrentUICulture)
    End Function

    Public Shared Function ParseWithCulture(ByVal sqlString As SqlString, ByVal culture As CultureInfo) As Currency
        If sqlString.IsNull _
            OrElse sqlString.Value.ToLower(CultureInfo.CurrentUICulture) = "null" Then
            Return Currency.Null
        End If

        Dim digitPos As Integer = 0
        Dim stringValue As String = sqlString.Value

        While digitPos < stringValue.Length _
            AndAlso Not Char.IsDigit(stringValue, digitPos) ' TODO: ++ operator not supported within expressions
            digitPos = digitPos + 1
        End While

        If digitPos < stringValue.Length Then
            Return New Currency(culture, _
                Decimal.Parse(stringValue.Substring(digitPos), culture))
        End If

        Return Currency.Null
    End Function

    Public Overrides Function GetHashCode() As Integer
        If Me.IsNull Then
            Return 0
        End If

        Return Me.ToString().GetHashCode()
    End Function
    '' Note: This only affects the behavior of CLR, not SQL Server.  Comparions
    '' for SQL Server will be determined by the Write method below.

    Public Function CompareTo(ByVal obj As Object) As Integer Implements IComparable.CompareTo
        If obj Is Nothing Then
            Return 1 ' by definition
        End If

        If TypeOf (obj) Is Currency Then
            Throw New ArgumentException("the argument to compare is not a Currency")
        End If

        Dim c As Currency = CType(obj, Currency)

        If Me.IsNull Then
            If c.IsNull Then
                Return 0
            End If
            Return -1
        End If

        If c.IsNull Then
            Return 1
        End If

        Return Me.ToString().CompareTo(c.ToString())
    End Function

    ' IBinarySerialize methods
    ' The binary layout is as follow:
    '    Bytes 0 - 19:	Culture name, padded to the right with null characters, UTF-16 encoded
    '    Bytes 20+:	Decimal value of money
    ' If the culture name is empty, the currency is null.
    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2201:DoNotRaiseReservedExceptionTypes")> _
    Public Sub Write(ByVal w As System.IO.BinaryWriter) Implements Microsoft.SqlServer.Server.IBinarySerialize.Write
        If Me.IsNull Then
            w.Write(nullMarker)
            w.Write(System.Convert.ToDecimal(0))
            Return
        End If

        If cultureName.Length > cultureNameMaxSize Then
            Throw New ApplicationException(String.Format(CultureInfo.CurrentUICulture, _
               "{0} is an invalid culture name for currency as it is too long.", cultureNameMaxSize))
        End If

        Dim paddedName As String = cultureName.PadRight(cultureNameMaxSize, CChar(vbNullChar))

        For i As Integer = 0 To cultureNameMaxSize - 1
            w.Write(paddedName(i))
        Next i

        ' Normalize decimal value to two places
        currencyVal = Decimal.Floor(currencyVal * 100) / 100
        w.Write(currencyVal)
    End Sub

    Public Sub Read(ByVal r As System.IO.BinaryReader) Implements Microsoft.SqlServer.Server.IBinarySerialize.Read
        Dim name As Char() = r.ReadChars(cultureNameMaxSize)
        Dim stringEnd As Integer = Array.IndexOf(name, CChar(vbNullChar))

        If stringEnd = 0 Then
            cultureName = Nothing
            Return
        End If

        cultureName = New String(name, 0, stringEnd)
        currencyVal = r.ReadDecimal()
    End Sub
End Structure




