<%@ Control Language="VB" %>
<%@ Implements Interface="System.Web.UI.WebControls.WebParts.IWebPart" %>
<%@ Implements Interface="Microsoft.Sample.WebParts.ITextCommunication" %>
<%@ Import Namespace="System.Web.UI.WebControls.WebParts" %>
<%@ Import Namespace="Microsoft.Sample.WebParts" %>

<script runat="server">

  Private _catalogImageUrl As String = String.Empty
  Private _description As String = String.Empty
  Private _subTitle As String = "[0]"
  Private _title As String = "Super cool user control "

  Public Property CatalogIconImageUrl() As String Implements IWebPart.CatalogIconImageUrl
    Get
      Return _catalogImageUrl
    End Get
    Set(ByVal value As String)
      _catalogImageUrl = value
    End Set
  End Property

  Public Property Description() As String Implements IWebPart.Description
    Get
      Return _description
    End Get
    Set(ByVal value As String)
      _description = value
    End Set
  End Property
  
  Public ReadOnly Property Subtitle() As String Implements IWebPart.Subtitle
    Get
      Return String.Empty
    End Get
  End Property
  
  Public Property Title() As String Implements IWebPart.Title
    Get
      Return _title
    End Get
    Set(ByVal _title As String)
    End Set
  End Property

  Public Property TitleIconImageUrl() As String Implements IWebPart.TitleIconImageUrl
    Get
      Return String.Empty
    End Get
    Set(ByVal _title As String)
    End Set
  End Property

  Public Property TitleUrl() As String Implements IWebPart.TitleUrl
    Get
      Return String.Empty
    End Get
    Set(ByVal _title As String)
    End Set
  End Property
  
  ReadOnly Property Text() As String Implements ITextCommunication.Text
    Get
      Return Me.TextBox1.Text
    End Get
  End Property
  
    <ConnectionProvider("TextProvider", "Text Provider")> _
    Public Function ProvideInterfaceForConnection() As ITextCommunication
        Return Me
    End Function
  
</script>
<asp:Label ID="Label2" Text="Enter Text: " Runat="server" />
<asp:TextBox ID="TextBox1" Runat="server" />
<br />
<asp:Button ID="Button2" Text="Button" Runat="server" />
