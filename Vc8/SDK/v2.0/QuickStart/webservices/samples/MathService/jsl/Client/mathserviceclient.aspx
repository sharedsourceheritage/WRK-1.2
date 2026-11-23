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

<%@ Page Language="VJ#" Debug="True" %>

<html>

<script language="VJ#" runat="server">

  float operand1 = 0;
  float operand2 = 0;

  public void Submit_Click(Object sender, EventArgs E)
  {
      try
      {
        operand1 = Float.valueOf(Operand1.get_Text()).floatValue();
        operand2 = Float.valueOf(Operand2.get_Text()).floatValue();
      }
      catch (Exception exc) { /* ignored */ }

      MathService service = new MathService();
      //change this URL if the location of the Web service changes
      service.set_Url("http://localhost/QuickStartv20/webservices/Samples/MathService/jsl/Server/MathService.asmx");

      String operation = ((Control)sender).get_ID();
      if(operation == "Add")
         Result.set_Text("<b>Result</b> = " + Float.toString(service.Add(operand1, operand2)));
      else if(operation == "Subtract")
         Result.set_Text("<b>Result</b> = " + Float.toString(service.Subtract(operand1, operand2)));
      else if(operation == "Multiply")
         Result.set_Text("<b>Result</b> = " + Float.toString(service.Multiply(operand1, operand2)));
      else if(operation == "Divide")
         Result.set_Text("<b>Result</b> = " + Float.toString(service.Divide(operand1, operand2)));
  }


</script>

<body style="font: 10pt verdana">

  <h4>Using a Simple Math Service </h4>

  <form runat="server">

  <div style="padding:15,15,15,15;background-color:#F5F5DC;width:300;border-color:black;border-width:1;border-style:solid">

    Operand 1: <br><asp:TextBox id="Operand1" Text="15" runat="server"/><br>
    Operand 2: <br><asp:TextBox id="Operand2" Text="5" runat="server"/><p>

    <input type="submit" id="Add" value="Add" OnServerClick="Submit_Click" runat="server">
    <input type="submit" id="Subtract" value="Subtract" OnServerClick="Submit_Click" runat="server">
    <input type="submit" id="Multiply" value="Multiply" OnServerClick="Submit_Click" runat="server">
    <input type="submit" id="Divide" value="Divide" OnServerClick="Submit_Click" runat="server">

    <p>

    <asp:Label id="Result" runat="server"/>

  </div>

  </form>

</body>
</html>


