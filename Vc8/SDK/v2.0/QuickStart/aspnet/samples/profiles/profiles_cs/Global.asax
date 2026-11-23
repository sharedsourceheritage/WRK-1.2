<%@ Application Language="C#" %>

<script runat="server">

    void Profile_MigrateAnonymous(Object sender, ProfileMigrateEventArgs pe)
    {
      //Get the anonymous profile here
      ProfileCommon anonProfile = Profile.GetProfile(pe.AnonymousID);

      //pick up the anonymous value if available
      if (anonProfile.PreferredBackgroundColor != System.Drawing.Color.Empty)
      {
        //carry over the desired properties;
        Profile.PreferredBackgroundColor = anonProfile.PreferredBackgroundColor;
      }
        
      //Delete the anonymous data from the database
      ProfileManager.DeleteProfile(pe.AnonymousID);
        
      //Remove the anonymous identifier from the request so 
      //this event will no longer fire for a logged-in user
      AnonymousIdentificationModule.ClearAnonymousIdentifier();  
    }

    void Profile_ProfileAutoSaving(Object sender, ProfileAutoSaveEventArgs e)
    {
        if ((e.Context.Items["CancelProfileAutoSave"] != null) && ((bool)e.Context.Items["CancelProfileAutoSave"] == true))
            e.ContinueWithProfileAutoSave = false;
    }

       
</script>
