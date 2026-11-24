using System;
using System.Collections;
using System.ComponentModel;
using System.Drawing;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using Microsoft.VisualStudio.Shell.Interop;

namespace Microsoft.VisualStudio.VSIP.Samples.BasicEditor
{
	/// <summary>
	/// Extension of a RichTextBox
	/// </summary>
	public class MyEditor : RichTextBox
	{
		public MyEditor()
		{
		}

		private void InitializeComponent()
		{
			// 
			// MyEditor
			// 
			this.WordWrap = false;
		}

		/// <summary>
		/// Return the index of the first character on the specified line
		/// </summary>
		/// <param name="line">Line for which you want to get the char index</param>
		/// <returns>Char index where that line can be found in the Text</returns>
		public int GetCharIndexOfLine(int line)
		{

			int LowerPosition = 0;
			int UpperPosition = Text.Length;
			int LowerLine = 0;
			int UpperLine = GetLineFromCharIndex(UpperPosition);

            // Make sure the line is inside the bound of the text, if not, return the bound
			if (line <= LowerPosition)
				return LowerPosition;
			else if (line > UpperLine)
				return UpperPosition;

			int CurrentPosition = LowerPosition;
			int CurrentLine = LowerLine;
			bool Increasing = true;
			int DeltaLine = line;
			int DeltaPosition = 0;
			int LinesLeft = UpperLine;

			// Look for the line
			while(CurrentLine != line)
			{
				DeltaLine = line - CurrentLine;

				if (Increasing)
				{
					LowerPosition = CurrentPosition;
					LowerLine = CurrentLine;
					DeltaPosition = UpperPosition - CurrentPosition;
					LinesLeft = UpperLine - CurrentLine;
				}
				else
				{
					UpperPosition = CurrentPosition;
					UpperLine = CurrentLine;
					DeltaPosition = LowerPosition - CurrentPosition;
					LinesLeft = CurrentLine - LowerLine;
				}

				// As we get closer move to a more binary like search to compensate for the fact that one line could be long and the other short
				if (LinesLeft < 2)
					LinesLeft = 2;

				// Calculate offset to next position
				int Delta = DeltaPosition * DeltaLine / LinesLeft;
				if (Delta == 0)
				{
					if (Increasing)
						Delta = 1;
					else
						Delta = -1;
				}

				// Set new position
				CurrentPosition += Delta;
				CurrentLine = GetLineFromCharIndex(CurrentPosition);
				Increasing = CurrentLine < line;
			}

			// Now that we found the line, find the first character on that line
			while(GetLineFromCharIndex(CurrentPosition) == line)
			{
				--CurrentPosition;
			}
			
			return CurrentPosition + 1;
		}

	}
}
