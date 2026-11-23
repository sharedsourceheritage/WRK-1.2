<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.Calendar" runat="server">
  Calendar
</Acme:TypeRef>
</h2>

The <b>Calendar</b> control displays a month calendar from which users can select dates.
The following sample illustrates using a simple <b>Calendar</b> control.

<br /><br />

<!--basic-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/calendar/Calendar1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/calendar/Calendar1.src"
        Caption="C# Calendar1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/calendar/Calendar1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/calendar/Calendar1.src"
        Caption="VB Calendar1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="modes"></a>
<h3>Date Selection Modes</h3>

<b>Calendar</b> supports four date selection modes, as described in the following table.

<br /><br />

<table class="table">
    <tr>
    <th style="width:25%"><b>Mode</b></th>
    <th>Description</th>
    </tr>
    <tr>
    <td style="width:25%"><b>Day</b></td>
    <td>User can select any single day.</td>
    </tr>
    <tr>
    <td style="width:25%"><b>DayWeek</b></td>
    <td>User can select a single day, or an entire week.</td>
    </tr>
    <tr>
    <td style="width:25%"><b>DayWeekMonth</b></td>
    <td>User can select a single day, an entire week, or the entire visible month.</td>
    </tr>
    <tr>
    <td style="width:25%"><b>None</b></td>
    <td>Date selection is disabled.</td>
    </tr>
</table>

<br /><br />

The following sample demonstrates mode selection with a <b>Calendar</b> control.

<br /><br />

<!--Date Selection Modes-->
<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/calendar/Calendar2_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/calendar/Calendar2.src"
        Caption="C# Calendar2.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/calendar/Calendar2_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/calendar/Calendar2.src"
        Caption="VB Calendar2.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="graphics"></a>
<h3>Selection Link Graphics</h3>
The <b>Calendar</b> control can use either text or graphics for its selection links.  The following sample shows how
to use graphics to create a better-looking calendar.
<!--selection link graphics-->

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/calendar/Calendar3_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/calendar/Calendar3.src"
        Caption="C# Calendar3.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/calendar/Calendar3_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/calendar/Calendar3.src"
        Caption="VB Calendar3.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="text"></a>
<h3>Selection Link Text</h3>
The <b>Calendar</b> control can also use text labels for week or month selection, as shown in the following example.
<!--selection link text-->

<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/calendar/Calendar4_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/calendar/Calendar4.src"
        Caption="C# Calendar4.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/calendar/Calendar4_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/calendar/Calendar4.src"
        Caption="VB Calendar4.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

<a name="custom"></a>
<h3>Adding Custom Content to Calendar</h3>
You can make appointment-style calendars by adding content in the <b>OnDayRender</b> event. Two of the arguments
for <b>OnDayRender</b> are the <b>Day</b> that is being rendered and its <b>Cell</b> object.  Custom text can be added to the
cell for a particular day by adding it as a <b>LiteralControl</b> to the <b>Cell</b> object's Controls collection, as shown in the following example.

<br /><br />

<Acme:TabControl runat="server">
<Tab Name="C#">
string Hol = GetHoliday(Day.Date);

if (Hol != string.Empty) Cells.Controls.Add(new LiteralControl("&lt;br&gt;" + Hol));
</Tab>

<Tab Name="VB">
Dim Hol As String = GetHoliday(Day.Date)

If Hol <> String.Empty Then Cells.Controls.Add(New LiteralControl("&lt;br&gt;" + Hol))
</Tab>

</Acme:TabControl>

<!--adding custom content-->
<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/calendar/Calendar5_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/calendar/Calendar5.src"
        Caption="C# Calendar5.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/calendar/Calendar5_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/calendar/Calendar5.src"
        Caption="VB Calendar5.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
