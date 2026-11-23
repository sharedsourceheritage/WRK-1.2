/*=====================================================================

  File:      StoreSurvey.cs for Store Survey XML Example
  Summary:   Winform for displaying a product catalog stored in
			 the AdventureWorks OLTP database.
  Date:	     April 27, 2004

---------------------------------------------------------------------
  This file is part of the Microsoft SQL Server Code Samples.
  Copyright (C) Microsoft Corporation.  All rights reserved.

  This source code is intended only as a supplement to Microsoft
  Development Tools and/or on-line documentation.  See these other
  materials for detailed information regarding Microsoft code samples.

  THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
  KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
  PARTICULAR PURPOSE.
======================================================= */

using System;
using System.Windows.Forms;
using System.IO;
using System.Xml;
using System.Net;
using System.Net.Cache;
using System.Globalization;
using System.ComponentModel;

namespace Microsoft.Samples.SqlServer
{
    /// <summary>
    /// Summary description for StoreSurvey.
    /// </summary>
    public class StoreSurvey : System.Windows.Forms.Form
    {
        private System.Windows.Forms.Label label1;

        private System.Windows.Forms.MainMenu mainMenu1;

        private System.Windows.Forms.MenuItem fileMenuItem;

        private System.Windows.Forms.MenuItem saveMenuItem;

        private System.Windows.Forms.MenuItem exitMenuItem;

        private System.Windows.Forms.Label label2;

        private System.Windows.Forms.Label label3;

        private System.Windows.Forms.Label label4;

        private System.Windows.Forms.Label label5;

        private System.Windows.Forms.Label label6;

        private System.Windows.Forms.Label label7;

        private System.Windows.Forms.Label label8;

        private System.Windows.Forms.Label label9;

        private System.Windows.Forms.Label label10;

        private System.Windows.Forms.TextBox BankNameTextBox;

        private System.Windows.Forms.ComboBox BusinessTypeComboBox;

        private System.Windows.Forms.TextBox YearOpenedTextBox;

        private System.Windows.Forms.ComboBox SpecialtyComboBox;

        private System.Windows.Forms.ComboBox BrandsComboBox;

        private System.Windows.Forms.ComboBox InternetConnectionComboBox;

        private System.Windows.Forms.TextBox CommentsTextBox;

        private System.Windows.Forms.TextBox StoreSizeTextBox;

        private ComboItem[] BusinessCategories = new ComboItem[6] {
			new ComboItem(), new ComboItem("BM", "Bicycle Manufacturer"),
			new ComboItem("BS", "Bicycle Store"),
			new ComboItem("OS", "Online Store"),
			new ComboItem("SGS", "Sporting Goods Store"),
			new ComboItem("D", "Discount Store")
		};

        private ComboItem[] SpecialtyCategories = new ComboItem[7] {
			new ComboItem(), new ComboItem("Family", "Family Oriented"),
			new ComboItem("Kids", "Kids Bikes"),
			new ComboItem("Road", "Road Racing Bikes"),
			new ComboItem("BMX", "BMX Racing"),
			new ComboItem("Mountain", "Mountain Biking"),
			new ComboItem("All", "All types")
		};

        private ComboItem[] BrandCategories = new ComboItem[5] {
			new ComboItem(),
			new ComboItem("AW", "Exclusively Adventure-Works"),
			new ComboItem("2", "One other brand"),
			new ComboItem("3", "Two other brands"),
			new ComboItem("4+", "More than three brands")
		};

        private ComboItem[] InternetConnectionCategories = new ComboItem[7] {
			new ComboItem(), new ComboItem("56kb", "56kb dial up"),
			new ComboItem("ISDN", "ISDN"),
			new ComboItem("DSL", "DSL or Cable Modem"),
			new ComboItem("T1", "T1"), new ComboItem("T2", "T2"),
			new ComboItem("T3", "T3")
		};

        // How much space to preallocate for the XML document as we construct it
        // before it is transmitted to the server's web service.
        const int ExpectedDocSize = 2048;

        private System.Windows.Forms.Label InformationLabel;

        private System.Windows.Forms.TextBox AnnualSalesTextBox;

        private System.Windows.Forms.TextBox AnnualRevenueTextBox;

		private ErrorProvider surveyErrorProvider;

        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        public StoreSurvey()
        {
            //
            // Required for Windows Form Designer support
            //
            InitializeComponent();

            BusinessTypeComboBox.Items.AddRange(BusinessCategories);
            SpecialtyComboBox.Items.AddRange(SpecialtyCategories);
            BrandsComboBox.Items.AddRange(BrandCategories);
            InternetConnectionComboBox.Items.AddRange(InternetConnectionCategories);

			YearOpenedTextBox.Validating += new CancelEventHandler(YearOpened_Validating);
			StoreSizeTextBox.Validating += new CancelEventHandler(StoreSize_Validating);
			AnnualSalesTextBox.Validating += new CancelEventHandler(AnnualSales_Validating);
			AnnualRevenueTextBox.Validating += new CancelEventHandler(AnnualRevenue_Validating);

			YearOpenedTextBox.Validated += new EventHandler(this.YearOpened_Validated);
			StoreSizeTextBox.Validated += new EventHandler(StoreSize_Validated);
			AnnualSalesTextBox.Validated += new EventHandler(AnnualSales_Validated);
			AnnualRevenueTextBox.Validated += new EventHandler(AnnualRevenue_Validated);
		}

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                if (components != null)
                {
                    components.Dispose();
                }
            }

            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
			this.components = new System.ComponentModel.Container();
			System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(StoreSurvey));
			this.label1 = new System.Windows.Forms.Label();
			this.mainMenu1 = new System.Windows.Forms.MainMenu(this.components);
			this.fileMenuItem = new System.Windows.Forms.MenuItem();
			this.saveMenuItem = new System.Windows.Forms.MenuItem();
			this.exitMenuItem = new System.Windows.Forms.MenuItem();
			this.label2 = new System.Windows.Forms.Label();
			this.label3 = new System.Windows.Forms.Label();
			this.label4 = new System.Windows.Forms.Label();
			this.label5 = new System.Windows.Forms.Label();
			this.label6 = new System.Windows.Forms.Label();
			this.label7 = new System.Windows.Forms.Label();
			this.label8 = new System.Windows.Forms.Label();
			this.label9 = new System.Windows.Forms.Label();
			this.label10 = new System.Windows.Forms.Label();
			this.BankNameTextBox = new System.Windows.Forms.TextBox();
			this.BusinessTypeComboBox = new System.Windows.Forms.ComboBox();
			this.YearOpenedTextBox = new System.Windows.Forms.TextBox();
			this.SpecialtyComboBox = new System.Windows.Forms.ComboBox();
			this.StoreSizeTextBox = new System.Windows.Forms.TextBox();
			this.BrandsComboBox = new System.Windows.Forms.ComboBox();
			this.InternetConnectionComboBox = new System.Windows.Forms.ComboBox();
			this.CommentsTextBox = new System.Windows.Forms.TextBox();
			this.InformationLabel = new System.Windows.Forms.Label();
			this.AnnualSalesTextBox = new System.Windows.Forms.TextBox();
			this.AnnualRevenueTextBox = new System.Windows.Forms.TextBox();
			this.surveyErrorProvider = new System.Windows.Forms.ErrorProvider(this.components);
			((System.ComponentModel.ISupportInitialize)(this.surveyErrorProvider)).BeginInit();
			this.SuspendLayout();
			// 
			// label1
			// 
			resources.ApplyResources(this.label1, "label1");
			this.label1.Name = "label1";
			// 
			// mainMenu1
			// 
			this.mainMenu1.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.fileMenuItem});
			// 
			// fileMenuItem
			// 
			this.fileMenuItem.Index = 0;
			this.fileMenuItem.MenuItems.AddRange(new System.Windows.Forms.MenuItem[] {
            this.saveMenuItem,
            this.exitMenuItem});
			resources.ApplyResources(this.fileMenuItem, "fileMenuItem");
			// 
			// saveMenuItem
			// 
			this.saveMenuItem.Index = 0;
			resources.ApplyResources(this.saveMenuItem, "saveMenuItem");
			this.saveMenuItem.Click += new System.EventHandler(this.saveMenuItem_Click);
			// 
			// exitMenuItem
			// 
			this.exitMenuItem.Index = 1;
			resources.ApplyResources(this.exitMenuItem, "exitMenuItem");
			this.exitMenuItem.Click += new System.EventHandler(this.exitMenuItem_Click);
			// 
			// label2
			// 
			resources.ApplyResources(this.label2, "label2");
			this.label2.Name = "label2";
			// 
			// label3
			// 
			resources.ApplyResources(this.label3, "label3");
			this.label3.Name = "label3";
			// 
			// label4
			// 
			resources.ApplyResources(this.label4, "label4");
			this.label4.Name = "label4";
			// 
			// label5
			// 
			resources.ApplyResources(this.label5, "label5");
			this.label5.Name = "label5";
			// 
			// label6
			// 
			resources.ApplyResources(this.label6, "label6");
			this.label6.Name = "label6";
			// 
			// label7
			// 
			resources.ApplyResources(this.label7, "label7");
			this.label7.Name = "label7";
			// 
			// label8
			// 
			resources.ApplyResources(this.label8, "label8");
			this.label8.Name = "label8";
			// 
			// label9
			// 
			resources.ApplyResources(this.label9, "label9");
			this.label9.Name = "label9";
			// 
			// label10
			// 
			resources.ApplyResources(this.label10, "label10");
			this.label10.Name = "label10";
			// 
			// BankNameTextBox
			// 
			resources.ApplyResources(this.BankNameTextBox, "BankNameTextBox");
			this.BankNameTextBox.Name = "BankNameTextBox";
			// 
			// BusinessTypeComboBox
			// 
			this.BusinessTypeComboBox.DisplayMember = "UIName";
			this.BusinessTypeComboBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
			resources.ApplyResources(this.BusinessTypeComboBox, "BusinessTypeComboBox");
			this.BusinessTypeComboBox.FormattingEnabled = true;
			this.BusinessTypeComboBox.Name = "BusinessTypeComboBox";
			this.BusinessTypeComboBox.ValueMember = "KeyName";
			// 
			// YearOpenedTextBox
			// 
			resources.ApplyResources(this.YearOpenedTextBox, "YearOpenedTextBox");
			this.YearOpenedTextBox.Name = "YearOpenedTextBox";
			// 
			// SpecialtyComboBox
			// 
			this.SpecialtyComboBox.DisplayMember = "UIName";
			this.SpecialtyComboBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
			resources.ApplyResources(this.SpecialtyComboBox, "SpecialtyComboBox");
			this.SpecialtyComboBox.FormattingEnabled = true;
			this.SpecialtyComboBox.Name = "SpecialtyComboBox";
			this.SpecialtyComboBox.ValueMember = "KeyName";
			// 
			// StoreSizeTextBox
			// 
			resources.ApplyResources(this.StoreSizeTextBox, "StoreSizeTextBox");
			this.StoreSizeTextBox.Name = "StoreSizeTextBox";
			// 
			// BrandsComboBox
			// 
			this.BrandsComboBox.DisplayMember = "UIName";
			this.BrandsComboBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
			this.BrandsComboBox.FormattingEnabled = true;
			resources.ApplyResources(this.BrandsComboBox, "BrandsComboBox");
			this.BrandsComboBox.Name = "BrandsComboBox";
			this.BrandsComboBox.ValueMember = "KeyName";
			// 
			// InternetConnectionComboBox
			// 
			this.InternetConnectionComboBox.DisplayMember = "UIName";
			this.InternetConnectionComboBox.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
			this.InternetConnectionComboBox.FormattingEnabled = true;
			resources.ApplyResources(this.InternetConnectionComboBox, "InternetConnectionComboBox");
			this.InternetConnectionComboBox.Name = "InternetConnectionComboBox";
			this.InternetConnectionComboBox.ValueMember = "KeyName";
			// 
			// CommentsTextBox
			// 
			resources.ApplyResources(this.CommentsTextBox, "CommentsTextBox");
			this.CommentsTextBox.Name = "CommentsTextBox";
			// 
			// InformationLabel
			// 
			resources.ApplyResources(this.InformationLabel, "InformationLabel");
			this.InformationLabel.Name = "InformationLabel";
			// 
			// AnnualSalesTextBox
			// 
			resources.ApplyResources(this.AnnualSalesTextBox, "AnnualSalesTextBox");
			this.AnnualSalesTextBox.Name = "AnnualSalesTextBox";
			// 
			// AnnualRevenueTextBox
			// 
			resources.ApplyResources(this.AnnualRevenueTextBox, "AnnualRevenueTextBox");
			this.AnnualRevenueTextBox.Name = "AnnualRevenueTextBox";
			// 
			// surveyErrorProvider
			// 
			this.surveyErrorProvider.ContainerControl = this;
			// 
			// StoreSurvey
			// 
			resources.ApplyResources(this, "$this");
			this.Controls.Add(this.AnnualRevenueTextBox);
			this.Controls.Add(this.AnnualSalesTextBox);
			this.Controls.Add(this.InformationLabel);
			this.Controls.Add(this.CommentsTextBox);
			this.Controls.Add(this.InternetConnectionComboBox);
			this.Controls.Add(this.BrandsComboBox);
			this.Controls.Add(this.StoreSizeTextBox);
			this.Controls.Add(this.SpecialtyComboBox);
			this.Controls.Add(this.YearOpenedTextBox);
			this.Controls.Add(this.BusinessTypeComboBox);
			this.Controls.Add(this.BankNameTextBox);
			this.Controls.Add(this.label10);
			this.Controls.Add(this.label9);
			this.Controls.Add(this.label8);
			this.Controls.Add(this.label7);
			this.Controls.Add(this.label6);
			this.Controls.Add(this.label5);
			this.Controls.Add(this.label4);
			this.Controls.Add(this.label3);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.label1);
			this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
			this.Menu = this.mainMenu1;
			this.Name = "StoreSurvey";
			((System.ComponentModel.ISupportInitialize)(this.surveyErrorProvider)).EndInit();
			this.ResumeLayout(false);
			this.PerformLayout();

        }
        #endregion

        private static string GetSoapRequestXml(String survey)
        {
            return
                "<soap:Envelope xmlns:xsi='http://www.w3.org/2001/XMLSchema-instance' xmlns:xsd='http://www.w3.org/2001/XMLSchema' xmlns:soap='http://schemas.xmlsoap.org/soap/envelope/'>" +
                "  <soap:Body>" +
                "    <SaveStoreSurvey xmlns='testns'>" +
                "        <SID>1</SID> " +
                "        <Survey> " +
                            survey +
                "	     </Survey>" +
                "    </SaveStoreSurvey>" +
                "  </soap:Body>" +
                "</soap:Envelope>";
        }

        private void PostSoapRequest(string requestXml)
        {
            try
            {
                HttpWebRequest webRequest =
                               (HttpWebRequest)WebRequest.Create("http://localhost/StoreSurvey/");

                webRequest.Accept = "text/xml";
                webRequest.ContentType = "text/xml";
                webRequest.CachePolicy = new RequestCachePolicy(RequestCacheLevel.
                                                                NoCacheNoStore);
                webRequest.Headers.Add("SOAPAction", "");
                webRequest.Credentials = CredentialCache.DefaultCredentials;
                webRequest.Method = "POST";

                Stream webStream = webRequest.GetRequestStream();

                using (StreamWriter webWriter = new StreamWriter(webStream))
                {
                    try
                    {
                        webWriter.Write(requestXml);
                        webWriter.Flush();
                    }
                    finally
                    {
                        webWriter.Close();
                    }
                    WebResponse response = webRequest.GetResponse();
                    using (Stream rs = response.GetResponseStream())
                    {
                        using (StreamReader sr = new StreamReader(rs))
                        {
                            try
                            {
                                sr.ReadToEnd();
                            }
                            finally
                            {
                                sr.Close();
                            }
                        }
                    }
                }
				InformationLabel.Text = "Your data has been saved.  Thank you for participating in the survey.";
            }
            catch (System.Net.WebException e)
            {
                WebResponse wr = e.Response;
                if (wr == null)
                {
                    InformationLabel.Text = "Error: " + e.ToString();
                }
                else
                {
                    using (Stream rs = wr.GetResponseStream())
                    {
                        using (StreamReader sr = new StreamReader(rs))
                        {
                            InformationLabel.Text = "Error: "
                                + e.ToString() + sr.ReadToEnd();
                        }
                    }
                }
            }
        }

        private void exitMenuItem_Click(object sender, System.EventArgs e)
        {
            Application.Exit();
        }

        private void saveMenuItem_Click(object sender, System.EventArgs e)
        {
			foreach (Control control in Controls)
			{
				// Set focus on control
				control.Focus();
				// Validate causes the control's Validating event to be fired,
				// if CausesValidation is True
				if (!Validate())
				{
					InformationLabel.Text = "Please correct any mistakes and try to save again.";
					return;
				}
			}

            using (StringWriter sw = new StringWriter(CultureInfo.InvariantCulture))
            {
                try
                {
                    using (XmlTextWriter xmlw = new XmlTextWriter(sw))
                    {
                        try
                        {
                            xmlw.WriteStartElement("StoreSurvey",
                                "http://schemas.microsoft.com/sqlserver/2004/07/adventure-works/StoreSurvey");
                            // SelectedValue member not currently working, so we need to use SelectedItem member
                            // on combo boxes temporarily.
                            MaybeWriteXmlElement("AnnualSales",
                                                 MaybeParseDecimal(AnnualSalesTextBox.Text), xmlw, true);
                            MaybeWriteXmlElement("AnnualRevenue",
												 MaybeParseDecimal(AnnualRevenueTextBox.Text), xmlw, true);
                            MaybeWriteXmlElement("BankName", BankNameTextBox.Text, xmlw);
                            MaybeWriteXmlElement("BusinessType",
                                                 BusinessTypeComboBox.SelectedItem,
                                                 xmlw);
                            MaybeWriteXmlElement("YearOpened", YearOpenedTextBox.Text,
                                                 xmlw);
                            MaybeWriteXmlElement("Specialty",
                                                 SpecialtyComboBox.SelectedItem, xmlw);
							MaybeWriteXmlElement("SquareFeet", MaybeParseDecimal(StoreSizeTextBox.Text),
                                                 xmlw, true);
                            MaybeWriteXmlElement("Brands",
                                                 BrandsComboBox.SelectedItem, xmlw);
                            MaybeWriteXmlElement("Internet",
                                                 InternetConnectionComboBox.
                                                 SelectedItem, xmlw);
                            MaybeWriteXmlElement("Comments", CommentsTextBox.Text, xmlw);
                            xmlw.WriteEndElement();

                            xmlw.Flush();
                        }
                        finally
                        {
                            xmlw.Close();
                        }
                        String requestString = GetSoapRequestXml(sw.ToString());
                        PostSoapRequest(requestString);
                    }
                }
                finally
                {
                    sw.Close();
                }
            }
        }

		private static string MaybeParseDecimal(string val)
		{
			if (val.Length == 0) return ""; else return Decimal.Parse(val).ToString();
		}


		private static void MaybeWriteXmlElement(String elementName, object elementValue, XmlTextWriter xmlWriter)
		{
			MaybeWriteXmlElement(elementName, elementValue, xmlWriter, false);
		}

        private static void MaybeWriteXmlElement(String elementName, object elementValue, XmlTextWriter xmlWriter, bool isDecimal)
        {
            ComboItem elementItem;
            string element;

            if (elementValue != null)
            {
                // SelectedValue member not currently working, so we need to use SelectedItem member
                // on combo boxes temporarily.
                elementItem = elementValue as ComboItem;
                //if (elementValue is ComboItem)
                if (elementItem != null)
                {
                    elementValue = elementItem.KeyName;
                }

                element = (String)elementValue;
                if (element.Length > 0)
                {
					if (isDecimal)
					{
						//We use the en-US culture because that is how the XML Schema specification 
						//(http://www.w3.org/TR/xmlschema-2/#decimal) defines the decimal data type.
						element = Decimal.Parse(element,
							CultureInfo.CurrentCulture).ToString(CultureInfo.CreateSpecificCulture("en-US"));
					}
                    xmlWriter.WriteElementString(elementName,
                        "http://schemas.microsoft.com/sqlserver/2004/07/adventure-works/StoreSurvey",
                        element);
                }
            }
        }

		private void YearOpened_Validating(object sender, CancelEventArgs e)
		{
			surveyErrorProvider.SetError(YearOpenedTextBox, 
				ValidateElement("Year opened", YearOpenedTextBox.Text, 1500m,
				(decimal)(DateTime.Now.Year + 1), true, e));
		}

		private void StoreSize_Validating(object sender, CancelEventArgs e)
		{
			surveyErrorProvider.SetError(StoreSizeTextBox,
				ValidateElement("Store size", StoreSizeTextBox.Text, 50m,
				50000m, false, e));
		}

		private void AnnualSales_Validating(object sender, CancelEventArgs e)
		{
			surveyErrorProvider.SetError(AnnualSalesTextBox,
				ValidateElement("Annual sales", AnnualSalesTextBox.Text, 0m,
				900000000000m, false, e));
		}

		private void AnnualRevenue_Validating(object sender, CancelEventArgs e)
		{
			surveyErrorProvider.SetError(AnnualRevenueTextBox,
				ValidateElement("Annual revenue", AnnualRevenueTextBox.Text, 0m,
				900000000000m, false, e));
		}

		private void YearOpened_Validated(object sender, System.EventArgs e)
		{
			surveyErrorProvider.SetError(YearOpenedTextBox, "");
		}

		private void StoreSize_Validated(object sender, System.EventArgs e)
		{
			surveyErrorProvider.SetError(StoreSizeTextBox, "");
		}

		private void AnnualSales_Validated(object sender, System.EventArgs e)
		{
			surveyErrorProvider.SetError(AnnualSalesTextBox, "");
		}

		private void AnnualRevenue_Validated(object sender, System.EventArgs e)
		{
			surveyErrorProvider.SetError(AnnualRevenueTextBox, "");
		}

		private static string ValidateElement(String elementName, object elementValue,
			object min, object max, bool mustBeInt, CancelEventArgs e)
		{
			string errorString = "";

			try
			{
				if (elementValue != null && ((String)elementValue).Length > 0)
				{
					string stringValue = (string)elementValue;
					int i = 0;
					do
					{
						if (!char.IsDigit(stringValue[i]))
						{
							if (mustBeInt)
								throw new FormatException("Please enter an integer using digits only.");
							else
							{
								if (stringValue.Substring(i).StartsWith(
							CultureInfo.CurrentCulture.NumberFormat.CurrencyDecimalSeparator))
								{
									//If we're parsing a decimal value, allow decimals, and if
									//a decimal is more than one character in this culture, skip
									//over all of the characters except the last one, as 
									//we'll cover the last character at the end of this loop.
									i = i
										+ CultureInfo.CurrentCulture.NumberFormat.CurrencyDecimalSeparator.Length - 1;
								}
								else if (stringValue.Substring(i).StartsWith(
							CultureInfo.CurrentCulture.NumberFormat.CurrencyGroupSeparator))
								{
									//If we're parsing a decimal value, allow group separators, and if
									//a group separator is more than one character in this culture, skip
									//over all of the characters except the last one, as 
									//we'll cover the last character at the end of this loop.
									i = i
										+ CultureInfo.CurrentCulture.NumberFormat.CurrencyGroupSeparator.Length - 1;
								}
								else
								{
									throw new FormatException(string.Format("Invalid character {0} in number.",
								stringValue[i]));
								}
							}
						}


						i += 1;
					} while (i < stringValue.Length);
					decimal val = decimal.Parse(stringValue);
					if (min != null && (decimal)min > val)
						errorString = String.Format("{0} must be at least {1}",
							elementName, min.ToString());
					else if (max != null && val >= (decimal)max)
						errorString = String.Format("{0} must be less than {1}",
							elementName, max.ToString());
				}

			}
			catch (FormatException fe)
			{
				errorString = fe.Message;
			}
			if (errorString.Length > 0)
			{
				e.Cancel = true;
			}

			return errorString;
		}
    }

    // Helper class which holds the possible XML values and how they 
    // are presented in the combo box UI.
    public sealed class ComboItem
    {
        private String keyName = String.Empty;

        private String uiName = String.Empty;

        public String KeyName
        {
            get
            {
                return this.keyName;
            }
            set
            {
                this.keyName = value;
            }
        }

        public String UIName
        {
            get
            {
                return this.uiName;
            }
            set
            {
                this.uiName = value;
            }
        }

        public ComboItem()
        {
        }

        public ComboItem(String keyName, String uiName)
        {
            this.keyName = keyName;
            this.uiName = uiName;
        }

        public override string ToString()
        {
            return this.UIName;
        }
    }
}
