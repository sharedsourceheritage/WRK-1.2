<%@ Page Language="VB" %>
<%@ Register tagprefix="Quickstart" tagname="SampleControl" src="SampleControl_vb.ascx" %>

<script runat="server">

    Sub Page_Load(sender As Object, e As EventArgs)
    
      If ((Not CachedControl Is Nothing) AndAlso CachedControl.CachePolicy.SupportsCaching) Then

        Dim cache As String = Request.Params("cache")

        If ((Not cache Is Nothing) AndAlso cache.Equals("false")) Then

          CachedControl.CachePolicy.Cached = false

        Else

          CachedControl.CachePolicy.VaryByParams("cache") = true
          CachedControl.CachePolicy.Cached = true
          CachedControl.CachePolicy.Duration = TimeSpan.FromSeconds(10)
        End If
      End If

    End Sub

</script>

<html>
<head>
    <title>Programatic Control Over Fragment Caching.</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    <b>This page uses the control cache policy API to change cache settings for a user control programatically.</b>
    <br /><br /> 
    <Quickstart:SampleControl id="CachedControl" runat="server" />
    <br /><br /> 
    <asp:HyperLink runat="server" Text="Reload with control cached" NavigateUrl="ControlCachePolicy_cs.aspx" />
    <br />    
    <asp:HyperLink runat="server" Text="Reload with control not cached" NavigateUrl="ControlCachePolicy_cs.aspx?cache=false" />    
    </div>
    </form>
</body>
</html>
