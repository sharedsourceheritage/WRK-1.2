//------------------------------------------------------------------------------
// <copyright from='2003' to='2004' company='Microsoft Corporation'>           
//  Copyright (c) Microsoft Corporation, All rights reserved.             
//  This code sample is provided "AS IS" without warranty of any kind, 
//  it is not recommended for use in a production environment.
// </copyright>                                                                
//------------------------------------------------------------------------------

using System;
using System.Collections;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Globalization;
using System.Windows.Forms;

namespace PackageWizard
{
    /// <summary>
    /// This page is the one that is responsible for the definition of the tokens used by the language.
    /// For each token it is possible to specify a description and a color class.
    /// </summary>
    public class Page8 : System.Windows.Forms.UserControl, WizardLibrary.IWizardPage
    {
        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.Container components = null;

        // This string is the name of the token in the output file to describe the language tokens
        private const string m_strFileToken = "%TokensInfo%";

        private const string syntaxColorKey = "SyntaxColor";

        // These constants are used in the case of the defualt grammar to find the space and
        // comment token and map them to the right char class. This is needed in order to let
        // the generated parser to work.
        private const string spaceToken = "LEX_WHITE";
        private const string commentToken = "LEX_COMMENT";

        private System.Windows.Forms.Label lblName;
        private System.Windows.Forms.TextBox txtName;
        private System.Windows.Forms.TextBox txtDesc;
        private System.Windows.Forms.Label lblDesc;
        private System.Windows.Forms.Label lblColor;
        private System.Windows.Forms.ComboBox cmbColor;
        private System.Windows.Forms.ComboBox cmbCharClass;
        private System.Windows.Forms.Label lblChar;
        private System.Windows.Forms.Button cmdAdd;
        private System.Windows.Forms.Button cmdDel;
        private System.Windows.Forms.Button cmdModify;
        private System.Windows.Forms.ListBox lstTokens;
        private System.Windows.Forms.CheckedListBox lstTriggers;

        // This flag indicates when the user is changing the selection, so we have not to
        // update the enable status of the "Apply" button.
        private bool m_bChangingSelection;
        private System.Windows.Forms.Button cmdLoad;
        private bool useColors;

        // The following flags indicates if wich properties have to be updated for the
        // selected tokens
        private bool m_bDescChanged;

        // A reference to the wizard
        private WizardLibrary.WizardLibrary    m_wizard;

        public Page8()
        {
            // This call is required by the Windows.Forms Form Designer.
            InitializeComponent();

            m_bChangingSelection = true;
            useColors = false;
        }

        /// <summary> 
        /// Clean up any resources being used.
        /// </summary>
        protected override void Dispose( bool disposing )
        {
            if( disposing )
            {
                if(components != null)
                {
                    components.Dispose();
                }
            }
            base.Dispose( disposing );
        }

        #region Component Designer generated code
        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.lstTokens = new System.Windows.Forms.ListBox();
            this.lblName = new System.Windows.Forms.Label();
            this.txtName = new System.Windows.Forms.TextBox();
            this.txtDesc = new System.Windows.Forms.TextBox();
            this.lblDesc = new System.Windows.Forms.Label();
            this.lblColor = new System.Windows.Forms.Label();
            this.cmbColor = new System.Windows.Forms.ComboBox();
            this.cmbCharClass = new System.Windows.Forms.ComboBox();
            this.lblChar = new System.Windows.Forms.Label();
            this.cmdAdd = new System.Windows.Forms.Button();
            this.cmdDel = new System.Windows.Forms.Button();
            this.cmdModify = new System.Windows.Forms.Button();
            this.lstTriggers = new System.Windows.Forms.CheckedListBox();
            this.cmdLoad = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // lstTokens
            // 
            this.lstTokens.Location = new System.Drawing.Point(8, 16);
            this.lstTokens.Name = "lstTokens";
            this.lstTokens.Size = new System.Drawing.Size(184, 199);
            this.lstTokens.TabIndex = 0;
            this.lstTokens.SelectedIndexChanged += new System.EventHandler(this.lstTokens_SelectedIndexChanged);
            // 
            // lblName
            // 
            this.lblName.Location = new System.Drawing.Point(200, 8);
            this.lblName.Name = "lblName";
            this.lblName.Size = new System.Drawing.Size(88, 16);
            this.lblName.TabIndex = 1;
            this.lblName.Text = "Name:";
            // 
            // txtName
            // 
            this.txtName.Location = new System.Drawing.Point(296, 8);
            this.txtName.Name = "txtName";
            this.txtName.Size = new System.Drawing.Size(192, 20);
            this.txtName.TabIndex = 1;
            this.txtName.Text = "";
            this.txtName.TextChanged += new System.EventHandler(this.txtName_TextChanged);
            // 
            // txtDesc
            // 
            this.txtDesc.Location = new System.Drawing.Point(296, 32);
            this.txtDesc.Name = "txtDesc";
            this.txtDesc.Size = new System.Drawing.Size(192, 20);
            this.txtDesc.TabIndex = 2;
            this.txtDesc.Text = "";
            this.txtDesc.TextChanged += new System.EventHandler(this.txtDesc_TextChanged);
            // 
            // lblDesc
            // 
            this.lblDesc.Location = new System.Drawing.Point(200, 32);
            this.lblDesc.Name = "lblDesc";
            this.lblDesc.Size = new System.Drawing.Size(88, 16);
            this.lblDesc.TabIndex = 3;
            this.lblDesc.Text = "Description:";
            // 
            // lblColor
            // 
            this.lblColor.Location = new System.Drawing.Point(200, 56);
            this.lblColor.Name = "lblColor";
            this.lblColor.Size = new System.Drawing.Size(88, 16);
            this.lblColor.TabIndex = 5;
            this.lblColor.Text = "Color Class:";
            // 
            // cmbColor
            // 
            this.cmbColor.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmbColor.Location = new System.Drawing.Point(296, 56);
            this.cmbColor.Name = "cmbColor";
            this.cmbColor.Size = new System.Drawing.Size(192, 21);
            this.cmbColor.TabIndex = 3;
            this.cmbColor.SelectedIndexChanged += new System.EventHandler(this.cmbColor_SelectedIndexChanged);
            // 
            // cmbCharClass
            // 
            this.cmbCharClass.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList;
            this.cmbCharClass.Location = new System.Drawing.Point(296, 80);
            this.cmbCharClass.Name = "cmbCharClass";
            this.cmbCharClass.Size = new System.Drawing.Size(192, 21);
            this.cmbCharClass.TabIndex = 4;
            this.cmbCharClass.SelectedIndexChanged += new System.EventHandler(this.cmbCharClass_SelectedIndexChanged);
            // 
            // lblChar
            // 
            this.lblChar.Location = new System.Drawing.Point(200, 80);
            this.lblChar.Name = "lblChar";
            this.lblChar.Size = new System.Drawing.Size(88, 16);
            this.lblChar.TabIndex = 7;
            this.lblChar.Text = "Char Class:";
            // 
            // cmdAdd
            // 
            this.cmdAdd.Location = new System.Drawing.Point(304, 192);
            this.cmdAdd.Name = "cmdAdd";
            this.cmdAdd.Size = new System.Drawing.Size(56, 24);
            this.cmdAdd.TabIndex = 8;
            this.cmdAdd.Text = "&New";
            this.cmdAdd.Click += new System.EventHandler(this.cmdAdd_Click);
            // 
            // cmdDel
            // 
            this.cmdDel.Location = new System.Drawing.Point(432, 192);
            this.cmdDel.Name = "cmdDel";
            this.cmdDel.Size = new System.Drawing.Size(56, 24);
            this.cmdDel.TabIndex = 10;
            this.cmdDel.Text = "&Del";
            this.cmdDel.Click += new System.EventHandler(this.cmdDel_Click);
            // 
            // cmdModify
            // 
            this.cmdModify.Location = new System.Drawing.Point(368, 192);
            this.cmdModify.Name = "cmdModify";
            this.cmdModify.Size = new System.Drawing.Size(56, 24);
            this.cmdModify.TabIndex = 9;
            this.cmdModify.Text = "&Apply";
            this.cmdModify.Click += new System.EventHandler(this.cmdModify_Click);
            // 
            // lstTriggers
            // 
            this.lstTriggers.Location = new System.Drawing.Point(200, 105);
            this.lstTriggers.Name = "lstTriggers";
            this.lstTriggers.Size = new System.Drawing.Size(288, 79);
            this.lstTriggers.TabIndex = 6;
            this.lstTriggers.ItemCheck += new System.Windows.Forms.ItemCheckEventHandler(this.lstTriggers_ItemCheck);
            // 
            // cmdLoad
            // 
            this.cmdLoad.Location = new System.Drawing.Point(200, 192);
            this.cmdLoad.Name = "cmdLoad";
            this.cmdLoad.Size = new System.Drawing.Size(56, 24);
            this.cmdLoad.TabIndex = 7;
            this.cmdLoad.Text = "&Load";
            this.cmdLoad.Click += new System.EventHandler(this.cmdLoad_Click);
            // 
            // Page8
            // 
            this.Controls.Add(this.cmdLoad);
            this.Controls.Add(this.lstTriggers);
            this.Controls.Add(this.cmdModify);
            this.Controls.Add(this.cmdDel);
            this.Controls.Add(this.cmdAdd);
            this.Controls.Add(this.cmbCharClass);
            this.Controls.Add(this.lblChar);
            this.Controls.Add(this.cmbColor);
            this.Controls.Add(this.lblColor);
            this.Controls.Add(this.txtDesc);
            this.Controls.Add(this.lblDesc);
            this.Controls.Add(this.txtName);
            this.Controls.Add(this.lblName);
            this.Controls.Add(this.lstTokens);
            this.Name = "Page8";
            this.Size = new System.Drawing.Size(496, 220);
            this.Load += new System.EventHandler(this.Page8_Load);
            this.Enter += new EventHandler(Page8_Enter);
            this.ResumeLayout(false);

        }
        #endregion

        #region IWizardPage Members

        public void PerformWork1(WizardLibrary.WizardLibrary wizardLibrary)
        {
            // Build the C++ description of the tokens of this language.
            string strTokensDefinition = "";

            bool isDefault = (bool)wizardLibrary.customData["IsDefaultGrammar"];
            if ( !isDefault )
            {
                // If the selected grammar is not the default one, we have to warn the user
                // that it is possible that the generated parser will not work if the mapping
                // between tokens and char class is not correct.
                strTokensDefinition +=
                    "    // NOTE: The following token definition was generated by the wizard according with\n" +
                    "    // the information you provided. However it is possible that this code will not work\n" +
                    "    // if there is a missmatch between the char class defined for some tokens and what is\n" +
                    "    // expected by the lexer.\n";
            }

            // Check again the value of the syntax color custom data because it is possible that it is
            // different from the one that was detected before, for instance is the user navigated to
            // this page, then navigate back to a previous, changed the check box for the syntax color
            // and then pressed "Finish".
            if ( (m_wizard != null) && m_wizard.customData.Contains(syntaxColorKey) )
            {
                useColors = (bool)m_wizard.customData[syntaxColorKey];
            }
            foreach (LanguageToken token in lstTokens.Items)
            {
                // If the syntax colors are disabled, set to the default the color class for
                // all the tokens
                if ( !useColors )
                {
                    token.ColorClass = LanguageToken.rgColorClasses[0];
                }
                strTokensDefinition += token.TokenInfoDefinition + ",\n";
            }

            // Add to the token processor the description of the language tokens
            TokenProcessor processor = (TokenProcessor)wizardLibrary.customData["TokenProcessor"];
            processor.AddReplace(m_strFileToken, strTokensDefinition, TokenReplaceType.ReplaceCode);
        }

        public void PerformWork2(WizardLibrary.WizardLibrary wizardLibrary)
        {
            // Do nothing
        }

        public string HeadingLabel
        {
            get
            {
                return @"Language Tokens";
            }
        }

        public string HelpKeyword
        {
            get
            {
                // TODO:  Add TitlePage.HelpKeyword getter implementation
                return "vs.vsip.LangServWiz.langtoks";
            }
        }

        public string DescriptionLabel
        {
            get
            {
                return @"Define the tokens of your language that need syntax highlighting.";
            }
        }

        public System.Drawing.Image Icon
        {
            get
            {
                System.Reflection.Assembly asm = System.Reflection.Assembly.GetExecutingAssembly();
                return System.Drawing.Image.FromStream(asm.GetManifestResourceStream("PackageWizard.SmallArtWork.bmp"));
            }
        }

        public void Initialize(WizardLibrary.WizardLibrary wizardLibrary)
        {
            m_wizard = wizardLibrary;
        }

        public bool ValidateFields()
        {
            // We don't need validation here because all the validation must be done
            // when the items are added to the list view.
            return true;
        }

        #endregion

        private void Page8_Load(object sender, System.EventArgs e)
        {
            // Initialize the combo box for the color classes
            foreach (string c in LanguageToken.rgColorClasses)
            {
                cmbColor.Items.Add(c);
            }

            // Initialize the combo for the char classes
            foreach (string c in LanguageToken.rgCharClasses)
            {
                cmbCharClass.Items.Add(c);
            }

            // Associate the checked list box to the array of triggers
            lstTriggers.Items.AddRange( LanguageToken.rgTriggerNames );
            lstTriggers.CheckOnClick = true;

            // Disable the controls that are supposed to modify the
            // selected tokens, because no token is defined by now.
            txtName.Enabled = false;
            txtName.Text = "";

            txtDesc.Enabled = false;
            txtDesc.Text = "";
            m_bDescChanged = false;

            cmbColor.Enabled = false;
            cmbColor.SelectedItem = null;

            cmbCharClass.Enabled = false;
            cmbCharClass.SelectedItem = null;

            cmdDel.Enabled = false;
            cmdModify.Enabled = false;

            lstTriggers.Enabled = false;

            // Initialize the list box
            lstTokens.SelectionMode = SelectionMode.MultiExtended;
        }

        private void Page8_Enter(object sender, EventArgs e)
        {
            // Check the value of the global flag for syntax color
            if ( (m_wizard != null) && m_wizard.customData.Contains(syntaxColorKey) ) 
            {
                useColors = (bool)m_wizard.customData[syntaxColorKey];
                // Now set the right enable status for the controls
                EnableControls();
            }
        }

        // This function will find the first avaible token name in the for TOKENn
        private string FindTokenName()
        {
            int i = 1;
            string strBasis = "TOKEN";
            while ( lstTokens.FindStringExact(strBasis + i.ToString(CultureInfo.CurrentCulture))>=0 )
            {
                i++;
            }
            return strBasis + i.ToString(CultureInfo.CurrentCulture);
        }

        // This function will open the .y file and extract the tokens from it.
        // To extract the tokens it assumes that the file has a Bison-like format
        private void LoadTokensFromFile()
        {
            // Make sure that the object is in a correct state
            if (m_wizard == null)
            {
                return;
            }
            // Read the name of the grammar file from the wizard's custom data
            string strFileName = m_wizard.customData["GrammarFile"] as string;
            // Check if the grammar file is the default one
            bool isDefault = (bool)m_wizard.customData["IsDefaultGrammar"];
            // Now open the grammar file for read.
            System.IO.StreamReader reader = new System.IO.StreamReader(strFileName);

            // Create the two regualr expression that we will use to find the tokens
            // definition in the bison file
            System.Text.RegularExpressions.Regex rex = 
                new System.Text.RegularExpressions.Regex(@"^\s*%token((\s+([^'\s]+|'.'))+)");
            System.Text.RegularExpressions.Regex innerExp = 
                new System.Text.RegularExpressions.Regex(@"\s+([^'\s]+|'.')(.*)$");

            // Clear the previously defined collection of tokens
            lstTokens.Items.Clear();

            // Now parse all the rows of the grammar file
            string strRow;
            while ( reader.Peek() != -1 )
            {
                strRow = reader.ReadLine();
                System.Text.RegularExpressions.Match m = rex.Match(strRow);
                if ( m.Success )
                {
                    System.Text.RegularExpressions.Group g = m.Groups[1];
                    string strTokens = g.Value;
                    while (strTokens.Length > 0)
                    {
                        System.Text.RegularExpressions.Match t = innerExp.Match(strTokens);
                        if ( !m.Success )
                            break;
                        string strTok = t.Groups[1].Value;
                        strTokens = t.Groups[2].Value;
                        LanguageToken token = new LanguageToken(strTok);
                        // If we are loading the default grammar, then we have to provide
                        // the default mapping for the space and comment tokens.
                        if (isDefault)
                        {
                            if (strTok == spaceToken)
                            {
                                token.CharClass = "CharWhiteSpace";
                            }
                            else if (strTok == commentToken)
                            {
                                token.CharClass = "CharComment";
                            }
                        }

                        // Add the token to the list
                        lstTokens.Items.Add( token );
                    }
                }
            }
        }

        private void DeleteSelection()
        {
            // This function deletes all the tokens selected in the list box.
            // The deletion is performed against both the list box and the 
            // hash of tokens
            try
            {
                // Remember the position of the item that is selected before the delete
                int iSelIndex = lstTokens.SelectedIndex;
                ArrayList list = new ArrayList();
                foreach (LanguageToken n in lstTokens.SelectedItems)
                {
                    list.Add(n);
                }

                foreach (LanguageToken n in list)
                {
                    lstTokens.Items.Remove(n);
                }

                // Set the selection an the list box right after the element that was
                // selected before the delete
                if (iSelIndex >= lstTokens.Items.Count)
                {
                    iSelIndex--;
                }
                lstTokens.SelectedIndex = iSelIndex;
            }
            catch ( Exception )
            {
                // Do nothing
            }
        }

        private void cmdAdd_Click(object sender, System.EventArgs e)
        {
            // Add a default token, that means that the name is a dummy name and
            // the tokens properties are the default ones.
            string strNewName = FindTokenName();

            // Deselect all the items
            lstTokens.ClearSelected();

            LanguageToken token = new LanguageToken(strNewName);
            int index = lstTokens.Items.Add(token);
            lstTokens.SelectedIndex = index;
            lstTokens.Focus();
        }

        private void lstTokens_SelectedIndexChanged(object sender, System.EventArgs e)
        {
            EnableControls();
        }

        private void txtName_TextChanged(object sender, System.EventArgs e)
        {
            if ( !m_bChangingSelection )
            {
                cmdModify.Enabled = true;
            }
        }

        private void txtDesc_TextChanged(object sender, System.EventArgs e)
        {
            if ( !m_bChangingSelection )
            {
                m_bDescChanged = true;
                cmdModify.Enabled = true;
            }
        }

        private void cmbColor_SelectedIndexChanged(object sender, System.EventArgs e)
        {
            if ( !m_bChangingSelection )
            {
                cmdModify.Enabled = true;
            }
        }

        private void cmbCharClass_SelectedIndexChanged(object sender, System.EventArgs e)
        {
            if ( !m_bChangingSelection )
            {
                cmdModify.Enabled = true;
            }
        }

        private void cmdDel_Click(object sender, System.EventArgs e)
        {
            DeleteSelection();
        }

        private void cmdModify_Click(object sender, System.EventArgs e)
        {
            if ( lstTokens.SelectedItems.Count == 0 )
            {
                // If there is no item selected in the list box, this function
                // must not be called, so there is a bug. Anyway we can ignore
                // it and simply exit the function.
                return;
            }

            bool bNeedRefresh = false;

            if ( lstTokens.SelectedItems.Count == 1 )
            {
                // The only special case about the single selection is that it is
                // possible that the name of the token was changed. In this case
                // we have to check that the new name is not in use.
                string strNewName = txtName.Text.Trim();
                string strOldName = lstTokens.SelectedItems[0].ToString();
                LanguageToken token = (LanguageToken)lstTokens.SelectedItems[0];

                if (string.Compare(strNewName, strOldName, true, CultureInfo.CurrentCulture)!=0)
                {
                    // As first check that the new name is not in use.
                    if ( lstTokens.FindStringExact(strNewName) >= 0 )
                    {
                        MessageBox.Show(this, "Redefinition of token " + strNewName + ".", "Microsoft Development Environment", MessageBoxButtons.OK, MessageBoxIcon.Error);
                        return;
                    }
                }

                if ( strNewName != strOldName )
                {
                    // Change the name of the token
                    token.Name = strNewName;
                    bNeedRefresh = true;
                }
            }

            // Now set the properties for each selected token
            foreach (LanguageToken token in lstTokens.SelectedItems)
            {
                if ( m_bDescChanged )
                {
                    token.Description = txtDesc.Text;
                }

                if ( cmbColor.SelectedItem != null )
                {
                    token.ColorClass = cmbColor.Text;
                }

                if ( cmbCharClass.SelectedItem != null )
                {
                    token.CharClass = cmbCharClass.Text;
                }

                // Set the enabled state of the triggers
                for (int i=0; i<lstTriggers.Items.Count; i++)
                {
                    if (lstTriggers.GetItemCheckState(i) != CheckState.Indeterminate)
                    {
                        token.SetTriggerStatus(
                            lstTriggers.Items[i].ToString(), 
                            (lstTriggers.GetItemCheckState(i)==CheckState.Checked) 
                        );
                    }
                }
            }

            // If the list box needs refresh a simple call to refresh doesn't works, so
            // let's try deleting the item and adding it again.
            if ( bNeedRefresh )
            {
                // Note that here we use selected index because if we need refresh, then a
                // token name is changed => only one item is selected
                int index = lstTokens.SelectedIndex;
                LanguageToken renamed = (LanguageToken)lstTokens.Items[index];
                lstTokens.Items.RemoveAt(index);
                lstTokens.Items.Insert(index, renamed);
                lstTokens.SelectedItem = renamed;
            }
            // All done, now there are no more changes to save, so disable this button
            cmdModify.Enabled = false;
            lstTokens.Focus();
        }

        private void lstTriggers_ItemCheck(object sender, System.Windows.Forms.ItemCheckEventArgs e)
        {
            if ( !m_bChangingSelection )
            {
                cmdModify.Enabled = true;
            }            
        }

        private void cmdLoad_Click(object sender, System.EventArgs e)
        {
            LoadTokensFromFile();
        }


        private void EnableControls()
        {
            // Inside here we are changing the selection, so the enabled status of the
            // apply button must not change when the propriety fields change.
            m_bChangingSelection = true;

            // The text box that show the name is enabled only if the user selects exacly
            // one token, otherwise doesn't make sense
            txtName.Enabled = (lstTokens.SelectedItems.Count == 1);
            txtName.Text = "";

            // The apply button must be disabled if no change was made to the properties
            cmdModify.Enabled = false;

            if (lstTokens.SelectedItems.Count == 0)
            {
                // If no item is selected on the list view, then disble all the controls
                // that are supposed to show or modify its properties.
                txtDesc.Enabled = false;
                txtDesc.Text = "";

                cmbColor.Enabled = false;
                cmbColor.SelectedItem = null;

                cmbCharClass.Enabled = false;
                cmbCharClass.SelectedItem = null;

                lstTriggers.Enabled = false;

                cmdDel.Enabled = false;
            }
            else
            {
                // If there is at least one item selected, then it is possible to modify or
                // delete it (or them), so enable the controls.
                txtDesc.Enabled = true;
                cmbColor.Enabled = useColors;
                cmbCharClass.Enabled = true;
                lstTriggers.Enabled = true;
                cmdDel.Enabled = true;

                // The name can be show and modify only if only one token is selected.
                if ( lstTokens.SelectedItems.Count == 1 )
                {
                    txtName.Text = lstTokens.SelectedItems[0].ToString();
                }

                // Now search for the properties that has the same value for all the tokens
                string strDesc = null;
                string strColor = null;
                string strChar = null;
                bool bFirstToken = true;
                foreach (LanguageToken token in lstTokens.SelectedItems)
                {
                    // Set the values of the triggers
                    for (int i=0; i<lstTriggers.Items.Count; i++)
                    {
                        if ( bFirstToken )
                        {
                            // For the first token set the check status as the enable status of the trigger
                            lstTriggers.SetItemCheckState(i,
                                token.IsTriggerEnabled(lstTriggers.Items[i].ToString()) ? CheckState.Checked : CheckState.Unchecked);
                        }
                        else
                        {
                            // For all the other selected tokens, check if the check status in
                            // the list is the same of the enabled status of the trigger, otherwise
                            // set the check box as Indeterminate.
                            bool triggerEnabled = token.IsTriggerEnabled(lstTriggers.Items[i].ToString());
                            if ((triggerEnabled && (lstTriggers.GetItemCheckState(i) != CheckState.Checked)) ||
                                (!triggerEnabled && (lstTriggers.GetItemCheckState(i) != CheckState.Unchecked)) )
                            {
                                lstTriggers.SetItemCheckState(i, CheckState.Indeterminate);
                            }
                        }
                    }
                    bFirstToken = false;

                    // Check the description
                    if ( (strDesc == null) || (strDesc == token.Description) )
                    {
                        strDesc = token.Description;
                    }
                    else
                    {
                        strDesc = "";
                    }

                    // Check the color class
                    if ( (strColor == null) || (strColor == token.ColorClass) )
                    {
                        strColor = token.ColorClass;
                    }
                    else
                    {
                        strColor = "";
                    }

                    // Check the char class
                    if ( (strChar == null) || (strChar == token.CharClass) )
                    {
                        strChar = token.CharClass;
                    }
                    else
                    {
                        strChar = "";
                    }
                }
                // Now set the text values of the controls
                txtDesc.Text = strDesc;
                if ( strColor.Length == 0 )
                {
                    cmbColor.SelectedItem = null;
                }
                else
                {
                    cmbColor.Text = strColor;
                }
                if ( strChar.Length == 0 )
                {
                    cmbCharClass.SelectedItem = null;
                }
                else
                {
                    cmbCharClass.Text = strChar;
                }
            }

            // By now the description of the tokens is not changed
            m_bDescChanged = false;

            // All done; from now on a change to any property field must enable the
            // apply button
            m_bChangingSelection = false;
        }

    }
}
