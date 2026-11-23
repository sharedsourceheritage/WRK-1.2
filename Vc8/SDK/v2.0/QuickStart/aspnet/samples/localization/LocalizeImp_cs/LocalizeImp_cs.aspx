<%@ Page Language="C#" AutoEventWireup="true"  Culture="auto:en-US" meta:resourcekey="PageResource1" UICulture="auto:en-US" %>
<%@ Import Namespace="System.Globalization" %>
<%@ Import Namespace="System.Xml" %>
<%@ Import Namespace="System.Data" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" >
<head runat="server">
    <title>Currency Exchange Calculator</title>
</head>
<script runat="server">
    private void Page_Load(object sender, EventArgs e)
    {
        if (!IsPostBack || (string)Session["CultureName"] != CultureInfo.CurrentCulture.Name)
        {
            DateTimePlaceholder.Text = DateTime.Now.ToLongDateString();

            // Populate the drop-down with currency names
            // If possible set the default selected currency to the currency of the CurrentCulture
            RegionInfo UserRegion = new RegionInfo(CultureInfo.CurrentCulture.Name);
            RegionInfo TargetRegion;
            
            XmlTextReader ExchangeRateTextReader = new XmlTextReader(Server.MapPath("~/ExchangeRates.xml"));
            DataSet ExchangeRateDataSet = new DataSet("ds");
            ExchangeRateDataSet.ReadXml(ExchangeRateTextReader);
            DataTable CurrencyTable = ExchangeRateDataSet.Tables["Currency"];
            DataTableReader CurrencyTableReader = CurrencyTable.CreateDataReader();
            CurrencyDropDown.Items.Clear();   // Make sure drop down is clear in case of culture change
            while (CurrencyTableReader.Read())
            {
                TargetRegion = new RegionInfo(CurrencyTableReader.GetString(0));
                ListItem Currency = new ListItem(TargetRegion.CurrencyEnglishName, CurrencyTableReader.GetString(1));
                if (TargetRegion.ISOCurrencySymbol == UserRegion.ISOCurrencySymbol)
                {
                    Currency.Selected = true;
                }
                CurrencyDropDown.Items.Add(Currency);
            }
            Session["CultureName"] = CultureInfo.CurrentCulture.Name;
        }

    }

    private string CalculateExchangeValue(string Rate)
    {
        double Value;
        try
        {
            Value = double.Parse(ConvertValue.Text);
        }
        catch
        {
            Value = 0;
        }
        double ExchangeValue = (double.Parse(Rate, CultureInfo.InvariantCulture) / double.Parse(CurrencyDropDown.SelectedItem.Value, CultureInfo.InvariantCulture)) * Value;
        
        return ExchangeValue.ToString("F");
    }

    private string CurrencyName(string RegionName)
    {
        string result;
        try
        {
            RegionInfo ri = new RegionInfo(RegionName);
            result = ri.CurrencyEnglishName;
        }
        catch
        {
            result = "Unknown";
        }
        return result;
    }

    private void ConvertButton_Click(object sender, EventArgs e)
    {
        ExchangeGrid.DataBind();
    }
    
</script>
<body bgcolor="moccasin">
    <form id="form1" runat="server">
    <div>
        <h2>
            <asp:Label ID="LabelTitle" runat="server" Text="Currency Exchange Calculator" meta:resourcekey="LabelResource1"></asp:Label>&nbsp;</h2>
        <asp:Label ID="DateTimePlaceholder" runat="server" Text="DateTimePlaceholder" meta:resourcekey="LabelResource2"></asp:Label><br /><br />
        <asp:Label ID="LabelInstruction" runat="server" Text="Enter an amount, choose a currency and click the Convert button to calculate the exchange values." meta:resourcekey="LabelResource3"></asp:Label>
        <br />
        &nbsp;<asp:TextBox ID="ConvertValue" runat="server" meta:resourcekey="TextBoxResource1">100</asp:TextBox>&nbsp;&nbsp;&nbsp;
        <asp:DropDownList ID="CurrencyDropDown" runat="server" meta:resourcekey="DropDownListResource1">
        </asp:DropDownList>
        <asp:Button ID="ConvertButton" runat="server" Text="Convert" OnClick="ConvertButton_Click" meta:resourcekey="ButtonResource1" />
        <asp:XmlDataSource DataFile="ExchangeRates.xml" ID="XmlExchangeRates"
            runat="server"></asp:XmlDataSource>
        &nbsp;&nbsp;
        <br />
        <asp:GridView AutoGenerateColumns="False" DataSourceID="XmlExchangeRates" ID="ExchangeGrid"
            runat="server" meta:resourcekey="GridViewResource1" >
            <Columns>
                <asp:TemplateField HeaderText="Name" meta:resourcekey="TemplateFieldResource1">
                    <ItemTemplate>
                        <asp:Label ID="ColumnCurrency" runat="server" Text='<%# CurrencyName((string)Eval("Region")) %>' meta:resourcekey="LabelResource4"></asp:Label>
                    </ItemTemplate>
                    <ItemStyle HorizontalAlign="Left" />
                    <HeaderStyle HorizontalAlign="Left" />
                </asp:TemplateField>
                <asp:TemplateField HeaderText="Exchange Value" meta:resourcekey="TemplateFieldResource2">
                    <ItemTemplate>
                        <asp:Label ID="ColumnExchangeValue" runat="server" Text='<%# CalculateExchangeValue((string)Eval("Rate")) %>' meta:resourcekey="LabelResource5"></asp:Label>
                    </ItemTemplate>
                    <ItemStyle HorizontalAlign="Right" />
                    <HeaderStyle HorizontalAlign="Right" />
                </asp:TemplateField>
            </Columns>
        </asp:GridView>
        <br />
        <asp:Label ID="LabelDisclaimer" runat="server" Text="Disclaimer: The rate calculation above is based on exchange rates published on Dec 9th, 2004 by the United States Federal Reserve Bank of New York. For up-to-date exchange rates please go to the website of this organization. This sample application is not intended to provide accurate or up-to-date currency conversions." meta:resourcekey="LabelResource6"></asp:Label></div>
    </form>
</body>
</html>
