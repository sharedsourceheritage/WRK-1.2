<%@ Control Language="VB" ClassName="TextDisplay" %>
<%@ Import Namespace="Microsoft.Sample.WebParts" %>

<script runat="server">
    Private _textContent As String
    
    <Personalizable()> _
    Public Property TextContent() As String
        Get
            Return _textContent
        End Get
        Set(ByVal value As String)
            _textContent = value
        End Set
    End Property
 
  
    Protected Overrides Sub OnPreRender(ByVal e As EventArgs)
        Label1.Text = Me.textContent
        Dim viewIndex As Integer = 0
    
        Dim wpmg As WebPartManager = WebPartManager.GetCurrentWebPartManager(Me.Page)
        Dim myNewWpmg As NewWebPartManager
        myNewWpmg = CType(wpmg, NewWebPartManager)
       
        If Not (myNewWpmg Is Nothing) Then
            Dim mode As WebPartDisplayMode = myNewWpmg.SupportedDisplayModes(NewWebPartManager.InlineEdit.Name)
            If Not (mode Is Nothing) AndAlso myNewWpmg.DisplayMode Is mode Then
                viewIndex = 1
            End If
        End If
        Me.MultiView1.ActiveViewIndex = viewIndex

    End Sub 'OnPreRender
 

    Protected Sub Button1_Click(ByVal sender As Object, ByVal e As EventArgs)
        Me.TextContent = TextBox1.Text
    
        Dim wpmg As WebPartManager = WebPartManager.GetCurrentWebPartManager(Me.Page)
        Dim mode As WebPartDisplayMode = wpmg.SupportedDisplayModes(WebPartManager.BrowseDisplayMode.Name)
        If Not (mode Is Nothing) Then
            wpmg.DisplayMode = mode
        End If

    End Sub 'Button1_Click
</script>
<asp:MultiView ID="MultiView1" runat="server">
    <asp:View ID="View1" runat="server">
        <asp:Label ID="Label1" runat="server" Text="Label"></asp:Label></asp:View>
    <asp:View ID="View2" runat="server">
        <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox>
        <asp:Button ID="Button1" OnClick="Button1_Click" runat="server" Text="Button" /></asp:View>
</asp:MultiView>