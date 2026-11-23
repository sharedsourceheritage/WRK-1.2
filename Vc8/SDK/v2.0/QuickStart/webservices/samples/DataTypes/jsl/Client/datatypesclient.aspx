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

<%@ Page Language="VJ#" Debug="true" %>
 
<html>
<style>

    div
    {
        font: 8pt verdana;
        background-color:cccccc;
        border-color:black;
        border-width:1;
        border-style:solid;
        padding:10,10,10,10;
    }

</style>

<script language="VJ#" runat="server">

    public void Page_Load(Object sender, EventArgs E) 
    {
        DataTypes  dataTypeService = new DataTypes();
        /** Change this Url property if the location of the service changes */
        dataTypeService.set_Url("http://localhost/quickstartv20/webservices/samples/DataTypes/jsl/server/DataTypes.asmx");

	String value = "";
        value += "Call 1:<BR>" + dataTypeService.SayHello() + "<BR><BR>";
	value += "Call 2:<BR>" + dataTypeService.SayHelloName("Bob");
        Message1.set_InnerHtml(value);

        int[] myIntArray = dataTypeService.GetIntArray();
        value = "Contents of the Array:<BR>";
        for( int i=0; i<myIntArray.get_Length(); i++)
        {
            value += myIntArray[i] + "<BR>";
        }
        Message2.set_InnerHtml(value);


        Order myOrder =  dataTypeService.GetOrder();
        Message4.set_InnerHtml("OrderID: " + myOrder.get_OrderID() + "<BR>Price: " + myOrder.get_Price());

        Order[] myOrders = dataTypeService.GetOrders();
        value = "";
        for( int i=0; i<myOrders.get_Length(); i++) {
            if ( i > 0 ) { value += "<BR>"; }
            value += "Order#: " + i;
            value += "<BR>OrderID: " + myOrders[i].get_OrderID();
            value += "<BR>Price: " + myOrders[i].get_Price() + "<BR>";
        }
	Message5.set_InnerHtml(value);

    }

</script>

<body style="font: 10pt verdana">
<H4>Using DataTypes with XML Web services</H4>

    <h5>Two Methods that return a Primitive (String): </h5>
    <div id="Message1" runat="server"/>

    <h5>Method that returns an Array of Primitives (Integers): </h5>
    <div id="Message2" runat="server"/>

    <h5>Method that returns a Class/Struct: </h5>
    <div id="Message4" runat="server"/>

    <h5>Method that returns an array of Classes/Structs: </h5>
    <div id="Message5" runat="server"/>

</body>
</html>


