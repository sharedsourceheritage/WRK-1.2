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
Imports System.Xml.Serialization

<System.SerializableAttribute()>  _
<System.Xml.Serialization.XmlTypeAttribute(Namespace:="Microsoft.Samples.Web.Services")> _
Public Class Book
    
    Private authorField As String
    Private titleField As String
    
    Public Property Author() As String
        Get
            Return Me.authorField
        End Get
        Set
            Me.authorField = value
        End Set
    End Property
    
    Public Property Title() As String
        Get
            Return Me.titleField
        End Get
        Set
            Me.titleField = value
        End Set
    End Property

End Class
