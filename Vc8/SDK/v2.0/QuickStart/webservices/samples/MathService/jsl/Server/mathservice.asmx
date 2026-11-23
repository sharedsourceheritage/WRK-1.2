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

<%@ WebService Language="VJ#" Class="MathService" %>

import System.*;
import System.Web.Services.*;

/** @attribute WebService(Namespace="Microsoft.Samples.XmlMessaging.WebServices") */
public class MathService {

   /** @attribute WebMethod() */
   public float Add(float a, float b)
   {
       return a + b;
   }

   /** @attribute WebMethod() */
   public float Subtract(float a, float b)
   {
       return a - b;
   }

   /** @attribute WebMethod() */
   public float Multiply(float a, float b)
   {
       return a * b;
   }

   /** @attribute WebMethod() */
   public float Divide(float a, float b)
   {
       if (b==0) return -1;
       return a / b;
   }

}