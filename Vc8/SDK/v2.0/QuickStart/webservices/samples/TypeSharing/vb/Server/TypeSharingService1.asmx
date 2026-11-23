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

<%@ WebService Language="VB" Class="Microsoft.Samples.XmlMessaging.WebServices.VBTypeSharing1.TypeSharingService1" %>

Imports System
Imports System.Web.Services

Namespace Microsoft.Samples.XmlMessaging.WebServices.VBTypeSharing1

Public Class ProductInvoice
   Public orderID As String
   Public orderDesc As String
   Public product As String
   Public productQuant As Integer
   Public shipDate As String
End Class 'ProductInvoice

<WebService(Namespace:="Microsoft.Samples.XmlMessaging.WebServices")>  _
Public Class TypeSharingService1
   
   <WebMethod>  _
   Public Function createOrder(product As String, quant As Integer) As ProductInvoice
      Dim invoice As New ProductInvoice()
      invoice.orderID = "EPPW8970"
      invoice.orderDesc = quant.ToString() + " " + product
      invoice.product = product
      invoice.productQuant = quant
      invoice.shipDate = "March 1" 'this is the default
      Return invoice
   End Function 'createOrder

End Class 'TypeSharingService1

End Namespace