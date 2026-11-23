<%@ Page Language="C#" MasterPageFile="~/aspnet/section.master" %>
<%@ Register TagPrefix=Acme Namespace=Acme %>
<%@ Register TagPrefix="Acme" TagName="SourceRef" Src="~/util/SrcRef.ascx"%>

<asp:Content ID="Content1" ContentPlaceHolderID=MainBody Runat=Server>

<h2>
<Acme:TypeRef TypeName="System.Web.UI.WebControls.FileUpload" runat="server">
  FileUpload
</Acme:TypeRef>
</h2>

The <b>FileUpLoad</b> control enables you to upload file to the server. It displays a text box control and a browse button that allow users to select a file to upload to the server.
<p>
The user specifies the file to upload by entering the fully qualified path to the file on the local computer (for example, "C:\MyFiles\TestFile.txt") in the text box of the control. Alternately, the user can select the file by clicking the Browse button and then locating it in the Choose File dialog box.

The <b>FileUpload</b> control does not automatically save a file to the server after the user selects the file to upload. You must explicitly provide a control or mechanism to allow the user to submit the specified file. For example, you can provide a button that the user clicks to upload the file. The code that you write to save the specified file should call the <b>SaveAs</b> method, which saves the contents of a file to a specified path on the server. Typically, the <b>SaveAs</b> method is called in an event-handling method for an event that raises a post back to the server. For example, if you provide a button to submit a file, you could place the code to save the file inside the event-handling method for the button's click event.



<br /><br />

<Acme:LangSwitch runat="server">
  <CsTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/FileUpload/FileUpload1_cs.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/FileUpload/FileUpload1.src"
        Caption="C# FileUpload1.aspx"
        runat="server" />
  </CsTemplate>
  <VbTemplate>
        <Acme:SourceRef
        RunSample="../../../samples/ctrlref/standard/FileUpload/FileUpload1_vb.aspx"
        ViewSource="~/aspnet/samples/ctrlref/standard/FileUpload/FileUpload1.src"
        Caption="VB FileUpload1.aspx"
        runat="server" />
  </VbTemplate>
</Acme:LangSwitch>

</asp:Content>
