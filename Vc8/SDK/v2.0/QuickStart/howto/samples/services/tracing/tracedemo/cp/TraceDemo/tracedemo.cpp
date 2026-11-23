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

// tracedemo.cpp

#using <mscorlib.dll>
using namespace System;
using namespace System::IO;

#using <System.dll>
using namespace System::Diagnostics;

// Set DWORD value of HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\COMPlus\Switches\TraceMethods to 0 (false) or 1 (true)
// Set DWORD value of HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\COMPlus\Switches\Arithmetic to 0 (off), 1(error), 2 (warning), 3(info), 4(verbose)

public ref class TraceDemo
{
private:
	BooleanSwitch^ traceMethods; 
	TraceSwitch^ arithmeticSwitch;

public:
	TraceDemo()
	{
		Debug::Listeners->Add(gcnew TextWriterTraceListener(Console::Out));
		traceMethods = gcnew BooleanSwitch("TraceMethods", "TraceDemo Method Tracing Switch");
		arithmeticSwitch = gcnew TraceSwitch("Arithmetic", "Arithemtic Operations");
			
		for(Int32 a = 0; a <= 4; a++)
			for(Int32 b = 0; b <= 4; b++)
				Console::WriteLine(String::Concat(a.ToString(), "/", b.ToString(), "=", (Percent(a, b)).ToString()));
	}

	Int64 Divide(Int64 a, Int64 b)
	{
		if (traceMethods->Enabled) 
			Trace::WriteLine(String::Concat("Divide(", a.ToString(), ",", b.ToString(), ") called"));
		
		if (b == 0)
		{
			Trace::WriteLineIf(arithmeticSwitch->TraceWarning, "!!!!!!!!!!!!!!!!!!Division by 0!!!!!!!!!!!!!!!!");
			b = 1;
		}
		
		Int64 ratio = a / b;
	
		if(traceMethods->Enabled)
			Trace::WriteLine(String::Concat("Divide(", a.ToString(), ",", b.ToString(), ") returns ", ratio.ToString()));

		return ratio;
	}

	Int64 Percent(Int64 a, Int64 b)
	{
		if (traceMethods->Enabled)
			Trace::WriteLine(String::Concat("Percent(", a.ToString(), ",", b.ToString(), ") called"));
		
		Int64 percent = Divide(100*a, b);
	
		if (traceMethods->Enabled)
			Trace::WriteLine(String::Concat("Percent(", a.ToString(), ",", b.ToString(), ") returns ", percent));

		return percent;
	}
};

void main()
{
	TraceDemo^ demo = gcnew TraceDemo();
}
