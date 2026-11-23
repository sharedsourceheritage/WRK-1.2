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

// parser.cpp
using namespace System;

namespace Parser
{
	public ref class Arguments
	{
	public:
		property String^ Arg1;
		property String^ Arg2;
		property Char Op;
	};

	public ref class Parser 
	{
	public:
		Arguments^ Parse(String^ formula) 
		{
			Arguments^ args = gcnew Arguments();

			// get the first arg
			array<Char>^ opsAndSpace = {' ','+','-','*','/'};

			int pos = formula->IndexOfAny(opsAndSpace);
			args->Arg1 = formula->Substring(0, pos);
			args->Arg2 = args->Arg1;

			// skip whitespace to get to the operator
			while (formula[pos] == ' ') 
			{
				pos++;
			}

			// get the operator
			args->Op = Convert::ToChar(formula->Substring(pos, 1));

			// skip whitespace to get to the second arg
			pos++;
			while (formula[pos] == ' ') 
			{
				pos++;
			}

			// get the second arg
			args->Arg2 = formula->Substring(pos);

			return args;
		}
	};
}
