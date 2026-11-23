<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4>How Do I...Use transactions across threads?</h4>

<p>
If you want to start asynchronous threads and have them participate in a transaction, use the DepedentTransaction object.  DependentTransction objects can be obtained by called the DependentClone method on a Transaction object.  A thread can use a DependentTransaction in a TransactionScope or use the transaction explicitly to perform transacted work.  When the thread is done with the transaction, it simply calls the complete method on the DependentTransaction.  In case of failure, the rollback method can be called.
<p>
The code starting the thread has two options when using a DependentClone:
<ul>
<li>BlockCommitUntilComplete:  The transaction will not commit until the Complete method is called on the DependentTransaction or the transaction times out, even if the commit method is called on the transaction.  Choose this option if you want to wait for the thread to finish before committing the transaction but don't want to manually track when the thread is complete.</li>
<li>RollbackIfNotComplete:  The transaction will rollback if the Commit method is called on the transaction before the Complete method is called on the DepedentTransaction.  Choose this option if you expect the thread to be done when you call commit.  The transaction will be aborted if the thread is not done with it's transacted work before Commit is called.</li>
</ul>
1.  Create a DependentClone of the transaction you want to do work on in another thread
<Acme:TabControl runat="server">
<Tab Name="C#">
	DependentTransaction MyDependentTx = MyTx.DependentClone(DependentCloneOption.BlockCommitUntilComplete));
</Tab>
<Tab Name="VB">
	Dim MyDependentTx as DependentTransaction
	MyDependentTx = MyTx.DependentClone(DependentCloneOption.BlockCommitUntilComplete))
</Tab>
</Acme:TabControl>
<p>

2.  In the thread, pass the dependent transaction to a TransactionScope object, do work within that TransactionScope and call complete on the TransactionScope.  Once the thread is finished with all work on the transaction, call complete on the DependentTransaction object.
<Acme:TabControl runat="server">
<Tab Name="C#">
	private static void WorkerThread(object transaction)
	{
		DependentTransaction dTx = (DependentTransaction)transaction;
	
		using (TransactionScope ts = new TransactionScope(dTx))
		{
			//Perform transactional work here.
	
			//Call complete on the transaction scope
			ts.Complete();
		}
	
		//Call complete on the dependent transaction
		dTx.Complete();
	}
</Tab>
<Tab Name="VB">
        Public Shared Sub WorkerThread(ByVal myTransaction As Object)

            Dim dTx As DependentTransaction
            dTx = CType(myTransaction, DependentTransaction)

            Using ts As TransactionScope = New TransactionScope(dTx)
                'Perform transactional work here.

                'Call complete on the transaction scope
                ts.Complete()
            End Using
            'Call complete on the dependent transaction
            dTx.Complete()
        End Sub
</Tab>
</Acme:TabControl>

<p>Here is a full example:
<Acme:LangSwitch runat="server">
  <CsTemplate>
<Acme:SourceRef
ViewSource="~/howto/samples/transactions/DependentTx/DependentTx.src"
SamplePath="howto\samples\Transactions\DependentTx"
MapRunSamplePath=true
runat="server" />
  </CsTemplate>
  <VbTemplate>
<Acme:SourceRef
ViewSource="~/howto/samples/transactions/DependentTx/DependentTx.src"
SamplePath="howto\samples\Transactions\DependentTx"
MapRunSamplePath=true
runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
</asp:Content>