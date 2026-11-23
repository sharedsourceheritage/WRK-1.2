<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >

    <head id="Head1" runat="server">
        <title>DataBinding to a property of another server control</title>
    </head>
    
    <script language="C#" runat="server">

        void SubmitBtn_Click(Object sender, EventArgs e) {
        
          // Rather than explictly pull out the variable from the "StateList"
          // and then manipulate a label control, just call "Page.DataBind".
          // This will evaluate any <%# %> expressions within the page
          
          Page.DataBind();
        }

    </script>

<body>

    <h3 style="font-family:Verdana">DataBinding to a property of another server control</h3>

    <form action="DataBind2_cs.aspx" runat="server">

        <asp:DropDownList id="StateList" runat="server">
          <asp:ListItem>CA</asp:ListItem>
          <asp:ListItem>IN</asp:ListItem>
          <asp:ListItem>KS</asp:ListItem>
          <asp:ListItem>MD</asp:ListItem>
          <asp:ListItem>MI</asp:ListItem>
          <asp:ListItem>OR</asp:ListItem>
          <asp:ListItem>TN</asp:ListItem>
          <asp:ListItem>UT</asp:ListItem>
        </asp:DropDownList>
        
        <asp:button ID="Button1" Text="Submit" OnClick="SubmitBtn_Click" runat="server"/>
        
        <br /><br />
        
        Selected State: <asp:label ID="Label1" text='<%# StateList.SelectedItem.Text %>' runat="server"/>
        
    </form>

</body>
</html>
