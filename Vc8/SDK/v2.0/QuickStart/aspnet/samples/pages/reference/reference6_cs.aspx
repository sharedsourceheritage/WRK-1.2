<html>

   <script language="C#" runat=server>

      void Page_Load(Object sender, EventArgs e) {

         ArrayItems.Add("One");
         ArrayItems.Add("Two");
         ArrayItems.Add("Three");

         MyList.DataSource = ArrayItems;
         MyList.DataBind();
      }

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