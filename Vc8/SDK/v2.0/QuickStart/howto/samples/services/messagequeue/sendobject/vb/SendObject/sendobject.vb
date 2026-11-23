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
Imports System.Messaging
Namespace Microsoft.Samples

Public Class SendObject

        Public Shared Sub Main()

            Dim mqPath As String = ".\MQSendSample"

            If (Not MessageQueue.Exists(mqPath)) Then
                MessageQueue.Create(mqPath)
            End If

            Dim mq As MessageQueue = New MessageQueue(mqPath)

            Dim customer As Customer = New Customer
            customer.LastName = "Copernicus"
            customer.FirstName = "Nicolaus"
            mq.Send(customer)

        End Sub

    End Class
End Namespace
