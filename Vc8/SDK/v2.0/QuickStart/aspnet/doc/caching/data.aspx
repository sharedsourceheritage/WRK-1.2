<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix="Acme" Namespace="Acme" %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx" %>
<asp:Content ID="Content1" ContentPlaceHolderID="MainBody" runat="Server">
    <h2>
        Caching Page Data</h2>
    <p>
        ASP.NET provides a full-featured cache engine that can be used by pages to store
        and retrieve arbitrary objects across HTTP requests. The ASP.NET cache is private
        to each application and stores objects in memory. The lifetime of the cache is equivalent
        to the lifetime of the application; that is, when the application is restarted,
        the cache is recreated.
    </p>
    <p>
        The cache provides a simple dictionary interface that allows programmers to easily
        place objects in and retrieve them from the cache. In the simplest case, placing
        an item in the cache is just like adding an item to a dictionary:
    </p>
    <Acme:TabControl runat="server">
        <tab name="C#">
Cache["mykey"] = myValue;</tab>
        <tab name="VB">
Cache("mykey") = myValue</tab>
    </Acme:TabControl>
    <p>
        Retrieving the data is just as simple. The existence of the object should be checked
        before retrieving the data from the cache as shown in the example below:
    </p>
    <Acme:TabControl runat="server">
        <tab name="C#">
myValue = Cache["mykey"];
if(myValue != null ) {
    DisplayData(myValue);
}
</tab>
        <tab name="VB">
myValue = Cache("mykey")
If Not (myValue Is Nothing) Then
    DisplayData(myValue)
End If
</tab>
    </Acme:TabControl>

    <a name="using"></a>
    <h3>
        Using the Data Cache</h3>
    <p>
        The following sample shows a simple use of the cache. It executes a database query
        and caches the result, which it continues to use for the lifetime of the application.
        When you run the sample, note the message at the bottom of the page. When first
        requested, it indicates that the data was explicitly retrieved from the database
        server. After refreshing the page, the page notes that the cached copy was used.
    </p>
    <Acme:LangSwitch runat="server">
        <cstemplate>
<Acme:SourceRef
  RunSample="../../samples/caching/API/datacache1_cs.aspx"
  ViewSource="~/aspnet/samples/caching/API/datacache1.src"
  Caption="C# Data Cache"
  runat="server" />
  </cstemplate>
        <vbtemplate>
<Acme:SourceRef
   RunSample="../../samples/caching/API/datacache1_vb.aspx"
  ViewSource="~/aspnet/samples/caching/API/datacache1.src"
  Caption="VB Data Cache"
  runat="server" />
  </vbtemplate>
    </Acme:LangSwitch>
    <p>
        The next example shows a cache item that depends on an XML file. It is similar
    to the first example, although in this case the data is retrieved from an XML data
    source instead of a database server. When the data is cached, the XML file is added
    as a dependency.

        When a new record is added using the form at the bottom of the page, the XML
    file is updated and the cached item must be recreated.
    </p>
        <Acme:LangSwitch runat="server">
            <cstemplate>
<Acme:SourceRef
   RunSample="../../samples/caching/API/datacache2_cs.aspx"
  ViewSource="~/aspnet/samples/caching/API/datacache2.src"
  Caption="C# Data Cache 2"
  runat="server" />
  </cstemplate>
            <vbtemplate>
<Acme:SourceRef
   RunSample="../../samples/caching/API/datacache2_vb.aspx"
  ViewSource="~/aspnet/samples/caching/API/datacache2.src"
  Caption="VB Data Cache 2"
  runat="server" />
  </vbtemplate>
          
        </Acme:LangSwitch>
        <p>
            Note that a file dependency is added by using <code>Cache.Insert</code> and supplying
            a <code>CacheDependency</code>
    object referencing the XML file. The same mechanism can be used for custom dependencies.
    </p>
        <Acme:TabControl runat="server">
        <tab name="C#">
Cache.Insert("MyData", Source,
         new CacheDependency(Server.MapPath("authors.xml")));
</tab>
        <tab name="VB">
Cache.Insert("MyData", Source, _
         New CacheDependency(Server.MapPath("authors.xml")))
</tab>
        </Acme:TabControl>
    <p>
        A cache item can depend on a single or multiple files or keys. As mentioned
    previously, an application can also set expiration policy on a cache item. The following
    code sets an absolute cache expiration time.
    </p>
        <Acme:TabControl runat="server">
        <tab name="C#">
Cache.Insert("MyData", Source, null,
             DateTime.Now.AddHours(1), TimeSpan.Zero);
</tab>
        <tab name="VB">
Cache.Insert("MyData", Source, Nothing, _
             DateTime.Now.AddHours(1), TimeSpan.Zero)
</tab>
        </Acme:TabControl>
    <p>
        The relevant parameter is the call to <b>DateTime.Now.AddHours(1)</b>, which indicates
        that the item expires 1 hour from the time it is inserted. The final argument, <b>TimeSpan.Zero</b>
    indicates that there is no relative expiration policy on this item.
    </p><p>
        The following code shows how to set a relative expiration policy. It inserts an
        item that expires 20 minutes after it is last accessed. Note the use of <b>DateTime.MaxValue</b>
    , which indicates that there is no absolute expiration policy on this item.
    </p>
        <Acme:TabControl runat="server">
        <tab name="C#">
Cache.Insert("MyData", Source, null, DateTime.MaxValue,
             TimeSpan.FromMinutes(20));
</tab>
        <tab name="VB">
Cache.Insert("MyData", Source, Nothing, DateTime.MaxValue, _
             TimeSpan.FromMinutes(20))
</tab>

        </Acme:TabControl>
   
    <p>
        For applications that need more sophisticated functionality, the ASP.NET cache supports
        scavenging, expiration, and file and key dependencies.
    </p>
    <a name="scavenging"></a>
    <h3>
        Scavenging Cache Entries</h3>
    <p>
        Scavenging means that the cache attempts to remove infrequently used or unimportant
        items if memory becomes scarce. Programmers who want to control how scavenging occurs
        can provide hints to the scavenger when items are inserted into the cache that indicate
        the relative cost of creating the item and the relative rate at which the item must
        be accessed to remain useful.
    </p>
    <a name="expiration"></a>
    <h3>
        Expiration of Cache Entries</h3>
    <p>
        Expiration allows programmers to give cache items lifetimes, which can be explicit
        (for example, expire at 6:00) or can be relative to an item's last use (for example,
        expire 20 minutes after the item was last accessed). After an item has expired,
        it is removed from the cache and future attempts to retrieve it return the null
        value unless the item is reinserted into the cache.
    </p>
    <a name="dependencies"></a>
    <h3>
        Cache Dependencies</h3>
    <p>
        Cache dependencies allow the validity of a cache item to be based on an external
        file or on another cache item. If a dependency changes, the cache item is invalidated
        and removed from the cache.
        For an example of how you might use this functionality, consider the following scenario:
        an application reads financial information from an XML file that is periodically
        updated. The application processes the data in the file and creates a graph of objects
        that represent that data in a consumable format. The application caches that data
        and inserts a dependency on the file from which the data was read. When the file
        is updated, the data is removed from the cache and the application can reread it
        and reinsert the updated copy of the data.
    </p>
  
    ASP.NET 2.0 has opened the <b>System.Web.Caching.CacheDependency</b> class for derivation,
    enabling anyone to write their own implementation of a cache dependency. By developing
    your own cache dependency, you can take advantage of the cache invalidation mechanism
    to keep the cached content current with the data that was used to construct it.
    This is a more efficient and reliable way to ensure data validity and enable cache
    synchronization across web farms than using frequent expiration.
    </p> <p>
    ASP.NET provides two dependency types built on top of CacheDependency: <b>AggregateCacheDependency</b>,
    which allows multiple dependencies to be aggregated for complex content types that
    depend on more then one type of resource, and <b>SqlCacheDependency</b>, which is
    described in <a href="SQLInvalidation.aspx">SQL Cache Invalidation</a>.
  

</asp:Content>
