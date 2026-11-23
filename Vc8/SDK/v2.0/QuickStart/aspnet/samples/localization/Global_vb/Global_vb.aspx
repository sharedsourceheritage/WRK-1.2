<%@ Page Language="VB" AutoEventWireup="true"  Culture="auto:en-US" %>
<%@ Import Namespace="System.Globalization" %>
<%@ Import Namespace="System.Xml" %>
<%@ Import Namespace="System.Data" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>Currency Exchange Calculator</title>
</head>
<script runat="server">
    Private Sub Page_Load(ByVal sender As Object, ByVal e As EventArgs)
        If (Not IsPostBack Or CStr(Session("CultureName")) <> CultureInfo.CurrentCulture.Name) Then
            DateTimePlaceholder.Text = DateTime.Now.ToLongDateString()
            
            ' Populate the drop-down with currency names
            ' If possible set the default selected currency to the currency of the CurrentCulture
            Dim UserRegion As New RegionInfo(CultureInfo.CurrentCulture.Name)
            Dim TargetRegion As RegionInfo
            Dim dir As String = Server.MapPath("")
            
            Dim ExchangeRateTextReader As New XmlTextReader(Server.MapPath("~/ExchangeRates.xml"))
            Dim ExchangeRateDataSet As New DataSet("ds")
            ExchangeRateDataSet.ReadXml(ExchangeRateTextReader)
            Dim CurrencyTable As DataTable = ExchangeRateDataSet.Tables("Currency")
            Dim CurrencyTableReader As DataTableReader = CurrencyTable.CreateDataReader()
            CurrencyDropDown.Items.Clear() ' Make sure list is empty on culture change in current session
            While CurrencyTableReader.Read()
                TargetRegion = New RegionInfo(CurrencyTableReader.GetString(0))
                Dim Currency As New ListItem(TargetRegion.CurrencyEnglishName, CurrencyTableReader.GetString(1))
                If TargetRegion.ISOCurrencySymbol = UserRegion.ISOCurrencySymbol Then
                    Currency.Selected = True
                End If
                CurrencyDropDown.Items.Add(Currency)
            End While
            Session("CultureName") = CultureInfo.CurrentCulture.Name
        End If

    End Sub 'Page_Load
     

    Private Function CalculateExchangeValue(ByVal Rate As String) As String
        Dim Value As Double
        Try
            Value = Double.Parse(ConvertValue.Text)
        Catch
            Value = 0
        End Try
        Dim ExchangeValue As Double = Double.Parse(Rate, CultureInfo.InvariantCulture) / Double.Parse(CurrencyDropDown.SelectedItem.Value, CultureInfo.InvariantCulture) * Value
        
        Return ExchangeValue.ToString("F")

    End Function 'CalculateExchangeValue


    Private Function CurrencyName(ByVal RegionName As String) As String
        Dim result As String
        Try
            Dim ri As New RegionInfo(RegionName)
            result = ri.CurrencyEnglishName
        Catch
            result = "Unknown"
        End Try
        Return result

    End Function 'CurrencyName


    Private Sub ConvertButton_Click(ByVal sender As Object, ByVal e As EventArgs)
        ExchangeGrid.DataBind()

    End Sub 'ConvertButton_Click
</script>
<body bgcolor="moccasin">
    <form id="form1" runat="server">
    <div>
        <h2>
            Currency Exchange Calculator</h2>
        <asp:Label ID="DateTimePlaceholder" runat="server" Text="DateTimePlaceholder"></asp:Label><br /><br />
        Enter an amount, choose a currency and click the Convert button to calculate the
        exchange values.<br />
        <br />
        &nbsp;<asp:TextBox ID="ConvertValue" runat="server">100</asp:TextBox>&nbsp;&nbsp;&nbsp;
        <asp:DropDownList ID="CurrencyDropDown" runat="server">
        </asp:DropDownList>
        <asp:Button ID="ConvertButton" runat="server" Text="Convert" OnClick="ConvertButton_Click" />
        <asp:XmlDataSource DataFile="ExchangeRates.xml" ID="XmlExchangeRates"
            runat="server"></asp:XmlDataSource>
        &nbsp;&nbsp;
        <br />
        <asp:GridView AutoGenerateColumns="False" DataSourceID="XmlExchangeRates" ID="ExchangeGrid"
            runat="server" >
            <Columns>
                <asp:TemplateField HeaderText="Name">
                    <ItemTemplate>
                        <asp:Label ID="ColumnCurrency" runat="server" Text='<%# CurrencyName(CStr(Eval("Region"))) %>'></asp:Label>
                    </ItemTemplate>
                    <ItemStyle HorizontalAlign="Left" />
                    <HeaderStyle HorizontalAlign="Left" />
                </asp:TemplateField>
                <asp:TemplateField HeaderText="Exchange Value">
                    <ItemTemplate>
                        <asp:Label ID="ColumnExchangeValue" runat="server" Text='<%# CalculateExchangeValue(CStr(Eval("Rate"))) %>'></asp:Label>
                    </ItemTemplate>
                    <ItemStyle HorizontalAlign="Right" />
                    <HeaderStyle HorizontalAlign="Right" />
                </asp:TemplateField>
            </Columns>
        </asp:GridView>
        <br />
        Disclaimer:
        The rate calculation above is based on exchange rates published on Dec 9th, 2004
        by the United States Federal Reserve Bank of New York. For up-to-date exchange rates please go to the website of this organization. This sample application
        is not intended to provide accurate or up-to-date currency conversions.</div>
    </form>
</body>
</html>
