using System;
using System.Globalization;
using System.Text;

/*=====================================================================

  File:      SurrogateStringFuntion.cs for Surrogate Strings Manipulation 
Object SQLCLR Example
  Summary:   Defines SQLCLR based functions for the equivalent string functions of LEN(), RIGHT(), LEFT() 
	     REPLACE(),... but with support of surrogate strings.
  Date:	     September 15, 2003

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

namespace Microsoft.Samples.SqlServer
{
	/// <summary>
	/// Include several string functions for T-SQL to manipulate surrogate characters.
	/// </summary>
	public sealed class SurrogateStringFunction
	{
		/// <summary>
		///	
		/// </summary>
		private SurrogateStringFunction()
		{	}

		/// <summary>
		/// LenS is equal to T-SQL string function LEN() which returns the number
		/// of characters, rather than the number of bytes, of the given string expression.
		/// </summary>
		/// <param name="value">The input string.</param>
		/// <returns>The number of characters in the string.</returns>
		public static long LenS(String value)
		{
			int[] myIndex;
			// Remove trailing spaces for situations when the Transact-SQL variable or table column
			// uses a fixed length datatype such as nchar(50).
			// If the trailing spaces are not excluded, this function will return 50 which is not
			// correct or expected.
			myIndex = StringInfo.ParseCombiningCharacters(value.TrimEnd());
			return (null != myIndex) ? myIndex.Length : 0;
		}

		/// <summary>
		/// SubS only support character expression of T-SQL funciton SUBSTRING()
		/// which returns part of a string.
		/// </summary>
		/// <param name="value">The input string.</param>
		/// <param name="start">The position of the first character that will be returned.</param>
		/// <param name="length">The number of characters to return.</param>
		/// <returns>The string found at the starting position for the specified
		/// number characters.</returns>
		public static String SubS(String value, int start, int length)
		{
            if (length < 0)
                throw new ArgumentException("Invalid length parameter passed to the substring function.");

			// In Transact-SQL, the substring method initializes to 1. So, start should be initialized to at least 1.
			// Length also has to be at least 1 or the Transact-SQL result would be an empty string.
            if ((start + length) <= 1)
                return (String.Empty);

			// The 2 if statements below guarentee that the result will match the substring function in 
			// Transact-SQL which will initialize start to 1 by subtracting from the length.
            if (start <= 0 && length > 0)
                length--;

            if ((start <= 0))
            {
                length = length + start;
                start = 1;
            }

            int[] myIndex;
			myIndex = StringInfo.ParseCombiningCharacters(value);
			int NumOfIndexes = (null != myIndex) ? myIndex.Length : 0;

            start--;
            if ((0 <= start) && (start < NumOfIndexes))
			{
				int lastIndex = start + length;

				// if we are past the last char, then we get the string
				// up to the last char 
				if (lastIndex > (NumOfIndexes - 1))
				{
					return value.Substring(myIndex[start]);
				}
				else
				{
					return value.Substring(myIndex[start], myIndex[lastIndex] - myIndex[start]);
				}
			}
			else
			{
				return String.Empty;
			}
		}

		// 
		//    
		/// <summary>
		/// LeftS is equal to T-SQL string function LEFT() which returns the left
		/// part of a character string with the specified number of characters.
		/// </summary>
		/// <param name="value">The input string.</param>
		/// <param name="start">The position of the first character that will be returned.</param>
		/// <param name="length">The number of characters to return.</param>
		/// <returns>The string found at the starting position for n-length.</returns>
		public static String LeftS(String value, int length )
		{
			if (length < 0)
				throw new ArgumentException("length must be a positive integer");

			return SubS(value, 1, length);			
		}

		// RightS is equal to T-SQL string function RIGHT() which returns the right
		//    part of a character string with the specified number of characters.
		public static String RightS(String value, int length)
		{
			if (length < 0)
				throw new NotSupportedException("length must be a positive integer");

			int[] myIndex;

			myIndex = StringInfo.ParseCombiningCharacters(value);
			int numOfIndexes = (null != myIndex) ? myIndex.Length : 0;

			if (numOfIndexes <= length)
				return value;

			if (length == 0) return String.Empty;

			int virtualStartIndex = numOfIndexes - length;
			int physicalStartIndex = myIndex[virtualStartIndex];
			return value.Substring(physicalStartIndex);
			
		}

		//
		// ReplaceS is equal to T-SQL string function REPLACE() which replaces all
		// occurrences of the second given string expression in the first string expression
		// with a third expression.
		//
		public static String ReplaceS(String value, String replaceValue, String newValue)
		{
			StringBuilder result = new StringBuilder(value.Length);
			int[] myIndex;
			int i = 0;
			String upperValue = value.ToUpper(CultureInfo.CurrentUICulture);
			String upperReplaceValue = replaceValue.ToUpper(CultureInfo.CurrentUICulture);

			myIndex = StringInfo.ParseCombiningCharacters(upperValue);
			int numOfIndexes = (null != myIndex) ? myIndex.Length : 0;
			while (i < value.Length)
			{
				int possibleMatch = upperValue.IndexOf(upperReplaceValue, i);
				if (possibleMatch < 0)
				{
					result.Append(value.Substring(i));
					break;
				}
				else
				{
					//Ensure we're not matching a partial surrogate
					int surrogateIndex = Array.IndexOf<int>(myIndex, possibleMatch);
					if (surrogateIndex < 0)
					{
						//We've matched in the middle of a surrogate, skip this match
						//as it is not valid.
						int nextStart = possibleMatch + 1;
						result.Append(value.Substring(i, nextStart-i));
						i = nextStart;
					}
					else
					{
						//This is a valid match.  Make the substitution.
						result.Append(value.Substring(i, possibleMatch - i));
						result.Append(newValue);
						i = possibleMatch + replaceValue.Length;
					}
				}
			}
			return result.ToString();
		}
	}
}
