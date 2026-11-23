<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>
    
  <h2>ADO.NET: Filter Data</h2>
    
    <br /><br />There are many ways to filter data. One way is to filter data at the database command level, using a where clause on your query. A second way is to filter the data after it is in the DataSet. This topic covers filtering in the DataSet.
    <br /><br />
    Once data is in a DataSet you can use methods on the DataSet to get at subsets of that data. 
    
    <h5>Filtering with the Select method</h5>
    <br /><br />
    Consider a DataSet with Customers and Orders tables.  To filter on Data for Customers with the FirstName of Kelly, you can use the <b>Select</b> method, which returns an array of rows.
    <br /><br />
    
    <Acme:TabControl runat="server">
    <Tab Name="C#">
    myRowArray = dsCustomers.Select("ContactName like 'Kelly%'");
    </Tab>
    <Tab Name="VB">
    myRowArray = dsCustomers.Select("ContactName like 'Kelly%'")
    </Tab>
    <Tab Name="C++">
    myRowArray = dsCustomers->Select("ContactName like 'Kelly%'");
    </Tab>
    </Acme:TabControl>
    
    <br /><br />
    Notice that the statements are ANSI-SQL like. They are essentially a subset of ANSI-SQL, with the following difference: because the DataSet can hold multiple related tables, the filter can also filter over these related tables. In the following example, use the <b>Child</b> keyword to filter the orders and the customers.
    <br /><br />
    
    
    <Acme:TabControl runat="server">
    <Tab Name="C#">
    myRowArray = dsCustomers.Select("ContactName like 'Kelly%' AND [child].OrderDate = '7/26/68'");
    </Tab>
    <Tab Name="VB">
    myRowArray = dsCustomers.Select("ContactName like 'Kelly%' AND [child].OrderDate = '7/26/68'")
    </Tab>
    <Tab Name="C++">
    myRowArray = dsCustomers->Select("ContactName like 'Kelly%' AND [child].OrderDate = '7/26/68'");
    </Tab>
    </Acme:TabControl>
    
    
    <br /><br />
    These functions return an array of rows. You can iterate through the array using the <b>foreach</b> statement.
    
    <h5>Filtering and Sorting with DataViews</h5>
    <br /><br />
    With the <b>DataView</b> object, you can place multiple filters on a DataSet, set up databinding to them, and so forth. A <b>DataView</b> can be filtered using the same query language rules as in the <b>Select</b>, but the filter is dynamic. Therefore, if a row is added to the data, and it qualifies with the filter, it is visible in the view. Views can be sorted and filtered. Filters include data filters and version filters (Current, New, Modified, Deleted). To set up a <b>DataView</b>, construct it by handing it a DataTable within a DataSet:
    <br /><br />
    
    <Acme:TabControl runat="server">
    <Tab Name="C#">
    DataView myDataView = new DataView(myDataSet.Tables["Customers"]);
    </Tab>
    <Tab Name="VB">
    Dim myDataView As DataView = New DataView(myDataSet.Tables("Customers"))
    </Tab>
    <Tab Name="C++">
    DataView * myDataView = new DataView(myDataSet->Tables->Item["Customers"]);
    </Tab>
    </Acme:TabControl>
    
    <br /><br />
    You can set up a filter with the <b>RowFilter</b> property using the same query filter language as in the example for the <b>Select</b> method above. To set up a sort, use a comma-delimited list of column sorts, followed by ASC (default and optional) or DESC for ascending and descending order.
    <br /><br />
    
    
    <Acme:TabControl runat="server">
    <Tab Name="C#">
    // Sort the view based on the FirstName column
    myDataView.Sort = "CustomerID";
    
    // Filter the dataview to only show customers with the CustomerID of ALFKI
    myDataView.RowFilter = "CustomerID='ALFKI'";
    </Tab>
    <Tab Name="VB">
    ' Sort the view based on the FirstName column
    myDataView.Sort = "CustomerID"
    
    ' Filter the dataview to only show customers with the CustomerID of ALFKI
    myDataView.RowFilter = "CustomerID='ALFKI'"
    </Tab>
    <Tab Name="C++">
    // Sort the view based on the FirstName column
    myDataView->Sort = "CustomerID";
    
    // Filter the dataview to only show customers with the CustomerID of ALFKI
    myDataView->RowFilter = "CustomerID='ALFKI'";
    </Tab>
    </Acme:TabControl>
    
    <br /><br />
    You can also filter based on the state of the rows (deleted, new, and so forth). Here is an example of a Filter on Deleted rows:
    <br /><br />
    
    <Acme:TabControl runat="server">
    <Tab Name="C#">
    myDataView.RowStateFilter = DataViewRowState.Deleted;
    </Tab>
    <Tab Name="VB">
    myDataView.RowStateFilter = DataViewRowState.Deleted
    </Tab>
    <Tab Name="C++">
    myDataView->RowStateFilter = DataViewRowState.Deleted;
    </Tab>
    </Acme:TabControl>
    
    
    <br /><br />
    The following sample demonstrates filling a DataSet, and then filtering it with a <b>DataView</b>. Note that a <b>DataView</b> can easily be data bound. See the databinding topics in Windows Forms or ASP.NET.
    
    <br /><br />
    
    <Acme:LangSwitch runat="server">
      <CsTemplate>
    <Acme:SourceRef
      RunSample="../../samples/adoplus/filterdatatable/cs/filterdatatable/filterdatatable.aspx"
      ViewSource="~/howto/samples/adoplus/filterdatatable/filterdatatable.src"
      Icon="../../../images/genicon.gif"
      Caption="C# FilterDataTable.aspx"
      SamplePath="howto\samples\adoplus\filterdatatable\"
      CanBeHosted="false"
      runat="server" />
      </CsTemplate>
      <VbTemplate>
    <Acme:SourceRef
      RunSample="../../samples/adoplus/filterdatatable/vb/filterdatatable/filterdatatable.aspx"
      ViewSource="~/howto/samples/adoplus/filterdatatable/filterdatatable.src"
      Icon="../../../images/genicon.gif"
      Caption="VB FilterDataTable.aspx"
      SamplePath="howto\samples\adoplus\filterdatatable\"
      CanBeHosted="false"
      runat="server" />
      </VbTemplate>
      <CpTemplate>
    <Acme:SourceRef
      RunSample=""
      ViewSource="~/howto/samples/adoplus/filterdatatable/filterdatatable.src"
      Icon="../../../images/genicon.gif"
      SamplePath="howto\samples\adoplus\filterdatatable\"
      CanBeHosted="false"
      Caption="C++ FilterDataTable.exe"
      runat="server" />
      </CpTemplate>
 	<VjsTemplate>
       <Acme:SourceRef
        RunSample=""
        ViewSource=""
        Icon = ""
        Caption=""
        CanBeHosted="false"
        runat="server" />
  	</VjsTemplate>
    </Acme:LangSwitch>
    
    
    <br /><br />
    
    </asp:Content>
