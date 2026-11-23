<%@ Control Language="C#" ClassName="FragCtrlwithAPI" %>
<%@ OutputCache Duration="60" VaryByControl="pickstate" %>

<script runat="server">
    private TimeSpan duration;
    
    protected void Page_Load(object sender, EventArgs e)
    {        
        if (pickstate.SelectedValue == "CA")
        {
           duration = new TimeSpan(0, 0, 10);
           this.CachePolicy.Duration = duration;
        }
    }

    protected void Page_PreRender(object sender, EventArgs e)
    {
        Label1.Text = DateTime.Now.ToString("G");
        Label2.Text = DateTime.Now.Add(CachePolicy.Duration).ToString("G");
    }
</script>

<div style="border: dotted 1px blue; padding: 5px; background-color: #eeeeee;">
    <asp:DropDownList ID="pickstate" runat="server" AutoPostBack=true>
        <asp:ListItem Text="CA" Value="CA" />
        <asp:ListItem Text="UT" Value="UT" />
        <asp:ListItem Text="MD" Value="MD" />
        <asp:ListItem Text="OR" Value="OR" />
        <asp:ListItem Text="MI" Value="MI" />
        <asp:ListItem Text="TN" Value="TN" />
    </asp:DropDownList>
    <asp:SqlDataSource ID="SqlDataSource1" runat="server" ConnectionString="<%$ ConnectionStrings:Pubs %>"
        SelectCommand="SELECT [au_id], [au_lname], [au_fname], [phone], [address], [city], [state], [zip], [contract] FROM [authors] where state=@state"
        ProviderName="System.Data.SqlClient">
        <SelectParameters>
            <asp:ControlParameter ControlID="pickstate" DefaultValue="CA" Name="state" PropertyName="SelectedValue" />
        </SelectParameters>
    </asp:SqlDataSource>
    <asp:GridView ID="GridView1" runat="server" DataSourceID="sqldatasource1" />
    <p>
        Control rendered at <asp:Label ID="Label1" runat="server" Text="Label"/><br />
        Control will expire at <asp:Label ID="Label2" runat="server" Text="Label"/><br />      
    </p>
</div>
