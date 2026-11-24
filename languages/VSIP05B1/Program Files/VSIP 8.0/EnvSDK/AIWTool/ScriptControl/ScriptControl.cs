#region Using directive

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Text;
using System.Windows.Forms;

#endregion

namespace ScriptControl
{
	public partial class ScriptControl: System.Windows.Forms.UserControl, AIWTool.Interop.IVBSCommandLine
	{
        private Microsoft.VisualBasic.VBCodeProvider scriptEngine;
        private const string vbSnippetBegin = "Module SnippetModule\nSub Main()\n";
        private const string vbSnippetEnd = "\nEnd Sub\nEnd Module\n";
		private string accumulateText;

		public ScriptControl()
		{
			InitializeComponent();

            scriptEngine = new Microsoft.VisualBasic.VBCodeProvider();
			accumulateText = "";
		}

        private void PrintHelp()
        {
            string helpMessage =
                        "\nHELP\n" +
                        "  ? = Show this help\n" +
                        "  ? expr = Evaluate 'expr'; output result\n" +
                        "  < filename = Read 'filename'; evaluate contents\n" +
                        //"  output x[,y][,z][,a][,c][,d][,e] = Evaluate each expr, output results\n" +
                        //"  readfile filename[,true|false] = Read 'filename'; evaluate contents [with opt. echo]\n" +
                        "  cls = Clear the screen\n";
            Font originalFont = richTextBox1.Font;
            FontStyle helpStyle = (originalFont.Style | FontStyle.Italic) & (~FontStyle.Bold);
            
            // Set the font style for the help.
            richTextBox1.SelectionFont = new Font(originalFont, helpStyle);
            richTextBox1.SelectedText = helpMessage;
            // Reset the original font
            richTextBox1.Font = originalFont;
        }

        private void PrintError(string errorMessage)
        {
            // Get the original font of the text box
            Font originalFont = richTextBox1.Font;
            FontStyle errorStyle = originalFont.Style | FontStyle.Bold | FontStyle.Italic;
            richTextBox1.SelectionFont = new Font(originalFont, errorStyle);
            richTextBox1.SelectedText = "\n\tERROR:\n" + errorMessage + "\n";
            // Reset the original font
            richTextBox1.SelectionFont = originalFont;
        }

        private void PrintOutput(string message)
        {
            Font originalFont = richTextBox1.Font;
            FontStyle outputStyle = (originalFont.Style | FontStyle.Italic) & (~FontStyle.Bold);
            richTextBox1.SelectionFont = new Font(originalFont, outputStyle);
            richTextBox1.SelectedText += message;
            richTextBox1.SelectionFont = originalFont;
        }

        private void EvaluateExprFromString(string expression)
        {
            // Get the compiler object from the engine.
            System.CodeDom.Compiler.ICodeCompiler compiler = scriptEngine.CreateCompiler();
            if (compiler == null)
                throw new System.Exception("Can't get the compiler.");

            // Get the compilation settings.
            System.CodeDom.Compiler.CompilerParameters cp = CompilerSettings;

            // Make this code compilable adding a class definition and a static Main()
            string snippetCode = string.Format("{0}\n{1}\n{2}", vbSnippetBegin, expression, vbSnippetEnd);
            System.CodeDom.CodeSnippetCompileUnit snippet = new System.CodeDom.CodeSnippetCompileUnit(snippetCode);

            // Now compile the expression
            System.CodeDom.Compiler.CompilerResults result =
                compiler.CompileAssemblyFromDom(cp, snippet);
            //compiler.CompileAssemblyFromSource(cp, expression);

            // Process the result of the compilation to show the errors
            // or execute the script.
            ProcessCompilationResult(result);
        }

        private void EvaluateExprFromFile(string fileName)
        {
            // Get the compiler object from the engine.
            System.CodeDom.Compiler.ICodeCompiler compiler = scriptEngine.CreateCompiler();
            if (compiler == null)
                throw new System.Exception("Can't get the compiler.");

            // Get the compilation settings.
            System.CodeDom.Compiler.CompilerParameters cp = CompilerSettings;

            // Now compile the file
            System.CodeDom.Compiler.CompilerResults result =
                compiler.CompileAssemblyFromFile(cp, fileName);

            // Process the result of the compilation to show the errors
            // or execute the script.
            ProcessCompilationResult(result);
        }

        private void ProcessCompilationResult(System.CodeDom.Compiler.CompilerResults result)
        {
            // Check if there is any error
            if (result.Errors.HasErrors)
            {
                StringBuilder errorMessage = new StringBuilder("");
                foreach (System.CodeDom.Compiler.CompilerError err in result.Errors)
                {
                    errorMessage.AppendFormat("Error {0} At ({1},{2}): {3}\n", err.ErrorNumber, err.Line, err.Column, err.ErrorText);
                }
                PrintError(errorMessage.ToString());
                return;
            }

            // Sometime, even if there is no error, the executable is not created.
            if (!System.IO.File.Exists(result.PathToAssembly))
            {
                PrintError("Can't find intermediate file.");
                return;
            }

            // Write an empty line on the output
            PrintOutput("\n");

            // Create a process object to wrap the executable.
            System.Diagnostics.Process process = new System.Diagnostics.Process();
            // Associate it to the new created assembly
            process.StartInfo.FileName = result.PathToAssembly;
            // We want to redirect the standard output on the text box, so
            // don't use the shell's output
            process.StartInfo.UseShellExecute = false;
            process.StartInfo.CreateNoWindow = true;
            // Now we inform the process that we want to redirect the output
            process.StartInfo.RedirectStandardOutput = true;

            // Start the process
            process.Start();

            // Get the standard output in a StreamReader
            System.IO.StreamReader stdOut = process.StandardOutput;

            // Now loop on the output and write it on the text box
            string outLine;
            while ((outLine = stdOut.ReadLine()) != null)
            {
                PrintOutput(outLine+"\n");
            }
            // Wait for the process to exit (actually, if we are here the process is
            // supposed to be exited, anyway it is better to wait).
            process.WaitForExit();
            // Delete the temporary file
            System.IO.File.Delete(result.PathToAssembly);
        }

        // Generates the compiler settings.
        private System.CodeDom.Compiler.CompilerParameters CompilerSettings
        {
            get
            {
                // Always add the reference to System.dll
                string[] references = { "System.dll" };
                // Create the parameter object.
                System.CodeDom.Compiler.CompilerParameters cp =
                    new System.CodeDom.Compiler.CompilerParameters(references);
                // We want to execute the script, so create an executable
                cp.GenerateExecutable = true;
                // We don't care about persist the assembly, so create it in memory
                //cp.GenerateInMemory = true;
                return cp;
            }
        }

		#region IVBSCommandLine Members

		void AIWTool.Interop.IVBSCommandLine.Reset()
		{
			// Do Nothing
		}

		void AIWTool.Interop.IVBSCommandLine.Init(int FontCharset, string FontName, double FontSize)
		{
			// Do Nothing
		}

		void AIWTool.Interop.IVBSCommandLine.AddObject(string bstrName, object pObj, bool fGlobal)
		{
			// Do Nothing
		}

		void AIWTool.Interop.IVBSCommandLine.ReadFile(string bstrFilename, bool fPrintFile)
		{
			// Do NOthing
		}

		void AIWTool.Interop.IVBSCommandLine.ExecuteStatement(string bstrStmt)
		{
			// Do Nothing
		}

#endregion

		void richTextBox1_KeyDown(object sender, System.Windows.Forms.KeyEventArgs e)
		{
			if ((e.KeyCode == System.Windows.Forms.Keys.Return))
			{
				// Check if we need to add the text to the accumulated buffer
				if (e.Shift)
				{
					if (accumulateText.Length > 0)
					{
						accumulateText += "\n";
					}
					if (richTextBox1.SelectionLength > 0)
					{
						accumulateText += richTextBox1.SelectedText;
					}
					else
					{
						accumulateText += GetLine(richTextBox1.Text, richTextBox1.SelectionStart);
					}

					return;
				}
				// The user pressed Return, so let's try to execute the code inserted.
				string commandText;
				if (richTextBox1.SelectionLength == 0)
				{
					commandText = GetLine(richTextBox1.Text, richTextBox1.SelectionStart);
				}
				else
				{
					commandText = richTextBox1.SelectedText;
					richTextBox1.SelectionStart = richTextBox1.SelectionStart + richTextBox1.SelectionLength;
					richTextBox1.SelectionLength = 0;
				}

				// If there is any accumulate text (added to the buffer with <Shift>+<Return>,
				// add it to the command text.
				if (accumulateText.Length > 0)
				{
					commandText = accumulateText + "\n" + commandText;
					// We are executing the command, so we can clear the buffer.
					accumulateText = "";
				}

				// Get rid of the blanks
				commandText = commandText.Trim();

				// If the command is empty, the we don't need to do anything.
				if (commandText.Length == 0)
					return;

				// Check if the command is an expression or an expression
				if (commandText[0] == '?')
				{
					if (commandText.Length == 1)
					{
						// If the command is a simple question mark, then show the help
						PrintHelp();
						return;
					}
					// In this case the expression is everything after the question mark
					string expression = commandText.Substring(1);
					// Let the script engine evaluate this expression
					try
					{
						EvaluateExprFromString(expression);
					}
					catch (System.Exception ex)
					{
						PrintError(ex.Message);
					}
					return;
				}
				// Check if we have to execute the content of a file
				if (commandText[0] == '<')
				{
					string fileName = commandText.Substring(1);
					if (!System.IO.File.Exists(fileName))
					{
						PrintError("Can't find file " + fileName);
						return;
					}
					try
					{
						EvaluateExprFromFile(fileName);
					}
					catch (System.Exception ex)
					{
						PrintError(ex.Message);
					}
					return;
				}
				// Check if the command is a CLS 
				if (commandText.CompareTo("cls") == 0)
				{
					// Clear the command window.
					richTextBox1.Text = "";
					// Don't add the new line
					e.Handled = true;
					return;
				}
			}
		}

		// This function will get the line of text containing the position "position"
		private string GetLine(string text, int position)
		{
			// Get the first char in the line
			int startOfLine = position;
			while ((startOfLine > 0) && (text[startOfLine-1] != '\n') && (text[startOfLine-1] != '\r'))
				startOfLine--;

			// Get the last char in the line
			char[] eolChars = {'\n', '\r'};
			int endOfLine = text.IndexOfAny(eolChars, position);
			if (endOfLine == -1)
			{
				endOfLine = text.Length;
			}
			else
			{
				endOfLine--;
			}

			return text.Substring(startOfLine, endOfLine - startOfLine);
		}

	}

}