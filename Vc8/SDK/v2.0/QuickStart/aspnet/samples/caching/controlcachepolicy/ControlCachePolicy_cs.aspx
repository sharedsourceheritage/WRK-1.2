<%@ Page Language="C#" %>
<%@ Register tagprefix="Quickstart" tagname="SampleControl" src="SampleControl_cs.ascx" %>

<script runat="server">

    void Page_Load(Object sender, EventArgs e)
    {
      if ((CachedControl != null) && CachedControl.CachePolicy.SupportsCaching)
      {
        string cache = Request.Params["cache"];

        if ((cache != null) && cache.Equals("false"))
        {
          CachedControl.CachePolicy.Cached = false;
        }
        else
        {
          CachedControl.CachePolicy.VaryByParams["cache"] = true;
          CachedControl.CachePolicy.Cached = true;
          CachedControl.CachePolicy.Duration = TimeSpan.FromSeconds(10);
        }
      }
    }

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
