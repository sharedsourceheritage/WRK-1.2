<%@ Control Language="C#" %>
<%@ Implements Interface="System.Web.UI.WebControls.WebParts.IWebPart" %>
<%@ Implements Interface="Microsoft.Sample.WebParts.ITextCommunication" %>
<%@ Import Namespace="Microsoft.Sample.WebParts" %>
<%@ Implements Interface=Microsoft.Sample.WebParts.IWordCount %>

<script runat="server">

    private String _catalogImageUrl = string.Empty;
    private String _description = string.Empty;
    private String _subTitle = "[0]";
    private String _title = "Super cool user control ";

    public String CatalogIconImageUrl
    {
        get { return _catalogImageUrl; }
        set { _catalogImageUrl = value; }
    }
    public String Description
    {
        get { return _description; }
        set { _description = value; }
    }
    public String Subtitle
    {
        get {return string.Empty; }
        set { ; }
    }
    public String Title
    {
        get { return _title; }
        set { _title = value; }
    }
    public String TitleIconImageUrl
    {
        get { return string.Empty; }
        set { ; }
    }
    public String TitleUrl
    {
        get { return string.Empty; }
        set { ; }
    }

    String ITextCommunication.Text
    {
        get { return this.TextBox1.Text; }
    }

    [ConnectionProvider("Text Provider")]
    public ITextCommunication ProvideInterfaceForConnection()
    {
        return this;
    }

    public int WordCount
    {
        get { 
            if (string.IsNullOrEmpty(TextBox1.Text))
                return 0;
            else
                return TextBox1.Text.Length;
            }
    }

    [ConnectionProvider("Word Count Provider", "WordCountProvider")]
    public IWordCount GetInterfaceForConnection()
    {
        return this;
    }

</script>

<asp:Label ID="Label1" Text="Enter Text: " Runat="server"/>
<asp:TextBox ID="TextBox1" Runat="server"/>
<br />
<asp:Button ID="Button1" Text="Button" Runat="server" />
