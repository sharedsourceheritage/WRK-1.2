//-----------------------------------------------------------------------
//  This file is part of the Microsoft .NET SDK Code Samples.
// 
//  Copyright (C) Microsoft Corporation.  All rights reserved.
// 
//This source code is intended only as a supplement to Microsoft
//Development Tools and/or on-line documentation.  See these other
//materials for detailed information regarding Microsoft code samples.
// 
//THIS CODE AND INFORMATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY
//KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//PARTICULAR PURPOSE.
//-----------------------------------------------------------------------
using System;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Reflection;

namespace Microsoft.Sample.WebParts
{
    public class CustonTextConsumerConnectionPoint : ConsumerConnectionPoint
    {
        public CustonTextConsumerConnectionPoint(MethodInfo callbackMethod, Type interfaceType, Type controlType,
                                           string name, string id, bool allowsMultipleConnections)
            : base(
                                               callbackMethod, interfaceType, controlType, name, id, allowsMultipleConnections)
        {
        }
        // NOTE: A provider connection point can be disable by overriding the GetEnabled(..) method.
        //       A provider connection point can be disable by overriding the SupportsConnection(..) method.
        public override bool SupportsConnection(System.Web.UI.Control control, ConnectionInterfaceCollection secondaryInterfaces)
        {
            bool canConnect = true;
            TextDisplayWebPart tp = control as TextDisplayWebPart;
            if (tp != null)
                canConnect = tp.AllowTextConsumerConnection;

            return canConnect;

        }
        
    }
}