<%@ Page Language="C#" MasterPageFile="~/webservices/webservices.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ContentPlaceHolderID="MainBody" Runat=Server>

<h2><b>Intrinsics (ASP.NET Session and Application State Management)</b></h2>
<br /><br />
ASP.NET Web Services allows you to access the underlying state management provided by ASP.NET.  To enable
ASP.NET session state, set WebMethod.EnableSession = True.  On the client you must also set serviceName.CookieContainer 
to a new instance of System.Net.CookieContainer.  This allows you to persist data within the same session.  Note that
to persist data for the entire application (for all incoming requests to the service), neither step is required.
<br /><br />
<b>Client-Side Code</b>

<br /><br /><Acme:TabControl runat="server">

<Tab Name="C#">
   //On the client you must add the following code (for session state only):
   serviceName.CookieContainer = new System.Net.CookieContainer();
</Tab>

<Tab Name="VB">
   'On the client you must add the following code (for session state only):
   serviceName.CookieContainer = new System.Net.CookieContainer()
</Tab>

<Tab Name="J#">
   //On the client you must add the following code (for session state only):
   serviceName.set_CookieContainer(new System.Net.CookieContainer());
</Tab>

</Acme:TabControl><br /><br />

<b>Server-Side Code</b>

<br /><br /><Acme:TabControl runat="server">

<Tab Name="C#">
   //Setting EnableSession to true allows state to be persisted per Session
   [WebMethod(EnableSession=true)]
   public String UpdateSessionHitCounter() {
      //update the session "HitCounter" here
      return Session["HitCounter"].ToString();
   }

   //Note that state can be persisted for the entire Application even if EnableSession is false
   [WebMethod(EnableSession=false)]
   public String UpdateApplicationHitCounter() {
      //update the application "HitCounter" here
      return Application["HitCounter"].ToString();
   } 
</Tab>

<Tab Name="VB">
   'Setting EnableSession to true allows state to be persisted per Session
   &lt;WebMethod(EnableSession:=True)> _
   Public Function UpdateSessionHitCounter() As String
      'update the session "HitCounter" here
      Return Session("HitCounter").ToString()
   End Function

   'Note that state can be persisted for the entire Application even if EnableSession is false
   &lt;WebMethod(EnableSession:=False)> _
   Public Function UpdateApplicationHitCounter() As String
      'update the application "HitCounter" here
      Return Application("HitCounter").ToString()
   End Function
</Tab>

<Tab Name="J#">
   //Setting EnableSession to true allows state to be persisted per Session
   /** @attribute WebMethod(EnableSession=true) */ 
   public String UpdateSessionHitCounter() 
   {
      HttpSessionState session = get_Session();
      //update the session "HitCounter" here
      return ((Integer)session.get_Item(0)).ToString();
   }

   //Note that state can be persisted for the entire Application even if EnableSession is false
   /** @attribute WebMethod(EnableSession=false) */ 
   public String UpdateApplicationHitCounter() 
   {
      HttpApplicationState application = get_Application();
      //update the application "HitCounter" here
      return ((Integer)application.get_Item(0)).ToString();
   } 
</Tab>

</Acme:TabControl><br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../samples/Intrinsics/cs/Client/SessionServiceClient.aspx"
        ViewSource="~/webservices/samples/Intrinsics/Intrinsics.src"
        Icon = "../../images/genicon.gif"
        Caption="C# Sample Caption"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../samples/Intrinsics/vb/Client/SessionServiceClient.aspx"
        ViewSource="~/webservices/samples/Intrinsics/Intrinsics.src"
        Icon = "../../images/genicon.gif"
        Caption="VB Sample Caption"
        runat="server" />
  </VbTemplate>
  <VjsTemplate>
        <Acme:SourceRef
        RunSample="../samples/Intrinsics/jsl/Client/SessionServiceClient.aspx"
        ViewSource="~/webservices/samples/Intrinsics/Intrinsics.src"
        Icon = "../../images/genicon.gif"
        Caption="J# Sample Caption"
        runat="server" />
  </VjsTemplate>
</Acme:LangSwitch>

</asp:Content>

