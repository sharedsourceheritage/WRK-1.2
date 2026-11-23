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
Imports Microsoft.VisualBasic
Imports System.Collections
Imports System.Collections.Generic
Imports System.Web.Profile

Public Class UserDefinedProfileClass
    Inherits ProfileBase

    Public Property JunkFood() As List(Of String)
        Get
            Return CType(Me("JunkFood"), List(Of String))
        End Get

        Set(ByVal value As List(Of String))
            Me("JunkFood") = value
        End Set
    End Property

End Class
