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
Imports System.Collections.Generic
Imports System.Data
Imports System.Configuration
Imports System.Web
Imports System.Web.Security
Imports System.Web.UI
Imports System.Web.UI.WebControls
Imports System.Web.UI.WebControls.WebParts
Imports System.Web.UI.HtmlControls



Namespace Microsoft.Sample.WebParts
    Public Class NewWebPartManager
        Inherits WebPartManager

        Public Sub New()

        End Sub 'New
        Public Shared InlineEdit As New InlineEditDisplayMode()

        Protected Overrides Function CreateDisplayModes() As WebPartDisplayModeCollection
            Dim displayModes As WebPartDisplayModeCollection = MyBase.CreateDisplayModes()
            displayModes.Add(InlineEdit)
            Return displayModes

        End Function 'CreateDisplayModes
    End Class 'NewWebPartManager
End Namespace
