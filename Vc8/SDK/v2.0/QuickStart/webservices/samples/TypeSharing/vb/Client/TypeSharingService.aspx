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

<%@ Page Language="VB" %>

<script runat="server">

Public Sub CreateOrder_Click(sender As [Object], E As EventArgs)
   Dim service1 As New TypeSharingService1()
   'Change this URL if the location of the Web service changes
   service1.Url = "http://localhost/Quickstartv20/webservices/Samples/TypeSharing/vb/Server/TypeSharingService1.asmx"
   Dim invoice As ProductInvoice = service1.createOrder("widgets", 10)
   OrderDescLabel.Text = "Success!  You have created an Order for 10 widgets."
   'Save the ProductInvoice instance so that it can later be shared
   Session("myOrder") = invoice
End Sub 'CreateOrder_Click


Public Sub UpdateOrder_Click(sender As [Object], E As EventArgs)
   'If an order has not yet been created then you cannot update the order
   If Session("myOrder") Is Nothing Then
      shippingDetailsLabel.Text = "Error. You must first create an order."
      Return
   End If
   Dim service2 As New TypeSharingService2()
   'Change this URL if the location of the Web service changes
   service2.Url = "http://localhost/QuickStartv20/webservices/Samples/TypeSharing/vb/Server/TypeSharingService2.asmx"
   'Retrieve the ProductInvoice instance and pass it to the second service
   Dim invoice As ProductInvoice = CType(Session("myOrder"), ProductInvoice)
   Dim updatedInvoice As ProductInvoice = service2.updateShipDate(invoice, "March 15")
   'Print out the new ship date from the updated ProductInvoice
   shippingDetailsLabel.Text = "Your new ship date is " + updatedInvoice.shipDate + "."
   'Save the updated ProductInvoice instance
   Session("myOrder") = updatedInvoice
End Sub 'UpdateOrder_Click


Public Sub ResetSample_Click(sender As [Object], E As EventArgs)
   Session("myOrder") = Nothing
   OrderDescLabel.Text = ""
   shippingDetailsLabel.Text = ""
End Sub 'ResetSample_Click
</script>

<html>  
<body>
    <form id="form1" runat="server">
        <font face="verdana">
        To share types, use the /sharetypes flag with wsdl.exe.  For example,
        <pre>
        wsdl.exe /sharetypes 
        http://localhost/QuickstartV20/webservices/Samples/TypeSharing/vb/Server/TypeSharingService1.asmx
        http://localhost/QuickstartV20/webservices/Samples/TypeSharing/vb/Server/TypeSharingService2.asmx
        </pre> 
        <font  size="+1">
        <p><input id="Submit1" type="submit" value="Reset Sample" OnServerClick="ResetSample_Click" runat="server" /></p>
        <p><b>Step 1: Create Order at Ordering Center</b> (create the type instance that will be shared)</p>
        <p><input type="submit" value="Create Order" OnServerClick="CreateOrder_Click" runat="server" /></p>
        <p><font color="red"><asp:Label id="OrderDescLabel" text="" runat="server"/></font></p>
        
        <p><b>Step 2: Update Order at Shipping Center with New Ship Date</b> (share the type instance with a second service)</p>    
        <p><input type="submit" value="Update Order" OnServerClick="UpdateOrder_Click" runat="server" /></p>
        <p><font color="red"><asp:Label id="shippingDetailsLabel" text="" runat="server"/></font></p>
        </font></font>
    </form>
</body>
</html>
