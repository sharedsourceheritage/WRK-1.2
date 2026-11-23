<%@ Application Language="C#" %>
<%@ Import Namespace=System.Security.Principal %>

<script runat="server">

    void Application_PostAuthenticateRequest(Object sender, EventArgs e)
    {
        if (HttpContext.Current.User.Identity.IsAuthenticated == true)
        {
            if (HttpContext.Current.User.Identity.Name.ToLowerInvariant() == "AllSections".ToLowerInvariant())
                HttpContext.Current.User = new GenericPrincipal(HttpContext.Current.User.Identity,new string[]{"Administrators"});
            else
                HttpContext.Current.User = new GenericPrincipal(HttpContext.Current.User.Identity, new string[] { "Regular Users" });
        }  
        
    }
       
    void Application_Start(Object sender, EventArgs e) {
        // Code that runs on application startup

    }
    
    void Application_End(Object sender, EventArgs e) {
        //  Code that runs on application shutdown

    }
        
    void Application_Error(Object sender, EventArgs e) { 
        // Code that runs when an unhandled error occurs

    }

    void Session_Start(Object sender, EventArgs e) {
        // Code that runs when a new session is started

    }

    void Session_End(Object sender, EventArgs e) {
        // Code that runs when a session ends. 
        // Note: The Session_End event is raised only when the sessionstate mode
        // is set to InProc in the Web.config file. If session mode is set to StateServer 
        // or SQLServer, the event is not raised.

    }
       
</script>
