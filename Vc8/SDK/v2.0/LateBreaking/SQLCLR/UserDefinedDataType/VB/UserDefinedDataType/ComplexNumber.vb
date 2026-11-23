'=====================================================================
'
'  File:    ComplexNumber.vb
'  Summary: A Format.Native UDT that represents a complex number
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

<System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Design", "CA1036:OverrideMethodsOnComparableTypes")> _
<System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Performance", "CA1815:OverrideEqualsAndOperatorEqualsOnValueTypes")> <Serializable(), Microsoft.SqlServer.Server.SqlUserDefinedType(Microsoft.SqlServer.Server.Format.Native, IsByteOrdered:=True)> _
Public Structure ComplexNumber
    Implements INullable, IComparable

    'Regular expression used to parse values that are of the form (1,2i)
    Private Shared ReadOnly parser As New Regex("\A\(\s*(?<real>\-?\d+(\.\d+)?)\s*,\s*(?<img>\-?\d+(\.\d+)?)\s*i\s*\)\Z", RegexOptions.Compiled Or RegexOptions.ExplicitCapture)
    Private realValue As Double
    Private imaginaryValue As Double
    Private isNullValue As Boolean
    Private Const nullValue As String = "<<null complex>>"
    Private Shared ReadOnly NULL_INSTANCE As New ComplexNumber(True)

    Public Sub New(ByVal real As Double, ByVal imaginary As Double)
        Me.realValue = real
        Me.imaginaryValue = imaginary
        Me.isNullValue = False
    End Sub

    Private Sub New(ByVal isnull As Boolean)
        Me.isNullValue = isnull
        Me.realValue = 0
        Me.imaginaryValue = 0
    End Sub

    Public Property Real() As Double
        Get
            If Me.isNullValue Then
                Throw New InvalidOperationException()
            End If
            Return Me.realValue
        End Get
        Set(ByVal Value As Double)
            Me.realValue = Value
        End Set
    End Property

    Public Property Imaginary() As Double
        Get
            If Me.isNullValue Then
                Throw New InvalidOperationException()
            End If
            Return Me.imaginaryValue
        End Get
        Set(ByVal Value As Double)
            Me.imaginaryValue = Value
        End Set
    End Property

    Public ReadOnly Property Modulus() As Double
        Get
            If Me.isNullValue Then
                Throw New InvalidOperationException()
            End If
            Return Math.Sqrt(Me.realValue * Me.realValue + Me.imaginaryValue * Me.imaginaryValue)
        End Get
    End Property

#Region "value-based equality"
    Public Function CompareTo(ByVal obj As Object) As Integer Implements IComparable.CompareTo
        If Not TypeOf obj Is ComplexNumber Then
            Return -1
        End If
        Dim c As ComplexNumber = CType(obj, ComplexNumber)

        If Me.isNullValue AndAlso c.isNullValue Then
            Return 0
        End If

        If Me.isNullValue OrElse c.isNullValue Then
            Return -1
        End If

        If Me.realValue = c.realValue AndAlso Me.imaginaryValue = c.imaginaryValue Then
            Return 0
        End If

        If Modulus = c.Modulus Then ' same modulus but different r/i, force diff
            Return -1
        End If

        ' arbitrary comparison...semantics for complex numbers not necessarily correct
        Return Modulus.CompareTo(c.Modulus)
    End Function

    <System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Usage", "CA2231:OverrideOperatorEqualsOnOverridingValueTypeEquals")> Public Overrides Function Equals(ByVal obj As Object) As Boolean
        Return Me.CompareTo(obj) = 0
    End Function

    Public Overrides Function GetHashCode() As Integer
        Return Modulus.GetHashCode()
    End Function

    Public Overloads Shared Operator =(ByVal c1 As ComplexNumber, ByVal c2 As ComplexNumber) As SqlBoolean
        'TODO: User-defined operator replaced by method.
        'References to operator will need to be replaced by calls to this method
        Return c1.Equals(c2)
    End Operator

    Public Overloads Shared Operator <>(ByVal c1 As ComplexNumber, ByVal c2 As ComplexNumber) As SqlBoolean
        'TODO: User-defined operator replaced by method.
        'References to operator will need to be replaced by calls to this method
        Return Not c1.Equals(c2)
    End Operator

    Public Overloads Shared Function LessThan(ByVal c1 As ComplexNumber, ByVal c2 As ComplexNumber) As SqlBoolean
        'TODO: User-defined operator replaced by method.
        'References to operator will need to be replaced by calls to this method
        Return c1.CompareTo(c2) < 0
    End Function

    Public Overloads Shared Function GreaterThan(ByVal c1 As ComplexNumber, ByVal c2 As ComplexNumber) As SqlBoolean
        'TODO: User-defined operator replaced by method.
        'References to operator will need to be replaced by calls to this method
        Return c1.CompareTo(c2) > 0
    End Function

#End Region

    Public Overrides Function ToString() As String
        If Me.isNullValue = True Then
            Return nullValue
        Else
            Return "(" & Me.realValue.ToString(CultureInfo.InvariantCulture) _
                & "," & Me.imaginaryValue.ToString(CultureInfo.InvariantCulture) _
                & "i)"
        End If
    End Function

    Public ReadOnly Property IsNull() As Boolean Implements INullable.IsNull
        Get
            Return Me.isNullValue
        End Get
    End Property

    Public Shared Function Parse(ByVal sqlString As SqlString) As ComplexNumber
        Dim value As String = sqlString.ToString()

        If sqlString.IsNull Or value = nullValue Then
            Return New ComplexNumber(True)
        End If

        Dim m As Match = parser.Match(value)

        If Not m.Success Then
            Throw New ArgumentException( _
                "Invalid format for complex number. Format is ( n, mi ) where n and m are floating point numbers")
        End If

        Return New ComplexNumber(Double.Parse(m.Groups(1).Value, CultureInfo.InvariantCulture), _
            Double.Parse(m.Groups(2).Value, CultureInfo.InvariantCulture))
    End Function

    Public Shared ReadOnly Property Null() As ComplexNumber
        Get
            Return NULL_INSTANCE
        End Get
    End Property
End Structure
