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

<%@ page language="VB" debug="true" %>

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

<script language="VB" runat="server">

    Public Sub Page_Load(Sender As Object, E As EventArgs)
     
        Dim dataTypeService As DataTypes = New DataTypes()
	' change this URL if the location of the Web service changes
        dataTypeService.Url = "http://localhost/QuickStartv20/webservices/Samples/DataTypes/vb/Server/DataTypes.asmx"
        Message1.InnerHtml = "Call 1:<BR>" & dataTypeService.SayHello() & "<BR><BR>"
        Message1.InnerHtml += "Call 2:<BR>" & dataTypeService.SayHelloName("Bob")

        Dim MyIntArray As Integer() = dataTypeService.GetIntArray()
        Dim MyString As String = "Contents of the Array:<BR>"
        Dim I As Integer
        For I = 0 To MyIntArray.Length - 1
            MyString = MyString & MyIntArray(I) & "<BR>"
        Next
        

        Message2.InnerHtml = Message2.InnerHtml & MyString

	Dim mode As Mode
	mode = dataTypeService.GetMode()
	
	Dim enumValue As String
	If mode.Equals(Mode.Large) Then
		enumValue = "Large"
	Else
		enumValue = "Small"
	End If

        Message3.InnerHtml = "Enum Value: <BR>" & enumValue

        Dim MyOrder As Order = dataTypeService.GetOrder()
        Message4.InnerHtml = Message4.InnerHtml & "OrderID: " & MyOrder.OrderID
        Message4.InnerHtml = Message4.InnerHtml & "<BR>Price: " & MyOrder.Price

        Dim MyOrders As Order() = dataTypeService.GetOrders()
        For I = 0 To myOrders.Length - 1
            If i > 0 Then Message5.InnerHtml &= "<BR>"
            Message5.InnerHtml &= "Order#: " & I
            Message5.InnerHtml &= "<BR>OrderID: " & myOrders(0).OrderID
            Message5.InnerHtml &= "<BR>Price: " & MyOrders(0).Price & "<BR>"
        Next
    End Sub

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


