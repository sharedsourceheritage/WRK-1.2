//-----------------------------------------------------------------------
//  This file is part of the Microsoft .NET Framework SDK Code Samples.
// 
//  Copyright (C) Microsoft Corporation.  All rights reserved.
// 
//This source code is intended only as a supplement to Microsoft
//Development Tools and/or on-line documentation.  See these other
//materials for detailed information regarding Microsoft code samples.
// 
//THIS CODE AND INFORMATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY
//KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//PARTICULAR PURPOSE.
//-----------------------------------------------------------------------

using System;
using System.Globalization;
using System.Runtime.CompilerServices;
using System.Reflection;

namespace Microsoft.Samples
{
	public class MathSample
	{
		public String GetResult(int arg1, Char op, int arg2)
		{
			switch (op)
			{
				case '+':
					return String.Format("Result: {0:G}", arg1 + arg2);

				case '-':
					return String.Format("Result: {0:G}", arg1 - arg2);

				case '*':
					return String.Format("Result: {0:G}", arg1 * arg2);

				case '/':
					return String.Format("Result: {0:G}", arg1 / arg2);

				default:
					return "Invalid operator: " + op;
			}
		}

		public static void Main(string[] args)
		{
			while (true)
			{
				Console.WriteLine("Enter a simple formula. Ex: 4+4: (or q to quit)");

				String formula = Console.ReadLine();

				if (formula == "q" || formula == "Q") break;

				// parse the formula and get the arguments
				Parser p = new Parser();

				try
				{
					Arguments a = p.Parse(formula);

					// do the calc and print the results
					MathSample m = new MathSample();

					Console.WriteLine(m.GetResult(Convert.ToInt32(a.Arg1, CultureInfo.InvariantCulture), a.Operator, Convert.ToInt32(a.Arg2, CultureInfo.InvariantCulture)));
				}
				catch (Exception e)
				{
					Console.WriteLine(e.Message);
				}				
			}
		}
	}
}