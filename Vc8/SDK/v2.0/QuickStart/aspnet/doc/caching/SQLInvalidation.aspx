<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx" %>
<%@ Register TagPrefix="Acme" Namespace="Acme" %>
<asp:Content ID="Content1" ContentPlaceHolderID="MainBody" runat="Server">
  <h2>
        SQL Cache Invalidation <span class="newinline">New in 2.0</span></h2>
    <p>
        In the previous example, the data was cached for 60 seconds, regardless of whether
        the data has changed in the database. SQL cache invalidation enables you to make
        the cache entry dependent on the database, so the cache entry will only be cleared
        when data in the database is changed.
    </p>

    <a name="polling"></a>
    <h3>
        Polling-based Invalidation</h3>
    <p>
        This mechanism uses polling to check if a table has been updated since the page
        was cached. To enable table based caching requires the following steps:
    </p>
    <table width="100%">
        <tr valign="top">
            <td>
                1)</td>
            <td>
                Enable notifications for the database using the aspnet_regsql.exe tool.
                <pre class="code">
&gt;aspnet_regsql.exe -S ".\SQLExpress" -E -d "pubs" -ed
</pre>
                This only needs to be done once for each database.<br /><br />
            </td>
        </tr>
        <tr valign="top">
            <td>
                2)</td>
            <td>
                Enable notifications for the table(s) you want to have dependencies on using the
                aspnet_regsql.exe tool.
                <pre class="code">
&gt;aspnet_regsql.exe -S ".\SQLExpress" -E -d "pubs" -et -t "authors"</pre>
            </td>
        </tr>
        <tr valign="top">
            <td>
                3)</td>
            <td>
                Register the notification in the configuration for the application.
                <pre class="code">
&lt;system.web&gt;
    &lt;caching&gt;
      &lt;sqlCacheDependency enabled="true" pollTime="1000" &gt;
        &lt;databases&gt;
          &lt;add name="PubsDB" connectionStringName="Pubs" /&gt;
        &lt;/databases&gt;
      &lt;/sqlCacheDependency&gt;
    &lt;/caching&gt;
&lt;/system.web&gt;</pre>
                The poll time specifies how often the application checks to see whether the data
                has changed.<br /><br />
            </td>
        </tr>
        <tr valign="top">
            <td>
                4)</td>
            <td>
                A SQL dependency can then be used on the OutputCache directive:
                <pre class="code">
&lt;%@ OutputCache Duration="999999" SqlDependency="Pubs:Authors" VaryByParam="none" %&gt;</pre>
                Or it can be specified directly on a datasource control:
                <pre class="code">
&lt;asp:SqlDataSource EnableCaching="true" CacheDuration="Infinite" SqlCacheDependency="PubsDB:Authors" ... /&gt;</pre>
            </td>
        </tr>
    </table>

        The following example uses output caching for a sql datasource using a table based
        notification. Watch the timestamp at the bottom of the application which should
        stay static. You can use the <a runat="server" href="~/aspnet/samples/Data/GridviewUpdating_vb.aspx"
            target="_blank">GridView example</a> to edit the data. Refreshing the page should
        then show the updated data and a new timestamp.
<br /><br />
    <Acme:LangSwitch ID="LangSwitch1" runat="server">
        <cstemplate>
        <Acme:SourceRef
        RunSample="../../samples/caching/cachedependency/cachedependency_cs/cachedependency.aspx"
        ViewSource="~/aspnet/samples/caching/cachedependency/CacheDependency.src"
        Caption="C# SqlCacheDependency"
        runat="server" />
  </cstemplate>
        <vbtemplate>
        <Acme:SourceRef
        RunSample="../../samples/caching/cachedependency/cachedependency_vb/cachedependency.aspx"
        ViewSource="~/aspnet/samples/caching/cachedependency/CacheDependency.src"
        Caption="VB SqlCacheDependency"
        runat="server" />
  </vbtemplate>
    </Acme:LangSwitch>
      
       <a name="notification"></a>
       <h3>Sql Server 2005 Notification-based Cache Invalidation</h3>

        This mechanism uses the query change notification mechanism of Sql Server 2005 to detect changes to the results 
        of queries. Unlike polling based invalidation for Sql Server 7.0 and 2000, notification based invalidation requires
        much less setup.
<br /><br />

<ol>
                <li>Unlike polling based validation, no <code>&lt;sqlCacheDependency&gt;</code> needs to be registered in your 
                application's configuration.  Furthermore, no special configuration using the aspnet_regsql.exe tool is
                needed.</li>
                <br /><br />

                <li>A notification based dependency is configured on the OutputCache directive using the string <b>
                CommandNotification</b>.  This value indicates to ASP.NET that a notification based dependency should be 
                created for the page or datasource control.
                <br /><br />
                <b>On a page:</b>
                <pre class="code">
&lt;%@ OutputCache Duration="999999" SqlDependency="CommandNotification" VaryByParam="none" %&gt;</pre>
                <b>On a datasource control:</b>
                <pre class="code">
&lt;asp:SqlDataSource EnableCaching="true" SqlCacheDependency="CommandNotification" CacheDuration="Infinite" ... /&gt;</pre>
</li>
				<li>System.Data.SqlClient.SqlDependency.Start() method must be called somewhere in the application before the first SQL query is executed.  This method could be placed in Application_Start() event in global.asax file.
</li>
</ol>

      Whenever a command is issued to Sql Server 2005, ASP.NET and ADO.NET will automatically create a cache dependency that listens 
      to change notifications sent from the Sql Server.  As data is changed in Sql Server, these notifications will cause the 
      cached queries to be invalidated on the web server.  The next time a page or datasource control associated with the 
      dependency is requested, the page or datasource control will be executed again as opposed to serving cached information.
      <br /><br />
      Common issues that prevent queries from working with Sql Server 2005 query notifications are:
<ol>
	<li>Queries must explicitly include column names in the SELECT statement. Using "SELECT *" results in a query
            that will not be registered with Sql Server 2005 query notifications.</li>
        <li>Table names in queries must include the ownername.  For example, if you issue a
            query against the authors table in the pubs database, the query must reference the
            table as "dbo.authors".</li>
        <li>The security identity running the query must have rights to register queries
            for notification in Sql Server 2005.  This right can be granted with the following T-SQL
            command: <code>GRANT SUBSCRIBE QUERY NOTIFICATIONS TO <i>username</i></code>.</li>
        <li>The security identity running the query must also have rights to send query
            notifications from Sql Server 2005.  This right can be granted with the following T-SQL
            command: <code>GRANT SEND ON SERVICE::SqlQueryNotificationService TO <i>username</i></code>.</li>
</ol>
      <b>Note:</b>  There are a number of restrictions on the syntax of queries that support query notifications.  For the list of 
      the specific constraints, please see the topic "Creating a Query for Notification" in the Sql Server 2005 Books Online.
      Also, if it appears that queries are not being cached, and instead are being executed on every page request, it is likely 
      that either the query does not follow the constraints required by Sql Server 2005, or that Sql Server 2005 generated an
      error when attempting to setup notifications for that query.  Currently, either of these conditions cause a silent failure 
      when attempting to setup a cache dependency in ASP.NET, with the end result being that the cache dependency is always invalid and hence
      any associated queries are always executed on each page request.



<%--
        Notification-based Invalidation</h3>
    <p>
        This mechanism uses the query change notification mechanism of the "Yukon" version
        of SQL Server to detect changes to the results of queries. To enable this mechanism, 
        set the SqlCacheDependency property to "CommandNotification" instead of a connection/table pair.
    </p>
--%>
        
</asp:content>
