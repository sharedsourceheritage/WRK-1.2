
<script language="VB" runat="server">

    Sub Page_Load(sender As Object, e As EventArgs)
    
        AddHandler Trace.TraceFinished, AddressOf Me.Trace_Finished
        Trace.Write("Using Page Trace", "Subscribed to TraceFinished event") 
    End Sub

    Sub Trace_Finished(sender As Object, e As TraceContextEventArgs)

        Dim trc As ICollection = e.TraceRecords
        Dim i As Integer = 0

        Dim r As TraceContextRecord
        For Each r in trc
            i=i+1
            Response.Write(String.Format("{0}) {1}:{2}<br />", i, r.Category, r.Message))
        Next
    End Sub
    
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
