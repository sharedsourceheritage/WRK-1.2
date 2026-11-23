<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4>How Do I...Use explicit transactions in my application?</h4>

<p>
If you want to explicitly create a transaction, use the CommittableTransaction class instead of the <a href="TransactionScope.aspx">TransactionScope</a> class.

There are important differences between CommittableTransaction objects and TransactionScope objects:
<ul>
<li>Creating a CommittableTransaction does not set the current transaction.  This means a transacted resource you might perform an action on will not automatically be part of the current transaction.  You will need to manually pass the transaction you created to the transacted resource.</li>
<li>When using CommittableTransactions, you must call commit or rollback.</li>
<li>Exceptions do not automatically rollback transactions.  Rollback must be called manually if a failure occurred when an exception is thrown.</li>
</ul>
<p>

1.  In it's simplest form, create a new CommittableTransaction
<Acme:TabControl runat="server">
<Tab Name="C#">
	CommittableTransaction tx = new CommittableTransaction();
</Tab>
<Tab Name="VB">
	Dim tx As New CommittableTransaction()
</Tab>
</Acme:TabControl>
<p>
2.  To commit the transaction, call the commit method
<Acme:TabControl runat="server">
<Tab Name="C#">
	tx.Commit();
</Tab>
<Tab Name="VB">
	tx.Commit()
</Tab>
</Acme:TabControl>
<p>
3.  Or to rollback the transaction, call the rollback method
<Acme:TabControl runat="server">
<Tab Name="C#">
	tx.Rollback();
</Tab>
<Tab Name="VB">
	tx.Rollback()
</Tab>
</Acme:TabControl>
<p>

<p>Here is a full example:
<Acme:LangSwitch runat="server">
  <CsTemplate>
<Acme:SourceRef
ViewSource="~/howto/samples/transactions/CommittableTx/CommittableTx.src"
SamplePath="howto\samples\Transactions\CommittableTx"
MapRunSamplePath=true
runat="server" />
  </CsTemplate>
  <VbTemplate>
<Acme:SourceRef
ViewSource="~/howto/samples/transactions/CommittableTx/CommittableTx.src"
SamplePath="howto\samples\Transactions\CommittableTx"
MapRunSamplePath=true
runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
</asp:Content>