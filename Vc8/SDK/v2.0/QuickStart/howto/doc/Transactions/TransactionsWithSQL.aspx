<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4>How Do I...Use System.Transactions with SQL?</h4>

<p>
The easiest way to perform SQL operations in a transaction is with TransactionScope.  Simply place all the SQL operations you want to execute within a TransactionScope block.  The TransactionScope object will set the current transaction which SQL will automatically find when you execute SQL statements.  If you need more than one SQL database in a single transaction, open a second connection and execute operations against it.  The second connection will also automatically find the current transaction.
<p>
<Acme:TabControl runat="server">
<Tab Name="C#">
	try
	{
		using (TransactionScope ts = new TransactionScope())
		{
			using (SqlConnection myConnection = new SqlConnection("server=(local)\\SQLExpress;Integrated Security=SSPI;database=northwind"))
			{
				SqlCommand myCommand = new SqlCommand();
				myConnection.Open();
				myCommand.Connection = myConnection;
			
				//Perform SQL work using myConnection.
			}
	
			ts.Complete();
		}
	}
	catch(System.Transactions.TransactionException ex)
	{
		Console.WriteLine(ex);
	}
	catch
	{
		Console.WriteLine("Cannot complete transaction");
		throw;
	}
</Tab>
<Tab Name="VB">
	Try
		Using scope As TransactionScope = New TransactionScope()

			Using myConnection As New SqlConnection("server=(local)\SQLExpress;Integrated Security=SSPI;database=northwind")
				Dim myCommand As New SqlCommand()
				myConnection.Open()
				myCommand.Connection = myConnection
			End Using
	
			scope.Complete()
		End Using
        Catch ex As TransactionException
        	Console.WriteLine(ex)
        Catch
        	Console.WriteLine("Cannot complete transaction")
                Throw
	End Try

</Tab>
</Acme:TabControl>
<p>Here is a full example:

<Acme:LangSwitch runat="server">
  <CsTemplate>
<Acme:SourceRef
ViewSource="~/howto/samples/transactions/ScopeWithSQL/ScopeWithSQL.src"
SamplePath="howto\samples\Transactions\ScopeWithSQL"
MapRunSamplePath=true
runat="server" />
  </CsTemplate>
  <VbTemplate>
<Acme:SourceRef
ViewSource="~/howto/samples/transactions/ScopeWithSQL/ScopeWithSQL.src"
SamplePath="howto\samples\Transactions\ScopeWithSQL"
MapRunSamplePath=true
runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
<p>
<p>
If you want to manually create and pass the transaction to SQL, use the CommittableTransaction object.  You can enlist SQL in the transaction by passing the transaction to the EnlistTransaction method on the SQLConnection object.  You will need to call commit or rollback on the transaction and handle exceptions.
<Acme:TabControl runat="server">
<Tab Name="C#">
	CommittableTransaction tx = new CommittableTransaction();

	using (SqlConnection myConnection = new SqlConnection("server=(local)\\SQLExpress;Integrated Security=SSPI;database=northwind"))
	{
		myConnection.Open();

		//Give the transaction to SQL to enlist with
		myConnection.EnlistTransaction(tx);
	}

</Tab>
<Tab Name="VB">
           Dim tx As New CommittableTransaction()

           Using myConnection As New SqlConnection("server=(local)\SQLExpress;Integrated Security=SSPI;database=northwind")
           		myConnection.Open()

           		'Give the transaction to SQL to enlist with
           		myConnection.EnlistTransaction(tx)
           End Using
</Tab>
</Acme:TabControl>
<p>
Here is a full example:
<Acme:LangSwitch runat="server">
  <CsTemplate>
<Acme:SourceRef
ViewSource="~/howto/samples/transactions/CommittableTxWithSQL/CommittableTxWithSQL.src"
SamplePath="howto\samples\Transactions\CommittableTxWithSQL"
MapRunSamplePath=true
runat="server" />
  </CsTemplate>
  <VbTemplate>
<Acme:SourceRef
ViewSource="~/howto/samples/transactions/CommittableTxWithSQL/CommittableTxWithSQL.src"
SamplePath="howto\samples\Transactions\CommittableTxWithSQL"
MapRunSamplePath=true
runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
</asp:Content>