'=====================================================================
'
'  File:    SimpleType.vb
'  Summary: Simple udt, used to drive the type browser sample
'  Date:    April 06, 2005
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

<System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Performance", "CA1815:OverrideEqualsAndOperatorEqualsOnValueTypes")> _
<Microsoft.SqlServer.Server.SqlUserDefinedTypeAttribute(Microsoft.SqlServer.Server.Format.Native), Serializable()> _
Public Structure SimpleUdt
    Implements INullable
#Region "udt contract"

    Public Overrides Function ToString() As String
        Return Value.ToString()
    End Function

    Public ReadOnly Property IsNull() As Boolean Implements INullable.IsNull
        Get
            Return Me.Value.IsNull
        End Get
    End Property

    Public Shared ReadOnly Property Null() As SimpleUdt
        Get
            Dim h As New SimpleUdt()

            Return h
        End Get
    End Property

    Public Shared Function Parse(ByVal sqlString As SqlString) As SimpleUdt
        If sqlString.IsNull Then
            Return Null
        End If

        Dim simpleUdt As New SimpleUdt()

        simpleUdt.Value = New SqlInt32(Integer.Parse(sqlString.Value, _
            System.Globalization.CultureInfo.InvariantCulture))

        Return simpleUdt
    End Function
#End Region

#Region "implementation"
    Private privValue As SqlInt32

    Private _examplePublicField As SqlInt32

    Public Property ExamplePublicField() As SqlInt32
        Get
            Return Me._examplePublicField
        End Get
        Set(ByVal value As SqlInt32)
            Me._examplePublicField = value
        End Set
    End Property

    Public Property Value() As SqlInt32
        Get
            Return Me.privValue
        End Get
        Set(ByVal value As SqlInt32)
            Me.privValue = value
        End Set
    End Property

    <Microsoft.SqlServer.Server.SqlMethod(IsDeterministic:=True)> _
    Public Function ReturnValue() As SqlInt32
        Return Me.privValue
    End Function
#End Region
End Structure
