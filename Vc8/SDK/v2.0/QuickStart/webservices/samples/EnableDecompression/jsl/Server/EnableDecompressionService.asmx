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

<%@ WebService Language="VJ#" Class="EnableDecompressionService" %>

import System.*;
import System.Web.Services.*;

/** @attribute WebService(Namespace="Microsoft.Samples.XmlMessaging.WebServices") */
public class EnableDecompressionService
{
    /** @attribute WebMethod() */
    public String HelloWorld()
    {
        //this service does not support compression
        //if this service supported compression it would be automatically
        //decompressed on the client when EnableDecompression=true
        return "Hello World";
    }	
}