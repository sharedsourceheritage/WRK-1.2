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
using System.IO;

namespace PackageWizard
{
    /// <summary>
    /// Summary description for GrammarFiles.
    /// </summary>
    public class GrammarFiles : System.Windows.Forms.UserControl, WizardLibrary.IWizardPage
    {
        private System.Windows.Forms.OpenFileDialog dlgParserFile;
        /// <summary> 
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.Container components = null;
        private System.Windows.Forms.CheckBox chkDefault;
        private System.Windows.Forms.TabControl tabFiles;
        private System.Windows.Forms.TabPage tabpageLex;
        private System.Windows.Forms.TabPage tabpageGram;
        private System.Windows.Forms.TextBox txtLexCommand;
        private System.Windows.Forms.Label lblLexCommand;
        private System.Windows.Forms.Button cmdFindLexFile;
        private System.Windows.Forms.TextBox txtLexFile;
        private System.Windows.Forms.Label lblLex1;
        private System.Windows.Forms.TextBox txtParserCommand;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button cmdFindParseFile;
        private System.Windows.Forms.TextBox txtParserFile;
        private System.Windows.Forms.Label lblGrammar;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox txtGramH;
        private System.Windows.Forms.TextBox txtGramCpp;
        private System.Windows.Forms.TextBox txtLexCpp;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox txtLexH;
        private System.Windows.Forms.Label label5;

        private WizardLibrary.WizardLibrary m_wizard;

        private string strToolsPath;
        
        private string strFlexExe;
        private string strDefaultFlexCmd;

        private string strBisonExe;
        private string strDefaultBisonCmd;

        public GrammarFiles()
        {
            // This call is required by the Windows.Forms Form Designer.
            InitializeComponent();

            // TODO: Add any initialization after the InitializeComponent call

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

        private void SetDefaultFileNames()
        {
            // Find the default path/name for the grammar and lex files
            string strTemplatePath = System.IO.Path.Combine(m_wizard.WizardTemplatesDir, "LP");

            txtParserFile.Text = System.IO.Path.Combine(strTemplatePath, "parser.y");
            txtGramH.Text = "parser.cpp.h";
            txtGramCpp.Text = "parser.cpp";

            txtLexFile.Text = System.IO.Path.Combine(strTemplatePath, "lexer.lex");
            txtLexH.Text = "";
            txtLexCpp.Text = "lexer.cpp";
        }

        #region Component Designer generated code
        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.dlgParserFile = new System.Windows.Forms.OpenFileDialog();
            this.chkDefault = new System.Windows.Forms.CheckBox();
            this.tabFiles = new System.Windows.Forms.TabControl();
            this.tabpageLex = new System.Windows.Forms.TabPage();
            this.txtLexCpp = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.txtLexH = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.txtLexCommand = new System.Windows.Forms.TextBox();
            this.lblLexCommand = new System.Windows.Forms.Label();
            this.cmdFindLexFile = new System.Windows.Forms.Button();
            this.txtLexFile = new System.Windows.Forms.TextBox();
            this.lblLex1 = new System.Windows.Forms.Label();
            this.tabpageGram = new System.Windows.Forms.TabPage();
            this.txtGramCpp = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.txtGramH = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.txtParserCommand = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.cmdFindParseFile = new System.Windows.Forms.Button();
            this.txtParserFile = new System.Windows.Forms.TextBox();
            this.lblGrammar = new System.Windows.Forms.Label();
            this.tabFiles.SuspendLayout();
            this.tabpageLex.SuspendLayout();
            this.tabpageGram.SuspendLayout();
            this.SuspendLayout();
            // 
            // chkDefault
            // 
            this.chkDefault.Location = new System.Drawing.Point(8, 8);
            this.chkDefault.Name = "chkDefault";
            this.chkDefault.Size = new System.Drawing.Size(456, 16);
            this.chkDefault.TabIndex = 0;
            this.chkDefault.Text = "Use default lexer and parser";
            this.chkDefault.CheckedChanged += new System.EventHandler(this.chkDefault_CheckedChanged);
            // 
            // tabFiles
            // 
            this.tabFiles.Controls.Add(this.tabpageLex);
            this.tabFiles.Controls.Add(this.tabpageGram);
            this.tabFiles.Location = new System.Drawing.Point(8, 32);
            this.tabFiles.Name = "tabFiles";
            this.tabFiles.SelectedIndex = 0;
            this.tabFiles.Size = new System.Drawing.Size(480, 184);
            this.tabFiles.TabIndex = 1;
            // 
            // tabpageLex
            // 
            this.tabpageLex.Controls.Add(this.txtLexCpp);
            this.tabpageLex.Controls.Add(this.label4);
            this.tabpageLex.Controls.Add(this.txtLexH);
            this.tabpageLex.Controls.Add(this.label5);
            this.tabpageLex.Controls.Add(this.txtLexCommand);
            this.tabpageLex.Controls.Add(this.lblLexCommand);
            this.tabpageLex.Controls.Add(this.cmdFindLexFile);
            this.tabpageLex.Controls.Add(this.txtLexFile);
            this.tabpageLex.Controls.Add(this.lblLex1);
            this.tabpageLex.Location = new System.Drawing.Point(4, 22);
            this.tabpageLex.Name = "tabpageLex";
            this.tabpageLex.Size = new System.Drawing.Size(472, 158);
            this.tabpageLex.TabIndex = 0;
            this.tabpageLex.Text = "Lexer";
            // 
            // txtLexCpp
            // 
            this.txtLexCpp.Location = new System.Drawing.Point(112, 112);
            this.txtLexCpp.Name = "txtLexCpp";
            this.txtLexCpp.Size = new System.Drawing.Size(312, 20);
            this.txtLexCpp.TabIndex = 6;
            this.txtLexCpp.Text = "";
            // 
            // label4
            // 
            this.label4.Location = new System.Drawing.Point(0, 112);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(112, 16);
            this.label4.TabIndex = 19;
            this.label4.Text = "Output sources:";
            // 
            // txtLexH
            // 
            this.txtLexH.Location = new System.Drawing.Point(112, 88);
            this.txtLexH.Name = "txtLexH";
            this.txtLexH.Size = new System.Drawing.Size(312, 20);
            this.txtLexH.TabIndex = 5;
            this.txtLexH.Text = "";
            // 
            // label5
            // 
            this.label5.Location = new System.Drawing.Point(0, 88);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(112, 16);
            this.label5.TabIndex = 17;
            this.label5.Text = "Output headers:";
            // 
            // txtLexCommand
            // 
            this.txtLexCommand.Location = new System.Drawing.Point(112, 32);
            this.txtLexCommand.Multiline = true;
            this.txtLexCommand.Name = "txtLexCommand";
            this.txtLexCommand.Size = new System.Drawing.Size(312, 48);
            this.txtLexCommand.TabIndex = 4;
            this.txtLexCommand.Text = "";
            // 
            // lblLexCommand
            // 
            this.lblLexCommand.Location = new System.Drawing.Point(0, 32);
            this.lblLexCommand.Name = "lblLexCommand";
            this.lblLexCommand.Size = new System.Drawing.Size(104, 16);
            this.lblLexCommand.TabIndex = 10;
            this.lblLexCommand.Text = "Command line:";
            // 
            // cmdFindLexFile
            // 
            this.cmdFindLexFile.Location = new System.Drawing.Point(432, 8);
            this.cmdFindLexFile.Name = "cmdFindLexFile";
            this.cmdFindLexFile.Size = new System.Drawing.Size(40, 24);
            this.cmdFindLexFile.TabIndex = 3;
            this.cmdFindLexFile.Text = "...";
            this.cmdFindLexFile.Click += new System.EventHandler(this.cmdFindLexFile_Click);
            // 
            // txtLexFile
            // 
            this.txtLexFile.Location = new System.Drawing.Point(112, 8);
            this.txtLexFile.Name = "txtLexFile";
            this.txtLexFile.Size = new System.Drawing.Size(312, 20);
            this.txtLexFile.TabIndex = 2;
            this.txtLexFile.Text = "lexer.lex";
            // 
            // lblLex1
            // 
            this.lblLex1.Location = new System.Drawing.Point(0, 8);
            this.lblLex1.Name = "lblLex1";
            this.lblLex1.Size = new System.Drawing.Size(104, 16);
            this.lblLex1.TabIndex = 7;
            this.lblLex1.Text = "Source file:";
            // 
            // tabpageGram
            // 
            this.tabpageGram.Controls.Add(this.txtGramCpp);
            this.tabpageGram.Controls.Add(this.label3);
            this.tabpageGram.Controls.Add(this.txtGramH);
            this.tabpageGram.Controls.Add(this.label2);
            this.tabpageGram.Controls.Add(this.txtParserCommand);
            this.tabpageGram.Controls.Add(this.label1);
            this.tabpageGram.Controls.Add(this.cmdFindParseFile);
            this.tabpageGram.Controls.Add(this.txtParserFile);
            this.tabpageGram.Controls.Add(this.lblGrammar);
            this.tabpageGram.Location = new System.Drawing.Point(4, 22);
            this.tabpageGram.Name = "tabpageGram";
            this.tabpageGram.Size = new System.Drawing.Size(472, 158);
            this.tabpageGram.TabIndex = 1;
            this.tabpageGram.Text = "Parser";
            // 
            // txtGramCpp
            // 
            this.txtGramCpp.Location = new System.Drawing.Point(112, 112);
            this.txtGramCpp.Name = "txtGramCpp";
            this.txtGramCpp.Size = new System.Drawing.Size(312, 20);
            this.txtGramCpp.TabIndex = 11;
            this.txtGramCpp.Text = "";
            // 
            // label3
            // 
            this.label3.Location = new System.Drawing.Point(0, 112);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(112, 16);
            this.label3.TabIndex = 15;
            this.label3.Text = "Output sources:";
            // 
            // txtGramH
            // 
            this.txtGramH.Location = new System.Drawing.Point(112, 88);
            this.txtGramH.Name = "txtGramH";
            this.txtGramH.Size = new System.Drawing.Size(312, 20);
            this.txtGramH.TabIndex = 10;
            this.txtGramH.Text = "";
            // 
            // label2
            // 
            this.label2.Location = new System.Drawing.Point(0, 88);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(112, 16);
            this.label2.TabIndex = 13;
            this.label2.Text = "Output headers:";
            // 
            // txtParserCommand
            // 
            this.txtParserCommand.Location = new System.Drawing.Point(112, 32);
            this.txtParserCommand.Multiline = true;
            this.txtParserCommand.Name = "txtParserCommand";
            this.txtParserCommand.Size = new System.Drawing.Size(312, 48);
            this.txtParserCommand.TabIndex = 9;
            this.txtParserCommand.Text = "";
            // 
            // label1
            // 
            this.label1.Location = new System.Drawing.Point(0, 32);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(104, 16);
            this.label1.TabIndex = 12;
            this.label1.Text = "Command line:";
            // 
            // cmdFindParseFile
            // 
            this.cmdFindParseFile.Location = new System.Drawing.Point(432, 8);
            this.cmdFindParseFile.Name = "cmdFindParseFile";
            this.cmdFindParseFile.Size = new System.Drawing.Size(40, 24);
            this.cmdFindParseFile.TabIndex = 8;
            this.cmdFindParseFile.Text = "...";
            this.cmdFindParseFile.Click += new System.EventHandler(this.cmdFindParseFile_Click);
            // 
            // txtParserFile
            // 
            this.txtParserFile.Location = new System.Drawing.Point(112, 8);
            this.txtParserFile.Name = "txtParserFile";
            this.txtParserFile.Size = new System.Drawing.Size(312, 20);
            this.txtParserFile.TabIndex = 7;
            this.txtParserFile.Text = "parser.y";
            // 
            // lblGrammar
            // 
            this.lblGrammar.Location = new System.Drawing.Point(0, 8);
            this.lblGrammar.Name = "lblGrammar";
            this.lblGrammar.Size = new System.Drawing.Size(88, 16);
            this.lblGrammar.TabIndex = 8;
            this.lblGrammar.Text = "Source file:";
            // 
            // GrammarFiles
            // 
            this.Controls.Add(this.tabFiles);
            this.Controls.Add(this.chkDefault);
            this.Name = "GrammarFiles";
            this.Size = new System.Drawing.Size(496, 220);
            this.Load += new System.EventHandler(this.GrammarFiles_Load);
            this.tabFiles.ResumeLayout(false);
            this.tabpageLex.ResumeLayout(false);
            this.tabpageGram.ResumeLayout(false);
            this.ResumeLayout(false);

        }
        #endregion

        #region IWizardPage Members

        public void PerformWork1(WizardLibrary.WizardLibrary wizardLibrary)
        {
            // Get the token processor.
            TokenProcessor processor = (TokenProcessor)wizardLibrary.customData["TokenProcessor"];

            // Add to the processor the tokens for the parser and lexer files
            processor.AddReplace("%ParserFileName%", Path.GetFileName(txtParserFile.Text), TokenReplaceType.ReplaceString);
            processor.AddReplace("%ParserFileNameNoExt%", Path.GetFileNameWithoutExtension(txtParserFile.Text), TokenReplaceType.ReplaceString);
            processor.AddReplace("%ParserCommand%", txtParserCommand.Text, TokenReplaceType.ReplaceString);

            processor.AddReplace("%LexFileName%", Path.GetFileName(txtLexFile.Text), TokenReplaceType.ReplaceString);
            processor.AddReplace("%LexFileNameNoExt%", Path.GetFileNameWithoutExtension(txtLexFile.Text), TokenReplaceType.ReplaceString);
            processor.AddReplace("%LexerCommand%", txtLexCommand.Text, TokenReplaceType.ReplaceString);

            // Save in the registry if use the default
            m_wizard.SetRegistryValue("Use Defaults", chkDefault.Checked ? 1 : 0);

            // If we are not using the defaults, then save also the command lines
            if ( !chkDefault.Checked )
            {
                m_wizard.SetRegistryValue("Parser Command", txtParserCommand.Text);
                m_wizard.SetRegistryValue("Lexer Command", txtLexCommand.Text);
            }

            // Build the list of the include file.
            string strDotH = txtLexH.Text.Trim();
            if ( txtGramH.Text.Trim() != "" )
            {
                if ( strDotH != "" )
                {
                    strDotH += ";";
                }
                strDotH += txtGramH.Text.Trim();
            }
            // The list of files is delimited by ';', so split it
            string [] strIncludes = strDotH.Split(';');
            // Now build the C++ code to include the files
            string strCppInclude = "";
            foreach (string inc in strIncludes)
            {
                strCppInclude += "#include \"" + inc + "\"\r\n";
            }
            // Replace the include statment in the template file(s)
            processor.AddReplace("%IncludeList%", strCppInclude, TokenReplaceType.ReplaceCode);

            // Build the list of output files for the lexer
            string strLexOut = txtLexH.Text.Trim();
            if ( txtLexCpp.Text.Trim() != "" )
            {
                if ( strLexOut != "" )
                {
                    strLexOut += ";";
                }
                strLexOut += txtLexCpp.Text.Trim();
            }
            processor.AddReplace("%LexOutFiles%", strLexOut, TokenReplaceType.ReplaceString);

            // Build the list of output files for the grammar tool
            string strGramOut = txtGramH.Text.Trim();
            if ( txtGramCpp.Text.Trim() != "" )
            {
                if ( strGramOut != "" )
                {
                    strGramOut += ";";
                }
                strGramOut += txtGramCpp.Text.Trim();
            }
            processor.AddReplace("%GramOutFiles%", strGramOut, TokenReplaceType.ReplaceString);

            // Now build the list of the files generate by the user's tools
            // and that need to be compiled
            string strCppFiles = txtLexCpp.Text.Trim();
            if ( txtGramCpp.Text.Trim() != "" )
            {
                if ( strCppFiles != "" )
                {
                    strCppFiles += ";";
                }
                strCppFiles += txtGramCpp.Text.Trim();
            }
            string [] filesList = strCppFiles.Split(';');
            // Build the xml string that describes additional source files in the project
            string strFiles = "";
            foreach (string cpp in filesList)
            {
                strFiles += "<File\r\nRelativePath=\".\\";
                strFiles += cpp + "\">\r\n";
                strFiles += "</File>\r\n";
            }
            // Pass the string to the token processor
            processor.AddReplace("%AdditionalSources%", strFiles, TokenReplaceType.ReplaceCode);
        }

        public void PerformWork2(WizardLibrary.WizardLibrary wizardLibrary)
        {
            // Create copies of the lexer and parser files in the project folder
            string strDestinationFile = Path.Combine(wizardLibrary.newProjectLocation, Path.GetFileName(txtParserFile.Text));
            File.Copy(txtParserFile.Text, strDestinationFile);

            strDestinationFile = Path.Combine(wizardLibrary.newProjectLocation, Path.GetFileName(txtLexFile.Text));
            File.Copy(txtLexFile.Text, strDestinationFile);
        }

        public string HeadingLabel
        {
            get
            {
                return "Language Specification";
            }
        }

        public string HelpKeyword
        {
            get
            {
                // TODO:  Add TitlePage.HelpKeyword getter implementation
                return "vs.vsip.LangServWiz.langSpec";
            }
        }

        public string DescriptionLabel
        {
            get
            {
                return "Specify the files defining the new language.";
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
            m_wizard = wizardLibrary;

            strToolsPath = m_wizard.InstallDir;
            strToolsPath += @"\babel\tools";
        
            strFlexExe = strToolsPath + @"\Flex.exe";
            strDefaultFlexCmd = "\"" + strFlexExe + "\" -o$(InputName).cpp $(InputName).lex\r\n";

            strBisonExe = strToolsPath + @"\bison.exe";
            strDefaultBisonCmd = "set INIT=" + strToolsPath + "\r\n\"" + strBisonExe + "\" -v -o$(InputName).cpp -d $(InputName).y\r\n";

            SetDefaultFileNames();
            // Find out if the "Use default" check box must be selected
            int iSelected = m_wizard.GetRegistryValue("Use Defaults", 1);
            chkDefault.Checked = (iSelected != 0);

            if ( chkDefault.Checked )
            {
                // Get the default values for the parser and lexer command line
                txtLexCommand.Text = strDefaultFlexCmd;
                txtParserCommand.Text = strDefaultBisonCmd;
            }
            else
            {
                // Get the last used command lines
                txtLexCommand.Text = m_wizard.GetRegistryValue("Lexer Command", strDefaultFlexCmd);
                txtParserCommand.Text = m_wizard.GetRegistryValue("Parser Command", strDefaultBisonCmd);
            }
        }

        public bool ValidateFields()
        {
            // Check that the parser file exists
            if ( !File.Exists(txtParserFile.Text) )
            {
                MessageBox.Show(this, "Parser file " + txtParserFile.Text + " doesn't exist.", "Microsoft Development Environment", MessageBoxButtons.OK, MessageBoxIcon.Error);
                txtParserFile.Focus();
                return false;
            }
            // Here the parser file is correct, so we can save it in the wizard custom data
            if (m_wizard != null)
            {
                if ( m_wizard.customData.Contains("GrammarFile") )
                {
                    m_wizard.customData["GrammarFile"] = txtParserFile.Text;
                    m_wizard.customData["IsDefaultGrammar"] = chkDefault.Checked;
                }
                else
                {
                    m_wizard.customData.Add("GrammarFile", txtParserFile.Text);
                    m_wizard.customData.Add("IsDefaultGrammar", chkDefault.Checked);
                }
            }

            // Check that the lexer file exists
            if ( !File.Exists(txtLexFile.Text) )
            {
                MessageBox.Show(this, "Lexer file " + txtParserFile.Text + " doesn't exist.", "Microsoft Development Environment", MessageBoxButtons.OK, MessageBoxIcon.Error);
                txtLexFile.Focus();
                return false;
            }

            // Check that at lest one output source file is specified.
            string strCpp = txtLexCpp.Text.Trim();
            if ( txtGramCpp.Text.Trim().Length > 0 )
            {
                if ( strCpp.Length > 0 )
                {
                    strCpp += ";";
                }
                strCpp += txtGramCpp.Text.Trim();
            }
            if ( strCpp.Length == 0 )
            {
                MessageBox.Show(this, "You must specify at least one output source file.", "Microsoft Development Environment", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            // TODO: we have to validate the list of the source files, but by now it is not
            // clear how to do it.

            // In the case of default, check that the flexer and bison tools are in the
            // expected place
            if ( chkDefault.Checked )
            {
                string strBisonFullPath = Path.Combine(m_wizard.newProjectLocation, strBisonExe);
                string strFlexFullPath = Path.Combine(m_wizard.newProjectLocation, strFlexExe);
                if ( !File.Exists(strBisonFullPath) || !File.Exists(strFlexFullPath) )
                {
                    // If the tools are not where expected, warn the user, but don't
                    // fail the operation
                    DialogResult res = MessageBox.Show(this, "One or more build tools are not in the expected location, therefore the build process will fail for the generated project.\rDo you want to continue?", "Microsoft Development Environment", MessageBoxButtons.YesNo, MessageBoxIcon.Warning);
                    if (DialogResult.No == res)
                    {
                        return false;
                    }
                }
            }

            // All the fields are valid
            return true;
        }

        #endregion

        private void cmdFindParseFile_Click(object sender, System.EventArgs e)
        {
            dlgParserFile.Filter = "Grammar files(*.y)|*.y|All Files(*.*)|*.*";
            dlgParserFile.ShowDialog(this);
            if (dlgParserFile.FileName != "")
            {
                txtParserFile.Text = dlgParserFile.FileName;
            }
        }

        private void cmdFindLexFile_Click(object sender, System.EventArgs e)
        {
            try
            {
                dlgParserFile.Filter = "Lexer files(*.lex)|*.lex|All Files(*.*)|*.*";
                dlgParserFile.ShowDialog(this);
                if (dlgParserFile.FileName != "")
                {
                    txtLexFile.Text = dlgParserFile.FileName;
                }
            }
            catch(Exception ex)
            {
                MessageBox.Show(this, ex.Message, "Microsoft Development Environment", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void GrammarFiles_Load(object sender, System.EventArgs e)
        {
            chkDefault.Checked = true;
        }

        private void chkDefault_CheckedChanged(object sender, System.EventArgs e)
        {
            if ( chkDefault.Checked )
            {
                // If the user wants to use the default, then the text boxes for file
                // selection must be disabled.
                SetDefaultFileNames();

                // Set the default value for the command lines
                txtLexCommand.Text = strDefaultFlexCmd;
                txtParserCommand.Text = strDefaultBisonCmd;

                txtParserFile.Enabled = false;
                cmdFindParseFile.Enabled = false;
                txtParserCommand.Enabled = false;
                txtGramH.Enabled = false;
                txtGramCpp.Enabled = false;

                txtLexFile.Enabled = false;
                cmdFindLexFile.Enabled = false;
                txtLexCommand.Enabled = false;
                txtLexH.Enabled = false;
                txtLexCpp.Enabled = false;
            }
            else
            {
                txtParserFile.Enabled = true;
                cmdFindParseFile.Enabled = true;
                txtParserCommand.Enabled = true;
                txtGramH.Enabled = true;
                txtGramCpp.Enabled = true;

                txtLexFile.Enabled = true;
                cmdFindLexFile.Enabled = true;
                txtLexCommand.Enabled = true;
                txtLexH.Enabled = true;
                txtLexCpp.Enabled = true;
            }
        }

    }
}
