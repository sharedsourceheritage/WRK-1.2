<html>

   <script language="VB" runat=server>

     Sub Page_Load(ByVal Sender As Object, ByVal E As EventArgs)

       ArrayItems.Add("One")
       ArrayItems.Add("Two")
       ArrayItems.Add("Three")

       MyList.DataSource = ArrayItems
       MyList.DataBind()
     End Sub

   </script>

   <body>

      <object id="ArrayItems" class="System.Collections.ArrayList" runat=server/>

      <asp:datalist id="MyList" runat=server>

         <ItemTemplate>

            Here is a value: <%# Container.DataItem %>

         </ItemTemplate>

      </asp:datalist>

   </body>

</html>