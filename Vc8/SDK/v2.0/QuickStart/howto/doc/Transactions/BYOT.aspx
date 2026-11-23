<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4>How Do I...Use System.Transactions with EnterpriseServices Transactions?</h4>

<p>
System.Transactions provides functionality that allows interoperability with EnterpriseServices transactions.  This sample will show how to use BYOT (Bring Your Own Transactions) with System.Transactions.
<p>

<h5>What is BYOT?</h5>
BYOT allows a component to be created with, or to inherit, an external transaction. That is, a component that does not already have an associated transaction can acquire a transaction. This is done by setting an arbitrary pre-existing transaction as the transaction property of a new component's context.  In this case this is the transactions started with System.Transactions.
<p>
Convert the transaction:<br>
Because it is necessary to use the BYOT functionality provided by the System.EnterpriseServices namespace, you must first convert the current transaction to be of the System.EnterpriseServices.Itransaction type. This can be done by the static TransactionInterop.GetDtcTransaction method as follows.
<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
	System.EnterpriseServices.ITransaction estx = null;
	estx = (System.EnterpriseServices.ITransaction) TransactionInterop.GetDtcTransaction(Transaction.Current);
</Tab>
<Tab Name="VB">
	Dim estx As System.EnterpriseServices.ITransaction
	estx = CType(TransactionInterop.GetDtcTransaction(Transaction.Current), System.EnterpriseServices.ITransaction)
</Tab>
</Acme:TabControl>
<p>
Associate a component with the transaction:<br>
You can use the CreateWithTransaction method of the System.EnterpriseServices.BYOT class to do the actual work. In this case, an object, SvcComp, inheriting from System.EnterpriseServices.ServicedComponent will receive a reference to the requested transaction.
<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
	SvcComp sc = (SvcComp) BYOT.CreateWithTransaction(estx, typeof(SvcComp));
</Tab>
<Tab Name="VB">
	Dim sc As SvcComp = New SvcComp
	System.EnterpriseServices.BYOT.CreateWithTransaction(estx, sc.GetType)
</Tab>
</Acme:TabControl>
<p>
Obtain context information for the component:<br>
Next, the System.EnterpriseServices.ContextUtil class is used to obtain information about the context of the object that inherits this transaction. Specifically, the sample must determine the GUID of the current transaction, and whether the current context is transactional. The following properties are used to obtain this information.
<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
	Console.WriteLine("IsInTransaction   {0}", ContextUtil.IsInTransaction);
	Console.WriteLine("TransactionId     {0}", ContextUtil.TransactionId);
</Tab>
<Tab Name="VB">
	Console.WriteLine("IsInTransaction   {0}", ContextUtil.IsInTransaction)
	Console.WriteLine("TransactionId     {0}", ContextUtil.TransactionId)
</Tab>
</Acme:TabControl>

<p>Here is a full example:

<Acme:LangSwitch runat="server">
  <CsTemplate>
<Acme:SourceRef
ViewSource="~/howto/samples/transactions/byot/byot.src"
SamplePath="howto\samples\Transactions\byot"
MapRunSamplePath=true
runat="server" />
  </CsTemplate>
  <VbTemplate>
<Acme:SourceRef
ViewSource="~/howto/samples/transactions/byot/byot.src"
SamplePath="howto\samples\Transactions\byot"
MapRunSamplePath=true
runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<p>
</asp:Content>