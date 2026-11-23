<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix="Acme" Namespace="Acme" %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx" %>
<asp:Content ID="Content1" ContentPlaceHolderID="MainBody" runat="Server">
    <h2>
        Page Fragment Caching</h2>
    <p>
        In addition to output caching an entire page, ASP.NET provides a simple way for
        you to output cache regions of page content, which is appropriately named fragment
        caching. You delineate regions of your page with a <asp:HyperLink NavigateUrl="~/aspnet/doc/ctrlref/userctrl/default.aspx" runat="server">user control</asp:HyperLink>,
        and mark them for caching using the <b>@ OutputCache</b> directive introduced in
        the previous section. This directive specifies the duration (in seconds) that the
        output content of the user control should be cached on the server, as well as any
        optional conditions by which it should be varied.


        For example, the following directive instructs ASP.NET to output cache the user
        control for 120 seconds, and to vary the caching using the "CategoryID" and "SelectedID"
        querystring or form post parameters.
    </p>
    <pre class="code">
&lt;%@ OutputCache Duration="120" VaryByParam="CategoryID;SelectedID"%&gt;
</pre>
    <p>
        The <b>VaryByParam</b> attribute is extremely powerful and allows user control authors
        to instruct ASP.NET to cache/store multiple instances of an output cache region
        on the server. For example, the following URLs to the host page of the previous
        user control cache separate instances of the user control content.
    </p>
    <div class="indent">
        <u>http://localhost/mypage.aspx?categoryid=foo&selectedid=0</u><br>
        <u>http://localhost/mypage.aspx?categoryid=foo&selectedid=1</u>
    </div>
    <p>
        Logic within a user control can then dynamically generate different content (which
        is cached separately) depending on the arguments provided.
    </p>
    <p>
        In addition to supporting the <b>VaryByParam</b> attribute, fragment caching also
        supports a <b>VaryByControl</b> attribute. Whereas the <b>VaryByParam</b> attribute
        varies cached results based on name/value pairs sent using <b>POST</b> or <b>GET</b>,
        the <b>VaryByControl</b> attribute varies the cached fragment by controls within
        the user control. For example:
    </p>
    <pre class="code">
&lt;%@ OutputCache Duration="120" VaryByParam="none" VaryByControl="Category" %&gt;
</pre>
    <p>
        Note that similar to output-cached pages, explicit use of either <b>VaryByParam</b> 
        or <b>VaryByControl</b> is required even if neither is used.
        If the user control contained a drop-down select box control named Category, the
        user control's output would vary based on the selected value within that control.
    </p>
    <p>
        The following sample code demonstrates how to cache two menu sections of a page
        using a declarative user control.
    </p>
    <Acme:TabControl runat="server">
<Tab Name="C#">
&lt;%@ Page Language="C#" %&gt;
&lt;%@ Register TagPrefix="Acme" TagName="Menu" Src="Menu.ascx" %&gt;

&lt;html&gt;
  &lt;body&gt;
    &lt;table&gt;
      &lt;tr&gt;
        &lt;td&gt;
          &lt;Acme:Menu Category="LeftMenu" runat=server/&gt;
        &lt;/td&gt;
        &lt;td&gt;
          &lt;h1&gt;Hi, the time is now: &lt;%=DateTime.Now%&gt; &lt;/h1&gt;
        &lt;/td&gt;
        &lt;td&gt;
          &lt;Acme:Menu Category="RightMenu" runat=server/&gt;
        &lt;/td&gt;
      &lt;tr&gt;
    &lt;/table&gt;
  &lt;/body&gt;
&lt;/html&gt;
</Tab>
<Tab Name="VB">
&lt;%@ Page Language="VB" %&gt;
&lt;%@ Register TagPrefix="Acme" TagName="Menu" Src="Menu.ascx" %&gt;

&lt;html&gt;
  &lt;body&gt;
    &lt;table&gt;
      &lt;tr&gt;
        &lt;td&gt;
          &lt;Acme:Menu Category="LeftMenu" runat=server/&gt;
        &lt;/td&gt;
        &lt;td&gt;
          &lt;h1&gt;Hi, the time is now: &lt;%=Now%&gt; &lt;/h1&gt;
        &lt;/td&gt;
        &lt;td&gt;
          &lt;Acme:Menu Category="RightMenu" runat=server/&gt;
        &lt;/td&gt;
      &lt;tr&gt;
    &lt;/table&gt;
  &lt;/body&gt;
&lt;/html&gt;
</Tab>
    </Acme:TabControl>
    <p>
        The following sample code shows the implementation of the "Acme:Menu" user control
        with caching support.
    </p>
    <Acme:TabControl runat="server">
<Tab Name="C#">
&lt;%@ Control Language="C#" ClassName="AcmeMenu" %&gt;
&lt;%@ OutputCache Duration="120" VaryByParam="none" %&gt;

&lt;script runat=server&gt;

    public String Category;

    void Page_Load(Object sender, EventArgs e)  {

        AdoConnection conn = new AdoConnection("MyDSN");

        MyMenu.DataSource = conn.Execute("select * from menu where category=" + Category );
        MyMenu.DataBind();
    }

&lt;/script&gt;

&lt;asp:datagrid id="MyMenu" runat=server/&gt;
</Tab>
<Tab Name="VB">
&lt;%@ Control Language="VB" ClassName="AcmeMenu" %&gt;
&lt;%@ OutputCache Duration="120" VaryByParam="none" %&gt;

&lt;script runat=server&gt;

    Public Category As String;

    Sub Page_Load(sender As Object, e As EventArgs)

        Dim conn As AdoConnection = New AdoConnection("MyDSN")

        MyMenu.DataSource = conn.Execute("select * from menu where category=" & Category)
        MyMenu.DataBind()
    End Sub

&lt;/script&gt;

&lt;asp:datagrid id="MyMenu" runat=server/&gt;
</Tab>

    </Acme:TabControl>
    <p>
        Note that this example output caches the response of each user control for a period
        of 120 seconds. All logic necessary to recreate each menu user control in the event
        of a cache miss (either because 120 seconds has expired or because memory conditions
        on the server have become scarce) is encapsulated cleanly within the user control.
    </p>
    <p>
        The following example shows simple fragment caching. The sample caches the output
        from a control that retrieves data from an SQL Server database, while keeping the
        dynamic properties of the parent page. You can see that the page is dynamic because
        the time is updated with every refresh, while the control is only updated every
        60 seconds.
    </p>
    <Acme:LangSwitch runat="server">
        <cstemplate>
<Acme:SourceRef
  RunSample="../../samples/caching/fragment/fragmentcache1_cs.aspx"
  ViewSource="~/aspnet/samples/caching/fragment/fragmentcache1.src"
  Caption="C# Fragment Cache"
  runat="server" />
  </cstemplate>
        <vbtemplate>
<Acme:SourceRef
  RunSample="../../samples/caching/fragment/fragmentcache1_vb.aspx"
  ViewSource="~/aspnet/samples/caching/fragment/fragmentcache1.src"
  Caption="VB Fragment Cache"
  runat="server" />
  </vbtemplate>
    </Acme:LangSwitch>

    <p>
        <b>Note:</b> Attempts to programmatically manipulate an output-cached control from
        its containing page result in an error. For example, attempts to use a declarative
        data binding expression on the user control tag generate parser errors, as shown
        in the following code.
    </p>
    <pre class="code">
&lt;!-- The following tags generate parser errors. --&gt;
&lt;Acme:Menu Category='&lt;%# Container.DataItem("Category")'  runat="server"/&gt;
</pre>
    <p>
        The reason for this is simple. In cases when the content of a user control is output
        cached, an instance of the control is created only on the first request; thus, once
        cached, the control is no longer available. Instead, you should encapsulate all
        the logic necessary to create the content of a user control directly within the
        control itself; this is typically done within the user control's <b>Page_Load</b>
        event or <b>Page_PreRender</b> event.
    </p>
    <p>
        You can declare and use other declarative property parameters to customize the control.
        For example, the previous user control can be customized as follows:
    </p>
    <pre class="code">
&lt;Acme:Menu Category="LeftMenu" runat=server/&gt;
&lt;Acme:Menu Category="RightMenu" runat=server/&gt;
</pre>
    <p>
        These declarations cause the appropriate code to be generated and executed by the
        page compiler in the event that the control is created as a result of a cache miss.
        User control developers can then access these settings just as they would in a non-cached
        user control scenario.
    </p>
    <a name="api"></a>
    <h3>
        Fragment Caching API <span class="newinline">New in 2.0</span></h3>
    <p>
        In addition to using the <code>@ OutputCache</code> directive, you can now programatically
        adjust the caching options for user controls using the CacheAPI.
        In the following example, the control varies the time its cached for based on the
        state that is selected in the dropdown. You can see the time the control was rendered
        and the time when the cache entry will be cleared.
    </p>
        <Acme:LangSwitch ID="LangSwitch1" runat="server">
        <cstemplate>
<Acme:SourceRef
  RunSample="../../samples/caching/fragment/fragmentcache2_cs.aspx"
  ViewSource="~/aspnet/samples/caching/fragment/fragmentcache2.src"
  Caption="C# Fragment Cache API"
  runat="server" />
  </cstemplate>
        <vbtemplate>
<Acme:SourceRef
  RunSample="../../samples/caching/fragment/fragmentcache2_vb.aspx"
  ViewSource="~/aspnet/samples/caching/fragment/fragmentcache2.src"
  Caption="VB Fragment Cache API"
  runat="server" />
  </vbtemplate>
    </Acme:LangSwitch>

</asp:Content>
