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

<%@ WebService Language="C#" Class="Microsoft.Samples.WebServices.TypeSharing.CSSamples2.TypeSharingService2" %>

using System;
using System.Web.Services;

namespace Microsoft.Samples.WebServices.TypeSharing.CSSamples2
{

    public class ProductInvoice
    {
        public string orderID;
        public string orderDesc;
        public string product;
        public int productQuant;
        public string shipDate;
    }
    
    [WebService(Namespace="Microsoft.Samples.XmlMessaging.WebServices")]
    public class TypeSharingService2
    {
	    [WebMethod]
	    public ProductInvoice updateShipDate(ProductInvoice invoice, string shipDate)
	    {
		    invoice.shipDate = shipDate;
		    return invoice;
	    }
    }

}
