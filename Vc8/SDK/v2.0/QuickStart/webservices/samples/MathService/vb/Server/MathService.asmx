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

<%@ WebService Language="VB" Class="VBService.MathService" %>

Imports System
Imports System.Web.Services

Namespace VBService

    <WebService(Namespace:="Microsoft.Samples.XmlMessaging.WebServices")> _
    Public Class MathService

        <WebMethod()> Public Function Add(ByVal a As System.Single, ByVal b As System.Single) As System.Single

            Return a + b
        End Function

        <WebMethod()> Public Function Subtract(ByVal a As System.Single, ByVal b As System.Single) As System.Single

            Return a - b
        End Function

        <WebMethod()> Public Function Multiply(ByVal a As System.Single, ByVal b As System.Single) As System.Single

            Return a * b
        End Function

        <WebMethod()> Public Function Divide(ByVal a As System.Single, ByVal b As System.Single) As System.Single

            If b = 0 Then
                Return -1
            End If
            Return Convert.ToSingle(a / b)
        End Function

    End Class
    
End Namespace