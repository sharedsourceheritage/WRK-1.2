<%@ Application Language="VB" %>

<script runat="server">

  Sub Profile_MigrateAnonymous(ByVal sender As Object, ByVal pe As ProfileMigrateEventArgs)
    'Get the anonymous profile here
    Dim anonProfile As ProfileCommon = Profile.GetProfile(pe.AnonymousID)

    'pick up the anonymous value if available
    If (anonProfile.PreferredBackgroundColor <> System.Drawing.Color.Empty) Then
      'carry over the desired properties;
      Profile.PreferredBackgroundColor = anonProfile.PreferredBackgroundColor
    End If

    'Delete the anonymous data from the database
    ProfileManager.DeleteProfile(pe.AnonymousID)
        
    'Remove the anonymous identifier from the request so 
    'this event will no longer fire for a logged-in user
    AnonymousIdentificationModule.ClearAnonymousIdentifier() 

  End Sub

  Sub Profile_ProfileAutoSaving(ByVal sender as Object, ByVal e as ProfileAutoSaveEventArgs)
    If (Not e.Context.Items("CancelProfileAutoSave") Is Nothing)
       If (CBool(e.Context.Items("CancelProfileAutoSave")) = true)
           e.ContinueWithProfileAutoSave = false
       End If
    End If
  End Sub
        
</script>