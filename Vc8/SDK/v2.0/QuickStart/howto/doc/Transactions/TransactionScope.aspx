<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4>How Do I...Use simple transactions in my application?</h4>

<p>
The easiest way to use transactions in your code is using TransactionScope.  TransactionScope is used to transact a block of code.  The follow code snippet uses TransactionScope in its simplest way.

<Acme:TabControl runat="server">
<Tab Name="C#">
	try
	{
	    using (TransactionScope ts = new TransactionScope())
	    {
	        //Do some transactional work
	        
	        //Call complete on the transaction scope
	        ts.Complete()
	    }
	}
	catch()
	{
	    //Handle exception
	}
</Tab>
<Tab Name="VB">
    Try
        Using scope As TransactionScope = New TransactionScope()
            'Do some transactional work

            'Call complete on the transaction scope
            scope.Complete()
        End Using
    Catch
        'Handle exception
    End Try
</Tab>
</Acme:TabControl>
<p>
There are a few important things to note about this code:
<ul>
    <li>
        The recommended way to use TranasctionScope is with the 'using' statement.  Within the using block, all operations with transacted resources will automatically be part of the transaction.
    </li>
    <li>
        Calling complete() on the TransactionScope object tells the system the transaction is ready to be committed.  Failing to call complete() on the TransactionScope will rollback the transaction.
    </li>
    <li>
        The transaction will automatically commit or abort at the end of the using block based on whether complete() was called or not.
    </li>
    <li>
        Wrap the entire block of code with a try..catch.  Any exceptions thrown within the using block will cause the transaction to rollback.  The exception will then get thrown for the application code to deal with.
    </li>
</ul>

<p>Here is a full example:
<Acme:LangSwitch runat="server">
  <CsTemplate>
<Acme:SourceRef
ViewSource="~/howto/samples/transactions/TransactionScopeSample/TransactionScopeSample.src"
SamplePath="howto\samples\Transactions\TransactionScopeSample"
MapRunSamplePath=true
runat="server" />
  </CsTemplate>
  <VbTemplate>
<Acme:SourceRef
ViewSource="~/howto/samples/transactions/TransactionScopeSample/TransactionScopeSample.src"
SamplePath="howto\samples\Transactions\TransactionScopeSample"
MapRunSamplePath=true
runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
</asp:Content>