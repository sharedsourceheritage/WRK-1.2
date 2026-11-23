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
     Public Class Customer
        Protected last As String
        Protected first As String

        Public Property LastName() As String
            Get
                Return Me.last
            End Get
            Set(ByVal Value As String)
                Me.last = value
            End Set
        End Property

        Public Property FirstName() As String
            Get
                Return Me.first
            End Get
            Set(ByVal Value As String)
                Me.first = value
            End Set
        End Property

        Public ReadOnly Property FullName() As String
            Get
                Return (FirstName + LastName)
            End Get
        End Property
    End Class
End Namespace
