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
using System.Windows.Forms;

namespace PackageWizard
{
    /// <summary>
    /// Summary description for LanguageOptions.
    /// </summary>
    public class LanguageOptions : System.Windows.Forms.UserControl, WizardLibrary.IWizardPage
    {
        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.Container components = null;
        private System.Windows.Forms.CheckBox chkSyntaxColor;
        private System.Windows.Forms.CheckBox chkDefaultColors;
        private System.Windows.Forms.CheckBox chkSyntaxCheck;
        private System.Windows.Forms.CheckBox chkBlockComment;
        private System.Windows.Forms.CheckBox chkBraceMatch;
        private System.Windows.Forms.CheckBox chkMatchCursor;
        private System.Windows.Forms.CheckBox chkStatCompl;
        private System.Windows.Forms.CheckBox chkQuickInfo;

        // Collection of the tokens known by this page
        private Hashtable hashTokens;
        // A reference to the wizard
        WizardLibrary.WizardLibrary wizard;

        public LanguageOptions()
        {
            // This call is required by the Windows.Forms Form Designer.
            InitializeComponent();

            wizard = null;

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
            this.chkSyntaxColor = new System.Windows.Forms.CheckBox();
            this.chkDefaultColors = new System.Windows.Forms.CheckBox();
            this.chkSyntaxCheck = new System.Windows.Forms.CheckBox();
            this.chkBlockComment = new System.Windows.Forms.CheckBox();
            this.chkBraceMatch = new System.Windows.Forms.CheckBox();
            this.chkMatchCursor = new System.Windows.Forms.CheckBox();
            this.chkStatCompl = new System.Windows.Forms.CheckBox();
            this.chkQuickInfo = new System.Windows.Forms.CheckBox();
            this.SuspendLayout();
            // 
            // chkSyntaxColor
            // 
            this.chkSyntaxColor.Location = new System.Drawing.Point(8, 8);
            this.chkSyntaxColor.Name = "chkSyntaxColor";
            this.chkSyntaxColor.Size = new System.Drawing.Size(336, 16);
            this.chkSyntaxColor.TabIndex = 0;
            this.chkSyntaxColor.Text = "Enable syntax highlighting";
            // 
            // chkDefaultColors
            // 
            this.chkDefaultColors.Location = new System.Drawing.Point(48, 32);
            this.chkDefaultColors.Name = "chkDefaultColors";
            this.chkDefaultColors.Size = new System.Drawing.Size(288, 16);
            this.chkDefaultColors.TabIndex = 1;
            this.chkDefaultColors.Text = "Use default colors";
            this.chkDefaultColors.Visible = false;
            // 
            // chkSyntaxCheck
            // 
            this.chkSyntaxCheck.Location = new System.Drawing.Point(8, 40);
            this.chkSyntaxCheck.Name = "chkSyntaxCheck";
            this.chkSyntaxCheck.Size = new System.Drawing.Size(328, 20);
            this.chkSyntaxCheck.TabIndex = 2;
            this.chkSyntaxCheck.Text = "Enable syntax checking";
            // 
            // chkBlockComment
            // 
            this.chkBlockComment.Location = new System.Drawing.Point(8, 72);
            this.chkBlockComment.Name = "chkBlockComment";
            this.chkBlockComment.Size = new System.Drawing.Size(320, 16);
            this.chkBlockComment.TabIndex = 3;
            this.chkBlockComment.Text = "Allow block comment and uncomment";
            // 
            // chkBraceMatch
            // 
            this.chkBraceMatch.Location = new System.Drawing.Point(8, 104);
            this.chkBraceMatch.Name = "chkBraceMatch";
            this.chkBraceMatch.Size = new System.Drawing.Size(344, 20);
            this.chkBraceMatch.TabIndex = 4;
            this.chkBraceMatch.Text = "Enable brace matching";
            this.chkBraceMatch.CheckedChanged += new System.EventHandler(this.chkBraceMatch_CheckedChanged);
            // 
            // chkMatchCursor
            // 
            this.chkMatchCursor.Location = new System.Drawing.Point(48, 128);
            this.chkMatchCursor.Name = "chkMatchCursor";
            this.chkMatchCursor.Size = new System.Drawing.Size(304, 16);
            this.chkMatchCursor.TabIndex = 5;
            this.chkMatchCursor.Text = "Match brace at cursor";
            // 
            // chkStatCompl
            // 
            this.chkStatCompl.Location = new System.Drawing.Point(8, 160);
            this.chkStatCompl.Name = "chkStatCompl";
            this.chkStatCompl.Size = new System.Drawing.Size(344, 16);
            this.chkStatCompl.TabIndex = 6;
            this.chkStatCompl.Text = "Enable statement completion";
            // 
            // chkQuickInfo
            // 
            this.chkQuickInfo.Location = new System.Drawing.Point(8, 192);
            this.chkQuickInfo.Name = "chkQuickInfo";
            this.chkQuickInfo.Size = new System.Drawing.Size(344, 16);
            this.chkQuickInfo.TabIndex = 7;
            this.chkQuickInfo.Text = "Enable quick info";
            // 
            // LanguageOptions
            // 
            this.Controls.Add(this.chkQuickInfo);
            this.Controls.Add(this.chkStatCompl);
            this.Controls.Add(this.chkMatchCursor);
            this.Controls.Add(this.chkBraceMatch);
            this.Controls.Add(this.chkBlockComment);
            this.Controls.Add(this.chkSyntaxCheck);
            this.Controls.Add(this.chkDefaultColors);
            this.Controls.Add(this.chkSyntaxColor);
            this.Name = "LanguageOptions";
            this.Size = new System.Drawing.Size(496, 220);
            this.Load += new System.EventHandler(this.LanguageOptions_Load);
            this.ResumeLayout(false);

        }
        #endregion

        #region IWizardPage Members

        public void PerformWork1(WizardLibrary.WizardLibrary wizardLibrary)
        {
            // Set the value of the tokens.
            hashTokens["SyntaxColor"] = "0";    // This token is for custom colors, so disable it.
            hashTokens["SyntaxCheck"] = chkSyntaxCheck.Checked ? "1" : "0";
            hashTokens["MatchBraces"] = chkBraceMatch.Checked ? "1" : "0";
            hashTokens["MatchBracesAtCaret"] = chkMatchCursor.Checked ? "1" : "0";
            hashTokens["ShowCompletion"] = chkStatCompl.Checked ? "1" : "0";
            hashTokens["QuickInfo"] = chkQuickInfo.Checked ? "1" : "0";

            if ( chkBlockComment.Checked )
            {
                hashTokens["CommentFormatDecl"] =
					"override const CommentFormat* getCommentFormat() const;\r\n";

				hashTokens["CommentFormatImpl"] =
					"override const CommentFormat *Service::getCommentFormat() const\r\n" +
					"{\r\n" +
					"    // TODO: Change this definition using the comment formats of your language\r\n" +
					"    static CommentFormat commentFormat = { NULL, \"/*\", \"*/\", false };\r\n" +
					"    return &commentFormat;\r\n" +
					"}\r\n";
			}

            // Get the instance of the TokenProcessor
            TokenProcessor processor = (TokenProcessor)wizardLibrary.customData["TokenProcessor"];
            // Now pass the value of the tokens to the processor
            IDictionaryEnumerator tokens = (IDictionaryEnumerator)hashTokens.GetEnumerator();
            while ( tokens.MoveNext() )
            {
                processor.AddReplace( "%"+(string)tokens.Key+"%", (string)tokens.Value, TokenReplaceType.ReplaceCode );
            }
        }

        public void PerformWork2(WizardLibrary.WizardLibrary wizardLibrary)
        {
            // Do nothing
        }

        public string HeadingLabel
        {
            get
            {
                return @"Language Service Options";
            }
        }

        public string HelpKeyword
        {
            get
            {
                // TODO:  Add TitlePage.HelpKeyword getter implementation
                return "vs.vsip.LangServWiz.langServOpts";
            }
        }

        public string DescriptionLabel
        {
            get
            {
                return "Select the features to support the new language service. " +
                    "Some of these features require updates to the lex or grammar files prior to be functional.";
            }
        }

        public Image Icon
        {
            get
            {
                System.Reflection.Assembly asm = System.Reflection.Assembly.GetExecutingAssembly();
                return System.Drawing.Image.FromStream(asm.GetManifestResourceStream("PackageWizard.SmallArtWork.bmp"));
            }
        }

        public void Initialize(WizardLibrary.WizardLibrary wizardLibrary)
        {
            // save the reference to the wizard
            wizard = wizardLibrary;
            // Initialize the collection of tokens
            hashTokens = new Hashtable();
            hashTokens.Add("SyntaxColor", "0");
            hashTokens.Add("SyntaxCheck", "0");
            hashTokens.Add("SyntaxCheckDelay", "1500");
            hashTokens.Add("MaxErrMsg", "5");
            hashTokens.Add("MatchBraces", "0");
            hashTokens.Add("ShowMatchingBrace", "0");
            hashTokens.Add("MatchBracesAtCaret", "0");
            hashTokens.Add("ShowCompletion", "0");
            hashTokens.Add("SortMemberList", "1");
            hashTokens.Add("QuickInfo", "0");
            hashTokens.Add("CommentFormatImpl", "");
            hashTokens.Add("CommentFormatDecl", "");
        }

        public bool ValidateFields()
        {
            // Save in the wizard's custom data the value of the syntax color check box
            if (wizard.customData.Contains("SyntaxColor"))
            {
                wizard.customData["SyntaxColor"] = chkSyntaxColor.Checked;
            }
            else
            {
                wizard.customData.Add("SyntaxColor", chkSyntaxColor.Checked);
            }
            return true;
        }

        #endregion

        private void LanguageOptions_Load(object sender, System.EventArgs e)
        {
            // Set the default values for the check boxes
            chkSyntaxColor.Checked = true;
            chkDefaultColors.Enabled = false;
            chkDefaultColors.Checked = false;
            chkSyntaxCheck.Checked = true;
            chkBlockComment.Checked = true;
            chkBraceMatch.Checked = true;
            chkMatchCursor.Enabled = true;
            chkMatchCursor.Checked = false;
            chkStatCompl.Checked = true;
            chkQuickInfo.Enabled = true;
        }

        private void chkBraceMatch_CheckedChanged(object sender, System.EventArgs e)
        {
            if ( chkBraceMatch.Checked )
            {
                chkMatchCursor.Enabled = true;
            }
            else
            {
                chkMatchCursor.Checked = false;
                chkMatchCursor.Enabled = false;
            }
        }
    }
}
