<%@ Application Language="C#" %>
<script RunAt="server">

  void Application_Start(Object sender, EventArgs e)
  {
    if (Membership.GetUser("Test") == null)
    {
      // Create User In Membership System
      Membership.CreateUser("Test", "Test@1234");
    }
  }
       
</script>
