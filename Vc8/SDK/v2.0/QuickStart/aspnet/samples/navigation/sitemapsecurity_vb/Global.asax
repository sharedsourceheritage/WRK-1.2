<%@ Application Language="VB" %>
<%@ Import Namespace=System.Security.Principal %>


<script runat="server">

    Sub Application_PostAuthenticateRequest(ByVal sender As Object, ByVal e As EventArgs)
        If (HttpContext.Current.User.Identity.IsAuthenticated = true)
            If (HttpContext.Current.User.Identity.Name.ToLowerInvariant() = "AllSections".ToLowerInvariant()) Then
                Dim roleArray As String() = {"Administrators"}
                HttpContext.Current.User = New GenericPrincipal(HttpContext.Current.User.Identity, roleArray)
            Else
                Dim roleArray As String() = {"Regular Users"}
                HttpContext.Current.User = New GenericPrincipal(HttpContext.Current.User.Identity, roleArray)
            End If
        End If
        
    End Sub

    Sub Application_Start(ByVal sender As Object, ByVal e As EventArgs)
        ' Code that runs on application startup
    End Sub
    
    Sub Application_End(ByVal sender As Object, ByVal e As EventArgs)
        ' Code that runs on application shutdown
    End Sub
        
    Sub Application_Error(ByVal sender As Object, ByVal e As EventArgs)
        ' Code that runs when an unhandled error occurs
    End Sub

    Sub Session_Start(ByVal sender As Object, ByVal e As EventArgs)
        ' Code that runs when a new session is started
    End Sub

    Sub Session_End(ByVal sender As Object, ByVal e As EventArgs)
        ' Code that runs when a session ends. 
        ' Note: The Session_End event is raised only when the sessionstate mode
        ' is set to InProc in the Web.config file. If session mode is set to StateServer 
        ' or SQLServer, the event is not raised.
    End Sub
       
</script>
