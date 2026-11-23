<%@ Control Language="VB" ClassName="WordCountControl" %>
<%@ Import Namespace="Microsoft.Sample.WebParts" %>
<script runat="server">
Private _provider As IWordCount


<ConnectionConsumer("Word Count Consumer", "WordCountConsumer")>  _
Public Sub GetInterfaceForConnection(ByVal provider As IWordCount) 
    _provider = provider

End Sub 'GetInterfaceForConnection


Protected Sub Page_PreRender(ByVal sender As Object, ByVal e As EventArgs) 
    If _provider Is Nothing Then
        Me.wordcount.Text = "The current word count is 0"
    Else
        Me.wordcount.Text = "The current word count is " + _provider.WordCount.ToString()
    End If

End Sub 'Page_PreRender
</script>
<asp:Label runat=server ID=wordcount></asp:Label>