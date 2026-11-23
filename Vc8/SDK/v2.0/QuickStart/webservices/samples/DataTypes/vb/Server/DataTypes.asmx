<!--
---------------------------------------------------------------------
  This file is part of the Microsoft .NET Framework SDK Code Samples.
 
  Copyright (C) Microsoft Corporation.  All rights reserved.
 
This source code is intended only as a supplement to Microsoft
Development Tools and/or on-line documentation.  See these other
materials for detailed information regarding Microsoft code samples.
 
THIS CODE AND INFORMATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY
KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.
---------------------------------------------------------------------
-->

<%@ WebService Language="VB" Class="VBService.DataTypes" %>

Imports System
Imports System.Web.Services

Namespace VBService

    Public Enum Mode

        Large = 1
        Small = 2

    End Enum

    Public Class Order

        Public OrderID As Integer
        Public Price As Double
    End Class
    
    <WebService(Namespace:="Microsoft.Samples.XmlMessaging.WebServices")> _
    Public Class DataTypes

        <WebMethod()> Public Function SayHello() As String

            Return "Hello World!"
        End Function

        <WebMethod()> Public Function SayHelloName(ByVal Name As String) As String

            Return "Hello" & Name
        End Function

        <WebMethod()> Public Function GetIntArray() As Integer()

            Dim I As Integer
            Dim A(4) As Integer
            For I = 0 To 4
                A(I) = I * 10
            Next
            Return A
        End Function

        <WebMethod()> Public Function GetMode() As Mode

            Return VBService.Mode.Large

        End Function

        <WebMethod()> Public Function GetOrder() As VBService.Order

            Dim MyOrder As New VBService.Order

            MyOrder.Price = 34.5
            MyOrder.OrderID = 323232

            Return MyOrder
        End Function

        <WebMethod()> Public Function GetOrders() As VBService.Order()

            Dim MyOrder(2) As VBService.Order

            MyOrder(0) = New VBService.Order()
            MyOrder(0).Price = 34.5
            MyOrder(0).OrderID = 323232
            MyOrder(1) = New VBService.Order()
            MyOrder(1).Price = 99.4
            MyOrder(1).OrderID = 645645

            Return MyOrder
        End Function

    End Class

End Namespace