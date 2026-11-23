<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>

<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>


<h2>Accessing Trace Messages in Code <span class="newinline">New in 2.0</span></h2>

Page writers can now consume trace messages in code, allowing them to do custom processing, presentation, and redirection of trace output.  In the sample below, the page uses the TraceContext.TraceFinished event to obtain a collection of trace records, and display them manually:
<br/><br/>

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../samples/monitoring/tracing/ConsumingTraceRecords_cs.aspx"
        ViewSource="~/aspnet/samples/monitoring/tracing/ConsumingTraceRecords.src"
        Caption="C# Consuming Trace Records"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../samples/monitoring/tracing/ConsumingTraceRecords_vb.aspx"
        ViewSource="~/aspnet/samples/monitoring/tracing/ConsumingTraceRecords.src"
        Caption="VB Consuming Trace Records"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>

