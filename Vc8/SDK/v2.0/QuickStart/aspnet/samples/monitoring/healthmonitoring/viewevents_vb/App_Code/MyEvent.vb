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
Imports System.Web.Management

Namespace Microsoft.Samples.WebEvents

    Public Class MyEvent : Inherits WebBaseEvent

        Public Const EventCode As Integer = WebEventCodes.WebExtendedBase + 10

        Public Sub New(ByVal message As String, ByVal eventSource As Object)

            MyBase.New(message, eventSource, EventCode)
        End Sub
    End Class
End Namespace