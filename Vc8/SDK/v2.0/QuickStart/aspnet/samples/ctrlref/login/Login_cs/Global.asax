<%@ Application Language="C#" %>
<script RunAt="server">

    void Application_Start(Object sender, EventArgs e)
    {
        Membership.DeleteUser("User1");
        Membership.DeleteUser("User2");
        Membership.DeleteUser("User3");
        Roles.DeleteRole("Users");
        Roles.DeleteRole("Admins");
        Roles.DeleteRole("Customers");        
                
        MembershipUser firstUser = Membership.GetUser("User1");
        if (firstUser == null)
        {
            MembershipCreateStatus status;

            Membership.CreateUser("User1", "123456?", "User1@contoso.com", "Favorite color?", "Red", true, out status);
            Membership.CreateUser("User2", "123456?", "User2@contoso.com", "Favorite color?", "Red", true, out status);
            Membership.CreateUser("User3", "123456?", "User3@contoso.com", "Favorite color?", "Red", true, out status);
            Roles.CreateRole("Users");
            Roles.CreateRole("Admins");
            Roles.CreateRole("Customers");
            
            Roles.AddUserToRole("User1", "Users");
            Roles.AddUserToRole("User1", "Customers");
            Roles.AddUserToRole("User2", "Admins");
            Roles.AddUserToRole("User3", "Customers");
        }
    }
      
</script>
