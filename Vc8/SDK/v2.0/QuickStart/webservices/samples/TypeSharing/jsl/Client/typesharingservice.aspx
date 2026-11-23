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

<script runat="server">

public void CreateOrder_Click(Object sender, EventArgs E)
{
    TypeSharingService1 service1 = new TypeSharingService1();
    //Change this URL if the location of the Web service changes
    service1.set_Url("http://localhost/Quickstartv20/webservices/Samples/TypeSharing/jsl/Server/TypeSharingService1.asmx");
    ProductInvoice invoice = service1.createOrder("widgets", 10);
    OrderDescLabel.set_Text("Success!  You have created an Order for 10 widgets.");
    //Save the ProductInvoice instance so that it can later be shared
    System.Web.HttpContext context = System.Web.HttpContext.get_Current();
    System.Web.SessionState.HttpSessionState state = context.get_Session();
    state.Add("myOrder", invoice); 
}

public void UpdateOrder_Click(Object sender, EventArgs E)
{
    System.Web.HttpContext context = System.Web.HttpContext.get_Current();
    System.Web.SessionState.HttpSessionState state = context.get_Session(); 

    //If an order has not yet been created then you cannot update the order
    if (state.get_Item("myOrder") == null)
    {
        shippingDetailsLabel.set_Text("Error. You must first create an order.");
        return;
    }
    TypeSharingService2 service2 = new TypeSharingService2();
    //Change this URL if the location of the Web service changes
    service2.set_Url("http://localhost/QuickStartv20/webservices/Samples/TypeSharing/jsl/Server/TypeSharingService2.asmx");
    //Retrieve the ProductInvoice instance and pass it to the second service   
    ProductInvoice invoice = (ProductInvoice)state.get_Item("myOrder");
    ProductInvoice updatedInvoice = service2.updateShipDate(invoice, "March 15");
    //Print out the new ship date from the updated ProductInvoice
    shippingDetailsLabel.set_Text("Your new ship date is " + updatedInvoice.get_shipDate() + ".");
    //Save the updated ProductInvoice instance
    state.set_Item("myOrder", updatedInvoice);
}
    
public void ResetSample_Click(Object sender, EventArgs E)
{
    System.Web.HttpContext context = System.Web.HttpContext.get_Current();
    System.Web.SessionState.HttpSessionState state = context.get_Session();
    state.set_Item("myOrder", null);
    OrderDescLabel.set_Text("");
    shippingDetailsLabel.set_Text("");
}
</script>

<html>  
<body>
    <form id="form1" runat="server">
        <font face="verdana">
        To share types, use the /sharetypes flag with wsdl.exe.  For example,
        <pre>
        wsdl.exe /sharetypes 
        http://localhost/Quickstart/webservices/Samples/TypeSharing/vjs/Server/TypeSharingService1.asmx
        http://localhost/Quickstart/webservices/Samples/TypeSharing/vjs/Server/TypeSharingService2.asmx
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
