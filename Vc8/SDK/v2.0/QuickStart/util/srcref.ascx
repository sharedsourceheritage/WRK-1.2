<%@ Import Namespace="System.IO" %>
<script language="C#" runat="server">

    private String _target = "_blank";
    public String _runsample = "";
    public String ViewSource = "";
    public String Caption = "";
    public String Icon = "";
    public bool CanBeHosted = true;
    public String SamplePath = "";

    public void Page_Load(Object sender, EventArgs e) {

        // if remote hosting is on, turn all run sample links to view source instead
        if ((String)((NameValueCollection) Context.GetConfig("appSettings"))["RemoteHost"]=="true") {
		//if the sample cannot be hosted, we need to not show the run sample link
            if (CanBeHosted == false)
            {
                _runsample = "";
		    SamplePath="";
            }
        }
    }

    public String RunSample {
        get {
            return _runsample;
        }
        set {
            _runsample = value;
        }
    }

</script>


    <%
     if(RunSample != "") {
    %>

    <div class="runview">

      <%=Caption%><br/>

      <a target="<%=_target%>" href="<%=RunSample%>">
      <img alt="Run Sample" border="0" src="<%=HttpRuntime.AppDomainAppVirtualPath%>/images/button_run.gif"
          onmouseout="this.src='<%=HttpRuntime.AppDomainAppVirtualPath%>/images/button_run.gif'" 
          onmouseover="this.src='<%=HttpRuntime.AppDomainAppVirtualPath%>/images/button_run-over.gif'" 
          onmousedown="this.src='<%=HttpRuntime.AppDomainAppVirtualPath%>/images/button_run-down.gif'" 
          onmouseup="this.src='<%=HttpRuntime.AppDomainAppVirtualPath%>/images/button_run.gif'" /></a>

      <% if(ViewSource != "") { %>

      <a target="_blank" href="<%=HttpRuntime.AppDomainAppVirtualPath%>/util/srcview.aspx?path=<%=ViewSource%>">
      <img alt="View Source" border="0" src="<%=HttpRuntime.AppDomainAppVirtualPath%>/images/button_view.gif"
          onmouseout="this.src='<%=HttpRuntime.AppDomainAppVirtualPath%>/images/button_view.gif'" 
          onmouseover="this.src='<%=HttpRuntime.AppDomainAppVirtualPath%>/images/button_view-over.gif'" 
          onmousedown="this.src='<%=HttpRuntime.AppDomainAppVirtualPath%>/images/button_view-down.gif'" 
          onmouseup="this.src='<%=HttpRuntime.AppDomainAppVirtualPath%>/images/button_view.gif'" /></a>

      <% } %>

    </div>

    <%
    }
    else if(ViewSource != "") {
    %>

    <div class="runview">

        <%=Caption%><br/>

        <a target="_blank" href="<%=HttpRuntime.AppDomainAppVirtualPath%>/util/srcview.aspx?path=<%=ViewSource%>">
        <img alt="View Source" border="0" src="<%=HttpRuntime.AppDomainAppVirtualPath%>/images/button_view.gif"
          onmouseout="this.src='<%=HttpRuntime.AppDomainAppVirtualPath%>/images/button_view.gif'" 
          onmouseover="this.src='<%=HttpRuntime.AppDomainAppVirtualPath%>/images/button_view-over.gif'" 
          onmousedown="this.src='<%=HttpRuntime.AppDomainAppVirtualPath%>/images/button_view-down.gif'" 
          onmouseup="this.src='<%=HttpRuntime.AppDomainAppVirtualPath%>/images/button_view.gif'" /></a>
        
 
    </div>

      <% if(SamplePath !="") { %>
	   <p>
	   [This sample can be found at <%=HttpRuntime.AppDomainAppPath%><%=SamplePath%><br>
	    To build this sample, open the SDK command prompt and navigate to the above path.  Build the sample using the build tool <b>msbuild</b> 
            passing the solution file as the first parameter: <i>msbuild mySample.sln</i>.  The compiled executable will be found in the sub directory \bin 
	    directory.]</p>

      <% }
      }
      else {
      %>

      <b>No Source or Sample to display.</b>

      <%
      }
      %>

