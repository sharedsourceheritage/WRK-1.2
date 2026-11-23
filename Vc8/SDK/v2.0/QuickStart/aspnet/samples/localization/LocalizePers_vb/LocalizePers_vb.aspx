<%@ Page Language="VB" AutoEventWireup="true"  Culture="auto:en-US" meta:resourcekey="PageResource1" UICulture="auto:en-US" %>
<%@ Import Namespace="System.Globalization" %>
<%@ Import Namespace="System.Xml" %>
<%@ Import Namespace="System.Data" %>
<%@ Import Namespace="System.IO" %>
<%@ Import Namespace="System.Threading" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml" runat="server" dir="<%$ Resources: HTMLDirectionality %>" >
<head runat="server">
    <title>Currency Exchange Calculator</title>
</head>
<script runat="server">
    Protected Overrides Sub InitializeCulture()
        ' override virtual method InitializeCulture() to check if profile contains a user language setting
        Dim UserCulture As String = Profile.GetPropertyValue("PreferredCulture").ToString()
        If UserCulture <> "" Then
            ' there is a user language setting in the profile: switch to it
            Thread.CurrentThread.CurrentUICulture = New CultureInfo(UserCulture)
            Thread.CurrentThread.CurrentCulture = CultureInfo.CreateSpecificCulture(UserCulture)
        End If

    End Sub 'InitializeCulture


    Private Sub Page_Load(ByVal sender As Object, ByVal e As EventArgs)
        If Not IsPostBack Or CStr(Session("CultureName")) <> CultureInfo.CurrentCulture.Name Then
            DateTimePlaceholder.Text = DateTime.Now.ToLongDateString()
        
            ' Populate the language dropdown with the list of available languages on the server
            Dim ResLangs As String() = {"ar","de","es","fr","ja","en"}
            DropDownLanguage.Items.Clear() ' Clears the dropdown in case of a culture change
            Dim ResLanguage As String
            For Each ResLanguage In ResLangs
                Dim TempCultureInfo As New CultureInfo(ResLanguage)
                Dim ResourceLanguage As New ListItem(TempCultureInfo.NativeName, TempCultureInfo.Name)
                If TempCultureInfo.Equals(CultureInfo.CurrentUICulture) Then
                    ResourceLanguage.Selected = True
                End If
                DropDownLanguage.Items.Add(ResourceLanguage)
            Next ResLanguage
            
            ' Populate the currency drop-down with currency names
            ' If possible set the default selected currency to the currency of the CurrentCulture
            Dim UserRegion As New RegionInfo(CultureInfo.CurrentCulture.Name)
            Dim TargetRegion As RegionInfo
        
            Dim ExchangeRateTextReader As New XmlTextReader(Server.MapPath("~/ExchangeRates.xml"))
            Dim ExchangeRateDataSet As New DataSet("ds")
            ExchangeRateDataSet.ReadXml(ExchangeRateTextReader)
            Dim CurrencyTable As DataTable = ExchangeRateDataSet.Tables("Currency")
            Dim CurrencyTableReader As DataTableReader = CurrencyTable.CreateDataReader()
            CurrencyDropDown.Items.Clear() ' Clears the dropdown in case of a culture change
            While CurrencyTableReader.Read()
                TargetRegion = New RegionInfo(CurrencyTableReader.GetString(0))
                Dim Currency As New ListItem(CStr(GetGlobalResourceObject("CurrencyNames", TargetRegion.Name)), CurrencyTableReader.GetString(1))
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


    Private Sub ConvertButton_Click(ByVal sender As Object, ByVal e As EventArgs)
        ExchangeGrid.DataBind()

    End Sub 'ConvertButton_Click


    Protected Sub DropDownLanguage_SelectedIndexChanged(ByVal sender As Object, ByVal e As EventArgs)
        Dim SelectedLanguage As String = DropDownLanguage.SelectedValue.ToString()
        'Save selected user language in profile 
        Profile.SetPropertyValue("PreferredCulture", SelectedLanguage)
    
        'Force re-initialization of the page to fire InitializeCulture()
        Response.Redirect(Request.Url.LocalPath)

    End Sub 'DropDownLanguage_SelectedIndexChanged

</script>
<body bgcolor="moccasin">
    <form id="form1" runat="server">
    <div>
        <h2>
            <asp:Label ID="LabelTitle" runat="server" Text="<%$ Resources:LabelResource1.Text %>" BackColor="<%$ Resources:BackgroundColor %>"></asp:Label>&nbsp;</h2>
        <asp:Label ID="DateTimePlaceholder" runat="server" Text="<%$ Resources:LabelResource2.Text %>" BackColor="<%$ Resources:BackgroundColor %>"></asp:Label><br />
        <asp:DropDownList ID="DropDownLanguage" runat="server" OnSelectedIndexChanged="DropDownLanguage_SelectedIndexChanged" AutoPostBack="True">
        </asp:DropDownList><br /><br />
        <asp:Label ID="LabelInstruction" runat="server" Text="Enter an amount, choose a currency and click the Convert button to calculate the exchange values." meta:resourcekey="LabelResource3"></asp:Label>
        <br />
        &nbsp;<asp:TextBox ID="ConvertValue" runat="server" meta:resourcekey="TextBoxResource1" Text="100"></asp:TextBox>&nbsp;&nbsp;&nbsp;
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
                        <asp:Label ID="ColumnCurrency" runat="server" Text='<%# CStr(GetGlobalResourceObject("CurrencyNames",CStr(Eval("Region")))) %>' meta:resourcekey="LabelResource4"></asp:Label>
                    </ItemTemplate>
                </asp:TemplateField>
                <asp:TemplateField HeaderText="Exchange Value" meta:resourcekey="TemplateFieldResource2">
                    <ItemTemplate>
                        <asp:Label ID="ColumnExchangeValue" runat="server" Text='<%# CalculateExchangeValue(CStr(Eval("Rate"))) %>' meta:resourcekey="LabelResource5"></asp:Label>
                    </ItemTemplate>
                    <ItemStyle HorizontalAlign="Right" />
                </asp:TemplateField>
            </Columns>
        </asp:GridView>
        <br />
        <asp:Localize runat="server" meta:resourcekey="LiteralResource1">Disclaimer: The rate calculation above is based on 
exchange rates published on Dec 9th, 2004 by the United States Federal Reserve 
Bank of New York. For up-to-date exchange rates please go to the website of this 
organization. This sample application is not intended to provide accurate or 
up-to-date currency conversions.</asp:Localize>
        </div>
    </form>
</body>
</html>
