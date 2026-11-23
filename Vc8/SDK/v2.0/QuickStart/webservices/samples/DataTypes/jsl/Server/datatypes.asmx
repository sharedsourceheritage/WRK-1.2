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

<%@ WebService Language="VJ#" Class="DataTypes" %>

import System.*;
import System.Web.Services.*;

public class Order
{
   public int OrderID;
   public double Price;
}

/** @attribute WebService(Namespace="Microsoft.Samples.XmlMessaging.WebServices") */
public class DataTypes {

   /** @attribute WebMethod() */
   public String SayHello() 
   {
       return "Hello World!";
   }

   /** @attribute WebMethod() */
   public String SayHelloName(String name) 
   {
       return "Hello " + name + "!";
   }

   /** @attribute WebMethod() */
   public int[] GetIntArray() 
   {
       int[] a = new int[5];
       for (int i=0; i<5; i++)
           a[i] = i*10;
       return a;
   }


   /** @attribute WebMethod() */
   public Order GetOrder() 
   {
      Order myOrder = new Order();

      myOrder.Price=34.5;
      myOrder.OrderID = 323232;

      return myOrder;
   }

   /** @attribute WebMethod() */
   public Order[] GetOrders() 
   {
      Order [] myOrder = new Order[2];

      myOrder[0] = new Order();
      myOrder[0].Price=34.5;
      myOrder[0].OrderID = 323232;
      myOrder[1] = new Order();
      myOrder[1].Price=99.4;
      myOrder[1].OrderID = 645645;

      return myOrder;
   }
}
