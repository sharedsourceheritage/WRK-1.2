'=====================================================================
'
'  File:    UTF8String.cs for UTF8 SQLCLR Example
'  Summary: Defines a SQLCLR based UserDefinedType for storing UTF8 encoded strings.
'  Date:    May 25, 2004
'
'---------------------------------------------------------------------
'  This file is part of the Microsoft SQL Server Code Samples.
'  Copyright (C) Microsoft Corporation.  All rights reserved.
'
'  This source code is intended only as a supplement to Microsoft
'  Development Tools and/or on-line documentation.  See these other
'  materials for detailed information regarding Microsoft code samples.
'
'  THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
'  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
'  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
'  PARTICULAR PURPOSE.
'======================================================= 

<Assembly: System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1020:AvoidNamespacesWithFewTypes", Scope:="namespace", Target:="Microsoft.Samples.SqlServer")> 

<Serializable(), Microsoft.SqlServer.Server.SqlUserDefinedType(Microsoft.SqlServer.Server.Format.UserDefined, IsByteOrdered:=True, MaxByteSize:=8000), CLSCompliant(False)> _
Public Class Utf8String
    Implements INullable, IComparable, Microsoft.SqlServer.Server.IBinarySerialize
#Region "Conversion to/from Unicode strings"
    ''' <summary>
    ''' Parse the given string and return a utf8 representation for it.
    ''' </summary>
    ''' <param name="sqlString"></param>
    ''' <returns></returns>
    Public Shared Function Parse(ByVal sqlString As SqlString) As Utf8String
        If sqlString.IsNull Then
            Return Utf8String.Null
        End If

        Return New Utf8String(sqlString.Value)
    End Function

    ''' <summary>
    ''' Get/Set the utf8 bytes for this string.
    ''' </summary>
    Public Property Utf8Bytes() As SqlBinary
        Get
            If Me.IsNull Then
                Return SqlBinary.Null
            End If

            If Not (Me.privBytes Is Nothing) Then
                Return Me.privBytes
            End If

            If Not (Me.privString Is Nothing) Then
                Me.privBytes = System.Text.Encoding.UTF8.GetBytes(Me.privString)
                Return New SqlBinary(Me.privBytes)
            End If

            Throw New NotSupportedException("Cannot return bytes for empty instance")
        End Get
        Set(ByVal value As SqlBinary)
            If value.IsNull Then
                Me.privBytes = Nothing
                Me.privString = Nothing
            Else
                Me.privBytes = value.Value
                Me.privString = Nothing
            End If
        End Set
    End Property

    ''' <summary>
    ''' Return a unicode string for this type.
    ''' </summary>
    <Microsoft.SqlServer.Server.SqlMethod(IsDeterministic:=True, IsPrecise:=True, DataAccess:=Microsoft.SqlServer.Server.DataAccessKind.None, SystemDataAccess:=Microsoft.SqlServer.Server.SystemDataAccessKind.None)> _
    Public Overrides Function ToString() As String
        If Me.IsNull Then
            Return Nothing
        End If

        If Not (Me.privString Is Nothing) Then
            Return Me.privString
        End If

        If Not (Me.privBytes Is Nothing) Then
            Me.privString = System.Text.Encoding.UTF8.GetString(Me.privBytes)
            Return Me.privString
        End If

        Throw New NotSupportedException("dont know how to return string from empty instance")
    End Function

    ''' <summary>
    ''' Return a SqlStr
    ''' </summary>
    Public Function ToSqlString() As SqlString
        If Me.IsNull Then
            Return SqlString.Null
        End If

        Return New SqlString(Me.ToString())
    End Function

    Private Function GetSortKeyUsingCultureInternal(ByVal culture As CultureInfo, ByVal ignoreCase As Boolean, _
    ByVal ignoreNonSpace As Boolean, ByVal ignoreWidth As Boolean) As SqlString
        If Me.IsNull Then
            Return SqlString.Null
        End If
        Dim compareOptions As SqlCompareOptions = SqlCompareOptions.None
        If ignoreCase Then
            compareOptions = compareOptions Or SqlCompareOptions.IgnoreCase
        End If
        If ignoreNonSpace Then
            compareOptions = compareOptions Or SqlCompareOptions.IgnoreNonSpace
        End If
        If ignoreWidth Then
            compareOptions = compareOptions Or SqlCompareOptions.IgnoreWidth
        End If
        Return New SqlString(Me.ToString(), culture.LCID, compareOptions)
    End Function

    <Microsoft.SqlServer.Server.SqlMethod(IsDeterministic:=True, IsPrecise:=True)> _
    Public Function GetSortKeyUsingCulture(ByVal cultureName As String, ByVal ignoreCase As Boolean, _
    ByVal ignoreNonSpace As Boolean, ByVal ignoreWidth As Boolean) As SqlString
        Dim culture As CultureInfo = CultureInfo.CreateSpecificCulture(cultureName)
        If culture Is Nothing Then
            Throw New ArgumentException(String.Format(CultureInfo.InvariantCulture, _
            "Culture {0} not recognized.", cultureName))
        End If

        Return Me.GetSortKeyUsingCultureInternal(culture, ignoreCase, ignoreNonSpace, ignoreWidth)
    End Function

    <Microsoft.SqlServer.Server.SqlMethod(IsDeterministic:=True, IsPrecise:=True)> _
    Public Function GetSortKey(ByVal ignoreCase As Boolean, ByVal ignoreNonSpace As Boolean, _
    ByVal ignoreWidth As Boolean) As SqlString
        Return Me.GetSortKeyUsingCultureInternal(CultureInfo.CurrentCulture, ignoreCase, ignoreNonSpace, ignoreWidth)
    End Function

#End Region

#Region "Comparison operators"
    Public Overrides Function Equals(ByVal obj As Object) As Boolean
        Return Me.CompareTo(obj) = 0
    End Function

    Public Shared Operator =(ByVal utf8StringValue As Utf8String, ByVal other As Utf8String) As Boolean
        Return utf8StringValue.Equals(other)
    End Operator

    Public Shared Operator <>(ByVal utf8StringValue As Utf8String, ByVal other As Utf8String) As Boolean
        Return Not (utf8StringValue = other)
    End Operator

    Public Shared Operator <(ByVal utf8StringValue As Utf8String, ByVal other As Utf8String) As Boolean
        Return (utf8StringValue.CompareTo(other) < 0)
    End Operator

    Public Shared Operator >(ByVal utf8StringValue As Utf8String, ByVal other As Utf8String) As Boolean
        Return (utf8StringValue.CompareTo(other) > 0)
    End Operator

    Private Function CompareUsingCultureInternal(ByVal other As Utf8String, ByVal culture As CultureInfo, _
        ByVal ignoreCase As Boolean, ByVal ignoreNonSpace As Boolean, _
        ByVal ignoreWidth As Boolean) As Integer
        'By definition
        If other Is Nothing Then
            Return 1
        End If

        If Me.IsNull Then
            If other.IsNull Then
                Return 0
            Else
                Return -1
            End If
        End If

        If other.IsNull Then
            Return 1
        End If

        Return Me.GetSortKeyUsingCultureInternal(culture, ignoreCase, ignoreNonSpace, _
        ignoreWidth).CompareTo(other.GetSortKeyUsingCultureInternal(culture, ignoreCase, _
        ignoreNonSpace, ignoreWidth))
    End Function

    Public Function CompareUsingCulture(ByVal other As Utf8String, ByVal cultureName As String, _
        ByVal ignoreCase As Boolean, ByVal ignoreNonSpace As Boolean, _
        ByVal ignoreWidth As Boolean) As Integer
        Dim culture As CultureInfo = CultureInfo.CreateSpecificCulture(cultureName)
        If culture Is Nothing Then
            Throw New ArgumentException(String.Format(CultureInfo.InvariantCulture, _
            "Culture {0} not recognized.", cultureName))
        End If

        Return Me.CompareUsingCultureInternal(other, culture, ignoreCase, _
        ignoreNonSpace, ignoreWidth)
    End Function

    Public Function Compare(ByVal other As Utf8String, ByVal ignoreCase As Boolean, ByVal ignoreNonSpace As Boolean, _
        ByVal ignoreWidth As Boolean) As Integer
        Return Me.CompareUsingCultureInternal(other, CultureInfo.CurrentCulture, ignoreCase, _
        ignoreNonSpace, ignoreWidth)
    End Function

    Public Overrides Function GetHashCode() As Integer
        If Me.IsNull Then
            Return 0
        End If

        Return Me.ToString().GetHashCode()
    End Function

    Public Function CompareTo(ByVal obj As Object) As Integer Implements IComparable.CompareTo
        If obj Is Nothing Then
            Return 1 'by definition
        End If

        Dim s As Utf8String = CType(obj, Utf8String)

        If s Is Nothing Then
            Throw New ArgumentException("the argument to compare is not a Utf8String")
        End If

        If Me.IsNull Then
            If s.IsNull Then
                Return 0
            End If
            Return -1
        End If

        If s.IsNull Then
            Return 1
        End If

        Return Me.ToString().CompareTo(s.ToString())
    End Function
#End Region

#Region "Private state and constructors"
    Private privString As String
    Private privBytes() As Byte

    Public Sub New(ByVal value As String)
        Me.privString = value
        'Me.privBytes = Nothing
    End Sub

    Public Sub New(ByVal bytes() As Byte)
        Me.privBytes = bytes
        'Me.privString = Nothing
    End Sub
#End Region

#Region "UserDefinedType boilerplate code"
    Public ReadOnly Property IsNull() As Boolean Implements INullable.IsNull
        Get
            Return Me.privString Is Nothing AndAlso Me.privBytes Is Nothing
        End Get
    End Property

    Public Shared ReadOnly Property Null() As Utf8String
        Get
            Dim str As New Utf8String(CStr(Nothing))

            Return str
        End Get
    End Property

    Public Sub New()
    End Sub
#End Region

#Region "IBinarySerialize Members"
    Public Sub Write(ByVal w As System.IO.BinaryWriter) Implements Microsoft.SqlServer.Server.IBinarySerialize.Write
        Dim header As Byte
        If (Me.IsNull) Then
            header = 1
        Else
            header = 0
        End If

        w.Write(header)

        If header = 1 Then
            Return
        End If

        Dim bytes As Byte() = Me.Utf8Bytes.Value

        w.Write(bytes.Length)
        w.Write(bytes)
    End Sub

    Public Sub Read(ByVal r As System.IO.BinaryReader) Implements Microsoft.SqlServer.Server.IBinarySerialize.Read
        Dim header As Byte = r.ReadByte()

        If (header And 1) > 0 Then
            Me.privBytes = Nothing
            Return
        End If

        Dim length As Integer = r.ReadInt32()

        Me.privBytes = r.ReadBytes(length)
    End Sub
#End Region
End Class
