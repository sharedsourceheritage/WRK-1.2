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

<%@ Page Language="C#" Debug="true" %>
 
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

<script language="C#" runat="server">

    public void Page_Load(Object sender, EventArgs E) 
    {
        DataTypes  dataTypeService = new DataTypes();
	//change this URL if the location of the Web service changes
        dataTypeService.Url = "http://localhost/QuickStartv20/webservices/Samples/DataTypes/cs/server/DataTypes.asmx";
        Message1.InnerHtml = "Call 1:<BR>" + dataTypeService.SayHello() + "<BR><BR>";
        Message1.InnerHtml += "Call 2:<BR>" + dataTypeService.SayHelloName("Bob");

        int[] myIntArray = dataTypeService.GetIntArray();
        String myString = "Contents of the Array:<BR>";
        for( int i=0; i<myIntArray.Length; i++)
        {
            myString = myString + myIntArray[i] + "<BR>";
        }
        Message2.InnerHtml = Message2.InnerHtml + myString;

        Message3.InnerHtml = "Enum Value: <BR>" + dataTypeService.GetMode();

        Order myOrder =  dataTypeService.GetOrder();
        Message4.InnerHtml = "OrderID: " + myOrder.OrderID;
        Message4.InnerHtml += "<BR>Price: " + myOrder.Price;

        Order[] myOrders = dataTypeService.GetOrders();
        for( int i=0; i<myOrders.Length; i++) {
            if ( i > 0 ) { Message5.InnerHtml += "<BR>"; }
            Message5.InnerHtml += "Order#: " + i;
            Message5.InnerHtml += "<BR>OrderID: " + myOrders[i].OrderID;
            Message5.InnerHtml += "<BR>Price: " + myOrders[i].Price + "<BR>";
        }

    }

</script>

<body style="font: 10pt verdana">
<H4>Using DataTypes with XML Web services</H4>

    <h5>Two Methods that return a Primitive (String): </h5>
    <div id="Message1" runat="server"/>

    <h5>Method that returns an Array of Primitives (Integers): </h5>
    <div id="Message2" runat="server"/>

    <h5>Method that returns an Enum: </h5>
    <div id="Message3" runat="server"/>

    <h5>Method that returns a Class/Struct: </h5>
    <div id="Message4" runat="server"/>

    <h5>Method that returns an array of Classes/Structs: </h5>
    <div id="Message5" runat="server"/>

</body>
</html>


