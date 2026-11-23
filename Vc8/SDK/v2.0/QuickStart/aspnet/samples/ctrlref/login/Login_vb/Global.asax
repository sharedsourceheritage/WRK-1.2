<%@ Application Language="VB" %>
<script RunAt="server">

    Sub Application_Start(ByVal sender As Object, ByVal e As EventArgs)
    
        Membership.DeleteUser("User1")
        Membership.DeleteUser("User2")
        Membership.DeleteUser("User3")
        Roles.DeleteRole("Users")
        Roles.DeleteRole("Admins")
        Roles.DeleteRole("Customers")
                
        Dim firstUser As MembershipUser = Membership.GetUser("User1")
        If (firstUser Is Nothing) Then
        
            Dim status As MembershipCreateStatus
             
      Membership.CreateUser("User1", "123456?", "User1@contoso.com", "Favorite color?", "Red", True, status)
      Membership.CreateUser("User2", "123456?", "User2@contoso.com", "Favorite Color?", "Red", True, status)
      Membership.CreateUser("User3", "123456?", "User3@contoso.com", "Favorite Color?", "Red", True, status)
            Roles.CreateRole("Users")
            Roles.CreateRole("Admins")
            Roles.CreateRole("Customers")
            
            Roles.AddUserToRole("User1", "Users")
            Roles.AddUserToRole("User1", "Customers")
            Roles.AddUserToRole("User2", "Admins")
            Roles.AddUserToRole("User3", "Customers")
        End If
    End Sub
      
</script>
