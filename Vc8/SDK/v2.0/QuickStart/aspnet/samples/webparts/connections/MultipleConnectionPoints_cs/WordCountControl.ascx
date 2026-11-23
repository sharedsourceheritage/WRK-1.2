<%@ Control Language="C#" ClassName="WordCountControl" %>
<%@ Import Namespace="Microsoft.Sample.WebParts" %>

<script runat="server">
    private IWordCount _provider;
    
    [ConnectionConsumer ("Word Count Consumer","WordCountConsumer") ]
    public void GetInterfaceForConnection(IWordCount provider)
    {
        _provider = provider;
    }

    protected void Page_PreRender(object sender, EventArgs e)
    {
        if (_provider == null)
            this.wordcount.Text = "The current word count is 0";
        else
            this.wordcount.Text = "The current word count is " + _provider.WordCount.ToString();
    }
</script>

<asp:Label runat=server ID=wordcount></asp:Label>
