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

public class Formatters

        Public Shared Sub Main()
            Dim mqPath As String = ".\FormattersSample"
            If (Not MessageQueue.Exists(mqPath)) Then
                MessageQueue.Create(mqPath)
            End If

            Dim mq As MessageQueue = New MessageQueue(mqPath)

            Dim order As Order = New Order
            order.OrderId = 102
            order.ItemDescription = "MS Visual Studio 7"

            mq.Formatter = New XmlMessageFormatter
            mq.Send(order)

            mq.Formatter = New BinaryMessageFormatter
            mq.Send(order)

            mq.Formatter = New ActiveXMessageFormatter
            mq.Send(10)
        End Sub

    End Class
End Namespace
