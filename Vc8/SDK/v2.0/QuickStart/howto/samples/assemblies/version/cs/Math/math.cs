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
using System.Reflection;


[assembly:AssemblyVersion("5.0.0.0")]
namespace Microsoft.Samples
{
	public sealed class MathSample
	{
		private MathSample() { }

		public static void Main(string[] args)
		{
			while (true)
			{
				Console.WriteLine("Enter Formula: (or q to quit)");

				String formula = Console.ReadLine();

				if (formula == "q" || formula == "Q") break;

				// parse the formula and get the arguments
				Parser p = new Parser();

				try
				{
					Arguments a = p.Parse(formula);
					Int32 arg1 = Convert.ToInt32(a.Arg1, CultureInfo.InvariantCulture);
					Int32 arg2 = Convert.ToInt32(a.Arg2, CultureInfo.InvariantCulture);

					// do the calc and print the results
					Calc c = new Calc();

					Console.WriteLine(c.GetResult(arg1, a.Operator, arg2));
				}
				catch
				{
					Console.WriteLine("Invalid Formula entered.  Valid formulas consist of");
					Console.WriteLine("two numbers and one operator.  For example, 5 * 5");
				}
			}
		}
	}
}
