<%@ Import Namespace="System.Configuration" %>
<%@ Import Namespace="System.Web.Caching" %>

<script RunAt="server" Language="c#" >
void Application_OnStart(Object sender, EventArgs e)
{
  // enable sql cache dependency support in the database if needed
  // this will fail if the account does not have adminstrator permissions on the Pubs database 
 
  string connectionString = ConfigurationManager.ConnectionStrings["Pubs"].ConnectionString;

  bool needToInstall = true;
  
  try 
  {
    string[] tables = SqlCacheDependencyAdmin.GetTablesEnabledForNotifications(connectionString);

    if (tables != null) 
    {
        foreach(string table in tables)
        {
          if (table.ToLower().Equals("authors"))
            needToInstall = false;
        }
    }
  } 
  catch (Exception ex)
  {
    needToInstall = true;
  }
 
  if (needToInstall)
  {
    SqlCacheDependencyAdmin.EnableNotifications(connectionString);
    SqlCacheDependencyAdmin.EnableTableForNotifications(connectionString, "Authors");
  }
}
</script>