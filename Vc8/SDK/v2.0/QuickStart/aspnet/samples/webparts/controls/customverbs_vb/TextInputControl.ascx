<%@ Control Language="VB" %>
<%@ Implements Interface="System.Web.UI.WebControls.WebParts.IWebPart" %>
<%@ Import Namespace="System.Web.UI.WebControls.WebParts" %>

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
  
</script>
<asp:Label ID="Label1" Text="Enter Text: " Runat="server" />
<asp:TextBox ID="TextBox1" Runat="server" />
<br />
<asp:Button ID="Button1" Text="Button" Runat="server" />
