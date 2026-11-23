'-----------------------------------------------------------------------
'  This file is part of the Microsoft .NET Framework SDK Code Samples.
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
Namespace Microsoft.Samples

    <CLSCompliant(False)> _
    <Serializable()> Public Class Order
        Protected id As Int64
        Protected description As String

        Public Property OrderId() As Int64
            Get
                Return Me.id
            End Get
            Set(ByVal Value As Int64)
                Me.id = value
            End Set
        End Property

        Public Property ItemDescription() As String
            Get
                Return Me.description
            End Get
            Set(ByVal Value As String)
                Me.description = value
            End Set
        End Property
    End Class
End Namespace
