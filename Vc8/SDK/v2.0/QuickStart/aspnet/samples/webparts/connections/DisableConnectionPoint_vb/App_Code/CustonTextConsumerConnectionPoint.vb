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
Imports System
Imports System.Web.UI.WebControls
Imports System.Web.UI.WebControls.WebParts
Imports System.Reflection


Namespace Microsoft.Sample.WebParts
    Public Class CustonTextConsumerConnectionPoint
        Inherits ConsumerConnectionPoint

        Public Sub New(ByVal callbackMethod As MethodInfo, ByVal interfaceType As Type, ByVal controlType As Type, ByVal name As String, ByVal id As String, ByVal allowsMultipleConnections As Boolean)
            MyBase.New(callbackMethod, interfaceType, controlType, name, id, allowsMultipleConnections)

        End Sub 'New

        ' NOTE: A provider connection point can be disable by overriding the GetEnabled(..) method.
        '       A provider connection point can be disable by overriding the SupportsConnection(..) method.
        Public Overrides Function SupportsConnection(ByVal control As System.Web.UI.Control, ByVal secondaryInterfaces As ConnectionInterfaceCollection) As Boolean
            Dim canConnect As Boolean = True
            Dim tp As TextDisplayWebPart
            tp = CType(control, TextDisplayWebPart)

            'ToDo: Error processing original source shown below
            '            bool canConnect = true;
            '            TextDisplayWebPart tp = control as TextDisplayWebPart;
            '---------------------------------------------^--- Syntax error: ';' expected
            If Not (tp Is Nothing) Then
                canConnect = tp.AllowTextConsumerConnection
            End If
            Return canConnect

        End Function 'SupportsConnection 
    End Class 'CustonTextConsumerConnectionPoint
End Namespace
