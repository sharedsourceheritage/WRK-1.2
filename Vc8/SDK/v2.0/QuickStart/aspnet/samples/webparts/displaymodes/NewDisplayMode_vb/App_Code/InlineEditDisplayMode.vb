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
Imports System.Data
Imports System.Configuration
Imports System.Web
Imports System.Web.Security
Imports System.Web.UI
Imports System.Web.UI.WebControls
Imports System.Web.UI.WebControls.WebParts
Imports System.Web.UI.HtmlControls


Namespace Microsoft.Sample.WebParts

    Public Class InlineEditDisplayMode
        Inherits WebPartDisplayMode

        Public Sub New()
            MyBase.New("Inline Edit Display Mode")

        End Sub 'New

        Public Overrides ReadOnly Property AllowPageDesign() As Boolean
            Get
                Return True
            End Get
        End Property

        Public Overrides ReadOnly Property RequiresPersonalization() As Boolean
            Get
                Return True
            End Get
        End Property

        Public Overrides ReadOnly Property ShowHiddenWebParts() As Boolean
            Get
                Return False
            End Get
        End Property

        Public Overrides ReadOnly Property AssociatedWithToolZone() As Boolean
            Get
                Return False
            End Get
        End Property

        Public Overrides Function IsEnabled(ByVal webPartManager As WebPartManager) As Boolean
            Return True

        End Function 'IsEnabled
    End Class 'InlineEditDisplayMode
End Namespace
