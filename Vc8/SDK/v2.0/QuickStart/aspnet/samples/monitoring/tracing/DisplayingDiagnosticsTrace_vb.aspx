<%@ Page Language="VB" Trace="true" %>

<script runat="server">

    Sub Page_Load(sender As Object, e As EventArgs)
    
        Trace.Write("Using Page Trace","In Page_Load")
        System.Diagnostics.Trace.Write("Using System.Diagnostics.Trace", "Diagnostic message using System.Diagnostics.Trace")
        Trace.Write("Using Page Trace", "Finished Page_Load")
    End Sub
    
</script>

<html>
<head>
    <title>Integrated Tracing</title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
    <b>This page displays System.Diagnostics.Trace messages in the page trace.</b>
    </div>
    </form>
</body>
</html>
