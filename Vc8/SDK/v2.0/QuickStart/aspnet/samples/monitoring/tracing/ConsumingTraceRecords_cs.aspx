
<script language="C#" runat="server">

    void Page_Load(Object sender, EventArgs e) {
    
        Trace.TraceFinished += new TraceContextEventHandler(Trace_Finished);  
        Trace.Write("Using Page Trace", "Subscribed to TraceFinished event"); 
    }

    void Trace_Finished(Object sender, TraceContextEventArgs e) {

        ICollection trc = e.TraceRecords;
        int i=0;

        foreach(TraceContextRecord r in trc)
        {
            Response.Write(String.Format("{0}) {1}:{2}<br />", ++i, r.Category, r.Message));
        }
    }
    
</script>

<html>
  <head>
    <title>
      Consuming Tracing Records</title>
  </head>
  <body>
    <form id="form1" runat="server">
      <div>
        <b>This page consumes tracing records and displays them in a custom way.</b>
      </div>
    </form>
  </body>
</html>
