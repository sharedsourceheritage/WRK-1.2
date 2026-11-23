<%@ Page Language="C#" MasterPageFile="~/howto/howto.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h4>How Do I...Enilst on a transaction?</h4>

<p>
If you want to build a resource manager or simply vote on the outcome of a transaction you'll need to enlist on that transaction.  Enlisting allows you to receive transaction notifications and take appropriate action.
<p>
There are two steps to enlist on a transaction:
<ul>
<li>First, you will need to enlist on a transaction.  If your enlistment will not log state information and cannot recover from a failure, call the EnlistVolatile method on the Transaction object.  If your enlistment will log state information and can recover from a failure, call the EnlistDurable method on the Transaction object.</li>
<li>Second, your enlistment will need to implement the IEnlistmentNotification interface.  The methods implemented will be called for each of the possible transaction notifications:  Prepare, Commit, Rollback, and InDoubt.</li>
</ul>
<p>Here is a full example:
<Acme:LangSwitch runat="server">
  <CsTemplate>
<Acme:SourceRef
ViewSource="~/howto/samples/transactions/VolatileEnlist/VolatileEnlist.src"
SamplePath="howto\samples\Transactions\VolatileEnlist"
MapRunSamplePath=true
runat="server" />
  </CsTemplate>
  <VbTemplate>
<Acme:SourceRef
ViewSource="~/howto/samples/transactions/VolatileEnlist/VolatileEnlist.src"
SamplePath="howto\samples\Transactions\VolatileEnlist"
MapRunSamplePath=true
runat="server" />
  </VbTemplate>
</Acme:LangSwitch>
</asp:Content>