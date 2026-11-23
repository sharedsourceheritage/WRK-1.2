<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4>How Do I...Get the outcome of a transaction?</h4>

<p>
Transaction outcome is handled through events.  To receive the outcome of a specific transaction you need to handle the TransactionCompletedEvent event which is on the Transaction object.
<p>
Here is an example of how to receive the TransactionCompletedEvent event:
<p>
1.  Register for the TransactionCompletedEvent for the transaction you want to receive the outcome for
<Acme:TabControl runat="server">
<Tab Name="C#">
	MyTx.TransactionCompleted += new TransactionCompletedEventHandler(Current_TransactionCompleted);
</Tab>
<Tab Name="VB">
	AddHandler MyTx.TransactionCompleted, AddressOf Current_TransactionCompleted
</Tab>
</Acme:TabControl>
<p>
2.  Within the handler you can access the outcome of the transaction by looking at the Status property on the TransactionInformation class.  This can be accessed from the TransactionEventArgs e, which is a Transaction object.
<Acme:TabControl runat="server">
<Tab Name="C#">
	static void Current_TransactionCompleted(object sender, TransactionEventArgs e)
	{
		Console.WriteLine("Status:         {0}", e.Transaction.TransactionInformation.Status);
		Console.WriteLine("ID:             {0}", e.Transaction.TransactionInformation.LocalIdentifier);
	}
</Tab>
<Tab Name="VB">
        Public Shared Sub Current_TransactionCompleted(ByVal sender As Object, ByVal e As TransactionEventArgs)
            Console.WriteLine("Status:         {0}", e.Transaction.TransactionInformation.Status)
            Console.WriteLine("ID:             {0}", e.Transaction.TransactionInformation.LocalIdentifier)
        End Sub
</Tab>
</Acme:TabControl>
<p>
<p>Here is a full example:
<Acme:LangSwitch runat="server">
  <CsTemplate>
<Acme:SourceRef
ViewSource="~/howto/samples/transactions/TxOutcome/TxOutcome.src"
SamplePath="howto\samples\Transactions\TxOutcome"
MapRunSamplePath=true
runat="server" />
  </CsTemplate>
  <VbTemplate>
<Acme:SourceRef
ViewSource="~/howto/samples/transactions/TxOutcome/TxOutcome.src"
SamplePath="howto\samples\Transactions\TxOutcome"
MapRunSamplePath=true
runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
</asp:Content>