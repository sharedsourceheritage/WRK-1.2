<%@ Page Language="C#" AutoEventWireup="true" EnableEventValidation="false" CodeFile="CallBackEventHandler_cs.aspx.cs" Inherits="CallBackEventHandler_cs" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
   <title>Client CallBack</title>
</head>
<body>
<form id="Form1" runat="server">

   <h3>Cascading DropDownLists Using ICallBackEventHandler</h3>
   <asp:DropDownList ID="ParentDropDown"
    onchange="GetChildren(this.options[this.selectedIndex].value, 'ddl');"   
    Runat="server">
     <asp:ListItem Text="Item 1" />
     <asp:ListItem Text="Item 2" />
     <asp:ListItem Text="Item 3" />
   </asp:DropDownList>
   <asp:DropDownList ID="ChildDropDown" AutoPostBack="true" style="visibility:hidden" Runat="Server">
    <asp:ListItem Text="Child Item" />
   </asp:DropDownList>
   <br /><br />
   <asp:Label ID="Label1" runat="server"/>

   <script type="text/javascript">

   function ClientCallback(result, context){

      var childDropDown = document.forms[0].elements['<%=ChildDropDown.UniqueID%>'];

      if (!childDropDown){
         return;
      }

      childDropDown.length = 0;

      if (!result){
          return;
      }
      
      var rows = result.split('|'); 
      for (var i = 0; i < rows.length; ++i){
         var option = document.createElement("OPTION");
         option.value = rows[i];
         option.innerHTML = rows[i];     
         childDropDown.appendChild(option);
      }
      
      childDropDown.style.visibility = "visible";
   }

   function ClientCallbackError(result, context){
      alert(result);
   }

   </script>

</form>
</body>

</html>
