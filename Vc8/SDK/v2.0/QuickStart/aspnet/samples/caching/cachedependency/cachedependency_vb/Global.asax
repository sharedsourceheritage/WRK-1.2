<%@ Import Namespace="System.Configuration" %>
<%@ Import Namespace="System.Web.Caching" %>

<script Language="VB" runat="server">

Sub Application_OnStart(sender As Object, e As EventArgs)

  ' Enable sql cache dependency support in the database if needed
  ' This will fail if the account does not have adminstrator permissions on the Pubs database 
 
  Dim connectionString As String = ConfigurationManager.ConnectionStrings("Pubs").ConnectionString
  Dim needToInstall As Boolean = true
  
  Try 

    Dim tables() As String
    tables = SqlCacheDependencyAdmin.GetTablesEnabledForNotifications(connectionString)

    If (Not tables Is Nothing) Then

	Dim tbl As String
        For Each tbl in tables

          If (tbl.ToLower().Equals("authors")) Then
            needToInstall = false
          End If
        Next
    End If

  Catch ex As Exception

    needToInstall = true
  End Try
 
  If (needToInstall) Then
      SqlCacheDependencyAdmin.EnableNotifications(connectionString)
      SqlCacheDependencyAdmin.EnableTableForNotifications(connectionString, "Authors")
  End If

End Sub

</script>