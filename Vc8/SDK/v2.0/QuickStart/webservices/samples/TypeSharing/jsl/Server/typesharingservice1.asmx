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

<%@ WebService Language="VJ#" Class="TypeSharingService1" %>

import System.*;
import System.Web.Services.*;

public class ProductInvoice
{
   public String orderID;
   public String orderDesc;
   public String product;
   public int productQuant;
   public String shipDate;
}

/** @attribute WebService(Namespace="Microsoft.Samples.XmlMessaging.WebServices") */
public class TypeSharingService1
{
   /** @attribute WebMethod() */
   public ProductInvoice createOrder(String product, int quant)
   {
      ProductInvoice invoice = new ProductInvoice();
      invoice.orderID = "EPPW8970";
      invoice.orderDesc = quant + " " + product;
      invoice.product = product;
      invoice.productQuant = quant;
      invoice.shipDate = "March 1";  //this is the default
      return invoice;
   }
}

