<%@ Control Language="VB" ClassName="FragCtrlwithAPI" %>
<%@ OutputCache Duration="60" VaryByControl="pickstate" %>

<script runat="server">
    Private duration As TimeSpan
    
    Sub Page_Load(ByVal sender As Object, ByVal E As EventArgs)
        If (pickstate.SelectedValue = "CA") Then
            duration = New TimeSpan(0, 0, 10)
            CachePolicy.Duration = duration
        End If
    End Sub
  
    Sub Page_PreRender(ByVal sender As Object, ByVal e As EventArgs)
        Label1.Text = Now.ToString("G")
        Label2.Text = Now.Add(CachePolicy.Duration).ToString("G")
    End Sub
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
